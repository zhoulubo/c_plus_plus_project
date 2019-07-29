//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include <iostream>
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <vadefs.h>
#include <string.h>
#include "MyTeacher.h"

using namespace std;

// 在源文件中实现，在h文件中声明
int MyTeacher::getAge(){
		return age;
}

void MyTeacher::setAge(int age){
		this->age = age;
}

void MyTeacher::setName(char *name){
		this->name = name;
}


char* MyTeacher::getName(){
	return name;
}


// 构造函数，析构函数，拷贝构造函数
class MyClass
{
//public:
//	MyClass();
//	~MyClass();

private:
	char* name;



public:
	// 静态变量
	static char* field;

	// 无参构造
	MyClass(){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "无参构造 ";
		strcpy(name,add);
		cout << this << " : " << this->name << endl;
	}
	// 有参构造
	MyClass(int a, int b){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "带参构造 ";
		strcpy(name, add);
		cout << this << " : " << name << endl;
	}
	
	// const 修饰
	// 常函数,修饰的是this ，既不能改变指针的值也不能改变指针的内容
	// const Teacher* const this
	// 常量函数保证了数据的安全
	void func() const{
		// 静态变量可以改变
		this->field = "modif";
		//非静态变量不可改变,this不可改变
		//this->name = "modif";
		//this = (MyClass*)malloc(sizeof(MyClass));
		cout << "func" << endl;
	}

	void func2(){
		cout << "func2"  << endl;
	}



	// 默认浅拷贝 
	//MyClass(const MyClass &obj){
		// 拷贝的是指针的地址 (并没有拷贝值)，在析构的时候有可能会free两次，报错
		//name = obj.name;
	//}

	// 引用是变量的别名，指针存放的是地址
	// 拷贝构造函数(默认为值拷贝)
	// 浅拷贝
	// 深拷贝
	MyClass(const MyClass &obj){
		int len = strlen(obj.name);// strlen只会包含字符的个数，未包含\0结束符
		this->name = (char*)malloc(len+1);
		strcpy(this->name,obj.name);
		cout << "拷贝构造函数 " << this << " : " << this->name << endl;

	}

	// 析构函数 释放操作
	~MyClass(){
		//释放malloc在堆中分配的空间 
		cout << "析构函数 " << this <<" : "<< this->name << endl;
		//delete(this->name);
		free(this->name);
		//cout << "after MyClass 析构函数 neme \n" <<this->name<< endl;
	}

};

// 析构函数调用次数
void class01(){
	MyTeacher teacher;
	teacher.setAge(10);
	teacher.setName("teacher");
	cout << teacher.getName() << " : " << teacher.getAge() << endl;

	MyClass myclass;
	MyClass myclass2(1, 2);

	//使用拷贝构造函数(不是引用或指针)
	// 拷贝构造函数调用时机
	// 1.声明时赋值
	// 2.传参（形式参数值传递）
	// 3.返回值时
	//
	MyClass myclass3;// = myclass;
	// 此赋值方式赋值为指针，指向的同一地址，析构函数会被调用两次，
	// 同时被赋值之前的对象无法被回收，内存泄漏
	myclass3 = myclass2;
	//MyClass *myclass3 = new MyClass();
	//myclass3 = &myclass2;

}

void class03(){
	// 常量对象调用
	const MyClass myclass4;
	// 常量对象不能调用非常量方法
	//myclass4.func2();
	myclass4.func();

}



// 构造函数带对象参数的构造方式？？



// 静态变量只能在全局位置进行初始化赋值
// 变量类型 + 类名::字段名 = 赋值内容
char* MyClass::field = "123";


// 类的大小
// C/C++ 堆，栈，全局，（静态，全局），代码，静态常量
// 普通属性和结构体有相同的内存布局
// 
// java内存分区结构
// JVM Stack 程序员操作的是引用（基本数据类型，对象的引用）
// Native Method Stack （本地方法栈）
// 方法区
// 堆
// 静态常量

// this指针，由于函数方法不是直接存放在对象中的，是共享的，调用时则使用this标志当前调用的对象，
// 在c中没有this指针，所以如果要操作调用的对象，则需要将调用者的指针同时传递到方法内 （如jni中的*env）


//


// 创建对象和数组对象的方式
void  class02(){
	// 使用new关键字新创建对象并返回其指针，会走对应的构造函数和析构函数
	MyClass* myclass = new MyClass();
	delete myclass;

	// 使用c的malloc分配空间则不会回调构造函数和析构函数
	MyClass* myclass2 = (MyClass*)malloc(sizeof(MyClass));
	free(myclass2);

	// 创建数组类型
	// c方式
	char* charArray = (char*)malloc(sizeof(char)* 100);
	charArray[0] = 1;
	free(charArray);
	// c++方式
	char *p = new char[10];
	p[0] = 2;
	// 释放时使用[]表示数组
	delete[] p;

	// static 关键字,初始在全局位置进行，静态访问无法访问非静态成员，非静态方法可访问静态成员
	MyClass::field = "value";
	cout << MyClass::field << endl;



}



void main2x(){
	//class01();
	//class02();
	class03();
	getchar();


}