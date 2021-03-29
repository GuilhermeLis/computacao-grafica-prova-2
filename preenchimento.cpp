#include <GL/glut.h>
#include <stdlib.h>

GLubyte fire[] = { 
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x07, 0xfd, 0xff, 0xf8,
            0x1f, 0xfc, 0xff, 0xe8,
            0xff, 0xe3, 0xbf, 0x70,
            0xde, 0x80, 0xb7, 0x00,
            0x71, 0x10, 0x4a, 0x80,
            0x03, 0x10, 0x4e, 0x40,
            0x02, 0x88, 0x8c, 0x20,
            0x05, 0x05, 0x04, 0x40,
            0x02, 0x82, 0x14, 0x40,
            0x02, 0x40, 0x10, 0x80,
            0x02, 0x64, 0x1a, 0x80,
            0x00, 0x92, 0x29, 0x00,
            0x00, 0xb0, 0x48, 0x00,
            0x00, 0xc8, 0x90, 0x00,
            0x00, 0x85, 0x10, 0x00,
            0x00, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00 
};

GLfloat R, G, B;

int pontoOneX = 10;
int pontoOneY = 10;

int pontoTwoX = 310;
int pontoTwoY = pontoOneY;

int pontoThreeX = pontoTwoX;
int pontoThreeY = 300;

int pontoFourX = pontoOneX;
int pontoFourY = pontoThreeY;

int width = 320;
int height = 320;


void init(void);

void display(void);

void alteraJanela (int height, int width);

void mouse(int button , int state, int x, int y);

void keyboard(unsigned char key, int x, int y);




void init(void)

{
glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho (0, width, 0, height, -1 ,1);

}


void display(void)

    {

        int i;
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_POLYGON_STIPPLE); 
        glColor3f(R, G, B);
        glPolygonStipple(fire);

        glBegin(GL_POLYGON);

        glVertex2i(pontoOneX, pontoOneY); glVertex2i(pontoTwoX, pontoTwoY);
        glVertex2i(pontoThreeX, pontoThreeY); glVertex2i(pontoFourX, pontoFourY);


        glEnd();

        glFlush();
        glutSwapBuffers();
    }

void keyboard(unsigned char key, int x, int y)

{
switch (key) {

    case 27: 
        exit(0); 
        break;
    }
}

void alteraJanela(int x, int y){
    if (y == 0){
        y = 1;
    }
    float taxa = 1.0 * (pontoTwoX/y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, x, y);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button , int state, int x, int y){
   switch (button ) {
      case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN){
                R=(GLfloat)rand()/(RAND_MAX+1.0);
                G=(GLfloat)rand()/(RAND_MAX+1.0);
                B=(GLfloat)rand()/(RAND_MAX+1.0);
                glutPostRedisplay();
        }
         
        break;
    }
}




int main(int argc, char ** argv) 

{

    glutInit(&argc, argv);

    glutInitWindowPosition (200, 200);
    glutCreateWindow("Preenchimento");
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);    
    glutInitWindowSize (width, height);
    
    init();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(alteraJanela);
    glutMainLoop();
    return 0;
}