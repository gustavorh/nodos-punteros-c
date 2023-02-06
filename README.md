# README - Lista-Doble-Enlazada-C.c

## Introducción

Este código es un programa en lenguaje C que permite realizar operaciones en una lista doblemente enlazada. La lista permite crear un nodo, insertar un nodo en una posición específica o al inicio o al final, eliminar un nodo en una posición específica o al inicio o al final y mostrar la lista completa. 

## Funciones

La estructura principal de la aplicación es la estructura "Nodo", la cual tiene como atributos un puntero a un nodo anterior y otro puntero a un nodo siguiente, y un entero "dato".

El programa cuenta con un menú que permite realizar las siguientes operaciones:

1. Crear un nodo: permite ingresar un dato para un nuevo nodo.
2. Insertar un nodo al principio de la lista: permite insertar el nodo recién creado al inicio de la lista.
3. Eliminar un nodo al principio de la lista: elimina el primer nodo de la lista.
4. Eliminar un nodo con dato específico: permite eliminar un nodo de la lista con un dato específico.
5. Insertar un nodo en una posición específica: permite insertar un nodo en una posición específica dentro de la lista.
6. Eliminar un nodo en una posición específica: permite eliminar un nodo en una posición específica dentro de la lista.
7. Insertar un nodo al final de la lista: permite insertar el nodo recién creado al final de la lista.
8. Eliminar un nodo al final de la lista: elimina el último nodo de la lista.
9. Mostrar la lista: muestra todos los nodos de la lista.
10. Finalizar programa: finaliza la ejecución del programa.

## Flujo del código

El programa comienza con un menú que se presenta en un bucle infinito. Se pide al usuario que ingrese una opción del menú y se ejecutan las operaciones correspondientes a la opción seleccionada. Si se elige la opción "finalizar programa", se sale del bucle y se termina la ejecución del programa.

## Consideraciones

- El usuario debe crear un nodo antes de poder insertarlo en la lista.
- La opción de eliminar un nodo con un dato específico solo eliminará el primer nodo con ese dato que encuentre en la lista.
- La opción de insertar un nodo en una posición específica requiere que la lista tenga al menos

# README.md - Muestras-Lista-Enlazada.c

## Introducción

Este código en C es un ejemplo de una lista enlazada simple, que permite realizar operaciones de creación, eliminación y visualización de una lista enlazada, compuesta por una estructura `NodoMuestra` que contiene los campos `ph`, `ca` y `mg` para representar los valores de acidez, calcio y magnesio respectivamente. 

## Funciones

El código cuenta con una función `main` que permite interactuar con el usuario a través de un menú, para seleccionar las diferentes opciones disponibles: crear una lista enlazada simple, eliminar la cabeza de la lista, eliminar en una posición específica de la lista, eliminar al final de la lista, mostrar la lista o finalizar.

Las funciones utilizadas en este código son `malloc`, que permite reservar un bloque de memoria en tiempo de ejecución, y `scanf`, que permite la entrada de datos por parte del usuario.

## Flujo del código

El flujo del código se desarrolla en la función `main`, donde se muestra un menú al usuario y se ejecutan las operaciones según la opción seleccionada.

El proceso de creación de una lista enlazada se realiza a través de un ciclo `for` que permite agregar la cantidad de nodos que el usuario desee. Se crea un nuevo nodo con la función `malloc` y se asignan valores a los campos de la estructura `NodoMuestra`. La lista es enlazada, es decir, se crea un enlace entre los nodos, a través del puntero `sig` que apunta al siguiente nodo en la lista.

Las operaciones de eliminación de la cabeza de la lista, eliminación en una posición específica de la lista y eliminación al final de la lista, se realizan a través de punteros auxiliares, que permiten recorrer la lista y encontrar el nodo a eliminar, para actualizar los enlaces y liberar la memoria ocupada por el nodo eliminado.

La operación de visualización de la lista se realiza a través de un ciclo `while`, que permite recorrer la lista y mostrar los valores de los campos de la estructura `NodoMuestra`.

## Consideraciones

Es importante destacar que en este código se trabaja con punteros y memoria dinámica, por lo que es necesario tener en cuenta las buenas prácticas.

# README - Registro-Pacientes-Triage.c

## Introducción
Este código permite registrar los ingresos de pacientes en un hospital, aplicar triage y atender a los pacientes, hacer un diagnóstico y cerrar la atención. Además, los pacientes se registran en una cola según el orden en que llegaron.

## Funciones

- **main()**: Función principal que ejecuta todo el programa y maneja el menú de opciones.

- **Registro**: Estructura que representa a un paciente y sus datos de ingreso, triage, atención y cierre de atención.

## Flujo del código
El programa se ejecuta en la función `main()`. Inicialmente, se inicializan las variables para el manejo de fecha y hora y las variables para el programa. Se muestra el menú de opciones y se espera la entrada del usuario. Según la opción seleccionada, se ejecutan diferentes tareas, como registrar un ingreso, aplicar triage, atender y hacer un diagnóstico a un paciente, o cerrar la atención.

## Consideraciones
- Es importante tener en cuenta que los pacientes se registran en una cola según el orden en que llegaron y que los pacientes se clasifican según su gravedad en el triage.
- La fecha y hora se obtienen del sistema y se registran en cada etapa del proceso (ingreso, atención y cierre de atención).
- La clasificación en triage se guarda en un vector de punteros.
- El diagnóstico y la condición del paciente se registran en la etapa de atención.
- La fecha y hora de cierre de atención se registran en la etapa de cierre.

