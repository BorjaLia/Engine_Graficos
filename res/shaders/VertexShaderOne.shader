#version 330 core

layout(location = 0) in vec4 position;
layout(location = 2) in vec4 aColor;

uniform vec4 u_Color;
uniform mat4 u_MVP;

out vec4 vColor;

void main()
{
	gl_Position = u_MVP * position;
	vColor = u_Color;
}