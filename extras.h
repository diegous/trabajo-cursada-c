#ifndef __EXTRAS_H__
#define __EXTRAS_H__

/* Este archivo contiene funciones usadas en los archivos "Programa1.c" y "Programa2.c" */


/* Carga una variable de tipo T_alumno y retorna 0 si lo cargó bien y 1 uno en caso contrario.
 * Esta función no verifica que los datos ingresados sean correctos, por lo tanto no informará
 * al usuario en tal caso.
*/
int cargarAlumno(T_alumno *);

// Pasa un string a entero. No verifica que el String contenga solo números.
int stringANumero(char *);

/*
 * Carga un String desde con el BUFFER de teclado
 * Precondiciones:
 * - Max tiene que ser igual al tamaño del arreglo - 1 (cierra todo string en \0)
 * - Pal debe estar alocado
 * - Termina de leer si encuentra algún '\n' o EOF, sin importar que no haya cargado nada
*/
int leer(char *, int);


/*
 * Imprime una ayuda para ingreso de datos al ejecutar el programa
 * Muestra los parametros permitos y su funcion
*/
void ayuda_imprimir();



#endif
