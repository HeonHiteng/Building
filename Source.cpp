#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<math.h>

static float	tp3 = 0;
static float	pm = 300.0;
static float	bm = 350.0;
static float	bw = 0.0;


float spin = 0.0;

GLfloat	tx = 5;
GLfloat	ty = 5;


//parameter is radius of x,radius of y,position x,position y
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    for (i = 0; i <= 360; i++) {
        rad = i * (3.1416 / 180);
        glVertex2f(x + rx * cos(rad), y + ry * sin(rad));
    }
    glEnd();
}


void sun()
{
    glPushMatrix();
    //location 
    glTranslated(0, 240, 0);
    //orange color
    glColor3f(1.0, 0.76, 0.3);
    //create a sun by using circle
    circle(20, 35, 0, -40);
    glPopMatrix();
}

//create cloud with variable x,y
void make_cloud(int x, int y)
{
    //white color
    glColor3f(1.0, 1.0, 1.0);

    //create cloud by 7 circle
    circle(10, 10, x, y);
    circle(10, 10, x + 10, y);
    circle(10, 10, x + 30, y);
    circle(10, 10, x + 5, y - 10);
    circle(10, 10, x + 20, y - 10);
    circle(10, 10, x + 5, y + 10);
    circle(10, 10, x + 20, y + 10);
}

//create movement of cloud
void cloud_move_right(GLfloat t) {

    //t is the variable that control moving speed
    tp3 = tp3 + t;

    //appear at left when end in right side
    if (tp3 > 600)
        tp3 = -300;
    glutPostRedisplay();
}

//duplicate many cloud in different position
void cloud()
{
    glPushMatrix();
    glTranslatef(tp3, 0, 0);

    //parameter in the bracket is (x,y) location of cloud
    make_cloud(-300, 280);
    make_cloud(-500, 280);
    make_cloud(-200, 250);
    make_cloud(-400, 250);
    make_cloud(200, 250);
    make_cloud(-100, 250);
    make_cloud(-350, 230);
    glPopMatrix();

    // make the cloud move with 0.1 speed
    cloud_move_right(0.1);
    glEnd();
}

//rectangle with four variable point 
void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x, y1);
    glVertex2d(x1, y1);
    glVertex2d(x1, y);
    glEnd();
}


//rectangle with three variable point
void triangle(int x, int y, int x1, int x2, int y1)
{
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x1, y);

    glVertex2d(x1, y);
    glVertex2d(x2, y1);

    glVertex2d(x2, y1);
    glVertex2d(x, y);
    glEnd();
}

//8 point with coordinate (x,y) to create a rectangle
void rectangle1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    glVertex2d(x2, y2);
    glEnd();
}

void hill()
{
    //green color
    glColor3f(0.5, 0.87, 0.3);

    //hill
    circle(70, 120, -250, 90);
    circle(70, 120, -100, 90);
    circle(70, 120, 50, 100);
    circle(70, 120, 200, 90);

}

void soil()
{
    //light green
    glColor3f(0.9, 1.0, 0.9);
    rectangle(-300, -10, 300, 130);
}

void ground()
{
    glColor3f(0.9, 0.9, 0.7);
    rectangle(-300, -300, 300, -10);

}

void road()
{
    //Road Area
    glColor3f(0.3, 0.3, 0.3);
    rectangle(-300, -200, 300, -30);
    
    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(-270, -120, -230, -110);

    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(-270, -120, -200, -110);
    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(-150, -120, 0, -110);

    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(50, -120, 150, -110);
    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(200, -120, 290, -110);

    //road2 area
    glColor3f(0.3, 0.3, 0.3);
    rectangle1(20, 130, 70, 130, 10, -300,80, -300);

    //divider
    glColor3f(1.0, 1.0, 1.0);
    rectangle(43, 120, 47, 70);
    rectangle(43, 40, 47, -20);
    rectangle(43, -200, 47, -290);

}

