#include<iostream>
using namespace std;

int Euclides(int a, int b)
{
	if(b==0)
		return a;
	int d=b;
	cout<<endl<<a<<" = "<< b<<"."<<a/b<<" + "<< a%b<<endl;
	b=a%b;
	a=d;
	if(a<0)
		a*=-1;
	return Euclides(a,b);
}

int main (int argc, char *argv[]) {
	int a,b;
	cout<<"Ingrese dos numeros\n";
	cin>>a>>b;
	cout<<"\nmcd("<<a<<","<<b<<")="<<Euclides(a,b);
	return 0;
}
