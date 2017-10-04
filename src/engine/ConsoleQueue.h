#pragma once
#include <deque>

#include "DebugLine.h"

namespace engine {
    typedef unsigned int uint;
    typedef std::deque<DebugLine>::const_iterator QueueIterator;
    class ConsoleQueue
    {
    public:

        // uint getNumLines() const;
        // uint getMaxLines() const;
        // uint getMaxPrintedLines() const;

        // void setMaxPrintedLines(uint maxPrintedLines);
        // void setMaxLines(uint maxLines);

        // void clearLines();

        inline QueueIterator begin() const { return queue_.cbegin(); }
        inline QueueIterator end() const { return queue_.cend(); }
    private:
        uint maxLines_;
        uint maxPrintedLines_;

        std::deque<DebugLine> queue_;
    };
}