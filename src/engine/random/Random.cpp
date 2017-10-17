#include "Random.h"

namespace engine { namespace random {
    float randFloat()
    {
        return static_cast<float>( rand() / static_cast<float> (RAND_MAX));
    }
}}