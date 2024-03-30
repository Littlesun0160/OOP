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
    Object1.PropertyChanged_AddListener([](int) { std::cout << "—войство изменено!" << "\n";});
    Object1.setProperty(40);
    std::cout << "\n";

    //PropertyChanching
    ExampleOfPropertyChangingWork Object2(80);
    Object2.PropertyChanging_AddListener([](const int oldValue, const int newValue, bool& cancel) 
        {
            if (newValue == oldValue) 
            {
                cancel = true;
                std::cout << "—войство не изменено" << "\n";
            }
            else 
            {
                cancel = false;
                std::cout << "»зменение свойства с " << oldValue << " на " << newValue << "\n";
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
            std::cout << "Ёлемент " << value << " добавлен в коллекцию" << "\n";;
            break;
        case CollectionChangeAction::Removed:
            std::cout << "Ёлемент " << value << " под индексом " << index << " удален из коллекции" << "\n";;
            break;
        case CollectionChangeAction::ItemChanged:
            std::cout << "Ёлемент " << value << " под индексом " << index << " в коллекции изменен" << "\n";;
            break;
        }
        });
    Object3.Add(9);
    Object3.Add(0);
    Object3.Add(82);
    Object3.Change(10, 1);
    Object3.Remove(0);
}

//1) —оздать интерфейс
//INotifyPropertyChanged с методами AddInotifyPropertyChangedListener и RemoveNotifyPropertyChangedListener.¬ качестве аргументов методы 
// должны принимать функции, которые выполн€ютс€ в случае изменени€ свойств объекта, поддерживающего интерфейс
//
//2) —оздать интерфейс
//INotifyPropertyChanging с методами AddInotifyPropertyChangedListener и RemoveNotifyPropertyChangedListener.¬ качестве аргументов методы 
// должны принимать функции, которые выполн€ютс€ непосредственно перед изменением свойств объекта, поддерживающего интерфейс, с передачей 
// информации о том с какого на какое значение свойство мен€етс€ и с возможностью отмены данного изменени€
//
//3) —оздать интерфейс
//INotifyCollectionChanged с методами AddInotifyPropertyChangedListener и RemoveNotifyPropertyChangedListener.¬ качестве аргументов методы 
// должны принимать функции, которые выполн€ютс€ в случае изменени€ объекта - коллекции, поддерживающего интерфейс.—оздайте перечислитель со 
// статусами : Added, Removed, ItemChanged и передавайте соответствующее значение перечислител€ в качестве аргумента в подключаемые функции.
//
//4) —оздать классы, поддерживающие данные интерфейсы, подключитьс€ к данным интерфейсам† и продемонстрировать их работу в консольном приложении.