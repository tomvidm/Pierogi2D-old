/*
    This template class represent a fixed-size container. All objects are preallocated
    and "activated" when wanted. New objects are "activated" with incrementing index
    firstFreeObject_, and deactivated object ids are pushed to a linked list, so to ensure
    few holes in the pool for cache hits.
*/

#include <list>
#include <iostream>

namespace engine
{
    typedef unsigned int uint;

    enum class ObjectState
    {
        ACTIVE,
        FREE,
        INACTIVE
    };

    template <class ObjectType, uint POOL_SIZE>
    class Pool
    {
    public:
        Pool();

        inline uint getPoolSize() const { return poolSize_; }
        inline uint getNumObjects() const { return numObjects_; }

        uint activateObject();
        void deactivateObject(uint id);
        void freeAll();

        void printInfo() const;
    private:
        uint poolSize_ = POOL_SIZE;
        uint numObjects_ = 0;
        uint firstFreeObject_ = 0;

        ObjectState objectPoolStates_[POOL_SIZE] = { ObjectState::FREE };
        ObjectType objectPool_[POOL_SIZE];
        std::list<uint> freeList_;
    };

    template <class ObjectType, uint POOL_SIZE>
    Pool<ObjectType, POOL_SIZE>::Pool()
    {
        freeAll();
    }

    template <class ObjectType, uint POOL_SIZE>
    uint Pool<ObjectType, POOL_SIZE>::activateObject()
    {
        if (!freeList_.empty())
        {
            uint index = freeList_.front();
            objectPoolStates_[index] = ObjectState::ACTIVE;
            freeList_.pop_front();
            numObjects_ += 1;
            return index;

        }
        else if (numObjects_ < poolSize_)
        {
            objectPoolStates_[firstFreeObject_] = ObjectState::ACTIVE;
            numObjects_ += 1;
            return firstFreeObject_++;
        }
        else
        {
            return -1; // No more space
        }
    }

    // TODO: Try to modify how the linked list is pushed onto, to always ensure
    // that new objects are set to the first available "hole".
    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::deactivateObject(uint id)
    {
        if (objectPoolStates_[id] == ObjectState::ACTIVE)
        {
            objectPoolStates_[id] = ObjectState::INACTIVE;
            freeList_.push_back(id);
            numObjects_ -= 1;
        }
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::freeAll()
    {
        for (uint i = 0; i < poolSize_; i++)
        {
            objectPoolStates_[i] = ObjectState::FREE;
            freeList_.clear();
        }
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::printInfo() const
    {
        for (int i = 0; i < poolSize_; i++)
        {
            switch (objectPoolStates_[i])
            {
            case ObjectState::ACTIVE:
                std::cout << "A";
                break;
            case ObjectState::FREE:
                std::cout << "F";
                break;
            case ObjectState::INACTIVE:
                std::cout << "x";
                break;
            }
        }
        std::cout << std::endl;
    }
}