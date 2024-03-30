#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <windows.h>
#include <thread>

//������� ����������� ���������� � ���������������� ���������� ��� ������ � ���������� ������, � ������������ ������ �������� �����
//������������������ ������ ����������, ������ Workflow �� ������� ��������� ���������� ������ � ������� �����; ������������ ������������ ������� ������ ����� ������ �������� � ������� � ��������� ����� ���������
//������������������ �������������� ������� � ���������� ������ � ������������ Workflo

enum class TypeOfAction //������� ��������, ������� ����� ��������� ���������� ������
{
    PrintText,
    CalculatePlus,
    CalculateMinus,
    ScreenBrightnessUp,
    ScreenBrightnessDown
};
class Command 
{
private:
    TypeOfAction action;
public:
    Command() = default;
    Command(TypeOfAction Action) : action(Action) {};
    void SetNewAction(TypeOfAction Action) { action = Action; }
    virtual void execute() 
    {
        switch (action)
        {
        case(TypeOfAction::PrintText):
        {
            std::cout << "��������� �����: Bye World\n";
            break;
        }
        case(TypeOfAction::CalculatePlus):
        {
            std::cout << "��������� ��������\n";
            break;
        }
        case(TypeOfAction::CalculateMinus):
        {
            std::cout << "��������� ���������\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessUp):
        {
            std::cout << "������� ������ ��������\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessDown):
        {
            std::cout << "������� ������ ��������\n";
            break;
        }
        }
    };
    virtual void undo() 
    {
        switch (action)
        {
        case(TypeOfAction::PrintText):
        {
            std::cout << "��������� ��������� ������ ��������\n";
            break;
        }
        case(TypeOfAction::CalculatePlus):
        {
            std::cout << "��������� �������� �������� ��������\n";
            break;
        }
        case(TypeOfAction::CalculateMinus):
        {
            std::cout << "��������� �������� ��������� ��������\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessUp):
        {
            std::cout << "��������� ��������� ������� ������ ��������\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessDown):
        {
            std::cout << "��������� ��������� ������� ������ ��������\n";
            break;
        }
        }
    };
};

struct Key 
{
    Command KeyCommand;
    std::string keyCombination;
    Key(const std::string& keyName, const TypeOfAction action) : keyCombination(keyName), KeyCommand(action)   {};
};

class VirtualKeyboard 
{
private:
    std::vector<Key> History;
    std::vector<Key> Keys; 
public:
    void AddKey(const Key& key)
    {
        Keys.push_back(key);
    }
    void ReassignKey(const Key& key, const TypeOfAction& action)
    {
        for (int i = 0; i < Keys.size(); i++)
        {
            if (Keys[i].keyCombination == key.keyCombination)
            {
                (Keys[i].KeyCommand).SetNewAction(action);
                std::cout << "�������������� �������� ��� ������(�) ";
                for (int i = 0; i < key.keyCombination.size(); i++)
                {
                    std::cout << key.keyCombination[i];
                }
                std::cout << "\n";
                return;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }

    void pressKey(const Key& key) 
    {
        for (int i = 0; i < Keys.size(); i++)
        {
            if (Keys[i].keyCombination == key.keyCombination)
            {
                History.push_back(Keys[i]);
                std::cout << "��������� ��������: ";
                (Keys[i].KeyCommand).execute();
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                return;
            }
        }
    }

    void Undo() 
    {
        if (History.size() == 0)
        {
            std::cout << "������� �������� �� ���� ���������";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            std::cout << "\x1B[A" << '\r' << std::string(100, ' ') << '\r';
        }
        else
        {
            Command Inter;
            for (int i = 0; i < Keys.size(); i++)
            {
                if (History.back().keyCombination == Keys[i].keyCombination)
                {
                   Inter = Keys[i].KeyCommand;
                }
            }
            History.pop_back();
            std::cout << "\033[38; 5; 223m";
            Inter.undo();

            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            std::cout << "\033[0m";
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    VirtualKeyboard Keyboard;
    Key OOP("OOP", TypeOfAction::PrintText);
    Key A("A", TypeOfAction::CalculateMinus);
    Key Space("Space", TypeOfAction::ScreenBrightnessUp);
   
    Keyboard.AddKey(A);
    Keyboard.pressKey(A);
    Keyboard.ReassignKey(A, TypeOfAction::CalculatePlus);
    Keyboard.pressKey(A);

    Keyboard.AddKey(OOP);
    Keyboard.AddKey(Space);
    Keyboard.pressKey(Space);
    Keyboard.Undo();   
}






































//#include <iostream>
//#include <map>
//#include <vector>
//#include <thread>
//#include <chrono>
//
//class VirtualKeyboard {
//private:
//    std::map<char, std::string> keyActions; // ���� ��� �������� ��������������� �������� ������
//    std::vector<char> actionHistory; // �������� ������� ����������� ��������
//public:
//    void pressKey(char key) {
//        if (keyActions.find(key) != keyActions.end()) {
//            std::cout << "����������� ��������: " << keyActions[key] << std::endl;
//            actionHistory.push_back(key);
//            // ��������� ��������, ��������� � ��������
//        }
//        else {
//            std::cout << "������� " << key << " �� ����� ������������ ��������" << std::endl;
//        }
//    }
//
//    void reassignKey(char key, std::string action) 
//    {
//        keyActions[key] = action;
//    }
//
//    void rollbackLastAction() {
//        if (!actionHistory.empty()) {
//            char key = actionHistory.back();
//            std::cout << "����� ���������� ��������: " << keyActions[key] << std::endl;
//            actionHistory.pop_back();
//            // �������� ��������� ��������
//        }
//        else {
//            std::cout << "��� ����������� �������� ��� ������" << std::endl;
//        }
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//
//    VirtualKeyboard keyboard;
//
//    // ��������� ��������� ���������� ������
//    keyboard.reassignKey('a', "���������� '������!'");
//    keyboard.reassignKey('b', "���������� '��� ����?'");
//
//    // ������������ ������� ������
//    keyboard.pressKey('a');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.pressKey('b');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.pressKey('c');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.rollbackLastAction();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//
//    // ������������� ������� 'a' � ������������� ������ � ����� �����������
//    keyboard.reassignKey('a', "���������� '��� ����� ���������� ������� a'");
//    keyboard.pressKey('a');
//}