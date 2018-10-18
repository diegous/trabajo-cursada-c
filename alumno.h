#ifndef __ALUMNO_H__
#define __ALUMNO_H__


/* ESTRUCTURA DE T_ALUMNO */

typedef struct{
  char nombre[31];
  char apellido[31];
  struct{
    int dd;
    int mm;
    int yyyy;
  }fecha;
  char legajo[7];
  char dni[9];
}T_alumno;


/* STRINGS PARA LOS TO-STRING */

typedef struct{
  char alumno_s[100];
  char alumno_sf[65];
}alumno_string;




/* MANIPULADORES DE T_ALUMNOs */

// Copia un string a otro con un maximo de caracteres definido max-1 y fuerza el último char a '\0'
void copiarString(char *, int ,char *);

// Aloca espacio para una variable de tipo alumno y devuelve su direccion de memoria
T_alumno * alumno_crear();

// Carga un alumno con datos recibidos como parámetros
T_alumno alumno_cargar(char *, char *, char *, char *, int, int, int);



/* TO STRINGs */

// Recibe un String y una variable de tipo T_alumno y devuelve la misma cargada con los datos del alumno
char * alumno_toString (T_alumno, char *);

// Similar a alumno_toString, pero devuelve simpre 64 caracteres
char * alumno_toStringF (T_alumno, char *);


/* COMPARADORES */

// Compara el nombre de alu1 con respecto a alu2 y devuelve 1 si es mayor, -1 menor y 0 iguales
int alumno_compNombre (T_alumno *, T_alumno *);

// Compara el apellido de alu1 con respecto a alu2 y devuelve 1 si es mayor, -1 menor y 0 iguales
int alumno_compApellido (T_alumno *, T_alumno *);

// Compara la fecha de alu1 con respecto a la de alu2 y devuelve >0 si es mayor, <0 menor y 0 iguales
int alumno_compFecha (T_alumno *, T_alumno *);

// Compara alu1 con respecto a alu2 y develve 1 si son igules y 0 en caso contrario
int alumno_iguales(T_alumno *, T_alumno *);

// Desaloca una variable de tipo T_alumno
void alumno_borrar(T_alumno *);

#endif
