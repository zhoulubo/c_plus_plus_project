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
	// �޲ι���
	MyClass(){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "�޲ι��� ";
		strcpy(name,add);
		cout << this->name<<endl;
	}
	// �вι���
	MyClass(int a, int b){
		name = (char*)malloc(sizeof(char)* 100);
		char* add = "���ι��� ";
		strcpy(name, add);
		cout << name << endl;
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
		cout << "�������캯�� " << this->name << endl;

	}

	// �������� �ͷŲ���
	~MyClass(){
		//�ͷ�malloc�ڶ��з���Ŀռ� 
		cout << "�������� " << this->name << endl;
		//delete(this->name);
		free(this->name);
		//cout << "after MyClass �������� neme \n" <<this->name<< endl;
	}

};

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
	MyClass myclass3 = myclass;
	// �˸�ֵ��ʽ��ֵΪָ�룬ָ���ͬһ��ַ�����������ᱻ�������Σ�
	// myclass3 = myclass2




}

void main(){
	class01();

	getchar();


}