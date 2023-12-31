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
	//构造
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;
	
	//记录所有预约信息的容器  key 记录条数 value 具体记录键值对信息
	map<int, map<string, string>> m_orderData;
};



#endif // !_orderFile_

