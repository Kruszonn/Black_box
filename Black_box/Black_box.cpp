//IGOR KRUSZEWSKI S198062 ELEKTRONIKA I TELEKOMUNIKACJA
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


struct pozycja
{
    int x;
    int y;
};
void usun(char**& plansza, char**& plansza_ukryta, int& ilosc_atom, int& punkty, int& rozmiar, int& guesses, int& pos_x, int& pos_y, bool& stop, int& numer, pozycja*& trzymaj_pozycje, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{
    ilosc_atom = 0;
    punkty = 0;
    rozmiar = 0;
    guesses = 0;
    pos_x = 0;
    pos_y = 0;
    for (int i = 0; i < numer; i++)
    {
        trzymaj_pozycje[0].x = 0;
        trzymaj_pozycje[0].y = 0;

    }
    for (int i = 0; i < numer; i++)
    {
        trzymaj_pozycje_Redo[0].x = 0;
        trzymaj_pozycje_Redo[0].y = 0;

    }
    numer = 0;
    numer_Redo = 0;
    stop = false;

    if (plansza != nullptr && plansza_ukryta != nullptr)
    {
        for (int i = 0; i < rozmiar + 2; i++)
        {
            delete[] plansza[i];
            delete[] plansza_ukryta[i];
        }
        delete[] plansza;
        delete[] plansza_ukryta;
        plansza = nullptr;
        plansza_ukryta = nullptr;

    }
}


void generuj(int& choice, char**& plansza, char**& plansza_ukryta, char& katy, int& rozmiar, int& ilosc_atom, char& obramowanie)
{
    switch (choice)
    {
    case 1:
        rozmiar = 5;
        break;
    case 2:
        rozmiar = 8;
        break;
    case 3:
        rozmiar = 10;
        break;
    default:
        cerr << ".";


    }
    plansza = new char* [rozmiar + 2];
    plansza_ukryta = new char* [rozmiar + 2];

    for (int i = 0; i < rozmiar + 2; i++) {
        plansza[i] = new char[rozmiar + 2];
        plansza_ukryta[i] = new char[rozmiar + 2];
    }
    for (int i = 0; i < rozmiar + 2; i++)
    {
        for (int j = 0; j < rozmiar + 2; j++)
        {
            if (i == 0 || i == rozmiar + 1 || j == 0 || j == rozmiar + 1)
            {
                plansza[i][j] = obramowanie;
                plansza_ukryta[i][j] = obramowanie;
            }
            else
            {
                plansza[i][j] = 220;
                plansza_ukryta[i][j] = 220;
            }

        }
    }
    plansza[0][0] = katy;
    plansza[0][rozmiar + 1] = katy;
    plansza[rozmiar + 1][0] = katy;
    plansza[rozmiar + 1][rozmiar + 1] = katy;
    plansza_ukryta[0][0] = katy;
    plansza_ukryta[0][rozmiar + 1] = katy;
    plansza_ukryta[rozmiar + 1][0] = katy;
    plansza_ukryta[rozmiar + 1][rozmiar + 1] = katy;

    srand(time(NULL));
    if (choice == 1)
    {
        int atomy = 3;
        while (atomy)
        {
            int x = rand() % 4 + 1;
            int y = rand() % 4 + 1;
            if (plansza_ukryta[x][y] != '0')
            {
                plansza_ukryta[x][y] = '0';
                ilosc_atom++;
                atomy--;
            }
        }
    }
    else if (choice == 2)
    {
        int atomy = 5;
        while (atomy)
        {
            int x = rand() % 5 + 1;
            int y = rand() % 5 + 1;
            if (plansza_ukryta[x][y] != '0')
            {
                plansza_ukryta[x][y] = '0';
                ilosc_atom++;
                atomy--;
            }
        }
    }
    else if (choice == 3)
    {
        int atomy = 7;
        while (atomy)
        {
            int x = rand() % 7 + 1;
            int y = rand() % 7 + 1;
            if (plansza_ukryta[x][y] != '0')
            {
                plansza_ukryta[x][y] = '0';
                ilosc_atom++;
                atomy--;
            }
        }
    }



}

void rysowanie_menu(int dlugosc, char bariera)
{
    for (int i = 0; i < dlugosc; ++i)
    {
        cout << bariera;
    }
    cout << endl;
}

void menu_start()
{
    cout << " ____    _                    _____   _  __    ____     ____   __   __    __  __   ______   _   _   _    _" << endl;
    cout << "|  _ \\  | |          /\\      / ____| | |/ /   |  _ \\   / __ \\  \\ \\ / /   |  \\/  | |  ____| | \\ | | | |  | |" << endl;
    cout << "| |_) | | |         /  \\    | |      | ' /    | |_) | | |  | |  \\ V /    | \\  / | | |__    |  \\| | | |  | |" << endl;
    cout << "|  _ <  | |        / /\\ \\   | |      |  <     |  _ <  | |  | |   > <     | |\\/| | |  __|   | . ` | | |  | |" << endl;
    cout << "| |_) | | |____   / ____ \\  | |____  | . \\    | |_) | | |__| |  / . \\    | |  | | | |____  | |\\  | | |__| |" << endl;
    cout << "|____/  |______| /_/    \\_\\  \\_____| |_|\\_\\   |____/   \\____/  /_/ \\_\\   |_|  |_| |______| |_| \\_|  \\____/" << endl;


}

void menu_powitalne()
{
    cout << " ____    _                    _____   _  __    ____     ____   __   __     _____   _____" << endl;
    cout << "|  _ \\  | |          /\\      / ____| | |/ /   |  _ \\   / __ \\  \\ \\ / /    / ____| |  __ \\      /\\" << endl;
    cout << "| |_) | | |         /  \\    | |      | ' /    | |_) | | |  | |  \\ V /    | |  __  | |__) |    /  \\" << endl;
    cout << "|  _ <  | |        / /\\ \\   | |      |  <     |  _ <  | |  | |   > <     | | |_ | |  _  /    / /\\ \\" << endl;
    cout << "| |_) | | |____   / ____ \\  | |____  | . \\    | |_) | | |__| |  / . \\    | |__| | | | \\ \\   / ____ \\" << endl;
    cout << "|____/  |______| /_/    \\_\\  \\_____| |_|\\_\\   |____/   \\____/  /_/ \\_\\    \\_____| |_|  \\_\\ /_/    \\_\\" << endl;


}
void wyswietl_p(char**& plansza, int& rozmiar, int& pos_x, int& pos_y, int& punkty, int& ilosc_atom, int& guesses, int& numer)
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(zmiana_koloru, 4);
    system("cls");
    char border = 220;
    menu_start();
    rysowanie_menu(108, border);
    cout << "RESTART:CAPS                   LEAVE GAME: Q                      HELP: H                          " << endl;
    cout << "            MOVE WITH:: W - UP,  S - DOWN,  A - LEFT, d - RIGHT                   " << endl;
    rysowanie_menu(108, border);
    SetConsoleTextAttribute(zmiana_koloru, 3);
    for (int i = 0; i < rozmiar + 2; i++)
    {
        cout << "                          ";
        for (int j = 0; j < rozmiar + 2; j++)
        {
            if (i == pos_y && j == pos_x && plansza[i][j])
            {
                SetConsoleTextAttribute(zmiana_koloru, 4);
                cout << setw(3) << "P";
                SetConsoleTextAttribute(zmiana_koloru, 3);
            }
            else if (plansza[i][j] == 'o')
            {
                SetConsoleTextAttribute(zmiana_koloru, 4);
                cout << setw(3) << plansza[i][j];
                SetConsoleTextAttribute(zmiana_koloru, 3);
            }
            else
            {
                cout << setw(3) << plansza[i][j];
            }

        }
        cout << endl;

    }
    SetConsoleTextAttribute(zmiana_koloru, 3);
    cout << endl;
    cout << "Aktualna pozycja gracza: x = " << pos_x << " y = " << pos_y << endl;
    cout << "|nieodkryte atomy: " << ilosc_atom << "|" << endl;
    cout << "|punkty: " << punkty << "|" << endl;
    if (guesses == ilosc_atom) {
        cout << "maks zaznaczonych pozychi atomow[" << ilosc_atom << "]..." << endl;
        cout << "odznacz: z" << endl;
    }
}


