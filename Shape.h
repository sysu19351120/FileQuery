#ifndef SHAPE
#define SHAPE
#include<iostream>
class Shape
{
protected:
	float area_;
public:
	Shape(float area1_=0);
	~Shape();
	 Shape(const Shape &s);
	 float GetArea();

};
class Rectangle: public Shape
{
public:
	float GetArea();
	Rectangle(float x1 = 0, float y1 = 0);
	~Rectangle();
private:
	float x, y;

};
class Circle :public Shape
{
public:
	float GetArea();
	Circle(float r1 = 0);
	~Circle();
private:
	float r;
};
class Square :public Rectangle
{
public:
	float GetArea();
	Square(float x1);
	~Square();
private:
	float x;
};
#endif