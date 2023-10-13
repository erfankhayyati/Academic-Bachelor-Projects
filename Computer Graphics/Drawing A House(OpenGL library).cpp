#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#define p 3.14
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
}
//float radious = 0.5;
void circle(double x,double y,float radious){

glBegin(GL_TRIANGLE_FAN);
glColor3f(1,0,0);
glVertex2f(x,y);
for(int i=0;i<=360;i++){
    double ang = i*p/180;
    glVertex2f(x+radious*cos(ang),y+radious*sin(ang));
}

}
void display(){
glClear(GL_COLOR_BUFFER_BIT);

//draw roof

glBegin(GL_TRIANGLES);
glColor3f(0.411, 0.192, 0.066);
glVertex2f(0,1.0);
glVertex2f(-0.5,0.5);
glVertex2f(0.5,0.5);
glEnd();

//draw house

glBegin(GL_QUADS);
glColor3f(0.850, 0.466, 0.247);

glVertex2f(-0.5,0.5);
glVertex2f(-0.5,-0.5);
glVertex2f(0.5,-0.5);
glVertex2f(0.5,0.5);
glEnd();

//draw door
glBegin(GL_QUADS);
glColor3f(0.670, 0.721, 0.337);

glVertex2f(-0.25,0);
glVertex2f(-0.25,-0.5);
glVertex2f(0.25,-0.5);
glVertex2f(0.25,0);
glEnd();

// draw windows
circle(0.125,-0.25,0.05);

glEnd();

glFlush();
}
void reshape(int w,int h){
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1,1,-1,1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
int main(int argc , char **argv){
glutInit(&argc , argv);
glutCreateWindow("My house");
glutInitWindowPosition(400,400);
glutInitWindowSize(1000,1000);
init();
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutMainLoop();
return(EXIT_SUCCESS);


}

