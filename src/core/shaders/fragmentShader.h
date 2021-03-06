static const char* gFragmentShader =
//    "#version 120\n"
//    "varying vec2 UV;\n"
//    "uniform sampler2D myTextureSampler;\n"
//    "void main(){\n"
//    "    //gl_FragColor = texture2D( myTextureSampler, UV );\n"
//    "    gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
//    "}\n";
"#version 120\n"
"// Interpolated values from the vertex shaders\n"
"varying vec2 UV;\n"
"varying vec3 Position_worldspace;\n"
"varying vec3 Normal_cameraspace;\n"
"varying vec3 EyeDirection_cameraspace;\n"
"varying vec3 LightDirection_cameraspace;\n"
"\n"
"// Values that stay constant for the whole mesh.\n"
"uniform sampler2D myTextureSampler;\n"
"uniform mat4 MV;\n"
"uniform vec3 LightPosition_worldspace;\n"
"\n"
"void main(){\n"
"\n"
"    vec3 LightColor = vec3(.6f,.3f,.2f);\n"
"    float LightPower = 5000.0f;\n"
"    vec3 MaterialDiffuseColor = texture2D( myTextureSampler, UV ).rgb;\n"
"    vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;\n"
"    vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);\n"
"\n"
"    float distance = length( LightPosition_worldspace - Position_worldspace );\n"
"    vec3 n = normalize( Normal_cameraspace );\n"
"    vec3 l = normalize( LightDirection_cameraspace );\n"
"    float cosTheta = clamp( dot( n,l ), 0,1 );\n"
"    vec3 E = normalize(EyeDirection_cameraspace);\n"
"    vec3 R = reflect(-l,n);\n"
"    float cosAlpha = clamp( dot( E,R ), 0,1 );\n"
"    gl_FragColor.rgb = MaterialAmbientColor + MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance) + MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance);\n"
"}\n";