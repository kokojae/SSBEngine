#include "Animation.h"

void Animation::Update()
{
	if (timePerFrame < 0)
	{
		return;
	}

	auto curTime = clock();

	if (lastChangeTime + timePerFrame < curTime)
	{
		lastChangeTime = curTime;

		if (nowFrame.x + frameSize.x + 1.0f >= imageSize.x)
		{
			nowFrame.x = 0;
		}
		else
		{
			nowFrame.x += frameSize.x;
		}
	}
}

void Animation::SetAnimation(std::string textureName)
{
	lastChangeTime = clock();

	if (textureName == "TestImage")
	{
		// clock_t -> 1√  == 1000ms
		timePerFrame = 100;
		frameSize = { 192,108 };
	}
}
