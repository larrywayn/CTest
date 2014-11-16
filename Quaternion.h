#ifndef __QUATERNION_H
#define __QUATERNION_H

#include "Vektor4.h"

typedef struct Quaternion Quaternion;
struct Quaternion {
    double x;
	double y;
	double z;
	double w;
	
	double skalierung_x;
	double skalierung_y;
	double skalierung_z;
};

Quaternion* newQuaternion();
Quaternion* newQuaternionWerte(double x, double y, double z, double w, double skalierung_x, double skalierung_y, double skalierung_z);
void zeigeQ(Quaternion* to);
void multipliziereQQ(Quaternion* l, Quaternion* r, Quaternion* to);
void multipliziereQV(Quaternion* q, Vektor4* v, Vektor4* to);
double holWinkelQ(Quaternion* q);
void invertiereQ(Quaternion* q);
double magnitudeQ(Quaternion* q);
void normalisiereQ(Quaternion* q);
void konjuganteQ(Quaternion* q);

#endif // __QUATERNION_H
