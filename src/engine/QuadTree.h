#include "Utility.h"

namespace engine {
    template <class ContainedType, unsigned int DEPTH>
    class QuadTree
    {
    private:
        ContainedType data[intPow(4, DEPTH)];
    }

}