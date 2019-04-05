#version 330 core

#define MAX_LIGHTS 5 //Maximum number of point lights

struct Material {
	vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
    float shininess;
};

struct LightSource {
	vec3 position;

	float constant;
	float linear;
	float quadratic;

	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;
};

uniform Material material;
uniform LightSource lights[MAX_LIGHTS];
uniform vec3 viewPos;

out vec4 color;

in vec3 i_fragPos;
in vec3 i_normal;

vec3 calcPointLight(LightSource light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient  = light.ambientColor  * material.ambientColor;
    vec3 diffuse  = light.diffuseColor  * diff * material.diffuseColor;
    vec3 specular = light.specularColor * spec * material.specularColor;
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
} 

void main() {

	vec3 norm = normalize(i_normal);
	vec3 viewDir = normalize(viewPos - i_fragPos);

	vec3 result = vec3(0.0, 0.0, 0.0);
	for(int i = 0; i < MAX_LIGHTS; i++) {
		result += calcPointLight(lights[i], norm, i_fragPos, viewDir);
	}

	color = vec4(calcPointLight(lights[0], norm, i_fragPos, viewDir), 1.0);
}