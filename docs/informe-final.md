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

Para el análisis usamos `n` como la cantidad de productos. En la tabla hash también usamos `m` para representar la cantidad de posiciones, que en nuestro programa es 5.

Para hacer las demostraciones contamos los pasos básicos que necesita cada operación. Cada nodo que se revisa puede necesitar como máximo 10 pasos, y también tenemos algunos pasos adicionales que no dependen de la cantidad de productos.

### 3.1. Lista enlazada

**Operación CONSULTAR**

**Teorema.** CONSULTAR tiene un costo de O(n), donde n es la cantidad de productos de la lista.

**Demostración.** Para consultar un producto, el programa busca su código recorriendo la lista desde el primer nodo. Si el producto está al final o no existe, debe revisar todos los nodos.

**Desarrollo.** Como se pueden revisar máximo n nodos y cada revisión necesita como máximo 10 pasos, tenemos:

T(n) es menor o igual que 10n + 20.

Para todo n mayor o igual que 1:

10n + 20 es menor o igual que 30n.

**Conclusión.** Por lo tanto, CONSULTAR pertenece a O(n), con testigos c = 30 y k = 1.

**Operación AGREGAR**

**Teorema.** AGREGAR tiene un costo de O(n).

**Demostración.** Antes de agregar un producto, el programa revisa que su código no esté repetido. Si no lo encuentra, crea el nuevo nodo y lo coloca al inicio de la lista.

**Desarrollo.** En el peor caso, el programa debe revisar todos los productos antes de agregar el nuevo. Después realiza los pasos necesarios para crear y enlazar el nodo.

T(n) es menor o igual que 10n + 20.

Para todo n mayor o igual que 1:

10n + 20 es menor o igual que 30n.

**Conclusión.** Por lo tanto, AGREGAR pertenece a O(n), con testigos c = 30 y k = 1.

**Operación REPONER**

**Teorema.** REPONER tiene un costo de O(n).

**Demostración.** Para reponer unidades, el programa primero busca el producto por su código. Cuando lo encuentra, aumenta la cantidad disponible.

**Desarrollo.** En el peor caso, se deben revisar todos los nodos para encontrar el producto.

T(n) es menor o igual que 10n + 20.

Para todo n mayor o igual que 1:

10n + 20 es menor o igual que 30n.

**Conclusión.** Por lo tanto, REPONER pertenece a O(n), con testigos c = 30 y k = 1.

**Operación ELIMINAR**

**Teorema.** ELIMINAR tiene un costo de O(n).

**Demostración.** Para eliminar un producto, el programa recorre la lista hasta encontrar su código. Cuando lo encuentra, actualiza los enlaces y libera la memoria del nodo.

**Desarrollo.** En el peor caso, el producto está al final o no existe, por lo que se deben revisar todos los nodos.

T(n) es menor o igual que 10n + 20.

Para todo n mayor o igual que 1:

10n + 20 es menor o igual que 30n.

**Conclusión.** Por lo tanto, ELIMINAR pertenece a O(n), con testigos c = 30 y k = 1.

**Operación LISTAR**

**Teorema.** LISTAR tiene un costo de O(n).

**Demostración.** Para mostrar los productos, el programa recorre la lista desde el primer nodo hasta llegar al final.

**Desarrollo.** Cada producto se revisa una sola vez para mostrar su información.

T(n) es menor o igual que 10n + 20.

Para todo n mayor o igual que 1:

10n + 20 es menor o igual que 30n.

**Conclusión.** Por lo tanto, LISTAR pertenece a O(n), con testigos c = 30 y k = 1.

### 3.2. Tabla hash con encadenamiento

En nuestra tabla hash usamos el código del producto para calcular la posición donde se guarda. Si varios productos quedan en la misma posición, se guardan en una lista enlazada.

**Operación AGREGAR**

**Teorema.** AGREGAR tiene un costo de O(n) en el peor caso.

**Demostración.** Para agregar un producto, el programa calcula su posición y revisa la lista correspondiente para comprobar que el código no esté repetido.

**Desarrollo.** En el peor caso, todos los productos pueden quedar en la misma posición. Por eso, se pueden revisar hasta n nodos antes de agregar el nuevo.

T(n) es menor o igual que 10n + 25.

Para todo n mayor o igual que 1:

10n + 25 es menor o igual que 35n.

**Conclusión.** Por lo tanto, AGREGAR pertenece a O(n) en el peor caso, con testigos c = 35 y k = 1.

**Operación CONSULTAR**

**Teorema.** CONSULTAR tiene un costo de O(n) en el peor caso.

