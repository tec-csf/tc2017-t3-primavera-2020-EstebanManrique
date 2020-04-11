// -*- lsst-c++ -*-

/*
 * This file is part of tc2017-t3-primavera-2020-EstebanManrique 
 *
 * Developed for Algorithms Design and Analysis Class.
 * See the README file at the repository's root for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, 
 *
 * This program is distributed in the hope that it will help
 * this its creator to develop its coding habilities regarding algorithms design.
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <type_traits>
#include <bits/stdc++.h> 

using namespace std;

/**
 * Implementation of the class Matrixes allow a dynamic creation
 * of the number of arrays specified by the user. Random numbers will
 * fill up the matrixes to be used by the program.
 * 
 * Differennt methods are includes in this class; creation and storage, 
 * filling of a table containing the number of operations required to 
 * multiply the matrixes with different arrangements and the filling of a 
 * seconds table that will determine the order of multiplciation
 */
class Matrixes
{
    public:
    int numberMatrixes; //Number of matrixes to be used in the program.
    int dimensionsForPath = numberMatrixes+1; //Length and height of structures for number of operations and multiplication order.
    
    vector<vector<int>> matrixesVectorAux;
    vector<vector<vector<int>>> matrixesVector; //Matrixes are stored here.
    vector<int> columnsAndRowsForMultiplications; //Used for matrix generation.
    vector<vector<int>> numberOperationsMatrix; //Keeps number of operations depending of the multiplciation order of the matrixes.
    vector<vector<int>> multiplicationOrder; //Will be used for the actual order of the multiplication.

    /**
     * Generates all the matrixes to be used by the program (multiplication).
     * 
     * @param numberMatrix, which represents the number of matrixes to be generated and multiplied
     * by the program.
     * 
     * @note The arrays to be used by the program are stored in a vector of int vectors as the size
     * of each variable is not known until the user inputs its size.
     */ 
    void generateMatrixes(int numberMatrix)
    {
        int i = 0;
        for(i; i<numberMatrix; i++)
        {
            int rows;
            int columns;
            if(i==0)
            {
                cout<<"Introducir numero de filas del arreglo "<<i + 1<<endl;
                cin>>rows;
                columnsAndRowsForMultiplications.push_back(rows);
                cout<<"Introducir numero de columnas del arreglo "<<i + 1<<" el cual sera el numero de columnas del siguiente arreglo"<<endl;
                cin>>columns;
                columnsAndRowsForMultiplications.push_back(columns);
            }
            else
            {
                cout<<"Numero de filas del arreglo "<<i + 1<<" : "<<columns<<endl;
                rows = columns;
                cout<<"Introducir numero de columnas del arreglo "<<i + 1<<" el cual sera el numero de columnas del siguiente arreglo"<<endl;
                cin>>columns;
                columnsAndRowsForMultiplications.push_back(columns);
            }

            srand(time(NULL));

            for(int i = 0; i<rows; i++)
            {
                vector<int> temp;
                for(int j = 0; j<columns; j++)
                {
                    int number = rand()%9+1; //It is possbile to change the range in which the numbers are generated
                    temp.push_back(number);
                    cout<<number;
                    cout<<" ";
                }
                matrixesVectorAux.push_back(temp);
                cout<<" "<<endl;
                temp.clear();
            }
            matrixesVector.push_back(matrixesVectorAux);
            matrixesVectorAux.clear();
        }
    }

