#include "Force.h"
#include <queue>
#include <iostream>

class Vector {
    float Ui; /// Unit i vector along x-axis
    float Uj; /// Unit j vector along y-axis

public:
    std::queue<Force> forces;

    /**
     * @brief Construct a new Vector object
     *
     * @param x Magnitude in x relative to the i vector.
     * @param y Magnitude in y relative to the j vector.
     */
    Vector(float x, float y) : Ui(x), Uj(y) {
        Force g = Force(0, 9.8);
        forces.push(g); /// Unless the plane is weightless, gravity will always be a force.
    };

    /**
     *@brief Adds vector v onto the primary vector
     *
     * @param v Instance of vector to be added
     */
    void add(Vector v);

    /**
     *@brief Scales the vector by vector v
     *
     * @param sF Scale factors
     */
    void scaleM(float sF); // Change int type into ctime in seconds

    float getI() { return Ui; };
    float getJ() { return Uj; };

    /**
     *@brief Prints out the vector's x and y coordinates relative to the i and j vectors.
     *
     */

    void printVec();

    /**
     *@brief Apply the force on the velocity of the vector.
     *
     * @param f Force to be applied
     * @param delta Time elapsed
     */
    void apply(Force* f, float delta) {
        f->accel(Ui, Uj, delta);
    };
};
