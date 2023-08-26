#include <iostream>
#include <stdlib.h>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
using namespace std;

//�����ʦ�Ӳ˵�
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			//ע��i��¼
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�� ���Ե��������������ӿ�
		Manager* man = (Manager*)manager;

		int select;

		cin >> select;

		if (select == 1)//����˺�
		{
			//cout << "���" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���" << endl;
			man->clearFile();
		}
		else
		{
			//ע��
			//Ĭ������� ��Ϊ��ע����¼
			delete manager;//���ٵ������Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����  ��1 �����ļ��� ��2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�� ����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while ( ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}

	}

	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;//д��д����ν������������void����ֵ
}


int main()
{
	int select = 0;//���ڽ����û�����
	while (true)
	{
		cout << "======================= ��ӭ��������ԤԼϵͳ =====================";
		cout << endl << "������������" << endl;
		cout << "\t\t ---------------------------------------\n";
		cout << "\t\t|					|\n";
		cout << "\t\t|		1.ѧ������		|\n";
		cout << "\t\t|					|\n";
		cout << "\t\t|		2.��ʦ			|\n";
		cout << "\t\t|					|\n";
		cout << "\t\t|		3.����Ա		|\n";
		cout << "\t\t|					|\n";
		cout << "\t\t|		0.�˳�			|\n";
		cout << "\t\t|					|\n";
		cout << "\t\t ---------------------------------------\n";
		cout << "����������ѡ��" << endl;

		cin >> select;//�����û�����
		
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE,1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}