#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE 100
typedef struct elt{
	char* IDF;
	int type;
	int nature;
	int value;
	struct elt* svt;
}ELT;
ELT* TS[TAILLE];

void init(){ 
	int i;
	for (i=0;i<TAILLE;i++){
		TS[i]=NULL;
	}
}

int Fhach(char* e){
	int i=0, count=0; 
	while(e[i]!='\0'){
		count+=e[i]*i*(10*(i+1));
		i++;
	} 
	return (count%TAILLE);
} 

int recherche(char * el, ELT** adr){
	ELT* p;
	int index = Fhach(el);
	p=TS[index];
	*adr =p;
	if (p==NULL){
		return 0;
	}
	if (!strcmp(p->IDF,el)){
		return 1;
	}
	p=p->svt;
	while (p!=NULL && strcmp(p->IDF,el)){
		p=p->svt;
	}
	*adr =p;
	if (p==NULL){
		return 0;
	}
	return 1;
}

void insererValeur(char* idf, int value){
	ELT * adr; 
	recherche(idf,&adr); 
	adr->value = value;
}

int getValeur(char* idf){
	ELT * adr; 
	recherche(idf,&adr); 
	return adr->value;
}


void inserer(char* el,int type, int nature, int value){ 
	ELT* p; 
	ELT* adr;
	int index= Fhach(el);
	p= malloc(sizeof(ELT));
	p->IDF=el; 
	p->type=type;
	p->nature=nature;
	p->value=value;
	if (TS[index]==NULL){
		p->svt=NULL; 
		TS[index]=p;
	}
	else{
		p->svt=TS[index]; 
		TS[index]=p;
	}
}

void afficherTS(){
	int i=0; ELT* p;
	printf("\n");
	printf("\t                  Table des symboles:\n\n");
	printf("\t    ********************************************\n");
	printf("\t    *    IDF    *     Type     *    Nature     *\n");
	printf("\t    ********************************************\n");
	for (i=0;i<TAILLE;i++){
		if (TS[i]!=NULL){
			p=TS[i]; 
			while(p!=NULL){
				;
				printf("\t    *");
				printf("%10s",p->IDF);
				printf(" *");
				printf("    Entier   ");
				printf(" *");
				printf("   Variable   ");
				printf(" *\n");
				p=p->svt;
			}
		}
	}
	printf("\t    ********************************************\n");
	
}
