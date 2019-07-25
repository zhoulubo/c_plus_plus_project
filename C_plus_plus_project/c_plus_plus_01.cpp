
#include "stdafx.h"
//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

#include "MyTeacher.h"

using namespace std;
// 命名空间类似于java的包

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
	// 共用权限修饰符
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

// 结构体不能继承
struct MyStruct
{
	public: int key;
			int getKey(){
				return key;
			}

}myStruct;

// 比c增加了布尔类型
bool isSingle = true;

// 使用指针进行交换
void swipValueUesPoint(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}


// 使用指针进行交换
// int &a 表示声明一个引用变量a
void swipValueUseRef(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}


// 可变参数
void func(int i, ...){
	va_list args_p;
	// 可变参数的开始位置
	//va_start(args_p, i);
	_crt_va_start(args_p, i);
	// 读取参数
	int a = _crt_va_arg(args_p, int);
	int b = _crt_va_arg(args_p, int);
	int c = _crt_va_arg(args_p, int);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	_crt_va_end(args_p);




}


/*
C++ 可以与c代码混编
C++为面向对象语言，C为面向过程
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

	// 这里相当于直接创建了 MyCircle 对象
	MyCircle myCircle;
	myCircle.setR(10);

	cout << "圆的面积 ：" << myCircle.getS() << endl;

	//MyStruct myStruct2;
	myStruct.key = 3;
	cout << "MyStruct myStruct ：" << myStruct.getKey() << endl;

	// 布尔和三目运算符
	int a = 10, b = 20;
	// C++中 三目运算符可以成为左值，即三目运算算符是有返回值的
	// c和java中 只能是作为表达式运算
	int c = a > b ? a : b + 1;
	cout << " c = a > b ? a : b + 1 c: " << c << " b = " << b << endl;
	// 如果是左值的话需要是可以修改的左值
	(a > b ? a : b) = 30;
	cout << " (a > b ? a : b) = 30 c: " << c << " b = "<< b << endl;


	// 引用 声明一个引用为别名,引用不能为空，指针可以为空
	int &x = a;
	cout << "a's ref x : " << x<< endl;
	a = 10, b = 20;
	swipValueUesPoint(&a, &b);
	cout << "swipValueUesPoint a : " << a << " b : "<<b<< endl;

	a = 10, b = 20;
	swipValueUseRef(a, b);
	cout << "swipValueUseRef a : " << a << " b : " << b << endl;

	// 引用 简化二级指针




	// 指针常量 指向的地址不能修改 final
	int *const p1 = &a;

	// 常量指针 内容无法改变 const
	const int *p2 = &a;
	p2 = &b;

	// C++可以有默认参数，默认参数可以不传递，要注意的是重载时参数问题

	// 可变参数
	func(1, 2, 3, 4, 5, 6);
	getchar();

}



































