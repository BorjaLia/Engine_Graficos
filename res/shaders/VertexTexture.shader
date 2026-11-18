#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord; 
layout(location = 2) in vec4 color;

uniform vec4 u_Color;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Proj;

out vec2 v_TexCoord;
out vec4 v_Color;

void main()
{
	gl_Position = u_Proj * u_Model * position;
	v_TexCoord = texCoord;
    v_Color = u_Color;
}