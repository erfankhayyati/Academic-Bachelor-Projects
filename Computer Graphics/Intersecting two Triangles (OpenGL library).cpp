#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;




//int headsize()
//{
//    int head_size;
//    cout << "Enter your Head size : ";
//    cin >> head_size;
//    return head_size;
//}
float *user_input(int &head_size)
{
    head_size*=2;
    int j=1;
    float *arr = new float[head_size];
    for (int i=0;i<head_size;i+=2)
    {
        cout << "X" << j <<" : ";
        cin >> arr[i];
        cout << "Y" << j <<" : ";
        cin >> arr[i+1];
        cout << endl;
        j++;
    }
    return arr;
}
// Global varibles
//int head_size1 = headsize();
int head_size1 = 3;

float *polygon1 = user_input(head_size1); // [10,20,23,40,50,60]
//int head_size2 = headsize();
int head_size2 = 3;
//cout<<"Enter Second Triangle: ";
float *polygon2 = user_input(head_size2);

void display()
{
//    cout<<polygon1[0]<<"  "<<polygon1[1]<<"  "<<polygon1[2]<<"  "<<polygon1[3]<<"  "<<polygon1[4]<<"  "<<polygon1[5]<<endl;
//    cout<<polygon2[0]<<"  "<<polygon2[1]<<"  "<<polygon2[2]<<"  "<<polygon2[3]<<"  "<<polygon2[4]<<"  "<<polygon2[5]<<endl;
    float
    Mab12,Mab13,Mab23,
    Mab45,Mab46,Mab56,
    Mab14,Mab15,Mab16,
    Mab24,Mab25,Mab26,
    Mab34,Mab35,Mab36,
    Cab12,Cab13,Cab23,
    Cab46,Cab45,Cab56,
    Cab14,Cab15,Cab16,
    Cab24,Cab25,Cab26,
    Cab34,Cab35,Cab36,
    px2346,py2346 ,px2345,py2345 ,px2356,py2356,
    px1256,py1256,px1245,py1245,px1246,py1246,
    px1356,py1356,px1345,py1345,px1346,py1346
    ;
    // Mabxx = (Y2 - Y1 )/(X2 - X1) !!! shib khat !!!  xx ex. xx=12
    Mab12 = (polygon1[3]-polygon1[1])/(polygon1[2]-polygon1[0]);
    Mab13 = (polygon1[5]-polygon1[1])/(polygon1[4]-polygon1[0]);
    Mab23 = (polygon1[5]-polygon1[3])/(polygon1[4]-polygon1[2]);

    Mab45 = (polygon2[3]-polygon2[1])/(polygon2[2]-polygon2[0]);
    Mab46 = (polygon2[5]-polygon2[1])/(polygon2[4]-polygon2[0]);
    Mab56 = (polygon2[5]-polygon2[3])/(polygon2[4]-polygon2[2]);

    Mab14 = (polygon2[1]-polygon1[1])/(polygon2[0]-polygon1[0]);
    Mab15 = (polygon2[3]-polygon1[1])/(polygon2[2]-polygon1[0]);
    Mab16 = (polygon2[5]-polygon1[1])/(polygon2[4]-polygon1[0]);

    Mab24 = (polygon2[1]-polygon1[3])/(polygon2[0]-polygon1[2]);
    Mab25 = (polygon2[3]-polygon1[3])/(polygon2[2]-polygon1[2]);
    Mab26 = (polygon2[5]-polygon1[3])/(polygon2[4]-polygon1[2]);

    Mab34 = (polygon2[1]-polygon1[5])/(polygon2[0]-polygon1[4]);
    Mab35 = (polygon2[3]-polygon1[5])/(polygon2[2]-polygon1[4]);
    Mab36 = (polygon2[5]-polygon1[5])/(polygon2[4]-polygon1[4]);

    //Mab1 = (by1 - ay1) / (bx1 - ax1);
	//Mab2 = (by2 - ay2) / (bx2 - ax2);

    // C  =      Y0     - ( X0        * Mab  ); arz az mabda

    Cab12 = polygon1[1] - (polygon1[0]* Mab12);
    Cab13 = polygon1[1] - (polygon1[0]* Mab13);
    Cab23 = polygon1[3] - (polygon1[2]* Mab23);

    Cab45 = polygon2[1] - (polygon2[0]* Mab45);
    Cab46 = polygon2[1] - (polygon2[0]* Mab46);
    Cab56 = polygon2[3] - (polygon2[2]* Mab56);

    Cab14 = polygon1[1] - (polygon1[0]* Mab14);
    Cab15 = polygon1[1] - (polygon1[0]* Mab15);
    Cab16 = polygon1[1] - (polygon1[0]* Mab16);

    Cab24 = polygon1[3] - (polygon1[2]* Mab24);
    Cab25 = polygon1[3] - (polygon1[2]* Mab25);
    Cab26 = polygon1[3] - (polygon1[2]* Mab26);

    Cab34 = polygon1[5] - (polygon1[4]* Mab34);
    Cab35 = polygon1[5] - (polygon1[4]* Mab35);
    Cab36 = polygon1[5] - (polygon1[4]* Mab36);

	//Cab1 = ay1 - (ax1 * Mab1);
	//Cab2 = ay2 - (ax2 * Mab2);


    //Points Cordinates
	// 12
    px1256 = (Cab56 - Cab12) / (Mab12 - Mab56);
    py1256 = (Mab12 * px1256) + Cab12;

    px1245 = (Cab45 - Cab12) / (Mab12 - Mab45);
    py1245 = (Mab12 * px1245) + Cab12;

    px1246 = (Cab46 - Cab12) / (Mab12 - Mab46);
    py1246 = (Mab12 * px1246) + Cab12;
    //23
    px2356 = (Cab56 - Cab23) / (Mab23 - Mab56);
    py2356 = (Mab23 * px2356) + Cab23;

    px2346 = (Cab46 - Cab23) / (Mab23 - Mab46);
    py2346 = (Mab23 * px2346) + Cab23;

    px2345 = (Cab45 - Cab23) / (Mab23 - Mab45);
    py2345 = (Mab23 * px2345) + Cab23;
    // 13
    px1356 = (Cab56 - Cab13) / (Mab13 - Mab56);
    py1356 = (Mab13 * px1356) + Cab13;

    px1345 = (Cab45 - Cab13) / (Mab13 - Mab45);
    py1345 = (Mab13 * px1345) + Cab13;

    px1346 = (Cab46 - Cab13) / (Mab13 - Mab46);
    py1346 = (Mab13 * px1346) + Cab13;
//	px = (Cab21 - Cab11) / (Mab12 - Mab21);
//	py = (Mab12 * px) + Cab11;
////



    glClear(GL_COLOR_BUFFER_BIT);

    //Draw polygon1
    glBegin(GL_POLYGON);
        glColor4f(0.0 , 0.0 , 1.0 , 0.5);
        for(int i=0;i<head_size1;i+=2)
            glVertex2f(polygon1[i],polygon1[i+1]);
    glEnd();

    // Draw polygon2
   glBegin(GL_POLYGON);
        glColor4f(0,1,0,0.5);
        for(int i=0;i<head_size2;i+=2)
            glVertex2f(polygon2[i],polygon2[i+1]);
    glEnd();

    glPointSize(6.0);

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px2346, py2346);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px2345, py2345);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px2356, py2356);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1256, py1256);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1245, py1245);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1246, py1246);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1356, py1356);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1345, py1345);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px1346, py1346);
	glEnd();

    glFlush();
}



void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void init()
{
    glClearColor(1,1,1,0);
    glOrtho(-100,100,-100,100,-1,1);
}



int main(int argc, char *argv[])
{
    glutInit(&argc , argv);
    glutCreateWindow("My House");
    glutInitWindowPosition(200,300);
    glutInitWindowSize(500,500);

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    //cout << "Size Pol1 : " << pol_size1 << endl;
    //cout << "Size Pol2 : " << sizeof(polygon2)/sizeof(*polygon2) << endl;


    return 0;
}
