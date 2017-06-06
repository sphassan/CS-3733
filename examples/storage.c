#include <stdio.h>
#include <stdlib.h>

int G = 1;
int *P;

void func(int *arg1, int arg2) {
static int S = 10;
int A[10] = {arg2} ;
printf("S: %4d, B: %4d, C: %4d\n", S, *arg1, A[0]) ;
S = arg2;
}

int main() {
int M;
P = malloc(10*sizeof(int));

M = 100;
P[0] = 200;

func (&M, P[0]);
func (P, G);
}
