#include <queue>
#include <stack>
#include <memory>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

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

    class Application
    {
    public:
        void enterLoop();
    private:
        void loop();

        sf::Clock mainClock;
        sf::RenderWindow window; 
        int maxFramePeriod; 
    };
}