#pragma once
#ifndef _orderFile_
#define _orderFile_
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:
	//����
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;
	
	//��¼����ԤԼ��Ϣ������  key ��¼���� value �����¼��ֵ����Ϣ
	map<int, map<string, string>> m_orderData;
};



#endif // !_orderFile_

