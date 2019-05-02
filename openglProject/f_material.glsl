#version 330 core

#define MAX_LIGHTS 5 //Maximum number of point lights

struct Material {
	vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
    float shininess;
	sampler2D ambientMap;
	sampler2D diffuseMap;
	sampler2D specularMap;
	sampler2D normalMap;
};

struct LightSource {
	float constant;
	float linear;
	float quadratic;

	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;
};

uniform Material material;
uniform LightSource lights[MAX_LIGHTS];

out vec4 color;

in vec3 i_fragPos;
in vec2 i_texCoord;
in vec3 i_viewPos;
in vec3 i_lightPositions[MAX_LIGHTS];


vec3 calcPointLight(LightSource light, vec3 lightPos, vec3 normal, vec3 fragPos, vec3 viewDir) {

    // ambient
    vec3 ambient = light.ambientColor * vec3(texture(material.diffuseMap, i_texCoord));
  	
    // diffuse 
    vec3 lightDir = normalize(lightPos- fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuseColor * (diff * vec3(texture(material.diffuseMap, i_texCoord)));
    
    // specular
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
    vec3 specular = spec * light.specularColor;  

	//attenuation
	float distance = length(lightPos - fragPos);
	float attenuation = 1.0 / (0.001 + light.constant + light.linear  * distance + light.quadratic * (distance * distance));  

	vec3 result = (ambient + diffuse + specular) * attenuation ;
	return result;
} 

void main() {

	vec3 normal = texture(material.normalMap, i_texCoord).rgb;
	normal = normalize(normal * 2.0 - 1.0);   
	//normal = normalize(i_tbn * normal);

	vec3 viewDir = normalize(i_viewPos - i_fragPos);

	vec4 result = vec4(0.0, 0.0, 0.0, 1.0);

	for(int i = 0; i < MAX_LIGHTS; i++) {
		result += vec4(calcPointLight(lights[i], i_lightPositions[i], normal, i_fragPos, viewDir), 0.0);
	}

	color = result;	
	//color = vec4(1.0, 0.0, 0.0, 1.0);
}