#include "FrameData.h"

namespace engine {

	void printFrame(Frame frame)
	{
		using std::cout;
		using std::endl;
		cout << frame.duration << ", "
			 << frame.texRect.left << ", "
		     << frame.texRect.top << ", "
             << frame.texRect.width << ", "
		     << frame.texRect.height << endl;
	}

    sf::Rect<int> FrameData::getFrameRect(int index) const
    {
        return frames[index].texRect;
    }

    int FrameData::getFrameDuration(int index) const
    {
        return frames[index].duration;
    }
}
