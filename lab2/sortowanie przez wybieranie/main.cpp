#include <iostream>

using namespace std;

void sortowaniePrzezWybieranie(int *tab,int n);
void wyswietalnie(int *tab,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }

}

int main()
{
    cout << "Sortowanie przez wybieranie" << endl;
    int *Tab;
    int n;
    cout << "Ilosc liczb w tablicy: "<<endl;
    cin >> n;
    Tab = new int[n];
    int liczba;
    for(int i=0;i<n;i++)
    {
        cout <<"podaj liczbe do tablicy: "<<endl;
        cin >> liczba;
        Tab[i] = liczba;

    }
    sortowaniePrzezWybieranie(Tab,n);
    wyswietalnie(Tab,n);


    return 0;
}

void sortowaniePrzezWybieranie(int *tab,int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        for(int j = i + 1; j < n; j++)
        {
            if(tab[j] < tab[min_idx])
            {
                min_idx = j;
            }
        }

        if(min_idx != i)
        {
            swap(tab[min_idx], tab[i]);
        }
    }

}
