#include <GL/glut.h>
#include <stdlib.h>

static GLfloat theta[] = {0.0, 0.0, 0.0} ;

GLint torso = 0;
GLint shoulder11 = 0, shoulder12 = 0, shoulder13 = 0;
GLint shoulder21 = 0, shoulder22 = 0, shoulder23 = 0;
GLint elbow1 = 0, elbow2 = 0;
GLint hip11 = 0, hip12 = 0, hip13 = 0;
GLint hip21 = 0, hip22 = 0, hip23 = 0;
GLint knee1 = 0, knee2 = 0;

GLfloat position0[] = {1.0, 3.0, 4.0, 0.0};
GLfloat ambient0[] = {0.2, 0.2, 0.2, 1.0};

typedef struct matStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
} matStruct ;

matStruct rd = {
	{0.02, 0.02, 0.02},
	{0.01, 0.01, 0.01},
	{0.4, 0.4, 0.4},
	8
};

matStruct lamp = {
        {0.09, 0.09, 0.09},
        {0.07, 0.07, 0.07},
        {0.9, 0.9, 0.9},
        8
};

matStruct side = {
        {0.25, 0.25, 0.25},
        {0.4, 0.4, 0.4},
        {0.77, 0.77, 0.77},
        10
};

matStruct walls = {
	{0.33, 0.22, 0.03},
	{0.78, 0.57, 0.11},
	{0.99, 0.94, 0.81},
	20
};

matStruct wind = {
	{0.0, 0.1, 0.06},
	{0.0, 0.51, 0.51},
	{0.5, 0.5, 0.5},
	30
};

matStruct roof = {
	{0.17, 0.01, 0.01},
	{0.61, 0.04, 0.04},
	{0.73, 0.63, 0.63},
	6
};

matStruct silv = {
	{0.19, 0.19, 0.19, 0.3},
	{0.51, 0.51, 0.51, 0.3},
	{0.51, 0.51, 0.51, 0.3},
	20
};

void materials(matStruct *materials) {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,
			materials -> ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,
			materials -> diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,
			materials -> specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,
			materials -> shininess);
}

