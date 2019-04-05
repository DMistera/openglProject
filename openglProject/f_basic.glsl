#version 330 core

uniform vec3 objectColor = vec3(1.0, 0.1, 0.0);
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);

uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 color;

in vec3 i_fragPos;
in vec3 i_normal;

void main(){

	float ambientStrength = 0.5;
	vec3 ambient = ambientStrength * lightColor;

	vec3 norm = normalize(i_normal);
	vec3 lightDir = normalize(lightPos - i_fragPos);  
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float specularStrength = 10.0;
	vec3 viewDir = normalize(viewPos - i_fragPos);
	vec3 reflectDir = reflect(-lightDir, norm); 
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * objectColor;

	color = vec4(result, 1.0);
}