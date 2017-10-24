#include "engine/Application.h"
#include "engine/console/Logger.h"

int main(int argc, char* argv[])
{
    engine::console::Logger::getInstancePtr()->setLogLevel(engine::console::LogLevel::VERBOSE);
    // This is the main application
    engine::Application app;
    
    // It has to be started for some reason
    app.start();

    return 0;
}