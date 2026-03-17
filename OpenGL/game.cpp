#include <GL/freeglut.h>
#include <stdlib.h>
#include <cstdio>

// to run this program type in terminal :
// g++ game.cpp -o game -lfreeglut -lopengl32 -lglu32
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

void drawText(float x, float y, const char *string)
{
    glRasterPos2f(x,y);
    for(int i=0; string[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(gameOver)
    {
        glColor3f(1,0,0);
        drawText(210,250,"GAME OVER");

        char finalText[50];
        sprintf(finalText,"Final Score: %d",score);
        drawText(200,220,finalText);

        glFlush();
        return;
    }

    // Shooter
    glColor3f(0,1,0);
    glRectf(shooterX-20,20,shooterX+20,40);

    // Bullets
    glColor3f(1,1,0);
    for(int i=0;i<MAX_BULLETS;i++)
    {
        if(bulletActive[i])
            glRectf(bulletX[i]-3,bulletY[i],bulletX[i]+3,bulletY[i]+12);
    }

    // Enemy
    glColor3f(1,0,0);
    glRectf(enemyX-20,enemyY,enemyX+20,enemyY+20);

    // Score
    char scoreText[40];
    sprintf(scoreText,"Score: %d",score);
    glColor3f(1,1,1);
    drawText(10,470,scoreText);

    // High Score
    char highText[40];
    sprintf(highText,"High Score: %d",highScore);
    drawText(200,470,highText);

    // Health
    char healthText[30];
    sprintf(healthText,"Health: %d",health);
    drawText(420,470,healthText);

    glFlush();
}

void update(int value)
{
    if(gameOver) return;

    // Move bullets
    for(int i=0;i<MAX_BULLETS;i++)
    {
        if(bulletActive[i])
        {
            bulletY[i] += 20;

            if(bulletY[i] > 500)
                bulletActive[i] = false;

            // Collision
            if(bulletX[i] > enemyX-20 && bulletX[i] < enemyX+20 &&
               bulletY[i] > enemyY && bulletY[i] < enemyY+20)
            {
                bulletActive[i] = false;
                score++;

                if(score > highScore)
                    highScore = score;

                enemyY = 500;
                enemyX = rand()%460 + 20;
            }
        }
    }

    // Enemy movement
    enemyY -= 3;

    if(enemyY < 40)
    {
        health--;

        if(health <= 0)
        {
            gameOver = true;
            printf("\nGame Over\nFinal Score: %d\nHigh Score: %d\n",score,highScore);
        }

        enemyY = 500;
        enemyX = rand()%460 + 20;
    }

    glutPostRedisplay();
    glutTimerFunc(30,update,0);
}

void keyboard(unsigned char key,int x,int y)
{
    if(gameOver) return;

    if(key == ' ')
    {
        // Find free bullet slot
        for(int i=0;i<MAX_BULLETS;i++)
        {
            if(!bulletActive[i])
            {
                bulletActive[i] = true;
                bulletX[i] = shooterX;
                bulletY[i] = 50;
                break;
            }
        }
    }

    if(key == 27)
        exit(0);
}

void specialKeys(int key,int x,int y)
{
    if(gameOver) return;

    if(key == GLUT_KEY_LEFT)
    {
        shooterX -= 20;
        if(shooterX < 20)
            shooterX = 20;
    }

    if(key == GLUT_KEY_RIGHT)
    {
        shooterX += 20;
        if(shooterX > 480)
            shooterX = 480;
    }
}

void init()
{
    glClearColor(0,0,0,0);

    for(int i=0;i<MAX_BULLETS;i++)
        bulletActive[i] = false;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Fire Shooter Game");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(25,update,0);

    glutMainLoop();
}