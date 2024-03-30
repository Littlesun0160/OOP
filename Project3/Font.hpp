#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

enum class Color : int 
{
	BLACK,
	BLUE,
	GREEN,
	RED = 4,
	PURPLE = 5,
	BROWN = 6,
	GREY = 7,
	YELLOW = 14,
	WHITE = 15
};

class Font 
{
private:
	std::string m_Text;
	std::vector <std::string> m_5Font;
	std::vector <std::string> m_7Font;
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Font(std::string Text) 
	{
		m_Text = Text;
		std::string Row5;
		std::ifstream InputFont1("5.txt");
		std::string Row7;
		std::ifstream InputFont2("7.txt");
		std::vector <std::string> Intermediary;

		while (std::getline(InputFont1, Row5))
		{
			Intermediary.push_back(Row5);
		}
		InputFont1.close();

		int Index = 0;
		for (int i = 0; i < Intermediary[0].length(); i++)
		{
			bool Check = true;
			for (int p = 0; p < 5; p++)
			{
				if (Intermediary[p][i] != ' ')
				{
					Check = false;
				}
			}
			if (Check)
			{
				
				std::string Part;
				for (int j = 0; j < 5; j++)
				{
					Part += Intermediary[j].substr(Index, i - Index);
				}
				Index = i + 1;
				m_5Font.push_back(Part);
			}
		}
		Intermediary.clear();
		
		while (std::getline(InputFont2, Row7)) 
		{
			Intermediary.push_back(Row7);
		}
		InputFont2.close();
		Index = 0;
		for (int i = 0; i < Intermediary[0].length(); i++)
		{
			bool Check = true;
			for (int p = 0; p < 7; p++)
			{
				if (Intermediary[p][i] != ' ')
				{
					Check = false;
				}
			}
			if (Check)
			{
				std::string Part;
				for (int j = 0; j < 7; j++)
				{
					Part += Intermediary[j].substr(Index, i - Index);
				}
				Index = i + 1;
				m_7Font.push_back(Part);
			}
		}
	}

	void Output(int Count, Color colour, std::vector <std::string> Font)
	{
		std::vector <std::string> Text{};
		for (int i = 0; i < Count; i++) 
		{
			std::string InterText;
			for (int q = 0; q < m_Text.size(); q++) 
			{
				char Letter = toupper(m_Text[q]);
				if (Letter == ' ') 
				{
					InterText += "    ";
				}
				else 
				{
					for (int j = i * Font[Letter - 65].size() / Count; j < (i+ 1) * Font[Letter - 65].size() / Count; j++)
					{
						InterText += Font[Letter - 65][j];
					}
					InterText += " ";
				}
			}
			Text.push_back(InterText);
		}
		SetConsoleTextAttribute(hand, static_cast<int>(colour));
		for (int i = 0; i < Text.size(); i++) 
		{
			std::cout << Text[i] << '\n';
		}
		SetConsoleTextAttribute(hand, static_cast<int>(Color::WHITE));
	}

	void Print(int Font, Color colour) 
	{
		
		std::vector <std::string> font;
		if (Font == 5) 
		{
			for (int i = 0; i < m_5Font.size(); i++)
			{
				font.push_back(m_5Font[i]);
			}
			Output(5, colour, font);
		}
		else if (Font == 7) 
		{
			for (int i = 0; i < m_7Font.size(); i++)
			{
				font.push_back(m_7Font[i]);
			}
			Output(7, colour, font);
		}
		else 
		{
			std::cout << "Error. Uncorrected font" << "\n";
		}
	}
};