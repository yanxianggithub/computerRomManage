#pragma once
#ifndef _teacher_
#define _teacher_
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"Identity.h"
#include"orderFile.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
};

#endif // !_teacher_

