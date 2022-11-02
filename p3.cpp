#include<Gl/glut.h>
#include<stdlib.h>
#include<math.h>
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1.0,0.0,1.0);
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES); //triangle
    glVertex2f(0.1,0.6);
    glVertex2f(0.4,0.6);
    glVertex2f(0.25,0.86);
    glEnd();
    glBegin(GL_QUADS); //rectangle
    glVertex2f(0.6,0.85);
    glVertex2f(0.9,0.85);
    glVertex2f(0.9,0.65);
    glVertex2f(0.6,0.65);
    glEnd();
    glBegin(GL_QUADS); //square
    glVertex2f(0.1,0.1);
    glVertex2f(0.1,0.4);
    glVertex2f(0.4,0.4);
    glVertex2f(0.4,0.1);
    glEnd();
    float angle,x,y;
    glBegin(GL_LINES); //circle
    for (angle=0.0f; angle<=(2.0f*M_PI); angle+=0.01f){
        x = 0.15f * sin(angle);
        y = 0.15f * cos(angle);
        glVertex2f(0.75+x,0.25+y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500.0,500.0);
    glutCreateWindow("Basic Geometry Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
