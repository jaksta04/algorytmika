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

void wczytajStudentow(Student *&tab,int &n);

void wyswietlStudentow(Student *tab,int n)
{
    for(int i =0;i<n;i++)
    {
        cout << tab[i].imie <<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }

}

void usunTbliceStudentow(Student *&tab)
{
    delete [] tab;

}

void sortowanieSzysbkie(Student *tab,int poczatek,int koniec)
{
    int srodek = (poczatek+koniec)/2;
    Student piwot = tab[srodek];
    tab[srodek] = tab[koniec];
    int granica = poczatek;
    int i = poczatek;
    while(i < koniec)
    {
        if(tab[i].punkty <piwot.punkty)
        {
            swap(tab[granica],tab[i]);
            granica = granica+1;
        }
        i=i+1;
    }
    tab[koniec]=tab[granica];
    tab[granica] =piwot;
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
    Student *tab;
    int n;
    wczytajStudentow(tab,n);
    wyswietlStudentow(tab,n);
    sortowanieSzysbkie(tab,0,n-1);
    cout <<"po sortowaniu" <<endl<<endl;
    wyswietlStudentow(tab,n);
    usunTbliceStudentow(tab);

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
