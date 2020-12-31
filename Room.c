#include <GL/glut.h>


static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 1;  // axis z

// specify light properties below

  GLfloat light0_pos[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light0_spec[] = {0.0, 0.0, 1.0, 1.0};  // red
  GLfloat light0_amb[] = {1.0, 1.0, 1.0, 1.0};  // green
  GLfloat light0_diff[] = {1.0, 1.0, 0.0, 1.0}; // gb

  GLfloat light1_pos[] = {-1.0, 0.0, 3.0, 1.0};
  GLfloat light1_spec[] = {0.2, 0.0, 0.0, 1.0};  // red
  GLfloat light1_amb[] = {0.0, 1.0, 0.0, 1.0};  // green
  GLfloat light1_diff[] = {0.0, 0.0, 1.0, 1.0}; // gb

  GLfloat light2_pos[] = {-1.0, 0.0, 1.5, 1.0};
  GLfloat light2_spec[] = {0.0, 0.0, 1.0, 1.0};  // red
  GLfloat light2_amb[] = {1.0, 1.0, 1.0, 1.0};  // green
  GLfloat light2_diff[] = {1.0, 1.0, 0.0, 1.0}; // gb

// specify material properties below

typedef struct materialStruct {
  	GLfloat ambient[4];
  	GLfloat diffuse[4];
  	GLfloat specular[4];
}

materialStruct;

materialStruct lit = {
        {1.0, 1.0, 1.0, 1.0},
        {0.01, 0.01, 0.01, 1.0},
        {0.5, 0.5, 0.5, 1.0}
} ;

materialStruct libr = {
        {0.329, 0.224, 0.027, 1.0},
        {0.780, 0.569, 0.114, 1.0},
        {0.992, 0.941, 0.808, 1.0}
} ;

materialStruct brwn = {
  	{0.212, 0.127, 0.054, 1.0},
  	{0.714, 0.428, 0.181, 1.0},
  	{0.394, 0.272, 0.167, 1.0}
} ;

materialStruct wood = {
        {0.247, 0.199, 0.075, 1.0},
        {0.752, 0.606, 0.226, 1.0},
        {0.628, 0.556, 0.366, 1.0}
} ;

materialStruct red = {
        {0.0, 0.0, 0.0, 1.0},
        {0.5, 0.0, 0.0, 1.0},
        {0.7, 0.6, 0.6, 1.0}
} ;

materialStruct polsilv = {
	{0.231, 0.231, 0.231, 1.0},
  	{0.278, 0.278, 0.278, 1.0},
  	{0.774, 0.774, 0.774, 1.0}
} ;

materialStruct wall = {
        {0.1, 0.187, 0.175, 1.0},
        {0.396, 0.74, 0.69, 1.0},
        {0.297, 0.308, 0.306, 1.0}
} ;

materialStruct flr = {
        {0.106, 0.058, 0.114, 1.0},
        {0.427, 0.47, 0.541, 1.0},
        {0.33, 0.33, 0.522, 1.0}
} ;


void materials(materialStruct *materials) {
  	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materials -> ambient);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materials -> diffuse);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materials -> specular);
}


