//Integrantes del equipo
//Estudiante 1: Gustavo Reyes
//Estudiante 2: oculto
//Estudiante 3: oculto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>	//Librería para el manejo de fecha y hora del sistema
#include <string.h>

typedef struct Registro {
	// Ingreso inicial
	char rut[10];					// Rut del paciente sin puntos ni guion; incluyendo el digito verificador
	short int edad;					// Edad del paciente
	char genero[2];					// F: Femenino - M: Masculino - O: Otro
	char fechaIngreso[20];			// Fecha de ingreso obtenido del sistema en formato dd/mm/aa
	char horaIngreso[20];			// Hora de ingreso obtenido del sistema en formato hh/mm/ss
	// Etapa de clasificacion Triage
	char presionArterial[7];		// Presion sistolica/presion diastolica: 120/80
	float temperatura;				// Temperatura en grados Celcius
	short int saturacionOxigeno;	// Saturacion en porcentaje: 95, 87...
	char clasificacion[3];			// C1, C2, C3, C4, C5, siendo C1 mayor gravedad y C5 menor
	// Etapa de atencion
	char fechaAtencion[20];			// Fecha del inicio de la atencion
	char horaAtencion[20];			// Hora del inicio de la atencion
	char diagnostico[100];			// Diagnostico del paciente
	char condicion[4];				// H: Hospitalizado - NSI: Normal, sin indicaciones - NCI: Normal, con indicaciones - F: Fallecido
	// Etapa de cierre de atencion
	char fechaCierre[20];			// Fecha del cierre de atencion
	char horaCierre[20];				// Hora del cierre de atencion
	
	
	struct Registro* siguiente;
} Ingreso;


