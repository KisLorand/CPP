#include <iostream>

// student -> identifier
struct student{
    std::string name;
    double gpa;
    bool enrolled;
};

void printStudent(student student);
void printStudentRef(student &student);

void changeName(student &student, std::string name);

int main()
{
    // struct => A structure that a group related variables under one name
    //          structs can contain many different datatypes (string, bolean, int)
    //          variables in a struct are knwon as "members"
    //          members can be accesed with " . " -> class member access operator

    // a "class", that oly has public properties, no methods
    student student1;
    student1.name = "Joze";
    student1.gpa = 3.4;
    student1.enrolled = true;

    std::cout << "address (main): "<< &student1 << '\n';
    // struct can be passed by reference or value copy
    printStudent(student1); //value

    printStudentRef(student1); //reference

    
    changeName(student1, "Joze Manuel");
    printStudentRef(student1);

    return 0;
}

//In the function it is a different obj, 
//  a copy of the struct with same values
void printStudent(student student)
{
    std::cout << "address (function): "<< &student << '\n';
    std::cout << student.name << '\n';
    std::cout << student.gpa << '\n';
    std::cout << student.enrolled << '\n';
}

// passing struct by reference, it will be the same struct
void printStudentRef(student &student)
{
    std::cout << "address (function, ref): "<< &student << '\n';
    std::cout << student.name << '\n';
    std::cout << student.gpa << '\n';
    std::cout << student.enrolled << '\n';
}


// change member
void changeName(student &student, std::string name)
{
    student.name = name;
} 