void colorobject( void ) {

GLUquadricObj *cyl;
cyl = gluNewQuadric();
gluQuadricDrawStyle(cyl, GLU_FILL);

	//Lamp:
	glPushMatrix();
		glTranslatef(-1.75, -1.69, 1.75);

		//Bulb:
		glPushMatrix();
			materials(&lit);

			glTranslatef(0.0, 1.75, 0.0);
			glutSolidSphere(0.075, 100, 100);
		glPopMatrix();

		//Shade:
                glPushMatrix();
                        materials(&polsilv);

			glTranslatef(0.0, 1.5, 0.0);
                        glRotatef(270, 1.0, 0.0, 0.0);
                        gluCylinder(cyl, 0.205, 0.205, 0.45, 100, 100);
                glPopMatrix();

                //Stand:
                glPushMatrix();
                        materials(&polsilv);

                        glRotatef(270, 1.0, 0.0, 0.0);
                        gluCylinder(cyl, 0.0125, 0.0125, 1.8, 100, 100);
                glPopMatrix();


		//Base:
                glPushMatrix();
                        materials(&polsilv);

                        glRotatef(270, 1.0, 0.0, 0.0);
                        gluCylinder(cyl, 0.225, 0.225, 0.04, 100, 100);
                glPopMatrix();

                glPushMatrix();
                        materials(&polsilv);

                        glTranslatef(0.0, 0.025, 0.0);
                        glRotatef(270, 1.0, 0.0, 0.0);
                        glutSolidCone(0.225, 0.01, 100, 100);
                glPopMatrix();
	glPopMatrix();

	//Ceiling Lights:
	glPushMatrix();
		glTranslatef(-1.0, 1.52, 0.0);

		glPushMatrix();
			materials(&lit);

			glScalef(0.25, 0.095, 0.35);
			glTranslatef(0.0, -2.75, 0.0);
			glutSolidCube(2.0);
		glPopMatrix();

		glPushMatrix();
			materials(&polsilv);

			glScalef(0.0375, 0.175, 0.0375);
			glTranslatef(0.0, 0.0, 6.0);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&polsilv);

                        glScalef(0.0375, 0.175, 0.0375);
                        glTranslatef(0.0, 0.0, -6.0);
                        glutSolidCube(2.0);
                glPopMatrix();
	glPopMatrix();

        glPushMatrix();
                glTranslatef(1.0, 1.52, 0.0);

                glPushMatrix();
                        materials(&lit);

                        glScalef(0.25, 0.095, 0.35);
                        glTranslatef(0.0, -2.75, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&polsilv);

                        glScalef(0.0375, 0.175, 0.0375);
                        glTranslatef(0.0, 0.0, 6.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&polsilv);

                        glScalef(0.0375, 0.175, 0.0375);
                        glTranslatef(0.0, 0.0, -6.0);
                        glutSolidCube(2.0);
                glPopMatrix();
        glPopMatrix();

	//Desk Lamp:
	glPushMatrix();
		glTranslatef(0.55, -0.65, -1.4);

		//Base:
		glPushMatrix();
			materials(&polsilv);

			glRotatef(270, 1.0, 0.0, 0.0);
			gluCylinder(cyl, 0.175, 0.175, 0.03, 100, 100);
		glPopMatrix();

		glPushMatrix();
			materials(&polsilv);

			glTranslatef(0.0, 0.025, 0.0);
			glRotatef(270, 1.0, 0.0, 0.0);
			glutSolidCone(0.175, 0.01, 100, 100);
		glPopMatrix();

		//Stand:
		glPushMatrix();
			materials(&polsilv);

			glRotatef(270, 1.0, 0.0, 0.0);
			gluCylinder(cyl, 0.0105, 0.0105, 0.75, 100, 100);
		glPopMatrix();

		glPushMatrix();
                        materials(&polsilv);

			glTranslatef(0.0, 0.75, 0.0);
                        glRotatef(200, 1.0, 0.0, 0.0);
			glRotatef(45, 0.0, 1.0, 0.0);
                        gluCylinder(cyl, 0.0105, 0.0105, 0.45, 100, 100);
                glPopMatrix();

		//Lamp Head:
		glPushMatrix();

			glTranslatef(0.35, 0.8, -0.3);
			glRotatef(20, 0.0, 0.0, 1.0);

	                glPushMatrix();
        	                materials(&polsilv);

                	        glRotatef(270, 1.0, 0.0, 0.0);
                        	gluCylinder(cyl, 0.1, 0.1, 0.075, 100, 100);
                	glPopMatrix();

                	glPushMatrix();
                        	materials(&polsilv);

                        	glTranslatef(0.0, 0.065, 0.0);
				glRotatef(270, 1.0, 0.0, 0.0);
                        	glutSolidCone(0.1, 0.01, 100, 100);
                	glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	//Teapots:
        glPushMatrix();
                materials(&red);

                glScalef(1.0, 1.0, 1.0);
                glTranslatef(-2.225, 0.605, 0.0);
		glRotatef(55, 0.0, 1.0, 0.0);
                glutSolidTeapot(0.1);
        glPopMatrix();

	glPushMatrix();
		materials(&red);

		glScalef(1.0, 1.0, 1.0);
		glTranslatef(1.3, -0.52, -1.75);
		glutSolidTeapot(0.175);
	glPopMatrix();

	//Chair:
	glPushMatrix();
		glTranslatef(1.0, -1.38, -0.75);
		glRotatef(17, 0.0, -1.0, 0.0);

		glPushMatrix();
			materials(&wood);

			glScalef(0.3, 0.035, 0.3);
			glTranslatef(0.0, 9.0, 0.0);
			glutSolidCube(2.0);
		glPopMatrix();

		glPushMatrix();
			materials(&brwn);

			glScalef(0.175, 0.035, 0.025);
			glTranslatef(0.0, 24.0, 9.5);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.175, 0.035, 0.025);
                        glTranslatef(0.0, 14.5, 9.5);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.03, 0.325, 0.03);
                        glTranslatef(-6.0, 2.0, 8.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.03, 0.325, 0.03);
                        glTranslatef(6.0, 2.0, 8.0);
                        glutSolidCube(2.0);
                glPopMatrix();


		glPushMatrix();
			materials(&brwn);

			glScalef(0.025, 0.3, 0.025);
			glTranslatef(-10.5, 0.0, -10.5);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.025, 0.3, 0.025);
                        glTranslatef(10.5, 0.0, -10.5);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.025, 0.3, 0.025);
                        glTranslatef(-10.5, 0.0, 10.5);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.025, 0.3, 0.025);
                        glTranslatef(10.5, 0.0, 10.5);
                        glutSolidCube(2.0);
                glPopMatrix();

	glPopMatrix();
	//Table:
	glPushMatrix();

		glTranslatef(1.0, -1.2, -1.64);

		glPushMatrix();
			materials(&wood);

			glScalef(0.9, 0.035, 0.7);
			glTranslatef(0.0, 15.0, 0.0);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&wood);

                        glScalef(0.75, 0.035, 0.55);
                        glTranslatef(0.0, 12.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

		glPushMatrix();

			materials(&brwn);

			glScalef(0.035, 0.5, 0.035);
			glTranslatef(-20.5, 0.0, -16.5);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.035, 0.5, 0.035);
                        glTranslatef(20.5, 0.0, -16.5);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.035, 0.5, 0.035);
                        glTranslatef(-20.5, 0.0, 16.5);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.035, 0.5, 0.035);
                        glTranslatef(20.5, 0.0, 16.5);
                        glutSolidCube(2.0);
                glPopMatrix();

	glPopMatrix();

	//Shelf 1:
	glPushMatrix();

		glTranslatef(0.0, 0.0, -2.24);

		glPushMatrix();
                        materials(&brwn);

                        glScalef(0.65, 0.015, 0.1);
                        glTranslatef(1.75, 35.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

		glPushMatrix();
			materials(&brwn);

			glScalef(0.015, 0.1, 0.1);
			glTranslatef(31.5, 6.1, 0.0);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.015, 0.1, 0.1);
                        glTranslatef(119.5, 6.1, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();
	glPopMatrix();

        //Shelf 2:
        glPushMatrix();

                glRotatef(90, 0.0, 1.0, 0.0);
                glTranslatef(-1.0, 0.0, -2.24);

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.65, 0.015, 0.1);
                        glTranslatef(1.75, 35.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.015, 0.1, 0.1);
                        glTranslatef(31.5, 6.1, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&brwn);

                        glScalef(0.015, 0.1, 0.1);
                        glTranslatef(119.5, 6.1, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();
        glPopMatrix();

	//ROOM:
	glPushMatrix();

		glScalef(1.25, 1.25, 1.25);

		//Floor:
		glPushMatrix();
			materials(&flr);

			glScalef(1.25, 0.01, 1.25);
			glTranslatef(0.0, -136.0, 0.0);
			glutSolidCube(3.0);
		glPopMatrix();

		//Wall 1:
		glPushMatrix();
			materials(&wall);

			glScalef(0.01, 0.9, 1.25);
			glTranslatef(186.0, 0.005, 0.0);
			glutSolidCube(3.0);
		glPopMatrix();

        	//Wall 2:
        	glPushMatrix();
                	materials(&wall);

                	glScalef(0.01, 0.9, 1.25);
			glTranslatef(-186.0, 0.005, 0.0);
			glutSolidCube(3.0);
        	glPopMatrix();

        	//Wall 3:
        	glPushMatrix();
                	materials(&wall);

                	glScalef(1.25, 0.9, 0.01);
                	glTranslatef(0.0, 0.005, -186.0);
                	glutSolidCube(3.0);
        	glPopMatrix();

		//Ceiling:
//        	glPushMatrix();
//                	materials(&wall);

//                	glScalef(1.25, 0.01, 1.25);
//                	glTranslatef(0.0, 136.0, 0.0);
//                	glutSolidCube(3.0);
//        	glPopMatrix();

	glPopMatrix();

        //Closet:
        glPushMatrix();

		glScalef(1.15, 1.25, 1.1);
		glTranslatef(-1.0, -0.35, -1.8);

		glPushMatrix();
                	materials(&wood);

	                glScalef(0.6, 1.0, 0.01);
                	glTranslatef(0.0, 0.0, -25.0);
                	glutSolidCube(2.0);
	        glPopMatrix();

		//Door 1:
	                glPushMatrix();
                        	materials(&wood);

                        	glScalef(0.3, 1.0, 0.01);
                        	glTranslatef(1.01, 0.0, 25.0);
                        	glutSolidCube(2.0);
                	glPopMatrix();

			glPushMatrix();
				materials(&brwn);

				glTranslatef(0.1, -0.05, 0.28);
				glRotatef(180, 1.0, 0.0, 0.0);
				glutSolidCone(0.04, 0.04, 100, 100);
			glPopMatrix();
		//
		//Door 2:
			glPushMatrix();
                        	materials(&wood);

				glRotatef(25, 0.0, -1.0, 0.0);
                        	glScalef(0.3, 1.0, 0.01);
                        	glTranslatef(-0.5, 0.0, 47.005);
                        	glutSolidCube(2.0);
                	glPopMatrix();

                        glPushMatrix();
                                materials(&brwn);

				glRotatef(25, 0.0, -1.0, 0.0);
                                glTranslatef(0.1, -0.05, 0.5);
                                glRotatef(180, 1.0, 0.0, 0.0);
                                glutSolidCone(0.04, 0.04, 100, 100);
                        glPopMatrix();
//
		glPushMatrix();
	           	materials(&wood);

   	           	glScalef(0.01, 1.0, 0.25);
	              	glTranslatef(60.0, 0.0, 0.0);
	              	glutSolidCube(2.0);
	      	glPopMatrix();

                glPushMatrix();
                        materials(&wood);

                        glScalef(0.01, 1.0, 0.25);
                        glTranslatef(-60.0, 0.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

		glPushMatrix();
			materials(&libr);

			glScalef(0.59, 0.01, 0.24);
			glTranslatef(0.0, 99.0, 0.0);
			glutSolidCube(2.0);
		glPopMatrix();

                glPushMatrix();
                        materials(&libr);

                        glScalef(0.59, 0.01, 0.24);
                        glTranslatef(0.0, -98.5, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&libr);

                        glScalef(0.59, 0.01, 0.24);
                        glTranslatef(0.0, 50.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&libr);

                        glScalef(0.59, 0.01, 0.24);
                        glTranslatef(0.0, -50.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();

                glPushMatrix();
                        materials(&libr);

                        glScalef(0.59, 0.01, 0.24);
                        glTranslatef(0.0, 0.0, 0.0);
                        glutSolidCube(2.0);
                glPopMatrix();
	glPopMatrix();
}

void init() {

  glClearColor(0.0, 0.0, 0.0, 0.0);

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_NORMALIZE);

// specify light properties below

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);   // light source 1
  glEnable(GL_LIGHT1);
//  glEnable(GL_LIGHT2);

  glLightfv(GL_LIGHT0, GL_POSITION, light0_pos );
  glLightfv(GL_LIGHT0, GL_SPECULAR, light0_spec );
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light0_amb);

  glLightfv(GL_LIGHT1, GL_POSITION, light1_pos );
  glLightfv(GL_LIGHT1, GL_SPECULAR, light1_spec );
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diff);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light1_amb);

