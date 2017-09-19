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

    private:
        uint poolSize_ = POOL_SIZE;
        ObjectState objectPoolStates_[POOL_SIZE] = { ObjectState::FREE };//*POOL_SIZE;
        ObjectType objectPool_[POOL_SIZE];
    };

    template <class ObjectType, uint POOL_SIZE>
    Pool<ObjectType, POOL_SIZE>::Pool()
    {
        ;
    }
}