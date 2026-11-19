#include "Animation.h"

engine::Animation::Animation(float length, std::string name) :
	name(name),
	currentTime(0),
	currentFrame(0),
	frameLength(length),
	animLength(length),
	speed(1.0f)
{
}
engine::Animation::~Animation(void) {}

void engine::Animation::SetName(std::string newName)
{
	name = newName;
}

void engine::Animation::SetLength(float lenght)
{
	animLength = lenght;
	frameLength = animLength / frames.size();
}

void engine::Animation::SetSpeed(float speed)
{
	this->speed = speed;
	frameLength = (animLength / speed) / frames.size();
}

void engine::Animation::Update()
{
	currentTime += Time::GetDeltaTime();

	while (currentTime > animLength / speed)
	{
		currentTime -= animLength / speed;
	}

	currentFrame = static_cast<int>(currentTime / frameLength);
}

void engine::Animation::AddFrame(math::Rect rect, math::Vector2 textureSize)
{
	Frame frame;

	math::Vector2 texMin = { 0.0f, 0.0f };
	math::Vector2 texMax = { textureSize.x, textureSize.y };
	math::Vector2 uvMin = { 0.0f, 1.0f };
	math::Vector2 uvMax = { 1.0f, 0.0f };

	math::Vector2 rectMax = { rect.pos.x + rect.size.x, rect.pos.y + rect.size.y };

	math::Vector2 topLeft = math::Vector2::Remap(rect.pos, texMin, texMax, uvMin, uvMax);
	math::Vector2 bottomRight = math::Vector2::Remap(rectMax, texMin, texMax, uvMin, uvMax);

	frame.uvCoords[0].u = topLeft.x;
	frame.uvCoords[0].v = bottomRight.y;

	frame.uvCoords[1].u = topLeft.x;
	frame.uvCoords[1].v = topLeft.y;

	frame.uvCoords[2].u = bottomRight.x;
	frame.uvCoords[2].v = topLeft.y;

	frame.uvCoords[3].u = bottomRight.x;
	frame.uvCoords[3].v = bottomRight.y;

	frames.push_back(frame);

	frameLength = (animLength / speed) / frames.size();

	if (frameLength <= 0.0f)
	{
		std::cout << "Animation length can't be negative!" << std::endl;
	}
}

void engine::Animation::AddFrames(math::Rect rect, math::Vector2 textureSize, int framesAmount)
{
	if (framesAmount <= 0)
	{
		std::cout << "Cant load null frames!" << std::endl;
		return;
	}

	if (framesAmount == 1) return AddFrame(rect, textureSize);

	math::Rect frameRect = rect;
	frameRect.size.x = rect.size.x / framesAmount;

	for (int i = 0; i < framesAmount; i++)
	{
		frameRect.pos.x = rect.pos.x + frameRect.size.x * i;
		AddFrame(frameRect, textureSize);
	}

	return;
}

void engine::Animation::AddFrames(math::Rect rect, math::Vector2 textureSize, math::Vector2 framesAmount)
{
	if (framesAmount.x <= 0 || framesAmount.y <= 0)
	{
		std::cout << "Cant load null frames!" << std::endl;
		return;
	}

	if (framesAmount.x == 1 && framesAmount.y == 1) return AddFrame(rect, textureSize);

	math::Rect rowRect = rect;
	rowRect.size.y = rect.size.y / framesAmount.y;

	for (int i = 0; i < framesAmount.y; i++)
	{
		rowRect.pos.y = rect.pos.y + rowRect.size.y * i;
		AddFrames(rowRect, textureSize, static_cast<int>(framesAmount.x));
	}

	return;
}

std::vector<engine::Frame>& engine::Animation::GetFrames()
{
	return frames;
}

int engine::Animation::CurrentFrame()
{
	return currentFrame;
}