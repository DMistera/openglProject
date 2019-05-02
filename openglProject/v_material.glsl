#version 330 core

#define MAX_LIGHTS 5 //Maximum number of point lights

uniform mat4 p_matrix;
uniform mat4 v_matrix;
//uniform mat4 m_matrix;
uniform vec3 viewPos;
uniform vec3 lightPositions[MAX_LIGHTS];

layout(location = 0) in vec4 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in vec3 vertexTangent;
layout(location = 4) in mat4 m_matrix;

out vec3 i_fragPos;
out vec2 i_texCoord;
out mat3 i_tbn;
out vec3 i_viewPos;

out vec3 i_lightPositions[MAX_LIGHTS];

void main(){

	gl_Position = p_matrix*v_matrix*m_matrix*vertexPosition;

	vec3 t = normalize(vec3(m_matrix * vec4(vertexTangent,   0.0)));
	vec3 n = normalize(vec3(m_matrix * vec4(vertexNormal,    0.0)));
	t = normalize(t - dot(t, n) * n);
	vec3 b = cross(n, t);

	i_tbn = transpose(mat3(t, b, n));
	i_fragPos = i_tbn*vec3(m_matrix * vertexPosition);

	i_texCoord = texCoord;
	i_viewPos = i_tbn * viewPos;
	for(int i = 0; i < MAX_LIGHTS; i++) {
		i_lightPositions[i] = i_tbn*lightPositions[i];
	}
}