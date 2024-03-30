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
	std::cout << "Введите значение точки, в которой необходимо найти производную\n";
	std::cin >> x0;

	double Dx;
	std::cout << "Введите значение шага\n";
	std::cin >> Dx;
	
	std::cout << "Левая производная равна " << lef->Func(X2, x0,Dx) << "\n";
	std::cout << "Точность равна " << lef->Accuracy() << "\n";

	std::cout << "Средняя производная равна " << mid->Func(X2, x0, Dx) << "\n";
	std::cout << "Точность равна " << mid->Accuracy() << "\n";

	std::cout << "Правая производная равна " << rig->Func(X2, x0, Dx) << "\n";
	std::cout << "Точность равна" << rig->Accuracy() << "\n";
}