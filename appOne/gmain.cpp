#include"libOne.h"
class FLOAT2 {
public:
	float x = 0, y = 0;
	FLOAT2(){
	}
	FLOAT2(float x, float y) {
		this->x = x;
		this->y = y;
	}
	FLOAT2 operator+(FLOAT2& f2) {
		return FLOAT2(x + f2.x, y + f2.y);
	}
	FLOAT2 operator-(FLOAT2& f2) {
		return FLOAT2(x - f2.x, y - f2.y);
	}
	FLOAT2 operator*(float f) {
		return FLOAT2(x * f, y * f);
	}
	void operator+=(FLOAT2& f2) {
		x += f2.x;
		y += f2.y;
	}
	void normalize() {
		float mag = sqrt(x * x + y * y);
		x /= mag;
		y /= mag;
	}
};
void gmain() {
	window(1000, 1000, full);
	
	FLOAT2 pos(100, 10);
	FLOAT2 vec(200,20);
	pos += vec;

	printSize(200);
	print(pos.x);
	print(pos.y);
	while (notQuit) {

	}
}

/*
//TAKO.hとTAKO.cppを使う
#include"libOne.h"
#include"TAKO.h"
void gmain() {
	window(1920, 1080, full);
	int takoImg = loadImage("assets\\enemy.png");
	int num = 30;
	TAKO* takos = new TAKO[num];
	for (int i = 0; i < num; i++) {
		takos[i].setImage(takoImg);
		takos[i].init();
	}
	while (notQuit) {
		for (int i = 0; i < num; i++) {
			takos[i].move();
			takos[i].draw();
		}
	}
	delete[] takos;
}
*/

/*
#include"libOne.h"
class ENEMY {
protected:
	int Img = 0;
	float px, py, vx;
public:
	void setImage(int img) {
		Img = img;
	}
	void init() {
		px = random() % (int)width;
		py = random() % (int)height;
		vx = random() % 5 + 1.0f;
	}
	void move() {
		px += vx;
	}
	void draw() {
		image(Img, px, py);
	}
};
void gmain() {
	window(1920, 1080);
	int enemyImg = loadImage("assets\\enemy.png");
	int num = 5;
	ENEMY* enemy = new ENEMY[num];
	for (int i = 0; i < num; i++) {
		enemy[i].init();
		enemy[i].setImage(enemyImg);
	}
	while (notQuit) {
		clear();
		for (int i = 0; i < num; i++) {
			enemy[i].move();
			enemy[i].draw();
		}
	}
}
*/


/*
#include"libOne.h"

struct CHARACTER {
protected:
	int Img = 0;
	float Px = 0, Py = 0, Angle = 0;
	float Vx = 0, Vy = 0, AngSpeed = 0;
public:
	void setImage(int img) {
		Img = img;
	}
	void init() {
		Px = width / 2;
		Py = height / 2;
		Angle = 0;
		Vx = 1;
		Vy = 1;
		AngSpeed = 0.01f;
	}
	virtual void move() {
		Angle += AngSpeed;
	}
	void draw() {
		rectMode(CENTER);
		image(Img, Px, Py, Angle);
	}
};
class PLAYER : public CHARACTER {
public:
	void move() {
		Px += Vx;
	}
};
class ENEMY : public CHARACTER {
public:
	void move() {
		Py += Vx;
	}
};
class ENEMY_BULLET : public CHARACTER{};
void gmain() {
	window(1920, 1080, full);
	int playerImg = loadImage("assets\\player.png");
	int enemyImg = loadImage("assets\\enemy.png");
	int eBulletImg = loadImage("assets\\eBullet.png");

	PLAYER player;
	ENEMY enemy;
	ENEMY_BULLET eBullet;
	player.setImage(playerImg);
	enemy.setImage(enemyImg);
	eBullet.setImage(eBulletImg);

	const int num = 3;
	CHARACTER* chara[num];
	chara[0] = &enemy;
	chara[1] = &player;
	chara[2] = &eBullet;
	for (int i = 0; i < num; i++) {
		chara[i]->init();
	}
	while (notQuit) {
		for (int i = 0; i < num; i++) {
			chara[i]->move();
		}
		clear();
		for (int i = 0; i < num; i++) {
			chara[i]->draw();
		}
	}
}
*/




