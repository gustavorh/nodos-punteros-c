#include <stdio.h>
#include <stdlib.h>

typedef struct Medicion
{
	float ph;				//Acidez. Por ejemplo: 6.82, 7.02, 8.5
	float ca;				//Calcio. Por ejemplo: 16.2 mg/L, 32.1 mg/L
	float mg;				//Magnesio. Por ejemplo: 2.3 mg/L, 7.4 mg/L
	struct Medicion* sig;
}NodoMuestra;


void main()
{
	NodoMuestra* nuevo=NULL;	//Puntero para crear un nodo
	NodoMuestra* head=NULL;		//Puntero de inicio de lista
	NodoMuestra* aux=NULL;		//Puntero auxiliar
	NodoMuestra* aux2 = NULL;	// Puntero auxiliar.
	int opcion;					//Manejo de opciones del menú
	int posicion;				//Posición donde se desea insertar el nuevo nodo en la lista
	int longitud;				//Longitud de la lista
	int i;
	int cantNodos;				// Cantidad de nodos de la lista a agregar.
		
		
	printf("\nINSERCIONES EN UNA LISTA ENLAZADA SIMPLE (El codigo sera construido entre todos)\n");	//De acuerdo a este código, la lista nunca estará vacía
	do
	{
		printf("\n(1) Crear una lista enlazada simple");
		printf("\n(2) Eliminar la cabeza de la lista");
		printf("\n(3) Eliminar en una posicion especifica de la lista");
		printf("\n(4) Eliminar al final de la lista");
		printf("\n(5) Mostrar la lista");
		printf("\n(6) Finalizar");
		
		do
		{
			printf("\nIngrese una opcion: ");
			scanf("%i",&opcion);			
		}while(opcion < 1 || opcion > 6);
		
		/*
			Se puede reconocer una lista vacia si el valor de head es NULL
			
		*/
		
		switch (opcion)
		{
			case 1: printf("\nHas elegido la opcion 1");
			
					do {
						printf("\nCuantos nodos desea crear: ");
						scanf("%i", &cantNodos);
					} while (cantNodos <= 0);
					
					for (i = 1; i <= cantNodos; i++) {
						nuevo = (NodoMuestra*)malloc(sizeof(NodoMuestra));
						nuevo->ph = i; // Asignar valor al campo ph de la estructura de tipo NodoMuestra (solo para crear la lista)
						nuevo->ca = i+2;
						nuevo->mg = i+4;
						nuevo->sig = NULL;
						
						if (head == NULL) // Se pregunta si la lista está vacía
							head = nuevo;
						else // Caso contrario se debe enlazar la lista,
							aux->sig = nuevo;
						aux = nuevo;
					}
					/*
						Para limpiar la lista y dejar la lista solo con el puntero head.
					*/
					nuevo = NULL; // Restablecer a NULL para seguir ocupando
					aux = NULL; // Restablecer a NULL para seguir ocupando
					
					break;			
			
			case 2: printf("\nHas elegido la opcion 2");
					
					if (head == NULL)
						printf("\nLista vacia, no hay nodos para elimnar.");
					else {
						/*
							Se debe guardar la posicion de la lista para no perder su acceso de retorno.
							La variable aux ayudará a guardar dicha lista y enviar head al siguiente nodo.
						*/
						aux = head;
						head = head->sig;
						aux->sig = NULL;
						free(aux); // Libera la memoria de aux, es decir elimina el nodo que aux contiene.
						aux = NULL;
					}
					
					break;
			case 3: printf("\nHas elegido la opcion 3");
					break;
			case 4: if (head == NULL)
						printf("\nLista vacia, no hay nodos para eliminar.");
					else {
						aux = head;
						while (aux->sig != NULL) {
							aux2 = aux;
							aux = aux->sig;
						}
						aux2->sig = NULL;
						free(aux);
						aux = NULL;
						aux2 = NULL;
					}
					
					break;
			case 5: printf("\nHas elegido la opcion 5");
			
					printf("\nLISTA ENLAZADA\n");
					aux=head;
					while(aux != NULL)
					{
						printf("|%.2f|%.2f|%.2f|-->",aux->ph,aux->ca,aux->mg);
						aux=aux->sig;
					}
					printf("NULL");
					break;
		}
	}while(opcion != 6);
}
