#include "iGraphics.h"
#include <math.h>
#include <time.h>
void hour();void minute();void second(); void calltime();

double o,x=750,y=360+250,sx,sy,p;
double xm=750,ym=360+220,mx,my,pm;
double xh = 750, yh = 360 + 200, hx, hy, ph;
int H, M, S, H1, H2, M1, M2, S1, S2;
int i;
int am = 1;
double c;
int f= 1;
int blink = 1;
const int w1 = 10;//for vertical segs
const int w2 = 166.6667;//for horizontal segs
const int h1 = 170;//for vertical segs
const int h2 = 10;//for horizontal segs
const int h = 550;
const int cenx = 750;
const int ceny = 360;

int seg_arr[10][7] = { {1,1,1,1,1,1},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},
{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1} };

void sa(double l, int a)
{
	iFilledRectangle(l*a, (h - h2) * a, w2*a, h2 * a);
}

void sb(double l, int b)
{
	iFilledRectangle(l*b, (h-h2-h1) * b, w1*b, h1 * b);
}

void sc(double l, int c)
{
	iFilledRectangle(l*c, (h-h1-h2-h1-h2) * c, w1 * c, h1 * c);
}

void sd(double l, int d)
{
	iFilledRectangle(l*d, (h-h1-h1-h2-h2-h2) * d, w2*d, h2 * d);
}

void se(double l, int e)
{
	iFilledRectangle(l*e, (h - h1 - h1 - h2 - h2) * e, w1 * e, h1 * e);
}

void sf(double l, int f)
{
	iFilledRectangle(l*f, (h-h1-h2) * f, w1 * f, h1 * f);
}

void sg(double l, int g)
{
	iFilledRectangle(l*g, (h-h2-h2-h1) * g, w2*g, h2 * g);
}

void blink_cir()
{
	blink = blink ^ 1;
}


void seg_display(double l, int H)
{
	sa(l + w1, seg_arr[H][0]);
	sb(l + w1+w2, seg_arr[H][1]);
	sc(l + w1+w2, seg_arr[H][2]);
	sd(l+w1,seg_arr[H][3]);
	se(l,seg_arr[H][4]);
	sf(l,seg_arr[H][5]);
	sg(l+w1,seg_arr[H][6]);

}


void analog()
{
iClear();
ph = (3 - H)*30.0 - 30 * M / 60.0 - 30 * S / 3600.0 + .1 / 600 + 270 + 90;

		pm = (15 - M)*6.0 - S / 60.0 + .1 + 270 + 90;

		p = (15 - S)*6.0 + 6 + 270 + 90;
		hour();
		minute();
		second();
iSetColor(255,255,255);
iFilledRectangle(0, 0, 1500, 700);
iSetColor(255, 255, 204);
iFilledCircle(cenx, ceny, 310);//Large
iSetColor(0, 0, 0);
for (c = 310; c <= 316; c += .01)
{
	iCircle(cenx, ceny, c);//out
}
iSetColor(0, 0, 0);
for (c = 275; c <= 279; c += .01)
{
	iCircle(cenx, ceny, c);
}
iSetColor(0, 0, 0);
for (i = 1, o = (6 / 57.29); i <= 60; i++, o += (6 / 57.29))
{
if (i % 5 != 0)
iFilledCircle(cenx + 295 * cos(o), ceny + 295 * sin(o), 5);
}


iSetColor(255, 0, 0);
iLine(cenx, ceny, x, y);///second
iSetColor(0, 0, 0);
iLine(cenx, ceny, xm, ym);///minit
iSetColor(0, 0, 0);
iLine(cenx, ceny, xh, yh);//HR
iSetColor(0, 0, 0);
iText(cenx + 250, ceny - 150, "IV");
iText(cenx + 145, ceny - 256, "V");
iText(745, 64, "VI");
iText(750 - 155, 360 - 257, "VII");
iText(446, 360, "IX");
iText(500+250 - 260, 360 + 145, "X");
iText(500+250 + 248, 360 + 150, "II");
iText(500+250 + 140, 360 + 252, "I");
iText(490+250, 648, "XII");
iText(782+250, 360, "III");
iText(500+250 - 150, 360 + 250, "XI");
iText(500+250 - 270, 360 - 150, "VIII");
iSetColor(0, 0, 0);
iFilledCircle(500+250, 360, 15);//small
iCircle(500+250, 360, 150);//inside
iCircle(500+250, 360, 150.5);//inside
iCircle(500+250, 360, 151);//inside

}


