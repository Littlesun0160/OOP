#include"Font.hpp"
#include <iostream>
#include <string>

int main()
{
	/*������� ����� ��� ������ ������ � ������� � ������������ �������, ������������ ������ � ������������ �������� 
	������������ (����������� 1, 3, 4). ����� ������ ���������� ������� ��������� ������� � ����� � ����� ������ ��� 
	���������� �����. ������� ������������� �������� � �����. ������ ������ ���� �����, ����� �� ����� �������������
	����� ����������� � ����� ������� ����� ��������*/
	std::string str1 = "Hello";
	Font Shrift1(str1);
	Shrift1.Print(5, Color::GREY);

	std::string str2 = "World";
	Font Shrift2(str2);
	Shrift2.Print(7, Color::PURPLE);
}