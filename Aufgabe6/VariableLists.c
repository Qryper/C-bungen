/*
 * VariableLists.c
 *
 *  Created on: 29.05.2017
 *      Author: SimonSchmieden
 */
#include <stdio.h>
#include <stdarg.h>

int average(int account,...){
	va_list myList;
	va_start(myList,account);
	int myArg = 0;
	for(int i=0; i<account;i++){
		myArg += va_arg(myList, int);
	}
	va_end(myList);
	if(account!=0)
		myArg = myArg/account;
	return myArg;
}

int minimum(int account,...){
	va_list myList;
	va_start(myList,account);
	if(account!=0){
	 int min = va_arg(myList, int);
	 int myArg = 0;
	 for(int i=0; i<account;i++){
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
printf("%d\n",average(5,4,3,23,2,5));
printf("%d\n",minimum(5,22,2,3,4,5));
}
