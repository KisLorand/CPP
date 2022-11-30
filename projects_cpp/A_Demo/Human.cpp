#include <iostream>

class Human
{
    private:
        int id;
    
    public:
        std::string name;
        std::string occupation;
        int age;

    Human(std::string name, std::string occupation, int id, int age)
    {
        this->name = name;
        this->occupation = occupation;
        this->age = age;
        this->id = id;
    }

    void speak(std::string message);

};

void Human::speak(std::string message) 
{
    std::cout << message << '\n';
}

int main()
{
    return 0;
}