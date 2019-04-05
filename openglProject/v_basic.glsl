#version 330 core

uniform mat4 p_matrix;
uniform mat4 v_matrix;
uniform mat4 m_matrix;

layout(location = 0) in vec4 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

out vec3 i_fragPos;
out vec3 i_normal;

void main(){

	gl_Position = p_matrix*v_matrix*m_matrix*vertexPosition;

	i_fragPos = vec3( m_matrix * vertexPosition);
	i_normal = mat3(transpose(inverse(m_matrix)))*vertexNormal;
}