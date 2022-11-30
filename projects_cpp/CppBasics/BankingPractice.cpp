#include <iostream>
#include <iomanip> // setprecision and fixed

int bankMenu();
void bankOptionSelect(int option, double balance);

void showBalance(double balance);
double deposit();
double withdraw();


int main()
{
    double balance = 420.69;
    int option = 0;
    do{
        option = bankMenu();
        bankOptionSelect(option, balance);
        
    } while (option != 4);
}

int bankMenu()
{
    int option;
    std::cout << "******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "******************\n"; 
    std::cout << "1. Show Balance\n"; 
    std::cout << "2. Deposit\n"; 
    std::cout << "3. Withdraw\n"; 
    std::cout << "4. Exit\n"; 
    std::cin >> option;

    //clear input buffer
    std::cin.clear();
    fflush(stdin);

    return option;
}

void bankOptionSelect(int option, double balance)
{
    switch(option)
    {
        case 1 :
            showBalance(balance);
            break;
        case 2 :
            std::cout << "Enter the amount you would like to deposit :\n"; 
            balance += deposit();
            showBalance(balance);
            break;
        case 3 :
            std::cout << "Enter the amount you would like to withdraw :\n"; 
            balance -= deposit();
            showBalance(balance);
            break;
        case 4 :
            std::cout << "Thanks for wisiting!\n";
            break;
        default:
            std::cout << "Invalid Option\n";
            break;
    }
}

void showBalance(double balance)
{
    std::cout << "Your balance is : $"<< std::setprecision(2) << std::fixed << balance << "\n";
    //std::setprecision(int) -> sets the number of decimal values
    //std::fixed -> display the set number (by setprecision)
} 

double deposit()
{
    double amount;
    std::cin >> amount;

    if (amount > 0)
    {
        return amount;
    } 
    else
    {
        std::cout << "Invalid Amount!!\n";
        return 0;
    }

    
}

double withdraw(double balance)
{
    double amount;
    std::cin >> amount;

    if (amount > balance)
    {
        std::cout << "Insufficient Funds\n";
        return 0;
    } 
    else if (amount < 0)
    {
        std::cout << "Invalid Amount!!\n";
        return 0;
    }
    return amount;
}