#include<iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { IT, ME, MF, FI, KN };
string kursStr[]{ "I", "II", "III", "IV", "V", "VI" };
string specStr[]{ "IT", "ME", "MF", "FI", "KN" };

struct Student
{
	unsigned NumGr;
	string prizv;
	Kurs kurs;
	Spec spec;
	unsigned Fiz;
	unsigned Mat;
	unsigned Inf;
};


void Create(Student* s, const int N)
{
	int kurs;
	int spec;
	for (int i = 0; i < N; i++)
	{

		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " �������: ";  getline(cin, s[i].prizv);
		cout << " ���������� ����� �������� � ����: "; cin >> s[i].NumGr;
		cout << " ����: "; cin >> kurs;
		cout << " ������������ (0 - IT, 1 - ME, 2 - MF, 3 - FI, 4 - KN): "; cin >> spec;
		cout << " ������ � ������: "; cin >> s[i].Fiz;
		cout << " ������ � ����������: "; cin >> s[i].Mat;
		cout << " ������ � �����������: "; cin >> s[i].Inf;
		s[i].kurs = (Kurs)kurs;
		s[i].spec = (Spec)spec;
		cout << endl;
	}
};


void Print(Student* s, const int N)
{
	cout << "================================================================="
		<< endl;
	cout << "|  �  |   �������   | ����� | ���� | ���� | Գ�. | ���. | ���. |"
		<< endl;
	cout << "-----------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(5) << right << s[i].NumGr << " "
			<< "| " << setw(4) << right << kursStr[s[i].kurs - 1] << " "
			<< "| " << setw(4) << right << specStr[s[i].spec] << " "
			<< "| " << setw(4) << right << s[i].Fiz << " "
			<< "| " << setw(4) << right << s[i].Mat << " "
			<< "| " << setw(5) << right << s[i].Inf << "|" << endl;
	}
	cout << "================================================================="
		<< endl;
	cout << endl;
};

void Mat_5(Student* s, const int N, int& k1)
{
	k1 = 0;
	for (int i = 0; i < N; i++)
		if (s[i].Mat == 5)
			k1++;
}

void Fiz_5(Student* s, const int N, int& k2)
{
	k2 = 0;
	for (int i = 0; i < N; i++)
		if (s[i].Fiz == 5)
			k2++;
}


void Inf_5(Student* s, const int N, int& k3)
{
	k3 = 0;
	for (int i = 0; i < N; i++)
		if (s[i].Inf == 5)
			k3++;
}



void Fiz_Mat_five(Student* s, const int N, int& k)
{
	 k = 0;
	for (int i = 0; i < N; i++)
		if (s[i].Mat == 5 && s[i].Fiz == 5)
			k++;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 0;
	int k = 0;
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;

	
	cout << "������ ������� �������� : "; cin >> N;


	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);


	Mat_5(s, N, k1);
	cout << "ʳ������ ������ '������' � ����������:  " << k1 << endl;
	cout << endl;

	Fiz_5(s, N, k2);
	cout << "ʳ������ ������ '������' � ������:  " << k2<< endl;
	cout << endl;

	Inf_5(s, N, k3);
	cout << "ʳ������ ������ '������' � �����������:  " << k3 << endl;
	cout << endl;


	Fiz_Mat_five(s, N, k);
	cout << "ʳ������ ��������, �� �������� � ������ � � ���������� ������ '5' :   " << k << endl;

	return 0;
}
