#pragma once
#include <string>
#include <vector>

enum class Gender 
{ 
	Male, 
	Female 
};

template <typename Type>
class IRepository 
{
public:
    virtual void Add(Type* Item) {};
    virtual void Update(Type* ItemToUpdate, Type* NewItem) {};
    virtual void Delete(Type* Item) {};
    virtual std::vector<Type*> Get(const int& Index1, const int& Index2) { return {}; };
};

template <typename Type>
class MemoryRepository : public IRepository<Type>
{
protected:
    std::vector<Type*> m_Items;
public:
    void Add(Type* Item) override
    {
        m_Items.push_back(Item);
    }
    void Update(Type* ItemToUpdate, Type* NewItem) override
    {
        for (int i=0; i<m_Items.size(); i++)
        {
            if (m_Items[i] == ItemToUpdate)
            {
                m_Items[i] = NewItem;
            }
        }
    }
    void Delete(Type* Item) override
    {
        for (int i = 0; i < m_Items.size(); i++)
        {
            if (Item == m_Items[i])
            {
                m_Items.erase(m_Items.begin() + i);
                --i;
            }
        }
    }
    std::vector<Type*> Get(const int& Index1, const int& Index2) override
    {
        std::vector<Type*> InterItems{};
        if (Index1 >= m_Items.size() || Index1 < 0 || Index2 < Index1 || Index2 >= m_Items.size())
        {
            throw std::exception("out of range");
        }
        for (int i = Index1; i <= Index2; i++)
        {
            InterItems.push_back(m_Items[i]);
        }
        return InterItems;
    }
};




class User 
{
private:
    int m_Id;
    std::string m_Name;
    std::string m_Email;
    std::string m_Phone;
    std::string m_City;
    Gender m_Gender;
public:
    User(int Id, std::string& Name, std::string& Email, std::string& Phone, std::string& City, Gender gender)
    {
        m_Id = Id; m_Name = Name; m_Email = Email; m_Phone = Phone; m_City = City; m_Gender = gender;
    };
    User() = default;
    int getId() const
    {
        return m_Id;
    };
    std::string getName() const 
    {
        return m_Name; 
    }
    std::string getEmail() const 
    { 
        return m_Email; 
    }
    std::string getPhone() const 
    { 
        return m_Phone; 
    }
    std::string getCity() const 
    { 
        return m_City; 
    }
    Gender getGender() const 
    { 
        return m_Gender; 
    }

    void setId(int Id) 
    { 
        m_Id = Id; 
    }
    void setName(const std::string& Name) 
    { 
        m_Name = Name; 
    }
    void setEmail(const std::string& Email) 
    { 
        m_Email = Email; 
    }
    void setPhone(const std::string& Phone) 
    { 
        m_Phone = Phone; 
    }
    void setCity(const std::string& City) 
    { 
        m_City = City; 
    }
    void setGender(Gender gender) 
    { 
        m_Gender = gender; 
    }
    bool operator==(User& other) const 
    {
        if (m_Id == other.m_Id && m_Name == other.m_Name &&
            m_Email == other.m_Email && m_Phone == other.m_Phone &&
            m_City == other.m_City && m_Gender == other.m_Gender)
        {
            return true;
        }
        else return false;
    }
};

class IUserRepository : public IRepository<User> 
{
public:
    virtual User* getById(int Id) { return nullptr; };
    virtual User* getByName(const std::string& Name) { return nullptr; };
    virtual User* getByEmail(const std::string& Email) { return nullptr; };
    virtual std::vector<User*> getByCity(const std::string& city) { return {}; };
    virtual std::vector<User*> getByGender(Gender gender) { return {}; };
};

class MemoryUserRepository : public MemoryRepository<User>, public IUserRepository 
{
public:
    using MemoryRepository::Add;
    using MemoryRepository::Update;
    using MemoryRepository::Delete;
    using MemoryRepository::Get;
   
    User* getById(int Id) override 
    {
       for (User* User : MemoryUserRepository::m_Items) 
        {
            if (User->getId() == Id)
            {
                return User;
            }
        }
        return nullptr;
    }
    User* getByName(const std::string& Name) override 
    {
        for (User* User : MemoryUserRepository::m_Items)
        {
            if (User->getName() == Name) 
            {
                return User;
            }
        }
        return nullptr;
    }
    User* getByEmail(const std::string& Email) override 
    {
        for (User* User : MemoryUserRepository::m_Items)
        {
            if (User->getEmail() == Email)
            {
                return User;
            }
        }
        return nullptr;
    }
    std::vector<User*> getByCity(const std::string& City) override 
    {
        std::vector<User*> Intermediate{};
        for (User* User : MemoryUserRepository::m_Items)
        {
            if (User->getCity() == City) 
            {
                Intermediate.push_back(User);
            }
        }
        return Intermediate;
    }
    std::vector<User*> getByGender(Gender gender) override 
    {
        std::vector<User*> Intermediate{};
        for (User* User : MemoryUserRepository::m_Items)
        {
            if (User->getGender() == gender)
            {
                Intermediate.push_back(User);
            }
        }
        return Intermediate;
    }
};