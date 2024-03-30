#include <iostream>
#include <vector>
#include <functional>
#include "PropertyChanged.hpp"
#include "PropertyChanging.hpp"
#include "CollectionChanged.hpp"

int main() 
{
    setlocale(LC_ALL, "Russian");

    //PropertyChanged
    ExampleOfPropertyChangedWork Object1(60);
    Object1.PropertyChanged_AddListener([](int) { std::cout << "�������� ��������!" << "\n";});
    Object1.setProperty(40);
    std::cout << "\n";

    //PropertyChanching
    ExampleOfPropertyChangingWork Object2(80);
    Object2.PropertyChanging_AddListener([](const int oldValue, const int newValue, bool& cancel) 
        {
            if (newValue == oldValue) 
            {
                cancel = true;
                std::cout << "�������� �� ��������" << "\n";
            }
            else 
            {
                cancel = false;
                std::cout << "��������� �������� � " << oldValue << " �� " << newValue << "\n";
            }
        });
    Object2.setProperty(100);
    Object2.setProperty(10);
    Object2.setProperty(10);

    //CollectionChanged
    ExampleOfCollectionChangedWork Object3;
    Object3.CollectionChanged_AddListener([](int value, int index, CollectionChangeAction action) 
        {
        switch (action) 
        {
        case CollectionChangeAction::Added:
            std::cout << "������� " << value << " �������� � ���������" << "\n";;
            break;
        case CollectionChangeAction::Removed:
            std::cout << "������� " << value << " ��� �������� " << index << " ������ �� ���������" << "\n";;
            break;
        case CollectionChangeAction::ItemChanged:
            std::cout << "������� " << value << " ��� �������� " << index << " � ��������� �������" << "\n";;
            break;
        }
        });
    Object3.Add(9);
    Object3.Add(0);
    Object3.Add(82);
    Object3.Change(10, 1);
    Object3.Remove(0);
}

//1) ������� ���������
//INotifyPropertyChanged � �������� AddInotifyPropertyChangedListener � RemoveNotifyPropertyChangedListener.� �������� ���������� ������ 
// ������ ��������� �������, ������� ����������� � ������ ��������� ������� �������, ��������������� ���������
//
//2) ������� ���������
//INotifyPropertyChanging � �������� AddInotifyPropertyChangedListener � RemoveNotifyPropertyChangedListener.� �������� ���������� ������ 
// ������ ��������� �������, ������� ����������� ��������������� ����� ���������� ������� �������, ��������������� ���������, � ��������� 
// ���������� � ��� � ������ �� ����� �������� �������� �������� � � ������������ ������ ������� ���������
//
//3) ������� ���������
//INotifyCollectionChanged � �������� AddInotifyPropertyChangedListener � RemoveNotifyPropertyChangedListener.� �������� ���������� ������ 
// ������ ��������� �������, ������� ����������� � ������ ��������� ������� - ���������, ��������������� ���������.�������� ������������� �� 
// ��������� : Added, Removed, ItemChanged � ����������� ��������������� �������� ������������� � �������� ��������� � ������������ �������.
//
//4) ������� ������, �������������� ������ ����������, ������������ � ������ ����������� � ������������������ �� ������ � ���������� ����������.