#ifndef INTERPOLATION_H
#define INTERPOLATION_H

namespace common { namespace math {
	template <typename T>
	class LinearInterpolation
	{
	public:
		LinearInterpolation(T start, T goal, sf::Time dt);

		T interpolate();
	private:
		T start;
		T goal;
		sf::Time t0;
		sf::Time t1;
		sf::Clock timer;
	};
}}

#endif