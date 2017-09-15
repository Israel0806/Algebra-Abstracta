#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

int returnModulo(int &a, int &b)
{
    bool cond=false;
        if(a<-b)
        {
            a*=-1;
            cond=true;
        }
        if(a>=b)
        {
            a=a%b;

            if(cond)
                a*=-1;
        }
        if(a<0)
        {
            a=b+a;
        }
    return a;
}

void comprobarMOD(int &a, int &b)
{
    bool cond=false;
    if(a<-b)
    {
        a*=-1;
        cond=true;
    }
    if(a>=b)
    {
        a=a%b;

        if(cond)
            a*=-1;
    }
    if(a<0)
    {
        a=b+a;
    }
}

int Euclides(int &a, int &b)
{
	if(a==0)
		return b;
	int d=a;
	a=b%a;
	b=d;
	if(b<0)
		b*=-1;
	return Euclides(a,b);
}

class Modulo {
public:
    int a,b,ex;
    Modulo() {}
    Modulo(int _a, int _b) :a(_a), b(_b) {}
    Modulo(int _a, int _b, int _ex ) :a(_a), b(_b), ex(_ex) {}
    Modulo(const Modulo &A) { a=A.a; b=A.b; }

    friend void comprobarMOD(int &a, int &b);
    friend int returnModulo(int &a, int &b);

    friend Modulo operator *(Modulo A, Modulo B)
    {
        Modulo c;
        c.a= returnModulo(A.a,A.b) * returnModulo(B.a,B.b);
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        cout<<"El modulo es:\n "
            <<c.a<<"mod"<<c.b<<endl;
        return c;
    }
    void Inverso()
    {
        Modulo temp(a,b);
        int mcd=Euclides(temp.a,temp.b);
        if(mcd==1)
        {
            Modulo m(a,b);
            for(int i=1;i<m.b;i++)
            {
                int x=m.a*i;
                int temp=returnModulo( x, m.b);
                if(temp==1)
                {
                    cout<<"Inverso: "<<i<<endl;
                    break;
                }

            }
        }
        else
        {
            cout<<"No existe inversa\n";
        }
    }


    int Exponente()
    {
        long long r = 1;
        long long _b=b;
        long long y = a;
        int mod=ex;
        while (_b > 0)
        {
            if ((_b&1)==1)
                r = (r * y)% mod;
            _b>>=1;
            y=((y%mod)*(y%mod))%mod;
        }
        cout<<"modulo: "<<mod<<endl
            <<"base: "<<a<<endl
            <<"exponente: "<<b<<endl
            <<"resultado: "<<r<<endl<<endl;
        return r;
    }
};


int main()
{
    int op;
    bool cond=true;
    while(cond)
    {
        cout<<"\t\t\t\t\t\tCalculadora modular  \n"
            <<"Ingrese una Opcion:  \n"
            <<"1. Multiplicacion    \n"
            <<"2. Inversa           \n"
            <<"3. Exponenciacion    \n"
            <<"4. Salir             \n";
        cin>>op;
        switch(op)
        {
            int a,b,c;
            case 1:
            {
            cout<<"Ingrese dos numeros\n"; cin>>a>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c), B(b,c);
            Modulo C=A*B;
            break;
            }
            case 2:
            {
            cout<<"Ingrese un numero\n"; cin>>a;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c);
            A.Inverso();

            break;
            }
            case 3:
            {
            cout<<"Ingrese dos numeros\n Base: "; cin>>a;
            cout<<"Exponente: "; cin>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,b,c);
            int resultado = A.Exponente();
            cout<<"Resultado: "<<resultado;
            comprobarMOD(resultado,A.ex);
            cout<<" % "<<A.ex<<" = "<<resultado<<endl;
            break;
            }
            case 4:
                break;
            default:
                {
                cout<<"Ingrese una opcion correcta\n";
                cin>>op;
                break;
                }
        }
        if(op!=4)
        {
            char rpta;
            cout<<"\n\nDesea realizar otra operacion--> "; cin>>rpta;
            (rpta=='s' or rpta== 'S')?cond=true:cond=false;
            system("pause");
            system("cls");
        }
        else
            cond=false;

    }


    return 0;
}



