#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

void EucliExt(int a, int b)
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
    q.pop_back();
    r.pop_back();
    int i=r[n];
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
    cout<<endl
        <<"-----------------------"
        <<endl;
    cout<<"u: ";
    for(int i=0;i<u.size();i++)
        cout<<u[i]<<"   ";
    cout<<endl
        <<"-----------------------"
        <<endl;
    cout<<"v: ";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"   ";
    cout<<endl
        <<"-----------------------"
        <<endl;    cout<<"r: ";
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<"   ";
    cout<<endl<<endl;

    cout<<a<<" * "<<u[u.size()-1]<<" + "<<b<<" * "<< v[v.size()-1]<<" = "
        <<a*u[u.size()-1]<<" - "<<b*v[v.size()-1] <<" = "<<i<<endl<<endl;

}

int main () {
    system("title, EUCLIDES EXTENDIDO");
	int a,b;
	cout<<"Ingrese dos numeros\n";
	cin>>a>>b;
    EucliExt(a,b);
    return 0;
}
