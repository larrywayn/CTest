#include <stdlib.h> 
#include <stdio.h>
#include "Quaternion.h"
#include <math.h>

Quaternion* newQuaternion(){
	Quaternion *initQ = malloc(sizeof(*initQ));
	initQ->x = 0;
	initQ->y = 0;
	initQ->z = 0;
	initQ->w = 0;
	initQ->skalierung_x = 0;
	initQ->skalierung_y = 0;
	initQ->skalierung_z = 0;
	return initQ;
};

Quaternion* newQuaternionWerte(double x, double y, double z, double w, double skalierung_x, double skalierung_y, double skalierung_z){
	Quaternion *initQ = malloc(sizeof(*initQ));
	initQ->x = z;
	initQ->y = y;
	initQ->z = x;
	initQ->w = w;
	initQ->skalierung_x = skalierung_x;
	initQ->skalierung_y = skalierung_y;
	initQ->skalierung_z = skalierung_z;
	return initQ;
};

void zeigeQ(Quaternion* to){
	printf("Quaternion x: %e, y: %e, z: %e, w: %e \n", to->x*to->skalierung_x,to->y*to->skalierung_y,to->z*to->skalierung_z,to->w);	
};
	
void multipliziereQQ(Quaternion* l, Quaternion* r, Quaternion* to){
    double ax = l->x;
    double ay = l->y;
    double az = l->z;
    double aw = l->w;
    double bx = r->x;
    double by = r->y;
    double bz = r->z;
    double bw = r->w;
    to->x = (aw * bx + ax * bw + ay * bz - az * by);
    to->y = (aw * by + ay * bw + az * bx - ax * bz);
    to->z = (aw * bz + az * bw + ax * by - ay * bx);
    to->w = (aw * bw - ax * bx - ay * by - az * bz);
};

void multipliziereQV(Quaternion* q, Vektor4* v, Vektor4* to) {
    double x = q->x;
    double y = q->y;
    double z = q->z;
    double a00 = q->w * q->w;
    double a01 = q->w * x;
    double a02 = q->w * y;
    double a03 = q->w * z;
    double a11 = x * x;
    double a12 = x * y;
    double a13 = x * z;
    double a22 = y * y;
    double a23 = y * z;
    double a33 = z * z;
    to->x = ((v->x * q->skalierung_x) * (+a00 + a11 - a22 - a33) + 2.0 * (a12 * (v->y * q->skalierung_y) + a13 * (v->z * q->skalierung_z) + a02 * (v->z * q->skalierung_z) - a03 * (v->y * q->skalierung_y)));
    to->y = ((v->y * q->skalierung_y) * (+a00 - a11 + a22 - a33) + 2.0 * (a12 * (v->x * q->skalierung_x) + a23 * (v->z * q->skalierung_z) + a03 * (v->x * q->skalierung_x) - a01 * (v->z * q->skalierung_z)));
	to->z = ((v->z * q->skalierung_z) * (+a00 - a11 - a22 + a33) + 2.0 * (a13 * (v->x * q->skalierung_x) + a23 * (v->y * q->skalierung_y) - a02 * (v->x * q->skalierung_x) + a01 * (v->y * q->skalierung_y)));
	to->w = 1.0;
};

double holWinkelQ(Quaternion* q){
	 return (((acos(q->w) * 2.0) * M_PI) / 180.0);
}

void invertiereQ(Quaternion* q){
	normalisiereQ(q);
	konjuganteQ(q);
}

double magnitudeQ(Quaternion* q){
	double erg = ( q->x *  q->x) + ( q->y *  q->y) + ( q->z *  q->z) + ( q->w *  q->w);
    if (erg > 0.0) {
        return sqrt(erg);
    } else {
        return 1.0;
    }
}

void normalisiereQ(Quaternion* q){
	double mag = magnitudeQ(q);
    if (mag == 0.0) {
        q->w = 1.0;
        q->x = 0.0;
        q->y = 0.0;
        q->z = 0.0;
    } else {
        mag = 1.0 / mag;
        q->w *= mag;
        q->x *= mag;
        q->y *= mag;
        q->z *= mag;
    }
}

void konjuganteQ(Quaternion* q){
    q->x = -q->x;
    q->y = -q->y;
    q->z = -q->z;
}

/*
 * Falls nötig im Shader
Quaternion.prototype.erzeugeMatrix = function(vektor) {
    var matrixArray = [];
    var xy = this.x * this.y;
    var xz = this.x * this.z;
    var xx = this.x * this.x;
    var yy = this.y * this.y;
    var yw = this.y * this.w;
    var xw = this.x * this.w;
    var zz = this.z * this.z;
    var zw = this.z * this.w;
    var zy = this.z * this.y;
    matrixArray[0] = this.SkalierungX * (1.0 - (2.0 * (yy + zz)));
    matrixArray[1] = this.SkalierungX * 2.0 * (xy - zw);
    matrixArray[2] = this.SkalierungX * 2.0 * (xz + yw);
    matrixArray[3] = 0.0;
    matrixArray[4] = this.SkalierungY * 2.0 * (xy + zw);
    matrixArray[5] = this.SkalierungY * (1.0 - (2.0 * (xx + zz)));
    matrixArray[6] = this.SkalierungY * 2.0 * (zy - xw);
    matrixArray[7] = 0.0;
    matrixArray[8] = this.SkalierungZ * 2.0 * (xz - yw);
    matrixArray[9] = this.SkalierungZ * 2.0 * (zy + xw);
    matrixArray[10] = this.SkalierungZ * (1.0 - (2.0 * (xx + yy)));
    matrixArray[11] = 0.0;
    matrixArray[12] = vektor.x;
    matrixArray[13] = vektor.y;
    matrixArray[14] = vektor.z;
    matrixArray[15] = 1.0;
    return matrixArray;
};
*/