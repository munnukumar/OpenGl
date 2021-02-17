 #version 330 core 
layout(location = 0 ) in vec3 aPos;
//layout(location = 1 ) in vec3 aColor; 
layout(location = 1 ) in vec2 aTexture;

out vec3 ourColor;
out vec2 TexCoord;
//"out vec2 TexCoord; \n"

//uniform mat4 transform; 
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection*view*model*vec4(aPos, 1.0); 
	//gl_Position = vec4(aPos, 1.0f);
	//ourColor = aColor;
	TexCoord = aTexture;













//"gl_Position = vec4(aPos, 1.0); \n"
//"TexCoord = vec2(aTexCoord.x, aTexCoord.y); \n"
/*
if(aPos.x < 0.0) 
{
	color = vec4(1.0, 0.0, 0.0, 1.0); 
}

else if(aPos.x == 0) 
{
	color = vec4(0.0, 1.0, 0.0, 1.0); 
}

else
{
	color = vec4(0.0, 0.0, 1.0, 1.0); 
}*/

}
