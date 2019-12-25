#include<iostream>
#include<iomanip>
using namespace std;
#include<windows.h>
#include<string>
#define NULL 0
int A, B, i, j, t;
struct Staffs
{
	char Employees_Name[20];           //姓名
	char Employees_ID[20];             //工号
	float Base_pay;                    //基本工资
	float Subsidy;                     //补贴
	float Bonus;                       //奖金
	float Amount_deducted;             //扣除金额
	float Real_wages;                  //实发工资
};
Staffs *p = NULL;// = new Staffs[B];//定义动态结构体Staffs数组用于存储多个员工信息
void menu();//系统菜单
void write();//写入数据
void read();//读取数据
void inpo();//录入员工基本信息
void Add();//添加员工信息
void out();//输出员工信息
float calculation(float a, float b, float c, float d);//计算实发工资
void mod();//修改员工信息
void del();//删除职工信息
void output(int i); //显示信息
void find();//查找员工信息
void sort_ID();//工号排序
void FirstLetter(int nCode, char& strRet);
void GetFirstLetter(char* strName, char* strFirstLetter, int nLen);
void name_sort();//姓名排序
void sort_wages();//工资排序
void qeq();//排序
void  main()
{
	system("color 3e");
	int yonghu;
	int mima = 321666;
	cout << "请输入密码:";
	cin >> yonghu;
	if (yonghu == mima)
	{
		int U=1;
		system("cls");
		cout << "密码正确";
		Sleep(30);
		system("cls");
		while (U<5)
		{
			menu();
			cin >> A;
			system("cls");
			switch (A)
			{
			case 1:
				inpo(); break;
			case 2:
				Add(); break;
			case 3:
				del(); break;
			case 4:
				mod(); break;
			case 5:
				find(); break;
			case 6:
				qeq(); break;
			case 7:
				read();
				out(); break;
			case 8:
				U = 6; break;
			default:cout << "无效指令！！" << endl;
			}
		}
		if (p != NULL)
			delete p;
		p = NULL;
		system("pause");
		system("cls");
	}
}
void menu()
{
	cout << "      ▲|================================================================|▲" << endl;
	cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
	cout << "      ※|+--------------*****欢迎使用员工工资管理系统*****--------------+|※" << endl;
	cout << "      ※|+-------------------------1.录入员工基本信息-------------------+|※" << endl;
	cout << "      ※|+-------------------------2.增添员工信息-----------------------+|※" << endl;
	cout << "      ※|+-------------------------3.删除员工信息-----------------------+|※" << endl;
	cout << "      ※|+-------------------------4.修改员工信息-----------------------+|※" << endl;
	cout << "      ※|+-------------------------5.查询员工信息-----------------------+|※" << endl;
	cout << "      ※|+-------------------------6.按条件排序员工信息-----------------+|※" << endl;
	cout << "      ※|+-------------------------7.输出员工的工资条-------------------+|※" << endl;
	cout << "      ※|+-------------------------8.退出系统---------------------------+|※" << endl;
	cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
	cout << "      ▼|================================================================|▼" << endl;
	cout << "                    ********请输入您想要执行的系统代号********" << endl;
}
void write()
{
	FILE *fp;
	int N;
	fp = fopen("D:\\Date.bat", "wb");
	if (fp == NULL)
	{
		cout << "Date.bat文件不存在D\\下请创建一个Date.bat文件" << endl;
		exit(0);
	}
	else
		cout << "正在写入数据" << endl;

	fwrite(&B, sizeof(int), 1, fp);
	N = fwrite(p, sizeof(struct Staffs), B, fp);
	if (N != 0)
	{
		cout << "写入数据成功" << endl;
	}
	else
		cout << "写入数据失败" << endl;
	fclose(fp);
}
void read()
{
	FILE *fp;
	int R;
	fp = fopen("D:\\Date.bat", "rb");
	if (fp == NULL)
	{
		cout << "警告!!!!" << endl;
		cout << "Date.bat文件不存在D\\下请创建一个Date.bat文件" << endl;
		exit(0);
	}
	else
		cout << "正在读取数据" << endl;
	fread(&B, sizeof(int), 1, fp);
	if (p == NULL)
		p = new Staffs[B];
	else
	{
		delete p;
		Staffs * p_new = new Staffs[B];
		p = p_new;
	}
	R = fread(p, sizeof(struct Staffs), B, fp);
	if (R != 0)
	{
		cout << "读取数据成功" << endl;
	}
	else
	{
		cout << "读取数据失败" << endl;
		cout << "您可能还没有添加员工数据" << endl;
	}
	fclose(fp);
}
void inpo()
{
	read();
	cout << "您要输入多少个员工" << endl;
	cin >> B;
	p = new Staffs[B];
	for (i = 0; i<B; i++)
	{
		cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
		cin >> (p + i)->Employees_Name;
		cout << "请输入员工" << (p + i)->Employees_Name << "的工号" << endl;
		cin >> (p + i)->Employees_ID;
		cout << "请输入员工" << (p + i)->Employees_Name << "的基本工资" << endl;
		cin >> (p + i)->Base_pay;
		cout << "请输入员工" << (p + i)->Employees_Name << "的补贴金额" << endl;
		cin >> (p + i)->Subsidy;
		cout << "请输入员工" << (p + i)->Employees_Name << "的奖金" << endl;
		cin >> (p + i)->Bonus;
		cout << "请输入员工" << (p + i)->Employees_Name << "的扣除金额" << endl;
		cin >> (p + i)->Amount_deducted;
	}
	for (i = 0; i<B; i++)
	{
		(p + i)->Real_wages = calculation((p + i)->Base_pay, (p + i)->Subsidy, (p + i)->Bonus, (p + i)->Amount_deducted);
	}

	write();
}
void Add()
{
	int flo, AD;
	char c;
	read();
	do
	{
		cout << "您要添加多少个员工" << endl;
		cin >> AD;
		char lins[20];
		flo = 0;
		Staffs *p_new = new Staffs[B + AD];
		memcpy(p_new, p, sizeof(Staffs)*B);
		if (p != NULL)
			delete p;
		p = p_new;
		for (i = 0; i < AD; i++)
		{
		back:
		{
			cout << "请输入第" << i + 1 << "个员工的工号" << endl;
			cin >> lins; ///(p + B + i)->Employees_ID;
			for (int j = 0; j < B; j++)
			{
				if (strcmp((p + j)->Employees_ID, lins) == 0)
				{
					cout << "该工号已存在！！" << endl;
					cout << "请重新输入" << endl;
					goto back;
				}
				else
				{
					strcpy((p + B + i)->Employees_ID, lins);
					break;
				}
			}
			cout << "请输入工号为：" << (p + B + i)->Employees_ID << "的姓名" << endl;
			cin >> (p + B + i)->Employees_Name;
			cout << "请输入员工" << (p + B + i)->Employees_Name << "的基本工资" << endl;
			cin >> (p + B + i)->Base_pay;
			cout << "请输入员工" << (p + B + i)->Employees_Name << "的补贴金额" << endl;
			cin >> (p + B + i)->Subsidy;
			cout << "请输入员工" << (p + B + i)->Employees_Name << "的奖金" << endl;
			cin >> (p + B + i)->Bonus;
			cout << "请输入员工" << (p + B + i)->Employees_Name << "的扣除金额" << endl;
			cin >> (p + B + i)->Amount_deducted;
		}
		}
		cout << "是否继续添加(Y/N)" << endl;
		cin >> c;
		B += AD;
	} while (c != 'N' && c != 'n');
	for (i = 0; i<B; i++)
	{
		(p + i)->Real_wages = calculation((p + i)->Base_pay, (p + i)->Subsidy, (p + i)->Bonus, (p + i)->Amount_deducted);
	}
	write();
}
float calculation(float a, float b, float c, float d)
{
	float J;
	J = a + b + c - d;
	return J;
}
void output(int i)
{
	cout << "--------------------------员工工资条--------------------------" << endl;
	cout << "姓    名|工    号|基本工资|补    贴|奖    金|扣除金额|实发工资" << endl;
	cout << setfill(' ') << setw(8) << (p + i)->Employees_Name << "|" << setw(8) << (p + i)->Employees_ID << "|" << setw(8) << (p + i)->Base_pay << "|" << setw(8) << (p + i)->Subsidy << "|" << setw(8) << (p + i)->Bonus << "|" << setw(8) << (p + i)->Amount_deducted << "|" << setw(8) << (p + i)->Real_wages << endl;
	cout << "--------------------------------------------------------------" << endl;
}
void find()
{
	char num;
	int flag, i;
	char findID[20];
	char findname[20];
	char c;
	read();
	while (1)
	{
		system("cls");
		cout << "      ▲|================================================================|▲" << endl;
		cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
		cout << "      ※|+--------------*****欢迎进入员工工资查询界面*****--------------+|※" << endl;
		cout << "      ※|+-------------------------1.按工号查询-------------------------+|※" << endl;
		cout << "      ※|+--------------------------------------------------------------+|※" << endl;
		cout << "      ※|+-------------------------2.按姓名查询-------------------------+|※" << endl;
		cout << "      ※|+--------------------------------------------------------------+|※" << endl;
		cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
		cout << "      ▼|================================================================|▼" << endl;
		cout << "                    ********请输入您想要执行的系统代号（1\2）********" << endl;

		cin >> num;
		if (num<'1' || num>'2')
		{
			cout << "指令错误，请重新输入正确指令" << endl;
			system("pause");
			continue;
		}
		system("cls");
		flag = 0;
		if (num == '1')
		{
			cout << "请输入您要查询员工的工号" << endl;
			cin >> findID;
			for (i = 0; i<B; i++)
			{
				if (strcmp((p + i)->Employees_ID, findID) == 0)
				{
					output(i);
					flag = 1;
					break;


				}

			}


		}
		else if (num == '2')
		{
			cout << "请输入您要查询员工的姓名" << endl;
			cin >> findname;
			for (i = 0; i<B; i++)
			{
				if (strcmp((p + i)->Employees_Name, findname) == 0)
				{
					output(i);
					flag = 1;

				}
			}
		}
		if (!flag)
		{
			cout << "亲！我们这边没有这个人，建议你重新查询！！！" << endl;

		}
		cout << "是否继续查询呢亲？（Y\N）" << endl;
		cin >> c;
		if (c == 'N' || c == 'n') break;
	}
}
void out()
{
	for (i = 0; i<B; i++)
	{
		(p + i)->Real_wages = calculation((p + i)->Base_pay, (p + i)->Subsidy, (p + i)->Bonus, (p + i)->Amount_deducted);
	}
	cout << "--------------------------员工工资条--------------------------" << endl;
	for (i = 0; i<B; i++)
	{
		cout << "姓    名|工    号|基本工资|补    贴|奖    金|扣除金额|实发工资" << endl;
		cout << setfill(' ') << setw(8) << (p + i)->Employees_Name << "|" << setw(8) << (p + i)->Employees_ID << "|" << setw(8) << (p + i)->Base_pay << "|" << setw(8) << (p + i)->Subsidy << "|" << setw(8) << (p + i)->Bonus << "|" << setw(8) << (p + i)->Amount_deducted << "|" << setw(8) << (p + i)->Real_wages << endl;
		cout << "--------------------------------------------------------------" << endl;
	}
}
void FirstLetter(int nCode, char& strLetter)
{
	if (nCode >= 1601 && nCode < 1637) strLetter = 'A';
	if (nCode >= 1637 && nCode < 1833) strLetter = 'B';
	if (nCode >= 1833 && nCode < 2078) strLetter = 'C';
	if (nCode >= 2078 && nCode < 2274) strLetter = 'D';
	if (nCode >= 2274 && nCode < 2302) strLetter = 'E';
	if (nCode >= 2302 && nCode < 2433) strLetter = 'F';
	if (nCode >= 2433 && nCode < 2594) strLetter = 'G';
	if (nCode >= 2594 && nCode < 2787) strLetter = 'H';
	if (nCode >= 2787 && nCode < 3106) strLetter = 'J';
	if (nCode >= 3106 && nCode < 3212) strLetter = 'K';
	if (nCode >= 3212 && nCode < 3472) strLetter = 'L';
	if (nCode >= 3472 && nCode < 3635) strLetter = 'M';
	if (nCode >= 3635 && nCode < 3722) strLetter = 'N';
	if (nCode >= 3722 && nCode < 3730) strLetter = 'O';
	if (nCode >= 3730 && nCode < 3858) strLetter = 'P';
	if (nCode >= 3858 && nCode < 4027) strLetter = 'Q';
	if (nCode >= 4027 && nCode < 4086) strLetter = 'R';
	if (nCode >= 4086 && nCode < 4390) strLetter = 'S';
	if (nCode >= 4390 && nCode < 4558) strLetter = 'T';
	if (nCode >= 4558 && nCode < 4684) strLetter = 'W';
	if (nCode >= 4684 && nCode < 4925) strLetter = 'X';
	if (nCode >= 4925 && nCode < 5249) strLetter = 'Y';
	if (nCode >= 5249 && nCode < 5590) strLetter = 'Z';
}
void GetFirstLetter(char* strName, char* strFirstLetter, int nLen)
{
	int ucHigh, ucLow;
	int nCode;
	char strRet;
	memset(strFirstLetter, 0, sizeof(nLen));
	int len = 0;
	int nameLen = (int)strlen(strName);
	for (int i = 0; i < nameLen; i += 2)
	{
		ucHigh = (int)(strName[i + 0] & 0xFF);
		ucLow = (int)(strName[i + 1] & 0xFF);
		if (ucHigh < 0xa1 || ucLow < 0xa1)
		{
			i -= 1;
			continue;
		}
		else
		{
			nCode = (ucHigh - 0xa0) * 100 + ucLow - 0xa0;
		}
		FirstLetter(nCode, strRet);
		strFirstLetter[len] = strRet;
		len++;
	}
	strFirstLetter[len] = '\0';
}
void mod()//  修改
{
	char change_ID[20];
	int number;
	char num;
	char message[100];
	float message1;
	char c;
	int flag;
	int i;
	read();
	while (1)
	{
		flag = 0;
		system("cls");
		cout << "请输入需要修改的员工的工号：" << endl;
		cin >> change_ID;
		for (i = 0; i<B; i++)
		{
			if (strcmp((p + i)->Employees_ID, change_ID) == 0)
			{
				number = i;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << "无此员工信息！！！" << endl;
			cout << "是否继续修改（Y/N）:" << endl;
			cin >> c;
			if (c == 'N' || c == 'n')break;
			continue;
		}
		cout << "      ▲|================================================================|▲" << endl;
		cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
		cout << "      ※|+------------------***********修改***********------------------+|※" << endl;
		cout << "      ※|+-----------------------1.修改员工姓名-------------------------+|※" << endl;
		cout << "      ※|+-----------------------2.修改员工工号-------------------------+|※" << endl;
		cout << "      ※|+-----------------------3.修改员工基本工资---------------------+|※" << endl;
		cout << "      ※|+-----------------------4.修改员工补贴-------------------------+|※" << endl;
		cout << "      ※|+-----------------------5.修改员工奖金-------------------------+|※" << endl;
		cout << "      ※|+-----------------------6.修改员工扣除奖金---------------------+|※" << endl;
		cout << "      ※|+-----------------------输入其他任意键退出本模块---------------+|※" << endl;
		cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
		cout << "      ▼|================================================================|▼" << endl;
		cout << "请输入指令（1-6）:" << endl;
		cin >> num;
		if (num<'1' || num>'6')
		{
			cout << "错误指令！！！" << endl;
			system("pause");
			continue;
		}
		system("cls");
		cout << "请输入修改后的信息：" << endl;
		switch (num)
		{
		case '1':
			cin >> message;
			strcpy((p + number)->Employees_Name, message); break;
		case '2':
			cin >> message;
			strcpy((p + number)->Employees_ID, message); break;
		case '3':
			cin >> message1;
			(p + number)->Base_pay = message1; break;
		case '4':
			cin >> message1;
			(p + number)->Subsidy = message1; break;
		case '5':
			cin >> message1;
			(p + number)->Bonus, message1; break;
		case '6':
			cin >> message1;
			(p + number)->Amount_deducted, message1; break;
		}
		system("cls");
		cout << "是否继续修改(Y / N):" << endl;
		cin >> c;
		if (c == 'N' || c == 'n')break;
	}
	for (i = 0; i<B; i++)
	{
		(p + i)->Real_wages = calculation((p + i)->Base_pay, (p + i)->Subsidy, (p + i)->Bonus, (p + i)->Amount_deducted);
	}
	write();
}
void del()//删除员工工信息
{
	char delete_ID[20];//删除员工工号
	int pr;//标记是否有该员工信息
	char c;
	read();
	while (1)
	{
		pr = 0;
		cout << "请输入需删除职工信息的工号：" << endl;
		cin >> delete_ID;
		for (i = 0; i < B; i++)
		{
			if (strcmp((p + i)->Employees_ID, delete_ID) == 0)//查找员工
			{
				B--;
				pr = 1;
				for (j = i; j < B; j++)
				{
					*(p + j) = *(p + (j + 1));//让数据往前移
				}
				break;
			}
		}
		if (!pr)
			cout << "无此员工信息！" << endl;
		else
			cout << "删除成功！" << endl;
		cout << "是否继续删除(Y/N):" << endl;
		scanf("%*c%c", &c);
		if (c == 'N' || c == 'n') break;
	}
	write();
}
void sort_ID()  //工号排序
{
	read();
	for (i = 0; i<B-1; i++)
	{
		for (j = 0; j<B-1-i; j++)
		{
			if (strcmp((p + j)->Employees_ID, (p + j + 1)->Employees_ID)>0)
			{
				Staffs *psta = new Staffs;
				memcpy(psta, p + j, sizeof(Staffs));
				memcpy(p + j, p + j + 1, sizeof(Staffs));
				memcpy(p + j + 1, psta, sizeof(Staffs));
				delete psta;
			}

		}
	}
	out();
	write();
}
void sort_wages()
{
	read();
	for (i = 0; i<B-1; i++)
	{
		for (j = 0; j<B -1- i; j++)
		{
			if ((p + j)->Real_wages>(p + j + 1)->Real_wages)
			{
				Staffs *psta = new Staffs;
				memcpy(psta, p + j, sizeof(Staffs));
				memcpy(p + j, p + j + 1, sizeof(Staffs));
				memcpy(p + j + 1, psta, sizeof(Staffs));
				delete psta;
			}

		}
	}
	out();
	write();
}
void name_sort()
{
	read();
	char tup[999][20];
	char ttp[99];
	for (i = 0; i <B; i++)
	{
		int nameLen = (int)strlen((p + i)->Employees_Name);
		GetFirstLetter((p + i)->Employees_Name, tup[i], 20);
	}
	/*for (i = 0; i <B; i++)
	{
		cout<<tup[i][0]<<endl;
	}*/
	for (i = 0; i < B - 1; i++)
	{
		for (j = 0; j<B - 1 - i; j++)
		{
			if (strcmp(&(tup[j][0]), &(tup[j+1][0]))>0)//字符串比较:>0表示前面的字符串比后面的大则交换
			{
				
				strcpy(ttp,&(tup[j][0]));
				strcpy(&(tup[j][0]),&(tup[j+1][0]));//先名字排序
				strcpy(&(tup[j+1][0]),ttp);
				Staffs *pst = new Staffs;//然后交换
				memcpy(pst, p + j, sizeof(Staffs));
				memcpy(p + j, p + j + 1, sizeof(Staffs));
				memcpy(p + j + 1, pst, sizeof(Staffs));
				delete pst;
				/*Staffs *psta = new Staffs;
				memcpy(psta, p + j, sizeof(Staffs));
				memcpy(p + j, p + j + 1, sizeof(Staffs));
				memcpy(p + j + 1, psta, sizeof(Staffs));
				delete psta;*/


			}

		}
	}
/*	for (i = 0; i <B; i++)
	{
		cout<<"   "<<tup[i][0]<<endl;
	}*/
	out();
	write();
}
void qeq()
{
	int pai;
	cout << "      ▲|================================================================|▲" << endl;
	cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
	cout << "      ※|+--------------*****欢迎进入员工信息排序界面*****--------------+|※" << endl;
	cout << "      ※|+-------------------------1.按工号排序-------------------------+|※" << endl;
	cout << "      ※|+--------------------------------------------------------------+|※" << endl;
	cout << "      ※|+-------------------------2.按姓名排序-------------------------+|※" << endl;
	cout << "      ※|+--------------------------------------------------------------+|※" << endl;
	cout << "      ※|+-------------------------3.按工资排序-------------------------+|※" << endl;
	cout << "      ※|+--------------------------------------------------------------+|※" << endl;
	cout << "      ※|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|※" << endl;
	cout << "      ▼|================================================================|▼" << endl;
	cout << "                    ********请输入您想要执行的系统代号（1\2）********" << endl;
	cin >> pai;
	switch (pai)
	{
	case 1:
		sort_ID(); break;
	case 2:
		name_sort(); break;
	case 3:
		sort_wages(); break;
	default:cout << "无效指令！！" << endl;
	}
}
