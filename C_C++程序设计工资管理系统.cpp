#include<iostream>
#include<iomanip>
using namespace std;
#include<windows.h>
#include<string>
#define NULL 0
int A, B, i, j, t;
struct Staffs
{
	char Employees_Name[20];           //����
	char Employees_ID[20];             //����
	float Base_pay;                    //��������
	float Subsidy;                     //����
	float Bonus;                       //����
	float Amount_deducted;             //�۳����
	float Real_wages;                  //ʵ������
};
Staffs *p = NULL;// = new Staffs[B];//���嶯̬�ṹ��Staffs�������ڴ洢���Ա����Ϣ
void menu();//ϵͳ�˵�
void write();//д������
void read();//��ȡ����
void inpo();//¼��Ա��������Ϣ
void Add();//���Ա����Ϣ
void out();//���Ա����Ϣ
float calculation(float a, float b, float c, float d);//����ʵ������
void mod();//�޸�Ա����Ϣ
void del();//ɾ��ְ����Ϣ
void output(int i); //��ʾ��Ϣ
void find();//����Ա����Ϣ
void sort_ID();//��������
void FirstLetter(int nCode, char& strRet);
void GetFirstLetter(char* strName, char* strFirstLetter, int nLen);
void name_sort();//��������
void sort_wages();//��������
void qeq();//����
void  main()
{
	system("color 3e");
	int yonghu;
	int mima = 321666;
	cout << "����������:";
	cin >> yonghu;
	if (yonghu == mima)
	{
		int U=1;
		system("cls");
		cout << "������ȷ";
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
			default:cout << "��Чָ���" << endl;
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
	cout << "      ��|================================================================|��" << endl;
	cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
	cout << "      ��|+--------------*****��ӭʹ��Ա�����ʹ���ϵͳ*****--------------+|��" << endl;
	cout << "      ��|+-------------------------1.¼��Ա��������Ϣ-------------------+|��" << endl;
	cout << "      ��|+-------------------------2.����Ա����Ϣ-----------------------+|��" << endl;
	cout << "      ��|+-------------------------3.ɾ��Ա����Ϣ-----------------------+|��" << endl;
	cout << "      ��|+-------------------------4.�޸�Ա����Ϣ-----------------------+|��" << endl;
	cout << "      ��|+-------------------------5.��ѯԱ����Ϣ-----------------------+|��" << endl;
	cout << "      ��|+-------------------------6.����������Ա����Ϣ-----------------+|��" << endl;
	cout << "      ��|+-------------------------7.���Ա���Ĺ�����-------------------+|��" << endl;
	cout << "      ��|+-------------------------8.�˳�ϵͳ---------------------------+|��" << endl;
	cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
	cout << "      ��|================================================================|��" << endl;
	cout << "                    ********����������Ҫִ�е�ϵͳ����********" << endl;
}
void write()
{
	FILE *fp;
	int N;
	fp = fopen("D:\\Date.bat", "wb");
	if (fp == NULL)
	{
		cout << "Date.bat�ļ�������D\\���봴��һ��Date.bat�ļ�" << endl;
		exit(0);
	}
	else
		cout << "����д������" << endl;

	fwrite(&B, sizeof(int), 1, fp);
	N = fwrite(p, sizeof(struct Staffs), B, fp);
	if (N != 0)
	{
		cout << "д�����ݳɹ�" << endl;
	}
	else
		cout << "д������ʧ��" << endl;
	fclose(fp);
}
void read()
{
	FILE *fp;
	int R;
	fp = fopen("D:\\Date.bat", "rb");
	if (fp == NULL)
	{
		cout << "����!!!!" << endl;
		cout << "Date.bat�ļ�������D\\���봴��һ��Date.bat�ļ�" << endl;
		exit(0);
	}
	else
		cout << "���ڶ�ȡ����" << endl;
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
		cout << "��ȡ���ݳɹ�" << endl;
	}
	else
	{
		cout << "��ȡ����ʧ��" << endl;
		cout << "�����ܻ�û�����Ա������" << endl;
	}
	fclose(fp);
}
void inpo()
{
	read();
	cout << "��Ҫ������ٸ�Ա��" << endl;
	cin >> B;
	p = new Staffs[B];
	for (i = 0; i<B; i++)
	{
		cout << "�������" << i + 1 << "��Ա��������" << endl;
		cin >> (p + i)->Employees_Name;
		cout << "������Ա��" << (p + i)->Employees_Name << "�Ĺ���" << endl;
		cin >> (p + i)->Employees_ID;
		cout << "������Ա��" << (p + i)->Employees_Name << "�Ļ�������" << endl;
		cin >> (p + i)->Base_pay;
		cout << "������Ա��" << (p + i)->Employees_Name << "�Ĳ������" << endl;
		cin >> (p + i)->Subsidy;
		cout << "������Ա��" << (p + i)->Employees_Name << "�Ľ���" << endl;
		cin >> (p + i)->Bonus;
		cout << "������Ա��" << (p + i)->Employees_Name << "�Ŀ۳����" << endl;
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
		cout << "��Ҫ��Ӷ��ٸ�Ա��" << endl;
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
			cout << "�������" << i + 1 << "��Ա���Ĺ���" << endl;
			cin >> lins; ///(p + B + i)->Employees_ID;
			for (int j = 0; j < B; j++)
			{
				if (strcmp((p + j)->Employees_ID, lins) == 0)
				{
					cout << "�ù����Ѵ��ڣ���" << endl;
					cout << "����������" << endl;
					goto back;
				}
				else
				{
					strcpy((p + B + i)->Employees_ID, lins);
					break;
				}
			}
			cout << "�����빤��Ϊ��" << (p + B + i)->Employees_ID << "������" << endl;
			cin >> (p + B + i)->Employees_Name;
			cout << "������Ա��" << (p + B + i)->Employees_Name << "�Ļ�������" << endl;
			cin >> (p + B + i)->Base_pay;
			cout << "������Ա��" << (p + B + i)->Employees_Name << "�Ĳ������" << endl;
			cin >> (p + B + i)->Subsidy;
			cout << "������Ա��" << (p + B + i)->Employees_Name << "�Ľ���" << endl;
			cin >> (p + B + i)->Bonus;
			cout << "������Ա��" << (p + B + i)->Employees_Name << "�Ŀ۳����" << endl;
			cin >> (p + B + i)->Amount_deducted;
		}
		}
		cout << "�Ƿ�������(Y/N)" << endl;
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
	cout << "--------------------------Ա��������--------------------------" << endl;
	cout << "��    ��|��    ��|��������|��    ��|��    ��|�۳����|ʵ������" << endl;
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
		cout << "      ��|================================================================|��" << endl;
		cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
		cout << "      ��|+--------------*****��ӭ����Ա�����ʲ�ѯ����*****--------------+|��" << endl;
		cout << "      ��|+-------------------------1.�����Ų�ѯ-------------------------+|��" << endl;
		cout << "      ��|+--------------------------------------------------------------+|��" << endl;
		cout << "      ��|+-------------------------2.��������ѯ-------------------------+|��" << endl;
		cout << "      ��|+--------------------------------------------------------------+|��" << endl;
		cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
		cout << "      ��|================================================================|��" << endl;
		cout << "                    ********����������Ҫִ�е�ϵͳ���ţ�1\2��********" << endl;

		cin >> num;
		if (num<'1' || num>'2')
		{
			cout << "ָ�����������������ȷָ��" << endl;
			system("pause");
			continue;
		}
		system("cls");
		flag = 0;
		if (num == '1')
		{
			cout << "��������Ҫ��ѯԱ���Ĺ���" << endl;
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
			cout << "��������Ҫ��ѯԱ��������" << endl;
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
			cout << "�ף��������û������ˣ����������²�ѯ������" << endl;

		}
		cout << "�Ƿ������ѯ���ף���Y\N��" << endl;
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
	cout << "--------------------------Ա��������--------------------------" << endl;
	for (i = 0; i<B; i++)
	{
		cout << "��    ��|��    ��|��������|��    ��|��    ��|�۳����|ʵ������" << endl;
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
void mod()//  �޸�
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
		cout << "��������Ҫ�޸ĵ�Ա���Ĺ��ţ�" << endl;
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
			cout << "�޴�Ա����Ϣ������" << endl;
			cout << "�Ƿ�����޸ģ�Y/N��:" << endl;
			cin >> c;
			if (c == 'N' || c == 'n')break;
			continue;
		}
		cout << "      ��|================================================================|��" << endl;
		cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
		cout << "      ��|+------------------***********�޸�***********------------------+|��" << endl;
		cout << "      ��|+-----------------------1.�޸�Ա������-------------------------+|��" << endl;
		cout << "      ��|+-----------------------2.�޸�Ա������-------------------------+|��" << endl;
		cout << "      ��|+-----------------------3.�޸�Ա����������---------------------+|��" << endl;
		cout << "      ��|+-----------------------4.�޸�Ա������-------------------------+|��" << endl;
		cout << "      ��|+-----------------------5.�޸�Ա������-------------------------+|��" << endl;
		cout << "      ��|+-----------------------6.�޸�Ա���۳�����---------------------+|��" << endl;
		cout << "      ��|+-----------------------��������������˳���ģ��---------------+|��" << endl;
		cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
		cout << "      ��|================================================================|��" << endl;
		cout << "������ָ�1-6��:" << endl;
		cin >> num;
		if (num<'1' || num>'6')
		{
			cout << "����ָ�����" << endl;
			system("pause");
			continue;
		}
		system("cls");
		cout << "�������޸ĺ����Ϣ��" << endl;
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
		cout << "�Ƿ�����޸�(Y / N):" << endl;
		cin >> c;
		if (c == 'N' || c == 'n')break;
	}
	for (i = 0; i<B; i++)
	{
		(p + i)->Real_wages = calculation((p + i)->Base_pay, (p + i)->Subsidy, (p + i)->Bonus, (p + i)->Amount_deducted);
	}
	write();
}
void del()//ɾ��Ա������Ϣ
{
	char delete_ID[20];//ɾ��Ա������
	int pr;//����Ƿ��и�Ա����Ϣ
	char c;
	read();
	while (1)
	{
		pr = 0;
		cout << "��������ɾ��ְ����Ϣ�Ĺ��ţ�" << endl;
		cin >> delete_ID;
		for (i = 0; i < B; i++)
		{
			if (strcmp((p + i)->Employees_ID, delete_ID) == 0)//����Ա��
			{
				B--;
				pr = 1;
				for (j = i; j < B; j++)
				{
					*(p + j) = *(p + (j + 1));//��������ǰ��
				}
				break;
			}
		}
		if (!pr)
			cout << "�޴�Ա����Ϣ��" << endl;
		else
			cout << "ɾ���ɹ���" << endl;
		cout << "�Ƿ����ɾ��(Y/N):" << endl;
		scanf("%*c%c", &c);
		if (c == 'N' || c == 'n') break;
	}
	write();
}
void sort_ID()  //��������
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
			if (strcmp(&(tup[j][0]), &(tup[j+1][0]))>0)//�ַ����Ƚ�:>0��ʾǰ����ַ����Ⱥ���Ĵ��򽻻�
			{
				
				strcpy(ttp,&(tup[j][0]));
				strcpy(&(tup[j][0]),&(tup[j+1][0]));//����������
				strcpy(&(tup[j+1][0]),ttp);
				Staffs *pst = new Staffs;//Ȼ�󽻻�
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
	cout << "      ��|================================================================|��" << endl;
	cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
	cout << "      ��|+--------------*****��ӭ����Ա����Ϣ�������*****--------------+|��" << endl;
	cout << "      ��|+-------------------------1.����������-------------------------+|��" << endl;
	cout << "      ��|+--------------------------------------------------------------+|��" << endl;
	cout << "      ��|+-------------------------2.����������-------------------------+|��" << endl;
	cout << "      ��|+--------------------------------------------------------------+|��" << endl;
	cout << "      ��|+-------------------------3.����������-------------------------+|��" << endl;
	cout << "      ��|+--------------------------------------------------------------+|��" << endl;
	cout << "      ��|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|��" << endl;
	cout << "      ��|================================================================|��" << endl;
	cout << "                    ********����������Ҫִ�е�ϵͳ���ţ�1\2��********" << endl;
	cin >> pai;
	switch (pai)
	{
	case 1:
		sort_ID(); break;
	case 2:
		name_sort(); break;
	case 3:
		sort_wages(); break;
	default:cout << "��Чָ���" << endl;
	}
}