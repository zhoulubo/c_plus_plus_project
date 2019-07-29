#include "stdafx.h"


//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

using namespace std;

// 友元函数
class A{
	// 声明在类B中可以访问A的所有属性
	friend class B;

private: int a;

public: 
	A(){
		a = 10;
	}

	void myprint(){
		cout << a << endl;
	}

	friend void set_private_a(A*p, int a);
};

// 友元函数的实现
// 在友元函数中可以访问私有成员
void set_private_a(A*p, int a){
	p->a = a;
	p->myprint();
}


// 友元类
class B
{
public:
	B();
	~B();
	void accessA(){
		a.a = 40;
	}
private:
	A a;
};

// 运算符重载
class Point
{
	// operator 重载运算符
	// 成员函数写法
	friend Point operator * (Point &pa, Point &pb);

public:
	Point(int x, int y, int pv_x, int pv_y);
	~Point();
	void myprint(){
		cout << "x " << x << " y " << y << " pv_x " << pv_x << " pv_y " << pv_y << endl;
	}
	int x;
	int y;

	// operator 重载运算符
	// 成员函数写法
	Point operator - (Point &pb){
		this->myprint();
		pb.myprint();
		cout << "operator -" << endl;
		Point tmp(this->x + pb.x, pb.y + pb.y,this->pv_x,this->pv_y);
		return tmp;
	}



	// 私有成员的运算符重载使用友元函数
private:
	int pv_x = 20;
	int pv_y = 30;
};

Point::Point(int x, int y ,int pv_x, int pv_y){
	this->x = x;
	this->y = y;
	this->pv_x = pv_x;
	this->pv_y = pv_y;
}

Point::~Point()
{
}

// operator 重载运算符
Point operator + (Point &pa, Point &pb){
	pa.myprint();
	pb.myprint();
	cout << "operator +" << endl;
	Point tmp(pa.x + pb.x,pb.y + pb.y,0,0);
	return tmp;
}


Point operator * (Point &pa,Point &pb){
	pa.myprint();
	pb.myprint();
	cout << "operator *" << endl;
	Point tmp(0,0,pa.pv_x + pb.pv_x, pa.pv_y + pb.pv_y);
	return tmp;
}

void main3x(){
	A obja;
	// 私有成员无法直接访问
	//obja.
	obja.myprint();
	set_private_a(&obja,20);

	Point pointa(10,15,1,2);

	Point pointb(20, 25,2,3);
	Point sum = pointa + pointb;
	sum.myprint();

	Point sum2 = pointa*pointb;
	sum2.myprint();

	getchar();
}