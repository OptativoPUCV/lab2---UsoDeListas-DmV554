#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();

  //Si definimos malloc afuera del for, se reemplazará cada espacio ocupado por el arreglo, en este caso resultado un array solo de numeros 10, que es el ultimo que ocupamos. Es un mismo puntero que modifica su valor y se agrega 10 veces.
  int *elemento;
  for (int i = 1; i <= 10; i++) {
    elemento = malloc(sizeof(int));
    *elemento = i;
    pushBack(L, elemento);
  }

  imprime_lista(L);
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

  if(L == NULL) return 0;
  
  int* elem = first(L);
  int suma = 0;

  while(elem != NULL) {
    suma += *elem;
    elem = next(L);
  }

  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
  int*elemptr = first(L);

  while(elemptr != NULL) {
    if((*elemptr) == elem ) {
      popCurrent(L);
    }
    elemptr = next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {
  Stack* Paux = create_stack();
   void *dato;

  //P1 -> [2,1,4,5,0]
  //aux -> []
   while(top(P1) != NULL) {
      dato = pop(P1);
      push(Paux, dato);
   }

  //P1 -> []
  //aux -> [0,5,4,1,2]

   while(top(Paux) != NULL) {
     dato = pop(Paux);
      push(P1, dato);
      push(P2, dato);
   }

  //P1 -> [2, 1, 4, 5, 0]
  //P2 -> [2, 1, 4, 5, 0]
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int esParIgual(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

int parentesisBalanceados(char *cadena) {
    Stack *s = create_stack();
    int i;
    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
            push(s, &cadena[i]);
        } else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
            if (top(s) == NULL || !esParIgual(*(char *)top(s), cadena[i])) {
                return 0;
            }
            pop(s);
        }
    }
    if(top(s) == NULL) {
      return 1;
    } 

  return 0;
}



