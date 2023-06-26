class Force {
    const float ax;
    const float ay;
public:
    /**
     *@brief Construct a new Force object with acceleration given
     *
     * @param accx Acceleration in x (i vector)
     * @param accy Acceleration in y (j vector)
     */
    Force(float accx, float accy) : ax(accx), ay(accy) {};
    Force() : ax(0), ay(0) {};

    /**
     *@brief Calculate the final velocity of the body through the velocity and the delta time. The acceleration constant used here is 9.8m/s.
     *
     * @param vy (m/s) Velocity of body
     * @param delta (seconds) Time elapsed since last update
     */
    void accel(float& vx, float& vy, float delta) {
        vx = (vx + (ax * delta));
        vy = (vy + (ay * delta));
    };
};
