#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265
static int step = 0, step1, step2, step3, step4, step5, step6, step7, step8;

/* camera location in longitude and latitude */
static float alpha = 0.0;
static float beta = PI / 6.0;

/* position of camera */
static GLdouble cpos[3];

/* position of light source */
static GLfloat lpos[] = { -3.5, 3.5, 3.5, 1.0 };

/* vectors to specify material properties */
static GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
static GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
static GLfloat gray[] = { 0.5, 0.5, 0.5, 1.0 };
static GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
static GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
static GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
static GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
static GLfloat magenta[] = { 1.0, 0.0, 1.0, 1.0 };
static GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
static GLfloat darkcyan[] = { 0.0, 0.4, 0.4, 1.0 };
static GLfloat gold[] = { 255.0 / 255.0, 215.0 / 255.0, 0 / 255.0 };
static GLfloat silver[] = { 204.0 / 255.0, 204.0 / 255.0, 204.0 / 255.0 };

static bool trianglesExist = false;
static float stepBefore = step;
static float zoom = 10.0;
static bool lightSource = true;

void writemessage()
{
	printf("HW-1 - Computer Graphics - Professor Suzuki\n");
	printf("Seyedamirhossein Hesamian\n\n");

	printf(" X => x++ <= Move light source in direction of +X\n");
	printf(" Y => y++ <= Move light source in direction of +Y\n");
	printf(" Z => z++ <= Move light source in direction of +Z\n");
	printf("\n");
	printf("^X => x-- <= Move light source in direction of -X\n");
	printf("^Y => y-- <= Move light source in direction of -Y\n");
	printf("^Z => z-- <= Move light source in direction of -Z\n");
	printf("\n");
	printf(" ^ => Move camera up\n");
	printf(" > => Move camera right\n");
	printf(" < => Move camera left\n");
	printf(" down arrow => Move camera down\n");
	printf("\n");
	printf(" o => Opening box\n");
	printf(" c => Closing box\n");
	printf("\n");
	printf(" 0 => Toggling light source\n");
	printf("\n");
	printf(" You can not move the light source when the light source is off !!!");
}

