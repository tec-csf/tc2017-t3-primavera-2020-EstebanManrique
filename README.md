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

### 2.1 Pasos a seguir para utilizar la aplicación.

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