/*
#include"libOne.h"
struct A {
protected:
	int Img = 0;
	float px = 0, py = 0, Angle = 0, vx = 0, vy = 0, AngSpeed = 0;
public:
	void setImage(int img) {
		Img = img;
	}
	void init() {
		px = width / 2;
		py = height / 2;
		vx = 10;
		vy = 10;
		AngSpeed = 0.01f;
	}
	virtual void move(){
		Angle += AngSpeed;
	}
	void draw() {
		rectMode(CENTER);
		image(Img, px, py, Angle);
	}
};
class PLAYER :public A {
public:
	void move() {
		px += vx;
	}
};
void gmain() {
	window(960, 1080);
	int playerImg = loadImage("assets\\player.png");

	PLAYER player;
	A* a = &player;

	A a;
	a->init();
	a->setImage(playerImg);
	while (notQuit) {
		a->move();
		clear();
		a->draw();
	}
}
*/
/*
#include"libOne.h"
void gmain() {
	window(910, 1080);
	struct PLAYER {
		float px, py, w, h, vx, ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy;
		int hp = 0;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 200;
	p.w = 100;
	p.h = 200;
	p.vx = 10;
	p.ofsY = -150;
	const int numBLLET = 10;
	struct BULLET b[numBLLET];
	for (int i = 0; i < numBLLET; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 10;
		b[i].h = 20;
		b[i].vy = -10;
	}
	while (notQuit) {
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isPress(KEY_A)) { p.px -= p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0; i < numBLLET; i++) {
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
					i = numBLLET;
				}
			}
		}
		for (int i = 0; i < numBLLET; i++) {
			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		clear();
		rectMode(CENTER);
		rect(p.px, p.py, p.w, p.h);
		for (int i = 0; i < numBLLET; i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);
			}
		}

	}
}
*/







/*
#include"libOne.h"
#include<stdio.h>
void gmain(){
	window(1920, 1080, full);
	struct PLAYER {
		float px, py, w, h, vx, ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy;
		int hp = 0;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 150;
	p.w = 100;
	p.h = 200;
	p.vx = 10;
	p.ofsY = -100;
	const int numBullets = 10;
	struct BULLET b[numBullets];
	for (int i = 0; i < numBullets; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 20;
		b[i].h = 40;
		b[i].vy = -10;
	}
	while (notQuit) {
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0; i < numBullets; i++) {
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
				}
			}
		}
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		clear();
		rectMode(CENTER);
		rect(p.px, p.py, p.w, p.h);
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);
			}
		}
	}
}
*/




/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	int backImg = loadImage("assets\\green.png");
	int mobImg = loadImage("assets\\enemy.png");
	int playerImg = loadImage("assets\\player.png");
	float px = 860;
	float py = 1080 - 300;
	float vx = 5;
	float vy;
	float initVy = -50;
	float jampG = 3;
	int jampFlag = 0;
	while (notQuit) {
		clear();
		image(backImg, 0, 0);
		image(playerImg, px, py);
		if (isPress(KEY_D)) {
			px += vx;
		}
		if (isPress(KEY_A)) {
			px -= vx;
		}
		if (jampFlag == 0) {
			if (isTrigger(KEY_SPACE)) {
				vy = initVy;
				jampFlag = 1;
			}
		}
		if (jampFlag == 1) {
			py += vy;
			vy += jampG;
			if (py>780) {
				jampFlag = 0;
			}
		}
	}
}
*/




