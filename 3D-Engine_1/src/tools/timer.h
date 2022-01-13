#pragma once

#include <GLFW/glfw3.h>

namespace tools
{
	class Timer
	{
		double prevTime;
	public:
		Timer()
		{
			prevTime = glfwGetTime();
		}

		// get the time
		double time()
		{
			return glfwGetTime() - prevTime;
		}

		// reset the timer
		void reset()
		{
			prevTime = glfwGetTime();
		}

		// get the time and reset the timer
		double deltaTime()
		{
			double t = time();
			reset();
			return t;
		}
	};
}