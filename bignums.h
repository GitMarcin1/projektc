#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//co zwracaja poszzczegolne funkcje, odwolywanie sie do tablicy w funkcjach, wczytywanie czy dobrze, i wypisywanie, dzielneie

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


unsigned int a[1100], b[1100], p[1100], k[1100], s[1100], r[1100];

unsigned long long w[2200];

char licz1[9900];
char licz2[9900];

int n,m;

FILE *fp;
fp=fopen ("liczba1.txt", "r"); // liczba a

FILE *fp2;
fp2=fopen ("liczba2.txt", "r"); //liczba b

FILE *fp3;
fp3=fopen ("wynik.txt","w"); //liczba utworozna przy pomocy obliczen na a i b

void init(*fp,*fp2)
{

    int d1,d2;

    while(fgets (licz1, 9900, fp)!=NULL)    // wczytywanie liczby pierwszej do licz1 i sprawdzanie jej dlugosci
    {
        d1++;
    }

    while(fgets (licz2, 9900, fp2)!=NULL)    // wczytywanie liczby drugiej do licz2 i sprawdzanie jej dlugosci
    {
        d2++;
    }

    n=(d1/9)+1; //ilosc komorek w tablicach a  i b;
    m=(d2/9)+1;

    unsigned int b; //pomocnicze trzymanie komorki z tablicy a
    int c; // 10^j;

    for(int i=0; i<n; i++) //konwersja liczby zapisanej jako string w tablice z podzielona na czesci liczba
    {

        d=0;
        c=1;

        for (int j=0; j<9; j++)
        {

            //licz1[d1-(j*(i+1)]; cyfra z tablicy charow

            d=d+((licz1[d1-(j*(i+1))]-'0')*c);


            c=c*10;

        }

        a[i]=d; //pojdencza komorka tablicy z pierwsza liczba trzymajaca 9cyfrowa liczbe

    }

//druga liczba
    for(int i=0; i<m; i++) //konwersja liczby zapisanej jako string w tablice z podzielona na czesci liczba
    {

        d=0;
        c=1;

        for (int j=0; j<9; j++)
        {

            //licz1[d1-(j*(i+1)]; cyfra z tablicy charow

            d=d+((licz1[d1-(j*(i+1))]-'0')*c);


            c=c*10;

        }

        b[i]=d; //pojdencza komorka tablicy z pierwsza liczba trzymajaca 9cyfrowa liczbe

    }

}

int nadmiar=0;;
int maxs = MAX(n,m);

void sum()
{

    w[0]=(a[0]+b[0])%1000000000+nadmiar;


    for (int i=1; i<maxs; i++)
    {


        nadmiar=((a[i-1]+b[i-1])-(a[i-1]+b[i-1])%1000000000)/1000000000;

        // nadmiar pierwsza cyfra sumy dwoch komorek tablic a i b jesli liczba przekracza 9 cyfr


        w[i]=((a[i]+b[i])%1000000000)+nadmiar;

        //suma dwoch komorek z nadmiarem z poprzedniej liczby

    }



}

//n ilosc komorek w tablicy liczby a
//m ilosc komorek liczby b

void sub()
{

//odejmowanie jesli liczba1 > liczba2
    if(n>m || a[n-1]>b[n-1])
    {

        //odejmowanie kazdej komorki jak w odejmowaniu slupkowym
        for(int i=0; i<n; i++)
        {
            if(a[i]>b[i])
            {
                w[i]=a[i]-b[i];
            }
            else // jesli komorka liczby1 jest mniejsza od komorki z liczby2 zapozyczamy z kolejnej
                //komorki liczby1 jedynke i dodajemy jej wartosc do aktualnej komorki
            {
                a[i+1]=a[i+1]-1;
                a[i]=a[i]+1000000000;
                w[i]=a[i]-b[i];
            }

        }
    }
    else
// jesli liczba ktora chcemy odjac jest wieksza od liczby od ktorej odejmujemy
// zamieniamy je miejscami a wynik wypisujemy z minusem
    {

        for(int i=0; i<m; i++)
        {
            if(b[i]>a[i])
            {
                w[i]=b[i]-a[i];
            }
            else // jesli komorka liczby2 jest mniejsza od komorki z liczby1 zapozyczamy z kolejnej
                //komorki liczby2 jedynke i dodajemy jej wartosc do aktualnej komorki
            {
                b[i+1]=b[i+1]-1;
                b[i]=b[i]+1000000000;
                w[i]=b[i]-a[i];
            }

        }

        //  !printf -?

    }


}


