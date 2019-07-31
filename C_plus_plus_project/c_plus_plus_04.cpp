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

	// ʹ�� virtual �ؼ��������෽��������෽������дʱ����ʵ�ֶ�̬
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

// �̳�
class Man : public Human{

public:
	// ������java�е�super �� ��int a��b���ݵ�������
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



// c++ ��̳�

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
������ 
public public�̳з�ʽ������&public�̳� &protected�̳�=> public=> protected =) ivat,
*/

// �̳ж�������Լ��̳����η� public
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

// �̳еĶ�����



/*
carete Human Man a 2 b 3
create Man
Man say
~Man
~Human
*/
void class41(){
	// �ȵ���Human���췽��
	Man man(2, 3);
	man.say();

	// ���� �����say
	man.Human::say();

	// �ᴴ��Human����
	Human human = man;
	human.say();

	// ���ᴴ��Human����
	Human* humanp = &man;
	humanp->say();
	// ���ᴴ��Human����
	Human& humanRef = man;
	humanRef.say();

}


// ���麯���������ࣩ
// ����һ�����麯�����������ǳ�����
// �������ʵ�֣���������Ҳ�ǳ�����
// �������޷�����ʵ��
// ����չ������ʹ�ó��������Լ������δ����ʵ�ֽ��й淶
class Shape{
public :
	// ���桰= 0������ʾΪ���麯��
	virtual void sayArea() = 0;
};


// ����ģ�壨ģ�庯�������ͷ���

template <typename	T>
void myswap(T &a,T &b){
	T c = a;
	a = b;
	b = c;
}

//ģ����(������)
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

// �̳�ģ����Ҫʹ�þ��������
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


// c++ ��NDK����Ҫ���� ����֧���쳣����
void class42() throw(MyException,char*){ // ���������׳�����쳣
	// C++���쳣����
	try{
		int a = -110;
		if (a > 0 && a<100){
			// �����׳��������͵��쳣
			throw - 1;
		}else if(a>100){
			throw "mall a";
		}else{
			throw MyException("��׼�쳣");
		}
	}
	catch (int thr){
		cout << "�쳣" << thr << endl;
		goto code_block;

	}
	//catch (char* thrstr){
	//	cout << "�쳣" << thrstr << endl;
	//}
	catch (MyException& mye){
		throw MyException(" �ڲ��׳� ");
		//cout << "�쳣" << mye.what() << endl;
	}
	catch (out_of_range o){
		o.what();
	}
	catch (invalid_argument i){
	
	}
	//catch (...){
	//	cout << "���������쳣" << endl;
	//}
	

code_block:
	cout << "���մ���" << endl;

}



// �麯����ʹ�û�����н��ղ���ʱ��Ҫʹ��virtual����
// ��̬�����ͣ�
//	��̬��̬��������ָ����������д
//	��̬��̬������
//
// ������̬��̬������
// 1.�̳�
// 2.�������û�ָ��ָ���������
// 3.������д
//

void main4x(){
	class41();
	Student student(1,2);
	// ��̳��ж�����
	//student.a = 1;
	// ��ȷָ������
	student.Person::a = 10;

	// cΪBase�е�һ��person����,�̳�ʱʹ��virtual���ο��Է�ֹ��������ȷc
	student.c = 20;

	try{
		class42();
	}
	catch (MyException e){
		cout << "�����׳� " << e.what() << endl;
	}

	// ģ�����ʵ���� ��java ����
	A<char*> a("hello");
	a.myprint();
	getchar();
}




















