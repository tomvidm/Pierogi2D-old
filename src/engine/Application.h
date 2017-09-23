#include <queue>
#include <stack>
#include <memory>

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
        void start();
    private:
        void resourceThread();
        void eventThread();
        void mainThread();
        
        StatePtrStack statePtrStack_;       // States go here
        CommandQueue commandQueue_;         // External commands go here
        EventQueue eventQueue_;             // Global events go here
        SceneGraph sceneGraph_;             // All objects go here
        ResourceHandler resourceHandler_;   // Resource handler
    }
}