    /**
     * Checks every single way in which the different pairs of matrixes can be multiplied in order
     * to find the most effectiv way of finding the resultant matrix. It also saves certain data to then 
     * be used to print the way in which the matrixes should be multiplied.
     * 
     * @param numberMatrix, which represents the number of matrixes to be multiplied by the program.
     * 
     * @note Any combination between 2 matrixes is checked to find the optimal multiplication path.
     */ 
    void findBestMultiplicationStrategy(int numberMatrix)
    {
        int numberOperations = 0;
        int temp;
        int minimum = 100000;
        for(int i = 0; i<(numberMatrixes + 1); i++)
        {
            vector<int> temp;
            for(int j = 0; j<(numberMatrixes + 1); j++)
            {
                temp.push_back(0);
            }
            numberOperationsMatrix.push_back(temp);
            multiplicationOrder.push_back(temp);
        }
        for(int diagonals = 1; diagonals<numberMatrix; diagonals++)
        {
            for(int rows = 1; rows<(numberMatrix + 1) - diagonals; rows++)
            {
                temp = diagonals + rows;
                int min = 1000000;   
                for(int columns = rows; columns<=(temp - 1); columns++)
                {
                    vector<int> operations;
                    numberOperations = numberOperationsMatrix[rows][columns] + numberOperationsMatrix[columns + 1][temp] + columnsAndRowsForMultiplications.at(rows - 1) * columnsAndRowsForMultiplications.at(columns) * columnsAndRowsForMultiplications.at(temp);
                    operations.push_back(numberOperations);
                    if(operations.back()<=min)
                    {
                        min = operations.back();
                        multiplicationOrder[rows][temp] = columns;
                    }
                }
                numberOperationsMatrix[rows][temp] = min;
            }
        }
    }

    /**
     * Prints the path to be followed for the optimal multiplication of any number of matrixes
     * 
     * @param row, normally 1, is the parameter that represents the row from which the printing
     * of the multiplication path begins.
     * @param column, is the parameter that represents the column from which the printing of the
     * multiplication path begins.
     * 
     * @note Parenthesis denote each separation between matrixes to be multiplied.
     */
    void multiplicationPath(int row, int column)
    {
        int array1 = 0;
        int array2 = 0;
        if(multiplicationOrder[row][column]!=0)
        {
            cout<<"(";
            multiplicationPath(row, multiplicationOrder[row][column]);
            multiplicationPath(multiplicationOrder[row][column] + 1, column);
            cout<<")";
        }
        if(multiplicationOrder[row][column]==0)
        {
            cout<<"A"<<row;
        }
    }
};

/**
 * The class Node has been created as a Binary tree is later implemented for
 * the elaboration of the optimal matrix multiplcation path.
 * 
 * It contains a pointer to a left and right node, two integers that serve as 
 * limits that indicate the matrixes that each node contemplate and a vector of
 * integer vectors where the product matrix for that set of matrixes is stored.
 */
class Node
{
    public:
        Node* left;
        Node* right;
        int leftLimit;
        int rightLimit;
        vector<vector<int>> product;

        Node(int lL, int rL)
        {
            leftLimit = lL;
            rightLimit = rL;
            left = NULL;
            right = NULL;
        }
};

/**
 * Implementation of the class BT (binary tree), which is used to implement the most
 * optimal matrix multiplication pattern set eith previous methods.
 * 
 * It takes the information kept in the vectors numberOperationsMatrix and MultiplicationOrder
 * from the an object of the class Matrix to create the branches of the tree, in which the differents
 * necessary operations (multiplications are performed).
 * 
 */
class BT
{
    public:

        Node* root;
        Matrixes m;
        vector<Node*> nodes;
        vector<Node*> tempNodes;
        int i = 0;
        int level = 0;
        
        BT()
        {
            root = NULL;
        }

        /**
         * Performs the multiplication between 2 matrixes.
         * 
         * @param A1, which is the vector of int vectors containing the first matrix to be multiplied.
         * @param A2, which is the vector of int vectors containing the second matrix to be multiplied.
         * @param node, which indicates the node of the BT where the product of these matrixes will be kept
         * 
         * @return vector<vector<int>> resultant array, which contains the resultant matrix produced by 
         * the multiplication fo the arrays taken as parameters.
         * 
         * @note In case the parameter node is 0, it will print the FINAL RESULTANT ARRAY.
         */ 
        vector<vector<int>> multiplication(vector<vector<int>> A1, vector<vector<int>> A2, int node)
        {
            vector<vector<int>> resultantArray;
            for(int i = 0; i<A1.size(); i++)
            {
                vector<int> auxVector;
                for(int j = 0; j<A2.at(0).size(); j++)
                {
                    int sum = 0;
                    for(int k = 0; k<A1.at(0).size(); k++)
                    { 
                        sum = sum + A1.at(i).at(k) * A2.at(k).at(j);
                    }
                    if(node==0)
                    {
                        cout<<sum;
                        cout<<" ";
                    }
                    auxVector.push_back(sum);
                }
                if(node==0)
                {
                    cout<<""<<endl;
                }
                resultantArray.push_back(auxVector);
            }
            return resultantArray;
        }

