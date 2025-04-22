#include "iostream"
#include "time.h"

using namespace std;

struct Element
{
    int number;
    Element *next;
};
struct single_list
{
    Element *head;
    Element *tail;
    int counter;
};

void add_tail(single_list & lista,int value)
{
    Element *el = new Element;
    el->number=value;
    el->next= nullptr;
    if(lista.tail!= nullptr)
    {
        lista.tail->next=el;
    } else lista.head=el;
    lista.tail=el;
    lista.counter++;
}
void add_head(single_list &lista,int value)
{
    Element *el = new Element;
    el->number=value;
    el->next=lista.head;
    lista.head=el;
    if(lista.tail== nullptr)
    {
        lista.tail=el;
    }
    lista.counter++;
}

void add_position(single_list &lista,int value,int position)
{
    Element *el = new Element;
    el->number = value;
    Element *temp = lista.head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    el->next=temp->next;
    temp->next=el;
    lista.counter++;
}

void delete_tail(single_list &lista)
{
    Element *temp= lista.tail;
    if(lista.counter==1)
    {
        lista.tail= nullptr;
        lista.head= nullptr;
    }
    else
    {
        Element *bef_temp = lista.head;
        int i=1;
        while(i<lista.counter-1)
        {
            bef_temp=bef_temp->next;
            i++;
        }
        lista.tail=bef_temp;
        lista.tail->next= nullptr;
    }
    delete temp;
    lista.counter--;
}
void delete_head(single_list &lista)
{
    Element *temp=lista.head;
    lista.head = lista.head->next;
    if(lista.counter==1)
    {
        lista.tail= nullptr;
    }
    delete temp;
    lista.counter--;
}

void delete_position(single_list &lista,int position)
{
    Element *prev = lista.head;
    int i=1;
    while(i<position-1)
    {
        prev= prev->next;
        i++;
    }
    Element *temp = prev->next;
    prev->next=temp->next;
    delete temp;
    lista.counter--;
}

void show(single_list lista)
{
    int i=1;
    Element *temp = lista.head;
    while(i <= lista.counter)
    {
        cout << temp->number<<endl;
        temp=temp->next;
        i++;
    }
}

int isEmpty(single_list lista)
{
    if(lista.head == nullptr)
    {
        return 1;
    } else return 0;
}

int numbers_to_add()
{
    int a,b;
    a=1;
    b=50;
    srand(time(nullptr));
    int liczba;
    liczba = rand()%(b-a)+1-a;
    return liczba;

}

int first(single_list lista)
{
    return lista.head->number;
}

int last(single_list lista)
{
    return lista.tail->number;
}

int count_average(single_list lista)
{
    int suma=0;
    Element *temp = lista.head;
    int i=0;
    while(i<lista.counter)
    {
        suma += temp->number;
        temp = temp->next;
        i++;
    }
    return suma/lista.counter;
}

int max_element(single_list lista)
{
    int max;
    Element *temp = lista.head;
    max = temp->number;
    temp = temp->next;
    int i=1;
    while(i<lista.counter)
    {
        if(temp->number > max)
        {
            max = temp->number;
        }
        temp = temp->next;
        i++;
    }
    return max;
}


void delete_list(single_list &lista)
{
    int i=0;
    while(i<lista.counter)
    {
        Element *temp = lista.head;
        lista.head = lista.head->next;
        delete temp;
        i++;
    }

}


void menu(single_list lista)
{
    int choice;
    choice = 1;
    while(choice != 14)
    {
        cout << "1 - sprawdz czy lista jest pusta"<<endl<<
                "2 - dodaj element na koniec listy"<<endl<<
                "3 - dodaj element na poczatek listy"<<endl<<
                "4 - dodaj element na okreslona pozycje"<<endl<<
                "5 - usun element z konca listy"<<endl<<
                "6 - usun element z poczatku listy"<<endl<<
                "7 - usun element znajdujacy sie na okreslonej pozycji"<<endl<<
                "8 - pobieranie pierwszego elementu listy"<<endl<<
                "9 - pobieranie ostatniego elementu listy"<<endl<<
                "10 - policzenie srednej arytmetycznej elementow w liscie"<<endl<<
                "11 - znalezienie elementu maksymalnego w liscie"<<endl<<
                "12 - wyswietlenie calej listy"<<endl<<
                "13 - usuniecie calej listy"<<endl<<
                "14 - wyjscie z programu"<<endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                if(!isEmpty(lista))
                {
                    cout << "Lista nie jest pusta!"<<endl;
                }else cout << "Lista jest pusta!"<<endl;
                break;


            case 2:
                add_tail(lista,numbers_to_add());
                break;

            case 3:
                add_head(lista,numbers_to_add());
                break;

            case 4:
                cout << "podaj numer indeksu do wstawienia liczby: "<<endl;
                int index;
                cin>>index;
                add_position(lista,numbers_to_add(),index);
                break;

            case 5:
                delete_tail(lista);
                break;

            case 6:
                delete_head(lista);
                break;

            case 7:
                cout << "Podaj indeks z ktorego usunac liczbe: "<<endl;
                int indeks;
                cin>>indeks;
                delete_position(lista,indeks);
                break;

            case 8:
                cout<<"Pierwszy element listy: "<<first(lista)<<endl;
                break;

            case 9:
                cout<<"Ostatni element listy: "<<last(lista)<<endl;
                break;

            case 10:
                cout<<"Srednia arytmetyczna liczb w liscie: "<<count_average(lista)<<endl;
                break;

            case 11:
                cout << "Najwiekszy element w liscie: "<<max_element(lista)<<endl;
                break;

            case 12:
                if(!isEmpty(lista))
                {
                    show(lista);
                }else cout <<"Lista jest pusta, nie ma co wyswietlic"<<endl;
                break;

            case 13:
                delete_list(lista);
                break;

            case 14:
                return;

        }
    }
}

int main()
{
    single_list lista;
    lista.head = nullptr;
    lista.tail = nullptr;
    lista.counter =0;
    menu(lista);
    return 0;

}