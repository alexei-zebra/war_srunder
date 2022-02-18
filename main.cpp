#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "glFunc.hpp"

void display(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       
    //    glPointSize(6);
    //    glColor3f(1.0f,1.0f,1.0f);
    //    glBegin(GL_POINTS);//рисуем черную точку
    //    glVertex2f(-0.5f, 0.2f);
    //    glEnd();

        draw::v2::point({1.0f, 1.0f, 1.0f}, 6, {-0.5, 0.2});
       
        draw::v2::line({1.0f, 0.0f, 0.0f}, 3, {-1.0f, 1.0f}, {1.0f, -1.0f});
    //    glLineWidth(3);
    //    glColor3f(1.0f,0.0f,0.0f);
    //    glBegin(GL_LINES);//рисуем красную линию
    //    glVertex2d(-1,  1);
    //    glVertex2d( 1, -1);
    //    glEnd();
       
    
        glColor3f(0.0f, 1.0f,0.0f);
        glBegin(GL_TRIANGLES);//рисуем зеленый треугольник
        glVertex2d(0,   0);
        glVertex2f(0.5, 1);
        glVertex2d(1,   0);
        glEnd();
       
        glColor3f(0.0f, 0.0f, 1.0f);//рисуем синий треугольник
        glBegin(GL_QUADS);
        glVertex2d(-1, -1);
        glVertex2d(-1,  0);
        glVertex2d( 0,  0);
        glVertex2d( 0, -1);
        glEnd();
       
        glutSwapBuffers();//прорисовываем буфер на экран
}
void drawinit(){
}

int main(int pargc, char** argv){
    int width = 800;
    int height = 800;
    int size = 1;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(50, 50);
    glutInit(&pargc, argv);
    glutCreateWindow("Test");
    drawinit();
    glutDisplayFunc(display);
    //glutIdleFunc(draw);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 0, 0);
    glutMainLoop();
    return 0;
}