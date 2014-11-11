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

/*
Quaternion.prototype.multiplikationVR = function(vektor) {
    var tmpVektor = new Vektor4();
    var x = this.x;
    var y = this.y;
    var z = this.z;
    var a00 = this.w * this.w;
    var a01 = this.w * x;
    var a02 = this.w * y;
    var a03 = this.w * z;
    var a11 = x * x;
    var a12 = x * y;
    var a13 = x * z;
    var a22 = y * y;
    var a23 = y * z;
    var a33 = z * z;
    tmpVektor.x = ((vektor.x * this.SkalierungX) * (+a00 + a11 - a22 - a33) + 2.0 * (a12 * (vektor.y * this.SkalierungY) + a13 * (vektor.z * this.SkalierungZ) + a02 * (vektor.z * this.SkalierungZ) - a03 * (vektor.y * this.SkalierungY)));
    tmpVektor.y = ((vektor.y * this.SkalierungY) * (+a00 - a11 + a22 - a33) + 2.0 * (a12 * (vektor.x * this.scal.this.SkalierungX) + a23 * (vektor.z * this.SkalierungZ) + a03 * (vektor.x * this.scal.this.SkalierungX) - a01 * (vektor.z * this.SkalierungZ)));
    tmpVektor.z = ((vektor.z * this.SkalierungZ) * (+a00 - a11 - a22 + a33) + 2.0 * (a13 * (vektor.x * this.scal.this.SkalierungX) + a23 * (vektor.y * this.SkalierungY) - a02 * (vektor.x * this.scal.this.SkalierungX) + a01 * (vektor.y * this.SkalierungY)));
    tmpVektor.w = 1.0;
    return tmpVektor;
};
Quaternion.prototype.setzSkalierung = function(skalierungX, skalierungY, skalierungZ) {
    this.SkalierungX = (skalierungX) ? parseFloat(skalierungX) : 1.0;
    this.SkalierungY = (skalierungY) ? parseFloat(skalierungY) : 1.0;
    this.SkalierungZ = (skalierungZ) ? parseFloat(skalierungZ) : 1.0;
};
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

Quaternion.prototype.holWinkel = function() {
    return (((Math.acos(this.w) * 2.0) * Math.PI) / 180.0);
};
Quaternion.prototype.invertiere = function() {
    this.normalisiere();
    this.konjugante();
};
Quaternion.prototype.magnitude = function() {
    var erg = ( this.x * this.x) + (this.y * this.y) + (this.z * this.z) + (this.w * this.w);
    if (erg > 0) {
        return Math.sqrt(erg);
    } else {
        return 1.0;
    }
};
Quaternion.prototype.normalisiere = function() {
    var mag = this.magnitude();
    if (mag === 0.0) {
        this.w = 1.0;
        this.x = 0.0;
        this.y = 0.0;
        this.z = 0.0;
    } else {
        mag = 1.0 / mag;
        this.w *= mag;
        this.x *= mag;
        this.y *= mag;
        this.z *= mag;
    }
};
Quaternion.prototype.konjugante = function() {
    this.x = -this.x;
    this.y = -this.y;
    this.z = -this.z;
};
if (ENGINE_LOGGING) {
    console.log('Quaternion Class geladen');
}*/