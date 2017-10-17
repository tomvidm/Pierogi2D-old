#include "ConsoleQueue.h"

#include "SFML/graphics.hpp"

namespace engine {
namespace console {
    class DebugConsole
    {
    public:
        void handleInput();
        void update();
        void initDefaultConsoleFont();
    private:
        sf::Text* textField;
        ConsoleQueue consoleQueue;
    }
}
}