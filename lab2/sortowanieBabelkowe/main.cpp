#include <iostream>

using namespace std;

void sortowanieBabelkowe(int *&tab, int n, int tryb);
void wyswietlanie(int *&tab, int n, int tryb)
{
    if(tryb == 1)
    {
        cout << "posortowana tablica rosnaco: "<<endl;
    }
    if(tryb == 2)
    {
        cout << "posortowana tablica malejaco: "<<endl;
    }
    for(int i =0;i < n;i++)
    {
        cout<<tab[i]<<" ";

    }
    delete []tab;

}

int main()
{
    cout << "Sortowanie babelkowe" << endl;
    int *Tab;
    int n,tryb;
    cout << "Ile ma byc liczb: " <<endl;
    cin >> n;
    cout << "sortowanie: rosnace-1, malejace-2: " <<endl;
    cin >> tryb;
    if(tryb != 1 || tryb != 2) return 0;
    sortowanieBabelkowe(Tab,n,tryb);
    wyswietlanie(Tab,n,tryb);

    return 0;
}
void sortowanieBabelkowe(int *&tab, int n, int tryb)
{
    tab = new int[n];
    int liczba;
    for(int i =0;i < n;i++)
    {
        cout << "podaj liczbe do tablicy: "<<endl;
        cin >> liczba;
        tab[i] = liczba;
    }
    if(tryb == 1)
    {
        int zmiana = 0;
        while(zmiana == 0)
        {
            zmiana = 1;
            for(int i =0;i<n-1;i++)
            {
                if(tab[i] > tab[i+1])
                {
                    swap(tab[i],tab[i+1]);


                    zmiana = 0;
                }
            }
        }
    }
    if(tryb == 2)
    {
        int zmiana = 0;
        while(zmiana == 0)
        {
            zmiana = 1;
            for(int i =0;i<n-1;i++)
            {
                if(tab[i] < tab[i+1])
                {
                    swap(tab[i],tab[i+1]);


                    zmiana = 0;
                }
            }
        }
    }

}