void dotdisplay1()
{
	iFilledCircle(518.335, 250, 10);
	iFilledCircle(518.335, 450, 10);
}

void dotdisplay2()
{
	iFilledCircle(981.68, 250, 10);
	iFilledCircle(981.68, 450, 10);
}
void hourdisplay1()//for seven seg display
{
	seg_display(75, H1);
}

void hourdisplay2()//for 7 seg display
{
	seg_display(301.6667, H2);
}

void mindisplay1()
{
	seg_display(538.3333, M1);
}

void mindisplay2()
{
	seg_display(765.01, M2);
}

void secdisplay1()
{
	seg_display(1001.68, S1);
}

void secdisplay2()
{
	seg_display(1228.35, S2);
}
void digital()
{

iClear();
if(am == 1)
		{
			H = (H + 11) % 12 + 1;

		}
		H2 = H % 10;
		H1 = H / 10;
		M2 = M % 10;
		M1 = M / 10;
		S2 = (S - 2) % 10;
		S1 = (S - 2) / 10;
iSetColor(0, 0, 35);
iFilledRectangle(0, 0, 1500, 700);
iSetColor(50, 255, 50);
hourdisplay1();
hourdisplay2();
mindisplay1();
mindisplay2();
if (blink == 1)
{
	dotdisplay1();
	dotdisplay2();
}

secdisplay1();
secdisplay2();

}

void iDraw()
{

if (f == 0)
{
analog();
iSetColor(0, 0, 0);


}
else if (f == 1)
{
digital();
iSetColor(50, 255, 50);
iText(10, 635, "---> s or S = For Standard Time Display");
iText(10, 620, "---> h or H = For Hour Time Display");
}
iText(10, 680, "Shortcuts");
iText(10, 665, "---> a or A = Switch to Analog Display");
iText(10, 650, "---> d or D = Switch to Digital Display");



}


void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{

}
if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{

}
}


void iKeyboard(unsigned char key)
{
if(key == 'a' || key == 'A')
{
f = 0;
}
else if (key == 'd' || key == 'D')
{
f = 1;
}
else if (key == 'h' || key == 'H')
{
	am = 0;
}
else if (key == 's' || key == 'S')
{
	am = 1;
}
else if(key == 'p' || key == 'P')
{
	iPauseTimer(0);
	iPauseTimer(1);
}
else if(key == 'r' || key == 'R')
{
	iResumeTimer(0);
	iResumeTimer(1);

}

}


void iSpecialKeyboard(unsigned char key)
{

if(key == GLUT_KEY_END)
{
exit(0);
}
}

void second()

{
sx = 250 * cos(p / 57.29);
sy=250*sin(p/57.29);
x=750+sx;
y=360+sy;
//p=p-6;
}
void minute()
{
mx=220*cos(pm/57.29);
my=220*sin(pm/57.29);
xm=750+mx;
ym=360+my;
//pm=pm-.1;
}
void hour()
{
hx=200*cos(ph/57.29);
hy=200*sin(ph/57.29);
xh=750+hx;
yh=360+hy;
//ph=ph-1/600;
}

	


void calltime()
{
	time_t rawtime;
	tm * ptm;

	time(&rawtime);

	ptm = gmtime(&rawtime);   //getting time from bios
	H = (ptm->tm_hour + 6) % 24;
	M = ptm->tm_min;
	S = (ptm->tm_sec)+2;

	
		

	
		
}


int main()
{
calltime();
iSetTimer(1000, calltime);
iSetTimer(500, blink_cir);
iInitialize(1500, 700, "Watch");
return 0;
}	