void main() {
	//Variables para manejo de fecha y hora
	time_t t;
	struct tm tiempoLocal;	//struct tm es una estructura que maneja la librería time
	char fecha[20];
	char hora[20];
	char* formatoFecha;
	char* formatoHora;
	int bytes;
	
	//Variables del programa desarrollado
	int opcion;		//Manejo de opciones del menú
	int contadorPacientes = 0;
	char numeroClasif[2];
	int indiceTriage;
	int i;
	int identificacion;
	
	// Para cola
	Ingreso* inicio = NULL;
	Ingreso* fin = NULL;
	
	Ingreso* nuevo = NULL;
	Ingreso* aux = NULL;
	
	// Vector de punteros Triage
	Ingreso* triage[5] = {NULL};
	
	
	printf("\nURGENCIAS HOSPITAL DR. KHIEN TEKURA\n");
	do {
		printf("\n(1) Registrar ingreso");		//Equivale a crear un nodo con los datos de ingreso
		printf("\n(2) Aplicar Triage");			//Clasificación del paciente según nivel de gravedad. Incluye derivación a box
		printf("\n(3) Atender un paciente");	//Siempre se realiza por prioridad. Médico completa datos
		printf("\n(4) Cerrar atencion");		//Finaliza atención del paciente
		printf("\n(5) Mostrar Triage");			//Muestra todas las atenciones que no han sido cerradas, por nivel de Triage
		printf("\n(6) Finalizar turno");		//Indica término de ejecución del programa
												//NO SE PUEDE FINALIZAR EL TURNO mientras queda algún paciente por atender
		
		do {
			printf("\n    Ingrese una opcion: ");
			scanf("%i",&opcion);			
		}while(opcion < 1 || opcion > 6);
		
		//Manejo de fecha y hora. Se obtiene del sistema y queda disponible para la opción que lo requiera
		t=time(NULL);
		tiempoLocal=*localtime(&t);
		formatoFecha="%d-%m-%Y";
		formatoHora="%H:%M:%S";
		bytes=strftime(fecha, sizeof fecha, formatoFecha, &tiempoLocal); //fecha contiene la Fecha del sistema
		bytes=strftime(hora, sizeof hora, formatoHora, &tiempoLocal);	 //hora contiene la Hora del sistema
		//printf("Fecha: %s\tHora: %s",fecha,hora);
		
		
		
		switch (opcion) {
			case 1:
				nuevo = (Ingreso*)malloc(sizeof(Ingreso));
				nuevo->siguiente = NULL;
				
				// Ingreso de un paciente.
				printf("Ingrese el RUT del paciente (sin puntos ni guion; incluyendo el digito verificador): ");
				scanf("%s", &nuevo->rut);
				
				printf("Ingrese la edad del paciente: ");
				scanf("%i", &nuevo->edad);
				
				printf("Ingrese el genero del paciente (F, M, O: Otro): ");
				scanf("%s", &nuevo->genero);
				
				strcpy(nuevo->fechaIngreso, fecha);
				strcpy(nuevo->horaIngreso, hora);
				
				// Insercion a la lista
				if (inicio == NULL) { // No existe una lista
					inicio = nuevo;
					fin = nuevo;
				} else { // Si existe una lista
					fin->siguiente = nuevo; // Apunte el primer nodo al siguiente nodo
					nuevo->siguiente = NULL; // El nuevo nodo apunta a NULL ya que es el ultimo nodo insertado.
					fin = nuevo; // Nuestro nuevo rear es el ultimo nodo insertado
				}
				//nuevo = NULL;
				
				contadorPacientes++;
				printf("\nEl paciente numero %i fue ingresado correctamente.\n", contadorPacientes);
				
				break;
					
			case 2:
				if (nuevo == NULL) {
					printf("\nPor favor, ingrese un paciente primero.\n");
				} else {
					//printf("RUT: %s\n", nuevo->rut);
					
					printf("Ingrese la presion arterial del paciente (sistolica/diastolica): ");
					scanf("%s", &inicio->presionArterial);
					
					printf("Ingrese la temperatura del paciente: ");
					scanf("%f", &inicio->temperatura);
					
					printf("Ingrese la saturacion de oxigeno (en porcentaje): ");
					scanf("%i", &inicio->saturacionOxigeno);
					
					printf("Ingrese la clasificacion del paciente: ");
					scanf("%s", &inicio->clasificacion);
					
					numeroClasif[0] = inicio->clasificacion[1];
					numeroClasif[1] = inicio->clasificacion[2];
					
					indiceTriage = atoi(numeroClasif) - 1;
					
					//printf("inicio->clasificacion: %s \ntriage[%i]",inicio->clasificacion , indiceTriage);
					nuevo = (Ingreso*)malloc(sizeof(Ingreso));
					if (triage[indiceTriage] == NULL) {
						// Lista vacia
						triage[indiceTriage] = inicio; // Se inserta el head de la lista.
						triage[indiceTriage]->siguiente = NULL; // Puntero a siguiente nodo es NULL ya que fue el ultimo nodo insertado.
					} else {
						// Enlazo a lista
						aux = inicio;
						while (aux->siguiente != NULL)
							aux = aux->siguiente; // Avanzamos el puntero y aux queda en el ultimo elemento de la lista
						aux->siguiente = inicio;
					}
					aux = NULL; // Reasignamos a NULL para volver a utilizar
				}
				break;
				
			case 3:
				// Atencion de un paciente
				for (i = 0; i < 5; i++)
					if (triage[i] != NULL) {
						aux = triage[i];
						
						while (aux->siguiente != NULL) {
							//printf("\nRUT: %s\nClasificacion: %s\n", triage[i]->rut, triage[i]->clasificacion);
							// Rellena con datos faltantes
							strcpy(triage[i]->fechaAtencion, fecha);
							strcpy(triage[i]->horaAtencion, hora);
							
							printf("Ingrese el diagnostico del paciente: ");
							scanf("%s", &triage[i]->diagnostico);
							
							printf("Ingrese la condicion del paciente (H, NSI, NCI, F): ");
							scanf("%s", &triage[i]->condicion);
						}
					}
				break;
					
			case 4:
				strcpy(inicio->fechaCierre, fecha);
				strcpy(inicio->horaCierre, hora);
				
				printf("\nATENCION FINALIZADA");
				printf("\nRUT: %s\nFecha Ingreso: %s\n\nHora Ingreso: %s\nFecha Atencion: %s\nHora Atencion: %s\n\nDiagnostico: %s\nCondicion de Alta: %s\n\nFecha Cierre: %s\nHora Cierre: %s\n", inicio->rut, inicio->fechaIngreso, inicio->horaIngreso, inicio->fechaAtencion, inicio->horaAtencion, inicio->diagnostico, inicio->condicion, inicio->fechaCierre, inicio->horaCierre);
				
				if (inicio != NULL) {
					aux = inicio; // Guardamos referencia del nodo a eliminar
					inicio = inicio->siguiente; // Actualizamos el head de la lista de modo que apunte al segundo elemento (segundo elemento es ahora el head)
					free(aux);	
				}
				
				break;
					
			case 5:
				// Mostrar lista
				for (i = 0; i < 5; i++) {
					aux = triage[i];
					if (triage[i] != NULL) {
						while (aux != NULL) {
							printf("\nC%i --> |%s|%s", (i+1), triage[i]->rut, triage[i]->clasificacion);
							if (aux->siguiente) {
								printf("-->");
							}
							aux = aux->siguiente;
						}
					} else {
						printf("\nC%i --> NULL", (i+1));
					}
				}
				break;
		}
		
	}while(opcion != 6);
}