void init(void)
{
	writemessage();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	/* initially GL_FILL mode (default), later GL_LINE to show wireframe */
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_LIGHT0);
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	static int i;
	static double angle1, angle2, angle3, angle4, Y1, Z1, Y2, Z2, X3, Y3, X4, Y4;
	static double angle5, angle6, angle7, angle8, X5, Y5, X6, Y6, X7, Y7, X8, Y8;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* initialize (modelview) matrix */
	glLoadIdentity();

	/* update camera position */
	cpos[0] = zoom * cos(beta) * sin(alpha);
	cpos[1] = zoom * sin(beta);
	cpos[2] = zoom * cos(beta) * cos(alpha);
	gluLookAt(cpos[0], cpos[1], cpos[2], 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);

	if (lightSource==true){
		/* set current light source position */
		glLightfv(GL_LIGHT0, GL_POSITION, lpos);
		/* draw sphere to show light source */
		glMaterialfv(GL_FRONT, GL_EMISSION, white);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128);
		glPushMatrix();
		glTranslatef(lpos[0], lpos[1], lpos[2]);
		glutSolidSphere(0.1, 10, 8);
		glPopMatrix();
}


	/* remaining objects do not look as if they emit light */
	glMaterialfv(GL_FRONT, GL_EMISSION, black);

	/* draw a tabletop */
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
	glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, blue);

	glMaterialfv(GL_BACK, GL_SPECULAR, white);
	glNormal3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(5.0, -0.001, -3.0);
	glVertex3f(-5.0, -0.001, -3.0);
	glVertex3f(-5.0, -0.001, 5.0);
	glVertex3f(5.0, -0.001, 5.0);

	glEnd();

	//printf("%d", step);
	//printf("\n");

	if (step <= 360)
		trianglesExist = true;
	else
		trianglesExist = false;

	if (step > 630 && step < 720){
		step1 = 90;
		step2 = 90;
		step3 = 90;
		step4 = 90;
		step5 = 90;
		step6 = 90;
		step7 = 90;
		step8 = step - 630;
	}

	else if (step > 540 && step < 720){
		step1 = 90;
		step2 = 90;
		step3 = 90;
		step4 = 90;
		step5 = 90;
		step6 = 90;
		step7 = step - 540;
		step8 = 0;
	}
	else if (step > 450 && step < 720){
		step1 = 90;
		step2 = 90;
		step3 = 90;
		step4 = 90;
		step5 = 90;
		step6 = step - 450;
		step7 = 0;
		step8 = 0;
	}
	else if (step > 360 && step < 720){
		step1 = 90;
		step2 = 90;
		step3 = 90;
		step4 = 90;
		step5 = step - 360;
		step6 = 0;
		step7 = 0;
		step8 = 0;
	}
	else if (step > 270 && step <= 360)
	{
		step1 = 90;
		step2 = 90;
		step3 = 90;
		step4 = step - 270;
		step5 = 0;
		step6 = 0;
		step7 = 0;
		step8 = 0;

	}
	else if (step > 180 && step <= 360)
	{
		step1 = 90;
		step2 = 90;
		step3 = step - 180;
		step4 = 0;
		step5 = 0;
		step6 = 0;
		step7 = 0;
		step8 = 0;

	}
	else if (step > 90 && step <= 360)
	{
		step1 = 90;
		step2 = step - 90;
		step3 = 0;
		step4 = 0;
		step5 = 0;
		step6 = 0;
		step7 = 0;
		step8 = 0;
	}
	else if (step >= 0 && step <= 360)
	{
		step1 = step;
		step2 = 0;
		step3 = 0;
		step4 = 0;
		step5 = 0;
		step6 = 0;
		step7 = 0;
		step8 = 0;
	}
	else;

	if (trianglesExist)
	{
		// top back - first
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		angle1 = ((float)step1 / 180) * PI;
		glNormal3f(0, cos(angle1), -sin(angle1));
		glBegin(GL_POLYGON);
		glVertex3f(-3.0, 2.0, -1.0);
		glVertex3f(0, 2.0 + 2.0 * sin(angle1), -1.0 + 2.0 * cos(angle1));
		glVertex3f(3.0, 2.0, -1.0);
		glEnd();


		// top front - second
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		angle2 = ((float)step2 / 180) * PI;
		glNormal3f(0, cos(angle2), sin(angle2));
		glBegin(GL_POLYGON);
		glVertex3f(3.0, 2.0, 3.0);
		glVertex3f(0, 2.0 + 2.0 * sin(angle2), 3.0 + -2.0 * cos(angle2));
		glVertex3f(-3.0, 2.0, 3.0);
		glEnd();


		// top right - third
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		angle3 = ((float)step3 / 180) * PI;
		glNormal3f(sin(angle3), cos(angle3), 0);
		glBegin(GL_POLYGON);
		glVertex3f(3.0, 2.0, -1.0);
		glVertex3f(3.0 - 3.0 * cos(angle3), 2.0 + 2.0 * sin(angle3), 1);
		glVertex3f(3.0, 2.0, 3.0);
		glEnd();


		// top left - fourth
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		angle4 = ((float)step4 / 180) * PI;
		glNormal3f(-sin(angle4), cos(angle4), 0);
		glBegin(GL_POLYGON);
		glVertex3f(-3.0, 2.0, 3.0);
		glVertex3f(-3.0 + 3.0 * cos(angle4), 2.0 + 2.0 * sin(angle4), 1);
		glVertex3f(-3.0, 2.0, -1.0);
		glEnd();

		// back
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, -1);
		glVertex3f(-3.0, 0.0, -1.0);
		glVertex3f(-3.0, 2.0, -1.0);
		glVertex3f(3.0, 2.0, -1.0);
		glVertex3f(3.0, 0.0, -1.0);

		glEnd();

		// front
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(3.0, 0.0, 3.0);
		glVertex3f(3.0, 2.0, 3.0);
		glVertex3f(-3.0, 2.0, 3.0);
		glVertex3f(-3.0, 0.0, 3.0);
		glEnd();

		// right
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(3.0, 0.0, -1.0);
		glVertex3f(3.0, 2.0, -1.0);
		glVertex3f(3.0, 2.0, 3.0);
		glVertex3f(3.0, 0.0, 3.0);
		glEnd();

		// left
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(-3.0, 0.0, 3.0);
		glVertex3f(-3.0, 2.0, 3.0);
		glVertex3f(-3.0, 2.0, -1.0);
		glVertex3f(-3.0, 0.0, -1.0);
		glEnd();
	}
	else
	{
		// right-full
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glBegin(GL_POLYGON);
		angle5 = ((float)step5 / 180) * PI;
		angle5 = angle5 + PI / 2;
		glNormal3f(cos(angle5 - PI / 2), -sin(angle5 - PI / 2), 0);
		glVertex3f(3.0, 0.0, -1.0);
		glVertex3f(3.0 - 2 * cos(angle5), 2 * sin(angle5), -1.0);
		glVertex3f(3.0 - 4 * cos(angle5), 4.0* sin(angle5), 1.0);
		glVertex3f(3.0 - 2 * cos(angle5), 2 * sin(angle5), 3.0);
		glVertex3f(3.0, 0.0, 3.0);
		glEnd();


		// left-full
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		angle6 = ((float)step6 / 180) * PI;
		angle6 = angle6 + PI / 2;
		glNormal3f(-cos(angle6 - PI / 2), -sin(angle6 - PI / 2), 0);
		glVertex3f(-3.0, 0.0, 3.0);
		glVertex3f(-3.0 + 2 * cos(angle6), 2 * sin(angle6), 3.0);
		glVertex3f(-3.0 + 4 * cos(angle6), 4.0* sin(angle6), 1.0);
		glVertex3f(-3.0 + 2 * cos(angle6), 2 * sin(angle6), -1.0);
		glVertex3f(-3.0, 0.0, -1.0);
		glEnd();


		// back-full
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		angle7 = ((float)step7 / 180) * PI;
		angle7 = 2 * PI - angle7;
		glNormal3f(0, sin(-angle7), cos(-angle8));
		glVertex3f(3.0, 0, -1.0);
		glVertex3f(3.0, 2.0*cos(-angle7), -1.0 + 2 * sin(angle7));
		glVertex3f(0, 4 * cos(angle7), -1.0 + 4 * sin(angle7));
		glVertex3f(-3.0, 2.0*cos(angle7), -1.0 + 2 * sin(angle7));
		glVertex3f(-3.0, 0.0, -1.0);
		glEnd();


		// front-full
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glMaterialfv(GL_BACK, GL_EMISSION, black);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gold);
		glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, silver);
		glMaterialf(GL_BACK, GL_SHININESS, 128);
		glMaterialf(GL_FRONT, GL_SHININESS, 128);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glBegin(GL_POLYGON);
		angle8 = ((float)step8 / 180) * PI;
		glNormal3f(0, -sin(angle8), cos(angle8));
		glVertex3f(3.0, 0, 3.0);
		glVertex3f(3.0, 2.0*cos(angle8), 3.0 + 2 * sin(angle8));
		glVertex3f(0, 4 * cos(angle8), 3.0 + 4 * sin(angle8));
		glVertex3f(-3.0, 2.0*cos(angle8), 3.0 + 2 * sin(angle8));
		glVertex3f(-3.0, 0.0, 3.0);
		glEnd();

	}

	// buttom
	glMaterialfv(GL_FRONT, GL_EMISSION, black);
	glMaterialfv(GL_BACK, GL_EMISSION, black);
	glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, gold);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, silver);
	glMaterialf(GL_BACK, GL_SHININESS, 128);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-3.0, 0.0, -1.0);
	glVertex3f(-3.0, 0.0, 3.0);
	glVertex3f(3.0, 0.0, 3.0);
	glVertex3f(3.0, 0.0, -1.0);
	glEnd();

	glFlush();
	glutSwapBuffers();

}