/*
#include <stdio.h>
#include <process.h>

void setZeroInt(int* p) {
	*p = 0;
}

int main() {
	int a;
	a = 7;

	setZeroInt(&a);

	printf("%d\n", a);

	system("pause>0");
	return 0;
}


















#define _2
#ifdef _
#include<stdio.h>
#include<process.h>
#include"str.h"
int main() {
	char a[8];
	setString(a, "ABC");
	printf("%s", a);
	system("pause>0");
	return 0;
}
#endif

#ifdef _
#include<stdio.h>
#include<conio.h>
void finish() {
	_getch();
}
void nextLine() {
	printf("\n");
}
void dispInt(int a) {
	printf("%d", a);
}
void dispFloat(float a) {
	printf("%f", a);
}
int add(int a, int b) {
	return a + b;
}
float div(float a, float b) {
	return a / b;
}
int main() {
	dispInt(add(7, 5));
	nextLine();
	dispFloat(div(7, 5));
	finish();
	return 0;
}
#endif
#ifdef _VEC
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	float rx = 5;
	float bx = 7;
	while (notQuit) {
		float vx = rx - bx;
		float mag = vx < 0 ? -vx : vx;
		float nvx = vx / mag;
		bx += nvx * 0.01f;
		clear(200);
		mathAxis(9.1f);
		strokeWeight(10);
		stroke(0);
		mathArrow(0, 0, vx, 0);
		stroke(255, 0, 0);
		mathArrow(0, 0, nvx, 0);

		strokeWeight(20);
		stroke(255, 0, 0);
		mathPoint(rx, 0);
		stroke(0, 0, 255);
		mathPoint(bx, 0);

		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}

#endif
#ifdef _
#include"libOne.h"
#include"VEC.h"

struct BEETLE {
	struct VEC pos;
	float advSpeed = 0;
	float angle = 0;
	float angSpeed = 0;
};

void gmain() {
	window(1920, 1080, full);
	int osuImg = loadImage("assets\\osu.png");
	struct BEETLE osu;
	osu.pos.x = width / 2;
	osu.pos.y = height / 2;
	osu.advSpeed = 10;
	while (notQuit) {
		clear();
		image(osuImg, osu.pos.x, osu.pos.y, osu.angle);
	}
}
#endif
#ifdef _
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	int img = loadImage("assets\\pBullet.png");
	int haikei = loadImage("assets\\green.png");
	int player = loadImage("assets\\player.png");
	struct V {
		int hp = 0;
		float px = 0, py = 0, vx = 0, vy = 0, deg = 0;
	};
	const int num = 256;
	struct V u[num];
	float deg = 0;
	float deg2 = 0;
	angleMode(DEGREES);
	rectMode(CENTER);
	while (notQuit) {
		if (isPress(MOUSE_LBUTTON)) {
			for (int i = 0; i < num; i++) {
				if (u[i].hp == 0) {
					u[i].hp = 1;
					u[i].px = mouseX + sin(deg) * 20;
					u[i].py = mouseY;
					u[i].vx = 0;
					u[i].vy = -10;
					deg += 6;
					i = num;
				}
			}
		}
		if (isPress(MOUSE_RBUTTON)) {
			for (int i = 0; i < num; i++) {
				if (u[i].hp == 0) {
					u[i].hp = 1;
					u[i].px = mouseX;
					u[i].py = mouseY;
					u[i].vx = sin(deg2) * 5;
					u[i].vy = -cos(deg2) * 5;
					deg2 += 25;
					i = num;
				}
			}
		}
		for (int i = 0; i < num; i++) {
			if (u[i].hp == 1) {
				u[i].px += u[i].vx;
				u[i].py += u[i].vy;
				if (u[i].py > height + 50 || u[i].py < -50 ||
					u[i].px<-50 || u[i].px>width + 50) {
					u[i].hp = 0;
				}
			}
		}
		clear();
		image(haikei, width / 2, height / 2);
		for (int i = 0; i < num; i++) {
			if (u[i].hp == 1) {
				image(img, u[i].px, u[i].py, u[i].deg);
			}
		}
		image(player, mouseX, mouseY);
	}
}
#endif
#ifdef _2
#include"libOne.h"
class CHARACTER {
protected:
	int Img = 0;
	float Px = 0, Py = 0, Angle = 0;
	float Vx = 0, Vy = 0, AngSpeed = 0;
public:
	void setImage(int img) {
		Img = img;
	}
	void init() {
		Px = width / 2;
		Py = height / 2;
		Angle = 0;
		Vx = 1;
		Vy = 1;
		AngSpeed = 0.01f;
	}
	virtual void move() {
		Angle += AngSpeed;
	}
	void draw() {
		rectMode(CENTER);
		image(Img, Px, Py, Angle);
	}
};

class PLAYER : public CHARACTER {
public:
	void move() {
		Px += Vx;
	}
};

void gmain() {
	window(1920, 1080, full);
	int playerImg = loadImage("assets\\player.png");

	PLAYER player;
	CHARACTER* chara = &player;

	chara->setImage(playerImg);
	chara->init();
	while (notQuit) {
		chara->move();
		clear();
		chara->draw();
	}
}
#endif
#ifdef _BECTRU
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	angleMode(DEGREES);
	float x, y, angle;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(5.1f, 255);

		x = mathMouseX;
		y = mathMouseY;
		angle = atan2(y, x);

		strokeWeight(10);
		stroke(128);
		mathArrow(0, 0, x, y);
		stroke(255, 255, 200);
		mathArc(0, angle, 0.5f);

		textSize(50);
		fill(160);
		text((let)"x=" + x, 0, 50);
		text((let)"y=" + y, 0, 100);
		fill(255, 255, 200);
		text((let)"atan2(y,x)=" + angle, 0, 150);

		float r = sqrt(x * x + y * y);
		fill(255, 200, 200);
		text((let)"asin(y/r)=" + asin(y / r), 0, 200);
		text((let)"acos(x/y)=" + acos(x / r), 0, 250);
		text((let)"atan(y/x)=" + atan(y / x), 0, 300);
	}
}
#endif
#ifdef _
#include<stdio.h>
#include"libOne.h"
void ster(int tip) {
	if (tip == 1) {
		printf("☆");
	}
	else if (tip == 2) {
		printf("★");
	}
	else {
		printf("?");
	}
}
void sters(int num) {
	for (int i = 0; i < num; i++) {
		ster(2);
	}
}
int main() {
	sters(5);
	system("pause>0");
	return 0;
}
#endif
#ifdef _
#include"libOne.h"
struct V {
	int x;
	int y;
};
void setZero(V* p) {
	for (int i = 0; i < 3; i++) {
		p[i].x = 0;
		p[i].y = 0;
	}
}
int main(){
	V a[3];
	for (int i = 0; i < 3; i++) {
		a[i].x = i;
		a[i].y = i;
	}
	setZero(a);
	for (int i = 0; i < 3; i++) {
		printf("%d %d", a[i].x, a[i].y);
	}
	system("pause > 0");
	return 0;
}
#endif
#ifdef _
#include<stdio.h>
struct V {
	int x;
	int y;
};
void setZero(struct V*p) {
	for (int i = 0; i < 3; i++) {
		p[i].x = 0;
		p[i].y = 0;
	}
}
int main() {
	struct V a[3];
	for (int i = 0; i < 3; i++) {
		a[i].x = i + 1;
		a[i].y = i + 1;
	}
	setZero(a);
	for (int i = 0; i < 3; i++) {
		printf("%d %d\n", a[i].x,a[i].y);
	}
	system("pause>0");
	return 0;
}
#endif

#ifdef _
#include<stdio.h>
#include"libOne.h"
void A(int* p) {
	for (int i = 0; i < 3; i++) {
		p[i] = 0;
	}
}
int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		a[i] = i + 1;
	}
	A(a);
	for (int i = 0; i < 4; i++) {
		printf("%2d", a[i]);
	}
	system("pause>0");
	return 0;
}
#endif

#ifdef _BECTRU
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	angleMode(DEGREES);
	float x, y, angle;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(5.1f, 255);

		x = mathMouseX;
		y = mathMouseY;
		angle = atan2(y, x);

		strokeWeight(10);
		stroke(128);
		mathArrow(0, 0, x, y);
		stroke(255, 255, 200);
		mathArc(0, angle, 0.5f);

		textSize(50);
		fill(160);
		text((let)"x=" + x, 0, 50);
		text((let)"y=" + y, 0, 100);
		fill(255, 255, 200);
		text((let)"angle(y,x)=" + angle, 0, 150);

		float r = sqrt(x * x + y * y);
		fill(255, 200, 200);
		text((let)"asin(y/r)=" + asin(y / r), 0, 200);
		text((let)"scos(x/r)=" + acos(x / r), 0, 250);
		text((let)"atan(y/x)=" + atan(y / x), 0, 300);
	}
}
#endif

#ifdef _BECTRU
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	float x, y, r;
	float s, c, t;
	float tx, ty;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(3.1f, 255);
		x = mathMouseX;
		y = mathMouseY;
		r = sqrt(x * x + y * y);
		c = x / r;
		s = y / r;
		t = y / x;

		tx = s  * t;
		ty = -c * t;
		//元のベクトルを描画
		strokeWeight(4);
		stroke(128);
		mathArrow(0, 0, x, y);
		//単位円を描画
		fill(0, 0, 0, 0);
		mathCircle(0, 0, 2);
		//正規化ベクトルを描画
		strokeWeight(10);
		stroke(200);
		mathArrow(0, 0, c, s);
		//cosθを描画
		stroke(160, 200, 255);
		mathLine(0, 0, c, 0);
		//sinθを描画
		stroke(255, 160, 200);
		mathLine(c, 0, c, s);

		stroke(255, 255, 255);
		mathLine(c, s, c+tx, s+ty);
	}
}
#endif

#ifdef _KOTATUNEKO
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	int kotatuImg = loadImage("assets\\kotatu0.png");
	int kotatuColorImg = loadImage("assets\\kotatu1.png");
	int mikanImg = loadImage("assets\\mikan.png");

	int kimg = kotatuImg;
	float kpx = width / 2;
	float kpy = height / 2;

	struct MIKAN {
		float px;
		float py;
		float tx;
		float ty;
	};
	const int totalNum = 10;
	struct MIKAN m[totalNum];
	int curNum = 0;
	//-172,-40
	for (int i = 0; i < totalNum; i++) {
		m[i].tx = kpx - 172;
		m[i].ty = kpy - 40 - 50 * i;
	}
	float speed = 20;

	while (notQuit) {

		if (isTrigger(MOUSE_LBUTTON)) {
			if (curNum < totalNum) {
				m[curNum].px = mouseX;
				m[curNum].py = mouseY;
				curNum++;
			}
		}
		if (isTrigger(MOUSE_RBUTTON)) {
			curNum = 0;
			m[totalNum - 1].px = -100;
		}
		for (int i = 0; i < curNum; i++) {
			float vx = m[i].tx - m[i].px;
			float vy = m[i].ty - m[i].py;
			float mag = sqrt(vx * vx + vy * vy);
			if (mag > speed) {
				m[i].px += vx / mag * speed;
				m[i].py += vy / mag * speed;
			}
			else {
				m[i].px = m[i].tx;
				m[i].py = m[i].ty;
			}
		}
		int last = totalNum - 1;
		if (m[last].px == m[last].tx) {
			kimg = kotatuColorImg;
		}
		else {
			kimg = kotatuImg;
		}

		clear(220);
		rectMode(CENTER);
		image(kimg, kpx, kpy);
		for (int i = 0; i < curNum; i++) {
			image(mikanImg, m[i].px, m[i].py);
		}
	}
}
#endif

#ifdef _BECTRU
#include"libOne.h"
void gmain() {
	window(1000,1000);
	float rx = 5, ry = 5;
	float bx = 7, by = 7;
	while (notQuit) {
		bx = mathMouseX;
		by = mathMouseY;
		float vx = bx - rx;
		float vy = by - ry;
		float mag = sqrt(vx * vx + vy * vy);
		float nvx = vx / mag;
		float nvy = vy / mag;
		rx += nvx * 0.01f;
		ry += nvy * 0.01f;
		clear(200);
		mathAxis(9.1f);
		strokeWeight(5);
		stroke(0);
		mathArrow(0, 0, vx, vy);
		mathLine(0, 0, vx, 0);
		mathLine(vx, 0, vx, vy);
		stroke(255, 0, 0);
		mathArrow(0, 0, nvx, nvy);
		mathLine(0, 0, nvx, 0);
		mathLine(nvx, 0, nvx, nvy);

		strokeWeight(20);
		stroke(255, 0, 0);
		mathPoint(rx, ry);
		stroke(0, 0, 255);
		mathPoint(bx, by);

		textSize(50);
		text((let)"vec(" + vx + "," + vy + ")", 0, 50);
		text((let)"mag:" + mag , 0, 100);
		text((let)"nvec(" + nvx + "," + nvy + ")", 0, 150);
		mag = sqrt(nvx * nvx + nvy * nvy);
		text((let)"mag:" + mag, 0, 200);
	}
}
#endif

#ifdef _BECTRU
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	float rx = 5;
	float bx = 9;
	while (notQuit) {
		float vx = rx - bx;
		float mag = vx < 0 ? -vx : vx;
		float nvx = vx / mag;
		//if (vx < 0) { mag = -vx; }
		//else { mag = vx; }
		bx += nvx * 0.01f;
		clear(200);
		mathAxis(9.1f);
		strokeWeight(10);
		stroke(0);
		mathArrow(0, 0, vx, 0);
		stroke(255, 0, 0);
		mathArrow(0, 0, nvx, 0);

		strokeWeight(20);
		stroke(255, 0, 0);
		mathPoint(rx, 0);
		stroke(0, 0, 255);
		mathPoint(bx, 0);

		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}
#endif

#ifdef _TETRIS
#include"libOne.h"
const int INIT = 0;
const int PLAY = 1;
const int OVER = 2;
int GameState = INIT;
float Size = 30;
const int ROWS = 20;
const int COLS = 12;
float Satu = 200;
float Value = 255;
float Alpha = 255;
int FallFlag = 0;
struct COLOR Color[9]{
	COLOR(0,Satu,Value,Alpha),
	COLOR(30,Satu,Value,Alpha),
	COLOR(60,Satu,Value,Alpha),
	COLOR(120,Satu,Value,Alpha),
	COLOR(180,Satu,Value,Alpha),
	COLOR(240,Satu,Value,Alpha),
	COLOR(300,Satu,Value,Alpha),
	COLOR(200,44,88,Alpha),
	COLOR(0,0,20,Alpha),
};
const int WALL = 7;
const int BACK = 8;
int Stage[ROWS][COLS];
int X, Y, R;
int Px[4], Py[4];
int PtnNo = 0;
int Ptn[7][3][2] = {
	//■□■■...0
	-1,0,   1,0,  2,0,
	//■
	//■□■....1
	-1,-1, -1,0,  1,0,
	//  　■
	//■□■....2
	-1,0,   1,-1, 1,0,
	//■□
	//　■■....3
	-1,0,   0,1,  1,1,
	//　□■
	//■■  ....4
	 1,0,   0,1, -1,1,
	 //　■
	 //■□■....5
	 -1,0,   0,-1, 1,0,
	 //□■
	 //■■......6
	  1,0,   0,1,  1,1,
};
int LoopCnt = 0;

void init() {
	for (int y = 0; y < ROWS; y++) {
		Stage[y][0] = WALL;
		Stage[y][COLS - 1] = WALL;
		for (int x = 1; x < COLS - 1; x++) {
			Stage[y][x] = BACK;
			if (y == ROWS - 1) {
				Stage[y][x] = WALL;
			}
		}
	}
	X = 5;
	Y = 1;
	R = 0;
	PtnNo = random() % 7;
	GameState = PLAY;
}
void drawStage() {
	colorMode(HSV);
	angleMode(DEGREES);
	for (int y = 0; y < ROWS; y++) {
		for (int x = 0; x < COLS; x++) {
			int no = Stage[y][x];
			fill(Color[no]);
			rect(Size * x, Size * y, Size, Size);
		}
	}
}
void setPosition() {
	Px[0] = X;
	Py[0] = Y;
	int r = R % 4;
	for (int i = 0; i < 3; i++) {
		int x = Ptn[PtnNo][i][0];
		int y = Ptn[PtnNo][i][1];
		for (int j = 0; j < r; j++) {
			int w = x;
			x = y;
			y = -w;
		}
		Px[i + 1] = X + x;
		Py[i + 1] = Y + y;
	}
}
void setPtn() {
	setPosition();
	for (int i = 0; i < 4; i++) {
		int x = Px[i];
		int y = Py[i];
		Stage[y][x] = PtnNo;
	}
}
void delPtn() {
	setPosition();
	for (int i = 0; i < 4; i++) {
		int x = Px[i];
		int y = Py[i];
		Stage[y][x] = BACK;
	}
}
int collision() {
	setPosition();
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int x = Px[i];
		int y = Py[i];
		if (Stage[y][x] != BACK) {
			flag = 1;
		}
	}
	return flag;
}
void complete() {
	for (int y = 1; y < ROWS - 1; y++) {
		int flag = 1;
		for (int x = 1; x < COLS - 1; x++) {
			if (Stage[y][x] == BACK) {
				flag = 0;
			}
		}
		if (flag) {
			for (int upy = y - 1; upy > 0; upy--) {
				for (int x = 1; x < COLS - 1; x++) {
					Stage[upy + 1][x] = Stage[upy][x];
				}
			}
		}
	}
}
void play() {
	//Stage[Y][X] = BACK;
	delPtn();
	int dy = 0, dx = 0, dr = 0;
	if ((++LoopCnt %= 30) == 0)dy = 1;
	if (isTrigger(KEY_D))dx = 1;
	if (isTrigger(KEY_A))dx = -1;
	if (isTrigger(KEY_W))dr = 1;
	if (isTrigger(KEY_S))FallFlag = 1;
	if (FallFlag)dy = 1;
	Y += dy;
	X += dx;
	R += dr;
	//if (Stage[Y][X] != BACK) {
	if (collision()) {
		Y -= dy;
		X -= dx;
		R -= dr;
		FallFlag = 0;
		if (dy == 1 && dx == 0 && dr == 0) {
			//Stage[Y][X] = PtnNo;
			setPtn();
			complete();
			//新しいブロック
			Y = 1;
			X = 5;
			R = 0;
			PtnNo = random() % 7;
			if (collision()) {
				GameState = OVER;
			}
		}
	}

	//Stage[Y][X] = PtnNo;
	setPtn();

	clear(0);
	drawStage();
}
void over() {
	clear(0);
	drawStage();
	textSize(Size);
	fill(0, 0, 255);
	text("GAME OVER", Size * 2, Size);
	if (isTrigger(KEY_SPACE)) {
		GameState = INIT;
	}
}
void gmain() {
	window(Size * COLS, Size * ROWS);
	while (notQuit) {
		if (GameState == INIT)init();
		else if (GameState == PLAY)play();
		else if (GameState == OVER)over();
	}
}
#endif
*/

