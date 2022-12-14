#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/*  Intr-o librarie sunt n carti. Sa se afiseze titlurile de carti in ordinea lexicografica a numelor autorilor.
    Daca exista mai multe carti de acelasi autor, sa se afiseze cartile sortate dupa titlu */

struct carte {
    char titlu[30], autor[30];
}c[100];

int main()
{
    int n, i, j;
    ifstream f("carti.in");
    f>>n;
    f.get();
    for(i=0; i<n; i++){
        f.getline(c[i].titlu, 30);
        f.getline(c[i].autor, 30);
    }

    for(i=0; i<n-1; i++){
        for(j = i+1; j<n; j++){
            if(strcmp(c[i].autor, c[j].autor) > 0)
                swap(c[i], c[j]);
            else if(strcmp(c[i].autor, c[j].autor) == 0 && strcmp(c[i].titlu, c[j].titlu) > 0)
                swap(c[i], c[j]);
        }
    }

    for(i=0; i<n; i++)
        cout<<c[i].titlu<<endl;
    return 0;
}
