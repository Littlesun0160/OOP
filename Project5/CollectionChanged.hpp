#pragma once

enum class CollectionChangeAction
{
    Added,
    ItemChanged,
    Removed
};
class CollectionChanged
{
public:
    virtual void CollectionChanged_AddListener(std::function<void(int value, int index, CollectionChangeAction)> listener) {};
    virtual void CollectionChanged_RemoveListener(std::function<void(int value, int index, CollectionChangeAction)> listener) {};
};

class ExampleOfCollectionChangedWork : CollectionChanged
{
private:
    std::vector<int> collection;
    std::vector<std::function<void(int value, int index, CollectionChangeAction status)>> Listeners;
public:
    void Add(int Argument)
    {
        for (const auto& listener : Listeners) 
        {
            listener(Argument, collection.size(), CollectionChangeAction::Added);
        }
        collection.push_back(Argument);
    }
    void Change(int Argument, int Index)
    {
        if (Index<0 || Index>collection.size())
        {
            throw std::out_of_range("Неверный индекс");
        }
        for (const auto& listener : Listeners)
        {
            listener(collection[Index], Index, CollectionChangeAction::ItemChanged);
        }
        collection.at(Index) = Argument;
    }
    void Remove(int Index)
    {
        if (Index<0 || Index>collection.size())
        {
            throw std::out_of_range("Неверный индекс");
        }
        for (const auto& listener : Listeners)
        {
            listener(collection[Index], Index, CollectionChangeAction::Removed);
        }
        collection.erase(collection.begin() + Index);
    }
    
    void CollectionChanged_AddListener(std::function<void(int value, int index, CollectionChangeAction)> listener) override
    {
        Listeners.push_back(listener);
    }
    void CollectionChanged_RemoveListener(std::function<void(int value, int index, CollectionChangeAction)> listener) override
    {
        Listeners.pop_back();
    }
};