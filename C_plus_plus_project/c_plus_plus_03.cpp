#include "stdafx.h"


//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

using namespace std;

// ��Ԫ����
class A{
	// ��������B�п��Է���A����������
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

// ��Ԫ������ʵ��
// ����Ԫ�����п��Է���˽�г�Ա
void set_private_a(A*p, int a){
	p->a = a;
	p->myprint();
}


// ��Ԫ��
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

// ���������
class Point
{
	// operator ���������
	// ��Ա����д��
	friend Point operator * (Point &pa, Point &pb);

public:
	Point(int x, int y, int pv_x, int pv_y);
	~Point();
	void myprint(){
		cout << "x " << x << " y " << y << " pv_x " << pv_x << " pv_y " << pv_y << endl;
	}
	int x;
	int y;

	// operator ���������
	// ��Ա����д��
	Point operator - (Point &pb){
		this->myprint();
		pb.myprint();
		cout << "operator -" << endl;
		Point tmp(this->x + pb.x, pb.y + pb.y,this->pv_x,this->pv_y);
		return tmp;
	}



	// ˽�г�Ա�����������ʹ����Ԫ����
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

// operator ���������
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
	// ˽�г�Ա�޷�ֱ�ӷ���
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