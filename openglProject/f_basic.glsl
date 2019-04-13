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
in vec2 i_texCoord;

vec3 calcPointLight(LightSource light, vec3 normal, vec3 fragPos, vec3 viewDir) {

    // ambient
    vec3 ambient = light.ambientColor * material.ambientColor;
  	
    // diffuse 
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuseColor * (diff * material.diffuseColor);
    
    // specular
    vec3 reflectDir = reflect(-lightDir, normal);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = spec * light.specularColor;  
        
    vec3 result = (ambient + diffuse + specular)*material.ambientColor ;
    return result;
} 

void main() {

	vec3 norm = normalize(i_normal);
	vec3 viewDir = normalize(viewPos - i_fragPos);

	//vec4 result = vec4(1.0, 0.0, 1.0, 1.0);
	vec4 result = texture(material.diffuseMap, i_texCoord);
	//vec4 result = vec4(i_texCoord, 0.0, 1.0);

	for(int i = 0; i < MAX_LIGHTS; i++) {
		result += vec4(calcPointLight(lights[i], norm, i_fragPos, viewDir), 1.0);
	}

	color = result;	
}