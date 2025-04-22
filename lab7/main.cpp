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
void zapisDoPliku(Student *tab,int pon,int kon)
{
    ofstream zapis;
    string sciazkaDoZapisu = "/Users/student/lab7 js/wyniki.csv";
    zapis.open(sciazkaDoZapisu);

    while(pon < kon)
    {
        zapis << tab[pon].imie << ";" << tab[pon].nazwisko << ";";
        zapis << tab[pon].punkty << endl;
        pon++;
    }

    zapis.close();

}


void wyswietlStudentow2(Student *tab,int i)
{
   cout << tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;

}


int wyszukiwanieLiniowe2(Student *tab,int x,int n,int wartosc)
{
    int pocz,kon;
    int i=x;
    while(i>0)
    {
        if(tab[i].punkty==wartosc)
        {
            i--;
        }
        else break;
    }
    pocz = i+1;
    i=x;

    while(i<n)
    {
        if(tab[i].punkty==wartosc)
        {
            i++;
        }
        else break;
    }
    kon=i;
    zapisDoPliku(tab,pocz,kon);
    return -1;
}


int wyszukiwanieBisekcyjne(Student *tab,int n,int wartosc)
{
    int lewy=0;
    int prawy=n-1;
    while(lewy<=prawy)
    {
        int srodek = (lewy+prawy)/2;
        if(tab[srodek].punkty==wartosc)
        {
            return srodek;
        }
        else{
            if(wartosc<tab[srodek].punkty)
            {
                prawy=srodek-1;
            }
            else lewy=srodek+1;
        }
    }
    return -1;



}
int wyszukiwanieLiniowe(Student *tab,int n,int wartosc)
{
    int i=0;
    while(i<n)
    {
        if(tab[i].punkty==wartosc)
        {
            cout << i<<" ";
        }
        i++;
    }
    return -1;
}

void sortowanieBabelkowe(Student *tab, int n)
{
    int zmiana = 0;
    while(zmiana == 0)
    {
        zmiana = 1;
        for(int i =0;i<n-1;i++)
        {
            if(tab[i].punkty > tab[i+1].punkty)
            {
                swap(tab[i],tab[i+1]);
                zmiana = 0;
            }
        }
    }
}




void wczytajStudentow(Student *&tab,int *n)
{

    string sciezka,linia,pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka = "/Users/student/lab7 js/studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new Student[liczbaStudentow];
    *n = liczbaStudentow;
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
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();

}

void wyswietlStudentow(Student *tab,int n)
{
    for(int i=0;i<n;i++)
    {

        cout << tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }


}




int main()
{
    Student *tab;
    int n;
    while(true)
    {
        cout<<endl << "zad7.1 -(1)  zad7.2 -(2)  zad7.3 -(3)" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            wczytajStudentow(tab, &n);
        }
        if (choice == 2) {
            int wartosc;
            cout << "jaka ma byc wartosc: " << endl;
            cin >> wartosc;
            wyszukiwanieLiniowe(tab, n, wartosc);
        }
        if (choice == 3) {
            int wartosc;
            cout << "jaka ma byc wartosc: " << endl;
            cin >> wartosc;
            sortowanieBabelkowe(tab, n);
            int x = wyszukiwanieBisekcyjne(tab, n, wartosc);
            wyszukiwanieLiniowe2(tab, x, n, wartosc);
        }
    }



}
