#include <stdio.h>
#include "alumno.h"
#include "extras.h"

/* Carga una variable de tipo T_alumno y retorna 0 si lo cargó bien y 1 uno en caso contrario.
 * Esta función no verifica que los datos ingresados sean correctos, por lo tanto no informará
 * al usuario en tal caso.
*/
int cargarAlumno(T_alumno * alu){
	int num;
	
	char aux[5];
	printf("Nombre: ");
	if (leer((*alu).nombre, 30)){
		
		//Lee Apellido
		do {
			printf("Apellido: ");
			leer((*alu).apellido, 30);
		}while ((*alu).apellido[0] == '\0');

		//Lee Legajo
		do {
			printf("Legajo: ");
			leer((*alu).legajo, 6);
		}while ((*alu).legajo[0] == '\0');

		//Lee DNI
		do {
			printf("DNI: ");
			leer((*alu).dni, 8);
		}while ((*alu).dni[0] == '\0');
		
		//Lee Dia
		do {
			printf("Dia: ");
			leer(aux, 2);
		}while (aux[0] == '\0');
		
		num = stringANumero(aux);
		if (num < 0)
			num *= (-1);
		num %= 13;
		if (num == 0)
			num = 1;
		(*alu).fecha.dd = num;

		//Lee Mes
		do {
			printf("Mes: ");
			leer(aux, 2);
		}while (aux[0] == '\0');
		
		num = stringANumero(aux);
		if (num < 0)
			num *= (-1);
		num %= 32;
		if (num == 0)
			num = 1;
			
		(*alu).fecha.mm = num;

		//Lee Año
		do {
			printf("Anio: ");
			leer(aux, 4);
		}while (aux[0] == '\0');
		
		num = stringANumero(aux);
		if (num < 0)
			num *= (-1);
		num %= 2010;
		if (num <1900)
			num = 1900;
			
		(*alu).fecha.yyyy = num;
		
		return 0;
	}
	else
		return 1;
}

// Pasa un string a entero. No verifica que el String contenga solo números
int stringANumero(char num[]){
	int  i, j, aux, total = 0, largo = -1;

	
	//Mini strlen
	while(num[++largo] != '\0');
		
	for(i = 0; i < largo; i++){
		// Potencia 10 a lo que corresponda
		for (j = 0, aux = 1; j<(largo - i - 1); j++, aux *= 10);
		total += (num[i]-'0')*aux;

	}
	
	return total;
}




/*
 * Carga un String desde con el BUFFER de teclado
 * Precondiciones:
 * - Max tiene que ser igual al tamaño del arreglo - 1 (cierra todo string en \0)
 * - Pal debe estar alocado
 * - Termina de leer si encuentra algún '\n' o EOF, sin importar que no haya cargado nada
*/
int leer(char * pal, int max){
	int i = 0;
	char c;
	
	//Carga el arreglo
	
	while ( i<max   &&  (c = fgetc(stdin))!=EOF  &&  c!='\n' && c != '\r' )
		pal[i++] = c;
	
	//Cierra el string
	pal[i] = '\0';
	
	//Limpia el BUFFER
	if ( i == max)
		while ((c != EOF) && (c != '\n'))
			c = fgetc(stdin);
	
	return i;
}

// Imprime la ayuda en pantalla
void ayuda_imprimir(){
	
	printf("\n\nParametros insuficientes o incorrectos\n\n");
	printf("El 1 parametro debe corresponder al nombre de un archivo existente\n");
	printf("El 2 parametro debe corresponder al tipo de ordenacion en la que desea visualizar los datos:\n\n");
	printf("\tParametros de ordenacion validos\n\n");
	printf("\t1) parametro: -a\tordena por apellido\n");
	printf("\t2) parametro: -n\tordena por nombre\n");
	printf("\t3) parametro: -f\tordena por fecha\n\n");
	
}


