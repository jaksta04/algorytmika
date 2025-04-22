#include "iostream"

using namespace std;

struct Element
{
    int number;
    Element *next;
    Element *prev;
};

struct double_list
{
    Element *head;
    Element *tail;
    int counter;
};

void add_tail(double_list &lista,int value)
{
    Element *el = new Element;
    el->number = value;
    el->next = lista.head;
    el->prev = nullptr;
    if(lista.tail!= nullptr)
    {
        lista.tail->next=el;
        el->prev=lista.tail;
    }else lista.head=el;
    lista.tail=el;
    lista.counter++;

}

void add_head(double_list &lista,int value)
{
    Element *el = new Element;
    el->number = value;
    el->next = nullptr;
    el->prev = lista.tail;
    if(lista.head!= nullptr)
    {
        lista.head->prev=el;
        el->next=lista.head;
    }else lista.tail=el;
    lista.head=el;
    lista.counter++;
}

void add_position(double_list &lista,int value,int position)
{
    Element *temp = lista.head;
    int i=1;
    while(i<position-1)
    {
        temp = temp->next;
        i++;
    }
    Element *el = new Element;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    lista.counter++;
}

void delete_tail(double_list &lista)
{
    Element *temp = lista.tail;
    if(lista.counter==1)
    {
        lista.tail= nullptr;
        lista.head= nullptr;
    }
    else
    {
        lista.tail=lista.tail->prev;
        lista.tail->next= nullptr;
    }
    delete temp;
    lista.counter--;
}

void delete_head(double_list &lista)
{
    Element *temp = lista.head;
    if(lista.counter==1)
    {
        lista.tail= nullptr;
        lista.head= nullptr;
    }
    else
    {
        lista.head=lista.head->next;
        lista.head->prev= nullptr;
    }
    delete temp;
    lista.counter--;
}

void delete_position(double_list &lista,int position)
{
    Element *temp = lista.head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    Element *temp_us= nullptr;
    temp_us = temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
    lista.counter--;
}

void show(double_list lista)
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

int isEmpty(double_list lista)
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

void delete_list(double_list &lista)
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



void menu(double_list lista)
{
    int choice;
    choice = 1;
    while(choice != 14)
    {
        cout << "1 - sprawdz czy lista jest pusta"<<endl<<
             "2 - dodanie elementu za element biezacy"<<endl<<
             "3 - dodanie elementu przed element biezacy"<<endl<<
             "4 - usuniecie elementu stojacego za elementem biezacym"<<endl<<
             "5 - usuniecie elementu stojacego przed elementem biezacym"<<endl<<
             "6 - usuniecie elementu biezacego, a element stojacy za nim staje sie elementem biezacym"<<endl<<
             "7 - wyswietlenie elementow listy"<<endl<<
             "8 - usuniecie calej listy wraz ze zwolnieniem pamieci"<<endl<<
             "9 - wyjscie z programu"<<endl;
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
                delete_tail(lista);
                break;

            case 5:
                delete_head(lista);
                break;

            case 6:
                cout << "Podaj indeks z ktorego usunac liczbe: "<<endl;
                int indeks;
                cin>>indeks;
                delete_position(lista,indeks);
                break;

            case 7:
                if(!isEmpty(lista))
                {
                    show(lista);
                }else cout <<"Lista jest pusta, nie ma co wyswietlic"<<endl;
                break;

            case 8:
                delete_list(lista);
                break;

            case 9:
                return;

        }
    }
}



int main()
{
    double_list lista;
    lista.head = nullptr;
    lista.tail = nullptr;
    lista.counter = 0;
    menu(lista);
    return 0;
}