void sign()
{
    //sign stand
    glColor3f(0, 0.0, 0.0);
    rectangle(-180, -9, -185, 120);

    //sign board
    glColor3f(1, 0.0, 0.0);
    circle(20, 35, -182.5, 120);

    //sign rectangle
    glColor3f(1, 1, 1);
    rectangle(-170, 115, -195, 125);
}



void tree(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    //brown trunk
    glColor3f(0.25, 0.25, 0.25);
    rectangle(a, b, c, d);

    //green tree
    glColor3f(0.0, 0.3, 0.0);
    triangle(e, f, g, h, i);
}

void tree1()
{
    //upper
    tree(-200, 110, -202, 140, -195, 140, -205, -200, 170); //1
    tree(-300, 110, -298, 140, -305, 140, -293, -299, 170); //2
    tree(-270, 110, -268, 140, -275, 140, -263, -269, 170); //3
    tree(-240, 110, -238, 140, -245, 140, -233, -239, 170); //4
    tree(-180, 110, -178, 140, -185, 140, -173, -179, 170); //5
    tree(-150, 110, -148, 140, -155, 140, -143, -149, 170); //6
    tree(-120, 110, -118, 140, -125, 140, -113, -119, 170); //7
    tree(-90, 110, -88, 140, -95, 140, -83, -89, 170); //8
    tree(-60, 110, -58, 140, -65, 140, -53, -59, 170); //9
    tree(-30, 110, -28, 140, -35, 140, -23, -29, 170); //10
    tree(0, 110, 2, 140, -5, 140, 7, 1, 170); //11
    tree(90, 110, 92, 140, 85, 140, 97, 91, 170); //12
    tree(120, 110, 122, 140, 115, 140, 127, 121, 170); //13
    tree(150, 110, 152, 140, 145, 140, 157, 151, 170); //14
    tree(180, 110, 182, 140, 175, 140, 187, 181, 170); //15
    tree(210, 110, 212, 140, 205, 140, 217, 211, 170); //16
    tree(240, 110, 242, 140, 235, 140, 247, 241, 170); //17
    tree(270, 110, 272, 140, 265, 140, 277, 271, 170); //18
    tree(300, 110, 302, 140, 295, 140, 307, 301, 170); //19

    //lower 
    tree(-270, -250, -268, -280, -275, -250, -263, -269, -220); //20
    tree(-240, -250, -238, -280, -245, -250, -233, -239, -220); //21
    tree(-120, -250, -118, -280, -125, -250, -113, -119, -220); //22
    tree(-90, -250, -88, -280, -95, -250, -83, -89, -220); //23
    tree(-60, -250, -58, -280, -65, -250, -53, -59, -220); //24
    tree(-30, -250, -28, -280, -35, -250, -23, -29, -220); //25
    tree(90, -250, 92, -280, 85, -250, 97, 91, -220); //26
    tree(120, -250, 122, -280, 115, -250, 127, 121, -220); //27
    tree(150, -250, 152, -280, 145, -250, 157, 151, -220); //28
    tree(180, -250, 182, -280, 175, -250, 187, 181, -220); //29
    tree(270, -250, 272, -280, 265, -250, 277, 271, -220); //30
}

