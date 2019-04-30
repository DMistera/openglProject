#version 330 core

uniform mat4 p_matrix;
uniform mat4 v_matrix;
//uniform mat4 m_matrix;

layout(location = 0) in vec4 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in vec3 vertexTangent;
layout(location = 4) in mat4 m_matrix;

out vec3 i_fragPos;
out mat3 i_tbn;
out vec2 i_texCoord;


void main(){

	gl_Position = p_matrix*v_matrix*m_matrix*vertexPosition;

	i_fragPos = vec3( m_matrix * vertexPosition);
	i_texCoord = texCoord;

	vec3 t = normalize(vec3(m_matrix * vec4(vertexTangent,   0.0)));
	vec3 n = normalize(vec3(m_matrix * vec4(vertexNormal,    0.0)));
	t = normalize(t - dot(t, n) * n);
	vec3 b = cross(n, t);

	i_tbn = mat3(t, b, n);
}