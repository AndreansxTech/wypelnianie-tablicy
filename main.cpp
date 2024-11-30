#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
int znak,w,s;
bool z;
void kolor(int k)
{
    SetConsoleTextAttribute(color,k);
}
void sprawdz()
{
    while (znak!=49 && znak!=48 && znak!=1 && znak!=0)
    {
        kolor(64);cout<<"\nNiepoprawny znak ! \n Wpisz 1 lub 0:";kolor(45);cout<<" [   ]\b\b\b";znak=getch();znak=znak-'0';cout<<znak<<endl;
    }
}
void zmien()
{
    if (z==1)
        z=0;
    else
        z=1;
}
void tablica(int w,int s)
{
    int tabl[w][s];
    if(znak==0)
    {
        for (int i=0;i<w;i++)
        {
            for (int j=0;j<s;j++)
            {
                kolor(4);cout<<z<<endl;
                tabl[i][j]=z;zmien();
            }
        }
    }
    else if(znak==1)
    {
        for (int i=0;i<w;i++)
        {
            for (int j=0;j<s;j++)
            {
                zmien();tabl[i][j]=z;
            }
        }
    }
    cout<<endl;
    for (int i=0;i<w;i++)
    {
        for (int j=0;j<s;j++)
        {
            cout<<" | ";
            if (tabl[i][j]==1)
                kolor(12);
            else
                kolor(14);
            cout<<tabl[i][j];kolor(7);
        }
      cout<<"|"<<endl;
    }
}
int main()
{
    kolor(89); cout<<"-- Wypelnianie tablicy zerami i jedynkami --\n\n Podaj jaka wysokosc ma miec tablica:";kolor(45);cout<<" [   ]\b\b\b";
    cin>>w;kolor(89);cout<<"\n Podaj jaka szerokosc ma miec tablica:";kolor(45);cout<<"[   ]\b\b\b";cin>>s;
    kolor(89);cout<<"\n Podaj od jakiego znaku ma sie zaczynac tablica:";kolor(45);cout<<"[   ]\b\b\b";znak=getch();
    if (znak!=49 && znak!=48)
        cout<<"!";
    else
    {
        znak=znak-'0';cout<<znak;
    }
    sprawdz();kolor(7);tablica(w,s);
    return 0;
}