        /**
         * As mentioned before, a binary tree is filled with all the multiplications to be perfomed to obtain the
         * final matrix, The root from the aforementioned tree wil contain the RESULTANT MATRIX and will be the point
         * from which different levels of leafs are created and contain sub-products between the different matrixes generated
         * randomly.
         * 
         * @param m, which is an object from the class Matrixes that contain all of the matrixes to be multiplied by the method
         * multiplication.
         * 
         * @note The creation of the tree goes from top to bottom (as a normal BT is created). However, the products contained
         * by each node are introduced from the bottom to the root, as the root's product depends from every single node in the tree.
         */ 
        void insertar(Matrixes m)
        {
            Node *neww = new Node(1, m.numberMatrixes);
            root = neww;
            nodes.push_back(root);
    
            while (level<(m.numberMatrixes - 1))
            {
                int nodesGenerated = 0;
                while(nodesGenerated<pow(2,level))
                {
                    int i = 0;
                    Node *neww = new Node(1, m.numberMatrixes);
                    Node *temp;
                    temp = root;
        
                    nodes.push_back(neww);
                   
                    neww = new Node(1, m.numberMatrixes);

                    nodes.push_back(neww);
                    
                    nodesGenerated++;
                    i++;
                }
                level++;
            }

            int j = 0;
            while(j<(pow(2,(m.numberMatrixes-1)))-1)
            {
                Node* temp = nodes.at((2 * j) + 1);
                nodes.at(j)->left = temp;
                if(nodes.at(j)->leftLimit==nodes.at(j)->rightLimit)
                {
                    nodes.at((2 * j) + 1)->leftLimit = nodes.at(j)->leftLimit;
                    nodes.at((2* j) + 1)->rightLimit = nodes.at(j)->leftLimit;
                }
                else
                {
                    nodes.at((2 * j) + 1)->leftLimit = nodes.at(j)->leftLimit;
                    nodes.at((2 * j) + 1)->rightLimit = m.multiplicationOrder[nodes.at(j)->leftLimit][nodes.at(j)->rightLimit];
                }
                
                temp = nodes.at((2 * j) + 2);
                nodes.at(j)->right = temp;
                
                if(nodes.at(j)->leftLimit==nodes.at(j)->rightLimit)
                {
                    nodes.at((2 * j) + 2)->leftLimit = nodes.at(j)->leftLimit;
                    nodes.at((2 * j) + 2)->rightLimit = nodes.at(j)->leftLimit;
                }
                else
                {
                    nodes.at((2 * j) + 2)->leftLimit = (nodes.at(j)->left->rightLimit) + 1;
                    nodes.at((2 * j) + 2)->rightLimit = nodes.at(j)->rightLimit;
                }
                j++;
            }

            j = nodes.size() - 1;
            while(j>=0)
            {
                if(nodes.at(j)->leftLimit==nodes.at(j)->rightLimit)
                {
                    nodes.at(j)->product = m.matrixesVector.at((nodes.at(j)->leftLimit) - 1);
                }
                else
                {
                    nodes.at(j)->product = multiplication(nodes.at((j))->left->product, nodes.at(j)->right->product, j);
                }
                j--;
            }
        }
};

/**
 * Creation of an instance of the classes Matrixes and BT. The program asks the number of matrixes
 * to work with. Then, the user will introduce the number and rows for each array.
 * 
 * Last but not least, the program will present the most optimum multiplication path, the number of
 * multiplications to be performed to obtain the final RESULTANT MATRIX and the RESULTANT MATRIX.
 */
int main()
{
    Matrixes m;
    m.numberMatrixes = 4;
    m.generateMatrixes(m.numberMatrixes);
    m.findBestMultiplicationStrategy(m.numberMatrixes);
    
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Las matrices deben ser multiplicadas de la siguiente manera: ";
    m.multiplicationPath(1, m.numberMatrixes);
    cout<<endl;

    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"El numero de multiplicaciones a ser utilizadas para obtener la matriz resultante son: "<<m.numberOperationsMatrix.at(1).at(m.numberMatrixes)<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Matriz Resultante: "<<endl;

    BT t;
    t.insertar(m);
}
