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
	const int NUM = 3;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = cos(deg*i);
		vertices[i].y = sin(deg*i);
	}
	return createShape(vertices, NUM);
}

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
//���v
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