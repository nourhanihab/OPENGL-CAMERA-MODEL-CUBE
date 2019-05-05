#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
GLint width = 800, height = 600;

int perspective = 1;

void cube() {

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.3, -0.3, -0.3);
    glColor3f(1.0, 0, 0.0);
    glVertex3f(0.3, 0.3, -0.3);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.3, 0.3, -0.3);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.3, -0.3, -0.3);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.3, -0.3, 0.3);
    glVertex3f(0.3, 0.3, 0.3);
    glVertex3f(-0.3, 0.3, 0.3);
    glVertex3f(-0.3, -0.3, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.3, -0.3, -0.3);
    glVertex3f(0.3, 0.3, -0.3);
    glVertex3f(0.3, 0.3, 0.3);
    glVertex3f(0.3, -0.3, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, -0.3, 0.3);
    glVertex3f(-0.3, 0.3, 0.3);
    glVertex3f(-0.3, 0.3, -0.3);
    glVertex3f(-0.3, -0.3, -0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.3, 0.3, 0.3);
    glVertex3f(0.3, 0.3, -0.3);
    glVertex3f(-0.3, 0.3, -0.3);
    glVertex3f(-0.3, 0.3, 0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.3, -0.3, -0.3);
    glVertex3f(0.3, -0.3, 0.3);
    glVertex3f(-0.3, -0.3, 0.3);
    glVertex3f(-0.3, -0.3, -0.3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);
    glTranslatef(X, Y, Z);    //translate

    gluLookAt(1.0, 0.0, 2.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // trans
    glScalef(scale, scale, scale);

    cube();

    glFlush();
    glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y) {
    //ZOOM IN AND OUT
    switch (key) {
        case 'z': //zoom out
            Z -= 0.1f;
            break;
        case 'Z': //zoom in
            Z += 0.1f;
            break;
        case 'e':
            exit(0);            // exit
    }
    glutPostRedisplay();
}
void specialKeys(int key, int x, int y) {

    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;

    else if (key == GLUT_KEY_UP)
        rotate_x += 7;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;

    else if (key == GLUT_KEY_F2)
        rotate_z += 7;

    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;


    glutPostRedisplay();

}

void reshape(int alto, int ancho) {
    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (perspective)
        gluPerspective(60.0f, (GLfloat) width / (GLfloat) height, 1.0f, 30.0f);
    else
        glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    width = 800;
    height = 600;

}

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);

    init();


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Cube");




    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
       glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}
