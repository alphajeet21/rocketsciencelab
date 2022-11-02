// Write a C program to draw a cube and show
// translation, rotation and scaling motion of the line using OpenGL.
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
GLfloat T = 45;
GLfloat D = -1;
GLfloat Z = 0.01;
void MyInit() {
 glClearColor(1, 1, 1, 1);
 glColor3f(1, 0, 0);
 glEnable(GL_DEPTH_TEST);
}
void spin() {
 T = T + 0;
 if(T > 360) T = 0;
 glutPostRedisplay();
}
void translate() {
 D = D + 0.01;
 if(D > 0) D = -1;
 glutPostRedisplay();
}
void scale() {
 Z = Z + 0.01;
 if(Z > 1.1) Z = 0.01;
 glutPostRedisplay();
}
void allinone() {
 T = T + 1;
 if(T > 360) T = 0;
 D = D + 0.01;
 if(D > 0) D = -1;
 Z = Z + 0.01;
 if(Z > 1.1) Z = 0.01;
 glutPostRedisplay();
}
void face(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat d[]) {
 glBegin(GL_POLYGON);
 glVertex3fv(a);
 glVertex3fv(b);
 glVertex3fv(c);
 glVertex3fv(d);
 glEnd();
}
void cube(GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[], GLfloat
v5[], GLfloat v6[], GLfloat v7[]) {
 glColor3f(1, 0, 0);
 face(v0, v1, v2, v3);
 glColor3f(0, 1, 0);
 face(v4, v5, v6, v7);
 glColor3f(0, 0, 1);
 face(v0, v3, v7, v4);
 glColor3f(0, 1, 1);
 face(v1, v2, v6, v5);
 glColor3f(1, 0, 1);
 face(v0, v1, v5, v4);
 glColor3f(1, 1, 0);
 face(v3, v2, v6, v7);
}
void display() {
 GLfloat v[8][3] = {
 {-0.5, 0.5, 0.5},
 {0.5, 0.5, 0.5},
 {0.5, -0.5, 0.5},
 {-0.5, -0.5, 0.5},
 {-0.5, 0.5, -0.5},
 {0.5, 0.5, -0.5},
 {0.5, -0.5, -0.5},
 {-0.5, -0.5, -0.5}
 };
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glRotatef(T, 1, 1, 0);
 glTranslatef(D, 0, 0);
 glScalef(Z, Z, Z);
 cube(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
 glutSwapBuffers();
}
int main(int argc, char *argv[]) {
 glutInit(&argc, argv);
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(200, 200);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 if (!glutGet(GLUT_DISPLAY_MODE_POSSIBLE))
 {
 exit(1);
 }
 glutCreateWindow("Cube");
 MyInit();
 glutDisplayFunc(display);
 glutIdleFunc(allinone);
 glutMainLoop();
 return 0;
}
