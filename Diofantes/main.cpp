#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void dividir(int a, int b, int c)
{
    vector<int> q, r, u, v;
    r.push_back(a);
    r.push_back(b);
    u.push_back(1);
    u.push_back(0);
    v.push_back(0);
    v.push_back(1);

    int n=0;

    // a=r  b=q1
    // r0= r1.q1+r2
    // r1= r2.q2+r3
    while(r[n+1]!=0) // b!=0
    {
        //int d=r[n+1];
        cout<<endl<<r[n]<<" = "<< r[n+1]<<"."<<r[n]/r[n+1]<<" + "<< r[n]%r[n+1]<<endl;
        q.push_back(r[n]/r[n+1]);
        r.push_back(r[n]%r[n+1]);
        n++;
    }
    q.pop_back();
    r.pop_back();
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
    cout<<endl<<endl;
    cout<<"q: \t   ";
    for(int i=0;i<q.size();i++)
        cout<<q[i]<<"    ";
    cout<<endl<<endl;
    cout<<"u: ";
    for(int i=0;i<u.size();i++)
        cout<<u[i]<<"   ";
    cout<<endl<<endl;
    cout<<"v: ";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"   ";
    cout<<endl<<endl;
    cout<<"r: ";
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<"   ";
    cout<<endl<<endl;

    int x=v[n],
        y=u[n];
    cout<<"u: "<<x<<endl<<endl
        <<"v: "<<y<<endl<<endl
        <<"x: "<<x*d<<endl<<endl
        <<"y: "<<y*d<<endl<<endl;
    cout<<x<<" * "<< d << " * " << b << " + " << y << " * " << d << " * " << a << " = " <<x*d*b+y*d*a<<endl;
    }
}

int main () {
	int a,b,c;
	cout<<"Ingrese tres numeros\n";
	cin>>a>>b>>c;
    dividir(a,b,c);
    return 0;
}