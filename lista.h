#ifndef __LISTA_H__
#define __LISTA_H__


/* Estructura de la lista */
struct T_nodo{
	void * elem;
	struct T_nodo *sig;
};

typedef struct T_nodo * Lista;


/* Estructura del iterador */
typedef struct T_nodo * Iterador;


/*
 * CARACTERÍSTICAS DE LA LISTA
 * ===========================
 * 
 * - Usa almacenamiento externo, por lo que es necesario 
 *   alocar memoria para el dato contenido por cada nodo
 * 
 * - Para recorrer se debe usar un iterador de tipo Iterador,
 *   para el cual estan definidas las funciones INICIAR,
 *   SIGUIENTE, FIN y ELEMENTO
 * 
 * - Para crear una lista ordenada se dispone de una función
 *   "lista_ordenar", pero esta requiere de otra función que
 *   compare 2 elementos del tipo guardado en la lista
 * 
*/

/* OPERACIONES DE RECORRIDO DE LISTA CON ITERADOR */

// Iniciar el iterador
Iterador lista_iterador_iniciar(Lista);

// Siguiente (no comprueba que exista un siguiente)
void * lista_iterador_siguiente(Iterador *);

// Llego al final
int lista_iterador_fin (Iterador);

// Devuelve elemento del nodo en el que esté el iterador
void * lista_iterador_elemento(Iterador it);




/* OPERACIONES SOBRE LA LISTA */

// Inicia la lista
Lista lista_crear (Lista);

// Destruye la estructura de la lista, pero no sus nodos
Lista lista_destuir (Lista);

// Devuelve 1 si esta vacia, 0 caso contrario
int lista_vacia (Lista);

// Agrega un nuevo elemento al final de la lista
Lista lista_agregar (Lista, void *);

// Agrega a la lista tantos parametros como se le pasen
Lista lista_agregar_varios (Lista list, int cant, ...);

// Eliminar elemento de la lista y devuelve la lista sin el nodo
Lista lista_eliminar (Lista, void *, int (compare) (void *, void *) );

// Retorna 1 si existe X elemento y 0 si no existe
int lista_existe (Lista, void *, int (compare) (void*, void*));




/* CREACIÓN DE LISTA ORDENADA */

// Funcion que inserta ordenado
Lista lista_insertarOrdenado( void *, Lista, int (compare) (void*, void*));

// Funcion que recibe una lista y crea una nueva ordenada
Lista lista_ordenar(Lista, int (compare) (void*, void*));



#endif
