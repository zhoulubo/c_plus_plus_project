#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

using namespace std;

/*
	C++ 类型转换
	static_cast // 常规的转换
	const_cast // 常量转型为非常量
	dynamic_cast // 子类转型为父类类型或自己，不成功返回NULL
	reinterpret_cast // 函数指针转型，不具备移植性
*/

class Person2{
public:
	virtual void print(){
		cout << "人" << endl;
	}
};

class Man : public Person2{
public:
	void print(){
		cout << "男人" << endl;
	}

	void chasing(){
		cout << "泡妞" << endl;
	}
};


class Woman : public Person2{
public:
	void print(){
		cout << "女人" << endl;
	}

	void carebaby(){
		cout << "生孩子" << endl;
	}
};

// dynamic_cast
void funcDynamicCast(Person2* obj){
	//调用子类的特有的函数，转为实际类型
	//并不知道转型失败
	// C 的强制转换后，是不符合逻辑的，但还是强制转换 了
	Man* m = (Man*)obj;
	m->print();
	m->chasing();

	//C++ 转型失败，返回NULL，更加明确
	m = dynamic_cast<Man*>(obj);
	if (m != NULL){
		m->chasing();
	}

	Woman* w = dynamic_cast<Woman*>(obj);
	if (w != NULL){
		w->carebaby();
	}
}

// const_cast
void funcConstCast(const char c[]){
	//c[1] = 'a';
	// 上面的赋值时无法编译通过的，常量的内容是无法改变
	//c = (char*)malloc(sizeof(char[10]));

	//通过指针间接赋值
	//其他人并不知道，这次转型是为了去常量

	// C 使用(char*) 强制将静态数组转换为了非静态数组，从而可以修改内容
	char* c_p = (char*)c;
	c_p[1] = 'X';
	//C++ 指明了转换方式，提高了可读性
	c_p = const_cast<char*>(c);
	c_p[2] = 'Y';

	cout << c << endl;
}

void func1(){
	cout << "执行 func1" << endl;
}

char* func2(){
	cout << "执行 func2" << endl;
	return "abc";
}

// 函数指针
typedef void(*f_p)();

typedef	char*(*f_p2)();

// 函数指针的转换
void funcReinterpretCast(){

	//函数指针数组
	f_p f_array[6];
	//赋值
	f_array[0] = func1;
	f_array[0]();
	//C方式
	f_array[1] = (f_p)(func2);
	//C++方式 将一种返回类型的函数指针转换为另外的函数类型
	f_array[2] = reinterpret_cast<f_p>(func2);

	f_array[1]();

	// 转回原类型的函数指针
	f_p2 fp2 = reinterpret_cast<f_p2>(f_array[2]);
	// 执行函数
	cout << fp2() << endl;

}

// STL 标准模板库 ??





// IO 流，文本操作


void class51(){

}

void main(){
	// 自动转型
	int a = 10;
	double b = a;
	a = 10.6;

	a = static_cast<int>(10.7);

	//char* printStr;
	//sprintf(printStr,"int a %d ,double b %l")
	cout << a << " " << b << endl;

	Woman w1;
	Person2 *p1 = &w1;

	funcDynamicCast(p1);

	//Woman w1;
	//Woman* w_p = &w1;

	char c[] = "hello";
	funcConstCast(c);

	funcReinterpretCast();
	system("pause");
}












//void main(){
//	class51();
//	getchar();
//}