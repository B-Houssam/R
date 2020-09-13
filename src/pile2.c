#include <stdio.h>
#include <stdlib.h>

//definition de element de la pile 2
typedef struct pile2{
  int nbrQuad;
  struct pile2 * suivant;
}pile2;

pile2 * push2(pile2 * tetePile, int x){
  pile2 * element = malloc(sizeof(pile2));
  element->nbrQuad = x;
  element->suivant = tetePile;
  tetePile = element;
  return tetePile;
}

pile2 * pop2(pile2 * tetePile){
  tetePile = tetePile->suivant;
  return tetePile;
}

int peek2(pile2 *tetePile){
	if(tetePile == NULL) return 0;
	return tetePile->nbrQuad;
}

int empty2(pile2 *tetePile){
	if(tetePile == NULL) return 1;
	return 0;
}
