/*
kelompok 4
*/

#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

using namespace std;

int w=900, h=600, z=0;
int x1=0, y1=0, sudut=0, z1=0, skalaX=0, skalaY=0;

void Init()
{
     glClearColor(0,0,0,1);
     glEnable(GL_DEPTH_TEST);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0,(GLdouble) w/(GLdouble) h, 1.0,300.0);
     glMatrixMode(GL_MODELVIEW);
}

void objek3d(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(0,0,0,1);
     glLoadIdentity();
     glTranslatef(0,0,z);
     glRotatef(sudut,x1,y1,z1);

     glPopMatrix();
     glPushMatrix();
     glTranslatef(2,0.2,0);
     glRotatef(180,2,13,3);
     glColor3f(2,1,2);
     glutWireSphere(9.5,30,30);
     glPopMatrix();
     glutSwapBuffers();
     
}

void resize(int w1,int h1)
{
     glViewport(0,0,w1,h1);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}

void fungsiKeyboard(unsigned char key, int x, int y)
{
     if (key =='s') z+=5;
        else if (key == 'x')
        {
             x1=1;
             y1=0;
             z1=0;
             sudut+=10;
        }
        else if (key == 'y')
        {
             y1=1;
             x1=0;
             z1=0;
             sudut+=-10;
        }
        else if (key == 'z')
        {
             y1=0;
             x1=0;
             z1=1;
             sudut+=-10;
        }
}

void fungsiSpecialKeyboard(int key, int x, int y)
{
     switch(key)
     {
         case GLUT_KEY_UP:
         z+=5;
         break;
         case GLUT_KEY_DOWN:
         z-=5;
         break;
     }
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Objek 3d");
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    glutDisplayFunc(objek3d);
    glutReshapeFunc(resize);
    glutKeyboardFunc(fungsiKeyboard);
    glutSpecialFunc(fungsiSpecialKeyboard);
    glutTimerFunc(1,timer,0);
    Init();
    glutMainLoop();
}