/*
#include"libOne.h"
//流星群
void gmain() {
	window(1920, 1080, full);
	struct POS {
		float x, y, z;
	};
	const int num = 1000;
	struct POS p[num];
	for (int i = 0; i < num; i++) {
		p[i].x = random(-1.0f, 1.0f);
		p[i].y = random(-0.5f, 0.5f);
		p[i].z = random(0.0f, 1.0f);
	}
	while (notQuit) {
		for (int i = 0; i < num; i++) {
			p[i].z -= 0.003f;
			if (p[i].z <= 0.0f) {
				p[i].z = 1.0f;
			}
		}
		fill(0, 0, 0, 60);
		strokeWeight(0);
		rect(0, 0, width, height);
		mathAxis(1.0f);
		stroke(200, 255, 255);
		for (int i = 0; i < num; i++) {
			float size = (1.0f - p[i].z) * 20.0f;
			strokeWeight(size);
			mathPoint(p[i].x / p[i].z, p[i].y / p[i].z);
		}
	}
}
*/

/*
//球体
#include"libOne.h"
struct POS {
	float x, y, z;
};
void gmain() {
	window(1000, 1000);
	int numCorners = 30;
	int numRings = numCorners / 2 + 1;
	int numVertices = numCorners * numRings;
	float deg = 360.0f / numCorners;
	angleMode(DEGREES);
	struct POS* op = new POS[numVertices];
	for (int j = 0; j < numRings; j++) {
		float r = sin(deg * j);
		float z = cos(deg * j);
		for (int i = 0; i < numCorners; i++) {
			int k = j * numCorners + i;
			op[k].x = sin(deg * i) * r;
			op[k].y = cos(deg * i) * r;
			op[k].z = z;//1.0f - 2.0f / (numRings - 1) * j;
		}
	}
	struct POS* p = new POS[numVertices];
	deg = 0;
	int state = 0;
	while (notQuit) {
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < numVertices; i++) {
			if (state == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 5;

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(0);
		mathAxis(0.5);
		stroke(160, 200, 255);
		for (int i = 0; i < numVertices; i++) {
			strokeWeight(6);
			mathPoint(p[i].x, p[i].y);
			int j = i + 1;
			if (j % numCorners == 0)j -= numCorners;
			strokeWeight(2);
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			if (i < numVertices - numCorners) {
				j = i + numCorners;
				mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			}
		}
	}
	delete[]op;
	delete[]p;
}
*/

