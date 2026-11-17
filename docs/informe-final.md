# Informe final

*(Parte del informe del avance, corregido con la realimentación.)*

## 1. El escenario y el modelado

El proyecto consiste en desarrollar un programa para manejar el inventario de una tienda. Cada producto tiene un código único, un nombre y una cantidad disponible.

El programa permite agregar productos, consultar su información, reponer unidades, eliminar productos y mostrar todos los productos registrados.

Para desarrollar el proyecto se utilizan dos estructuras de datos: una lista simplemente enlazada, que se trabajó durante el avance, y una tabla hash con encadenamiento, que se utiliza en la entrega final.

También se utiliza `std::map` de C++ como estructura de referencia para comparar el comportamiento de las estructuras implementadas.

## 2. Las dos estructuras

Para el proyecto trabajamos con dos estructuras de datos: la lista enlazada y la tabla hash con encadenamiento.

**Lista enlazada:**

La lista enlazada guarda los productos en nodos. Cada nodo tiene el código, el nombre, la cantidad y un enlace al siguiente producto. Para encontrar un producto hay que recorrer la lista hasta encontrar su código.

**Tabla hash con encadenamiento:**

La tabla hash organiza los productos usando su código para calcular en qué posición se guardan. Si varios productos quedan en la misma posición, se utiliza una lista enlazada para guardar todos esos productos.

Aunque las dos estructuras guardan la información de forma diferente, ambas permiten agregar, consultar, reponer, eliminar y listar los productos.

También utilizamos `std::map` de C++ para comparar nuestros resultados con los de una estructura que ya viene incluida en el lenguaje.

## 3. Análisis formal de complejidad

En esta parte vamos a revisar cuánto puede tardar cada operación dependiendo de la cantidad de productos que tengamos guardados.

Para el análisis usamos n como la cantidad de productos. En la tabla hash también usamos m para representar la cantidad de posiciones, que en nuestro programa es 5.

Para las demostraciones usamos un modelo de costo en el que revisar un nodo tiene un costo constante. Llamamos a a ese costo máximo y b al costo de las instrucciones adicionales que no dependen de la cantidad de productos. Estos valores son constantes, es decir, no cambian cuando aumenta la cantidad de productos.

3.1. Lista enlazada

Operación CONSULTAR

Teorema. CONSULTAR tiene un costo de O(n), donde n es la cantidad de productos de la lista.

Demostración. Para consultar un producto, el programa utiliza la función buscar, que recorre la lista desde el primer nodo hasta encontrar el código. En el peor caso, el producto está al final o no existe, por lo que se revisan todos los nodos.

Desarrollo. Como se pueden revisar hasta n nodos y cada revisión tiene un costo constante a, además de un costo adicional b, tenemos:

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, CONSULTAR pertenece a O(n), con testigos c = a + b y k = 1.

Operación AGREGAR

Teorema. AGREGAR tiene un costo de O(n).

Demostración. Antes de agregar un producto, el programa utiliza buscar para comprobar que su código no esté repetido. Si no lo encuentra, crea el nuevo nodo y lo coloca al inicio de la lista.

Desarrollo. En el peor caso, el programa debe revisar todos los productos antes de agregar el nuevo. Después realiza una cantidad constante de pasos para crear y enlazar el nodo.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, AGREGAR pertenece a O(n), con testigos c = a + b y k = 1.

Operación REPONER

Teorema. REPONER tiene un costo de O(n).

Demostración. Para reponer unidades, el programa primero busca el producto por su código. Cuando lo encuentra, aumenta la cantidad disponible.

Desarrollo. En el peor caso, se deben revisar todos los nodos para encontrar el producto. La actualización de la cantidad requiere una cantidad constante de pasos.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, REPONER pertenece a O(n), con testigos c = a + b y k = 1.

Operación ELIMINAR

Teorema. ELIMINAR tiene un costo de O(n).

Demostración. Para eliminar un producto, el programa recorre la lista hasta encontrar su código. Cuando lo encuentra, actualiza los enlaces y libera la memoria del nodo.

