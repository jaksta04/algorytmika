#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct element
{
    int number;
    element* next;
};

void push(element*& stack, int value)
{
    element* el = new element;
    el -> number = value;
    el -> next = stack;
    stack = el;
}

int pop(element*& stack)
{
    element* temp = stack;
    int pom = temp->number;
    stack = stack -> next;
    delete temp;
    return pom;
}

bool isEmpty(element* stack)
{
    if(stack == nullptr) return true;
    else return false;
}

int top(element* stack) {return stack -> number;}

int randomFrom1to100()
{
    int a = 1, b = 100;
    srand((int)time(nullptr));
    return rand() % (b - a) + 1 + a;
}

void reverse(element*& stack)
{
    ifstream file;
    ofstream wynik;
    string linijka;

    file.open("C:\\Users\\jakst\\OneDrive\\Pulpit\\c++ projects\\algorytmika\\lab9\\znaki.txt");
    wynik.open("C:\\Users\\jakst\\OneDrive\\Pulpit\\c++ projects\\algorytmika\\lab9\\wyniki.txt");

    while(getline(file, linijka))
    {
        for(int i = 0; i < linijka.length(); i++)
        {
            push(stack,(int)linijka[i]);
            cout << (char) top(stack);
        }
        push(stack,(int)'\n');
        //cout << endl;
    }

    cout << endl<<endl;

    while(isEmpty(stack) != true)
    {
        cout<< (char) top(stack);
        wynik << (char) top(stack);
        pop(stack);
    }

    file.close();
    wynik.close();
}

void menu(element*& stack, element*& stack2)
{
    int wybor = 1;
    while(wybor != 0)
    {
        cout << "Wybierz: "<< endl
             << "0- wyjscie z programu" <<endl
             << "1- sprawdzenie czy stos jest pusty" <<endl
             << "2- dodanie losowego elementu z przedzialu 1 - 100 na stos (push)" <<endl
             << "3- usuniecie ostatniego elementu stosu (pop)" <<endl
             << "4- wyswietlenie ostatniego elementu stosu" <<endl
             << "5- usuniecie calego stosu" <<endl
             << "6- zad 9.2" <<endl;
        cin >> wybor;

        switch(wybor)
        {
            case 0:
                break;

            case 1:

                if(isEmpty(stack)) cout << "Stos jest pusty" << endl;
                else cout << "Stos nie jest pusty" << endl;

                break;

            case 2:
                push(stack, randomFrom1to100());
                cout << "dodano " << top(stack) << " do stosu"<< endl;
                break;

            case 3:

                if(isEmpty(stack)) cout << "Stos jest pusty" << endl;
                else
                {
                    cout << "Usunieto " <<pop(stack)<<endl;
                }

                break;

            case 4:

                if(isEmpty(stack)) cout << "NULL" << endl;
                else cout << top(stack) <<endl;

                break;

            case 5:

                if(isEmpty(stack)) cout << "Stos jest pusty" << endl;
                else
                {
                    while(!isEmpty(stack)) pop(stack);
                    cout << "Usunieto wszystkie elementy stosu" <<endl;
                }

                break;

            case 6:

                reverse(stack2);
                break;

            default:
                cout << "nieprawidlowe polecenie" <<endl;
                break;
        }
    }
}



int main()
{
    element* stack = nullptr;
    element* stack2 = nullptr;

    menu(stack,stack2);

    return 0;
}