void hospital()
{
    //front
    glColor3f(.9, 0.10,0.1);
    rectangle(100, -9, 260, 120);

    //side
    glColor3f(.9, 0.5, 0.5);
    rectangle(280, -9, 260, 100);
    rectangle(100, -9, 80, 100);
    
    //top
    glColor3f(0, 0, 0);
    rectangle(95, 130, 265, 120);
    rectangle(160, 40, 200, 30);
    rectangle(285, 110, 260, 100);
    rectangle(100, 110, 75, 100);

    //board
    glColor3f(1.0, 1.0, 1.0);
    circle(10, 20, 180, 145);
    glColor3f(.9, 0.10, 0.1);
    rectangle(175, 142, 185, 148);
    rectangle(178, 132, 182, 158);

    //windows
    glColor3f(1.0, 1.0, 1.0);
    rectangle(165, -9, 195, 30);
    rectangle(110, 100,130, 80);
    rectangle(140, 100, 160, 80);
    rectangle(170, 100, 190, 80);
    rectangle(200, 100, 220, 80);
    rectangle(230, 100, 250, 80);
    rectangle(110, 70, 130, 50);
    rectangle(140, 70, 160, 50);
    rectangle(170, 70, 190, 50);
    rectangle(200, 70, 220, 50);
    rectangle(230, 70, 250, 50);
    rectangle(95, 60, 85, 40);
    rectangle(95, 65, 85, 85);
    rectangle(95, 35, 85, 15);
    rectangle(275, 60, 265, 40);
    rectangle(275, 65, 265, 85);
    rectangle(275, 35, 265, 15);
}


void busmake()
{
    //bus lower body
    glColor3f(0.9, 0.72, 0.0);
    rectangle(-60, -15, 0, 15);
    rectangle(-80, -15, -60, 25);

    //bus upper body
    glColor3f(0.7, 0.7, 0.0);
    rectangle(-60, 15, -2, 50);
    rectangle(-70, 25, -60, 50);

    //bus top
    glColor3f(0.3, 0.2, 0.1);
    rectangle1(-2, 50, -70, 50, -7, 55, -76, 55);

    //bus side
    glColor3f(0.7, 0.60, 0);
    rectangle1(-70, 25, -74, 25, -70, 50, -76, 55);

    //bus door
    glColor3f(0.3, 0.2, 0.1);
    rectangle(-58, 0, -50, 35);

    //bus window
    glColor3f(1, 1, 1);
    rectangle(-45, 30, -40, 40);
    rectangle(-35, 30, -30, 40);
    rectangle(-25, 30, -20, 40);
    rectangle(-15, 30, -10, 40);

    //oval front and back of bus
    glColor3f(0.9, 0.72, 0.0);
    circle(3, 15, 0, 0);
    circle(3, 20, -80, 5);

    //tyres black outer layer
    glColor3f(0, 0, 0);
    circle(8, 16, -10, -15);
    circle(8, 16, -70, -15);

    //tyres white inner layer
    glColor3f(1, 1, 1);
    circle(6, 12, -10, -15);
    circle(6, 12, -70, -15);
}

void busMove() {
    bm = bm - 0.4;
    //when bus move to end of left will appear from right side
    if (bm < -350)
        bm = 350;
    glutPostRedisplay();
}

void bus()
{
    glPushMatrix();
    glTranslatef(bm, -165, 0);
    busmake();
    glPopMatrix();
}


void studentmade() {

    //hair
    glColor3f(0., 0., 0.0);
    circle(10, 20, -40, 90);

    //head
    glColor3f(1, 0.8, 0.0);
    circle(8, 15, -40, 85);

    //body
    glColor3f(0.0, 0.3, 0.8);
    rectangle(-32, 75, -48, 20);
    glColor3f(1, 1, 1);
    rectangle(-32,50, -48, 45);
   
    //limb
    glColor3f(1, 0.8, 0.0);
    rectangle(-32, 75, -27, 30);
    rectangle(-53, 75, -48, 30);
    rectangle(-43, -10, -48, 20);
    rectangle(-32, -10, -37, 20);

    //eye
    glColor3f(0., 0., 0.0);
    rectangle(-38, 90, -35, 95);
    rectangle(-41, 90, -44, 95);

    //mouth
    glColor3f(1, 0., 0.0);
    rectangle(-41, 80, -38, 85);
}


void studentwalk() {
    bw = bw - 0.4;
    //when student move to end of bottom will appear from top
    if (bw < -350)
        bw = 350;
    glutPostRedisplay();
}

