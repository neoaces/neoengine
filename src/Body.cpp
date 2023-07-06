#include "Body.h"
Body* Body::update(float delta) {
    std::queue<Force>* fArr = &v.forces;

    for (int i = 0; i < fArr->size(); i++) {
        Force temp = v.forces.front();
        fArr->pop();

        v.apply(&temp, delta);

        fArr->push(temp);
    }
    
    return this;
}

void Body::log() const {
    std::cout << *this;
}
