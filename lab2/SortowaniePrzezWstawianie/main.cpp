#include <iostream>

using namespace std;


void SortowaniePrzezWstawianie(int *Tab,int n)
{
    int pom,j;
    for(int i=1; i<n; i++)
    {
        pom = Tab[i];
        j = i-1;
        while(j>=0 && Tab[j]>pom)
        {
            Tab[j+1] = Tab[j];
            --j;
        }
        Tab[j+1] = pom;
    }
}



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
    SortowaniePrzezWstawianie(Tab,n);
    wyswietalnie(Tab,n);


    return 0;
}
