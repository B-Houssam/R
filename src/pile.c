#include <stdio.h>
#include <stdlib.h>

extern int QC, num_quad;

//definition de element de la pile 1
typedef struct pile{
  int adrCond;
  int nbrif;
  struct pile * suivant;
}pile;

pile * push(pile * tetePile){
  pile * element = malloc(sizeof(pile));
  element->adrCond = QC - 1;
  element->suivant = tetePile;
  tetePile = element;
  return tetePile;
}

pile * pop(pile * tetePile){
  num_quad = tetePile->adrCond;
  tetePile = tetePile->suivant;
  return tetePile;
}

int peek(pile *tetePile){
	if(tetePile == NULL) return 0;
	return tetePile->adrCond;
}
