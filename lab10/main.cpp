#include "iostream"
#include "fstream"
#include "cstdlib"

using namespace std;

struct element
{
    char character;
    element *next;
};

struct queue
{
    element *head;
    element *tail;
};

void push(queue &q,char value)
{
    element *el = new element;
    el->character=value;
    el->next = nullptr;
    if(q.tail != nullptr)
    {
        q.tail->next=el;
    }
    else {
        q.head = el;
    }
    q.tail=el;
}

void pop(queue &q)
{
    element *temp = q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head== nullptr)
    {
        q.tail= nullptr;
    }
}

int isEmpty(queue q)
{
    if(q.head== nullptr)
    {
        cout << "Stos jest pusty"<<endl;
        return 1;
    } else cout << "Stos nie jest pusty"<<endl; return 0;
}

char first(queue q)
{
    return q.head->character;
}

char dodajZnak()
{
    int a = 1, b = 255;
    srand((int)time(nullptr));
    return char(rand() % (b - a) + 1 + a);
}

void dodajZnaki2(queue &q)
{
    ifstream file;
    string linijka;

    file.open("C:\\Users\\jakst\\OneDrive\\Pulpit\\c++ projects\\algorytmika\\lab10\\Znaki2.txt");

    while(getline(file, linijka))
    {
        for(int i = 0; i < linijka.length(); i++)
        {

            if((int)linijka[i] >= 65 && (int)linijka[i] <= 90)
            {
                push(q, char(linijka[i]));
                cout << first(q)<<endl;
                pop(q);
            }

        }
    }

    file.close();
}




void menu(queue q)
{
    int choice;
    choice = 1;
    while(choice != 0)
    {
        cout << "1 - sprawdz czy kolejka jest pusta" << endl <<
             "2 - dodaj element" << endl <<
             "3 - usun element" << endl <<
             "4 - pobierz pierwszy element" << endl <<
             "5 - usun wszystkie elementy" << endl <<
             "6 - dodaj znaki z pliku Znaki2" << endl <<
             "7 - wyjscie z programu" << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                isEmpty(q);
                break;

            case 2:
                push(q,dodajZnak());
                break;

            case 3:
                pop(q);
                break;

            case 4:
                cout << first(q)<<endl;
                pop(q);
                break;

            case 5:
                while(!isEmpty(q)) pop(q);
                break;


            case 6:
                dodajZnaki2(q);
                break;

            case 7:
                cout << "Koniec programu"<<endl;
                return;






        }
    }
}


int main()
{
    queue q;
    q.head = nullptr;
    q.tail = nullptr;
    menu(q);


}