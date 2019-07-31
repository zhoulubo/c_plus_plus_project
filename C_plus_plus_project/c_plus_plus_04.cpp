#include "stdafx.h"


//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>
using namespace std;


class Human
{
public:
	//Human();

	Human(int a, int b){
		cout << "carete Human Man a " << a << " b " << b << endl;
	}

	Human(Human& human);
	~Human();

	// 使用 virtual 关键字修饰类方法，这个类方法被复写时可以实现多态
	virtual void say(){
		cout << "Human say" << endl;
	}
private:

};

//Human::Human()
//{
//	cout << "create Human " << endl;
//};

Human::Human(Human& human){

	cout << "copy human "  << endl;
}

Human::~Human()
{
	cout << "~Human " << endl;
}

// 继承
class Man : public Human{

public:
	// 类似于java中的super ， 将int a，b传递到父类中
	Man(int a,int b) :Human( a, b){
		cout << "create Man " << endl;
	}
	
	Man(Man& man) :Human(1, 2){
		cout << "copy Man " << endl;
		this->a = man.a;
	}

	~Man();

	void say(){
		cout << "Man say" << endl;
	}

	void funcA(){
		cout << "funcA " << endl;
		say();
	}

private:
	int a;

};

Man::~Man()
{
	cout << "~Man " << endl;
}



// c++ 多继承

class Base{
public :
	int c;
};


class Person : virtual public Base
{
public:
	Person();
	Person(int a,int b);
	~Person();
	int a;
	int b;
private:

};

Person::Person(int a, int b){
	cout << "carete Person" << a << b << endl;

}

Person::Person()
{
}

Person::~Person()
{
}

class Citizen :virtual public Base
{
public:
	Citizen(int a, int b);
	~Citizen();
	int a;
	int b;
private:

};

Citizen::Citizen(int a, int b)
{
	cout << "create Citizen" << a << b << endl;
}

Citizen::~Citizen()
{
}
/*
基类中 
public public继承方式子类中&public继承 &protected继承=> public=> protected =) ivat,
*/

// 继承多个父类以及继承修饰符 public
class Student :public Person, public Citizen
{
public:
	~Student();
	Student(int a, int b) 
		:Person(a, b), Citizen(a, b){
		cout <<"Student Person" << endl;

	};
	
private:

};


Student::~Student()
{
}

// 继承的二义性



/*
carete Human Man a 2 b 3
create Man
Man say
~Man
~Human
*/
void class41(){
	// 先调用Human构造方法
	Man man(2, 3);
	man.say();

	// 调用 父类的say
	man.Human::say();

	// 会创建Human对象
	Human human = man;
	human.say();

	// 不会创建Human对象，
	Human* humanp = &man;
	humanp->say();
	// 不会创建Human对象
	Human& humanRef = man;
	humanRef.say();

}


// 纯虚函数（抽象类）
// 包含一个纯虚函数，这个类就是抽象类
// 子类必须实现，否则子类也是抽象类
// 抽象类无法产生实例
// 在扩展过程中使用抽象类进行约束，对未来的实现进行规范
class Shape{
public :
	// 后面“= 0”，表示为纯虚函数
	virtual void sayArea() = 0;
};


// 函数模板（模板函数）泛型方法

template <typename	T>
void myswap(T &a,T &b){
	T c = a;
	a = b;
	b = c;
}

//模板类(泛型类)
template<class T>
class A{
public:
	A(T a){
		this->a = a;
	}
	void myprint(){
		cout << "Template data : " << a << endl;
	}
protected:
	T a;

};

// 继承模板类要使用具体的类型
class B :A<int>{
public:
	B();
	~B();

private:

};



class MyException :public exception{
public:
	MyException(char*msg) :exception(msg){
		cout << "create MyException :" << msg << endl;
	}

};


// c++ 在NDK中需要主动 配置支持异常处理
void class42() throw(MyException,char*){ // 可以向外抛出多个异常
	// C++的异常处理
	try{
		int a = -110;
		if (a > 0 && a<100){
			// 可以抛出任意类型的异常
			throw - 1;
		}else if(a>100){
			throw "mall a";
		}else{
			throw MyException("标准异常");
		}
	}
	catch (int thr){
		cout << "异常" << thr << endl;
		goto code_block;

	}
	//catch (char* thrstr){
	//	cout << "异常" << thrstr << endl;
	//}
	catch (MyException& mye){
		throw MyException(" 内部抛出 ");
		//cout << "异常" << mye.what() << endl;
	}
	catch (out_of_range o){
		o.what();
	}
	catch (invalid_argument i){
	
	}
	//catch (...){
	//	cout << "任意类型异常" << endl;
	//}
	

code_block:
	cout << "最终处理" << endl;

}



// 虚函数，使用基类进行接收参数时，要使用virtual修饰
// 多态的类型：
//	动态多态：运行中指定函数被重写
//	静态多态：重载
//
// 发生动态多态的条件
// 1.继承
// 2.父类引用或指针指向子类对象
// 3.函数重写
//

void main4x(){
	class41();
	Student student(1,2);
	// 多继承有二义性
	//student.a = 1;
	// 明确指定对象
	student.Person::a = 10;

	// c为Base中的一份person拷贝,继承时使用virtual修饰可以防止拷贝，明确c
	student.c = 20;

	try{
		class42();
	}
	catch (MyException e){
		cout << "向外抛出 " << e.what() << endl;
	}

	// 模板类的实例化 和java 类似
	A<char*> a("hello");
	a.myprint();
	getchar();
}




















