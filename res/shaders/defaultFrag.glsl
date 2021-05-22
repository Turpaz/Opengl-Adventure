#version 330 core

#define NOT_SOLID_COLOR false

#define INVALID_TYPE_COLOR vec4(1.f, .2f, .95f, 1.f)

#define MAX_LIGHTS 256
#define POINT_LIGHT_A 3.0f
#define POINT_LIGHT_B 0.7f

out vec4 FragColor;

struct light
{
	int type; // 0 = point, 1 = dir, 2 = spot

	vec3 position;
	vec4 color; // vec4(1.f, 1.f, 1.f, 1.f)
	vec3 direction; // vec3(1.f, 1.f, 0.f)

	float outerCone; // 0.90f
	float innerCone; // 0.95f

	float intenAdd; // 1.0f
	float ambient; // 0.2f
	float specular; // 0.5f
};

in vec3 crntPos;
in vec3 normal;
in vec3 color;
in vec2 texCoord;

uniform sampler2D diffuse0;
uniform sampler2D diffuse1;
uniform sampler2D specular0;
uniform sampler2D specular1;

uniform int nrOfLights;

uniform light lights[MAX_LIGHTS];

uniform vec3 camPos;

vec4 pointLight(light l)
{
	vec3 lightVec = l.position - crntPos;
	float dist = length(lightVec);
	float a = POINT_LIGHT_A;
	float b = POINT_LIGHT_B;
	float inten = 1.0f / (a * dist * dist + b * dist + l.intenAdd);

	float ambient = l.ambient;

	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(lightVec);

	float diffuse = max(dot(norm, lightDirection), 0.0f);

	float specularLight = l.specular;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectionDirection = reflect(-lightDirection, norm);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specularLight * specAmount;

	if (NOT_SOLID_COLOR)
		return texture(diffuse0, texCoord) * l.color * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten;
	else
		return vec4(color, 1.f) * l.color * (diffuse * inten + ambient) + vec4(color, 1.f) * specular * inten;
}

vec4 direcLight(light l)
{
	float ambient = l.ambient;

	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(l.direction);

	float diffuse = max(dot(norm, lightDirection), 0.0f);

	float specularLight = l.specular;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectionDirection = reflect(-lightDirection, norm);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specularLight * specAmount;

	if (NOT_SOLID_COLOR)
		return texture(diffuse0, texCoord) * l.color * (diffuse + ambient) + texture(specular0, texCoord).r * specular;
	else
		return vec4(color, 1.f) * l.color * (diffuse + ambient) + vec4(color, 1.f) * specular;
}

vec4 spotLight(light l)
{
	float outerCone = l.outerCone;
	float innerCone = l.innerCone;

	vec3 direction = l.direction;

	float ambient = l.ambient;

	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(l.position - crntPos);

	float diffuse = max(dot(norm, lightDirection), 0.0f);

	float specularLight = l.specular;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectionDirection = reflect(-lightDirection, norm);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specularLight * specAmount;

	float angle = dot(direction, -lightDirection);
	float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);

	if (NOT_SOLID_COLOR)
		return texture(diffuse0, texCoord) * l.color * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten;
	else
		return vec4(color, 1.f) * l.color * (diffuse * inten + ambient) + vec4(color, 1.f) * specular * inten;
}

void main()
{
	vec4 endcolor = vec4(0.f);

	for (int i = 0; i < nrOfLights; i++)
	{
		if (lights[i].type == 0)
			endcolor += pointLight(lights[i]);
		else if (lights[i].type == 1)
			endcolor += direcLight(lights[i]);
		else if (lights[i].type == 2)
			endcolor += spotLight(lights[i]);
		else
			endcolor = INVALID_TYPE_COLOR;
	}

	FragColor = endcolor;
}