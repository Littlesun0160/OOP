#include "Classes.hpp"
#include <iostream>


int main() 
{
    setlocale(LC_ALL, "Russian");
    //�������� ������ User
    std::string Name1 = "Apple";
    std::string Name2 = "Pineapple";
    std::string Email1 = "Apple123@mail.com";
    std::string Email2 = "Pine_Apple193@yandex.ru";
    std::string Phone1 = "89000000000";
    std::string Phone2 = "89111111111";
    std::string City = "Gorod";
    User* User1 = new User(00001, Name1, Email1, Phone1, City, Gender::Male);
    User* User2 = new User(00011, Name2, Email2, Phone2, City, Gender::Female);
    
    User* User3 = new User();
    User3->setId(0002); User3->setName("Banana"); User3->setEmail(Email1); User3->setPhone(Phone2); User3->setCity("NeGorod"); User3->setGender(Gender::Female);
    std::cout << "��� User1: " << User1->getName() << "\n" <<
        "��.����� User1: " << User1->getEmail() << "\n" <<
        "������� User1: " << User1->getPhone() << "\n";

    //�������� ������ MemoryUserRepository
    auto* userRepository = new MemoryUserRepository();
    userRepository->Add(User1);
    userRepository->Add(User2);
    userRepository->Add(User3);
    std::cout << userRepository->getByName("Banana")->getPhone() << "\n";
    std::cout << userRepository->getById(00001)->getName() << "\n";

    std::vector<User*> Inter = userRepository->getByGender(Gender::Female);
    for (int i=0; i<Inter.size(); i++)
    {
        std::cout << Inter[i]->getName() << " ";
    }
    std::cout << "\n";

    userRepository->Update(User2, User3);
    Inter = userRepository->Get(0, 2);
    for (int i = 0; i < Inter.size(); i++)
    {
        std::cout << Inter[i]->getName() << " ";
    }
    std::cout << "\n";

    userRepository->Delete(User1);
}


//1. ������� ��������� ��������� IRepository<T> :
//-void Add(T * item)
//- void Update(T * item)
//- void Delete(T * item)
//- std::vector<T*> Get(const std::string & where, const std::string & orderBy)
//2. ������� ����� User :
//-int mld;
//-std::string mName
//- std::string mEmail
//- std::string mPhone
//- std::string mCity
//- Gender(Male, Female) mGender
//�������� ������� � �������
//3. ������� ��������� UserRepository : public IRepository<User> :
//    -T * getByld(int id)
//    - T * getByname(const std::string & name)
//    - T * getByEmail(const std::string & city)
//    - std::vector<T*> getByCity(const std::string & city)
//    - std::vector<T*> getByGender(Gender gender)
//    4. ������� ����� MemoryRepository<T> : public IRepository<T>, ������� ��������� ������ � ��������� � ����������� ������
//    5. ������� ����� MemoryUserRepository : public MemoryRepository<T>, public IUserRepository ������� ��������� ������ � ��������� User � 
// ����������� ������
//    6. ������������������ ������ ���������� ��� ������ ����������, ���������, �������� � ��������� �������� User �� ����������� 
//MemoryUserRepository