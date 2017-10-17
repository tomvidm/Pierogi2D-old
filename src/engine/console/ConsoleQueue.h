#pragma once
#include <deque>
#include <string>
#include <algorithm>

#include "DebugLine.h"

namespace engine {
    typedef unsigned int uint;
    typedef std::deque<DebugLine>::const_iterator QueueIterator;

    // The ConsoleQueue is a wrapper holding a deque of DebugLine objects.
    // This class takes care of the logic behind showing N lines out of M total lines.
    // It also has a public interface letting the user retrieve a single string
    // representing all of the desired console lines.

    class ConsoleQueue
    {
    public:
        void addDebugLine(const DebugLine& line);

        std::string getDebugString() const;

        inline uint getNumLines() const { return queue_.size(); }
        inline uint getMaxStoredLines() const { return maxStoredLines_; }
        inline uint getMaxPrintedLines() const { return maxPrintedLines_; }

        // void setMaxStoredLines(uint maxLines);
        // void setMaxPrintedLines(uint maxPrintedLines);

        inline void clearLines() { queue_.clear(); }

        inline QueueIterator begin() const { return queue_.cend() - std::min<int>(maxPrintedLines_, queue_.size()); }
        inline QueueIterator end() const { return queue_.cend(); }
    private:
        uint maxStoredLines_ = 10;
        uint maxPrintedLines_ = 10;

        std::deque<DebugLine> queue_;
    };
}