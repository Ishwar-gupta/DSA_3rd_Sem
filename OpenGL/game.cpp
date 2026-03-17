#include <GL/freeglut.h>
#include <stdlib.h>
#include <cstdio>
#include <cmath>

float shooterX = 250;

const int MAX_BULLETS = 50;
float bulletX[MAX_BULLETS];
float bulletY[MAX_BULLETS];
bool bulletActive[MAX_BULLETS];

float enemyX = 200;
float enemyY = 500;

int score = 0;
int highScore = 0;

int health = 3;
bool gameOver = false;

// ---------------- TEXT ----------------
void drawText(float x, float y, const char *string)
{
    glRasterPos2f(x,y);
    for(int i=0; string[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

// ---------------- CIRCLE ----------------
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++)
    {
        float angle = 2*3.1416*i/100;
        glVertex2f(cx + r*cos(angle), cy + r*sin(angle));
    }
    glEnd();
}

// ---------------- CLOUD ----------------
void drawCloud(float x, float y)
{
    glColor3f(1,1,1);
    drawCircle(x, y, 20);
    drawCircle(x+20, y+10, 25);
    drawCircle(x+40, y, 20);
    drawCircle(x+20, y-10, 20);
}

// ---------------- BACKGROUND ----------------
void drawBackground()
{
    // Sky
    glBegin(GL_QUADS);
    glColor3f(0.5,0.8,1.0);
    glVertex2f(0,500);
    glVertex2f(500,500);
    glColor3f(0.2,0.6,1.0);
    glVertex2f(500,0);
    glVertex2f(0,0);
    glEnd();

    // Clouds
    drawCloud(100,400);
    drawCloud(300,420);
    drawCloud(200,350);
}

// ---------------- ROCKET ----------------
void drawRocket(float x)
{
    glColor3f(0,0.8,0);
    glBegin(GL_POLYGON);
    glVertex2f(x-10,20);
    glVertex2f(x+10,20);
    glVertex2f(x+10,50);
    glVertex2f(x-10,50);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x-10,50);
    glVertex2f(x+10,50);
    glVertex2f(x,70);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(x-10,30);
    glVertex2f(x-20,20);
    glVertex2f(x-10,20);

    glVertex2f(x+10,30);
    glVertex2f(x+20,20);
    glVertex2f(x+10,20);
    glEnd();

    // Fire
    glColor3f(1,0.5,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x-5,20);
    glVertex2f(x+5,20);
    glVertex2f(x,10-rand()%5);
    glEnd();
}

// ---------------- HEALTH BAR ----------------
void drawHealthBar()
{
    float width = health * 40;

    if(health == 3) glColor3f(0,1,0);       // green
    else if(health == 2) glColor3f(1,1,0);  // yellow
    else glColor3f(1,0,0);                  // red

    glRectf(400,450,400+width,470);
}

// ---------------- DISPLAY ----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();

    if(gameOver)
    {
        glColor3f(1,0,0);
        drawText(200,260,"GAME OVER");

        char txt[50];
        sprintf(txt,"Final Score: %d",score);
        drawText(200,230,txt);

        char highTxt[50];
        sprintf(highTxt,"High Score: %d",highScore);
        drawText(200,200,highTxt);

        glFlush();
        return;
    }

    drawRocket(shooterX);

    // Bullets
    glColor3f(1,1,0);
    for(int i=0;i<MAX_BULLETS;i++)
        if(bulletActive[i])
            glRectf(bulletX[i]-3,bulletY[i],bulletX[i]+3,bulletY[i]+12);

    // Enemy
    glColor3f(1,0,0);
    glRectf(enemyX-20,enemyY,enemyX+20,enemyY+20);

    // Score
    char scoreText[30];
    sprintf(scoreText,"Score: %d",score);
    glColor3f(0,0,0);
    drawText(10,470,scoreText);

    // Health bar
    drawHealthBar();

    glFlush();
}

// ---------------- UPDATE ----------------
void update(int value)
{
    if(gameOver) return;

    for(int i=0;i<MAX_BULLETS;i++)
    {
        if(bulletActive[i])
        {
            bulletY[i]+=20;

            if(bulletY[i]>500)
                bulletActive[i]=false;

            if(bulletX[i]>enemyX-20 && bulletX[i]<enemyX+20 &&
               bulletY[i]>enemyY && bulletY[i]<enemyY+20)
            {
                bulletActive[i]=false;
                score++;

                enemyY=500;
                enemyX=rand()%460+20;
            }
        }
    }

    enemyY-=3;

    if(enemyY<40)
    {
        health--;

        if(health<=0)
        {
            gameOver=true;

            if(score > highScore)
                highScore = score;

            printf("\nGame Over\nFinal Score: %d\nHigh Score: %d\n",score,highScore);
        }

        enemyY=500;
        enemyX=rand()%460+20;
    }

    glutPostRedisplay();
    glutTimerFunc(30,update,0);
}

// ---------------- INPUT ----------------
void keyboard(unsigned char key,int x,int y)
{
    if(gameOver) return;

    if(key==' ')
    {
        for(int i=0;i<MAX_BULLETS;i++)
        {
            if(!bulletActive[i])
            {
                bulletActive[i]=true;
                bulletX[i]=shooterX;
                bulletY[i]=50;
                break;
            }
        }
    }

    if(key==27) exit(0);
}

void specialKeys(int key,int x,int y)
{
    if(gameOver) return;

    if(key==GLUT_KEY_LEFT)
    {
        shooterX-=20;
        if(shooterX<20) shooterX=20;
    }

    if(key==GLUT_KEY_RIGHT)
    {
        shooterX+=20;
        if(shooterX>480) shooterX=480;
    }
}

// ---------------- INIT ----------------
void init()
{
    glClearColor(1,1,1,1);

    for(int i=0;i<MAX_BULLETS;i++)
        bulletActive[i]=false;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

// ---------------- MAIN ----------------
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Rocket Shooter");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(25,update,0);

    glutMainLoop();
}