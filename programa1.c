#include <stdio.h>
#include "alumno.h"
#include "extras.h"


int main(int argc, char * argv[]){
  FILE * arch;
  T_alumno alu;

  // Crea un archivo con el nombre recibido como parámetro
  if ( argc > 1 ){
    if (( arch = fopen(argv[1], "w") )){
      printf("Ingrese datos de alumnos:\n\n");

      while( ! cargarAlumno(&alu) ){
        fwrite(&alu, sizeof(T_alumno), 1,arch);
        printf("\n\nProximo alumno (ENTER para finalizar):\n");
      }
      fclose(arch);
    }
    else
      printf("\n\n    No se pudo abrir %s\n\n", argv[1]);
  }
  else{
    printf("\n\n    Parametros insufiecientes");
    printf("\n\n    Ingrese como parametro un nombre para generar el archivo donde se guardaran los datos cargados\n\n\n");
  }

  return 0;
}
