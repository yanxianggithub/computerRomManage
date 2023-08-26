#pragma once
#ifndef _student_
#define _student_
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"globalFile.h"
#include"computerRoom.h"
using namespace std;
#include"orderFile.h"
#include"Identity.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string naeme, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;

	//��ʼ��������Ϣ
	void initComRoom();
};


#endif // !_student_

