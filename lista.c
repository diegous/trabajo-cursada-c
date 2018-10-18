#include <stdlib.h>
#include <stdarg.h>
#include "lista.h"


/* OPERACIONES DE RECORRIDO DE LISTA CON ITERADOR */

// Iniciar el iterador
Iterador lista_iterador_iniciar(Lista pri){
	return pri;
}

// Siguiente (no comprueba que exista un siguiente)
void * lista_iterador_siguiente(Iterador *list){
	void * aux = (*list)->elem;
	*list = (*list)->sig;
	return aux;
}

// Llego al final
int lista_iterador_fin (Iterador itr){
	if (itr == NULL)
		return 1;
	else
		return 0;
}

// Devuelve elemento del nodo en el que esté el iterador
void * lista_iterador_elemento(Iterador it){
	return (*it).elem;
}


/* OPERACIONES SOBRE LA LISTA */

// Inicia la lista
Lista lista_crear (Lista list){
	return NULL;
}

// Destruye la estructura de la lista, pero no sus nodos
Lista lista_destuir (Lista list){
	Lista aux;
	
	while (list != NULL){
		aux = (*list).sig;
		free(list);
		list = aux;
	}
	
	return list;
}

// Devuelve 1 si esta vacia, 0 caso contrario
int lista_vacia (Lista list){
	if (list == NULL)
		return 1;
	else
		return 0;
}

// Agrega un nuevo elemento al final de la lista
Lista lista_agregar (Lista list, void * elem){
	
	//Se crea y aloca el nuevo nodo
	Lista nuevo;
	Iterador aux;	
	
	nuevo = (Lista) malloc(sizeof(struct T_nodo));
	(*nuevo).sig = NULL;
	(*nuevo).elem = elem;
	
	//Comprueba si debe insertarlo primero en la lista ...
	if ( lista_vacia(list) )
		return nuevo;
	
	//...en caso contrario lo inserta al final
	else{
		aux = lista_iterador_iniciar(list);
		
		while ( ! lista_iterador_fin((*aux).sig) )
			lista_iterador_siguiente(&aux);

		(*aux).sig = nuevo;
		return list;
	}


}

// Agrega a la lista tantos parametros como se le pasen
Lista lista_agregar_varios (Lista list, int cant, ...){
	int i;
	
	// Declara e inicializa la lista de parámetros
	va_list argumentos;
	va_start (argumentos, cant);
	
	// Agrega los parámetros a la lista
	for ( i = 0; i < cant; i++)
		list = lista_agregar(list, va_arg(argumentos, void *));
	
	// Finaliza el uso de la lista de parámetros
	va_end(argumentos);
	
	return list;
}

// Eliminar elemento de la lista y devuelve la lista sin el nodo
Lista lista_eliminar (Lista list, void* elem, int (compare) (void *, void *) ){
	Iterador ant, aux = lista_iterador_iniciar(list);

	if (lista_vacia(list))
		return list;
	else
	
	//se fija si es el primero..
	if ( !compare(elem, lista_iterador_elemento(aux)) ){
		lista_iterador_siguiente(&aux);
		free(list);		
		return ( aux );		
	}

	else{
		ant = aux;
		aux = aux->sig;

		//... sino lo busca		
		while ( !(lista_iterador_fin(aux)) && ( compare(elem, lista_iterador_elemento(aux) ))){
			ant = aux;
			aux = (*aux).sig;
		}
		

		//si existe lo saca
		if ( ! (aux == NULL) ){
			(*ant).sig = (*aux).sig;
			free(aux);
		}
		return (list);
	}
}

// Retorna 1 si existe X elemento y 0 si no existe
int lista_existe (Lista list, void * elem, int (compare) (void*, void*)){
	Iterador aux = lista_iterador_iniciar(list);

	while ( !(lista_iterador_fin(aux)) && (compare(elem, lista_iterador_elemento(aux))) )
		lista_iterador_siguiente(&aux);

	if ( ! lista_iterador_fin(aux) )
		return 1;
	else
		return 0;
}






/* CREACIÓN DE LISTA ORDENADA */

// Funcion que inserta ordenado
Lista lista_insertarOrdenado( void * data, Lista list, int (compare) (void*, void*)){
	Lista nuevo;
	Iterador aux;
		
	nuevo = (Lista) malloc(sizeof(struct T_nodo));
	(*nuevo).elem = data;

	//Si la lista esta vacia, lo inserta
	if ( lista_vacia(list) ){
		(*nuevo).sig = NULL;
		return nuevo;
	}

	else{
		aux = lista_iterador_iniciar(list);
		
		//Si no esta vacia se fija si va primero
		if ( compare( data, lista_iterador_elemento(aux) ) < 0 ){
			(*nuevo).sig = list;
			return nuevo;
		}
		
		//Si no va primero, busca la posicion
		else{
			while ( (!lista_iterador_fin((*aux).sig)) && (compare(data, lista_iterador_elemento((*aux).sig)) > 0))
				lista_iterador_siguiente(&aux);

			(*nuevo).sig = (*aux).sig;
			(*aux).sig = nuevo;

			return list;
		}
	}
}

// Función que recibe la lista y crea una nueva ordenada
Lista lista_ordenar(Lista original, int (compare) (void*, void*)){
	Lista nueva;
	nueva = lista_crear(nueva);

	while (!lista_iterador_fin(original))
		nueva = lista_insertarOrdenado( lista_iterador_siguiente(&original), nueva, compare );

	return nueva;
}
