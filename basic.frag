#version 330 core
out vec4 FragColor;

in vec3 chNormal;  
in vec3 chFragPos;  
in vec2 chUV;
  
uniform vec3 uLightPos; 
uniform vec3 uViewPos; 
uniform vec3 uLightColor;
uniform float uAlpha;
uniform int uUseTexture;
uniform vec3 uObjectColor;
uniform vec3 uTreasureLightPos;
uniform vec3 uTreasureLightColor;
uniform float uTreasureLightStrength;


uniform sampler2D uDiffMap1;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * uLightColor;

    vec3 norm = normalize(chNormal);
    vec3 lightDir = normalize(uLightPos - chFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * uLightColor;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(uViewPos - chFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * uLightColor;

    vec4 baseColor;
    if (uUseTexture == 1) {
        baseColor = texture(uDiffMap1, chUV);
    } else {
        baseColor = vec4(uObjectColor, 1.0);
    }

    vec3 treasureLight = vec3(0.0);

    if (uTreasureLightStrength > 0.0)
    {
        vec3 tLightDir = normalize(uTreasureLightPos - chFragPos);
        float tDiff = max(dot(norm, tLightDir), 0.0);

        float distance = length(uTreasureLightPos - chFragPos);
        float attenuation = 1.0 / (1.0 + 2.0 * distance * distance);

        treasureLight = tDiff * uTreasureLightColor * attenuation * uTreasureLightStrength;
    }

    vec3 lighting = ambient + diffuse + specular + treasureLight;



    FragColor = vec4(baseColor.rgb * lighting, baseColor.a * uAlpha);
}
