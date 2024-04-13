#pragma once
#include <cassert>
#include <iostream>
#define EASSERT(x, desc) { std::cout << "Asserting " << desc << std::endl; assert(x); }

#define WIDTH 640
#define HEIGHT 640

static class Utility 
{
public:
	static float coord(float px, bool returnX = true) 
	{
		float scWidth = WIDTH;
		float scHeight = HEIGHT;

		if (returnX)
			return (2.0f * px) / scWidth - 1.0f;
		else return
			1.0f - (2.0f * px) / scHeight;
	}
};