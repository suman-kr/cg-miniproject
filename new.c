#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
int prime,generator,a=5,b=3;
long long int pa,pb,shared;
int flag = 0;
//void *font = GLUT_BITMAP_TIMES_ROMAN_10;
//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'a');
void output(int x, int y, char *string)      
{
int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}
void alice()
{
	pa = (((long long int)pow(generator,a)) % prime);
	printf("public key of alice:%lld\n",pa);
}
void bob()
{
	pb = (((long long int)pow(generator,b)) % prime);
	printf("public key of bob:%lld\n",pb);
}
void shared_secret()
{
	shared = (((long long int)pow(pb,a)) % prime);
	printf("shared secret:%lld\n",shared);
}
int isPrime(int n )
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
GLint movement_angle=0,packet_angle=0,head_angle=0,packet_angle1=0,head_angle1=0,packet_angle2=0,head_angle2=0,packet_angle3=0,head_angle3=0,packet_angle4=0;
GLdouble mov_speed = 1;
GLint head_angle4=0,packet_angle5=0,head_angle5=0,packet_angle6=0,head_angle6=0,packet_angle7,head_angle7=0,packet_angle8=40;

GLint movement_angle1=0,arrow_angle=0,rev_arrow_angle=0,phy_header_angle=0,rev_phy_header_angle=0,rev_phy_header_angle1=0,phy_header_angle1=0,analog_sig_angle=0,rev_analog_sig_angle = 0;


void animation_encrypt(void)
{
if ((movement_angle += mov_speed) >= 600)
movement_angle = 600;
if ((arrow_angle += mov_speed) >= 150)
arrow_angle = 150;
if(arrow_angle==150)
if ((phy_header_angle += mov_speed) >= 100)
phy_header_angle = 100;
if(phy_header_angle==100)
if ((phy_header_angle1 += mov_speed) >= 100)
phy_header_angle1 = 100;
if(phy_header_angle1==100)
if ((analog_sig_angle += mov_speed) >= 100)
analog_sig_angle = 100;
if(analog_sig_angle==100)
if ((movement_angle1 += mov_speed) >= 420)
movement_angle1 = 420;
if(movement_angle1 ==420)
if ((rev_analog_sig_angle += mov_speed) >= 100)
rev_analog_sig_angle = 100;
if(rev_analog_sig_angle ==100)
if ((rev_phy_header_angle += mov_speed) >= 200)
rev_phy_header_angle = 200;
if(rev_phy_header_angle ==200)
if ((rev_phy_header_angle1 += mov_speed) >= 100)
rev_phy_header_angle1 = 100;
if(rev_phy_header_angle ==200)
if ((rev_arrow_angle += mov_speed) >= 100)
rev_arrow_angle = 100;
glutPostRedisplay();
}