/*
#include"libOne.h"
//正方形
struct POS {
	float x, y, z;
};
void gmain() {
	window(1000, 1000);
	const int num = 8;
	struct POS op[num] = {
		-1,1,-1,
		-1,-1,-1,
		1,-1,-1,
		1,1,-1,
		-1,1,1,
		-1,-1,1,
		1,-1,1,
		1,1,1,
	};
	struct POS p[num];
	float deg = 0;
	angleMode(DEGREES);
	int state = 0;
	while (notQuit) {
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < num; i++) {
			if (state == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 5;

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(128);
		mathAxis(0.5);
		stroke(160, 200, 255);
		strokeWeight(10);
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			mathLine(p[i + 4].x, p[i + 4].y, p[j + 4].x, p[j + 4].y);
			mathLine(p[i].x, p[i].y, p[i + 4].x, p[i + 4].y);
		}
	}
}
*/
/*
#include"libOne.h"
//ハート形
int createHeart() {
	const int NUM = 60;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float t = deg * i;
		vertices[i].x = pow(sin(t), 3);
		vertices[i].y = -(
			13 * cos(t) -
			5 * cos(2 * t) -
			2 * cos(3 * t) -
			1 * cos(4 * t) ) / 16;
	}
	return createShape(vertices, NUM);
}
void gmain() {
	window(1000, 1000);
	int idx = createHeart();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		//deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 200, 200);
		shape(idx, 500, 500, deg, 20);
	}
}
*/
/*
//星形
#include"libOne.h"
int createStar() {
	const int NUM = 10;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float radius = 0.5f + 0.5f * (i%2);
		vertices[i].x = sin(deg * i) * radius;
		vertices[i].y = cos(deg * i) * radius;
	}
	return createShape(vertices, NUM);
}
void gmain() {
	window(1000, 1000);
	int idx = createStar();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 255, 0);
		shape(idx, 500, 500, deg, 200);
	}
}
*/
/*
//正多角形
#include"libOne.h"
int createTriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3);
}
int createPolygon() {
	const int NUM = 60;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg * i);
		vertices[i].y = -cos(deg * i);
	}
	return createShape(vertices, NUM);
}
void gmain() {
	window(1000, 1000);
	int idx = createPolygon();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(5);
		fill(255, 255, 0);
		shape(idx, 500, 500, deg, 200);
	}
}
*/

