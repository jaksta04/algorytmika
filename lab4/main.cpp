#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    string imie;
    string nazwisko;
    int punkty;
};

int podzial3czesci(Student *tab,int n,int *ii,int *kk)
{
    int i =-1;
    int j=0;
    int k =n;
    while(j<k)
    {
        if(tab[j].punkty%3==0)
        {
            i++;
            swap(tab[i],tab[j]);
            j++;
        }
        else
        {
            if(tab[j].punkty%3==2)
            {
                k--;
                swap(tab[k],tab[j]);
            }
            else
            {
                j++;
            }

        }
    }
    *ii = i;
    *kk = k;
}

int podzial2czesci(Student *tab,int n,int granica)
{
    int i =0;
    int j =n-1;
    while(i<j)
    {
        while(tab[i].punkty <= granica && i<j)
        {
            i++;
        }
        while(tab[j].punkty> granica && i <j)
        {
            j--;
        }
        if(i<j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }

    }
    if(tab[i].punkty <= granica)
    {
        return i+1;
    }
    else
    {
        return i;
    }


}

void wyswietlStudentow(Student *tab, int p,int k)
{
    while(p<k)
    {
        cout <<tab[p].imie<<" "<<tab[p].nazwisko<<" "<<tab[p].punkty<<endl;
        p++;
    }
}


void wczytajStudentow(Student *&tab,int &n)
{
    string sciezka,linia,pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka = "studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new Student[liczbaStudentow];
    n = liczbaStudentow;

    for(int i=0;i<2;i++)
    {
        plik >> sredniki;
    }

    for(int i=0;i<liczbaStudentow;i++)
    {
        plik >> linia;
        stringstream ss(linia);
        getline(ss,tab[i].imie, ';');
        getline(ss,tab[i].nazwisko, ';');
        getline(ss,pomoc);
        tab[i].punkty = atoi(pomoc.c_str());

    }
    plik.close();

}



int main()
{
    Student *tab;
    int n;
    int x;
    wczytajStudentow(tab,n);
    wyswietlStudentow(tab,0,n);
    int choice;
    cout <<"wybierz podzial na dwie czesci(2) lub na trzy czesci(3):";
    cin >> choice;
    if(choice == 2)
    {
        x = podzial2czesci(tab,n,10);
        cout <<endl<<endl<<"Studenci,ktorzy otrzymali <=10 punktow:"<<endl<<endl;
        wyswietlStudentow(tab,0,x);
        cout << endl<<"Srudenci,ktorzy otrzymali >10 punktow:"<<endl<<endl;
        wyswietlStudentow(tab,x,n);
    }
    else if(choice == 3)
    {
        int i;
        int k;
        podzial3czesci(tab,n,&i,&k);
        cout << "Studenci,ktorzy otrzymali liczbe punktow podzielnych przez 3:"<<endl;
        wyswietlStudentow(tab,0,i+1);
        cout << endl<<endl<<"Studenci,ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:"<<endl;
        wyswietlStudentow(tab,i+1,k);
        cout << endl<<endl<<"Studenci,ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:"<<endl;
        wyswietlStudentow(tab,k,n);


    }

    return 0;
}