void computer()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(55.0,340.0);
glVertex2f(145.0,340.0);
glVertex2f(150.0,350.0);
glVertex2f(60.0,350.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(60.0,355.0);
glVertex2f(150.0,355.0);
glVertex2f(150.0,370.0);
glVertex2f(60.0,370.0);
glEnd();

glColor3f(0.75,0.85,0.65);
glBegin(GL_LINE_LOOP);
glVertex2f(75.0,380.0);
glVertex2f(135,380.0);
glVertex2f(135.0,430.0);
glVertex2f(75.0,430.0);
glEnd();

glColor3f(0.7,0.8,0.6);
glBegin(GL_QUADS);
glVertex2f(80.0,385.0);
glVertex2f(130.0,385.0);
glVertex2f(130.0,425.0);
glVertex2f(80.0,425.0);
glEnd();

   glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(90.0,370.0);
glVertex2f(90.0,380.0);
glVertex2f(120.0,370.0);
glVertex2f(120.0,380.0);
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
/*void cipher()
{
glColor3f(0.0f,0.0f,1.0f);
glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,14,0);
glutWireCube(2);
output(-1,0,"GENERATOR");
glPopMatrix();
}
void message_data()
{

glColor3f(1.0f,1.0f,0.0f);
glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,14,0);
glutWireCube(2);
output(-1,0,"KEY");
glPopMatrix();
}


void message_key(void)
{

glColor3f(0.0f,1.0f,0.0f);
glPushMatrix();
glScalef(20,20,.5);
glTranslatef(3,14,0);
glutWireCube(2);

output(-1,0,"PRIME");
glPopMatrix();
}

*/
void encryption()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
//glPushMatrix();
// glColor3f(0.25,0.15,0.36);
glColor3f(1.0f,1.0f,1.0f);
//glPopMatrix();

glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(-30,200,0);
output(75,440,"ALICE");
computer();
glPopMatrix();

glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
output(565,630,"BOB");
computer_dest();
glPopMatrix();

glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glScalef(70,40,.5);
glTranslatef(1.5,7,0);
glutWireCube(2);
glPopMatrix();

/*if(phy_header_angle1!=100)
{
glPushMatrix();
glTranslatef(0,-phy_header_angle1,0);
glPushMatrix();
glTranslatef(0,-arrow_angle,0);
glTranslatef(0,150,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(phy_header_angle,0,0);
glTranslatef(-100,0,0);
message_key();
glPopMatrix();
glPopMatrix();
}
glPushMatrix();
glTranslatef(movement_angle1,0,0);
if(phy_header_angle1==100)
{
glPushMatrix();
if(movement_angle1>=420)
{
// glRotatef(180,0,1,0);
glTranslatef(0,rev_analog_sig_angle,0);
}
glTranslatef(0,-analog_sig_angle,0);
if(rev_analog_sig_angle!=100)
cipher();
glPopMatrix();
}
glPopMatrix();
glPushMatrix();
glTranslatef(movement_angle1,0,0);
if(phy_header_angle1==100)
{
glPushMatrix();
glScalef(50,30,.5);
glTranslatef(2.5,2.5,0);
glutWireCube(2);
glPopMatrix();
}
glPopMatrix();
if(rev_analog_sig_angle==100)
{
glPushMatrix();
glTranslatef(450,rev_phy_header_angle1,0);
glPushMatrix();
//glTranslatef(0,rev_arrow_angle,0);
//glTranslatef(0,0,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(rev_phy_header_angle,0,0);
glTranslatef(-10,0,0);
if(rev_phy_header_angle<200)
message_key();
glPopMatrix();
glPopMatrix();
}*/
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(450,0,0);
glScalef(70,40,.5);
glTranslatef(1.5,7,0);
glutWireCube(2);//right layer
glPopMatrix();
animation_encrypt();
glFlush();
glutSwapBuffers();
}

void scan_menu(int id){
	if(id==1){
		alice();
		bob();
		
	}
	else if (id == 2){
		shared_secret();
	}

else{exit(0);}
	glutPostRedisplay();
}

void myinit()
{
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,700.0,0.0,700.0);
}

void display()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	output(350,550,"OpenGl");
	output(310,450,"MINI PROJECT ON");
	output(310,400,"DIFFIE HELLMAN");
	output(450,200,"By:");
	output(475,180,"SUMAN KUMAR");
	output(475,150,"SUBHASHIS GUPTA");
	glFlush();
	
	glutSwapBuffers();
}

void keyfunc (unsigned char key, int x, int y)
{
switch(key) {

	case 'S' :
	case 's' :glutDisplayFunc(encryption);
		break;
   	case 'q':  
   	case 'Q':
          exit(0);
 }
 glutPostRedisplay();
}

void main(int argc, char** argv)
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
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Diffie Hellman");
	glutKeyboardFunc(keyfunc);
	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(scan_menu);
	glutAddMenuEntry("exchange keys",1);
	glutAddMenuEntry("shared secret",2);
	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}