Desarrollo. En el peor caso, el producto está al final o no existe, por lo que se deben revisar todos los nodos. La actualización de los enlaces y la liberación del nodo requieren una cantidad constante de pasos.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, ELIMINAR pertenece a O(n), con testigos c = a + b y k = 1.

Operación LISTAR

Teorema. LISTAR tiene un costo de O(n).

Demostración. Para mostrar los productos, el programa recorre la lista desde el primer nodo hasta llegar al final.

Desarrollo. Cada producto se revisa una sola vez para mostrar su información. Por lo tanto, el costo depende directamente de la cantidad de nodos.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, LISTAR pertenece a O(n), con testigos c = a + b y k = 1.

3.2. Tabla hash con encadenamiento

En nuestra tabla hash usamos el código del producto para calcular la posición donde se guarda. Si varios productos quedan en la misma posición, se guardan en una lista enlazada.

La tabla tiene 5 posiciones. En el peor caso, todos los productos pueden quedar en una misma posición y formar una lista enlazada de n nodos.

Operación AGREGAR

Teorema. AGREGAR tiene un costo de O(n) en el peor caso.

Demostración. Para agregar un producto, el programa calcula su posición y revisa la lista correspondiente para comprobar que el código no esté repetido.

Desarrollo. Calcular la posición tiene un costo constante. En el peor caso, todos los productos pueden quedar en la misma posición, por lo que se pueden revisar hasta n nodos antes de agregar el nuevo.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, AGREGAR pertenece a O(n) en el peor caso, con testigos c = a + b y k = 1.

Operación CONSULTAR

Teorema. CONSULTAR tiene un costo de O(n) en el peor caso.

Demostración. El programa calcula la posición del código y busca el producto dentro de la lista enlazada que se encuentra en esa posición.

Desarrollo. Si todos los productos están en la misma posición, se deben revisar hasta n nodos. El cálculo de la posición tiene un costo constante.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, CONSULTAR pertenece a O(n) en el peor caso, con testigos c = a + b y k = 1.

Operación REPONER

Teorema. REPONER tiene un costo de O(n) en el peor caso.

Demostración. Para reponer unidades, el programa calcula la posición del producto y busca su código en la lista correspondiente. Cuando lo encuentra, actualiza la cantidad.

Desarrollo. En el peor caso, todos los productos están en la misma posición y se deben revisar hasta n nodos. La actualización de la cantidad tiene un costo constante.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, REPONER pertenece a O(n) en el peor caso, con testigos c = a + b y k = 1.

Operación ELIMINAR

Teorema. ELIMINAR tiene un costo de O(n) en el peor caso.

Demostración. El programa calcula la posición del producto y busca su código en la lista correspondiente. Cuando lo encuentra, actualiza los enlaces y libera el nodo.

Desarrollo. Si todos los productos están en la misma posición, se pueden revisar hasta n nodos. La actualización de los enlaces y la liberación del nodo tienen un costo constante.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, ELIMINAR pertenece a O(n) en el peor caso, con testigos c = a + b y k = 1.

Operación LISTAR

Teorema. LISTAR tiene un costo de O(n + m).

Demostración. Para mostrar los productos, el programa recorre todas las posiciones de la tabla y muestra los productos que encuentra en cada lista enlazada.

Desarrollo. Se revisan las m posiciones de la tabla y los n productos guardados. Llamamos d al costo constante de revisar una posición y b al costo adicional de la operación.

T(n,m) es menor o igual que a por n más d por m más b.

Para n y m mayores o iguales que 1:

a por n más d por m más b es menor o igual que (a más d más b) por (n más m).

Conclusión. Por lo tanto, LISTAR pertenece a O(n + m), con testigos c = a + d + b y k = 1.

En nuestro programa m vale 5. Como el tamaño de la tabla es fijo, LISTAR también pertenece a O(n), porque el costo de recorrer las posiciones no aumenta cuando crece la cantidad de productos.