void wyswietl_klawisze()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    cout << "------------------CONTROLS--------------------" << endl;
    cout << "|                                             |" << endl;
    cout << "|                                             |" << endl;
    cout << "|return to main menu:                      q/Q|" << endl;
    cout << "|undo move:                                u/U|" << endl;
    cout << "|redo:                                     r/R|" << endl;
    cout << "|shoot:                                  space|" << endl;
    cout << "|place a guess position:                    o |" << endl;
    cout << "|end game:                                  k |" << endl;
    cout << "|show answer:                               p |" << endl;
    cout << "|help:                                      H |" << endl;
    cout << "|restart:                                 caps|" << endl;


}

void menu_gry(bool& stop, char**& plansza, char**& plansza_ukryta, char& katy, int& rozmiar, int& ilosc_atom, int& pos_x, int& pos_y, int& punkty, int& guesses, char& obramowanie, int& numer)
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(zmiana_koloru, 4);
    menu_powitalne();
    rysowanie_menu(90, 220);
    cout << "                       IGOR KRUSZEWSKI   198062   PROJEKT PODSTAWY PROGRAMOWANIA 2023/24                          " << endl;
    cout << "                                                                                                                  " << endl;
    cout << "                                           WYBIERS POZIOM TRUDNOSCI                                               " << endl;
    cout << "1. Latwy: Plansza 5x5 z trzema atomami                                                                            " << endl;
    cout << "  2. Sredni: Plansza 8x8 z 5-oma atomami                                                                            " << endl;
    cout << "  3. Trudny: Plansza 10x10 z 8-oma atomami                                                                          " << endl;
    rysowanie_menu(90, 220);
    int choice;
    stop = true;
    if (cin >> choice)
    {
        SetConsoleTextAttribute(zmiana_koloru, 7);

        switch (choice)
        {
        case 1:
            generuj(choice, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, obramowanie);
            wyswietl_p(plansza, rozmiar, pos_x, pos_y, punkty, ilosc_atom, guesses, numer);
            break;
        case 2:
            generuj(choice, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, obramowanie);
            wyswietl_p(plansza, rozmiar, pos_x, pos_y, punkty, ilosc_atom, guesses, numer);
            break;
        case 3:
            generuj(choice, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, obramowanie);
            wyswietl_p(plansza, rozmiar, pos_x, pos_y, punkty, ilosc_atom, guesses, numer);
            break;
        default:
            menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
            break;
        }
    }
    else if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
    }
}

