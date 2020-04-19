#include<iostream>
#include"Shape.h"
using namespace std;
Shape::Shape(float area1_)
{
	area_ = area1_;
	cout << "you are using the constructor of shape" << endl;
}
Shape::Shape(const Shape& s)
{
	area_ = s.area_;
	cout << "you are using the copy constructor of shape" << endl;
}
Shape::~Shape()
{
	cout << "you are using the destructor of shape" << endl;
}
float Shape::GetArea()
{
	return area_;
}
Rectangle::Rectangle(float x1 , float y1 ):x(x1),y(y1),Shape(x*y)
{
	cout << "you are using the constructor of rectangle" << endl;
}

Rectangle::~Rectangle()
{
	cout << "you are using the destructor of rectangle" << endl;
}
float Rectangle::GetArea()
{
	return x*y;
}
Circle::Circle(float r1):r(r1),Shape(3.14 * r * r)
{
	cout << "you are using the constructor of circle" << endl;
}
Circle::~Circle()
{
	cout << "you are using the destructor of circle" << endl;
}
float Circle::GetArea()
{
	return 3.14 * r * r;
}
Square::Square(float x1) :x(x1), Rectangle(x, x)
{
	cout << "you are using the constructor of Square" << endl;
}
Square::~Square()
{
	cout << "you are using the destructor of square" << endl;
}
float Square::GetArea()
{
	return x*x;
}