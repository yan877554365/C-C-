#include<iostream>
#include<cmath>
#include<cstdlib>
#include<Windows.h>
using namespace std;
#define NULL 0
const double TINY_VALUE = 1e-10;//sinX�����ľ���
void love()
{
	float x, y;
	string s = "I love you!";
	int l = s.length();
	for (y = 1.3f; y >= -1.1f; y -= 0.06f)
	{
		int t = 0;
		for (x = -1.1f; x <= 1.1f; x += 0.025f)
		{
			double heart = x*x + (5.0*y / 4.0 - sqrt(abs(x)))*(5.0*y / 4.0 - sqrt(abs(x)));
			if (heart <= 1)
			{
				cout << s[t];
				t = (t + 1) % l;
			}
			else cout << " ";
		}
		cout << endl;
	}
}
void xing()
{
	float x, y;
	for (y = 1.5f; y >-1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x <1.5f; x += 0.05f)
		{
			float a = x*x + y*y - 1;
			if ((a*a*a - x*x*y*y*y) <= 0) cout << 'g';//���η���
			else cout << " ";
		}
		cout << endl;
	}
	cout << "                     ������";
}
void sprt_int(int n,int *a=NULL)
{
	int i, j,t;
	//char t;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (*(a + j)>*(a + j + 1))
			{
				t = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = t;
			}
		}
	}
}
void sprt_char()//��Ӧ�ڽṹ��
{

}
void FirstLetter(int nCode, char& strLetter)//��ȡ����ƴ������ĸ����1
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
void GetFirstLetter(char* strName, char* strFirstLetter, int nLen)//��ȡ����ƴ������ĸ����2
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
void name_sort()//��ĸ����a-z
{
	/*int i,*p=NULL,B;
	char tup[999][20];
	char ttp[99];
	for (i = 0; i < B; i++)
	{
		int nameLen = (int)strlen((p + i)->Employees_Name);
		GetFirstLetter((p + i)->Employees_Name, tup[i], 20);//��ȡ����ƴ������ĸ������������
	}*/
}
long double arctan(long double x)//arctanֵ�ļ��㺯��
{
	long double spr = x*x, e = x, r = 0;
	int i = 1;
	while (e / i > 1e-30)
	{
		long double F = e / i;
		r = (i % 4 == 1) ? r + F : r - F;
		e = e*spr;
		i += 2;
	}
	return r;
}
bool huei(unsigned n)//�����жϺ���
{
	unsigned i = n, m = 0;
	while (i > 0)
	{
		m = m * 10 + i%10;
		i /= 10;
	}
	return m == n;
}
void sum()//����1~100�ĺ�
{
	int s, p = 0, i;
	//����1��
	cout << "����һ���:";
	for (i = 1; i <= 100; i++)
	{
		p += i;
	}
	cout << p << endl;
	//����2��
	cout << "�����������";
	s = (1 + 100) * 100 / 2;
	cout << s << endl;
}
void paixuezu()//�������������
{
	int B[10];
	int f;
	for (f = 0; f < 10; f++)
		cin >> B[f];//�Ӽ����ϻ�ȡ����
	sprt_int(10, B);//����������
	for (f = 0; f < 10; f++)
		cout << B[f];
}
void pai()//�ɵ�������
{
	long double pai;
	pai = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0);
	cout << pai;
}
void wueiwen()//����������
{
	for (unsigned m = 11; m < 1000; m++)
	{
		if (huei(m) && huei(m*m) && huei(m*m*m))
		{
			cout << "m=" << m << endl << "m*m=" << m*m << endl << "m*m*m" << m*m*m;
		}
	}
}
double tsin(double x)
{
	double g = 0, t = x;
	int n = 1;
	do{
		g += t;
		n++;
		t = -t*x*x / (2 * n - 1) / (2 * n - 2);
	} while (fabs(t) >= TINY_VALUE);//fabs����ֵ�ж�
	return g;
}
int rollDice()//���
{
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	int sum = die1 + die2;
	cout << "��Ϸ����" << die1 << "+" << die2 << "=" << sum << endl;
	return sum;
}
enum GameStatus
{WIN,LOSE,PLAYING};
void gametotozhi()
{
	int sum, myPint;
	GameStatus status;
	unsigned seed;
	cout << "������һ���޷�������";
	cin >> seed;//�������������
	srand(seed);
	sum = rollDice();
	switch (sum)
	{
	case 7:
	case 11:
		status = WIN;
		break;
	case 2:
	case 3:
		status = LOSE;
		break;
	default:
		status = PLAYING;
		myPint = sum;
		cout << "point is" << myPint << endl;
		break;
	}
	while (status == PLAYING)
	{//ֻҪ״̬ΪPLAYING,����
		sum = rollDice();
		if (sum == myPint)//ĳ�ֵĺ������ڵ�����ȡʤ
			status = WIN;
		else if (sum == 7)//���ֺ���Ϊ7��Ϊ��
			status = LOSE;
	}
	//��״̬��ΪPLAYINGʱѭ�������������Ϸ���
	if (status == WIN)
		cout << "player wins" << endl;
	else
		cout << "player loses" << endl;
}
unsigned fac(unsigned x)//����x�Ľײ�
{
	unsigned f;
	if (x == 0)
		f = 1;
	else
		f = fac(x - 1)*x;
	return f;
}
void main()
{
	int xun=1;
	while (xun < 2)
	{
		int GAI;
		cout << "������Ҫ���Եĺ���ָ��" << endl;
		cin >> GAI;
		switch (GAI)
		{
		case 1:
			pai(); break;
		case 2:
			sum(); break;
		case 3:
			wueiwen(); break;
		case 4:
			love();
			xing(); break;
		case 5:
			gametotozhi(); break;
		case 6://���������
			int UNT, seed;
			cin >> seed;//�������������
			srand(seed);
			for (int i = 0; i < 5; i++)
			{
				UNT = rand();
				cout << UNT << endl;
			}break;
		case 7://����ײ�
			int n;
			cout << "������Ҫ����Ľײ�";
			cin >> n;
			cout << n << "�Ľײ���" << fac(n); break;
		default:
			xun = 4;
			cout << "ָ�����,���򼴽��˳�";
			break;
		}
	}
	system("pause");
}