void pomoc_h(char**& plansza, char**& plansza_ukryta, int& rozmiar, int& ilosc_atom, int& pos_x, int& pos_y, int& punkty, int& guesses, int& numer)
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < rozmiar + 2; i++)
    {
        for (int j = 0; j < rozmiar + 2; j++)
        {
            if (plansza_ukryta[i][j] == '0')
            {
                SetConsoleTextAttribute(zmiana_koloru, 4);
                cout << setw(3) << plansza_ukryta[i][j];
                SetConsoleTextAttribute(zmiana_koloru, 3);
            }
            else
            {
                cout << setw(3) << plansza_ukryta[i][j];

            }

        }
        cout << endl;

    }
    cout << endl;
    cout << "Nieodkryte atomy: " << ilosc_atom;
    Sleep(2000);
    wyswietl_p(plansza, rozmiar, pos_x, pos_y, punkty, ilosc_atom, guesses, numer);

}

void zaznacz_atom(char**& plansza, int& guesses, int& pos_x, int& pos_y, char& obramowanie, char& katy, int& rozmiar)
{
    if (guesses < rozmiar - 2)
    {
        if (plansza[pos_y][pos_x] != obramowanie && plansza[pos_y][pos_x] != 'o' && plansza[pos_y][pos_x] != katy)
        {
            plansza[pos_y][pos_x] = 'o';
            guesses++;
        }
    }
}
void odznacz_atom(char**& plansza, int& pos_x, int& pos_y, int& guesses)
{
    if (plansza[pos_y][pos_x] == 'o')
    {
        plansza[pos_y][pos_x] = 220;
        guesses--;
    }
}