/*
#include"libOne.h"
int createTriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3);
}

void gmain() {
	window(1000, 1000);
	int idx = createTriangle();
	float deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		deg += 1;
		clear(200);
		strokeWeight(10);
		fill(255, 255, 0);
		shape(idx, 500, 500, deg, 200);
	}
}
*/
/*
//時計
#include"libOne.h"
#include<time.h>
void gmain() {
	window(1000, 1000);
	float x, y, deg = 0;
	float second = 0, minute = 0, hour = 0;
	angleMode(DEGREES);
	time_t stdTime;
	struct tm local;
	while (notQuit) {
		time(&stdTime);
		localtime_s(&local, &stdTime);
		second = local.tm_sec;
		minute = local.tm_min;
		hour = local.tm_hour;

		//second += 1;
		//if (second >= 60) { minute++; second = 0; }
		//if (minute >= 60) { hour++; minute = 0; }
		clear(200);
		stroke(120, 160, 255);
		strokeWeight(30);
		fill(255);
		circle(500, 500, 400*2);

		deg = 30 * hour + 30 * minute / 60;
		x = sin(deg) * 200;
		y = -cos(deg) * 200;
		stroke(120, 160, 255);
		strokeWeight(20);
		line(500, 500, 500 + x, 500 + y);

		deg = 6 * minute + 6 * second / 60;
		x = sin(deg) * 350;
		y = -cos(deg) * 350;
		stroke(160, 200, 255);
		strokeWeight(15);
		line(500, 500, 500 + x, 500 + y);

		deg = 6 * second;
		x = sin(deg) * 350;
		y = -cos(deg) * 350;
		stroke(100, 120, 255);
		strokeWeight(5);
		line(500, 500, 500 + x, 500 + y);
	}
}
*/

