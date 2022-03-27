#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int board[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
int turn = 1, flag = 0;
int player, comp;

void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch, int pos);

// Created a COORD structure and filled in its members.
// Specifies the new position of the cursor to be set.
COORD coord = {0, 0}; // GLOBAL VARIABLE
// Center of axis is set to the top left cornor of the screen.

// Moves the cursor to a specified location on console.
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;

    // --> Obtained a handle to the console screen buffer.
    
    // Handle used to write to the console. Set the console cursor position then uses the 
    // handle and the coordinates we specified to place the blinking cursor in our command 
    // prompt.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int InitChoice;
    
    // Cleared the screen.
    system("CLS");

    std :: cout << "                                                           <--------  | Tic-Tac-Toe |  -------->              " << std ::endl;
    std :: cout << "\n\n                                                                    Press 0 to Play" << std ::endl;
    std :: cout << "                                                                  Press 1 for Instructions" << std ::endl;

    std :: cout << "\n\nEnter Your Choice (0 / 1)" << std ::endl;
    std :: cin >> InitChoice;
    std :: cout << "Your choice is " << InitChoice << std ::endl;
    
    // Cleared the screen
    system("cls"); 

    if (InitChoice == 0)
    {
        std :: cout << "                                                      <-------- | Starting the TIC TAC TOE 2021 EDITION | -------->  " << std ::endl;
        std :: cout << "                                                                          LOADING... PLEASE WAIT                 " << std ::endl;
        std :: cout << "\n\n\nPress Enter for MENU" << std :: endl;

        getch();
        
        // Cleared the screen
        system("cls");
        menu();

        getch();
    }

    else if (InitChoice == 1)
    {
        std :: cout << "                                                                      INSTRUCTIONS                           " << std ::endl;
        std :: cout << "  Hello User, We are glad to have you in our all new edition of this Tic-Tac-Toe game." << std ::endl;
        std :: cout << "  We have tried our best to keep our game simple and easy to play. " << std ::endl;

        std :: cin.get();

        std :: cout << "\n\n\n               | # STEPS |      " << std ::endl;
        std :: cout << " 1. Enter 0 to start the game & 1 to read the instructions." << std ::endl;
        std :: cout << " 2. Choose whether you want to play with O or X. " << std ::endl;
        std :: cout << " 3. If your choice is X then first chance is yours.   " << std ::endl;
        std :: cout << " 4. If your choice is O then Computer will make the first move.   " << std ::endl;
        std :: cout << " 5. Blank space numbers are as shown below. Use them to make a move.  " << std ::endl

                    << "\n\n" << std :: endl
                    << "               |        |         "
                    << "               |        |         " << std :: endl
                    << "        _ _1_ _| _ _2_ _| _ _3_ _ " << std :: endl
                    << "               |        |         " << std :: endl
                    << "               |        |         " << std :: endl
                    << "        _ _4_ _| _ _5_ _|  _ _6_ _" << std :: endl
                    << "               |        |         " << std :: endl
                    << "               |        |         " << std :: endl
                    << "           7   |    8   |     9   " << std :: endl;

           
        std :: cout << "Press Enter for MENU" << std :: endl;

        getch();
        
        menu();

    }

    else
    {
        system("CLS");
        std ::cout << "Invalid Input" << std ::endl;
        std ::cout << "\n\n PRESS ENTER FOR MENU" << std ::endl;
        
        getch();

        menu();

    }
}

void menu()
{
    int choice;

    // Cleared the screen
    system("cls");

    std :: cout << "\n1 : Play with X" << std :: endl;
    std :: cout << "\n2 : Play with O" << std :: endl;
    std :: cout << "\n3 : Exit" << std :: endl;

    std :: cout << "\nEnter your choice:>" << std :: endl;
    std :: cin >> choice;
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        player_first();
        break;
    case 2:
        player = 0;
        comp = 1;
        start_game();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }
}

int make2()
{
    if (board[5] == 2)
        return 5;
    if (board[2] == 2)
        return 2;
    if (board[4] == 2)
        return 4;
    if (board[6] == 2)
        return 6;
    if (board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if (board[1] == 2)
        return 1;
    if (board[3] == 2)
        return 3;
    if (board[7] == 2)
        return 7;
    if (board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{
    // p == 1 then X   
    // p == 0  then O

    int i;
    int check_val, pos;

    if (p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while (i <= 9) //row check
    {
        if (board[i] * board[i + 1] * board[i + 2] == check_val)
        {
            if (board[i] == 2)
                return i;
            if (board[i + 1] == 2)
                return i + 1;
            if (board[i + 2] == 2)
                return i + 2;
        }
        i += 3;
    }

    i = 1;
    while (i <= 3) //column check
    {
        if (board[i] * board[i + 3] * board[i + 6] == check_val)
        {
            if (board[i] == 2)
                return i;
            if (board[i + 3] == 2)
                return i + 3;
            if (board[i + 6] == 2)
                return i + 6;
        }
        i++;
    }

    if (board[1] * board[5] * board[9] == check_val)
    {
        if (board[1] == 2)
            return 1;
        if (board[5] == 2)
            return 5;
        if (board[9] == 2)
            return 9;
    }

    if (board[3] * board[5] * board[7] == check_val)
    {
        if (board[3] == 2)
            return 3;
        if (board[5] == 2)
            return 5;
        if (board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if (turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos;

    check_draw();
    draw_board();
    gotoxy(30, 18);
    std :: cout << "Your turn :>" << std :: endl;
    std :: cin >> pos;

    if (board[pos] != 2)
        player_first();

    if (pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30, 20);
        std :: cout << "Player Wins" << std :: endl;
        getch();
        exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}

void start_game()
{

    // p == 1 then X
    // p == 0 then O
    
    if (posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if (posswin(player))
        go(posswin(player));

    else if (make2())
        go(make2());

    else
        go(make4());
    draw_board();

    if (flag)
    {
        gotoxy(30, 20);
        std :: cout << "Computer wins" << std :: endl;

        getch();
    }
    else
        player_first();
}

void check_draw()
{
    if (turn > 9)
    {
        gotoxy(30, 20);
        std :: cout << "Game Draw" << std :: endl;
        getch();
        exit(0);
    }
}

void draw_board()
{
    int j;

    for (j = 9; j < 17; j++)
    {
        gotoxy(35, j);
        std :: cout << "|       |" << std :: endl;
    }
    gotoxy(28, 11);
    std :: cout << "-----------------------" << std :: endl;

    gotoxy(28, 14);
    std :: cout << "-----------------------" << std :: endl;

    for (j = 1; j < 10; j++)
    {
        if (board[j] == 3)
            put_X_O('X', j);
        else if (board[j] == 5)
            put_X_O('O', j);
    }
}

void put_X_O(char ch, int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if (m > 3)
    {
        while (m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if (pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while (pos)
        {
            x += 8;
            pos--;
        }
    }
    gotoxy(x, y);
    std :: cout << ch << std :: endl;
}