void colorcube(void)
{

// Background:
	glPushMatrix();

		glTranslatef(0.0, 0.0, -7.0);

	// Road:
		glPushMatrix();

			materials(&rd);

			glTranslatef(0.0, -8.6, 0.0);
			glScalef(10.0, 1.3, 1.5);
			glutSolidCube(2.0);
		glPopMatrix();

	// SideWalk:
		glPushMatrix();

			materials(&side);

			glTranslatef(0.0, -7.3, 0.0);
			glScalef(10.0, 0.5, 1.5);
			glutSolidCube(2.0);
		glPopMatrix();

	// Street Lamps:

		// Lamp 1:
			glPushMatrix();

				materials(&rd);
				glTranslatef(8.0, 0.0, 0.0);

			// Post:
				glPushMatrix();

					glScalef(0.25, 7.0, 0.25);
					glutSolidCube(2.0);

				glPopMatrix();
			// Lamp:
				glPushMatrix();

					glTranslatef(0.0, 7.0, 0.0);
					glScalef(0.75, 0.5, 0.5);
					glutSolidCube(2.0);

				glPopMatrix();

			glPopMatrix();

		// Lamp 2:
                        glPushMatrix();

                                materials(&rd);
                                glTranslatef(-8.0, 0.0, 0.0);

                        // Post:
                                glPushMatrix();

                                        glScalef(0.25, 7.0, 0.25);
                                        glutSolidCube(2.0);

                                glPopMatrix();
                        // Lamp:
                                glPushMatrix();

                                        glTranslatef(0.0, 7.0, 0.0);
                                        glScalef(0.75, 0.5, 0.5);
                                        glutSolidCube(2.0);

                                glPopMatrix();

                        glPopMatrix();

	// House:
		glPushMatrix();

		// Flat Roof:
			glPushMatrix();
				materials(&roof);

				glTranslatef(0.0, 3.75, 0.0);
				glScalef(4.8, 0.35, 1.25);
				glutSolidCube(3.0);

			glPopMatrix();

		// Walls:
			glPushMatrix();
				materials(&walls);

				glTranslatef(0.0, -1.5, 0.0);
				glScalef(4.5, 3.5, 1.0);
				glutSolidCube(3.0);

			glPopMatrix();

		// Windows:
			glPushMatrix();
				materials(&wind);

				glTranslatef(4.0, -0.25, 0.1);
				glScalef(0.75, 1.0, 1.0);
				glutSolidCube(3.0);

			glPopMatrix();

                        glPushMatrix();
                                materials(&wind);

                                glTranslatef(-4.0, -0.25, 0.1);
                                glScalef(0.75, 1.0, 1.0);
                                glutSolidCube(3.0);

                        glPopMatrix();

		// Door:
			glPushMatrix();
				materials(&wind);

				glTranslatef(0.0, -4.19, 0.1);
				glScalef(1.0, 1.75, 1.0);
				glutSolidCube(3.0);

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();

// Robot:
glPushMatrix();

	materials(&silv);

	glScalef(1.0, 0.925, 1.0);
	glTranslatef(0.0, -3.65, 0.0);
	glRotatef(30, 0.0, 1.0, 0.0);

	// Head:
		glPushMatrix();

			glTranslatef(0.0, 3.0, 0.0);

			glutSolidSphere(0.95, 200, 200);

		glPopMatrix();

	// Torso + Arms:
		glPushMatrix();

			glTranslatef(0.0, 0.45, 0.0);

                	glRotatef((GLfloat) torso, 0.0, 1.0, 0.0); // Rotate w/respect to Y

		// Torso:
			glPushMatrix();

				glScalef(2.0, 4.0, 2.0);
				glutSolidCube(1.0);

			glPopMatrix();

		// Arm 1:
			glPushMatrix();

	                	glTranslatef(1.23, 1.98, 0.0);
        	        	// Moves origin to allow arm to swing from shoulder joint.

                		glRotatef((GLfloat) shoulder11, 0.0, 0.0, 1.0); // Rotate w/respect to Z
                		glRotatef((GLfloat) shoulder12, 0.0, 1.0, 0.0); // Rotate w/respect to Y
                		glRotatef((GLfloat) shoulder13, 1.0, 0.0, 0.0); // Rotate w/respect to X

	                	glTranslatef(-1.23, -1.98, 0.0); // Returns origin to OG position.

        		// Upper Arm 1:
                		glPushMatrix();

                        		glTranslatef(1.23, 0.98, 0.0);

                        		glScalef(0.45, 2.0, 0.45);
                        		glutSolidCube(1.0);

                		glPopMatrix();

        		// Forearm 1:
                		glPushMatrix();

                        		glTranslatef(1.23, 0.0, 0.0);
                        		// Moves origin to allow forearm to swing from elbow joint.

                        		glRotatef((GLfloat) elbow1, 1.0, 0.0, 0.0);

                        		glTranslatef(-1.23, 0.0, 0.0); // Returns origin to OG position.

                        		glPushMatrix();

	                                	glTranslatef(1.23, -1.0, 0.0);

        	                        	glScalef(0.45, 2.0, 0.45);
                	                	glutSolidCube(1.0);

                        		glPopMatrix();

				glPopMatrix();

			glPopMatrix();


		// Arm 2:
			glPushMatrix();

				glTranslatef(-1.23, 1.98, 0.0);
				// Moves origin to allow arm to swing from shoulder joint.

				glRotatef((GLfloat) shoulder21, 0.0, 0.0, 1.0); // Rotate w/respect to Z
				glRotatef((GLfloat) shoulder22, 0.0, 1.0, 0.0); // Rotate w/respect to Y
				glRotatef((GLfloat) shoulder23, 1.0, 0.0, 0.0); // Rotate w/respect to X

				glTranslatef(1.23, -1.98, 0.0); // Returns origin to OG position.

			// Upper Arm 2:
				glPushMatrix();

	                		glTranslatef(-1.23, 0.98, 0.0);

					glScalef(0.45, 2.0, 0.45);
					glutSolidCube(1.0);

				glPopMatrix();

			// Forearm 2:
				glPushMatrix();

                        		glTranslatef(-1.23, 0.0, 0.0);
		                	// Moves origin to allow forearm to swing from elbow joint.

					glRotatef((GLfloat) elbow2, 1.0, 0.0, 0.0);

					glTranslatef(1.23, 0.0, 0.0); // Returns origin to OG position.

					glPushMatrix();

						glTranslatef(-1.23, -1.0, 0.0);

						glScalef(0.45, 2.0, 0.45);
						glutSolidCube(1.0);

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	// Hip 1:
		glPushMatrix();

                	glTranslatef(0.55, -1.49, 0.0);
                	// Moves origin to allow leg to swing from hip joint.

                	glRotatef((GLfloat) hip11, 0.0, 0.0, 1.0); // Rotate w/respect to Z
                	glRotatef((GLfloat) hip12, 0.0, 1.0, 0.0); // Rotate w/respect to Y
                	glRotatef((GLfloat) hip13, 1.0, 0.0, 0.0); // Rotate w/respect to X

                	glTranslatef(-0.55, 1.49, 0.0); // Returns origin to OG position.

		// Thigh 1:
                	glPushMatrix();

                		glTranslatef(0.55, -2.49, 0.0);

                		glScalef(0.45, 2.0, 0.45);
                		glutSolidCube(1.0);

                	glPopMatrix();

        	// Lower Leg 1:
                	glPushMatrix();

	                	glTranslatef(0.55, -3.49, 0.0);
        	        	// Moves origin to allow lower leg to swing from knee joint.

                		glRotatef((GLfloat) knee1, 1.0, 0.0, 0.0);

                		glTranslatef(-0.55, 3.49, 0.0); // Returns origin to OG position.

                		glPushMatrix();

                			glTranslatef(0.55, -4.49, 0.0);

                        		glScalef(0.45, 2.0, 0.45);
                        		glutSolidCube(1.0);

                		glPopMatrix();

                 	glPopMatrix();

        	glPopMatrix();

	// Hip 2:
        	glPushMatrix();

                	glTranslatef(-0.55, -1.49, 0.0);
                	// Moves origin to allow leg to swing from hip joint.

                	glRotatef((GLfloat) hip21, 0.0, 0.0, 1.0); // Rotate w/respect to Z
                	glRotatef((GLfloat) hip22, 0.0, 1.0, 0.0); // Rotate w/respect to Y
                	glRotatef((GLfloat) hip23, 1.0, 0.0, 0.0); // Rotate w/respect to X

                	glTranslatef(0.55, 1.49, 0.0); // Returns origin to OG position.

        	// Thigh 2:
                	glPushMatrix();

                        	glTranslatef(-0.55, -2.49, 0.0);

                        	glScalef(0.45, 2.0, 0.45);
                        	glutSolidCube(1.0);

                	glPopMatrix();

        	// Lower Leg 2:
                	glPushMatrix();

                        	glTranslatef(-0.55, -3.49, 0.0);
                        	// Moves origin to allow lower leg to swing from knee joint.

                        	glRotatef((GLfloat) knee2, 1.0, 0.0, 0.0);

                        	glTranslatef(0.55, 3.49, 0.0); // Returns origin to OG position.

                        	glPushMatrix();

                                	glTranslatef(-0.55, -4.49, 0.0);

                                	glScalef(0.45, 2.0, 0.45);
                                	glutSolidCube(1.0);

                        	glPopMatrix();

                 	glPopMatrix();

        	glPopMatrix();

glPopMatrix();
}

