#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include<fstream>
#include<sstream>
#include<cstdlib>

#define dinoPos 2
#define hurdlePos 74

using namespace std;

class draw;
class dino;
class obstacle;
class score;
class shop;
class headstart;
class speed;
class level;

int extra = 0;
int distancecovered = 0;
int score = 0;
int coins;
int headstart = 0;
int score_extra = 0;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoY;
int speed = 40;
int gameover = 0;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void read() {
    ifstream iff;
    iff.open("headstart.txt");
    iff >> headstart;
    iff.close();
}

void write() {
    ofstream off;
    off.open("headstart.txt", ios::trunc);
    off << headstart;
    off.close();
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) {
        size = 20;
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}


class draw
{
public:
    virtual void background()
    {
        gameover = 0;

        gotoxy(3, 2); cout << "SCORE : ";
        for (int i = 0; i < 79; i++) {
            gotoxy(1 + i, 1); cout << "ß";
            gotoxy(1 + i, 29); cout << "ß";
        }
    }
    void color()
    {
        if (extra >= 0 && extra < 20)
        {
            system("Color 07");
        }
        if (extra == 20)
        {
            system("Color 70");
        }
        if (extra == 40)
        {
            extra = 0;
        }
    }
};
class dino : public draw
{
public:

    void background(int jump = 0) {
        static int foot = 0;

        if (jump == 0)
            dinoY = 0;
        else if (jump == 2)
            dinoY--;
        else dinoY++;

        gotoxy(dinoPos, 19 - dinoY); cout << "                 ";
        gotoxy(dinoPos, 20 - dinoY); cout << "         ÜÛßÛÛÛÛÜ";
        gotoxy(dinoPos, 21 - dinoY); cout << "         ÛÛÛÛÛÛÛÛ";
        gotoxy(dinoPos, 22 - dinoY); cout << "         ÛÛÛÛÛßßß";
        gotoxy(dinoPos, 23 - dinoY); cout << " Û      ÜÛÛÛÛßßß ";
        gotoxy(dinoPos, 24 - dinoY); cout << " ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
        gotoxy(dinoPos, 25 - dinoY); cout << " ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
        gotoxy(dinoPos, 26 - dinoY); cout << "   ßÛÛÛÛÛÛÛß     ";
        gotoxy(dinoPos, 27 - dinoY);

        if (jump == 1 || jump == 2) {
            cout << "    ÛÛß ßÛ       ";
            gotoxy(2, 28 - dinoY);
            cout << "    ÛÜ   ÛÜ      ";
        }
        else if (foot == 0) {
            cout << "    ßÛÛß  ßßß    ";
            gotoxy(2, 28 - dinoY);
            cout << "      ÛÜ         ";
            foot = !foot;
        }
        else if (foot == 1) {
            cout << "     ßÛÜ ßÛ      ";
            gotoxy(2, 28 - dinoY);
            cout << "          ÛÜ     ";
            foot = !foot;
        }

        gotoxy(2, 29 - dinoY);
        if (jump == 0) {
            cout << "ßßßßßßßßßßßßßßßßß";
        }
        else {
            cout << "                ";
        }
        Sleep(speed);
    }
    void background2(int jump = 0)
    {
        static int foot = 0;

        if (jump == 0)
            dinoY = 0;
        else if (jump == 2)
            dinoY--;
        else dinoY++;
        distancecovered++;
        if (distancecovered % 10 == 0) {
            score++;
            score_extra++;
            extra++;
            gotoxy(11, 2); cout << "     ";
            gotoxy(11, 2); cout << score;
        }

        gotoxy(dinoPos, 17 - dinoY); cout << "                 ";
        gotoxy(dinoPos, 18 - dinoY); cout << "          Û    Û ";
        gotoxy(dinoPos, 19 - dinoY); cout << "         ÜÛß  ÜÛß";
        gotoxy(dinoPos, 20 - dinoY); cout << "         ÜÛßÛÛÛÛÜ";
        gotoxy(dinoPos, 21 - dinoY); cout << "         ÛÛÛÛÛÛÛÛ";
        gotoxy(dinoPos, 22 - dinoY); cout << " ÜÛß     ÛÛÛÛÛßßß";
        gotoxy(dinoPos, 23 - dinoY); cout << " Û      ÜÛÛÛÛßßß ";
        gotoxy(dinoPos, 24 - dinoY); cout << " ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
        gotoxy(dinoPos, 25 - dinoY); cout << " ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
        gotoxy(dinoPos, 26 - dinoY); cout << "   ßÛÛÛÛÛÛÛß     ";
        gotoxy(dinoPos, 27 - dinoY);

        if (jump == 1 || jump == 2) {
            cout << "    ÛÛß ßÛ       ";
            gotoxy(2, 28 - dinoY);
            cout << "    ÛÜ   ÛÜ      ";
        }
        else if (foot == 0) {
            cout << "    ßÛÛß  ßßß    ";
            gotoxy(2, 28 - dinoY);
            cout << "      ÛÜ         ";
            foot = !foot;
        }
        else if (foot == 1) {
            cout << "     ßÛÜ ßÛ      ";
            gotoxy(2, 28 - dinoY);
            cout << "          ÛÜ     ";
            foot = !foot;
        }

        gotoxy(2, 29 - dinoY);
        if (jump == 0) {
            cout << "ßßßßßßßßßßßßßßßßß";
        }
        else {
            cout << "                ";
        }
        Sleep(speed);
    }
};

