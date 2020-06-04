#version 330 core

#define ParticuleNb 300

out vec4 FragColor;
  
uniform vec2 particulePos[ParticuleNb];
uniform vec4 particuleColor[ParticuleNb];
uniform float particuleRadius[ParticuleNb];

void main()
{
	
	for(int index = 0; index < ParticuleNb; index ++)
	{
		vec2 iPos = particulePos[index];
		float iRad = particuleRadius[index];
		vec2 pixelPos = gl_FragCoord.xy;

		vec2 diffVec = pixelPos - iPos;
		if(dot(diffVec, diffVec) < iRad * iRad)
		{
			FragColor = particuleColor[index];
			return;
		}
	}
	FragColor = vec4(0.9,0.9,0.9,1);
}