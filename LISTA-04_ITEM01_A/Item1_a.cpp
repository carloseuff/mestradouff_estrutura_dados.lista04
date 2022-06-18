#include <iostream>

constexpr int MAXN = 5; // capacidade máxima do deque

using namespace std;

class Deque1
{
public:
    char elementos[MAXN];
    int N; 
    int inicio;
    int fim;

    void cria()
    {
        this->N = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    char ver_inicio()
    {
        return this->elementos[inicio];
    }

    void insere_inicio(char dado) 
    {
        this->elementos[fim] = dado;
        this->fim = (fim + 1) % MAXN;
        this->N++;
    }

    char remove_inicio()
    {
        char r = this->elementos[inicio];
        this->inicio = (inicio + 1) % MAXN;
        this->N--;
        return r;
    }

    char ver_fim()
    {
        return this->elementos[N + inicio - 1];
    }

    void insere_fim(char dado)
    {
        this->elementos[fim] = dado;
        this->fim = (fim + 1) % MAXN;
        this->N++;
    }

    char remove_fim()
    {
        char r = this->elementos[fim];
        this->fim = (fim + 1) % MAXN;
        this->N--;
        return r;
    }
};

int main()
{

    Deque1 *p = new Deque1();

    p->cria();
    p->insere_inicio('A');
    p->insere_inicio('B');
    p->insere_fim('E');
    p->insere_fim('D');
    p->insere_inicio('g');

    cout << "\nValor de FIM------:" << p->fim+p->N << endl;
    cout << "\nValor de N........:" << p->N << endl;
    cout << "\nValor de INICIO...:" << p->inicio << endl;

    cout << "================================================" << endl;

    while (p->N > 0)
    {
        cout << "\nFrente da Fila..:" << p->ver_inicio() << endl;
        cout << "Fim da Fila..:" << p->ver_fim() << endl;
        cout << "\nValor de FIM------:" << p->N << endl;
        p->remove_fim();
    }
    cout <<endl << "================================================" << endl;
    cout << "\nValor de FIM------:" << p->fim << endl;
    cout << "\nValor de N........:" << p->N << endl;
    cout << "\nValor de INICIO...:" << p->inicio << endl;
    return 0;
}
