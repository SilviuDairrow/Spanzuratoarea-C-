#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>

using namespace std;
ifstream f("cuvinte.in");

char grafica[41][41];
char cuvant[31]={'\0'},necunoscut[31]={'\0'};
int sw,cond;
char tlit[2];
char desen[21][21]={'\0'};

void cautare()///Cautare inainte de afisnec
{
    int n=strlen(cuvant);
    bool rex=0;
    for(int i=0;i<n;++i)
    {
        if(cuvant[i]==tlit[0])
        {
            necunoscut[i]=tlit[0];
            rex=1;
            cond++;
        }
    }
    if (!rex)sw++;
}

void GenNec()
{
    int n=strlen(cuvant);
    for(int i=0;i<n;i++)
    {
        if(cuvant[i]==' ')necunoscut[i]=' ';
        else necunoscut[i]='_';
    }
}
void AfisNec()
{
    int n=strlen(cuvant);
    for(int i=0;i<n;++i)
    {
        cout << necunoscut[i];
    }
    cout << "\n";
}
void GenCuv()
{
    char aux[31];
    srand((int)time(0));
    int randnumb=rand()%200+1;
    for(int i=1;i<=randnumb;++i)
    {
        f>>aux;
    }
    strcpy(cuvant,aux);
}
void Start()
{
    cout << "Introdu tasta R pentru random word\n";
    cout << "Introdu tasta T pentru a introduce de la tastatura cuvant\n";
}
void Start2()
{
    char Optiune[2];
    cin.getline(Optiune,2);
        if(Optiune[0]=='r'||Optiune[0]=='R')
        {
            cout << "Se genereaza cuvantul";
            GenCuv();
            Sleep(300);
            cout << ".";
            Sleep(300);
            cout << ".";
            Sleep(300);
            cout << ".\n";
            Sleep(1000);
            cout << "Cuvantul a fost generat cu succes\n";
        }
        else
        {
            if(Optiune[0]=='t'||Optiune[0]=='T')
            {
                cout << "\nIntrodu cuvantul: ";
                Sleep(500);
                cin.getline(cuvant,31);
            }
            else
            {
                cout<<"Eroare! Introdu o optiune.";
                Sleep(3000);
                system("CLS");
                Start();
                Start2();
            }
            cout << "Jocul va incepe imediat!";
            Sleep(3500);
        }
            system("CLS");
}
void AfisWin()
{
    cout << "\n\n                                             Congratulations!";
    cout << "\n                                         Cuvant final: ";
    for(int i=0;i<strlen(cuvant);++i)cout << cuvant[i];
    cout << "\n\n\n\n\n\n";

}
void AfisLose()
{
    cout << "\n\n                                        Lose.";
    cout << "\n                                 Cuvant final: ";
    for(int i=0;i<strlen(cuvant);++i)cout << cuvant[i];
}
void AfisDesen()
{
    int i,j;
   for(i=0;i<21;++i)
   {
    for(j=0;j<21;++j)cout<<desen[i][j];
    cout<<"\n";
}
}
void GenDesen0()
{
    int i,j;
   for(i=0;i<20;++i)
        for(j=0;j<20;++j)desen[i][j]=' ';
   for(j=0;j<17;++j)desen[20][j]='_';
   for(i=20;i>5;--i)desen[i][8]='|';
   for(j=9;j<15;++j)desen[5][j]='_';
   for(i=6;i<9;++i)desen[i][15]='|';
}
void GenDesen1()
{
    int i,j;
    desen[9][15]='_';
    desen[10][14]=desen[11][16]='/';
    desen[11][14]=desen[10][16]=char(92);
    desen[11][15]='_';
}
void GenDesen2()
{
    int i,j;
    for(i=12;i<17;++i)desen[i][15]='|';

}
void GenDesen3()
{
    desen[13][14]=desen[14][13]='/';
}
void GenDesen4()
{
    desen[13][16]=desen[14][17]=char(92);
}
void GenDesen5()
{
    desen[17][14]=desen[18][13]='/';
}
void GenDesen6()
{
    desen[17][16]=desen[18][17]=char(92);
}
int main()
{
    Start();
    Sleep(1300);
    GenDesen0();
    Start2();
    GenNec();
    sw=0;
        while(sw<6)
        {
            system("CLS");
            AfisDesen();
            cout << "\n            incercari ramase: " << 6-sw << "\n";
            AfisNec();
            cout << "Introdu litera: "; cin.getline(tlit,2);
            cautare();
            if(cond==strlen(cuvant))
                {
                system("CLS");
                cout <<"\n\n\n";
                AfisWin();
                return 0;
        }
        if(sw==1)GenDesen1();
        if(sw==2)GenDesen2();
        if(sw==3)GenDesen3();
        if(sw==4)GenDesen4();
        if(sw==5)GenDesen5();
        if(sw==6)GenDesen6();
        }
        if(sw==6)
        {
            system("CLS");
            AfisDesen();
            Sleep(300);
            bool restart=0;
            AfisLose();
            Sleep(3500);
            cout << "\n\n Ca sa continui, tasteaza 1";
            cout << "\n Ca sa inchizi programul, tasteaza 0\n";
            cin >> restart;
            if(restart==0)
            {
                return 0;
            }
            else
            {
                Sleep(1500);
                system("CLS");
                main();
            }
        }
    return 0;
}
