#include "NeoEngine.h"

#ifndef IOSTREAM_DEC
#include <iostream>
#define IOSTREAM_DEC
#endif

#include <cstdio>
#include "Body.h"
#include "GraphicsEngine.h"

using namespace neoengine;

int main() {
    Body body(1.0f, 2.0f, 0, 0);
    std::cout << "Base state: " << body;
    body.update(1.0f)->log();
    body.update(1.0f)->log();
    body.update(1.0f)->log();

    NeoEngine engine{};

    return engine.run();
}

// https://gafferongames.com/post/fix_your_timestep/

