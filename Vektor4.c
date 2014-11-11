#include <stdlib.h> 
#include <stdio.h>
#include "Vektor4.h"
#include <math.h>

Vektor4* newVektor4(){
	Vektor4 *initV = malloc(sizeof(*initV));
	initV->x = 0;
	initV->y = 0;
	initV->z = 0;
	initV->w = 0;
	return initV;
};

void zeigeV(Vektor4* to){	
	printf("Vektor x: %e, y: %e, z: %e, w: %e \n", to->x,to->y,to->z,to->w);	
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


void invertiereV(Vektor4* v){
	v->x *= -1.0; 
	v->y *= -1.0; 
	v->z *= -1.0; 
	v->w *= -1.0; 
};


void skaliereV(Vektor4* v, double x, double y, double z, double w){
	v->x *= x; 
	v->y *= y; 
	v->z *= z; 
	v->w *= w; 
};

double laengeV(Vektor4* v){
	double erg = pow(v->x,2)+pow(v->y,2)+pow(v->z,2)+pow(v->w,2);	
	printf("Erg V2: %e \n", erg);	
	 if (erg > 0) {
        return sqrt(erg);
    } else {
        return 1.0;
    }
};