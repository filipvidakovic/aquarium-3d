#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

// Lights
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

uniform vec3 treasureLightPos;
uniform vec3 treasureLightColor;

// Material properties
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
    int hasDiffuseMap;
};

uniform Material material;
uniform sampler2D uTex;
uniform int useTexture;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    
    // === GLAVNI IZVOR SVETLOSTI ===
    vec3 lightDir = normalize(lightPos - FragPos);
    
    // Ambient
    vec3 ambient = material.ambient * lightColor;
    
    // Diffuse
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * material.diffuse * lightColor;
    
    // Specular
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = spec * material.specular * lightColor;
    
    // === SVETLO IZ KOVČEGA ===
    vec3 treasureLightDir = normalize(treasureLightPos - FragPos);
    float treasureDiff = max(dot(norm, treasureLightDir), 0.0);
    float distance = length(treasureLightPos - FragPos);
    float attenuation = 1.0 / (1.0 + 0.5 * distance + 1.0 * distance * distance);
    
    vec3 treasureDiffuse = treasureDiff * material.diffuse * treasureLightColor * attenuation;
    
    vec3 treasureReflectDir = reflect(-treasureLightDir, norm);
    float treasureSpec = pow(max(dot(viewDir, treasureReflectDir), 0.0), material.shininess);
    vec3 treasureSpecular = treasureSpec * material.specular * treasureLightColor * attenuation;
    
    // === KOMBINUJ SVETLOSTI ===
    vec3 result = ambient + diffuse + specular + treasureDiffuse + treasureSpecular;
    
    // Primeni teksturu ako postoji
    if (material.hasDiffuseMap == 1) {
        vec4 texColor = texture(uTex, TexCoords);
        result *= texColor.rgb;
        FragColor = vec4(result, texColor.a);
    } else if (useTexture == 1) {
        // Legacy podrška za običnu teksturu
        vec4 texColor = texture(uTex, TexCoords);
        result *= texColor.rgb;
        FragColor = vec4(result, texColor.a);
    } else {
        // Providnost za stakla i mehurće
        float alpha = 1.0;
        if (material.diffuse.b > 0.6 && material.diffuse.b > material.diffuse.r) {
            // Plavo-providni objekti
            alpha = 0.3;
        }
        FragColor = vec4(result, alpha);
    }
}
