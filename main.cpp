#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
float r;
void circle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,-1.0);
        glVertex2f(0.0,1.0);
    glEnd();
    glPointSize(5);
    glBegin(GL_POINTS);
    float x=0, y=r, p;
    p=1-r;
    while(x<=y){
        glColor3f(1.0,0.0,0.0);
        glVertex2f(x/100,y/100);
        glVertex2f(x/100,-y/100);
        glVertex2f(-x/100,y/100);
        glVertex2f(-x/100,-y/100);
        glVertex2f(y/100,x/100);
        glVertex2f(y/100,-x/100);
        glVertex2f(-y/100,x/100);
        glVertex2f(-y/100,-x/100);

        if(p<0){
            p=p+2*x+3;
            x++;
        }
        else{
            p=p+2*x-2*y+5;
            x++; y--;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    cout<<"Enter radius (r): ";
    cin>>r;
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("LAB 3");
    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}
