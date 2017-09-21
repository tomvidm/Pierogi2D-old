/*
    This template class represent a fixed-size container. All objects are preallocated
    and "activated" when wanted. New objects are "activated" with incrementing index
    firstFreeObject_, and deactivated object ids are pushed to a linked list, so to ensure
    few holes in the pool for cache hits.

    ObjectState::ACTIVE - Object is in use.
    ObjectState::FREE - Object slot has not been used yet. Internal variable always points to first free slot.
    ObjectState::INACTIVE - previously used slot. Index is kept in a linked list.
*/

#include <list>
#include <iostream>

namespace engine
{
    typedef unsigned int uint;

    const uint TOTALLY_UNUSED   = 0;
    const uint HAS_BEEN_USED    = 1 << 0;
    const uint ACTIVE           = 1 << 1;


    template <class ObjectType, uint POOL_SIZE>
    class Pool
    {
    public:
        Pool();

        inline uint getPoolSize() const { return poolSize_; }
        inline uint getNumObjects() const { return numObjects_; }

        uint activateObject();
        uint getFirstAvailableIndex(uint id = 0) const;
        void deactivateObject(uint id);
        void freeAll();

        void setState(uint id, uint state);
        void addState(uint id, uint state);
        void subState(uint id, uint state);
        void toggleState(uint id, uint state);
        uint getState(uint id) const;

        inline ObjectType& get(uint id) { return objectPool_[id]; }
        
    private:
        uint poolSize_ = POOL_SIZE;
        uint numObjects_ = 0;
        uint firstFreeObject_ = 0;

        uint objectPoolStates_[POOL_SIZE];
        ObjectType objectPool_[POOL_SIZE];
        std::list<uint> freeList_;
    };

    template <class ObjectType, uint POOL_SIZE>
    Pool<ObjectType, POOL_SIZE>::Pool()
    {
        freeAll();
    }

    /*
        When called, an object is "activated" and the index is returned. Adding
        an object is as simple as changing a few flags here. setting up the object and
        assigning sprites etc are left to something else.
    */
    template <class ObjectType, uint POOL_SIZE>
    uint Pool<ObjectType, POOL_SIZE>::activateObject()
    {
        if (!freeList_.empty())
        {
            uint index = freeList_.front();
            objectPoolStates_[index] |= ACTIVE;
            freeList_.pop_front();
            numObjects_ += 1;
            return index;

        }
        else if (numObjects_ < poolSize_)
        {
            objectPoolStates_[firstFreeObject_] = ACTIVE | HAS_BEEN_USED;
            numObjects_ += 1;
            return firstFreeObject_++;
        }
        else
        {
            return -1; // No more space
        }
    }

    /*
        given an index, first the first index which is free and also bigger than the parameter id.
    */
    template <class ObjectType, uint POOL_SIZE>
    uint Pool<ObjectType, POOL_SIZE>::getFirstAvailableIndex(uint id = 0) const
    {
        
        if (freeList_.empty())
        {
            return firstFreeObject_;
        }
        else if (freeList_.back() < id)
        {
            return firstFreeObject_;
        }
        else
        {
            for (auto id_iter : freeList_)
            {
                if (id_iter > id)
                {
                    return id_iter;
                }
            }
            return firstFreeObject_;
        }
    }

    // TODO: Try to modify how the linked list is pushed onto, to always ensure
    // that new objects are set to the first available "hole". (OR: In order. Heap?)
    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::deactivateObject(uint id)
    {
        if (objectPoolStates_[id] & ACTIVE) // If a number is >0, then true
        {
            objectPoolStates_[id] &= ~ACTIVE; // Switch of ACTIVE bit
            freeList_.push_back(id);
            numObjects_ -= 1;
        }
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::setState(uint id, uint state)
    {
        objectPoolStates_[id] = state;
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::addState(uint id, uint state)
    {
        objectPoolStates_[id] |= state;
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::subState(uint id, uint state)
    {
        objectPoolStates_[id] &= ~state;
    }

    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::toggleState(uint id, uint state)
    {
        objectPoolStates_[id] ^= state;
    }

    template <class ObjectType, uint POOL_SIZE>
    uint Pool<ObjectType, POOL_SIZE>::getState(uint id) const
    {
        return objectPoolStates_[id];
    }


    template <class ObjectType, uint POOL_SIZE>
    void Pool<ObjectType, POOL_SIZE>::freeAll()
    {
        for (uint i = 0; i < poolSize_; i++)
        {
            objectPoolStates_[i] = TOTALLY_UNUSED;
            freeList_.clear();
        }
    }
}