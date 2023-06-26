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

void Vector::printVec() {
    std::cout << "(" << this->getI() << ", " << this->getJ() << ")" << std::endl;
};