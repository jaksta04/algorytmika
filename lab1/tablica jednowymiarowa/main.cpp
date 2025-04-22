#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;


void przydzielanie(int *&Tab,int *ile)
{
    Tab = new int[*ile];
}

void lokowanie(int *&Tab,int a,int b,int *ile)
{
    srand(time(NULL));
    for(int i =0;i<*ile;i++)
    {
        int liczba = rand()%(b-a+1)+a;
        Tab[i] = liczba;
    }
}

void wyswietlanie(int *&Tab,int *ile)
{
    for(int i =0;i<*ile;i++)
    {
        cout <<"wartosc"<<i<<"jest rowna: "<<Tab[i] << endl;
    }
}
void usuwanie(int *&Tab)
{
    delete []Tab;
}


int main()
{
    cout << "wybierz przedzial z ktorego mam doadac liczby do tablicy:" << endl;
    int a,b;
    cout <<"a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    int ile;
    cout <<"ile ma byc liczb: ";
    cin >> ile;
    int *tab = nullptr;
    przydzielanie(tab,&ile);
    lokowanie(tab,a,b,&ile);
    wyswietlanie(tab,&ile);
    usuwanie(tab);



    return 0;
}







