/*
 * Aufgabe3.c

 *
 *  Created on: 14.05.2017
 *      Author: SimonSchmieden
 */
#include <stdio.h>

int cube[3][2][4] = {{{1,2,3,4}},{{2,3},{4,6,8,10}},{{3,4,5,6},{6,8,10}}};
int main(void){
	int x=1,y=1,z=2;
	int *p = &cube[0][0][0];
	int *vptr = &cube[x][y];
	int *mptr = &cube[x];
	printf("%d\n", cube[x][y][z]);
	printf("%d\n", p);
	printf("%d\n", vptr);
	printf("%d\n", mptr);
}

