#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <windows.h>
#include <thread>

//Создать виртуальную клавиатуру с переназначаемыми действиями для клавиш и комбинаций клавиш, с возможностью отката действий назад
//Продемонстрировать работу клавиатуры, сделав Workflow из нажатий различных комбинаций клавиш и откатов назад; симулировать демонстрацию нажатий клавиш путем вывода значения в консоль и задержкой между нажатиями
//Продемонстрировать переназначение клавиши и комбинации клавиш с перезапуском Workflo

enum class TypeOfAction //примеры действий, которые могут выполнять комбинации клавиш
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
            std::cout << "Напечатан текст: Bye World\n";
            break;
        }
        case(TypeOfAction::CalculatePlus):
        {
            std::cout << "Проведено сложение\n";
            break;
        }
        case(TypeOfAction::CalculateMinus):
        {
            std::cout << "Проведено вычитание\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessUp):
        {
            std::cout << "Яркость экрана повышена\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessDown):
        {
            std::cout << "Яркость экрана понижена\n";
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
            std::cout << "Последнее написание текста отменено\n";
            break;
        }
        case(TypeOfAction::CalculatePlus):
        {
            std::cout << "Последнее действие сложения отменено\n";
            break;
        }
        case(TypeOfAction::CalculateMinus):
        {
            std::cout << "Последнее действие вычитания отменено\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessUp):
        {
            std::cout << "Последнее повышение яркости экрана отменено\n";
            break;
        }
        case(TypeOfAction::ScreenBrightnessDown):
        {
            std::cout << "Последнее понижение яркости экрана отменено\n";
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
                std::cout << "Переобозначено действие для клавиш(и) ";
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
                std::cout << "Выполнено действие: ";
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
            std::cout << "Никаких действий не было совершено";
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
//    std::map<char, std::string> keyActions; // Мапа для хранения переназначенных действий клавиш
//    std::vector<char> actionHistory; // Хранение истории выполненных действий
//public:
//    void pressKey(char key) {
//        if (keyActions.find(key) != keyActions.end()) {
//            std::cout << "Выполняется действие: " << keyActions[key] << std::endl;
//            actionHistory.push_back(key);
//            // Выполнить действие, связанное с клавишей
//        }
//        else {
//            std::cout << "Клавиша " << key << " не имеет назначенного действия" << std::endl;
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
//            std::cout << "Откат последнего действия: " << keyActions[key] << std::endl;
//            actionHistory.pop_back();
//            // Откатить последнее действие
//        }
//        else {
//            std::cout << "Нет выполненных действий для отката" << std::endl;
//        }
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//
//    VirtualKeyboard keyboard;
//
//    // Добавляем начальные назначения клавиш
//    keyboard.reassignKey('a', "Напечатать 'Привет!'");
//    keyboard.reassignKey('b', "Напечатать 'Как дела?'");
//
//    // Демонстрация нажатий клавиш
//    keyboard.pressKey('a');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.pressKey('b');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.pressKey('c');
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    keyboard.rollbackLastAction();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//
//    // Переназначаем клавишу 'a' и демонстрируем работу с новым назначением
//    keyboard.reassignKey('a', "Напечатать 'Это новое назначение клавиши a'");
//    keyboard.pressKey('a');
//}