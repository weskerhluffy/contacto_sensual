/*
 * contacto_sensual.c
 *
 *  Created on: 27/10/2017
 *      Author: ernesto
 */

// XXX: https://www.hackerrank.com/challenges/contacts/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nt {
	char c;
	struct nt *v['z' - 'a' + 1];
	int cont;
} nt;

//nt nds[((int)1E5+1)*22]={0};
nt *nds = NULL;
int ndsc = 0;

void ac(nt *r, char *n, int nc) {
	nt *na = r;
//    printf("mierda %s tam %d\n",n,nc);
	for (int i = 0; i < nc; i++) {
		char ca = n[i] - 'a';
		if (na->v[ca]) {
			na = na->v[ca];
		} else {
			nt *nn = nds + ndsc++;
			na->v[ca] = nn;
//            printf("anadiendo nodo %c a %c\n",ca,na->c);
			na = nn;
		}
		na->c = ca;
		na->cont++;
	}
}

int ec(nt *r, char *n, int nc) {
	nt *na = r;
	int i;
	for (i = 0; i < nc; i++) {
		char ca = n[i] - 'a';
//        printf("letra act %c en %c\n",ca,na->c);
		if (na->v[ca]) {
			na = na->v[ca];
		} else {
			break;
		}
	}
//    printf("el ult nodo '%c' u %u nc %u\n",na->c,i,nc);
	return i == nc ? na->cont : 0;
}

int main() {

	int caca = 0;
//    nds=calloc((((int)1E5)+1)*22,sizeof(nt));
	nds = calloc(100000 * 10, sizeof(nt));
	assert(nds);
	char *op = (char[10] ) { 0 };
	char *palo = (char[22] ) { 0 };
	scanf("%d", &caca);
	nt *raiz = nds + ndsc++;

	while (caca--) {
		scanf("%s %s", op, palo);
//        printf("la op %s\n",op);
		if (!strcmp(op, "add")) {
			ac(raiz, palo, strlen(palo));
		} else {
			int mierda = ec(raiz, palo, strlen(palo));
			printf("%u\n", mierda);
		}
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
