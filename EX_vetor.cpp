#include <iostream>
using namespace std;

#define MAX 29

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

float pop(Pilha *p, Pilha *i) {
	int podeDesempilharPar = (p->qtde > 0);
	int podeDesempilharImpar = (i->qtde > 0);
	float v;
	if (podeDesempilharImpar || podeDesempilharPar) {
		if(p->elementos[p->qtde-1]>i->elementos[i->qtde-1])
		{
			v = p->elementos[p->qtde-1];
			p->qtde--;
		}
		else
		{
			v = i->elementos[i->qtde-1];
			i->qtde--;
		}
	}
	else
	{
		v = -1;
	}
	return v;	
}


int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

void print(Pilha *p, Pilha *i) {
	cout <<endl<< "Qtde de elementos na pilha Par: " << p->qtde << endl;
	cout << "Qtde de elementos na pilha Impar: " << i->qtde << endl;
	int cp = p->qtde-1;
	int ci = i->qtde-1;
	for(int j=((p->qtde)+(i->qtde))-1; j>=0; --j) {
	
		if(p->elementos[cp]>i->elementos[ci])
		{
			cout << p->elementos[cp] << "  par"<< endl;
		 	cp--;
		}
		else
		{
			cout << i->elementos[ci] << "  impar"<< endl;
			ci--;
		}
	}
	cout << "--------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaImpar;
	pilhaImpar = new Pilha;
	pilhaImpar = init();
	
	Pilha *pilhaPar;
	pilhaPar = new Pilha;
	pilhaPar = init();
	
	cout << "Pilha Impar vazia: " << (isEmpty(pilhaImpar)?"SIM":"NAO") << endl;
	cout << "Pilha Par vazia: " << (isEmpty(pilhaPar)?"SIM":"NAO") << endl;
	int ultnum = -99999999;
	int atunum = 0;
	cout<<"Digite 30 numeros em ordem crescente: "<<endl;
	for(int i=1; i<=30;)
	{
		cout << i <<"- Digite o numero: "<<endl;
		cin >> atunum;
		if(atunum <= ultnum)
		{
			cout<<"error"<<endl;
			for(int j = 0; j <=1;)
			{
				cout <<"Digite um numero maior que o anterior empilhado: "<<endl;
				cin >> atunum;
				if(atunum <= ultnum)
				{
					cout<<"error"<<endl;
				}
				else
				{
					if(atunum%2==0)
					{
						cout << "Empilhado valor: " << (push(pilhaPar, atunum)?"SIM":"NAO") << endl;
					}
					else
					{
						cout << "Empilhado valor: " << (push(pilhaImpar, atunum)?"SIM":"NAO") << endl;
					}
					ultnum = atunum;
					j++;
				}
			}
			
		}
		else
		{
			if(atunum%2==0)
			{
				cout << "Empilhado valor: " << (push(pilhaPar, atunum)?"SIM":"NAO") << endl;
			}
			else
			{
				cout << "Empilhado valor: " << (push(pilhaImpar, atunum)?"SIM":"NAO") << endl;
			}
			ultnum = atunum;
			i++;
		}
	}
	
	
	
	
	cout << endl << "Pilha Impar vazia: " << (isEmpty(pilhaImpar)?"SIM":"NAO") << endl;
	cout << "Pilha Par vazia: " << (isEmpty(pilhaPar)?"SIM":"NAO") << endl;
	
	print(pilhaPar, pilhaImpar);
	
	for(int i = 1;i<=30;i++){
		cout << "Valor desempilhado: " << pop(pilhaPar,pilhaImpar) << endl;
	}
	
	return 0;	
}