void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glLoadIdentity();

 glRotatef(theta[0], 1.0, 0.0, 0.0);
 glRotatef(theta[1], 0.0, 1.0, 0.0);
 glRotatef(theta[2], 0.0, 0.0, 1.0);

 colorcube();

 glFlush();

 glutSwapBuffers();
}


// Insert function key below

  void mykey(unsigned char key, int x, int y) {

  switch (key) {
	case 'z': //Counter-clock torso
	  torso = (torso + 5) % 360;
	  glutPostRedisplay();
	  break;
        case 'Z': //Clockwise torso
          torso = (torso - 5) % 360;
          glutPostRedisplay();
          break;
   	case 'a': //Counter-clock shoulder 13
	  shoulder13 = (shoulder13 + 5) % 360;
	  glutPostRedisplay();
	  break;
	case 'A': //Clockwise shoulder 13
	  shoulder13 = (shoulder13 - 5) % 360;
	  glutPostRedisplay();
	  break;
 	case 'b': //Counter-clock shoulder 12
	  shoulder12 = (shoulder12 + 5) % 360;
	  glutPostRedisplay();
	  break;
        case 'B': //Clockwise shoulder 12
  	  shoulder12 = (shoulder12 - 5) % 360;
	  glutPostRedisplay();
	  break;
	case 'c': //Counter-clock shoulder 11
	  shoulder11 = (shoulder11 + 5) % 360;
	  glutPostRedisplay();
	  break;
	case 'C': //Clockwise shoulder 11
	  shoulder11 = (shoulder11 - 5) % 360;
	  glutPostRedisplay();
	  break;
	case 'd': //Elbow 1
	  elbow1 = (elbow1 + 5) % 360;
	  glutPostRedisplay();
	  break;
        case 'D': //Elbow 1
          elbow1 = (elbow1 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'e': //Counter-clock shoulder 23
          shoulder23 = (shoulder23 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'E': //Clockwise shoulder 23
          shoulder23 = (shoulder23 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'f': //Counter-clock shoulder 22
          shoulder22 = (shoulder22 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'F': //Clockwise shoulder 22
          shoulder22 = (shoulder22 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'g': //Counter-clock shoulder 21
          shoulder21 = (shoulder21 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'G': //Clockwise shoulder 21
          shoulder21 = (shoulder21 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'h': //Elbow 2
          elbow2 = (elbow2 + 5) % 360;
          glutPostRedisplay();
	  break;
        case 'H': //Elbow 2
          elbow2 = (elbow2 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'i': //Counter-clock hip 13
          hip13 = (hip13 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'I': //Clockwise hip 13
          hip13 = (hip13 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'j': //Counter-clock hip 12
          hip12 = (hip12 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'J': //Clockwise hip 12
          hip12 = (hip12 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'k': //Counter-clock hip 11
          hip11 = (hip11 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'K': //Clockwise hip 11
          hip11 = (hip11 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'l': //Knee 1
          knee1 = (knee1 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'L': //Knee 1
          knee1 = (knee1 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'm': //Counter-clock hip 23
          hip23 = (hip23 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'M': //Clockwise hip 23
          hip23 = (hip23 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'n': //Counter-clock hip 22
          hip22 = (hip22 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'N': //Clockwise hip 22
          hip22 = (hip22 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'o': //Counter-clock hip 21
          hip21 = (hip21 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'O': //Clockwise hip 21
          hip21 = (hip21 - 5) % 360;
          glutPostRedisplay();
          break;
        case 'p': //Knee 2
          knee2 = (knee2 + 5) % 360;
          glutPostRedisplay();
          break;
        case 'P': //Knee 2
          knee2 = (knee2 - 5) % 360;
          glutPostRedisplay();
          break;
	case 'q':
	  exit(0);
	  break;
	default:
	  break;
  }
 }


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w,
            10.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h,
            10.0 * (GLfloat) w / (GLfloat) h, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {

 glClearColor(0.0, 0.5, 1.0, 1.0);

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);

// enable light here

 glLightfv(GL_LIGHT0, GL_POSITION, position0);
 glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);


}

int
main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
//    glutIdleFunc(myidle); // add this
    glutKeyboardFunc(mykey);

    init();
    glutMainLoop();
}

