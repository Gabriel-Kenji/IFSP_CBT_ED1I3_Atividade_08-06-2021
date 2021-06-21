#include <iostream>
using namespace std;

struct No {
	int dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int push(Pilha *p, int v) {
	No *no = new No;
	int i = 0;
	No* n;
	n = p->topo;
	while (n != NULL) {
		i++;
		n = n->prox;
	}
	int podeEmpilhar = (i < 30);
	if(podeEmpilhar)
	{
		no->dado = v;
		no->prox = p->topo;
		p->topo = no;
	}
	return podeEmpilhar;
	
}

float pop(Pilha *p, Pilha* i) {
	float ret;
	int podeDesempilharPar = (p->topo != NULL);
	int podeDesempilharImpar = (i->topo != NULL);
	if (podeDesempilharPar || podeDesempilharImpar) {
	   No *np = p->topo;
	   No *ni = i->topo;
	   if(podeDesempilharPar)
		{
			if(podeDesempilharImpar){
				if(np->dado > ni->dado  )
				{
				   	ret = np->dado;
				   	p->topo = p->topo->prox;
				   	free(np);
				}
				else
				{
					ret = ni->dado;
					i->topo = i->topo->prox;
					free(ni);
				}
			}
			else
			{
	  		    ret = np->dado;
				p->topo = p->topo->prox;
			   	free(np);
			}	
		}
		else
		{
		   ret = ni->dado;
		   i->topo = i->topo->prox;
		   free(ni);
		}
		
	}
	else
	{
	
	
		ret = -1;
	}
	return ret;
}

void print(Pilha* p, Pilha* i) {
	No* np;
	No* ni;
	np = p->topo;
	ni = i->topo;
	while (np != NULL || ni != NULL) {	
		if(np != NULL )
		{
			if(ni != NULL){
				if(np->dado > ni->dado  )
				{
				
					cout << np->dado << " par" << endl;
					np = np->prox;
				}
				else
				{
					cout << ni->dado << " impar"<< endl;
					ni = ni->prox;
				}
			}
			else
			{
				cout << np->dado << " par" << endl;
				np = np->prox;
			}	
		}
		else
		{
			cout << ni->dado << " impar"<< endl;
			ni = ni->prox;
		}
	}
	cout << "--------------------" << endl;
}


int count(Pilha* p) {
	int i = 0;
	No* n;
	n = p->topo;
	while (n != NULL) {
		i++;
		n = n->prox;
	}
	return i;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void freePilha(Pilha *p) {
	No *n = p->topo;
	while(n != NULL) {
		No *t = n->prox;
		free(n);
		n = t;
	}
	free(p);
}


int main(int argc, char** argv)
{
	Pilha *pilhaPar;
	pilhaPar = init();
	Pilha *pilhaImpar;
	pilhaImpar = init();
	
	
	
		
	cout << "Pilha Par vazia: " << (isEmpty(pilhaPar)?"SIM":"NAO") << endl;
	cout << "Pilha Impar vazia: " << (isEmpty(pilhaImpar)?"SIM":"NAO") << endl<< endl;

	int ultnum = -99999999;
	int atunum = 0;
	cout<<"Digite 30 numeros em ordem crescente: "<<endl;
	for(int i=1; i<=10;)
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
	
	
	
	
	
	
	
	cout << endl << "Pilha Par vazia: " << (isEmpty(pilhaPar)?"SIM":"NAO") << endl;
	cout << "Pilha Impar vazia: " << (isEmpty(pilhaImpar)?"SIM":"NAO") << endl << endl;
	
	cout << "Qtde elementos na pilha Par: " << count(pilhaPar) << endl;
	cout << "Qtde elementos na pilha Impar: " << count(pilhaImpar) << endl << endl;
	
	cout << "Exibindo pilhas par e impar de forma decrescente"<< endl;
	print(pilhaPar, pilhaImpar);
	
	cout <<endl << "Desempilhando pilhas par e impar de forma decrescente"<< endl;
	for(int i = 1; i<=10;i++)
	{
		cout << "Desempilhado valor: " << pop(pilhaPar, pilhaImpar) << endl;
	}
	
	freePilha(pilhaImpar);
	freePilha(pilhaPar);
	
}
