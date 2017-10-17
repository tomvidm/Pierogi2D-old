#include "ConsoleQueue.h"

namespace engine {
    void ConsoleQueue::addDebugLine(const DebugLine& line)
    {
        if (queue_.size() == maxStoredLines_)
        {
            queue_.pop_front();
        }
        queue_.push_back(line);
    }

    std::string ConsoleQueue::getDebugString() const
    {
        std::string output = "";
        for (auto i = begin(); i != end(); i++)
        {
            output.append(i->get());
            output.append("\n");
        }
        return output;
    }
}