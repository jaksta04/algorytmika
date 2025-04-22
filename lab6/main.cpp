#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int makeHash(char s, int off,int p,int exp) {
    int hash=0;
    hash=hash+((int)s-off)*pow(p,exp);
    return hash;
}

int updateHash(int hash, char s_prev, char s_next,int off, int p, int exp) {
    int u_hash=hash-((int)s_prev-off)*pow(p, exp);
    u_hash=u_hash*p;
    u_hash=u_hash+((int)s_next-off);
    return u_hash;
}
bool naiwny(string wzorzec, string tekst, int start, int w)
{

    int i=0;
    while(i<w && wzorzec[i]==tekst[i+start]){
        i++;
    }
    if(i==w)
    {
        return true;
    }
    else {
        return false;
    }
}

void kr(string pattern, string text, int lenP, int lenT, int p, int off)
{
    int hashP=0;
    int hashT=0;
    int pomoc=0;
    int i=0;
    while(i<lenP){
        hashP=hashP+makeHash(pattern[i],off,p,lenP-i-1);
        hashT=hashT+makeHash(text[i],off,p,lenP-i-1);
        i=i+1;
    }
    i=lenP;
    int j=0;
    while(i<=lenT)
    {
        if(hashP==hashT)
        {
            if(naiwny(pattern, text, j, pattern.length()))
            {
                cout<<j+1<<" ";
                pomoc=1;
            }
        }
        if(i<lenT)
        {
            hashT=updateHash(hashT, text[j], text[i], off, p, lenP-1);
        }
        i++;
        j++;
    }
    if (pomoc==0)
        cout<<"-1";
}

int main()
{
    string sciezka, linia, wzorzec;
    ifstream plik;
    sciezka="tekst";
    plik.open(sciezka);
    plik>>wzorzec;
    cout<<wzorzec<<endl;
    int i=1;
    if (plik.is_open()) {
        while (getline(plik, linia)) {
            if(i>1){
                cout << "Linijka"<<i<<": ";
                kr(wzorzec, linia, wzorzec.length(), linia.length(),58 ,65);
                cout<<endl;
            }
            i++;
        }
        plik.close();
        return 0;
    }
}




