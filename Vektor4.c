#include <stdlib.h> 
#include <stdio.h>
#include "Vektor4.h"

Vektor4* newVektor4(){
	Vektor4 *initV = malloc(sizeof(*initV));
	initV->x = 0;
	initV->y = 0;
	initV->z = 0;
	initV->w = 0;
	return initV;
};

void addiereVV(Vektor4* l, Vektor4* r, Vektor4* to){
	to->x = l->x+r->x;
	to->y = l->y+r->y;
	to->z = l->z+r->z;
	to->w = 1.0;	
};

void subVV(Vektor4* l, Vektor4* r, Vektor4* to){
	to->x = l->x-r->x;
	to->y = l->y-r->y;
	to->z = l->z-r->z;
	to->w = 1.0;	
};

void mulVV(Vektor4* l, Vektor4* r, Vektor4* to){
	to->x = l->x*r->x;
	to->y = l->y*r->y;
	to->z = l->z*r->z;
	to->w = l->w*r->w;
};

double skalarV(Vektor4* v){
	Vektor4 *tmpV = newVektor4();
	mulVV(v,v,tmpV);
	return tmpV->x + tmpV->y + tmpV->z + tmpV->w;
};

void kreuzVV(Vektor4* l, Vektor4* r, Vektor4* to){
	to->x = (l->y * r->z) - (l->z * r->y);
	to->y = (l->z * r->x) - (l->x * r->z);
	to->z = (l->x * r->y) - (l->y * r->x);
	to->w = (l->w + r->w);
};