/*
#include"libOne.h"
void roundFace(float px, float py) {
	fill(255, 255, 0);
	circle(px, py, 300);
	fill(255);
	circle(px - 50, py, 80);
	circle(px + 50, py, 80);
	fill(0);
	circle(px - 50, py, 30);
	circle(px + 50, py, 30);
	fill(255, 0, 0);
	circle(px, py + 80, 80);
}
void squareFace(float px, float py,float angle) {
	rectMode(CENTER);
	fill(255, 255, 0);
	rect(px, py, 300,300, angle);
	fill(255);
	rect(px - 50, py, 80,80, angle);
	rect(px + 50, py, 80,80, angle);
	fill(0);
	rect(px - 50, py, 30,30);
	rect(px + 50, py, 30,30);
	fill(255, 0, 0);
	rect(px, py + 80, 80,80, angle);
}
void gmain() {
	window(1920, 1080, full);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	float ofsX = 100;
	float ofsY = 100;
	int sw = 1;
	while(notQuit) {
		ofsX = width / 2 - mouseX;
		ofsY = height / 2 - mouseY;
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		angle += 0.05f;
		clear(60, 120, 240);
		strokeWeight(10);
		for (int i = -5; i <= 5; i++) {
			if (sw == 1) {
				roundFace(px + ofsX * i, py + ofsY * i);
			}
			else {
				squareFace(px + ofsX * i, py + ofsY * i, angle);
			}
		}
	}
}
*/
/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);

	struct COLOR green = { 0,255,0 };
	struct COLOR yellow = { 255,255,0 };
	struct COLOR red = { 255,0,0 };
	struct COLOR color = green;

	int hpMax = 500;
	int hp = hpMax;
	float hpyellow = hp * 0.5f;
	float hpred = hp * 0.1f;
	float px = 700;
	float py = 200;
	float h = 60;
	while (notQuit) {
		if (isTrigger(KEY_SPACE)) { hp = hpMax; }
		if (hp > 0) { hp -= 1; }
		if (hp > hpyellow) {
			color = green;
		}
		else if (hp > hpred) {
			color = yellow;
		}
		else {
			color = red;
		}

		clear(74, 84, 89);
		fill(128);
		rect(px, py, hpMax, h);
		fill(color);
		rect(px, py, hp, h);
		if (hp <= 0) {
			textSize(100);
			text("Game Over", 700, 400);
		}
	}
}
*/
/*
#include"libOne.h"
void gmain(){
	window(1920, 1080, full);
	int life = 5;
	float px = 700;
	float py = 200;
	float radius = 50;
	float spase = 100;
	while (notQuit) {
		if (isTrigger(KEY_A)) { life--; }
		if (isTrigger(KEY_D)) { life++; }
		clear(74, 84, 89);
		fill(0, 0, 255);
		print((let)"life=" + life);

		
		for (int i = 0; i < life; i++) {
			float offsetX = spase * i;
			strokeWeight(10);
			stroke(255, 0, 0);
			fill(0, 255, 0);
			circle(px + offsetX, py, radius * 2);
		}
	}
}
*/
/*
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float radius = 150;
	float len = radius / 1.41421356f * 2;
	float angle = 0;
	float angleSpeed = 1;

	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (px < 0 || px > 1920) { vx = -vx; angleSpeed = -angleSpeed; }
		clear(0);
		stroke(255,0,0);
		strokeWeight(20);
		fill(0);
		circle(px, py, radius * 2);
		rectMode(CENTER);
		angleMode(DEGREES);
		rect(px, py, len, len, angle);
		rect(px, py, len, len, 45+angle);
		circle(px, py, radius);
		strokeWeight(50);
		point(px, py);
		strokeWeight(20);
		line(1920 / 2, 0, px, py);
		
	}
}
*/