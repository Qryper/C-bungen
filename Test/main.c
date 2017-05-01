/*
 * main.c
 *
 *  Created on: 27.04.2017
 *      Author: SimonSchmieden
 */
#include <stdio.h>
#include "newHead.h"

int area = CIRCLE_AREA( 4 );
int main(void){
	int x = 5;
	int y = 10;
	int z = MAX(x++, y++);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);
	printf("%d", area);
}