//  glLightfv(GL_LIGHT2, GL_POSITION, light2_pos );
//  glLightfv(GL_LIGHT2, GL_SPECULAR, light2_spec );
//  glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diff);
//  glLightfv(GL_LIGHT2, GL_AMBIENT, light2_amb);

}


void display( void ) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity( );
  glRotatef( theta[0], 1.0, 0.0, 0.0 );  // rotate wrt x axis
  glRotatef( theta[1], 0.0, 1.0, 0.0 );  // rotate wrt y axis
  glRotatef( theta[2], 0.0, 0.0, 1.0 );  // rotate wrt z axis

  colorobject( );  // call the function colorobject

  glFlush( );
  glutSwapBuffers( );
}

void spinCube( ) {

  theta[axis] += 0.3;
  if (theta[axis] > 360.0) theta[axis] -= 360.0;
  glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {  // our mouse
  
  if (btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) axis = 0;  // x
  if (btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN) axis = 1; // y
  if (btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) axis = 2;  // z
}

void Reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  
  if (w <= h) 
    glOrtho(-3.0, 3.0, -3.0*(GLfloat) h/ (GLfloat) w, 
        3.0*(GLfloat) h/ (GLfloat) w, -10.0, 10.0);
  else
    glOrtho(-3.0*(GLfloat) w/ (GLfloat) h, 3.0*(GLfloat) w/(GLfloat) h,
       -3.0, 3.0, -10.0, 10.0);

  glMatrixMode( GL_MODELVIEW );
}

void myKeyboard(unsigned char key, int x, int y) {
  if (key == 'q' || key == 'Q') exit(0);
  if (key == 'c' || key == 'C') glutIdleFunc( spinCube );
  if (key == 's' || key == 'S') glutIdleFunc( NULL );
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);

  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); 
  glutInitWindowSize( 750, 750 );
  glutCreateWindow("PROJECT 5");
  glutReshapeFunc(Reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc( myKeyboard );
  glutMouseFunc(mouse);
  init();
  glutMainLoop();
}