/*
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

int returnModulo(int &a, int &b)
{
    bool cond=false;
        if(a<-b)
        {
            a*=-1;
            cond=true;
        }
        if(a>=b)
        {
            a=a%b;

            if(cond)
                a*=-1;
        }
        if(a<0)
        {
            a=b+a;
        }
    return a;
}

void comprobarMOD(int &a, int &b)
{
    bool cond=false;
    if(a<-b)
    {
        a*=-1;
        cond=true;
    }
    if(a>=b)
    {
        a=a%b;

        if(cond)
            a*=-1;
    }
    if(a<0)
    {
        a=b+a;
    }
}

int Euclides(int &a, int &b)
{
	if(a==0)
		return b;
	int d=a;
	a=b%a;
	b=d;
	if(b<0)
		b*=-1;
	return Euclides(a,b);
}

class Modulo {
public:
    int a,b,ex;
    Modulo() {}
    Modulo(int _a, int _b) :a(_a), b(_b) {}
    Modulo(int _a, int _b, int _ex) :a(_a), b(_b), ex(_ex) {}
    Modulo(const Modulo &A) { a=A.a; b=A.b; }

    friend void comprobarMOD(int &a, int &b);
    friend int returnModulo(int &a, int &b);

    friend Modulo operator *(Modulo A, Modulo B)
    {
        Modulo c;
        c.a= returnModulo(A.a,A.b) * returnModulo(B.a,B.b);
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        cout<<"El modulo es:\n "
            <<c.a<<"mod"<<c.b<<endl;
        return c;
    }
    void Inverso()
    {
        Modulo temp(a,b);
        int mcd=Euclides(temp.a,temp.b);
        if(mcd==1)
        {
            Modulo m(a,b);
            for(int i=1;i<m.b;i++)
            {
                int x=m.a*i;
                int temp=returnModulo( x, m.b);
                if(temp==1)
                {
                    cout<<"Inverso: "<<i<<endl;
                    break;
                }

            }
        }
        else
        {
            cout<<"No existe inversa\n";
        }
    }


    int Exponente()
    {
        int modulo=ex;
        int base=a;
        int exponent=b;
        int result=1;

        while(exponent>0)
        {
            if(exponent%1==1)
                result=(base*result)%modulo;
            exponent>>=1;
            base=(base%modulo)*(base%modulo)%modulo;
        }
        cout<<"modulo: "<<ex<<endl
            <<"base: "<<a<<endl
            <<"exponente: "<<b<<endl
            <<"resultado: "<<result<<endl<<endl;
        return result;
    }
};


int main()
{
    int op;
    bool cond=true;
    while(cond)
    {
        cout<<"\t\t\t\t\t\tCalculadora modular  \n"
            <<"Ingrese una Opcion:  \n"
            <<"1. Multiplicacion    \n"
            <<"2. Inversa           \n"
            <<"3. Exponenciacion    \n"
            <<"4. Salir             \n";
        cin>>op;
        switch(op)
        {
            int a,b,c;
            case 1:
            {
            cout<<"Ingrese dos numeros\n"; cin>>a>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c), B(b,c);
            Modulo C=A*B;
            break;
            }
            case 2:
            {
            cout<<"Ingrese un numero\n"; cin>>a;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c);
            A.Inverso();

            break;
            }
            case 3:
            {
            cout<<"Ingrese dos numeros\n Base: "; cin>>a;
            cout<<"Exponente: "; cin>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,b,c);
            int resultado = A.Exponente();
            cout<<"Resultado: "<<resultado;
            comprobarMOD(resultado,A.ex);
            cout<<" % "<<A.ex<<" = "<<resultado<<endl;
            break;
            }
            case 4:
                break;
            default:
                {
                cout<<"Ingrese una opcion correcta\n";
                cin>>op;
                break;
                }
        }
        if(op!=4)
        {
            char rpta;
            cout<<"\n\nDesea realizar otra operacion--> "; cin>>rpta;
            (rpta=='s' or rpta== 'S')?cond=true:cond=false;
            system("pause");
            system("cls");
        }
        else
            cond=false;

    }


    return 0;
}
*/
