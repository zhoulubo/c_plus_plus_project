#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vadefs.h>
#include <stdarg.h>

using namespace std;

/*
	C++ ����ת��
	static_cast // �����ת��
	const_cast // ����ת��Ϊ�ǳ���
	dynamic_cast // ����ת��Ϊ�������ͻ��Լ������ɹ�����NULL
	reinterpret_cast // ����ָ��ת�ͣ����߱���ֲ��
*/

class Person2{
public:
	virtual void print(){
		cout << "��" << endl;
	}
};

class Man : public Person2{
public:
	void print(){
		cout << "����" << endl;
	}

	void chasing(){
		cout << "���" << endl;
	}
};


class Woman : public Person2{
public:
	void print(){
		cout << "Ů��" << endl;
	}

	void carebaby(){
		cout << "������" << endl;
	}
};

// dynamic_cast
void funcDynamicCast(Person2* obj){
	//������������еĺ�����תΪʵ������
	//����֪��ת��ʧ��
	// C ��ǿ��ת�����ǲ������߼��ģ�������ǿ��ת�� ��
	Man* m = (Man*)obj;
	m->print();
	m->chasing();

	//C++ ת��ʧ�ܣ�����NULL��������ȷ
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
	// ����ĸ�ֵʱ�޷�����ͨ���ģ��������������޷��ı�
	//c = (char*)malloc(sizeof(char[10]));

	//ͨ��ָ���Ӹ�ֵ
	//�����˲���֪�������ת����Ϊ��ȥ����

	// C ʹ��(char*) ǿ�ƽ���̬����ת��Ϊ�˷Ǿ�̬���飬�Ӷ������޸�����
	char* c_p = (char*)c;
	c_p[1] = 'X';
	//C++ ָ����ת����ʽ������˿ɶ���
	c_p = const_cast<char*>(c);
	c_p[2] = 'Y';

	cout << c << endl;
}

void func1(){
	cout << "ִ�� func1" << endl;
}

char* func2(){
	cout << "ִ�� func2" << endl;
	return "abc";
}

// ����ָ��
typedef void(*f_p)();

typedef	char*(*f_p2)();

// ����ָ���ת��
void funcReinterpretCast(){

	//����ָ������
	f_p f_array[6];
	//��ֵ
	f_array[0] = func1;
	f_array[0]();
	//C��ʽ
	f_array[1] = (f_p)(func2);
	//C++��ʽ ��һ�ַ������͵ĺ���ָ��ת��Ϊ����ĺ�������
	f_array[2] = reinterpret_cast<f_p>(func2);

	f_array[1]();

	// ת��ԭ���͵ĺ���ָ��
	f_p2 fp2 = reinterpret_cast<f_p2>(f_array[2]);
	// ִ�к���
	cout << fp2() << endl;

}

// STL ��׼ģ��� ??





// IO �����ı�����


void class51(){

}

void main(){
	// �Զ�ת��
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