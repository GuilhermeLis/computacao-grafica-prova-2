#include <GL/glut.h>

#include <stdlib.h>

#include <math.h>

#include <thread>

#include <iostream>

#include <stdio.h>

using namespace std;

// Function Prototypes
void init(void);

void display(void);
void specialKeys();

// Global Variables
double rotate_y=0; 
double rotate_x=0;



void init(void)

{

glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho (0, 600, 0, 600, -1 ,1);
glShadeModel(GL_FLAT);

}

void piramede()
    {
        int pontoOneX = 10;
        int pontoOneY = 10;

        int pontoTwoX = 290;
        int pontoTwoY = 80;

        int pontoThreeX = 390;

        int pontoFourX = 110;

        int pontoFiveX = 220;
        int pontoFiveY = 450;

        glClear(GL_COLOR_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glColor3f(1.0,0.8,0.2);
        glLineWidth(2);

        glBegin(GL_QUADS);

        glVertex2i(pontoOneX,pontoOneY);
        glVertex2i(pontoThreeX,pontoOneY);
        glVertex2i(pontoTwoX,pontoTwoY);
        glVertex2i(pontoFourX,pontoTwoY);

        glEnd(); // Base do quadrado

        glBegin(GL_POLYGON);

        glVertex2i(pontoOneX,pontoOneY);
        glVertex2i(pontoFourX,pontoTwoY);
        glVertex2i(pontoFiveX,pontoFiveY);

        glEnd();

        glBegin(GL_POLYGON);

        glVertex2i(pontoTwoX,pontoTwoY);
        glVertex2i(pontoThreeX,pontoOneY);
        glVertex2i(pontoFiveX,pontoFiveY);

        glEnd();

        glutSwapBuffers(); // glutSwapBuffers troca os buffers da janela atual se duplo buffer.



    }

void cubo()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPolygonMode(GL_FRONT, GL_LINE);

        glColor3f(0.0,0.0,1.0);
        glLineWidth(2);

        int comprimento = 50;

        // first square

        int pontoOneX = 550;
        int pontoOneY = 100;

        int pontoTwoX = 200;
        int pontoTwoY = pontoOneY;

        int pontoThreeX = 150;
        int pontoThreeY = pontoOneY - comprimento;

        int pontoFourX = 500;
        int pontoFourY = pontoThreeY;

        // second square

        int pontoFiveX = pontoOneX;
        int pontoFiveY = 550;

        int pontoSexX = pontoTwoX;
        int pontoSexY = pontoFiveY;

        int pontoSevenX = pontoThreeX;
        int pontoSevenY = pontoFiveY - comprimento;

        int pontoEightX = pontoFourX;
        int pontoEightY = pontoSevenY;


        glBegin(GL_QUADS);

        glVertex2i(pontoOneX,pontoOneY); glVertex2i(pontoTwoX,pontoTwoY);
        glVertex2i(pontoThreeX,pontoThreeY); glVertex2i(pontoFourX,pontoFourY);

        glEnd();

        glBegin(GL_QUADS);

        glVertex2i(pontoFiveX,pontoFiveY);  glVertex2i(pontoSexX,pontoSexY);
        glVertex2i(pontoSevenX,pontoSevenY);   glVertex2i(pontoEightX,pontoEightY);

        glEnd();

        glBegin(GL_QUADS);

        glVertex2i(pontoOneX,pontoOneY); glVertex2i(pontoFiveX,pontoFiveY); 
        glVertex2i(pontoEightX,pontoEightY); glVertex2i(pontoFourX,pontoFourY);

        glEnd();

        glBegin(GL_QUADS);

        glVertex2i(pontoThreeX,pontoThreeY);  glVertex2i(pontoSevenX,pontoSevenY);
        glVertex2i(pontoSexX,pontoSexY); glVertex2i(pontoTwoX,pontoTwoY);

        glEnd();

        glutSwapBuffers();
    } //d2

int main(int argc, char ** argv) 

    {
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);

    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);

    glutCreateWindow("Piramade");

    init();


    glutDisplayFunc(cubo);  


    glutMainLoop();
    return 0;

    }