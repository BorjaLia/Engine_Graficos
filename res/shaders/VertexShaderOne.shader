#version 330 core

layout(location = 0) in vec4 position;
layout(location = 2) in vec4 aColor;

uniform vec4 u_Color;

out vec4 vColor;

void main()
{
	gl_Position = position;
	vColor = u_Color;
}