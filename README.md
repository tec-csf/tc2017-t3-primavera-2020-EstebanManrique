# Tarea *3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *Esteban Manrique de Lara Sirvent* - *A01027077* - *Campus Santa Fe* 

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
```

## 2. Solución

*Problema 1: Multiplicación encadenada de matrices*

*El problema consiste en poder multiplicar de la manera más óptima un número n de matrices; se entiende por óptima como la manera en donde se requiera la menor cantidad de multiplicaciones escalares entre los diferentes elementos de las matrices. Para resolver esta prblemática se decidió adoptar un estilo de Programación Dinámica.*

*El primer paso adoptado en el programa diseñado para este problema es la generación de n matrices con números generados de manera aleatoria. Estas matrices se decidió que fueran guardadas en un vedctor de vectores de int's; lo anterior debido a que el número de matrices y la cantidad de columnas y filas de éstas siempre será variable. Teniendo las matrices ya generadas, se debe calcular el número de operaciones que se deben realizar para concretar las distintas combinaciones de multiplicaciones entre las matrices*

*El número de operaciones se calcula para cada posible combinación. Como se presenta en la siguiente tabla (la cual fue programda como un vector en la solución propuesta), se van introduciendo las cantidades de operaciones por parejas. Habrá casos en donde se tengan distintas combinaciones y se deba obtener el mínimo número de operaciones para realizar la tarea. Para lo anterior de utilizó la siguiente fórmula:*

*min_operaciones = {matriz[i,k] + matriz[k+1, j] + (columnas matriz[i,k] * columnas matriz[k+1,j] * filas matriz[k+1,j])}*

*A la par de la obtención y guardado de la cantidad de operaciones, se va guardando en una estructura distinta a la mencionada previamente, el camino a seguir. Teniendo en cuenta esto, se puede imprimir el camino de multiplicación a seguir para encontrar ka matriz resultante de la manera más óptima. Este camino se representa en este caso como una secuencia de matrices y pares de paréntesis que delimitan e indican el camino a seguir para la multiplicación completa y la obtención de la matriz resultante.*

*Las dos estructuras previamente mencionadas se conjuntan para la creación de un árbol binario en donde el nodo raíz (matriz resultante del problema planteado) resulta de los productos de sus nodos hijos y estos nodos hijos dependen completamente de sus sub-niveles de nodos hijos. De esta manera se pueden conectar todos los subproductos dentro del problema para obtener la matriz resultante que solucione al mismo.*

<img src = "https://github.com/tec-csf/tc2017-t3-primavera-2020-EstebanManrique/blob/master/Examples/MultiplicacionMatrices.png.jpg" >

*La imagen presentada muestra un ejemplo con 4 matrices; La primera tabla contempla el número de operaciones a ser realizadas para encontrar el número de operaciones idóneo para solucionar el problema. Este número siempre se encontrará en la fila 1 y en la última columna de la tabla. La segunda tabla contempla el orden que se debe seguir para la implementación óptima de la multiplicación de matrices. Esta tabla desemboca en el árbol binario previamente mencionado, donde la raiz contiene a la matriz resultante. Finalmente, se imprime el camino a seguir, el número de operaciones y la matriz resultante.*

*La complejidad temporal presentada para este problema es de O(n^3), mientras que la espacial es de O(n^2).*

*Problema 2: Coloreo de Nodos*

*El problema consiste en darle un color (en este caso un número mayor a 1) a cada nodo que pertenezca a un grafo conexo sin que 2 o más nodos adyacentes tengan un color repetido. Este problema puede ser aproximado con distintos enfoques pero si decidió diseñarlo mediante un algoritmo de tipo ávido*

*El programa primero le pide al usuario que introduzca el número de nodos que desea tener en el grafo a ser coloreado. Debido a razones de prueba y para demmostrar que el algoritmo sirve para cualquier escenario, se programó la solución de tal manera en que el número de conexiones entre nodos y los nodos que conforman a cada una de las conexiones sea un proceso por completo.*

*Se programó una clase Grafo que cuenta con 2 atributos (uno que recibe el número/color de cada nodo y el otro es una lista adyacente que contiene todos los nodos a los que cada uno de los elementos de un grafo tiene relaciones con -incluido el mismo nodo en caso de que sea una conexión a si mismo-). Asimismo, se cuenta con 2 métodos: addConnection(), el cual conecta a 2 nodos determimados y Coloring(), el cual se explica a continuación.*

*Cuando se aplica el método Coloring, el programa irá revisando cada uno de los elementos en la lista de adyacencia previamente mencionada (estructura list); previo a esta revisión, a cada nodo de la lista de adyacencia se le asignará un valor por default (-1) que será cambiado cada vez que se le asigne un nuevo número a cada uno de los nodos del grafo. Esta asignación de nodos debe contemplar a todos los nodos adyacentes.*

*Una vez que todos los nodos recibieron su debido color, se impirme en consola cada una de estas asignaciones para que el usuario pueda visualizar el "coloreo". Terminada la impresión en consola, se resetean los colores de cada nodo. Como nota adicional, vale la pena mencionar que el número de colores/números que pueden considerarse como elecciones para cada nodo nunca rebasan el máximo grado del nodo con más conexiones en el grafo.*


*La complejidad temporal presentada para este problema es de O(n^2) principalmente por los recorridos realizados en las listas de adyacencia, mientras que la espacial es de O(n).*

### 2.1 Pasos a seguir para utilizar la aplicación.

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
