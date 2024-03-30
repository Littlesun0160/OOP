#include <iostream>
#include "classArray3.hpp"


int main()
{
		/*Создаем класс шаблонный Arry3d<> который хранит одномерный массив, но выдает наружу его как 
		трезхмерны1. Переопределить операторы индексации[][][], <<
		Сдлать методы GetValue0(int i) ->[][] GeValue1(int j) ->[][]  GetValues2(int k) ->[][]
		GetValues01(int i, int j) ->[]
		GetValues02(int i, int k) ->[]
		GetValues12(in j, int k) ->[]
		и аналогичные методы для SetValues
		Сделать статический метод CrteaeFill для создания массива и присваивания всех элементов одному 
		значению*/
	setlocale(LC_ALL, "RUS");
    auto* Arr1 = new Array3<int, 2, 3, 4>();

    //Fill
    auto Arr2 = Arr1->Fill(3);
    std::cout << "Fill: ";
    Arr2->print();

    //setValue
    Arr1->setValue(1, 1, 1, 2);
    std::cout << "setValue: ";
    Arr1->print();

    //getValue
    std::cout << "getValue: ";
    std::cout << Arr1->getValue(1, 1, 1) << "\n";

    //setValue0
    std::vector<std::vector<int>> Arr3 = { {2,5,1,1},{2,1,5,8},{5,0,0,1} };
    Arr1->setValue0(Arr3, 0);
    std::cout << "setValue0: ";
    Arr1->print();

    //getValue01
    std::vector<int> Vect = Arr1->getValue01(0, 2);
    std::cout << "getValue01: ";
    for (int i = 0; i < Vect.size(); i++)
    {
        std::cout << Vect[i] << " ";
    }
    std::cout << "\n";
}