3.3. Estructura de la biblioteca: std::map

También usamos std::map para comparar nuestro trabajo con una estructura que ya viene incluida en C++.

Esta estructura mantiene los productos organizados por su código mediante un árbol balanceado. Sus operaciones principales tienen los siguientes costos:

AGREGAR: O(log n). Primero se busca si el código ya existe y después se inserta el producto. Ambas operaciones tienen costo logarítmico.

CONSULTAR: O(log n). Busca el código dentro del árbol balanceado.

REPONER: O(log n). Primero busca el producto y después actualiza su cantidad.

ELIMINAR: O(log n). Primero busca el producto y después lo elimina.

LISTAR: O(n). Recorre todos los productos para mostrar su información.

Demostración de las operaciones de búsqueda, inserción y eliminación.

Teorema. Las operaciones AGREGAR, CONSULTAR, REPONER y ELIMINAR tienen un costo de O(log n) en std::map.

Demostración. std::map utiliza un árbol balanceado. Al buscar, insertar o ubicar un producto, el programa avanza por los niveles del árbol. Como el árbol se mantiene balanceado, su altura crece de forma logarítmica respecto a la cantidad de productos.

Desarrollo. Si a representa una constante que limita el costo de recorrer cada nivel y b representa los pasos adicionales, el costo puede expresarse como:

T(n) es menor o igual que a por logaritmo en base 2 de (n + 1), más b.

Para n mayor o igual que 2, el logaritmo en base 2 de (n + 1) es menor o igual que dos veces el logaritmo en base 2 de n. Además, el logaritmo en base 2 de n es mayor o igual que 1.

Por lo tanto, T(n) es menor o igual que (2a + b) por logaritmo en base 2 de n.

Conclusión. Por lo tanto, estas operaciones pertenecen a O(log n), con testigos c = 2a + b y k = 2.

Demostración de LISTAR.

Teorema. LISTAR tiene un costo de O(n) en std::map.

Demostración. Para mostrar los productos, el programa recorre todos los elementos del mapa utilizando un iterador.

Desarrollo. Cada producto se visita una vez y avanzar al siguiente elemento tiene un costo constante amortizado. Por eso, el costo total es proporcional a la cantidad de productos.

T(n) es menor o igual que a por n más b.

Para todo n mayor o igual que 1:

a por n más b es menor o igual que (a más b) por n.

Conclusión. Por lo tanto, LISTAR pertenece a O(n), con testigos c = a + b y k = 1.

Estos costos corresponden al comportamiento de std::map de C++, que utilizamos como referencia y no implementamos desde cero.

3.4. Resumen de costos

Operación|Desde cero|De la biblioteca|Por qué|

AGREGAR|Lista: O(n). Hash: O(n) en el peor caso.|O(log n)|Antes de agregar,se revisa que el código no este repetido

CONSULTAR|Lista: O(n). Hash: O(n) en el peor caso.|O(log n)|Se busca el producto por medio de su código.

REPONER|Lista: O(n). Hash: O(n) en el peor caso.|O(log n)|Primero se busca el producto y después se actualiza la cantidad.

ELIMINAR|Lista: O(n). Hash: O(n) en el peor caso.|O(log n)|Se busca el producto y se elimina de la estructura.

LISTAR|Lista: O(n). Hash: O(n + m), que en nuestro programa es O(n).|O(n)|Se recorren las posiciones y los productos para mostrar su información.

En general, la lista enlazada necesita recorrer sus nodos para encontrar un producto. La tabla hash puede facilitar las búsquedas cuando los productos quedan bien distribuidos, pero como usamos solamente 5 posiciones, pueden presentarse varias colisiones. Por otro lado, std::map organiza los productos por su código y permite realizar las búsquedas y modificaciones en tiempo logarítmico.

## 4. Experimentos

Para realizar los experimentos se utilizó un computador con Windows 11 y el compilador GCC 16.2.0, utilizando el estándar C++17. El programa se compiló con las opciones -Wall -Wextra.

