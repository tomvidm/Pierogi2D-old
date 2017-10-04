#pragma once
#include <deque>

#include "DebugLine.h"

namespace engine {
    typedef unsigned int uint;

    class ConsoleQueue
    {
    public:

        // uint getNumLines() const;
        // uint getMaxLines() const;
        // uint getMaxPrintedLines() const;

        // void setMaxPrintedLines(uint maxPrintedLines);
        // void setMaxLines(uint maxLines);

        // void clearLines();
    private:
        uint maxLines_;
        uint maxPrintedLines_;

        std::deque<DebugLine> queue_;
    };
}