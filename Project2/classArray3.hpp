#pragma once

#include <vector>
#include <iostream>

template<class Type, int Dim1, int Dim2, int Dim3>

class Array3
{
private:
    std::vector <Type> m_Array;
    int m_SizeofArray = Dim1*Dim2*Dim3;
public:
    Array3()   
    {
        for (int i = 0; i < m_SizeofArray; i++) {
            m_Array.push_back(Type());               //заполняет массив пустыми значениями 
        }
    }

    bool CheckRange1(int InputDim1)
    {
        if ((InputDim1>=0) && (InputDim1 < Dim1)) { return true; }
        else return false;
    }
    bool CheckRange2(int InputDim2)
    {
        if ((InputDim2>=0) && (InputDim2 < Dim2)) { return true; }
        else return false;
    }
    bool CheckRange3(int InputDim3)
    {
        if ((InputDim3>=0) && (InputDim3 < Dim3)) { return true; }
        else return false;
    }

    void setValue(int InputDim1, int InputDim2, int InputDim3, const Type& element)
    {
        if (CheckRange1(InputDim1) && CheckRange2(InputDim2) && CheckRange3(InputDim3))
        {
            m_Array[(m_SizeofArray / Dim1) * InputDim1 + (m_SizeofArray / (Dim1 * Dim2)) * InputDim2 + InputDim3] = element;
        }
        else
        {
            throw std::exception("Неверные индексы");
        }
    }

    void setValue0(const std::vector<std::vector<Type>>& Array2, int InputDim1) 
    {
        for (int i = 0; i < Dim2; i++)
        {
            for (int j = 0; j < Dim3; j++)
            {
                if (i < Array2.size() && j < Array2[i].size()) 
                {
                    this->setValue(InputDim1, i, j, Array2[i][j]);
                }
            }
        }
    }
    void setValue1(const std::vector<std::vector<Type>>& Array2, int InputDim2) 
    {
        for (int i = 0; i < Dim1; i++)
        {
            for (int j = 0; j < Dim3; j++)
            {
                if (i < Array2.size() && j < Array2[i].size())
                {
                    this->setValue(InputDim2, i, j, Array2[i][j]);
                }
            }
        }
    }
    void setValue2(const std::vector<std::vector<Type>>& Array2, int InputDim3) 
    {
        if (CheckRange3(InputDim3) == false)
        {
            throw std::out_of_range("Неверные индексы");
        }
        for (int i = 0; i < Dim1; i++)
        {
            for (int j = 0; j < Dim2; j++)
            {
                if (i < Array2.size() && j < Array2[i].size())
                {
                    this->setValue(InputDim3, i, j, Array2[i][j]);
                }
            }
        }
    }

    void setValue01(std::vector<Type> Array1, int InputDim1, int InputDim2)
    {
        if ((CheckRange1(InputDim1) == false) || (CheckRange2(InputDim2) == false))
        {
            throw std::out_of_range("Неверные индексы");
        }
        for (int i = 0; i < Dim3; i++)
        {
            if (i < Array1.size())
            {
                this->setValue(InputDim1, InputDim2, i, Array1[i]);
            }
        }
    }
    void setValue02(std::vector<Type> Array1, int InputDim1, int InputDim3)
    {
        if ((CheckRange1(InputDim1) == false) || (CheckRange3(InputDim3) == false))
        {
            throw std::out_of_range("Неверные индексы");
        }
        for (int i = 0; i < Dim2; i++)
        {
            if (i < Array1.size())
            {
                this->setValue(InputDim1, InputDim3, i, Array1[i]);
            }
        }
    }
    void setValue12(std::vector<Type> Array1, int InputDim2, int InputDim3)
    {
        if ((CheckRange2(InputDim2) == false) || (CheckRange3(InputDim3) == false))
        {
            throw std::out_of_range("Неверные индексы");
        }
        for (int i = 0; i < Dim1; i++)
        {
            if (i < Array1.size())
            {
                this->setValue(InputDim2, InputDim3, i, Array1[i]);
            }
        }
    }


    Type getValue(int InputDim1, int InputDim2, int InputDim3) 
    {
        if ((CheckRange1(InputDim1) == false) && (CheckRange2(InputDim2) == false) && (CheckRange3(InputDim3) == false))
        {
            throw std::out_of_range("Неверные индексы");
        }
        return m_Array[(m_SizeofArray / Dim1) * InputDim1 + (m_SizeofArray / (Dim1 * Dim2)) * InputDim2 + InputDim3];
    }

