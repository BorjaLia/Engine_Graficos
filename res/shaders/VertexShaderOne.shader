#version 330 core

layout(location = 0) in vec4 position;
layout(location = 2) in vec4 aColor;

uniform vec4 u_Color;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Proj;

out vec4 vColor;

void main()
{
	gl_Position = u_Proj * u_View * u_Model * position;
	vColor = u_Color;
}