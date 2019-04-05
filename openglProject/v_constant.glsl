#version 330 core

uniform mat4 p_matrix;
uniform mat4 v_matrix;
uniform mat4 m_matrix;

layout(location = 0) in vec4 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

void main(){

	gl_Position = p_matrix*v_matrix*m_matrix*vertexPosition;
}