#include "ConsoleQueue.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace engine {
namespace console {
    class DebugConsole : public sf::Drawable, public sf::Transformable
    {
    public:
        void handleInput();
        void update();
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void initDefaultConsoleFont();
        void addLine(std::string line);
    private:
        sf::Text textField;
        sf::Font font;
        ConsoleQueue consoleQueue;
    };
}
}