class obstacle :public draw
{
public:

    static int plantX;

    void gameovers()
    {
        if ((plantX == 67 && dinoY < 3) || (plantX == 62 && dinoY < 3)) {
            extra = 0;
            score_extra = 0;
            speed = 40;
            gotoxy(36, 8); cout << "Game Over";
            _getch();
            gameover = 1;
        }
    }
    void gameovers2()
    {
        if ((plantX == 73 && dinoY < 1) || (plantX == 70 && dinoY < 1)) {
            extra = 0;
            score_extra = 0;
            speed = 40;
            gotoxy(36, 8); cout << "Game Over";
            _getch();
            gameover = 1;
        }
    }

    void background() override
    {
        gameovers();
        gotoxy(hurdlePos - plantX, 24); cout << "| | ";
        gotoxy(hurdlePos - plantX, 25); cout << "| | ";
        gotoxy(hurdlePos - plantX, 26); cout << "|_| ";
        gotoxy(hurdlePos - plantX, 27); cout << " |  ";
        gotoxy(hurdlePos - plantX, 28); cout << " |  ";

        plantX++;

        if (plantX == 73) {
            plantX = 0;
            score++;
            score_extra++;
            gotoxy(11, 2); cout << score;
        }
    }


    void backgroundobs2()
    {
        gameovers();
        gotoxy(hurdlePos - plantX, 24); cout << "| | | ";
        gotoxy(hurdlePos - plantX, 25); cout << "| | | ";
        gotoxy(hurdlePos - plantX, 26); cout << "||| ";
        gotoxy(hurdlePos - plantX, 27); cout << "  |   ";
        gotoxy(hurdlePos - plantX, 28); cout << "  |   ";

        plantX++;

        if (plantX == 73) {
            plantX = 0;
            score++;
            score_extra++;
            gotoxy(11, 2); cout << score;

        }
    }


    void backgroundobs3()
    {
        gameovers2();
        gotoxy(hurdlePos - plantX, 28); cout << " ||||| ";

        plantX++;

        if (plantX == 73) {
            plantX = 0;
            score++;
            score_extra++;
            gotoxy(11, 2); cout << score;

        }
    }

};
int obstacle::plantX = 0;


class speedy
{
public:
    void check_score()
    {
        if (distancecovered % 20 == 0)
        {
            speed--;
        }
    }
};
class shop
{
public:
    void menu()
    {
        do {
            ifstream readcoin("coins.txt");
            string line;
            (getline(readcoin, line));
            istringstream iss(line);
            iss >> coins;
            readcoin.close();
        up:  system("cls");
            gotoxy(30, 2); cout << "ßßßßß    ß    ß    ßßßßß    ßßßßß\n";
            gotoxy(30, 3); cout << "ß        ß    ß    ß   ß    ß   ß\n";
            gotoxy(30, 4); cout << "ßßßßß    ßßßßßß    ß   ß    ßßßßß\n";
            gotoxy(30, 5); cout << "    ß    ß    ß    ß   ß    ß    \n";
            gotoxy(30, 6); cout << "ßßßßß    ß    ß    ßßßßß    ß    \n";
            gotoxy(5, 8); cout << "COINS : " << coins << endl;
            gotoxy(5, 9); cout << "Head-Starts : " << headstart << endl;

            gotoxy(10, 12); cout << "Press 1 to Buy Head-starts. ( 5 COINS )";
            gotoxy(10, 13); cout << "Press 2 to Exit.\n";

            char op = _getch();

            if (op == '1') {


                if (coins >= 5) {
                    headstart++;
                    write();
                    read();
                    coins = coins - 5;
                    ofstream writecoin("coins.txt", ios::trunc);
                    writecoin << coins << endl;
                    writecoin.close();
                    goto up;
                }
                else {
                    gotoxy(10, 16); cout << "Unsufficient Coins\n";
                    Sleep(5000);
                    goto up;
                }
            }
            else if (op == '2') break;
        } while (0);

    }

};