void student()
{
    glPushMatrix();
    //the variable of y axis is bw which can be cahnge
    glTranslatef(0, bw, 0);
    studentmade();
    glPopMatrix();
}

void traficlight()
{
    //stand
    glColor3f(0.5, 0.5, 0.5);
    rectangle(0, -270, 5, -150);

    //body
    glColor3f(0.1, 0.1, 0.1);
    rectangle(-10, -185, 15, -80);

    //red light
    glColor3f(1.0, 0, 0);
    circle(5, 10, 2, -100);

    //yellow light
    glColor3f(1.0, 1.0, 0);
    circle(5, 10, 2, -130);

    //green light
    glColor3f(0, 1.0, 0);
    circle(5, 10, 2, -160);
}


void make_tree2()
{
    //leave
    glColor3f(0.0, 0.6, 0.0);
    circle(20, 30, 0, 0);
    circle(20, 30, 20, 0);
    circle(20, 30, 40, 0);
    circle(20, 30, 30, 30);
    circle(20, 30, 10, 30);
    circle(20, 30, 10, -30);
    circle(20, 30, 30, -30);

    //leave 2
    circle(10, 20, 50, -70);
    circle(10, 20, 60, -60);
    circle(10, 20, 60, -80);

    //branch
    glColor3f(0.75, 0.5, 0.25);
    rectangle1(10, -130, 30, -130, 10, -30, 30, -30);
    rectangle1(10, -30, 17, -30, 5, 0, 5, 0);
    rectangle1(17, -30, 22, -30, 19, 0, 19, 0);
    rectangle1(22, -30, 30, -30, 35, 0, 35, 0);
    rectangle1(30, -90, 30, -100, 55, -70, 55, -75);

}

void tree2()
{
    //1st tree
    glPushMatrix();
    glTranslated(-300, 120, 0);
    make_tree2();
    glPopMatrix();

    //2nd tree
    glPushMatrix();
    glTranslated(-200, -150, 0);
    make_tree2();
    glPopMatrix();

    //3rd tree
    glPushMatrix();
    glTranslated(200, -150, 0);
    make_tree2();
    glPopMatrix();

}

void busstop()
{
    //roof
    glColor3f(0.8, 0.8, 1);
    rectangle(-150, 150, 0, 130);
    glColor3f(0.2, 0.2, 0.6);
    rectangle(-150, 120, 0, 130);

    //tiang
    glColor3f(0.2, 0.2, 0.6);
    rectangle(-140, 120, -145, -10);
    rectangle(-10, 120, -5, -10);
    rectangle(-75, 120, -70, -10);
   
    //seat
    glColor3f(0, 0.2, 0.2);
    rectangle(-10, 30, -140, 20);

    //mirror
    glColor3f(0.8, 0.8, 1);
    rectangle(-135, 35, -80, 115);
    rectangle(-65, 35, -15, 115);

    glColor3f(1, 1, 1);
    rectangle(-130, 40, -85, 110);
    rectangle(-60, 40, -20, 110);

    //board
    glColor3f(0.2, 0.2, 0.6);
    rectangle(-115, 145, -35, 180);
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    cloud();
    hill();
    soil();
    ground();
    tree1();
    road();
    busstop();
    student();
    bus();
    tree2();
    sign();
    hospital();
    traficlight();
    glFlush();
}


void init()
{
    glClearColor(0.1, 0.3, 1, 1.0);
    glOrtho(-300, 300, -300, 300, -150, 500);
}

void my_keyboard(unsigned char key, int x, int y)
{

    switch (key) {

        //when 'w' student start walking
    case 'w':
        glutIdleFunc(studentwalk);
        break;

        //when 'r' student rest
    case 'r':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }

    
    switch (key) {
        //when 's' bus start moving
    case 's':
        glutIdleFunc(busMove);
        break;

        //when 'b' bus stop
    case 'b':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Computer Grapics Project");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}