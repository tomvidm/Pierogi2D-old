#include <queue>
#include <stack>
#include <memory>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "AnimatedSprite.h"

namespace engine
{
    // Dummy typedefs
    typedef int Command;
    typedef int State;
    typedef int SceneGraph;
    typedef int Event;
    typedef int ResourceHandler;


    // Non-dummy typedefs
    typedef std::unique_ptr<State> StatePtr;
    typedef std::stack<StatePtr> StatePtrStack;
    typedef std::queue<Command> CommandQueue;
    typedef std::queue<Event> EventQueue;

    /*
        Very shitty application class so far.
    */

    class Application
    {
    public:
        void enterLoop();
        void testAnimation();
    private:
        void loop();
        void drawSprites();

        sf::Texture texture; // DELET DIS!!!
        std::vector<graphics::AnimatedSprite> spriteVector;

        sf::Clock mainClock;
        sf::RenderWindow window; 
        int maxFramePeriod; 
    };
}