#include <iostream>
#include <string>
using namespace std;
typedef struct inf{
	string nume;
	double nr;
}info;

typedef struct nod
{
	info x;
	struct nod *urm;
}NOD;

NOD *varf;

void creeaza()
{
	varf=NULL;
}

int vida()
{
	if (varf==NULL) return 1;
	else return 0;
}

void pune(double a,string b)
{
	NOD *p=new NOD;
	p->x.nr=a;
	p->x.nume=b;
	p->urm=varf;
	varf=p;
}

info scoate()
{
	NOD *p;
	info a;
	p=varf;
	varf=varf->urm;
	a.nume=p->x.nume;
	a.nr=p->x.nr;
	delete(p);
	return a; 

}


void main()
{
	info b;
	creeaza();
	do{
		cout << "Dati un nume:" << endl;
		cin >> b.nume;
		cout<<"Dati un numar : ";
		cin >> b.nr;
		
		
		if(b.nr!=0.0) pune(b.nr,b.nume);
	}while(b.nr!=0.0);
	cout<<"Numerele din stiva sunt : "<<endl;
	while (!vida())
	{
		b=scoate();
		cout<<b.nume<<endl;
		cout << b.nr << endl;
		
	}
	system("pause");
}
