
#include "stdafx.h"
//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

#include "MyTeacher.h"

using namespace std;
// �����ռ�������java�İ�

namespace NSP_A{
	int a = 19;
	struct Teacher
	{
		char* name;
	};

	struct Student
	{
		char* name;
	};

};

namespace NSP_B{
	int a = 20;

	namespace NSP_B_C{
		int c = 30;
	
	}

	struct Student
	{
		char* name;
	};

};

using namespace NSP_A;
using namespace NSP_B;

class MyCircle{
	// ����Ȩ�����η�
private:
	double r;

public:
	void setR(double r){
		this->r = r;
	}

	double getS(){
		return 3.14*r*r;
	}

};

// �ṹ�岻�ܼ̳�
struct MyStruct
{
	public: int key;
			int getKey(){
				return key;
			}

}myStruct;

// ��c�����˲�������
bool isSingle = true;

// ʹ��ָ����н���
void swipValueUesPoint(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}


// ʹ��ָ����н���
// int &a ��ʾ����һ�����ñ���a
void swipValueUseRef(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}


// �ɱ����
void func(int i, ...){
	va_list args_p;
	// �ɱ�����Ŀ�ʼλ��
	//va_start(args_p, i);
	_crt_va_start(args_p, i);
	// ��ȡ����
	int a = _crt_va_arg(args_p, int);
	int b = _crt_va_arg(args_p, int);
	int c = _crt_va_arg(args_p, int);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	_crt_va_end(args_p);




}


/*
C++ ������c������
C++Ϊ����������ԣ�CΪ�������
*/
void mainxx(){
	printf("hello");
	cout << "hello c plus plus " << endl;
	cout << NSP_A::a << endl;
	cout << NSP_B::a << endl;
	cout << NSP_B::NSP_B_C::c << endl;

	NSP_A::Teacher t;
	t.name = "teacher";

	NSP_A::Student s;
	s.name = "student";

	// �����൱��ֱ�Ӵ����� MyCircle ����
	MyCircle myCircle;
	myCircle.setR(10);

	cout << "Բ����� ��" << myCircle.getS() << endl;

	//MyStruct myStruct2;
	myStruct.key = 3;
	cout << "MyStruct myStruct ��" << myStruct.getKey() << endl;

	// ��������Ŀ�����
	int a = 10, b = 20;
	// C++�� ��Ŀ��������Գ�Ϊ��ֵ������Ŀ����������з���ֵ��
	// c��java�� ֻ������Ϊ���ʽ����
	int c = a > b ? a : b + 1;
	cout << " c = a > b ? a : b + 1 c: " << c << " b = " << b << endl;
	// �������ֵ�Ļ���Ҫ�ǿ����޸ĵ���ֵ
	(a > b ? a : b) = 30;
	cout << " (a > b ? a : b) = 30 c: " << c << " b = "<< b << endl;


	// ���� ����һ������Ϊ����,���ò���Ϊ�գ�ָ�����Ϊ��
	int &x = a;
	cout << "a's ref x : " << x<< endl;
	a = 10, b = 20;
	swipValueUesPoint(&a, &b);
	cout << "swipValueUesPoint a : " << a << " b : "<<b<< endl;

	a = 10, b = 20;
	swipValueUseRef(a, b);
	cout << "swipValueUseRef a : " << a << " b : " << b << endl;

	// ���� �򻯶���ָ��




	// ָ�볣�� ָ��ĵ�ַ�����޸� final
	int *const p1 = &a;

	// ����ָ�� �����޷��ı� const
	const int *p2 = &a;
	p2 = &b;

	// C++������Ĭ�ϲ�����Ĭ�ϲ������Բ����ݣ�Ҫע���������ʱ��������

	// �ɱ����
	func(1, 2, 3, 4, 5, 6);
	getchar();

}



































