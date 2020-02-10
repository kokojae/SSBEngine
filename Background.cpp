#include "Background.h"
#include "Animation.h"

Background::Background()
{
}

Background::~Background()
{
}

void Background::Init()
{
	animation->SetAnimation("TestBack");
	position = { 0.0f,0.0f };
}
