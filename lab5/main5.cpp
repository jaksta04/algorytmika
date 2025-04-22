#include <iostream>
#include <string>
using namespace std;

void AlgorytmNaiwny(string tekst,string wzorzec,int dlt,int dlw)
{
    int i=0;
    while(i <= dlt - dlw)
    {
        int j=0;
        while(j <dlw && wzorzec[j]==tekst[i+j])
        {
            j++;
        }
        if(j==dlw)
        {
            cout << i;
        }
        i++;
    }
}

void TablicaDopasowan(string wzorzec,int dlw,int *p)
{
    p[0]=0;
    p[1]=0;
    int t=0;
    int i=1;
    while(i<dlw)
    {
        while(t>0 && wzorzec[t]!=wzorzec[i])
        {
            t=p[t];
        }
        if(wzorzec[t]==wzorzec[i])
        {
            t++;
        }
        p[i+1]=t;
        i++;
    }
}

void kmp(string wzorzec, string tekst,int dlw,int dlt,int *p)
{
    int i=0;
    int j=0;
    while(i< dlt-dlw+1)
    {
        while(wzorzec[j]==tekst[i+j] && j<dlw)
        {
            j++;
        }
        if(j==dlw)
        {
            cout << i<<endl;
        }
        i=i+max(1,j-p[j]);
        j=p[j];
    }
}

int main()
{
    string tekst("abbcabb");
    string wzorzec("ab");
    int dl_tekst = (int)tekst.size();
    int dl_wzorzec = (int)wzorzec.size();
    //AlgorytmNaiwny(tekst, wzorzec, dl_tekst, dl_wzorzec);
    int *p= new int[dl_wzorzec+1];
    TablicaDopasowan(wzorzec,dl_wzorzec,p);
    kmp(wzorzec,tekst,dl_wzorzec,dl_tekst,p);

    return 0;
}
