#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>

using namespace std;

const int width = 1000;
const int height = 1000;

GLfloat eyeX = 10;
GLfloat eyeY = 30;
GLfloat eyeZ = 80;

GLfloat lookX = 10;
GLfloat lookY = 5;
GLfloat lookZ = 0;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}




void Chair12()
{
    float height=2;
    float width=4;
    float length=2;

    float base_height=.5;
    float leg_height=height-base_height;
    float leg_width=.4;

    // whole table
    glPushMatrix();
    glTranslatef(0,leg_height,0);

    // base
    glPushMatrix();
    glScalef(width,base_height,length);
    glTranslatef(-0.5,0,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();
//upper put
    glPushMatrix();
    glScalef(3,2,.5);
    glTranslatef(-0.5,.5,-1);
    cube(1,1,0);
    glPopMatrix();

    //middle part 1
    glPushMatrix();
    glScalef(.2,1,.2);
    glTranslatef(3,0,-2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glScalef(.2,1,.2);
    glTranslatef(-4,0,-2);
    cube(0,0,0);
    glPopMatrix();


    glPopMatrix();

}



void fliedGround(){
    //FIELD
    glPushMatrix();
    glScaled(50,1,50);
    cube(0.0,1.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glScaled(-50,1,50);
    cube(0.0,1.0,0.0);
    glPopMatrix();

};

void roadMap1(){
    //left side
    glPushMatrix();
    glScaled(-6,1.2,50);
    cube(0.1,0.1,0.1);
    glPopMatrix();
    //right side
    glPushMatrix();
    glScaled(6,1.2,50);
    cube(0.1,0.1,0.1);
    glPopMatrix();

    //mid white sign
    glPushMatrix();
    glScaled(0.1,1.5,50);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //right yellow sign
    glPushMatrix();
    glTranslated(-0.8,0,0);
    glScaled(0.3,1.3,50);
    cube(1.0,1.0,0.0);
    glPopMatrix();

    //left yellow sign
    glPushMatrix();
    glTranslated(0.6,0,0);
    glScaled(0.3,1.3,50);
    cube(1.0,1.0,0.0);
    glPopMatrix();


};




void houseModel(){



//house 1
    //back
    glPushMatrix();
    glTranslated(11,0,11);
    glScaled(10,8,1);
    cube(0.9,0.2,0.1);
    glPopMatrix();

    //front
    glPushMatrix();
    glTranslated(11,0,22);
    glScaled(10,8,1);
    cube(0.9,0.2,0.1);
    glPopMatrix();




    //left
    glPushMatrix();
    glTranslated(11,0,12);
    glScaled(1,8,10);
    cube(0.9,0.2,0.9);
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslated(20,0,12);
    glScaled(1,8,10);
    cube(0.8,0.2,0.8);
    glPopMatrix();

    //top
    glPushMatrix();
    glTranslated(10,7.5,10.9);
    glScaled(12,1,12);
    cube(0.1,0.5,0.5);
    glPopMatrix();

    //roof top
    glPushMatrix();
    glTranslated(12,8,11.9);
    glScaled(2,3,2);
    cube(0.1,0.1,0.5);
    glPopMatrix();


    //front door
    glPushMatrix();
    glTranslated(14.5,0,22.1);
    glScaled(3,6,1);
    cube(0.9,0.5,0.1);
    glPopMatrix();


    //left window
    glPushMatrix();
    glTranslated(10.5,3,18);
    glScaled(1,5,3);
    cube(0.9,0.9,0.9);
    glPopMatrix();

    //right window
    glPushMatrix();
    glTranslated(20.5,3,18);
    glScaled(1,5,3);
    cube(0.9,0.9,0.9);
    glPopMatrix();


}


void electricalTower(){

    glPushMatrix();
    glScaled(0.8,18,0.8);
    cube(0.309804,0.184314,0.184314);
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslated(-2,18,0);
    glScaled(5,0.8,0.8);
    cube(0.309804,0.184314,0.184314);
    glPopMatrix();

    //dotLine right
    glPushMatrix();
    glTranslated(1,18.5,0.001);
    glScaled(1,0.8,0.7);
    cube(0.0,1.0,1.0);
    glPopMatrix();

    //dotLine left
    glPushMatrix();
    glTranslated(-1,18.5,0.001);
    glScaled(1,0.8,0.7);
    cube(0.0,1.0,1.0);
    glPopMatrix();

};


void pool(){

    //water
    glPushMatrix();
    glScaled(15,1.2,15);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    //wall 1
    glPushMatrix();
    glScaled(16,1.5,0.3);
    cube(0.0,1.0,1.0);
    glPopMatrix();

    //wall 2
    glPushMatrix();
    glScaled(1,1.5,15);
    cube(0.0,1.0,1.0);
    glPopMatrix();

    //wall 3
    glPushMatrix();
    glTranslated(0.3,0,15);
    glScaled(16,1.5,0.3);
    cube(0.0,1.0,1.0);
    glPopMatrix();

    //wall 4
    glPushMatrix();
    glTranslated(15,0,0.3);
    glScaled(1,1.5,15);
    cube(0.0,1.0,1.0);
    glPopMatrix();


};


void car(){

    //body
    glPushMatrix();
    glTranslated(1.4,2,12);
    glScaled(4,2,8);
    cube(0.1,0.3,0.1);
    glPopMatrix();

    //top
    glPushMatrix();
    glTranslated(1.4,4,13);
    glScaled(4,2,5);
    cube(0.2,1.1,0.9);
    glPopMatrix();

    //head left light
    glPushMatrix();
    glTranslated(1.6,2.8,20);
    glScaled(0.8,0.8,0.2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //head right light
    glPushMatrix();
    glTranslated(4.4,2.8,20);
    glScaled(0.8,0.8,0.2);
    cube(1.0,1.0,1.0);
    glPopMatrix();

}


void tree(){

    //tree body
    glPushMatrix();
    glTranslated(-0.4,0,0);
    glScaled(1,15,1);
    cube(0.522,0.369,0.259);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(45.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(-45.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(90.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(-90.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(120.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glRotated(-120.0,0,0,1);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();









    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(45.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(-45.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(90.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(-90.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(120.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glRotated(-120.0,1,1,0);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();


    //leaf
    glPushMatrix();
    glTranslated(0,14.5,0.5);
    glScaled(0.5,6,0.5);
    cube(0.208,0.443,0.024);
    glPopMatrix();

}


void playGround(){

    //field
    glPushMatrix();
    glTranslated(0,0.3,0);
    glScaled(30,1,15);
    cube(0.937,0.961,0.514);
    glPopMatrix();

}


void goalbar(){

    glPushMatrix();
    glScaled(0.4,8,0.4);
    cube(1.0,1.0,1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,0,5);
    glScaled(0.4,8,0.4);
    cube(1.0,1.0,1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,8,0);
    glScaled(0.4,0.4,5.3);
    cube(1.0,1.0,1.0);
    glPopMatrix();

}










static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);



    //filed
    fliedGround();

    //road
    roadMap1();


    //playground
    glPushMatrix();
    glTranslated(-45,0,35);
    playGround();
    glPopMatrix();


    //goal bar left side
    glPushMatrix();
    glTranslated(-45.5,0,40);
    goalbar();
    glPopMatrix();

    //goal bar right side
    glPushMatrix();
    glTranslated(-15,0,40);
    goalbar();
    glPopMatrix();




    //tree 1
    glPushMatrix();
    glTranslated(15,0,30);
    tree();
    glPopMatrix();

    //tree 2
    glPushMatrix();
    glTranslated(25,0,30);
    tree();
    glPopMatrix();

    //tree 3
    glPushMatrix();
    glTranslated(35,0,30);
    tree();
    glPopMatrix();


    //tree 4
    glPushMatrix();
    glTranslated(45,0,30);
    tree();
    glPopMatrix();



    //tree pool
    glPushMatrix();
    glTranslated(47,0,3);
    tree();
    glPopMatrix();


    // left house trees

    //tree 1
    glPushMatrix();
    glTranslated(-15,0,30);
    tree();
    glPopMatrix();

    //tree 4
    glPushMatrix();
    glTranslated(-45,0,30);
    tree();
    glPopMatrix();






    //car
    glPushMatrix();
    car();
    glPopMatrix();



    //2nd car
    glPushMatrix();
    glTranslated(-6.5,0,16);
    car();
    glPopMatrix();


    //first house
    houseModel();

    //house walls 1
    glPushMatrix();
    glTranslated(7,0,0);
    glScaled(0.4,3,26);
    cube(1.0,1.0,0.894);
    glPopMatrix();

    //right pool
    glPushMatrix();
    glTranslated(30,0,5);
    pool();
    glPopMatrix();

    //right electricalTower
    glPushMatrix();
    glTranslated(8,0,5);
    electricalTower();
    glPopMatrix();

    //front chair right
    glPushMatrix();
    glTranslated(20,0,26);
    Chair12();
    glScaled(1,2,1);
    glPopMatrix();







    //second left house
    glPushMatrix();
    glTranslated(-30,0,0);
    houseModel();
    glPopMatrix();

    //house walls 1
    glPushMatrix();
    glTranslated(-7,0,0);
    glScaled(0.4,3,26);
    cube(1.0,1.0,0.894);
    glPopMatrix();

    //left pool
    glPushMatrix();
    glTranslated(-40,0,5);
    pool();
    glPopMatrix();


    //left electricalTower
    glPushMatrix();
    glTranslated(-8,0,5);
    electricalTower();
    glPopMatrix();

    //left chair
    glPushMatrix();
    glTranslated(-18,0,26);
    Chair12();
    glScaled(1,2,1);
    glPopMatrix();








    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'w':
        eyeY=eyeY+0.1;
        break;
    case 's':
        eyeY=eyeY-0.1;
        break;
    case 'd':
        eyeX=eyeX+0.1;
        break;
    case 'a':
        eyeX=eyeX-0.1;
    break;

    case 'i':
        lookY=lookY+0.1;
        break;
    case 'k':
        lookY=lookY-0.1;
        break;
    case 'j':
        lookX=lookX+0.1;
        break;
    case 'l':
        lookX=lookX-0.1;
        break;


    case '+':
        eyeZ=eyeZ+0.1;
        break;
    case '-':
        eyeZ=eyeZ-0.1;
        break;

    }

    glutPostRedisplay();
}


int main (int argc, char **argv)
{
    printf("3D Modern Village \n------------------ \n \n");
    printf("Press (-) for Zoom in \n");
    printf("Press (+) for Zoom Out \n");
    printf("Press (A) for Left \n");
    printf("Press (D) for Right \n");
    printf("Press (W) for Up \n");
    printf("Press (S) for Down \n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("3D Modern Village");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();


    return 0;
}
