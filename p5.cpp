#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
int choice = 0,rx,ry,px0,px1,py0,py1,transX, transY;
double scaleX, scaleY;
int round1(double number){
return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}
void drawPolygon(int pntX0,int pntY0,int pntX1,int pntY1)
{
glBegin(GL_LINES);
glColor3f(0.0, 0.0, 1.0);
glVertex2i(pntX0, pntY0);
glVertex2i(pntX1,pntY1);
glEnd();
}
void drawPolygonTrans(int x, int y)
{
glBegin(GL_LINES);
glColor3f(0.0, 1.0, 0.0);
glVertex2i(px0 + x, py0 + y);
glVertex2i(px1 + x, py1 + y);
glEnd();
}
void drawPolygonScale(double x, double y)
{
glBegin(GL_LINES);
glColor3f(0.0, 1.0, 1.0);
glVertex2i(round1(px0 * x), round1(py0 * y));
glVertex2i(round1(px1 * x), round1(py1 * y));
glEnd();
}
void drawPolygonrotate(int rx1,int ry1)
{
 float p=sin((30*3.14)/180);
 float q=cos((30*3.14)/180);
 rx=rx1*p - ry1*q;
 ry=rx1*p + ry1*q;
}
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
if (choice == 1)
{
drawPolygon(px0,py0,px1,py1);
drawPolygonTrans(transX, transY);
}
else if (choice == 2)
{
drawPolygon(px0,py0,px1,py1);
drawPolygonScale(scaleX, scaleY);
}
else if(choice == 3)
 {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(255,255,255);
 drawPolygon(px0,py0,px1,py1);
 drawPolygonrotate(px1,py1);
 glBegin(GL_LINES);
glColor3f(0.0, 1.0, 0.0);
glVertex2i(px0, py0);
glVertex2i(rx,ry);
glEnd();
 int i=0;
 while(i<5)
 {
 drawPolygonrotate(rx,ry);
 glColor3f(1,0,0);
 glBegin(GL_LINES);
glColor3f(1.0, 0.0, 0.0);
glVertex2i(px0, py0);
glVertex2i(rx,ry);
glEnd();
 i++;
 }
 }
glFlush ();
}
int main(int argc, char** argv)
{
cout << "Enter your choice:\n\n" << endl;
cout << "1. Translation" << endl;
cout << "2. Scaling" << endl;
cout << "3. Rotation" << endl;
cout<<"4.Exit"<<endl;
cin >> choice;
if (choice == 4) {
return 0;
}
 cout << "Enter co-ordinates for vertex 1 : " ; cin >> px0 >> py0;
 cout << "Enter co-ordinates for vertex 2 : " ; cin >> px1 >> py1;
if (choice == 1)
{
cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
}
else if (choice == 2)
{
cout << "Enter the scaling factor for X and Y: "; cin >> scaleY >> scaleX;
}
 glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 400);
glutInitWindowPosition (50, 50);
glutCreateWindow ("Basic Transformations");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
return 0;
}
