#include <string.h>
#include <stdlib.h>

#include "alumno.h"


/* MANIPULADORES DE VARIABLES TIPO T_ALUMNO */

// Copia un string a otro con un maximo de caracteres definido max-1 y fuerza el último char a '\0'
void copiarString(char * nueva, int max,char * original){
  int i = 0;

  while ((i<(max-1)) && (original[i] != '\0')){
    nueva[i] = original[i];
    i++;
  }

  nueva[i] = '\0';
}

// Aloca espacio para una variable de tipo alumno y devuelve su direccion de memoria
T_alumno * alumno_crear(){
  T_alumno * nuevo;
  nuevo = (T_alumno *) malloc(sizeof(T_alumno));

  return nuevo;
}




// Carga un alumno con datos recibidos como parámetros
T_alumno alumno_cargar(char *nom, char *apell, char *dni, char *legajo, int dia, int mes, int anio){
  T_alumno alu;

  //Nombre
  copiarString(alu.nombre, 31, nom);

  //Apellido
  copiarString(alu.apellido, 31, apell);

  //DNI
  copiarString(alu.dni, 9, dni);

  //Legajo
  copiarString(alu.legajo, 7, legajo);

  //Fecha
  alu.fecha.dd = dia;
  alu.fecha.mm = mes;
  alu.fecha.yyyy = anio;

  return alu;
}




/* TO STRINGs */

// Recibe un String y una variable de tipo T_alumno y devuelve la misma cargada con los datos del alumno
char * alumno_toString (T_alumno alu, char *d){

  int p = 0, i =0;


  while(alu.apellido[p] != '\0')
    d[i++] = alu.apellido[p++];
  d[i++] = ',';
  d[i++] = ' ';

  p = 0;
  while(alu.nombre[p] != '\0')
    d[i++] = alu.nombre[p++];
  d[i++] = '\n';

  p = 0;
  while(alu.legajo[p] != '\0')
    d[i++] = alu.legajo[p++];
  d[i++] = '\n';

  p = 0;
  while(alu.dni[p] != '\0')
    d[i++] = alu.dni[p++];
  d[i++] = '\n';


  d[i++] = (alu.fecha.dd / 10)%10 + '0';
  d[i++] = alu.fecha.dd % 10 + '0';

  d[i++] = '/';

  d[i++] = (alu.fecha.mm / 10)%10 + '0';
  d[i++] = alu.fecha.mm % 10 + '0';

  d[i++] = '/';

  d[i++] = (alu.fecha.yyyy / 1000)%10 + '0';
  d[i++] = (alu.fecha.yyyy / 100)%10 + '0';
  d[i++] = (alu.fecha.yyyy / 10)%10 + '0';
  d[i++] = alu.fecha.yyyy % 10 + '0';

  d[i] = '\0';

  return d;
}

// Similar a alumno_toString, pero devuelve simpre 64 caracteres
char * alumno_toStringF (T_alumno alu, char * d){

/*  Formato final del String
 *
 *  nombre    '    'apellido  '    'legajo '     'DNI      '     'dd/mm/yyyy' \0
 *  10        + 4  + 10       + 4  + 7     + 5   + 9       + 5   + 10       + 1  = 65 bytes
*/

  int p, i =0, j;

  /*  APELLIDO  */
  p = 0;
  for (j = 0; j < 9; j++)
    if (alu.apellido[p] != '\0')
      d[i++] = alu.apellido[p++];
    else
      d[i++] = ' ';

  // Si el apellido tiene mas de 10 caracteres, lo trunca e inserta un '~'
  if (alu.apellido[p] != '\0'){
    if (alu.apellido[p+1] == '\0')
      d[i++] = alu.apellido[p];
    else
      d[i++] = '~';
  }
  else
    d[i++] = ' ';

  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';



  /*  NOMBRE  */
  p = 0;
  for (j = 0; j < 9; j++)
    if (alu.nombre[p] != '\0')
      d[i++] = alu.nombre[p++];
    else
      d[i++] = ' ';

  // Si el nombre tiene mas de 10 caracteres, lo trunca e inserta un '~'
  if (alu.nombre[p] != '\0'){
    if (alu.nombre[p+1] == '\0')
      d[i++] = alu.nombre[p];
    else
      d[i++] = '~';
  }
  else
    d[i++] = ' ';

  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';



  /*  LEGAJO  */
  p = 0;
  for (j = 0; j < 7; j++)
    if (alu.legajo[p] != '\0')
      d[i++] = alu.legajo[p++];
    else
      d[i++] = ' ';


  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';



  /*  DNI  */
  p = 0;
  for (j = 0; j < 9; j++)
    if (alu.dni[p] != '\0')
      d[i++] = alu.dni[p++];
    else
      d[i++] = ' ';


  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';
  d[i++] = ' ';



  /*  FECHA  */
  d[i++] = (alu.fecha.dd / 10)%10 + '0';
  d[i++] = alu.fecha.dd % 10 + '0';

  d[i++] = '/';

  d[i++] = (alu.fecha.mm / 10)%10 + '0';
  d[i++] = alu.fecha.mm % 10 + '0';

  d[i++] = '/';

  d[i++] = (alu.fecha.yyyy / 1000)%10 + '0';
  d[i++] = (alu.fecha.yyyy / 100)%10 + '0';
  d[i++] = (alu.fecha.yyyy / 10)%10 + '0';
  d[i++] = alu.fecha.yyyy % 10 + '0';

  d[i] = '\0';

  return d;
}



/* COMPARADORES */

// Compara el nombre de alu1 con respecto a alu2 y devuelve 1 si es mayor, -1 menor y 0 iguales
int alumno_compNombre (T_alumno * alu1, T_alumno * alu2){
  return strcmp( (*alu1).nombre, (*alu2).nombre );
}

// Compara el apellido de alu1 con respecto a alu2 y devuelve 1 si es mayor, -1 menor y 0 iguales
int alumno_compApellido (T_alumno * alu1, T_alumno * alu2){
  return strcmp( (*alu1).apellido, (*alu2).apellido );
}

// Compara la fecha de alu1 con respecto a la de alu2 y devuelve >0 si es mayor, <0 menor y 0 iguales
int alumno_compFecha (T_alumno * alu1, T_alumno * alu2){
  int aux;

  aux = (*alu1).fecha.yyyy - (*alu2).fecha.yyyy;

  if (aux == 0){
    aux = (*alu1).fecha.mm - (*alu2).fecha.mm;
    if (aux == 0)
      aux = (*alu1).fecha.dd - (*alu2).fecha.dd;
  }

  return aux;
}

// Compara alu1 con respecto a alu2 y develve 1 si son igules y 0 en caso contrario
int alumno_iguales(T_alumno * alu1, T_alumno * alu2){
  if ( ! strcmp( (*alu1).dni, (*alu2).dni ) )
    if( ! strcmp( (*alu1).legajo, (*alu2).legajo ) )
      if( ! alumno_compFecha(alu1, alu2) )
          if( ! alumno_compApellido(alu1, alu2) )
          if( ! alumno_compNombre(alu1, alu2) )
            return 1;
  return 0;
}

// Desaloca una variable de tipo T_alumno
void alumno_borrar(T_alumno *Bill){
  free( (*Bill).nombre   );
  free( (*Bill).apellido );
  free( (*Bill).dni      );
  free( (*Bill).legajo   );
  free( Bill );
}
