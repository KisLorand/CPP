#include <iostream>

class Human
{
    private:
        int id;

    public:
        std::string name;
        std::string occupation;
        int age;

    Human()
    {
        id = 0;
    }

    Human(std::string name, std::string occupation, int id, int age)
    {
        this->name = name;
        this->occupation = occupation;
        this->age = age;
        this->id = id;
        // if the name ctor parameter is "x" or something not "name"
        // the "this->" can be leaved
        // name = HumanName;
    }
        void eat()
        {
            std::cout << "This person is eating.\n";
        }

        void printId()
        {
            std::cout << "Id: " << this->id << '\n';
        }


};


void printHumanData(Human &human);

int main()
{

    Human human1;

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 69;

    printHumanData(human1);
    human1.printId();

    human1.eat();

    std::cout << '\n';

    Human human2("Morty", "student", 1244, 15);
    printHumanData(human2);
    human2.printId();

    return 0;
}

void printHumanData(Human &human)
{
    std::cout << "Name: " << human.name << '\n';
    std::cout << "Age: " << human.age << '\n';
    std::cout << "Occupation: " << human.occupation << '\n';
}