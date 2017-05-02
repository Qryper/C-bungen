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
	/*
	int x = 5;
	int y = 10;
	int z = MAX(x++, y++);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);
	printf("%d", area);
	*/
	int j=0;
	char input[100];
	int out[100];
	fgets (input, 100, stdin);
	for(int i=0; i<sizeof(input); i=i+2){
		char current = input[i];
		char next = input[i+1];
		int decNumber;
		int nexNumber;
		switch(current){
		case 'A' : decNumber=10;break;
		case 'B' : decNumber=11;break;
		case 'C' : decNumber=12;break;
		case 'D' : decNumber=13;break;
		case 'E' : decNumber=14;break;
		case 'F' : decNumber=15;break;
		default : decNumber=current -'0';
		}
		switch(next){
		case 'A' : nexNumber=10;break;
		case 'B' : nexNumber=11;break;
		case 'C' : nexNumber=12;break;
		case 'D' : nexNumber=13;break;
		case 'E' : nexNumber=14;break;
		case 'F' : nexNumber=15;break;
		default : nexNumber=next - '0';
		}
			out[j] = nexNumber + 16*decNumber;
			j++;
	}
	for(int j=0; j<(sizeof(input)/2);j++){
		printf("%c",out[j]);
	}
}
