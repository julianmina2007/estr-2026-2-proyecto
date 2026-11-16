
# Informe de avance – Escenario A: Inventario

## 1. Descripción del escenario

El escenario consiste en crear un programa para manejar el inventario de una tienda. Cada artículo tiene un código, un nombre y una cantidad disponible.
El programa debe permitir agregar artículos, eliminarlos, consultar su información, reponer unidades y mostrar todos los artículos registrados.

## 2. Estructura y operaciones

Para este avance utilizamos una lista simplemente enlazada. Cada nodo guarda el código, el nombre y la cantidad de un artículo. También tiene un puntero que señala al siguiente nodo.
Las operaciones que debe realizar el programa son:

El proyecto consiste en desarrollar un sistema de inventario para una
tienda, que permita administrar los productos registrados mediante
diferentes operaciones.

Cada producto estará identificado por un código único y tendrá
asociados un nombre y una cantidad disponible en el inventario.

El sistema permitirá realizar las siguientes operaciones:

- Agregar productos nuevos al inventario.
- Consultar un producto mediante su código.
- Reponer las existencias de un producto registrado.
- Eliminar productos del inventario.
- Listar todos los productos registrados.

El objetivo es facilitar la administración de los productos,
manteniendo organizada la información y permitiendo actualizar las
cantidades disponibles cuando sea necesario.

Para desarrollar el sistema se utilizará el lenguaje C++ y una
estructura de datos dinámica que permita almacenar y modificar
los productos durante la ejecución del programa.

## 2. Qué guarda la estructura y qué operaciones necesita

Cada producto almacenado en el inventario tendrá los siguientes
atributos:

- Código: identificador único del producto.
- Nombre: descripción o nombre del producto.
- Cantidad: número de unidades disponibles.

El sistema contará con las siguientes operaciones:

| Operación | Descripción | Datos necesarios | Precondiciones |
|-----------|-------------|------------------|----------------|
| AGREGAR | Registra un producto nuevo. | Código, nombre y cantidad. | El código no debe estar registrado previamente. |
| CONSULTAR | Busca y muestra la información de un producto. | Código del producto. | Se debe proporcionar un código válido. |
| REPONER | Aumenta las existencias de un producto. | Código y cantidad que se agrega. | El producto debe existir y la cantidad a reponer debe ser positiva. |
| ELIMINAR | Retira un producto del inventario. | Código del producto. | El producto debe estar registrado. |
| LISTAR | Muestra todos los productos del inventario. | No requiere datos adicionales. | Ninguna. |

El código de cada producto debe ser único para evitar registros
duplicados. Además, las cantidades deben mantenerse en valores
no negativos.

| Operación | Descripción |
|---|---|
| AGREGAR | Agrega un artículo si su código no está registrado. |
| ELIMINAR | Elimina un artículo usando su código. |
| CONSULTAR | Busca un artículo y muestra su información. |
| REPONER | Aumenta la cantidad de un artículo. |
| LISTAR | Muestra todos los artículos registrados. |

## 3. Elección de la estructura y costos

Escogimos una lista simplemente enlazada porque permite agregar y eliminar artículos sin tener que mover los demás elementos de la estructura. Además, podemos recorrerla para buscar un artículo por su código.
Los costos esperados de las operaciones son:

| Operación | Costo esperado |
|---|---|
| AGREGAR | O(n), porque se debe revisar si el código ya existe. |
| ELIMINAR | O(n), porque se debe buscar el artículo. |
| CONSULTAR | O(n), porque se recorre la lista hasta encontrar el código. |
| REPONER | O(n), porque primero se debe buscar el artículo. |
| LISTAR | O(n), porque se deben recorrer todos los nodos. |
Donde n representa la cantidad de artículos registrados.
Esta elección se relaciona con el tema de estructuras lineales, explicado en la sección 7 del material de clase. Los costos se relacionan con el tema de complejidad, explicado en la sección 2.

## 4. Pruebas realizadas

Se realizaron cuatro pruebas para comprobar que las operaciones funcionaran correctamente.

### Prueba 1

**Entrada:**
7
AGREGAR 1004512 arroz 20
AGREGAR 1004498 azucar 5
CONSULTAR 1004512
REPONER 1004498 10
CONSULTAR 1004498
ELIMINAR 1004512
CONSULTAR 1004512

**Salida esperada:**
ok
ok
1004512 arroz 20
ok
1004498 azucar 15
ok
no existe
**Salida obtenida:** Coincide con la esperada.

### Prueba 2

**Entrada:**
5
AGREGAR 101 pan 10
AGREGAR 102 leche 4
AGREGAR 101 arroz 8
LISTAR
CONSULTAR 102

**Salida esperada:**
ok
ok
repetido
102 leche 4
101 pan 10
102 leche 4
**Salida obtenida:** Coincide con la esperada.

### Prueba 3

**Entrada:**
7
AGREGAR 10 arroz 20
AGREGAR 20 leche 5
AGREGAR 30 pan 8
ELIMINAR 20
CONSULTAR 20
ELIMINAR 30
LISTAR

**Salida esperada:**
ok
ok
ok
ok
no existe
ok
10 arroz 20
**Salida obtenida:** Coincide con la esperada.

### Prueba 4: lista vacía

**Entrada:**
4
LISTAR
CONSULTAR 100
ELIMINAR 100
REPONER 100 5

**Salida esperada:**
no existe
no existe
no existe
**Salida obtenida:** Coincide con la esperada. La operación LISTAR no muestra nada porque la lista está vacía.

## 5. Mediciones para la entrega final

Para la entrega final pensamos medir cuánto tarda la operación CONSULTAR al aumentar la cantidad de artículos.
También compararemos los resultados de la lista enlazada, la tabla hash y `map`. Para la tabla hash probaremos diferentes tamaños y un caso en el que varios códigos queden en la misma posición.
Con estos resultados podremos comparar el comportamiento de las tres estructuras.