Se comparó el tiempo de búsqueda de productos en tres estructuras de datos: la lista enlazada, la tabla hash con encadenamiento y std::map de C++.

Para las pruebas se utilizaron cinco cantidades de productos: 1.000, 5.000, 10.000, 50.000 y 100.000. Los productos se generaron automáticamente con códigos consecutivos, desde 1 hasta la cantidad correspondiente a cada experimento.

En cada tamaño se realizaron 100 repeticiones de un grupo de 10 consultas, para un total de 1.000 consultas por estructura en cada ejecución. Se consultaron los mismos códigos en las tres estructuras para poder comparar sus tiempos.

La medición se realizó después de construir las estructuras, por lo que solamente se tuvo en cuenta el tiempo de búsqueda y no el tiempo de inserción. Se hicieron cinco ejecuciones completas y se calculó el promedio de los tiempos obtenidos. Los resultados se expresaron en microsegundos por consulta.

Los resultados se guardaron en cinco archivos CSV dentro de la carpeta datos.

Tabla de resultados:

Cantidad de productos|Lista enlazada (µs)|Tabla hash (µs)|std::map (µs)|

1.000                |2,4126             |0,6965         |0,1551       |

5.000                |19,7074            |5,3807         |0,1831       |

10.000               |63,6263            |19,5616        |0,1990       |

50.000               |1.472,5672         |517,6553       |0,2173       |

100.000              |2.856,3313         |1.465,9908     |0,2437       |

Gráfica de los resultados

xychart-beta
    title "Promedio del tiempo de consulta"
    x-axis ["1000", "5000", "10000", "50000", "100000"]
    y-axis "Tiempo en microsegundos" 0 --> 3000
    line [2.4126, 19.7074, 63.6263, 1472.5672, 2856.3313]
    line [0.6965, 5.3807, 19.5616, 517.6553, 1465.9908]
    line [0.1551, 0.1831, 0.1990, 0.2173, 0.2437]

En la gráfica, la primera línea representa la lista enlazada, la segunda representa la tabla hash y la tercera representa std::map.

## 5. Lo medido contra lo predicho
Los resultados obtenidos muestran diferencias en el tiempo de búsqueda de las tres estructuras.

En la lista enlazada, el tiempo de consulta aumentó bastante al incrementar la cantidad de productos. Esto coincide con el análisis teórico, porque para encontrar un producto es necesario recorrer los nodos hasta encontrar el código buscado. Por esta razón, su búsqueda tiene complejidad O(n).

En la tabla hash también aumentó el tiempo de búsqueda. Esto se debe a que nuestra tabla tiene un tamaño fijo de 5 posiciones. Como se utilizaron códigos consecutivos, varios productos quedaron almacenados en las mismas posiciones y fue necesario recorrer las listas enlazadas para encontrar algunos de ellos. Esto demuestra que las colisiones pueden afectar el rendimiento de una tabla hash.

Por otro lado, std::map presentó los menores tiempos de consulta en todos los tamaños probados. Sus tiempos se mantuvieron relativamente bajos incluso cuando aumentó la cantidad de productos. Esto coincide con su complejidad de búsqueda O(log n).

Al comparar las tres estructuras, se observa que los resultados experimentales coinciden con lo esperado en el análisis de complejidad. La lista enlazada y la tabla hash tuvieron mayores tiempos de búsqueda al aumentar la cantidad de productos, mientras que std::map presentó un comportamiento más estable.

En conclusión, para las condiciones de estos experimentos, std::map obtuvo el mejor rendimiento en las consultas. La tabla hash fue más rápida que la lista enlazada, pero su tamaño fijo y las colisiones afectaron su desempeño. Si se aumentara el tamaño de la tabla hash y se utilizara una función de dispersión adecuada, su rendimiento podría mejorar.
## 6. Conclusiones

(Cuál estructura conviene para este escenario y bajo qué condiciones
cambiaría la respuesta.)
