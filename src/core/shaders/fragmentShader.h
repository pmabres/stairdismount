static const char gFragmentShader[] =
    "#version 120\n"
    "varying vec2 UV;\n"
    "uniform sampler2D myTextureSampler;\n"
    "void main(){\n"
    "    //gl_FragColor = texture2D( myTextureSampler, UV );\n"
    "    gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
    "}\n";