#include "Animation.h"
#include "GraphicManager.h"

Animation::Animation() : textureName(""), imageSize({ 0,0 }), frameSize({ 0,0 }), nowFrame({ 0,0 }),
lastChangeTime(0), timePerFrame(0)
{
}

Animation::~Animation()
{
}

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
	timePerFrame = -1;
	this->textureName = textureName;
	frameSize = imageSize = GraphicManager::GetTextureSize(textureName);

	lastChangeTime = clock();

	if (textureName == "TestImage")
	{
		// clock_t -> 1√  == 1000ms
		timePerFrame = 500;
		frameSize = { 192,108 };
	}
}

RECT Animation::GetRect()
{
	int left	= nowFrame.x;
	int top		= 0;
	int right	= left + frameSize.x;
	int bottom	= top + frameSize.y;

	return { left,top,right,bottom };
}