**Demostración.** El programa calcula la posición del código y busca el producto dentro de la lista enlazada que se encuentra en esa posición.

**Desarrollo.** Si todos los productos están en la misma posición, se deben revisar hasta n nodos.

T(n) es menor o igual que 10n + 25.

Para todo n mayor o igual que 1:

10n + 25 es menor o igual que 35n.

**Conclusión.** Por lo tanto, CONSULTAR pertenece a O(n) en el peor caso, con testigos c = 35 y k = 1.

**Operación REPONER**

**Teorema.** REPONER tiene un costo de O(n) en el peor caso.

**Demostración.** Para reponer unidades, el programa calcula la posición del producto y busca su código en la lista correspondiente. Cuando lo encuentra, actualiza la cantidad.

**Desarrollo.** En el peor caso, todos los productos están en la misma posición y se deben revisar hasta n nodos.

T(n) es menor o igual que 10n + 25.

Para todo n mayor o igual que 1:

10n + 25 es menor o igual que 35n.

**Conclusión.** Por lo tanto, REPONER pertenece a O(n) en el peor caso, con testigos c = 35 y k = 1.

**Operación ELIMINAR**

**Teorema.** ELIMINAR tiene un costo de O(n) en el peor caso.

**Demostración.** El programa calcula la posición del producto y busca su código en la lista correspondiente. Cuando lo encuentra, actualiza los enlaces y libera el nodo.

**Desarrollo.** Si todos los productos están en la misma posición, se pueden revisar hasta n nodos.

T(n) es menor o igual que 10n + 25.

Para todo n mayor o igual que 1:

10n + 25 es menor o igual que 35n.

**Conclusión.** Por lo tanto, ELIMINAR pertenece a O(n) en el peor caso, con testigos c = 35 y k = 1.

**Operación LISTAR**

**Teorema.** LISTAR tiene un costo de O(n + m).

**Demostración.** Para mostrar los productos, el programa recorre las posiciones de la tabla y muestra los productos que encuentra en cada lista.

**Desarrollo.** Se revisan las m posiciones y los n productos guardados.

T(n,m) es menor o igual que 10n + 10m + 20.

En nuestro programa m vale 5. Entonces:

T(n) es menor o igual que 10n + 70.

Para todo n mayor o igual que 1:

10n + 70 es menor o igual que 80n.

**Conclusión.** Por lo tanto, LISTAR pertenece a O(n), porque nuestra tabla tiene un tamaño fijo de 5 posiciones, con testigos c = 80 y k = 1.

### 3.3. Estructura de la biblioteca: std::map

También usamos `std::map` para comparar nuestro trabajo con una estructura que ya viene incluida en C++.

Esta estructura organiza los productos por su código y utiliza un árbol balanceado. Sus costos son los siguientes:

- **AGREGAR:** O(log n), porque debe ubicar el código donde se va a guardar el producto.
- **CONSULTAR:** O(log n), porque busca el código dentro del árbol.
- **REPONER:** O(log n), porque primero busca el producto y después actualiza su cantidad.
- **ELIMINAR:** O(log n), porque primero busca el producto y después lo elimina.
- **LISTAR:** O(n), porque debe recorrer todos los productos para mostrarlos.

Estos costos corresponden al comportamiento de `std::map` de C++, que utilizamos como referencia y no implementamos desde cero.

### 3.4. Resumen de costos

| Operación | Desde cero | De la biblioteca | Por qué |
|---|---|---|---|
| AGREGAR | Lista: O(n). Hash: O(n) en el peor caso. | O(log n) | Antes de agregar, se revisa que el código no esté repetido. |
| CONSULTAR | Lista: O(n). Hash: O(n) en el peor caso. | O(log n) | Se busca el producto por medio de su código. |
| REPONER | Lista: O(n). Hash: O(n) en el peor caso. | O(log n) | Primero se busca el producto y después se actualiza la cantidad. |
| ELIMINAR | Lista: O(n). Hash: O(n) en el peor caso. | O(log n) | Se busca el producto y se elimina de la estructura. |
| LISTAR | Lista: O(n). Hash: O(n + m). | O(n) | Se recorren los productos para mostrar su información. |

En general, la lista enlazada necesita recorrer sus nodos para encontrar un producto. La tabla hash puede facilitar las búsquedas cuando los productos quedan bien distribuidos, pero como usamos solamente 5 posiciones, pueden presentarse varias colisiones. Por otro lado, `std::map` organiza los productos por su código y permite realizar las búsquedas y modificaciones en tiempo logarítmico.

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