void strzel_promien_(char**& plansza, char**& plansza_ukryta, int& pos_x, int& pos_y, int& rozmiar, char& katy, char& oddanie_strzalu)
{
    if (pos_x == 0 && pos_y != 0 && pos_y != rozmiar + 1)
    {
        bool sukces = false;
        for (int i = 0; i < rozmiar + 1; i++)
        {
            if (plansza_ukryta[pos_y][i] == '0')
            {
                plansza[pos_y][0] = 'H';
                plansza_ukryta[pos_y][0] = 'H';
                if (plansza_ukryta[pos_y][i] == '0' && plansza_ukryta[pos_y][i - 1] == 'H')
                {
                    if (plansza_ukryta[pos_y + 1][i] != '0' && plansza_ukryta[pos_y + 1][0] != katy && plansza_ukryta[pos_y + 1][0] == '@')
                    {
                        plansza[pos_y + 1][0] = 'R';
                        plansza_ukryta[pos_y + 1][0] = 'R';

                    }
                    if (plansza_ukryta[pos_y - 1][i] != '0' && plansza_ukryta[pos_y - 1][0] != katy && plansza_ukryta[pos_y - 1][0] == '@')
                    {
                        plansza[pos_y - 1][0] = 'R';
                        plansza_ukryta[pos_y - 1][0] = 'R';
                    }



                }
                sukces = true;

            }

        }
        if (!sukces)
        {
            if (plansza[pos_y][0] != 'H' && plansza[pos_y][0] != oddanie_strzalu && plansza[pos_y][0] != 'R')
            {
                plansza[pos_y][0] = oddanie_strzalu;
                plansza_ukryta[pos_y][0] = oddanie_strzalu;
            }
            if (plansza[pos_y][rozmiar + 1] != 'H' && plansza[pos_y][rozmiar + 1] != oddanie_strzalu && plansza[pos_y][rozmiar + 1] != 'R')
            {
                plansza[pos_y][rozmiar + 1] = oddanie_strzalu;
                plansza_ukryta[pos_y][rozmiar + 1] = oddanie_strzalu;
            }
            oddanie_strzalu++;
        }
    }
    else if (pos_x == rozmiar + 1 && pos_y != 0 && pos_y != rozmiar + 1)
    {
        bool sukces = false;
        for (int i = rozmiar + 1; i > 0; i--)
        {
            if (plansza_ukryta[pos_y][i] == '0')
            {
                plansza[pos_y][rozmiar + 1] = 'H';
                plansza_ukryta[pos_y][rozmiar + 1] = 'H';
                if (plansza_ukryta[pos_y][i] == '0' && plansza_ukryta[pos_y][i + 1] == 'H')
                {
                    if (plansza_ukryta[pos_y + 1][i] != 0 && plansza_ukryta[pos_y + 1][rozmiar + 1] != katy && plansza_ukryta[pos_y + 1][rozmiar + 1] == '@')
                    {
                        plansza[pos_y + 1][rozmiar + 1] = 'R';
                        plansza_ukryta[pos_y + 1][rozmiar + 1] = 'R';
                    }
                    if (plansza_ukryta[pos_y - 1][i] != 0 && plansza_ukryta[pos_y - 1][rozmiar + 1] != katy && plansza_ukryta[pos_y - 1][rozmiar + 1] == '@')
                    {
                        plansza[pos_y - 1][rozmiar + 1] = 'R';
                        plansza_ukryta[pos_y - 1][rozmiar + 1] = 'R';
                    }

                }
                sukces = true;
            }

        }
        if (!sukces)
        {
            if (plansza[pos_y][rozmiar + 1] != 'H' && plansza[pos_y][rozmiar + 1] != oddanie_strzalu && plansza[pos_y][rozmiar + 1] != 'R')
            {
                plansza[pos_y][rozmiar + 1] = oddanie_strzalu;
                plansza_ukryta[pos_y][rozmiar + 1] = oddanie_strzalu;

            }
            if (plansza[pos_y][0] != 'H' && plansza[pos_y][0] != oddanie_strzalu && plansza[pos_y][0] != 'R')
            {
                plansza[pos_y][0] = oddanie_strzalu;
                plansza_ukryta[pos_y][0] = oddanie_strzalu;

            }
            oddanie_strzalu++;
        }

    }
    else if (pos_y == 0 && pos_x != 0 && pos_x != rozmiar + 1)
    {
        bool sukces = false;
        for (int j = 0; j < rozmiar + 2; j++)
        {
            if (plansza_ukryta[j][pos_x] == '0')
            {
                plansza[0][pos_x] = 'H';
                plansza_ukryta[0][pos_x] = 'H';
                if (plansza_ukryta[j][pos_x] == '0' && plansza_ukryta[j - 1][pos_x] == 'H')
                {
                    if (plansza_ukryta[j][pos_x + 1] != '0' && plansza_ukryta[0][pos_x + 1] != katy && plansza_ukryta[0][pos_x + 1] == '@')
                    {
                        plansza[0][pos_x + 1] = 'R';
                        plansza_ukryta[0][pos_x + 1] = 'R';
                    }
                    if (plansza_ukryta[j][pos_x - 1] != '0' && plansza_ukryta[0][pos_x - 1] != katy && plansza_ukryta[0][pos_x - 1] == '@')
                    {
                        plansza[0][pos_x - 1] = 'R';
                        plansza_ukryta[0][pos_x - 1] = 'R';
                    }

                }
                sukces = true;
            }


        }
        if (!sukces)
        {
            if (plansza[0][pos_x] != 'H' && plansza[0][pos_x] != oddanie_strzalu && plansza[0][pos_x] != 'R')
            {
                plansza[0][pos_x] = oddanie_strzalu;
                plansza_ukryta[0][pos_x] = oddanie_strzalu;
            }
            if (plansza[rozmiar + 1][pos_x] != 'H' && plansza[rozmiar + 1][pos_x] != oddanie_strzalu && plansza[0][pos_x] != 'R')
            {
                plansza[rozmiar + 1][pos_x] = oddanie_strzalu;
                plansza_ukryta[rozmiar + 1][pos_x] = oddanie_strzalu;

            }
            oddanie_strzalu++;




        }
    }
    else if (pos_y == rozmiar + 1 && pos_x != 0 && pos_x != rozmiar + 1)
    {
        bool sukces = false;
        for (int j = rozmiar + 1; j > 0; j--)
        {
            if (plansza_ukryta[j][pos_x] == '0')
            {
                plansza[rozmiar + 1][pos_x] = 'H';
                plansza_ukryta[rozmiar + 1][pos_x] = 'H';
                if (plansza_ukryta[j][pos_x] == '0' && plansza_ukryta[j + 1][pos_x] == 'H')
                {
                    if (plansza_ukryta[j][pos_x + 1] != '0' && plansza_ukryta[rozmiar + 1][pos_x + 1] != katy && plansza_ukryta[rozmiar + 1][pos_x + 1] == '@')
                    {
                        plansza[rozmiar + 1][pos_x + 1] = 'R';
                        plansza_ukryta[rozmiar + 1][pos_x + 1] = 'R';
                    }
                    if (plansza_ukryta[j][pos_x - 1] != '0' && plansza_ukryta[rozmiar + 1][pos_x - 1] != katy && plansza_ukryta[rozmiar + 1][pos_x + 1] == '@')
                    {
                        plansza[rozmiar + 1][pos_x - 1] = 'R';
                        plansza_ukryta[rozmiar + 1][pos_x - 1] = 'R';
                    }



                }
                sukces = true;
            }

        }
        if (!sukces)
        {
            if (plansza[rozmiar + 1][pos_x] != 'H' && plansza[rozmiar + 1][pos_x] != oddanie_strzalu && plansza[rozmiar + 1][pos_x] != 'R')
            {
                plansza[rozmiar + 1][pos_x] = oddanie_strzalu;
                plansza_ukryta[rozmiar + 1][pos_x] = oddanie_strzalu;
            }
            if (plansza[0][pos_x] != 'H' && plansza[0][pos_x] != oddanie_strzalu && plansza[0][pos_x] != 'R')
            {
                plansza[0][pos_x] = oddanie_strzalu;
                plansza_ukryta[0][pos_x] = oddanie_strzalu;
            }
            oddanie_strzalu++;


        }
    }

}

