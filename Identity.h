#pragma once //��ֹͷ�ļ��ظ�����
#ifndef _Identity_
#define _Identity_
#include<iostream>
using namespace std;

class Identity
{
public:
	//�����˵�  ���麯��
	virtual void operMenu() = 0;


	//����
	string m_Name;
	//����
	string m_Pwd;
};

#endif // !_Identity_


