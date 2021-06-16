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

/*
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
*/

/*
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