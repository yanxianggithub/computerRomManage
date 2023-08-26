#pragma once
#ifndef _manager_
#define _manager_
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#include"globalFile.h"
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearFile();
	//��ʼ������
	void initVector();
	//����ظ� ��1 ���ѧ��/ְ����  ��2 �������
	bool checkRepeat(int id, int type);
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��ʼ��������Ϣ
	void initComputerRoom();
	//������Ϣ����
	vector<ComputerRoom> vCom;
};

#endif // !_manager_


