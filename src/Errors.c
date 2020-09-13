#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern int ligne, colonne;

#define TAILLE 100
typedef struct elt{
	char* IDF;
	int type;
	int nature;
	int value;
	struct elt* svt;
}ELT;
ELT* TS[TAILLE];

int ErrorDoubleDeclaration(char *idf){
	int index; 
	ELT * adr; 
	int b = recherche(idf,&adr); 
	if(b == 1){
		printf("Erreur Symantique, Ligne:%d, Colone:%d, Double Declaration de %s\n",ligne,colonne,idf);
	}
	return b;
}

void ErrorNonDeclaree(char *idf){
	int index; 
	ELT * adr; 
	int b = recherche(idf,&adr); 
	if(b != 1){
		printf("Erreur Symantique, Ligne:%d, Colone:%d, Non Declaration de %s\n",ligne,colonne-strlen(idf),idf);
		inserer(idf, 1, 1, 0);
	}
}

void ErrorDepassementTaille(){
	printf("Erreur Lexical,Ligne:%d, Colone:%d, Capacite Depassee \n",ligne,colonne);
}

void RangeEronne(int a, int b){
	if(a>b){
		printf("Erreur Symantique, Ligne:%d, Colone:%d, Valeur a < b non verifiee\n",ligne,colonne);
	}
	if(a<0 || b<0){
		printf("Erreur Syntaxique, Ligne:%d, Colone:%d, Valeur < 0 dans Range\n",ligne,colonne);
		exit(0);
	}
	
}

void ErrorDivisionParZero(){
	printf("Erreur Symantique, Ligne:%d, Colone:%d, Devision par zero impossible\n",ligne,colonne);
}
