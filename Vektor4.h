#ifndef __VEKTOR4_H
#define __VEKTOR4_H

typedef struct Vektor4 Vektor4;
struct Vektor4 {
    double x;
	double y;
	double z;
	double w;
};

Vektor4* newVektor4();
void addiereVV(Vektor4* l, Vektor4* r, Vektor4* to);
void subVV(Vektor4* l, Vektor4* r, Vektor4* to);
void mulVV(Vektor4* l, Vektor4* r, Vektor4* to);
double skalarV(Vektor4* v);
void kreuzVV(Vektor4* l, Vektor4* r, Vektor4* to);

#endif // VEKTOR4_H
