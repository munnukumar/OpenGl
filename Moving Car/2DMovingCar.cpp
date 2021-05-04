#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

GLint b = 300;
float  counter = 100.0;
void initOpenGl()
{
    glClearColor(0.249, 0.292, 55.785, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

float xr = 0, yr = 0;
void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glEnd();

}
float r,g,B=1;
void specialkey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        yr = yr - 1;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        yr = yr + 1;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        g = 0;
        r =  1;
        B = 0;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        r = 0;
        g =  1;
        glutPostRedisplay();
        break;


     }
}

void road()
{
    glColor3d(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(800, 0);
    glVertex2d(800, 82);
    glVertex2d(0, 82);

    glEnd();
}

void marks()
{
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(200, 40);
    glVertex2d(300, 40);
    glVertex2d(300, 75);
    glVertex2d(200, 75);

    glEnd();
}

void grass()
{
    glColor3d(0.249, 0.292, 55.785);
    glBegin(GL_POLYGON);
    glVertex2d(0, 220);
    glVertex2d(800, 220);
    glVertex2d(800, 500);
    glVertex2d(0, 500);

    glEnd();
}


void car()
{


    //Bottom Part
    glLoadIdentity();
    glColor3f(r, g, B);
    //glScaled(0.1,0.1,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100+yr, 100);
    glVertex2f(100+yr, 160);
    glVertex2f(450+yr, 160);
    glVertex2f(450+yr, 100);

    //Top Part
    glBegin(GL_POLYGON);
    glVertex2f(150+yr, 160);
    glVertex2f(200+yr, 200);
    glVertex2f(400+yr, 200);
    glVertex2f(450+yr, 160);



    glEnd();
    wheel(200+yr, 100);
    wheel(380+yr, 100);

}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    car();
    road();
    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();


}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Car Moving");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(specialkey);
    glutMainLoop();
    return 0;
}
