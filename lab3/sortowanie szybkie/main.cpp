#include <iostream>
#include <time.h>

using namespace std;

void wyswietl(int *tab,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << tab[i]<<" ";
        cout << endl;
    }
}

void sortowanieSzysbkie(int *tab,int poczatek,int koniec)
{
    int srodek = (poczatek+koniec)/2;
    int piwot = tab[srodek];
    tab[srodek] = tab[koniec];
    int granica = poczatek;
    int i = poczatek;
    while(i < koniec)
    {
        if(tab[i]<piwot)
        {
            swap(tab[granica],tab[i]);
            granica = granica+1;
        }
        i=i+1;
    }
    tab[koniec]=tab[granica];
    tab[granica]=piwot;
    if(poczatek < granica-1)
    {
        sortowanieSzysbkie(tab,poczatek,granica-1);
    }
    if(granica+1<koniec)
    {
        sortowanieSzysbkie(tab,granica+1,koniec);
    }

}

int main()
{
    cout << "Sotowanie szybkie" << endl;
    int n;
    cout << "ilosc elementow w tablicy: "<<endl;
    cin >> n;
    int *tab = new int[n];
    int a,b;
    cout << "z jakiego przedzialu maja byc dodane liczby (a,b): "<<endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        tab[i] = rand()%(b-a+1)+a;
    }
    wyswietl(tab,n);
    cout << "tablica po sortowaniu: "<<endl;
    sortowanieSzysbkie(tab,0,n-1);
    wyswietl(tab,n);

    return 0;
}
