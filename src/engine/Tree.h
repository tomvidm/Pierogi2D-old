/*
    Too lazy to add a cpp file, so make it template.
    Purpose of use is to have a simple tree representation
    for hopping around inedxes in object pools.
    The adjacency list is implemented as a map of vectors instead of
    a vector of vectors.
    It can be assumed that not every object har a list of many children, because
    duhhh, a child can only have one parent. Might be more space friendly for many objects.
*/

#include <vector>
#include <map>

namespace engine {
namespace utils {
    typedef unsigned int uint;

    template <typename MappedType>
    struct Relation
    {
        MappedType parent;
        std::vector<MappedType> children;
    };

    template <typename MappedType>
    class Tree
    {
    public:
        void setAsChild(MappedType parent, MappedType child);

        inline MappedType parentOf(MappedType who) { return tree[who].parent; }
        inline std::vector<MappedType> childrenOf(MappedType who) { return tree[who].children; }
    private:
        std::map<MappedType, Relation<MappedType>> tree;
    };


    // TODO: Does not check for ancestry conflict!!!
    template <typename MappedType>
    void Tree<typename MappedType>::setAsChild(MappedType parent, MappedType child)
    {
        tree[parent].children.push_back(child);
        tree[child].parent = parent;
    }

}} // engine::utils