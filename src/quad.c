#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TailleQuad 200

typedef struct {
	char* opr;
	char* op1;
	char* op2;
	char* res;
	int col[4];
}quadruplet;

quadruplet q[TailleQuad];

extern QC;

//création d'un quadruplet
void Quad(char* opr, char* op1, char* op2, char* res){
	q[QC].opr = opr;
	q[QC].op1 = op1;
	q[QC].op2 = op2;
	q[QC].res = res;
	QC++;
}


void afficherQuad(int x){
	int i;
	if(x == 1){
	printf("\n\n\t                       Quads: \n\n");
	}else{
	printf("\n\n\t                  Quads Optimises: \n\n");
	}
	printf("\t   **********************************************\n");
	printf("\t   * ID *   OPR   *   OP1   *   OP2   *   RES   *\n");
	printf("\t   **********************************************\n");
	for (i=0;i<QC;i++){
		printf("\t   * ");
		printf("%02d", i);
		printf(" *");
		printf("  %5s  ", q[i].opr);
		printf("*");
		printf("  %5s  ", q[i].op1);
		printf("*");
		printf("  %5s  ", q[i].op2);
		printf("*");
		printf("  %5s  ", q[i].res);
		printf("*\n");
	}
	printf("\t   **********************************************\n");
}

void Maj(int nQc, int jmp){
	char buff[10];
	sprintf(buff, "%02d", jmp);
	q[nQc].op1 = strdup(buff);
}