void mult()
{

    unsigned long long karatsuba(unsigned int a[],unsigned int b[])
    {


//maxs wieksza z dlugosci liczb
        int rozmiar; // dlugosc podzielonej liczby na dwie czesci

// int potega = 10^n;

        if(maxs%2==0)
        {
            rozmiar=maxs/2;
        }
        else
        {
            rozmiar=(maxs/2) +1
        }


        unsigned int liczbaa1[rozmiar]; // pierwsza czesc liczby a

        unsigned int liczbaa2[rozmiar]; // druga czesc liczbya

        for(int i=0; i<rozmiar; i++)
        {

            liczbaa1[i]=a[rozmiar + i];

            liczbaa2[i]=a[i];
        }

        unsigned int liczbab1[rozmiar]; // pierwsza czesc liczby b

        unsigned int liczbab2[rozmiar]; // druga czesc liczby b


        for(int i=0; i<rozmiar; i++)
        {

            liczbab1[i]=b[rozmiar + i];

            liczbab2[i]=b[i];
        }

        ac= karatsuba(liczbaa1[],liczbab1[]);
        bd= karatsuba(liczbaa2[],liczbab2[]);
        e= karatsuba(sum1(liczbaa1[],liczbaa2[]),sum1(liczbab1,liczbab2));
        f=sum1(ac,bd);
        g=sub1(e[],f[]);


       // return w[]?

    }

}


void div()
{















}


void save(plik.txt)
{











}






unsigned long long sum1(unsigned int a[],unsigned int b[])
{

    w[0]=(a[0]+b[0])%1000000000+nadmiar;


    for (int i=1; i<maxs; i++)
    {


        nadmiar=((a[i-1]+b[i-1])-(a[i-1]+b[i-1])%1000000000)/1000000000;

        // nadmiar pierwsza cyfra sumy dwoch komorek tablic a i b jesli liczba przekracza 9 cyfr


        w[i]=((a[i]+b[i])%1000000000)+nadmiar;

        //suma dwoch komorek z nadmiarem z poprzedniej liczby

    }


    return w[];
}



void sub()
{

//odejmowanie jesli liczba1 > liczba2
    if(n>m || a[n-1]>b[n-1])
    {

        //odejmowanie kazdej komorki jak w odejmowaniu slupkowym
        for(int i=0; i<n; i++)
        {
            if(a[i]>b[i])
            {
                w[i]=a[i]-b[i];
            }
            else // jesli komorka liczby1 jest mniejsza od komorki z liczby2 zapozyczamy z kolejnej
                //komorki liczby1 jedynke i dodajemy jej wartosc do aktualnej komorki
            {
                a[i+1]=a[i+1]-1;
                a[i]=a[i]+1000000000;
                w[i]=a[i]-b[i];
            }

        }
    }
    else
// jesli liczba ktora chcemy odjac jest wieksza od liczby od ktorej odejmujemy
// zamieniamy je miejscami a wynik wypisujemy z minusem
    {

        for(int i=0; i<m; i++)
        {
            if(b[i]>a[i])
            {
                w[i]=b[i]-a[i];
            }
            else // jesli komorka liczby2 jest mniejsza od komorki z liczby1 zapozyczamy z kolejnej
                //komorki liczby2 jedynke i dodajemy jej wartosc do aktualnej komorki
            {
                b[i+1]=b[i+1]-1;
                b[i]=b[i]+1000000000;
                w[i]=b[i]-a[i];
            }

        }

        //  !printf -?

    }


}

