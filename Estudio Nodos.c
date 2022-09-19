#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numOpciones 10

typedef struct Nodo {
  	struct Nodo *ant;
  	int dato;
  	struct Nodo *sig;
} Nodo;

Nodo* inicio = NULL;
Nodo* fin = NULL;

Nodo* nuevo = NULL;

Nodo* aux = NULL;
Nodo* aux2 = NULL;

float borrar;
int longitud;
int i;

void main() {
    int opcion;			//Moverse entre las opciones
	int posicion;		//Posicion para elimiar o insertar nodo

    printf("INGRESO DE OPCIONES DEL MENU");
    do {
		printf("\n1) Crear un nodo.");
		printf("\n------------------------------------------");
		printf("\n2) Insertar un nodo al principio de la lista.");
		printf("\n3) Eliminar un nodo al principio de la lista.");
		printf("\n------------------------------------------");
		printf("\n4) Eliminar un nodo con dato especifico.");
		printf("\n------------------------------------------");
    	printf("\n5) Insertar un nodo en una posicion especifica.");
		printf("\n6) Eliminar un nodo en una posicion especifica.");
		printf("\n------------------------------------------");
		printf("\n7) Insertar un nodo al final de la lista.");
		printf("\n8) Eliminar un nodo al final de la lista.");
		printf("\n------------------------------------------");
		printf("\n9) Mostrar la lista.");
		printf("\n------------------------------------------");
		printf("\n10) Finalizar Programa");
	
	
		do {
            printf("\n\nIngrese una opcion: ");
			scanf("%i",&opcion);
        } while (opcion < 1 || opcion > numOpciones);

        switch(opcion) {
            case 1: // Crear un nodo.
				nuevo = (Nodo*)malloc(sizeof(Nodo)); // Ayuda a crear un nuevo nodo del tamaño de la estructura declarada, si nuestra estructura tiene nombre "Nodo" debemos usar este nombre.
				printf("\nIngresa un valor para el nuevo nodo: ");
				scanf("%i", &nuevo->dato);
										
				nuevo->ant=NULL;
				nuevo->sig=NULL;
					
				printf("\nNo olvides que este nodo debe ser insertado para formar parte de la lista\n");			
				break;
				
            case 2: // Insertar un nodo al principio de la lista.
				if (nuevo == NULL) //Si no hay un nodo creado en nuevo, osea es NULL, retornar mensaje de ir a la opcion numero 1.
					// No hay un nodo creado para insertar
					printf("\nPara insertar un nodo, debe crear uno primero en la opción 1.");
                else { //Existe un nodo creado
                    if(inicio==NULL) {//Si hay una lista vacia entonces hacer que el inicio sea el nodo a ingresar, unico nodo en la lista.
                        inicio = nuevo;//El inicio de la lista es el valor del nodo nuevo
                        fin = nuevo;//El final de la lista vale tambien el valor del nodo nuevo
                    } else { //Sino, existen mas valores en la lista y se ingresa al principio de la lista.
						nuevo->sig = inicio;//El valor del nuevo nodo flecha siguiente nodo ahora vale el valor del inicio de la lista.
						inicio = nuevo;//El inicio vale el valor del nodo nuevo
					}
					nuevo = NULL;//Eliminamos el nodo nuevo
                }
                break;
			case 3: // Eliminar un nodo al principio de la lista.
				if(inicio == NULL)
					printf("\nLista vacia, no hay nodos para eliminar");
				else {
					aux = inicio;
					inicio = inicio->sig;
					aux->sig = NULL;
					free(aux);
					aux = NULL;
				}
				break;
			case 4: // Eliminar un nodo con dato especifico.
				if(inicio == NULL)	//No existe la lista
					printf("\nLista vacia. No es posible eliminar.");
				else { //Existe la lista
					printf("\nIngrese el valor del dato a borrar: ");
					scanf("%f", &borrar);
					aux = inicio;	
					
					while(aux->dato != borrar && aux->sig != NULL) //Se verifica si el valor es distinto al ingresado, si es así avanza. Y si aux siguiente es distinto a NULL para que no caiga el programa.
						aux=aux->sig;
						
					if(aux->dato != borrar)	//Verificar si el valor ingresado existe en la lista.
						printf("\nEl valor ingresado no existe.");
					else {
						if(aux == inicio) {
							inicio=inicio->sig;
								
							if(inicio != NULL)
								inicio->ant = NULL;
							else
								fin = NULL;
									
							aux->sig = NULL;
								
							free(aux);	//Liberar la memoria del nodo (Borrar el Nodo.)
							aux = NULL;	//Eliminar lo que recuerda aux.
									
						} else {
							if(aux == fin) {
								fin = fin->ant;
									
								if(fin != NULL)
									fin->sig = NULL;
								else
									inicio = NULL;
										
								aux->ant = NULL;
								free(aux);
								aux = NULL;
							} else {
								aux2 = aux->ant;
								aux2->sig = aux->sig;
								aux2 = aux2->sig;
								aux2->ant = aux->ant;
								aux->ant = NULL;
								aux->sig = NULL;
								free(aux);
								aux = NULL;
								aux2 = NULL;
							}
						}
					}
				}
				break;
			case 5: // Insertar un nodo en una posicion especifica.
				if(nuevo == NULL)
					printf("\nAntes de insertar debe crear un nodo, vaya a la opcion (1).\n");
				else {
					longitud = 0;
					aux = inicio;
					
					while(aux != NULL) {
						longitud++;
						aux = aux->sig;
					}
						
					if(longitud>1) {
						do {
							printf("\nIngrese posicion donde desa insetar el nodo: ");
							scanf("%i", &posicion);
						} while(posicion < 2 || posicion > longitud);
							
						aux = inicio;
							
						for(i=1; i<posicion-1; i++)	
							aux = aux->sig;
							
						nuevo->sig = aux->sig;
						aux->sig = nuevo;
						nuevo = NULL;
						aux = NULL;
					} else {
						if(longitud == 0)
							printf("\nERROR: La lista se encuentra vacia, escoja otra opcion.\n");
						else
							printf("\nLa lista solo posee un nodo, elija otra opcion.\n");	
					}
				}
				break;
			case 6: // Eliminar un nodo en una posicion especifica.
				if(inicio == NULL)
					printf("\nLa lista esta vacia. Vaya a la opcion (1) a crear una");
				else {
					longitud = 0;
					aux = inicio;
					while(aux != NULL) {
						longitud++;
						aux = aux->sig;
					}
						
					if(longitud > 2) { //Por lo menos debe haber tres nodos	
						do {	//if(posicion < 1)
							printf("\nIngrese la posicion del nodo a eliminar: ");
							scanf("%i", &posicion);
							/*else{
								if(posicion == 1)
									printf("\nSi queire eliminar al principio de la lista vaya a la opcion 3");
								else
								{
									if()
								}
							}
								
                               if()
							*/  
						} while(posicion < 2 || posicion >= longitud);
							
						aux = inicio;
						i = 1;
						while(i < posicion) {
							aux2 = aux;
							aux = aux->sig;
							i++;
						}
							
						//Eliminación - Desconexión del nodo de la lista
						aux2->sig = aux->sig;
						aux->sig = NULL;
						
						//Eliminación - Devolución de memoria del nodo
						free(aux);
						aux = NULL;
					} else
						printf("\nLa longitud de la lista no permite eliminacion de nodos internos");
				}	
				break;
            case 7: // Insertar un nodo al final de la lista.
				if (nuevo == NULL)
				    // No hay un nodo creado para insertar
				printf("\nPara insertar un nodo, debe crear uno primero en la opción 1.");
                else {
                    if(inicio == NULL) { //No hay Lista
					    inicio = nuevo; // Head apunta a nuestro nuevo nodo.
					    fin = nuevo; // Rear apunta a nuestro nuevo nodo.
					
				    } else { // Hay lista
                        aux = inicio; // Puntero auxiliar para guardar referencia al nodo nuevo.
                        while (aux->sig != NULL)
                            aux = aux->sig; // Avanzamos el puntero hasta el final de la lista
                        aux->sig = nuevo; // ????
                    }  
                }
				break;
			case 8: // Eliminar un nodo al final de la lista.
				if(inicio == NULL)
					printf("\nPara insertar un nodo, debe crear uno primero en la opción 1.");
				else {
                    if(inicio->sig == NULL) {
						//printf("\nHay un solo nodo en la lista");
                        inicio = NULL;
                        free(inicio);
                    } else {
                        aux = inicio;
    					while(aux->sig != NULL) {
    						aux2 = aux;
    						aux = aux->sig;
    					}
    					aux2->sig = NULL;
    					free(aux);
    					aux = NULL;
    					aux2 = NULL;
                    }	
				}
				break;
            case 9: // Mostrar la lista.
				aux = inicio;
				if(inicio == NULL)
					printf("La lista se encuentra vacia\n");
				else {
					printf("NULL<--");
					while(aux != NULL) {
						printf("| %i |", aux->dato);		//Hay un detallito con la flechita en la impresiï¿½auxn
						if(aux->sig != NULL)
							printf("<-->");
						aux = aux->sig; // Avanzamos el puntero al siguiente nodo.
					}
					printf("-->NULL\n");
				}
				break;
			}
    }while (opcion != numOpciones);
}

