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

// ��Դ�ļ���ʵ�֣���h�ļ�������
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


// ���캯���������������������캯��
class MyClass
{
//public:
//	MyClass();
//	~MyClass();

private:
	char* name;



public:
	// ��̬����
	static char* field;

	// �޲ι���
	MyClass(){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "�޲ι��� ";
		strcpy(name,add);
		cout << this << " : " << this->name << endl;
	}
	// �вι���
	MyClass(int a, int b){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "���ι��� ";
		strcpy(name, add);
		cout << this << " : " << name << endl;
	}
	
	// const ����
	// ������,���ε���this ���Ȳ��ܸı�ָ���ֵҲ���ܸı�ָ�������
	// const Teacher* const this
	// ����������֤�����ݵİ�ȫ
	void func() const{
		// ��̬�������Ըı�
		this->field = "modif";
		//�Ǿ�̬�������ɸı�,this���ɸı�
		//this->name = "modif";
		//this = (MyClass*)malloc(sizeof(MyClass));
		cout << "func" << endl;
	}

	void func2(){
		cout << "func2"  << endl;
	}



	// Ĭ��ǳ���� 
	//MyClass(const MyClass &obj){
		// ��������ָ��ĵ�ַ (��û�п���ֵ)����������ʱ���п��ܻ�free���Σ�����
		//name = obj.name;
	//}

	// �����Ǳ����ı�����ָ���ŵ��ǵ�ַ
	// �������캯��(Ĭ��Ϊֵ����)
	// ǳ����
	// ���
	MyClass(const MyClass &obj){
		int len = strlen(obj.name);// strlenֻ������ַ��ĸ�����δ����\0������
		this->name = (char*)malloc(len+1);
		strcpy(this->name,obj.name);
		cout << "�������캯�� " << this << " : " << this->name << endl;

	}

	// �������� �ͷŲ���
	~MyClass(){
		//�ͷ�malloc�ڶ��з���Ŀռ� 
		cout << "�������� " << this <<" : "<< this->name << endl;
		//delete(this->name);
		free(this->name);
		//cout << "after MyClass �������� neme \n" <<this->name<< endl;
	}

};

// �����������ô���
void class01(){
	MyTeacher teacher;
	teacher.setAge(10);
	teacher.setName("teacher");
	cout << teacher.getName() << " : " << teacher.getAge() << endl;

	MyClass myclass;
	MyClass myclass2(1, 2);

	//ʹ�ÿ������캯��(�������û�ָ��)
	// �������캯������ʱ��
	// 1.����ʱ��ֵ
	// 2.���Σ���ʽ����ֵ���ݣ�
	// 3.����ֵʱ
	//
	MyClass myclass3;// = myclass;
	// �˸�ֵ��ʽ��ֵΪָ�룬ָ���ͬһ��ַ�����������ᱻ�������Σ�
	// ͬʱ����ֵ֮ǰ�Ķ����޷������գ��ڴ�й©
	myclass3 = myclass2;
	//MyClass *myclass3 = new MyClass();
	//myclass3 = &myclass2;

}

void class03(){
	// �����������
	const MyClass myclass4;
	// ���������ܵ��÷ǳ�������
	//myclass4.func2();
	myclass4.func();

}



// ���캯������������Ĺ��췽ʽ����



// ��̬����ֻ����ȫ��λ�ý��г�ʼ����ֵ
// �������� + ����::�ֶ��� = ��ֵ����
char* MyClass::field = "123";


// ��Ĵ�С
// C/C++ �ѣ�ջ��ȫ�֣�����̬��ȫ�֣������룬��̬����
// ��ͨ���Ժͽṹ������ͬ���ڴ沼��
// 
// java�ڴ�����ṹ
// JVM Stack ����Ա�����������ã������������ͣ���������ã�
// Native Method Stack �����ط���ջ��
// ������
// ��
// ��̬����

// thisָ�룬���ں�����������ֱ�Ӵ���ڶ����еģ��ǹ���ģ�����ʱ��ʹ��this��־��ǰ���õĶ���
// ��c��û��thisָ�룬�������Ҫ�������õĶ�������Ҫ�������ߵ�ָ��ͬʱ���ݵ������� ����jni�е�*env��


//


// ����������������ķ�ʽ
void  class02(){
	// ʹ��new�ؼ����´������󲢷�����ָ�룬���߶�Ӧ�Ĺ��캯������������
	MyClass* myclass = new MyClass();
	delete myclass;

	// ʹ��c��malloc����ռ��򲻻�ص����캯������������
	MyClass* myclass2 = (MyClass*)malloc(sizeof(MyClass));
	free(myclass2);

	// ������������
	// c��ʽ
	char* charArray = (char*)malloc(sizeof(char)* 100);
	charArray[0] = 1;
	free(charArray);
	// c++��ʽ
	char *p = new char[10];
	p[0] = 2;
	// �ͷ�ʱʹ��[]��ʾ����
	delete[] p;

	// static �ؼ���,��ʼ��ȫ��λ�ý��У���̬�����޷����ʷǾ�̬��Ա���Ǿ�̬�����ɷ��ʾ�̬��Ա
	MyClass::field = "value";
	cout << MyClass::field << endl;



}



void main2x(){
	//class01();
	//class02();
	class03();
	getchar();


}