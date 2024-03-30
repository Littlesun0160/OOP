#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>

//Создать виртуальную клавиатуру с переназначаемыми действиями для клавиш и комбинаций клавиш, с возможностью отката действий назад
//Продемонстрировать работу клавиатуры, сделав Workflow из нажатий различных комбинаций клавиш и откатов назад; симулировать демонстрацию нажатий клавиш путем вывода значения в консоль и задержкой между нажатиями
//Продемонстрировать переназначение клавиши и комбинации клавиш с перезапуском Workflo

class Command
{
protected:
    std::string NameCommand;
    bool UndoFlag = false;
public:
    Command() 
    { 
        NameCommand = "Command";
    };
    virtual void execute() {};
    virtual void Undo() {};
    std::string GetName() 
    { 
        return NameCommand; 
    };
};

class VolumeDown : public Command
{
public:
    VolumeDown() : Command()
    { 
        NameCommand = "VolumeDown";
    };
    void execute() override
    {
        std::cout << "Громкость понижена!\n";
    }
    void Undo() override 
    {
        UndoFlag = true;
    }
};
class VolumeUp : public Command
{
public:
    VolumeUp() : Command()
    { 
        NameCommand = "VolumeUp";
    };
    void execute() override
    {
        std::cout << "Громкость повышена!\n";
    }
    virtual void Undo() override 
    {
        UndoFlag = true;
    }
};
class ScreenBrightnessUp : public Command
{
public:
    ScreenBrightnessUp() : Command()
    {
        NameCommand = "ScreenBrightnessUp";
    };
    virtual void execute() override
    {
        std::cout << "Яркость экрана повышена!\n";
    }
    void Undo() override
    {
        UndoFlag = true;
    }
};
class ScreenBrightnessDown : public Command
{
public:
    ScreenBrightnessDown() : Command()
    {
        NameCommand = "ScreenBrightnessDown";
    };
    virtual void execute() override
    {
        std::cout << "Яркость экрана понижена!\n";
    }
    void Undo() override
    {
        UndoFlag = true;
    }
};

class Key 
{
private:
    std::string KeyName;
    Command* KeyCommand = nullptr;
public:
    Key(std::string Name, Command* Command) : KeyName(Name), KeyCommand(Command) {}
    void PressKey() 
    {
        KeyCommand->execute();
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
    void Undo() 
    {
        KeyCommand->Undo();
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
    std::string GetName() 
    {
        return KeyName;
    }
};

class VirtualKeyboard
{
private:
    std::vector <Key> Keys{};
    std::vector <Key> History{};
public:
    void AddKey(const Key& key) 
    { 
        Keys.push_back(key); 
    }
    void PressKey(Key key)
    {
        for (int i = 0; i < Keys.size(); i++)
        {
            if (Keys[i].GetName() == key.GetName())
            {
                std::cout << "Выполнено действие: ";
                Keys[i].PressKey();
                History.push_back(Keys[i]);
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
            Key Inter = Keys[Keys.size() - 1];
            std::cout << "Выполнение команды отменено: " << Inter.GetName() << "\n";
            Inter.Undo();
            History.pop_back();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    VirtualKeyboard Keyboard;
    Key VU("VU",new VolumeUp());
    Key VD("VD", new VolumeDown());

    Keyboard.AddKey(VU);
    Keyboard.PressKey(VU);
    Keyboard.PressKey(VU);
    Keyboard.Undo();
    Keyboard.PressKey(VU);
    Keyboard.PressKey(VU);

    Keyboard.AddKey(VD);
    Keyboard.PressKey(VD);
    Keyboard.Undo();
}