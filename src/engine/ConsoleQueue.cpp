#include "ConsoleQueue.h"

namespace engine {
    void ConsoleQueue::addDebugLine(const DebugLine& line)
    {
        if (queue_.size() == maxStoredLines)
        {
            queue_.pop_front();
        }
        queue_.push_back(line);
    }
}