#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

void Diofantes(int a, int b, int c)
{
    vector<int> q, r, u, v;
    r.push_back(a); r.push_back(b);
    u.push_back(1); u.push_back(0);
    v.push_back(0); v.push_back(1);

    int n=0;

    while(r[n+1]!=0) // b!=0
    {
        cout<<endl<<r[n]<<" = "<< r[n+1]<<"."<<r[n]/r[n+1]<<" + "<< r[n]%r[n+1]<<endl;
        q.push_back(r[n]/r[n+1]);
        r.push_back(r[n]%r[n+1]);
        n++;
    }
    q.pop_back(); r.pop_back();
    if(c%r[n]!=0)
    {
        cout<<endl<<" No existe una solucion"<<endl;
    }
    else
    {
    int d=c/r[n];
    cout<<endl<<endl;
    for(int i=2;i<=n;i++)
    {
        int temp;
        temp=u[i-2]-(q[i-2]*u[i-1]);
        u.push_back(temp);
        temp=v[i-2]-(q[i-2]*v[i-1]);
        v.push_back(temp);
    }
    int x=v[n],
        y=u[n];
    cout<<"u: "<<x<<endl<<endl
        <<"v: "<<y<<endl<<endl
        <<"x: "<<x*d<<endl<<endl
        <<"d: "<<d<<endl<<endl
        <<"y: "<<y*d<<endl<<endl;
    cout<<x<<" * "<< d << " * " << b << " + " << y << " * "
        << d << " * " << a << " = " <<x*d*b+y*d*a<<endl;
    }
}

int main () {
    system("title, DIOFANTES");
	int a,b,c;
	cout<<"Ingrese tres numeros\n";
	cin>>a>>b>>c;
    Diofantes(a,b,c);
    return 0;
}
