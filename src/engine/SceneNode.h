#include <set>

namespace engine
{
    class SceneNode
    {
    public:
        inline bool isRoot() const { return isRoot_; }
    private:
        bool isRoot_ = true;
    }
}