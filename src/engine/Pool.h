/*
    
*/

namespace engine
{
    typedef unsigned int uint;

    enum class ObjectState
    {
        IN_USE,
        FREE,
        DEAD
    };

    template <class ObjectType, uint POOL_SIZE>
    class Pool
    {
    public:
        Pool();

        inline uint getPoolSize() const { return poolSize_; }
        inline uint getNumObjects() const { return numObjects_; }
    private:
        uint poolSize_ = POOL_SIZE;
        uint numObjects_ = 0;
        uint firstFreeObject_ = 0;

        ObjectState objectPoolStates_[POOL_SIZE] = { ObjectState::FREE };//*POOL_SIZE;
        ObjectType objectPool_[POOL_SIZE];
    };

    template <class ObjectType, uint POOL_SIZE>
    Pool<ObjectType, POOL_SIZE>::Pool()
    {
        ;
    }
}