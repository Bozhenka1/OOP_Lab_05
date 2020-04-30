#include <string>
#include <iostream>
#include "Excursion.h"

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");

	const int MaxKst_allElem = 20;

	WalkingTour* walk[MaxKst_allElem];
	MixedExcursion* Mix[MaxKst_allElem];

	int kst_walk;
	int kst_mix;

	cout << "������ ������� ���� ��������" << endl;
	cin >> kst_walk;

	string temp_str;
	int temp_int;
	double temp_dou;

	for (int i = 0; i < kst_walk; i++)
	{
		walk[i] = new WalkingTour;
		cout << "������ ����� �������" << endl;
		cin >> temp_str;
		walk[i]->SetName(temp_str);

		cout << "������ ���� ������� (��������� 12.06.1945)" << endl;
		cin >> temp_str;
		walk[i]->SetData(temp_str);

		cout << "������ ��������� ������� � ������� �������" << endl;
		cin >> temp_int;
		walk[i]->SetDuration(temp_int);

		cout << "������ ���� �������" << endl;
		cin >> temp_dou;
		walk[i]->SetPrice(temp_dou);

		cout << "������ ��� ���" << endl;
		cin >> temp_str;
		walk[i]->SetGidName(temp_str);

		cout << "������ ���� ���" << endl;
		cin >> temp_dou;
		walk[i]->SetGidPrice(temp_dou);
	}
	cout << "������ ������� ������� ��������" << endl;
	cin >> kst_mix;

	for (int i = 0; i < kst_mix; i++)
	{
		Mix[i] = new MixedExcursion;
		cout << "������ ����� �������" << endl;
		cin >> temp_str;
		Mix[i]->SetName(temp_str);

		cout << "������ ���� ������� (��������� 12.06.1945)" << endl;
		cin >> temp_str;
		Mix[i]->SetData(temp_str);

		cout << "������ ��������� ������� � ������� �������" << endl;
		cin >> temp_int;
		Mix[i]->SetDuration(temp_int);

		cout << "������ ���� �������" << endl;
		cin >> temp_dou;
		Mix[i]->SetPrice(temp_dou);

		cout << "������ ��� ���" << endl;
		cin >> temp_str;
		Mix[i]->SetGidName(temp_str);

		cout << "������ ���� ���" << endl;
		cin >> temp_dou;
		Mix[i]->SetGidPrice(temp_dou);

		cout << "������ ����� ��������" << endl;
		cin >> temp_str;
		Mix[i]->SetBusNamber(temp_str);

		cout << "������ ��� ����" << endl;
		cin >> temp_str;
		Mix[i]->SetDriverName(temp_str);

		cout << "������ ���� ����" << endl;
		cin >> temp_dou;
		Mix[i]->SetDriverPrice(temp_dou);

		cout << "������ ������� ���� ����" << endl;
		cin >> temp_int;
		Mix[i]->SetPedestrianTime(temp_int);

		cout << "������ ������� ���� �� �������" << endl;
		cin >> temp_int;
		Mix[i]->SetBusTime(temp_int);
	}
	cout << "��� ��� ��� �������" << endl;
	for (int i = 0; i < kst_walk; i++)
	{
		cout << i + 1 << ')' << endl;
		cout << walk[i]->GetName() << endl;
		cout << walk[i]->GetData() << endl;
		cout << walk[i]->GetPrice() << endl;
		cout << walk[i]->GetDuration() << endl;
		cout << walk[i]->GetGidName() << endl;
		cout << walk[i]->GetGidPrice() << endl;
	}


	cout << "��� ��� ����� �������" << endl;
	for (int i = 0; i < kst_mix; i++)
	{
		cout << i + 1 << ')' << endl;
		cout << Mix[i]->GetName() << endl;
		cout << Mix[i]->GetData() << endl;
		cout << Mix[i]->GetPrice() << endl;
		cout << Mix[i]->GetDuration() << endl;
		cout << Mix[i]->GetGidName() << endl;
		cout << Mix[i]->GetGidPrice() << endl;
		cout << Mix[i]->GetBusNamber() << endl;
		cout << Mix[i]->GetDriverName() << endl;
		cout << Mix[i]->GetDriverPrice() << endl;
		cout << Mix[i]->GetPedestrianTime() << endl;
		cout << Mix[i]->GetBusTime() << endl;
	}
	Excursion* arr[MaxKst_allElem * 2];

	int i, arrkst = 0;

	for (i = 0; i < kst_walk; i++)
	{
		bool NewUniwerse = false;
		int j;
		for (j = 0; j < arrkst; j++) {
			if (arr[j]->GetGidName() == walk[i]->GetGidName()) {
				NewUniwerse = true;
				break;
			}
		}
		if (NewUniwerse) {
			arr[j]->AddSum(walk[i]->GetGidPrice());
			continue;
		}
		arr[arrkst] = walk[i];
		arr[arrkst]->AddSum(walk[i]->GetGidPrice());
		arrkst++;
	}


	for (i = 0; i < kst_mix; i++)
	{
		bool NewUniwerse = false;
		int j;
		for (j = 0; j < arrkst; j++) {
			if (arr[j]->GetGidName() == Mix[i]->GetGidName()) {
				NewUniwerse = true;
				break;
			}
		}
		if (NewUniwerse) {
			arr[j]->AddSum(Mix[i]->GetGidPrice());
			continue;
		}
		arr[arrkst] = Mix[i];
		arr[arrkst]->AddSum(Mix[i]->GetGidPrice());
		arrkst++;
	}

	Excursion* temp;
	for (int d = 0; d < arrkst; d++)
		for (int g = 0; g < arrkst - d - 1; g++)
			if (arr[g]->GetTotalPrice() < arr[g + 1]->GetTotalPrice()) {
				temp = arr[g];
				arr[g] = arr[g + 1];
				arr[g + 1] = temp;
			}
	cout << "������� ����� ��� ��� � �� ��������" << endl;
	for (int d = 0; d < arrkst; d++) {
		cout << arr[d]->GetGidName() << '\t' << arr[d]->GetTotalPrice() << endl;
	}
	system("pause");
	return 0;
}