    std::vector<std::vector<Type>> getValue0(int InputDim1) 
    {
        if ((CheckRange1(InputDim1) == false))
        {
            throw std::out_of_range("Неверные индексы");
        }
        std::vector<std::vector<Type>> InterArray2{}; 
        for (int i = 0; i < Dim2; i++) 
        {
            std::vector<Type> InterArray1{}; 
            for (int j = 0; j < Dim3; j++) 
            {
                InterArray1.push_back(this->getValue(InputDim1, i, j));
            }
            InterArray2.push_back(InterArray1);
        }
        return InterArray2;
    }
     std::vector<std::vector<Type>> getValue1(int InputDim2) 
    {
         if ((CheckRange2(InputDim2) == false))
         {
             throw std::out_of_range("Неверные индексы");
         }
        std::vector<std::vector<Type>> InterArray2{}; 
        for (int i = 0; i < Dim1; i++) 
        {
            std::vector<Type> InterArray1{}; 
            for (int j = 0; j < Dim3; j++) 
            {
                InterArray1.push_back(this->getValue(InputDim2, i, j));
            }
            InterArray2.push_back(InterArray1);
        }
        return InterArray2;
    }
     std::vector<std::vector<Type>> getValue2(int InputDim3)
     {
         if ((CheckRange3(InputDim3) == false))
         {
             throw std::out_of_range("Неверные индексы");
         }
         std::vector<std::vector<Type>> InterArray2{};
         for (int i = 0; i < Dim1; i++)
         {
             std::vector<Type> InterArray1{};
             for (int j = 0; j < Dim2; j++)
             {
                 InterArray1.push_back(this->getValue(InputDim3, i, j));
             }
             InterArray2.push_back(InterArray1);
         }
         return InterArray2;
     }


     std::vector<Type> getValue01(int InputDim1, int InputDim2) 
     {
         if ((CheckRange1(InputDim1) == false) && (CheckRange2(InputDim2) == false))
         {
             throw std::out_of_range("Неверные индексы");
         }
         std::vector<Type> InterArray1{};
         for (int i = 0; i < Dim3; i++) 
         {
             InterArray1.push_back(getValue(InputDim1, InputDim2, i));
         }
         return InterArray1;
     }
     std::vector<Type> getValue02(int InputDim1, int InputDim3)
     {
         if ((CheckRange1(InputDim1) == false) && (CheckRange3(InputDim3) == false))
         {
             throw std::out_of_range("Неверные индексы");
         }
         std::vector<Type> InterArray1{};
         for (int i = 0; i < Dim2; i++)
         {
             InterArray1.push_back(getValue(InputDim1, InputDim3, i));
         }
         return InterArray1;
     }
     std::vector<Type> getValue12(int InputDim2, int InputDim3)
     {
         if ((CheckRange2(InputDim2) == false) && (CheckRange3(InputDim3) == false))
         {
             throw std::out_of_range("Неверные индексы");
         }
         std::vector<Type> InterArray1{};
         for (int i = 0; i < Dim1; i++)
         {
             InterArray1.push_back(getValue(InputDim2, InputDim3, i));
         }
         return InterArray1;
     }

     static Array3* Fill(Type element) 
     {
         auto* NewArray = new Array3<Type, Dim1, Dim2, Dim3> (); //объект матрёшки
         for (int i = 0; i < Dim1; i++) 
         {
             for (int j = 0; j < Dim2; j++) 
             {
                 for (int k = 0; k < Dim3; k++) 
                 {
                     NewArray->setValue(i, j, k, element);
                 }
             }
         }
         return NewArray;
     }

     void print()
     {
         std::cout << "[";
         for (int i = 0; i < Dim1; i++) 
         {
             std::cout << "[";
             for (int j = 0; j < Dim2; j++) 
             {
                 std::cout << "[";
                 for (int k = 0; k < Dim3; k++) 
                 {
                     std::cout << getValue(i, j, k);
                     if (k != (Dim3 - 1)) 
                         std::cout << ",";
                 }
                 std::cout << "]";
                 if (j != (Dim2 - 1))
                     std::cout << ",";
             }
             std::cout << "]";
             if (i != (Dim1 - 1))
                 std::cout << ",";
         }
         std::cout << "]";
         std::cout << "\n";
     }
};