void restart(char**& plansza, char**& plansza_ukryta, int& rozmiar, char& obramowanie, int& punkty, int& pos_x, int& pos_y, int& guesses, char& oddanie_strzalu, char& katy, int& numer, pozycja*& trzymaj_pozycje, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{
    system("cls");
    for (int i = 0; i < rozmiar + 2; i++)
    {
        for (int j = 0; j < rozmiar + 2; j++)
        {
            if (plansza[i][j] == 'H' || plansza[i][j] == 'R' || plansza[i][j] == '1' || plansza[i][j] == '2' || plansza[i][j] == '3' || plansza[i][j] == '4' || plansza[i][j] == '5' || plansza[i][j] == '6' || plansza[i][j] == '7' || plansza[i][j] == '8' || plansza[i][j] == '9')
            {
                plansza[i][j] = obramowanie;
                plansza_ukryta[i][j] = obramowanie;
            }
            else if (plansza[i][j] != obramowanie && plansza[i][j] != katy)
            {
                plansza[i][j] = 220;
            }
        }
    }
    punkty = 0;
    pos_x = 0;
    pos_y = 0;
    guesses = 0;
    for (int i = 0; i < numer; i++)
    {
        trzymaj_pozycje[0].x = 0;
        trzymaj_pozycje[0].y = 0;
    }
    for (int i = 0; i < numer; i++)
    {
        trzymaj_pozycje_Redo[0].x = 0;
        trzymaj_pozycje_Redo[0].y = 0;
    }
    numer = 0;
    numer_Redo = 0;
}

void ekran_wygranej()
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(zmiana_koloru, 10);
    cout << " __          __ __     __   _____   _____               _        ______    _____ " << endl;
    cout << " \\ \\        / / \\ \\   / /  / ____| |  __ \\      /\\     | |      |  ____|  / ____|" << endl;
    cout << "  \\ \\  /\\  / /   \\ \\_/ /  | |  __  | |__) |    /  \\    | |      | |__    | (___   " << endl;
    cout << "   \\ \\/  \\/ /     \\   /   | | |_ | |  _  /    / /\\ \\   | |      |  __|    \\___ \\  " << endl;
    cout << "    \\  /\\  /       | |    | |__| | | | \\ \\   / ____ \\  | |____  | |____   ____) |" << endl;
    cout << "     \\/  \\/        |_|     \_____| |_|  \\_\\ /_/    \\_\\ |______| |______| |_____/" << endl;
    SetConsoleTextAttribute(zmiana_koloru, 4);

}
void ekran_przegranej()
{
    cout << "_____    _____    ______  ______    _____   _____               _        ______    _____ " << endl;
    cout << "|  __ \\  |  __ \\  |___  / |  ____|  / ____| |  __ \\      /\\     | |      |  ____|  / ____|" << endl;
    cout << "| |__) | | |__) |    / /  | |__    | |  __  | |__) |    /  \\    | |      | |__    | (___" << endl;
    cout << "|  ___/  |  _  /    / /   |  __|   | | |_ | |  _  /    / /\\ \\   | |      |  __|    \\___ \\" << endl;
    cout << "| |      | | \\ \\   / /__  | |____  | |__| | | | \\ \\   / ____ \\  | |____  | |____   ____) |" << endl;
    cout << "|_|      |_|  \\_\\ /_____| |______|  \\_____| |_|  \\_\\ /_/    \\_\\ |______| |______| |_____/" << endl;


}

