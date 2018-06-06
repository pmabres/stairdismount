

////
//////glClearColor(grey, grey, grey, 1.0f);
//GLfloat radius = 0.3f;
//GLfloat height = 1.0f;
//GLubyte R = 255;
//GLubyte G = 160;
//GLubyte B = 100;
//glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
//GLfloat x              = 0.0;
//GLfloat y              = 0.0;
//GLfloat angle          = 0.0;
//GLfloat angle_stepsize = 0.1;
//
//void Cylinder::draw()
//{
//
///** Draw the tube */
//    glColor3ub(R-40,G-40,B-40);
//    glBegin(GL_QUAD_STRIP);
//    angle = 0.0;
//    while( angle < 2*glm::pi() ) {
//        x = radius * cos(angle);
//        y = radius * sin(angle);
//        glVertex3f(x, y , height);
//        glVertex3f(x, y , 0.0);
//        angle = angle + angle_stepsize;
//    }
//    glVertex3f(radius, 0.0, height);
//    glVertex3f(radius, 0.0, 0.0);
//    glEnd();
//
///** Draw the circle on top of cylinder */
//    glColor3ub(R,G,B);
//    glBegin(GL_POLYGON);
//    angle = 0.0;
//    while( angle < 2*PI ) {
//        x = radius * cos(angle);
//        y = radius * sin(angle);
//        glVertex3f(x, y , height);
//        angle = angle + angle_stepsize;
//    }
//    glVertex3f(radius, 0.0, height);
//    glEnd();
//}
//void Cylinder::setup()
//{
//    Shape::setup();
//}
