#version 330 core 
out vec4 FragColor; 
in vec3 ourColor; 
in vec2 TexCoord;

//uniform float mixValue;
uniform sampler2D texturel; 
uniform sampler2D texture2;
void main()
{
//"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \n"
//FragColor = vec4(ourColor , 1.0f);
//"FragColor = TexCoord; \n"
FragColor = mix(texture(texturel, TexCoord), texture(texture2, TexCoord), 0.2);
//FragColor = vec4(ourColor, 1.0f);
}
