#include <iostream>

using namespace std;

void przydzielanie(int **&tab, int *wier, int *kol);
void lokowanie(int **&tab, int *wier, int *kol);
void wyswietlanie(int **&tab, int *wier, int *kol);
void usuwanie(int **&tab, int *wier, int *kol);

int main()
{
    cout << "proba tablicy dwuwymiarowej " << endl;
    int **Tab = nullptr;
    int wiersze;
    int kolumny;
    cout << "podaj ilosc wierszy: "<<endl;
    cin >> wiersze;
    cout << "podaj ilosc kolumn: "<<endl;
    cin >> kolumny;
    przydzielanie(Tab,&wiersze,&kolumny);
    lokowanie(Tab,&wiersze,&kolumny);
    wyswietlanie(Tab,&wiersze,&kolumny);
    usuwanie(Tab,&wiersze,&kolumny);

    return 0;
}

void przydzielanie(int **&tab, int *wier, int *kol)
{
    tab = new int*[*wier];
    for(int i = 0;i < *wier;i++)
    {
        tab[i] = new int[*kol];
    }
}

void lokowanie(int **&tab,int *wier,int *kol)
{
    int liczba;
    for(int i =0;i<*wier;i++)
    {
        for(int j=0;j<*kol;j++)
        {
            cout <<"podaj liczbe do tablicy"<<"["<<i<<"]["<<j<<"] :"<<endl;
            cin >> liczba;
            tab[i][j] = liczba;

        }
    }
}

void wyswietlanie(int **&tab,int *wier,int *kol)
{
    for(int i =0;i<*wier;i++)
    {
        for(int j=0;j<*kol;j++)
        {
            cout <<"liczby w tablicy: "<<endl;
            cout <<"pozycja["<<i<<"]["<<j<<"]: "<<tab[i][j]<<endl;

        }
    }


}
void usuwanie(int **&tab,int *wier,int *kol)
{
    for(int i =0;i<*wier;i++)
    {
        delete [] tab[*wier];
    }
    delete []tab;


}
















