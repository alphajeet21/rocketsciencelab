#include <GL/glut.h>
#include <stdlib.h>
static void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity() ;
    glOrtho(-50.0,50.0,-50.0,50.0, -1.0, 1.0);
}

static void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
    glLineWidth(2.5);
    glVertex3f(-45,30,0);
    glVertex3f(-30,30,0);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return EXIT_SUCCESS;
}