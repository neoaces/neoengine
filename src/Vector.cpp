#include "Vector.h"
#include <iostream>
void neoengine::Vector::add(Vector *v) {
    this->Ui += v->Ui;
    this->Uj += v->Uj;
};

void neoengine::Vector::scaleM(float sF) {
    this->Ui = this->Ui * sF;
    this->Uj = this->Uj * sF;
};

void neoengine::Vector::apply(Force *f, float delta) {
    f->accel(Ui, Uj, delta);
};


void neoengine::Vector::printVec() const {
    std::cout << "(" << this->getI() << ", " << this->getJ() << ")" << std::endl;
}
