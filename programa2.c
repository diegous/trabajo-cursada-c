#include <stdio.h>
#include "alumno.h"
#include "lista.h"
#include "extras.h"

// Macros para facilitar la impresión con formato de un alumno
#define imprimir(x, y) printf("%s\n", alumno_toStringF(*x ,y))



int main(int argc, char * argv[]){
	FILE * arch;
	Iterador I;
	Lista L, Lo;
	
	T_alumno * alu;
	alumno_string s;
	
	
	
	if (argc > 2){
		
		// Abre un archivo con el nombre recibido como parámetro
		if ((arch = fopen(argv[1], "r"))){

			/* Se carga una lista para cargar en el orden que vienen los alumnos desde	 *
			 * el archivo, para asi poder imprimir la lista sin orden antes de ordenarla */
			L = lista_crear(L);
			
			// Carga un alumno desde el archivo y lo aloca en la memoria
			alu = alumno_crear();
			fread(alu, sizeof(T_alumno), 1, arch);

			printf("\n\nAPELLIDO      NOMBRE        LEGAJO      DNI           FECHA DE NAC.\n\n");


			// Carga y muestra en pantalla una lista con datos del archivo
			while ( !feof(arch)){
				imprimir( alu, s.alumno_sf );
				L = lista_agregar_varios (L, 1, alu);
				alu = alumno_crear();
				fread(alu, sizeof(T_alumno), 1, arch);
			}


			// Cierra el archivo una vez cargada la lista
			fclose(arch);


			// Ordena la lista segun corresponda
			if (argv[2][0] == '-'){
				
				Lo = lista_crear(Lo);
				
				// Elige como ordenar segun el parámetro ingresado
				switch (argv[2][1]){
					case 'n': 	Lo = lista_ordenar(L, alumno_compNombre);
								break;
					case 'a': 	Lo = lista_ordenar(L, alumno_compApellido);
								break;
					case 'f': 	Lo = lista_ordenar(L, alumno_compFecha);
								break;
					default:
						ayuda_imprimir();
				}
				
				// Se destruye la lista original ya que no es necesaria
				L = lista_destuir(L);
				
				printf("\n\n");

				
				I = lista_iterador_iniciar(Lo);	
				while (! lista_iterador_fin(I))
					imprimir( ((T_alumno *)lista_iterador_siguiente(&I)), s.alumno_sf );

					
			}
			else
				ayuda_imprimir();
			
		}
		else
			printf("\n\n    No se pudo abrir el archivo  \" %s \"\n\n", argv[1]);
	}
	else
		ayuda_imprimir();
	
	return 0;
}