class Headstart
{
public:
    void booster()
    {
        system("cls");
        gotoxy(40, 12); cout << "Do you want to use Head-Start ?";
        gotoxy(40, 13); cout << "Press H to use Head-Start";
        gotoxy(40, 14); cout << "Press S to Start without Head-Start";
        char op = _getch();

        if (op == 'H' || op == 'h') {
            for (int i = 0; i < 30; i = i + 5) {
                for (int y = 0; y < 120; y = y + 5) {
                    system("cls");
                    gotoxy(y, i); cout << "ßßßßß";

                }
            }
            score = 50;
            headstart--;
            write();
            read();
            return;
        }
        else if (op == 'S' || op == 's') return;
    }
};

class HIGHSCORE
{
public:

    void calculate_score(int score1)
    {
        ifstream inputFile("score_store.txt");
        int highScore;
        string line;
        if (getline(inputFile, line)) {
            istringstream iss(line);
            if (iss >> highScore) {
                if (score1 > highScore) {
                    cout << "Congratulations! You've set a new high score!" << endl;
                    cout << "New Score: " << score1 << endl;
                    cout << "Previous High Score: " << highScore << endl;
                    Sleep(800);
                    ofstream outputFile("score_store.txt", ios::trunc);
                    outputFile << score1;
                    outputFile.close();
                }
                else {
                    cout << "Your score is not higher than the current high score." << endl;
                    cout << "Current Score: " << score1 << endl;
                    cout << "Highest Score: " << highScore << endl;
                    Sleep(800);
                }
            }
            else {
                cerr << "Invalid data in the file." << endl;
            }
        }
        else
        {
            cout << "You have a made a new high score: " << score1 << endl;
            ofstream output("score_store.txt", ios::trunc);
            output << score1 << endl;
            output.close();
        }

        inputFile.close();
    }


    void calculate_coins()
    {
        ifstream readcoin("coins.txt");
        string line;
        if (getline(readcoin, line)) {
            istringstream iss(line);
            if (iss >> coins)
            {
                if (score % 20 == 0);
                {
                    coins++;
                    ofstream writecoin("coins.txt", ios::trunc);
                    writecoin << coins << endl;
                    writecoin.close();
                }
            }
        }
    }
    void display_coin()
    {
        ifstream readcoin("coins.txt");
        string line;
        if (getline(readcoin, line)) {
            istringstream iss(line);
            if (iss >> coins) {
                cout << "Coins: " << coins << endl;
                readcoin.close();

            }
        }
    }

};

class levels
{
    draw d1;
    dino d2;
    obstacle b1;
    speedy s1;
public:
    void easy()
    {
        obstacle::plantX = 0;
        gameover = 0;
        char ch;
        int i;
        d1.background();
        while (true)
        {
            while (!_kbhit()) {
                if (gameover == 1) {
                    return;
                }
                d2.background();
                b1.background();
            }

            ch = _getch();
            if (ch == 32) {
                i = 0;
                while (i < 12) {
                    d2.background(1);
                    b1.background();
                    i++;
                }
                while (i > 0) {
                    d2.background(2);
                    b1.background();
                    i--;
                }
            }
            else if (ch == 'p' || ch == 'P')
                _getch();
            else if (ch == 27)
                break;
        }
    }
    void medium()
    {
        obstacle::plantX = 0;
        gameover = 0;
        char ch;
        int i;
        d1.background();
        while (true)
        {
            while (!_kbhit()) {
                if (gameover == 1) {
                    return;
                }
                d2.background2();
                b1.backgroundobs2();
                s1.check_score();
                d1.color();
            }

            ch = _getch();
            if (ch == 32) {
                i = 0;
                while (i < 12) {
                    d1.color();
                    d2.background2(1);
                    b1.backgroundobs2();
                    s1.check_score();
                    i++;
                }
                while (i > 0) {
                    d1.color();
                    d2.background2(2);
                    b1.backgroundobs2();
                    s1.check_score();
                    i--;
                }
            }
            else if (ch == 'p' || ch == 'P')
                _getch();
            else if (ch == 27)
                break;
        }

    }

