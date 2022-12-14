#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct masina {
    char brand[20], model[20];
    int cilindree, an;
}m[100];

int main()
{
    int i, j, n;
    int c;
    ifstream f("masini.in");
    f>>n; // cate masini sunt disponibile
    f>>c; //se citeste cilindreea specificata
    f.get();
    for(i=0; i<n; i++){
        f.get(m[i].brand, 20);
        f.get();
        f.get(m[i].model, 20);
        f.get();
        f>>m[i].cilindree;
        f>>m[i].an;
        f.get();
    }

    cout<<endl;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(m[i].brand, m[j].brand) > 0) swap(m[i], m[j]);
        }
    }

    for(i=0; i<n; i++){
        if(m[i].cilindree == c && m[i].brand != m[i-1].brand) cout<<m[i].brand<<endl;
    }


    //----------------------------------------
    cout<<endl;
    masina x[100];
    int a = 0;
    for(i=0; i<n; i++){
        if(m[i].an==2021)
        {
            x[a] = m[i];
            a++;
        }
    }
    for(i=0; i<a-1; i++){
        for(j=i; j<a; j++){
            if(strcmp(x[i].model, x[j].model) > 0)
                swap(x[i], x[j]);
        }
    }
    for(i=0; i<a; i++)
        cout<<x[i].model<<endl;

    f.close();
    return 0;
}
