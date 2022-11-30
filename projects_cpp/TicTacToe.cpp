#include <iostream>

void drawBoard(char *board, int size);
void playerMove(char *board, char player);
bool checkForWinner(char *board, int size, char player);

int main()
{
    // vector, has size
    char board[9] = {
        '.','.','.','.','.','.','.','.','.'
    };
    int size = sizeof(board)/sizeof(char);
    char player1 = 'X';
    char player2 = 'O';
    int turn = 1;
    bool isGameFinished = false;
    char currentPlayer;

    while (turn <= 9 && isGameFinished == false)
    {
        drawBoard(board, size);
        currentPlayer = (turn%2==1) ? player2 : player1; 
        playerMove(board, currentPlayer);
        isGameFinished = checkForWinner(board, size, currentPlayer);
        turn++;
    }

    drawBoard(board, size);
    std::cout << "Player " << currentPlayer << " has won." << '\n';
    
    return 0;
}

void drawBoard(char *board, int size)
{
    for (int i=0; i<size; i++)
    {
        std::cout << board[i] << ' ';
        if (i % 3 == 2)
        {
            std::cout <<'\n';
        }
    }
}

void playerMove(char *board, char player)
{
    int space = 0;
    bool validSpace = false;
    do{
       int row;
        std::cout << "Enter a row : " << std::endl;
        std::cin >> row;
        int col;
        std::cout << "Enter a col : " << std::endl;
        std::cin >> col;

        space = (row-1)*3 + col-1;
        if (space < 10 &&  space >= 0 && board[space] == '.')
        {
            validSpace = true;
        } 
        else
        {
            std::cout << "Invalid Coordinates \n";
        }

    } while (validSpace == false);
    
    board[space] = player; 
}



bool checkForWinner(char *board, int size, char player)
{
    if (board[0] == board[4] && board[4] == board[8] && board[0] == player)
    {
        return true;
    }
    for (int i=0; i<size/3; i++)
    {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] == player)
        {
            return true;
        }
    }
    for (int i=0; i<size/3; i++)
    {
        if (board[i] == board[i+3] && board[i+3] == board[i+3*2] && board[i] == player)
        {
            return true;
        }
    }
    return false;
}