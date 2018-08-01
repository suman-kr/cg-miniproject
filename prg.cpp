//g++ new.cpp -std=c++14 -lGLU -lGL -lglut && ./a.out
#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
int prime,generator, flag = 0;
char p[10],g[10];
int a,b;
char pal[10],pbb[10];
long int pa,pb;
char al[10],bb[10];
char sha[10];
void output(int x, int y, char *string)
{
  glColor3f(0,0,0);
   int len, i;
   glRasterPos2f(x, y);
   len = (int) strlen(string);
   for (i = 0; i < len; i++)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
   glFlush();
}

void delay(int x = 1) {
   this_thread::sleep_for(chrono::milliseconds(x * 3));
}

// x, y = lower left corner
void clearArea(int x, int y, int width, int height, int deb = 0) {
    float scale = 10.0 / 7;
    // glScissor(x * scale, y * scale, width * scale, height * scale);
    glScissor(x * scale, y, width * scale, height);
    glEnable(GL_SCISSOR_TEST);
    if (deb)
        glClearColor(1, 1, 1, 1);
    else
        glClearColor(0.4,0.3,0.8,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
    glFlush();
}
void clearArea1(int x, int y, int width, int height) {
    int scale = 3;
    glScissor(x * scale, y * scale, width * scale, height * scale);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
    glFlush();
}
void tostring(char str[], long int num)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++ )
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
int isPrime(int n)
{
   int i,c=0;
   for(i=1;i<n;i++)
   {
      if(n%i == 0)
         c++;
   }
   if (c==1)
      return 1;
   else
      return 0;
}

void sk()
{
    double yinc = 120.0 / 450.0;
    double y = 350;
    for (int x = 70; x <= 520; x += 1, y -= yinc) {
        output(x, round(y), "g^a (mod) p = A");
        output(x + 30, round(y) - 45, pal);
        delay(1);
        if (x != 520)
            clearArea(x - 4, y - 54, 150 + 4, 80 + 4);
    }
    y = 350;
    for (int x = 520; x >= 70; x -= 1, y -= yinc) {
        output(x, round(y), "g^b (mod) p = B");
        output(x + 30, round(y) - 45, pbb);
        delay(1);
        if (x != 70)
            clearArea(x - 4, y - 54, 150 + 4, 80 + 4);
    }
}

void alice()
{
   pa = (((long int)pow(generator,a)) % prime);
   printf("public key of alice:%ld\n",pa);
   tostring(pal,pa);
   for (int x=0; x < 70; x += 1) {
      output(x, 350, "g^a (mod) p = A");
      delay(2);
      if (x != 69)
         clearArea(x, 325, 150, 50);
   }
   output(100,305,pal);
}
void bob()
{
   pb = (((long int)pow(generator,b)) % prime);
   printf("public key of bob:%ld\n",pb);
   tostring(pbb,pb);
   for (int x=600; x >= 520; x -= 1) {
      output(x, 350, "g^b (mod) p = B");
      delay(2);
      if (x != 520)
         clearArea(x, 325, 150, 50);
   }
   output(550,305,pbb);
   // swapKey();
}

long long powM(long long base, long long exp, long long mod) {
  long long res = 1;
  for (int i = 0; i < exp; i++) {
    res = (res * base) % mod;
  }
  return res;
}

void grid() {
  glColor3f(1, 1, 1);
  for (int i = 0; i < 1000; i+= 50) {
    for (int j = 0; j < 700; j+=50) {
      glBegin(GL_LINES);
        glVertex2i(i, 0);
        glVertex2i(i, 700);
      glEnd();
      glBegin(GL_LINES);
        glVertex2i(0, j);
        glVertex2i(700, j);
      glEnd();
    }
  }
  glFlush();
}

