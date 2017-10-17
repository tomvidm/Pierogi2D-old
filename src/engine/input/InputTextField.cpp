#include "InputTextField.h"


namespace engine {
namespace input {
    void InputTextField::handleEvent(sf::Event event)
    {
        if (static_cast<int>(event.text.unicode) == 8)
        {
            if (string.size() == 0)
            {
                return;
            }
            else
            {
                string.pop_back();
                return;
            }
        }
        string.push_back((static_cast<int>(event.text.unicode)));
    }
}
}