#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct masina
{
    char brand[20], model[20];
    int cilindree, an;
} ma[100];

struct punct
{
    float x,y;
} p[2];

struct triunghi
{
    float u[3],l[3];
    punct p[3];
} t;


struct carte {
    char titlu[30], autor[30];
}ca[100];

void grafic(punct k,punct o)
{
    int y,b,x,i;
    float sl;
    sl=(o.y - k.y) / (o.x - k.x);

    b = o.y - (sl * o.x);
    for(y=19; y>=0; y--)
    {
        cout<<endl;
        if(y<10)
            cout<<y<<"  ";
        else
            cout<<y<<" ";
        for(x=0; x<20; x++)
        {
            if(x*sl +b< y+0.5 && x*sl +b>y-0.5)
                cout<<"1 ";
            else cout<<"0 ";
        }
    }
    cout<<endl<<endl<<"   ";
    for(x=0; x<20; x++)
        cout<<x%10<<" ";
}

void linie(punct k,punct o,int m[20][20])
{
    int y,b,x,ma,mi;
    float sl;
    if(o.x>k.x)
    {
        mi=k.x;
        ma=o.x;
    }
    else
    {
        ma=k.x;
        mi=o.x;
    }

    sl=(o.y - k.y) / (o.x - k.x);

    b = o.y - (sl * o.x);
    for(y=19; y>=0; y--)

        for(x=mi; x<=ma; x++)
        {
            if(x*sl +b< y+0.51 && x*sl +b>y-0.51)
                m[y][x]=1;
            else if(m[y][x]==0) m[y][x]=0;
        }

}


int main()
{
    int i,m[20][20]= {0},x,y,s,j,n,c, a=0;

    cout<<"Meniu principal:"<<endl<<"1.sortare carti"<<endl<<"2.sortare masini"<<endl<<"3.listare masini"<<endl<<"4.grafic"<<endl<<"5.linie"<<endl<<"6.triunghi"<<endl<<"Introduceti optiunea:";
    cin>>s;
    system("CLS");

    switch(s)
    {
    case 1:
        cout<<"Introduceti numarul de carti: ";
        cin>>n;
        cout<<endl<<"Introduceti date despre carti:"<<endl;
        cin.get();
        for(i=0; i<n; i++){
            cin.getline(ca[i].titlu, 30);
            cin.getline(ca[i].autor, 30);
        }

        for(i=0; i<n-1; i++){
            for(j = i+1; j<n; j++){
                if(strcmp(ca[i].autor, ca[j].autor) > 0)
                    swap(ca[i], ca[j]);
                else if(strcmp(ca[i].autor, ca[j].autor) == 0 && strcmp(ca[i].titlu, ca[j].titlu) > 0)
                    swap(ca[i], ca[j]);
            }
        }

        cout<<endl;
        for(i=0; i<n; i++)
            cout<<ca[i].titlu<<endl;

        break;
    case 2:
        cout<<"Numarul de masini disponibile: ";
        cin>>n;
        cout<<endl<<"Cilindreea dorita: ";
        cin>>c;
        cout<<"Specificatii masini: "<<endl;
        cin.get();
        for(i=0; i<n; i++){
            cin.get(ma[i].brand, 20);
            cin.get();
            cin.get(ma[i].model, 20);
            cin.get();
            cin>>ma[i].cilindree;
            cin>>ma[i].an;
            cin.get();
        }

        cout<<endl;

        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                if(strcmp(ma[i].brand, ma[j].brand) > 0) swap(ma[i], ma[j]);
            }
        }

        for(i=0; i<n; i++){
            if(ma[i].cilindree == c && ma[i].brand != ma[i-1].brand) cout<<ma[i].brand<<endl;
        }


        break;
    case 3:
        cout<<"Numarul de masini disponibile: ";
        cin>>n;
        cout<<endl<<"Anul dorit: ";
        cin>>c;
        cout<<"Specificatii masini: "<<endl;
        cin.get();
        for(i=0; i<n; i++){
            cin.get(ma[i].brand, 20);
            cin.get();
            cin.get(ma[i].model, 20);
            cin.get();
            cin>>ma[i].cilindree;
            cin>>ma[i].an;
            cin.get();
        }

        cout<<endl;
        masina mas[100];
        for(i=0; i<n; i++){
            if(ma[i].an==c)
            {
                mas[a] = ma[i];
                a++;
            }
        }
        for(i=0; i<a-1; i++){
            for(j=i; j<a; j++){
                if(strcmp(mas[i].model, mas[j].model) > 0)
                    swap(mas[i], mas[j]);
            }
        }
        for(i=0; i<a; i++){
            cout<<mas[i].model<<endl;
        }

        break;
    case 4:
        cout<<"Introduceti doua puncte(x,y < 20)";
        cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
        grafic(p[0],p[1]);
        break;
    case 5:
        cout<<"Introduceti doua puncte(x,y < 20)";
        cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;
        linie(p[0],p[1],m);
        for(y=19; y>=0; y--)
        {
            cout<<endl;
            for(x=0; x<20; x++)
                cout<<m[y][x]<<" ";
        }
        break;
    case 6:
        cout<<"Introduceti punctele triunghiului(x,y < 20)";
        for(i=0; i<=2; i++)
        {
            cin>>t.p[i].x;
            cin>>t.p[i].y;
        }
        linie(t.p[0],t.p[1],m);
        linie(t.p[1],t.p[2],m);
        linie(t.p[0],t.p[2],m);
        for(y=19; y>=0; y--)
        {
            cout<<endl;
            for(x=0; x<20; x++)
                cout<<m[y][x]<<" ";
        }
        break;
    }

}
