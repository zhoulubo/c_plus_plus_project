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
	// 无参构造
	MyClass(){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "无参构造 ";
		strcpy(name,add);
		cout << this->name<<endl;
	}
	// 有参构造
	MyClass(int a, int b){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "带参构造 ";
		strcpy(name, add);
		cout << name << endl;
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
		cout << "拷贝构造函数 " << this->name << endl;

	}

	// 析构函数 释放操作
	~MyClass(){
		//释放malloc在堆中分配的空间 
		cout << "析构函数 " << this->name << endl;
		//delete(this->name);
		free(this->name);
		//cout << "after MyClass 析构函数 neme \n" <<this->name<< endl;
	}

};

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
	MyClass myclass3 = myclass;
	// 此赋值方式赋值为指针，指向的同一地址，析构函数会被调用两次，
	// myclass3 = myclass2




}

void main(){
	class01();

	getchar();


}