void shared() {
   long long sh = powM(generator, a * b, prime);
   cout << "shared secret:"<< sh <<endl;
   output(75,100,"g^(a*b) (mod) p");
   tostring(sha,sh);
   cout << sha << endl;
   output(110,75,sha);
   output(520,100,"g^(a*b) (mod) p");
   output(560,75,sha);

   for (int y=250; y < 300; y += 1) {
     output(250,y,"CONNECTION ESTABLISHED!!");
      delay(2);
      if (y != 299)
         clearArea(250,y - 10, 245, 50);
   }
  glColor3f(1, 0, 0);
  for (int i = 200; i < 500; i++) {
    glBegin(GL_POLYGON);
      glVertex2i(i, 550);
      glVertex2i(i + 1, 550);
      glVertex2i(i + 1, 560);
      glVertex2i(i, 560);
    glEnd();
    glFlush();
    delay(1);
  }
}
void output2(int x, int y, char *string)
{
   int len, i;
   glRasterPos2f(x, y);
   len = (int) strlen(string);
   for (i = 0; i < len; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
   glFlush();
}
void prac()
{
  cout << "prac" <<endl;
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,1,1);
  output2(300,600,"Discrete Logarithm");
  // output2()
  glFlush();
}
void computer()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(55.0,525.0);
glVertex2f(145.0,525.0);
glVertex2f(150.0,535.0);
glVertex2f(60.0,535.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(60.0,540.0);
glVertex2f(150.0,540.0);
glVertex2f(150.0,555.0);
glVertex2f(60.0,555.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cpu
glBegin(GL_LINE_LOOP);
glVertex2f(75.0,565.0);
glVertex2f(135,565.0);
glVertex2f(135.0,615.0);
glVertex2f(75.0,615.0);
glEnd();

glColor3f(0.7,0.8,0.6);//monitor
glBegin(GL_QUADS);
glVertex2f(80.0,570.0);
glVertex2f(130.0,570.0);
glVertex2f(130.0,610.0);
glVertex2f(80.0,610.0);
glEnd();

glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(90.0,555.0);
glVertex2f(90.0,565.0);
glVertex2f(120.0,555.0);
glVertex2f(120.0,565.0);
glEnd();
}
void computer_dest()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(545.0,525.0);
glVertex2f(635.0,525.0);
glVertex2f(640.0,535.0);
glVertex2f(550.0,535.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(550.0,540.0);
glVertex2f(640.0,540.0);
glVertex2f(640.0,555.0);
glVertex2f(550.0,555.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cpu
glBegin(GL_LINE_LOOP);
glVertex2f(565.0,565.0);
glVertex2f(625,565.0);
glVertex2f(625.0,615.0);
glVertex2f(565.0,615.0);
glEnd();

glColor3f(0.7,0.8,0.6);//monitor
glBegin(GL_QUADS);
glVertex2f(570.0,570.0);
glVertex2f(620.0,570.0);
glVertex2f(620.0,610.0);
glVertex2f(570.0,610.0);
glEnd();

glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(580.0,555.0);
glVertex2f(580.0,565.0);
glVertex2f(610.0,555.0);
glVertex2f(610.0,565.0);
glEnd();
}

void keys()
{
    cout << "in keys" << endl;
    tostring(p,prime);
    tostring(g,generator);
    glClearColor(0.4,0.3,0.8,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    output(75,630,"ALICE");
    output(565,630,"BOB");
    output(295,610,"PRIME:");
    output(295,580,"GENERATOR:");
    output(360,610,p);
    output(410,580,g);
    computer();
    computer_dest();
    tostring(al,a);
    tostring(bb,b);
    glColor3f(0.0,0.0,0.0);
    output(60,450,"PRIVATE KEY");
    output(85,425,al);
    output(550,450,"PRIVATE KEY");
    output(575,425,bb);
    // output(695, 300, "public key");
    glFlush();
}
void display()
{
   glClearColor(0.4,0.3,0.8,1.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0,0.0,0.0);
   output(350,550,"OpenGl");
   output(310,450,"MINI PROJECT ON");
   output(310,400,"DIFFIE HELLMAN");
   output(450,200,"By:");
   output(475,180,"SUMAN KUMAR");
   output(475,150,"SUBHASHIS GUPTA");
   output(150,010,"Press S/s to Start");
   output(300,010,"Press Q/q to Quit");
   glFlush();
}
void scan_menu(int id){
   if(id==1){
      alice();
      bob();
      sk();
      //grid();
      // flag = 1;
        // glutPostRedisplay();
   }
   else if (id == 2){
            shared();
   }
   else{ exit(0); }
    // glutPostRedisplay();
}
void keyfunc (unsigned char key, int x, int y)
{
   switch(key) {

      case 'S' :
      case 's' :
         // glutDisplayFunc(keys);
          // glutPostRedisplay();
         keys();
         break;
      case 'n':
      case 'N': prac();
        break;
      case 'q':
      case 'Q':
             exit(0);
    }
}
int main(int argc, char** argv)
{
   srand(time(0));
   while (1)
   {
      prime = rand()%(500 + 1 - 100)+100;
      if (isPrime(prime)==1)
         break;
   }
   while (1)
   {
      generator = rand()%(100 + 1 - 10)+10;
      if (isPrime(generator)==1)
         break;
   }
   printf("prime no:%d\n",prime);
   printf("generator:%d\n",generator);
   printf("Enter private key for Alice:\n");
   scanf("%d",&a);
   printf("Enter private key for Bob:\n");
   scanf("%d",&b);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(1000,700);
   glutInitWindowPosition(0,0);
   glutCreateWindow("Diffie Hellman");
   glMatrixMode(GL_MODELVIEW);//INIT
   gluOrtho2D(0,700,0,700);
   glPointSize(10.0);
   glutKeyboardFunc(keyfunc);//enabling keyboard
   glutCreateMenu(scan_menu);//enabling mouse right button
   glutAddMenuEntry("exchange keys",1);
   glutAddMenuEntry("shared secret",2);
   glutAddMenuEntry("Quit",3);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
    // glutDisplayFunc(display);
   display();
   glutMainLoop();
}
