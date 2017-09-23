#include <queue>
#include <stack>
#include <memory>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "AnimatedSprite.h"
#include "TextureHandler.h"
#include "Pool.h"

namespace engine
{
    // Dummy typedefs
    typedef int Command;
    typedef int State;
    typedef int SceneGraph;
    typedef int Event;


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

        TextureHandler textureHandler;
        Pool<graphics::AnimatedSprite, 1024> spriteVector;

        sf::Clock mainClock;
        sf::RenderWindow window; 
        int maxFramePeriod; 

        graphics::AnimatedSprite makeTestSprite();
    };
}