    void hard()
    {
        obstacle::plantX = 0;
        gameover = 0;
        speed = 30;
        char ch;
        int i;
        d1.background();
        while (true)
        {
            while (!_kbhit()) {
                if (gameover == 1) {
                    extra = 0;
                    return;
                }
                d2.background2();
                b1.backgroundobs3();
                s1.check_score();
                d1.color();
            }

            ch = _getch();
            if (ch == 32) {
                i = 0;
                while (i < 12) {
                    d1.color();
                    d2.background2(1);
                    b1.backgroundobs3();
                    s1.check_score();
                    i++;
                }
                while (i > 0) {
                    d1.color();
                    d2.background2(2);
                    b1.backgroundobs3();
                    s1.check_score();
                    i--;
                }
            }
            else if (ch == 'p' || ch == 'P')
                _getch();
            else if (ch == 27)
                break;
        }
    }

};
void instructions() {
    setcursor(0, 0);
    do {
        system("cls");
        gotoxy(30, 3); cout << " ------------------------------ \n";
        gotoxy(30, 4); cout << " |        INSTRUCTIONS        | \n";
        gotoxy(30, 5); cout << " ------------------------------ \n";
        gotoxy(10, 8); cout << "\n1. Avoid hurdles by jumping";
        gotoxy(10, 9); cout << "\n2. Press 'Spacebar' to jump ";
        gotoxy(10, 10); cout << "\n3. Press 'p' to pause game ";
        gotoxy(10, 11); cout << "\n4. Press 'Escape' to exit from game";
        gotoxy(10, 13); cout << "\n\nPress any key to go back to menu";
        _getch();
    } while (0);
}

#endif // SOURCE_H_INCLUDED



int main()
{
    shop s;
    levels l1;
    Headstart h;
    ifstream iff;
    iff.open("headstart.txt");
    iff >> headstart;
    iff.close();
    HIGHSCORE h1;

    do {
    here:
        system("cls");
        gotoxy(30, 2); cout << "ßßßßß    ßßßßß    ß   ß    ßßßßß";
        gotoxy(30, 3); cout << "ß   ß      ß      ßß  ß    ß   ß";
        gotoxy(30, 4); cout << "ß   ß      ß      ßßßßß    ß   ß";
        gotoxy(30, 5); cout << "ß   ß      ß      ß  ßß    ß   ß";
        gotoxy(30, 6); cout << "ßßßßß    ßßßßß    ß   ß    ßßßßß";
        gotoxy(10, 9); cout << "1. Start Game";
        gotoxy(10, 10); cout << "2. Instructions";
        gotoxy(10, 11); cout << "3. Shop";
        gotoxy(10, 12); cout << "4. Exit";
        gotoxy(10, 14); cout << "Select option: ";
        char op = _getch();

        if (op == '1') {
            system("cls");
            if (headstart > 0) { h.booster(); }
            system("cls");
            cout << "Press 1 if you want to play an easy state" << endl;
            cout << "Press 2 if you want to play medium state" << endl;
            cout << "Press 3 if you want to play hard state" << endl;
            char op = _getch();
            if (op == '1')
            {
                h1.calculate_coins();
                gameover = 0;
                system("cls");
                l1.easy();
                if (gameover == 1)
                {
                    extra = 0;
                    system("cls");
                    h1.calculate_score(score);
                    h1.display_coin();
                    Sleep(5000);
                    score = 0;
                    goto here;
                }
            }
            else if (op == '2')
            {
                h1.calculate_coins();
                gameover = 0;
                system("cls");
                l1.medium();
                if (gameover == 1)
                {
                    extra = 0;
                    system("cls");
                    h1.calculate_score(score);
                    h1.display_coin();
                    Sleep(5000);
                    score = 0;
                    goto here;
                }
            }
            else if (op == '3')
            {
                h1.calculate_coins();
                gameover = 0;
                system("cls");
                l1.hard();
                if (gameover == 1)
                {
                    extra = 0;
                    system("cls");
                    h1.calculate_score(score);
                    h1.display_coin();
                    Sleep(5000);
                    score = 0;
                    goto here;
                }
            }
        }
        else if (op == '2') instructions();
        else if (op == '3') s.menu();
        else if (op == '4') exit(0);

    } while (1);

    return 0;
}
