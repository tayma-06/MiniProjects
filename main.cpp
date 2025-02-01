// Bismillahir Rahmanir Rahim
// Author : Khadiza Sultana
// Date   : 2/1/2025

#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

void showMenu();
void displayBoard(char matrix[][3]);
void playGame(char matrix[][3], bool singlePlayer);
void enterMove(char matrix[][3], char player, char playerChar);
bool checkWin(char matrix[][3], char player);
bool checkDraw(char matrix[][3]);

int main()
{
    srand(time(0));
    char matrix[3][3];
    int choice;
    while (true)
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            playGame(matrix, true);
            break;
        case 2:
            playGame(matrix, false);
            break;
        case 3:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid Choice! Please try again." << endl;
        }
    }
}
void showMenu()
{
    cout << "1. Single Player" << endl;
    cout << "2. Multiplayer" << endl;
    cout << "3. Quit" << endl;
}
void displayBoard(char matrix[][3])
{
    string a = "|", b = "--";
    for (int i = 0; i < 3; i++)
    {
        cout << "  " << b;
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a << " " << matrix[i][j] << " ";
        }
        cout << a << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "  " << b;
        }
        cout << endl;
    }
}
void playGame(char matrix[][3], bool singlePlayer)
{
    char playerX, playerO;
    int scoreX = 0, scoreO = 0;
    if (singlePlayer)
    {
        cout << "Enter an alphabet to represent Player X (Except A): ";
        cin >> playerX;
        playerO = 'A';
    }
    else
    {
        cout << "Enter an alphabet to represent Player X: ";
        cin >> playerX;
        cout << "Enter an alphabet to represent Player O: ";
        cin >> playerO;
    }

    char playAgain;
    while (true)
    {
        char num = '1';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = num++;
            }
        }

        int moves = 0;
        bool gameOver = false;
        while (!gameOver && moves < 9)
        {
            displayBoard(matrix);
            if (moves % 2 == 0)
            {
                enterMove(matrix, playerX, 'X');
                if (checkWin(matrix, 'X'))
                {
                    displayBoard(matrix);
                    cout << playerX << " wins!" << endl;
                    scoreX++;
                    gameOver = true;
                }
            }
            else
            {
                if (singlePlayer)
                {
                    cout << "AI's turn!" << endl;
                    char move;
                    while (true)
                    {
                        move = '0' + (rand() % 9 + 1);
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (matrix[i][j] == move)
                                {
                                    matrix[i][j] = 'O';
                                    goto endLoop;
                                }
                            }
                        }
                    }
                endLoop:
                    if (checkWin(matrix, 'O'))
                    {
                        displayBoard(matrix);
                        cout << "AI wins!" << endl;
                        scoreO++;
                        gameOver = true;
                    }
                }
                else
                {
                    enterMove(matrix, playerO, 'O');
                    if (checkWin(matrix, 'O'))
                    {
                        displayBoard(matrix);
                        cout << playerO << " wins!" << endl;
                        scoreO++;
                        gameOver = true;
                    }
                }
            }
            moves++;
            if (!gameOver && checkDraw(matrix))
            {
                displayBoard(matrix);
                cout << "It's a draw!" << endl;
                gameOver = true;
            }
        }
        cout << "Score: " << playerX << " " << scoreX << " - " << playerO << " " << scoreO << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y')
        {
            break;
        }
    }
}

void enterMove(char matrix[][3], char player, char playerChar)
{
    char move;
    while (true)
    {
        cout << player << ", enter move (1-9): ";
        cin >> move;
        if (move < '1' || move > '9')
        {
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == move)
                {
                    matrix[i][j] = playerChar;
                    return;
                }
            }
        }
        cout << "Cell already occupied! Try again." << endl;
    }
}

bool checkWin(char matrix[][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
            return true;
        if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player)
            return true;
    }
    if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
        return true;
    if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
        return true;
    return false;
}

bool checkDraw(char matrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                return false;
        }
    }
    return true;
}
