#include "Vector.h"
#include <iostream>
void Vector::add(Vector v) {
    this->Ui += v.Ui;
    this->Uj += v.Uj;
};

void Vector::scaleM(float sF) {
    this->Ui = this->Ui * sF;
    this->Uj = this->Uj * sF;
};

void Vector::apply(Force *f, float delta) {
    f->accel(Ui, Uj, delta);
};


void Vector::printVec() const {
    std::cout << "(" << this->getI() << ", " << this->getJ() << ")" << std::endl;
}