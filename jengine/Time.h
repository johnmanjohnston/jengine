#pragma once
#include "GLFW/glfw3.h"

static class Time 
{
protected:
	static double _deltaSeconds;
	static double _lastDelta;

public:
	static double getDeltaSeconds(double glfwTime = -1) 
	{
		double curTime = 0;

		if (glfwTime == -1) 
		{
			curTime = glfwGetTime();
		}

		else { curTime = glfwTime; }

		_deltaSeconds = curTime - _lastDelta;
		_lastDelta = curTime;

		return _deltaSeconds;
	}
};

double Time::_deltaSeconds = -1;
double Time::_lastDelta = -1;