void koniec_ekran_p()
{
    cout << "_  __   ____    _   _   _____   ______    _____" << endl;
    cout << "| |/ /  / __ \ | \ | | |_   _| |  ____|  / ____| " << endl;
    cout << "| ' /  | |  | | |  \| |   | |   | |__    | | " << endl;
    cout << "| < | |  | | | . ` |   | |   |  __|   | |" << endl;
    cout << "| . \  | |__| | | |\ | _| |_  | |____  | |____" << endl;
    cout << "| _ | \_\  \____/  |_ | \_| |_____| |______ | \_____ |" << endl;


}
void ekran_koniec(char**& plansza, char**& plansza_ukryta, int& rozmiar, int& punkty, int& guesses, int& ilosc_atom, int& pos_x, int& pos_y, bool& stop, char& obramowanie, char& katy, int& numer, pozycja*& trzymaj_pozycje, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    char border = 219;
    for (int i = 0; i < rozmiar + 2; i++)
    {
        for (int j = 0; j < rozmiar + 2; j++)
            if (plansza[i][j] == 'o' && plansza_ukryta[i][j] == '0')
            {

                plansza_ukryta[i][j] = 'O';
                punkty++;
            }
            else if (plansza[i][j] == 'o' && plansza_ukryta[i][j] == 220)
            {
                plansza_ukryta[i][j] = 'X';
            }
            else if (plansza_ukryta[i][j] == '0' && plansza[i][j] == 220)
            {
                plansza_ukryta[i][j] == '0';
            }
    }

    SetConsoleTextAttribute(zmiana_koloru, 4);
    rysowanie_menu(50, 220);
    koniec_ekran_p();
    rysowanie_menu(50, 220);


    SetConsoleTextAttribute(zmiana_koloru, 3);
    for (int i = 0; i < rozmiar + 2; i++)
    {
        cout << "                          ";
        for (int j = 0; j < rozmiar + 2; j++)
        {

            if (plansza_ukryta[i][j] == '0' || plansza_ukryta[i][j] == 'X' || plansza_ukryta[i][j] == 'O')
            {
                SetConsoleTextAttribute(zmiana_koloru, 4);

                cout << setw(3) << plansza_ukryta[i][j];
                SetConsoleTextAttribute(zmiana_koloru, 3);
            }
            else
            {

                cout << setw(3) << plansza_ukryta[i][j];

            }

        }
        cout << endl;
    }
    cout << endl;
    guesses = 0;
    char wybor;
    do
    {
        cin >> wybor;
    } while (wybor != 'q' && wybor != 'Q' && wybor != 'e' && wybor != 'E');
    switch (wybor)
    {
    case 'q':
    case 'Q':
        system("cls");
        usun(plansza, plansza_ukryta, ilosc_atom, punkty, rozmiar, guesses, pos_x, pos_y, stop, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
        break;
    case 'e':
    case 'E':
        exit(0);
    default:
        break;

    }


}



void zakoncz(char**& plansza, char**& plansza_ukryta, int& rozmiar, int& punkty, int& guesses, int& ilosc_atom, int& pos_x, int& pos_y, bool& stop, char& obramowanie, char& katy, int& numer, pozycja*& trzymaj_pozycje, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{
    HANDLE zmiana_koloru = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    char border = 219;
    for (int i = 0; i < rozmiar + 2; i++)
    {
        for (int j = 0; j < rozmiar + 2; j++)
            if (plansza[i][j] == 'o' && plansza_ukryta[i][j] == '0')
            {

                plansza_ukryta[i][j] = 'O';
                punkty++;
            }
            else if (plansza[i][j] == 'o' && plansza_ukryta[i][j] != '0')
            {
                plansza_ukryta[i][j] = 'X';
            }
            else if (plansza_ukryta[i][j] == 'o' && plansza[i][j] == 220)
            {
                plansza_ukryta[i][j] == '0';
            }
    }

    SetConsoleTextAttribute(zmiana_koloru, 4);
    if (punkty == ilosc_atom)
    {
        ekran_wygranej();
        cout << endl;
        rysowanie_menu(90, 220);

        cout << "Zdobyte punkty: " << punkty << "                                                     nowa gra: q   " << endl;
        cout << "Ilosc atomow: " << ilosc_atom << "                                                       zakoncz gre: e   " << endl;
        rysowanie_menu(90, 220);

    }
    else if (punkty < ilosc_atom)
    {
        ekran_przegranej();
        cout << endl;
        rysowanie_menu(90, 220);
        cout << "Zdobyte punkty: " << punkty << "                                                        nowa gra: q   " << endl;
        cout << "Ilosc atomow: " << ilosc_atom << "                                                         zakoncz gre: e   " << endl;
        rysowanie_menu(90, 220);


    }


    SetConsoleTextAttribute(zmiana_koloru, 3);
    for (int i = 0; i < rozmiar + 2; i++)
    {
        cout << "                          ";
        for (int j = 0; j < rozmiar + 2; j++)
        {

            if (plansza_ukryta[i][j] == '0' || plansza_ukryta[i][j] == 'X' || plansza_ukryta[i][j] == 'O')
            {
                SetConsoleTextAttribute(zmiana_koloru, 4);

                cout << setw(3) << plansza_ukryta[i][j];
                SetConsoleTextAttribute(zmiana_koloru, 3);
            }
            else
            {

                cout << setw(3) << plansza_ukryta[i][j];

            }

        }
        cout << endl;
    }
    cout << endl;
    guesses = 0;
    char wybor;
    do
    {
        cin >> wybor;
    } while (wybor != 'q' && wybor != 'Q' && wybor != 'e' && wybor != 'E');
    switch (wybor)
    {
    case 'q':
    case 'Q':
        system("cls");
        usun(plansza, plansza_ukryta, ilosc_atom, punkty, rozmiar, guesses, pos_x, pos_y, stop, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
        break;
    case 'e':
    case 'E':
        exit(0);
    default:
        break;

    }


}

void undo(pozycja*& trzymaj_pozycje, int& pos_x, int& pos_y, int& numer)
{
    ++numer;
    trzymaj_pozycje[numer].x = pos_x;
    trzymaj_pozycje[numer].y = pos_y;



}
void undo_klik(pozycja*& trzymaj_pozycje, int& pos_x, int& pos_y, char**& plansza, int& numer, int& numer_licznik, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{

    if (numer_licznik == numer || (trzymaj_pozycje[0].x == pos_x && trzymaj_pozycje[0].y == pos_y))
    {
        cerr << "Nie mozna wykonac więcej cofniec " << endl;
        numer_licznik--;

    }
    else
    {

        pos_x = trzymaj_pozycje[numer - 1].x;
        pos_y = trzymaj_pozycje[numer - 1].y;
        numer--;
        ++numer_licznik;


    }

}

void redo(pozycja*& trzymaj_pozycje, pozycja*& trzymaj_pozycje_Redo, int& pos_x, int& pos_y, int& numer, int& numer_licznik, int& numer_Redo)
{
    ++numer_Redo;
    trzymaj_pozycje_Redo[numer_Redo].x = pos_x;
    trzymaj_pozycje_Redo[numer_Redo].y = pos_y;

}
void redo_klik(pozycja*& trzymaj_pozycje_Redo, int& pos_x, int& pos_y, int& numer_Redo)
{

    if (numer_Redo == 0 || (trzymaj_pozycje_Redo[0].x == pos_x && trzymaj_pozycje_Redo[0].y == pos_y))
    {
        cerr << "Nie mozna wykonac ruchu wstecz";
    }
    else
    {
        pos_x = trzymaj_pozycje_Redo[numer_Redo].x;
        pos_y = trzymaj_pozycje_Redo[numer_Redo].y;
        numer_Redo--;

    }
}




void input_sprawdz(char input, char**& plansza, char**& plansza_ukryta, int& rozmiar, int& ilosc_atom, int& pos_x, int& pos_y, int& punkty, int& guesses, bool& stop, char& katy, char& obramowanie, char& oddanie_strzalu, pozycja*& trzymaj_pozycje, int& numer, int& numer_licznik, pozycja*& trzymaj_pozycje_Redo, int& numer_Redo)
{
    switch (input)
    {
    case 'h':
    case 'H':
        pomoc_h(plansza, plansza_ukryta, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, numer);
        break;
    case 'q':
    case 'Q':
        usun(plansza, plansza_ukryta, ilosc_atom, punkty, rozmiar, guesses, pos_x, pos_y, stop, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
        numer = 0;
        break;
    case 'w':
    case 'W':
        if (pos_y > 0)
        {
            --pos_y;
            undo(trzymaj_pozycje, pos_x, pos_y, numer);
        }
        break;
    case 's':
    case 'S':
        if (pos_y < rozmiar + 1)
        {
            ++pos_y;
            undo(trzymaj_pozycje, pos_x, pos_y, numer);
            numer_Redo = 0;
        }
        break;
    case 'a':
    case 'A':
        if (pos_x > 0)
        {
            --pos_x;
            undo(trzymaj_pozycje, pos_x, pos_y, numer);
            numer_Redo = 0;
        }
        break;
    case 'd':
    case 'D':
        if (pos_x < rozmiar + 1)
        {
            ++pos_x;
            undo(trzymaj_pozycje, pos_x, pos_y, numer);
            numer_Redo = 0;
        }
        break;
    case 'o':
    case 'O':
        zaznacz_atom(plansza, guesses, pos_x, pos_y, obramowanie, katy, rozmiar);
        break;
    case 'z':
    case 'Z':
        odznacz_atom(plansza, pos_x, pos_y, guesses);
        break;
    case 'l':
    case 'L':
        restart(plansza, plansza_ukryta, rozmiar, obramowanie, punkty, pos_x, pos_y, guesses, oddanie_strzalu, katy, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        break;
    case 'K':
    case 'k':
        zakoncz(plansza, plansza_ukryta, rozmiar, punkty, guesses, ilosc_atom, pos_x, pos_y, stop, obramowanie, katy, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        break;
    case ' ':
        if (plansza[pos_y][pos_x] == obramowanie)
        {
            strzel_promien_(plansza, plansza_ukryta, pos_x, pos_y, rozmiar, katy, oddanie_strzalu);
            break;
        }
        break;
    case 'u':
    case 'U':
        redo(trzymaj_pozycje, trzymaj_pozycje_Redo, pos_x, pos_y, numer, numer_licznik, numer_Redo);
        undo_klik(trzymaj_pozycje, pos_x, pos_y, plansza, numer, numer_licznik, trzymaj_pozycje_Redo, numer_Redo);
        break;
    case 'r':
    case 'R':

        redo_klik(trzymaj_pozycje_Redo, pos_x, pos_y, numer_Redo);
        break;
    case 'p':
    case 'P':
        ekran_koniec(plansza, plansza_ukryta, rozmiar, punkty, guesses, ilosc_atom, pos_x, pos_y, stop, obramowanie, katy, numer, trzymaj_pozycje, trzymaj_pozycje_Redo, numer_Redo);
        break;


    }
}


int main()
{
    char** plansza = nullptr;
    char** plansza_ukryta = nullptr;
    int rozmiar = 0;
    int ilosc_atom = 0;
    char oddanie_strzalu = 49;
    int punkty = 0;
    int pos_x = 0;
    int pos_y = 0;
    int guesses = 0;
    bool stop = true;
    char obramowanie = '@';
    char katy = 178;
    int numer = 0;
    int numer_licznik = 0;
    int numer_Redo = 0;
    pozycja* trzymaj_pozycje = new pozycja[100];
    pozycja* trzymaj_pozycje_Redo = new pozycja[100];
    trzymaj_pozycje[0].x = 0;
    trzymaj_pozycje[0].y = 0;


    menu_gry(stop, plansza, plansza_ukryta, katy, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, obramowanie, numer);
    char input;
    while (stop)
    {
        cout << "Ruch gracza:";
        cin >> noskipws;
        cin.get(input);
        input_sprawdz(input, plansza, plansza_ukryta, rozmiar, ilosc_atom, pos_x, pos_y, punkty, guesses, stop, katy, obramowanie, oddanie_strzalu, trzymaj_pozycje, numer, numer_licznik, trzymaj_pozycje_Redo, numer_Redo);
        wyswietl_p(plansza, rozmiar, pos_x, pos_y, punkty, ilosc_atom, guesses, numer);



    }

}
