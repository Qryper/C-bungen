/*
 * VariableLists.c
 *
 *  Created on: 29.05.2017
 *      Author: SimonSchmieden
 */
#include <stdio.h>
#include <stdarg.h>

float average(int amount,...){
	va_list myList;
	va_start(myList,amount);
	float myArg = 0;
	for(int i=0; i<amount;i++){
		myArg += va_arg(myList, int);
	}
	va_end(myList);
	if(amount!=0)
		myArg = myArg/amount;
	return myArg;
}

int minimum(int amount,...){
	va_list myList;
	va_start(myList,amount);
	if(amount!=0){
	 int min = va_arg(myList, int);
	 int myArg = 0;
	 for(int i=0; i<amount;i++){
		myArg = va_arg(myList, int);
		if(myArg < min)
			min = myArg;
	 }
	 va_end(myList);
	 return min;
	}
	else return 0;

}

int main(void){
printf("%f\n",average(5,4,3,23,2,5));
printf("%d\n",minimum(5,22,2,3,4,5));
}
