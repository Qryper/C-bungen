/*
 * unionstructs.c
 *
 *  Created on: 21.05.2017
 *      Author: SimonSchmieden
 */

#include <stdio.h>
/*
typedef union raw_float {		//typedef macht daraus ne Variable /struct muss nicht immer erstellt werden
	float r_float;
	struct b_float{				// Typ
		unsigned s:1;			//falschrum(intuitiv richtig, aber L. Endian)
		unsigned e:8;
		unsigned m:23;
	}bin_float;					//Variable vom Typ kann angelegt werden (Dec/Def einer Variable des Typs)
}raw_float;
*/

typedef struct IeeeFloat {
	unsigned m:23;				//little Endian
	unsigned e:8;
	unsigned s:1;
} IeeeFloat;

union MyFloat {
	float f;
	IeeeFloat raw;
};

typedef union MyFloat MyFloat;


int main(void){
	MyFloat f;
	f.f = -1.0f;				//erst falsch, da little Endian verwendet wurde (Reihenfolge der Var Decl.)

	printf("raw s =%x\n", f.raw.s);
	printf("raw e =%x\n", f.raw.e);
	printf("raw m =%x\n", f.raw.m);

}

