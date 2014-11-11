#ifndef __QUATERNION_H
#define __QUATERNION_H

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

#endif // __QUATERNION_H
