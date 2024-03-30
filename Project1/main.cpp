#include <iostream>
#include <functional>
#include "Diff.hpp"


double x2(double x)
{
	return x * x;
}
std::function <double(double)> X2 = x2;


int main()
{
	setlocale(LC_ALL, "rus");
	LeftDiff* lef = new LeftDiff();
	middleDiff* mid = new middleDiff();
	RightDiff* rig = new RightDiff();

	double x0;
	std::cout << "������� �������� �����, � ������� ���������� ����� �����������\n";
	std::cin >> x0;

	double Dx;
	std::cout << "������� �������� ����\n";
	std::cin >> Dx;
	
	std::cout << "����� ����������� ����� " << lef->Func(X2, x0,Dx) << "\n";
	std::cout << "�������� ����� " << lef->Accuracy() << "\n";

	std::cout << "������� ����������� ����� " << mid->Func(X2, x0, Dx) << "\n";
	std::cout << "�������� ����� " << mid->Accuracy() << "\n";

	std::cout << "������ ����������� ����� " << rig->Func(X2, x0, Dx) << "\n";
	std::cout << "�������� �����" << rig->Accuracy() << "\n";
}