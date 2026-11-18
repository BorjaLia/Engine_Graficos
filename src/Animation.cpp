#include "Animation.h"

engine::Animation::Animation(std::string name) :
	name(name),
	currentTime(0),
	currentFrame(0),
	length(1000)
{
}
engine::Animation::~Animation(void) {}

DllExport void engine::Animation::SetName(std::string newName)
{
	name = newName;
}

void engine::Animation::Update()
{
	currentTime += Time::GetDeltaTime();

	while(currentTime > length) 
	{
		currentTime -= length;
		std::cout << "reset anim" << std::endl;
	}
	
	float frameLength = length / frames.size();
	currentFrame = static_cast<int>(currentTime / frameLength);
}

void engine::Animation::AddFrame(float frameX, float frameY,
	float frameWidth, float frameHeigth,
	float textureWidth, float textureHeigth,
	float durationInSecs)
{
	length = durationInSecs * 1000;
	Frame frame;

	float flippedY = textureHeigth - frameY - frameHeigth;

	frame.uvCoords[0].u = (frameX / textureWidth);
	frame.uvCoords[0].v = (flippedY / textureHeigth);

	frame.uvCoords[1].u = (frameX / textureWidth);
	frame.uvCoords[1].v = ((flippedY + frameHeigth) / textureHeigth);

	frame.uvCoords[2].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[2].v = ((flippedY + frameHeigth) / textureHeigth);

	frame.uvCoords[3].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[3].v = (flippedY / textureHeigth);

	frames.push_back(frame);
}

void engine::Animation::AddFrame(float frameX, float frameY,
	float frameWidth, float frameHeigth,
	float textureWidth, float textureHeigth,
	float durationInSecs,
	int frameCount)
{
	length = durationInSecs * 1000;

	float frameXIndex = 0;

	for (int i = 0; i < frameCount; i++)
	{
		Frame frame;

		frame.uvCoords[0].u = (frameX / textureWidth);
		frame.uvCoords[0].v = (frameY / textureHeigth);

		frame.uvCoords[1].u = (frameX / textureWidth);
		frame.uvCoords[1].v = ((frameY + frameHeigth) / textureHeigth);

		frame.uvCoords[2].u = ((frameX + frameWidth) / textureWidth);
		frame.uvCoords[2].v = ((frameY + frameHeigth) / textureHeigth);

		frame.uvCoords[3].u = ((frameX + frameWidth) / textureWidth);
		frame.uvCoords[3].v = (frameY / textureHeigth);

		frames.push_back(frame);
		frameXIndex += frameWidth;
	}
}

void engine::Animation::AddFrame(math::Vector2 framePos, math::Vector2 frameSize, math::Vector2 textureSize, float durationInSecs)
{
	AddFrame(framePos.x, framePos.y, frameSize.x, frameSize.y, textureSize.x, textureSize.y, durationInSecs);
}

void engine::Animation::AddFrame(math::Vector2 framePos, math::Vector2 frameSize, math::Vector2 textureSize, float durationInSecs, int frameCount)
{
	AddFrame(framePos.x, framePos.y, frameSize.x, frameSize.y, textureSize.x, textureSize.y, durationInSecs,frameCount);
}

std::vector<engine::Frame>& engine::Animation::GetFrames()
{
	return frames;
}

int engine::Animation::CurrentFrame()
{
	return currentFrame;
}