void keyboard(unsigned char key, int x, int y)
{
	static int polygonmode[2];

	switch (key) {
	case 27:
		exit(0);
		break;

		/* open and close the top */
	case 'o':
		if (step < 720) { stepBefore = step*1.0; step = step + 2; }
		glutPostRedisplay();
		break;
	case 'c':
		if (step > 0) {
			stepBefore = step*1.0; step = step - 2;
		}
		glutPostRedisplay();
		break;
		/* w for switching between GL_FILL and GL_LINE
		* Using a query command glGetIntegerv() we obtain two integers
		* indicating the current GL_POLYGON_MODE for FRONT and BACK faces.
		* Look up glIsEnabled() that may be found useful. */
	case 'w':
		glGetIntegerv(GL_POLYGON_MODE, polygonmode);
		if (polygonmode[0] == GL_FILL)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutPostRedisplay();
		break;

		/* control lpos */
	case 'x':
		if (lightSource == true)
			lpos[0] = lpos[0] + 0.2;
		glutPostRedisplay();
		break;
	case 'X':
		if (lightSource == true)
			lpos[0] = lpos[0] - 0.2;
		glutPostRedisplay();
		break;
	case 'y':
		if (lightSource == true)
			lpos[1] = lpos[1] + 0.2;
		glutPostRedisplay();
		break;
	case 'Y':
		if (lightSource == true)
			lpos[1] = lpos[1] - 0.2;
		glutPostRedisplay();
		break;
	case 'z':
		if (lightSource == true)
			lpos[2] = lpos[2] + 0.2;
		glutPostRedisplay();
		break;
	case 'Z':
		if (lightSource == true)
			lpos[2] = lpos[2] - 0.2;
		glutPostRedisplay();
		break;

	case '+':
		if (zoom != 1.5)zoom = zoom - 0.5;
		glutPostRedisplay();
		break;
	case '-':
		if (zoom != 15)zoom = zoom + 0.5;
		glutPostRedisplay();
		break;
	case '0':
		if (lightSource == true){
			glDisable(GL_LIGHT0);
			lightSource = false;
		}
		else{
			glEnable(GL_LIGHT0);

			lightSource = true;
		}
		glutPostRedisplay();
		break;

	default:
		break;
	}
}
void specialkey(GLint key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		alpha = alpha + PI / 180;
		if (alpha > 2 * PI) alpha = alpha - 2 * PI;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		alpha = alpha - PI / 180;
		if (alpha < 0) alpha = alpha + 2 * PI;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		if (beta < 0.45*PI) beta = beta + PI / 180;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		if (beta > -0.05*PI) beta = beta - PI / 180;
		glutPostRedisplay();
		break;


	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkey);
	glutMainLoop();
	return 0;
}
