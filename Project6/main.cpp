#include <iostream>
#include <string>
#include <vector>
#include "Control.hpp"
#include "ControlFactory.hpp"
#include "OSForms.hpp"
#include <windows.h>
enum class OS
{
    WINDOWS,
    LINUX,
    MacOS
};

int main() 
{
    setlocale(LC_ALL, "Russian");
    ControlFactory* mainFabric = nullptr;
    Form* mainForm = nullptr;
    std::vector<OS> osMass{  OS::LINUX, OS::WINDOWS, OS::MacOS };

    for (auto os : osMass) 
    { 
        switch (os) 
        {
        case OS::WINDOWS:
            mainFabric = new WindowsControlFactory();
            break;
        case OS::LINUX:
            mainFabric = new LinuxControlFactory();
            break;
        case OS::MacOS:
            mainFabric = new MacOSControlFactory();
            break;
        }

        mainForm = mainFabric->createForm({ 19, 0 });

        mainForm->addControl(mainFabric->createLabel("Hello World", { 0,1 }));
        mainForm->addControl(mainFabric->createTextBox("Bye World", { 0, 0 }));
        mainForm->addControl(mainFabric->createButton("Button do click", { 12, 9 }));
        mainForm->addControl(mainFabric->createForm({ 76, 90 }));

        for (Control* control : mainForm->Controls) 
        {
            std::cout << control->toString() << "\n";
            if (auto* button = dynamic_cast<Button*>(control)) 
            {
                button->Click();
            }
            if (auto* label = dynamic_cast<Label*>(control))
            {
                label->getText();
            }
            if (auto* Text = dynamic_cast<TextBox*>(control))
            {
                Text->getText();
            }
        }
        std::cout << "\n";
    }
}

//—оздать симул€цию крокссплатформенного приложени€ пр помощи паттерна Ђабстрактна€ фабрикаї.‘абрика должна генерировать набор контроллов дл€ 
// различных операционных систем(Windows, Linux, MacOS).
//¬се контроллы наследуютс€ от базового класса
//Contol(setPosition, getPosition).
//ѕримеры реализующихс€ контроллов и их возможных методов
//Х	Form(addContol)
//Х	Label(setText, getText)
//Х	TextBox(setText, getText, OnValueChanged)
//Х	ComboBox(getSeletecedIndex, setSelectedIndex, setItems, getItems)
//Х	Button(setText, getText, Click)
//ѕриложение должно в зависимости от выбранной операционной системы создавать свой набор контроллов, размещать их на форме, делать с ними 
// манипул€ции(вызывать их методы(.
//√рафический интерфейс создавать не требуетс€! онтроллы в реальности на все методы просто пишут информацию о вызове метода в консоль по 
// типу :
//Ђ¬ызван метод _____  у контролла ___ї
