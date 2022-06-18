#include <iostream>

constexpr int MAXN = 5; // capacidade máxima da fila

using namespace std;

class Deque1
{
private:
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
        this->fim++;
        this->N++;
    }

    char remove_inicio()
    {
        char r = this->elementos[inicio];
        this->inicio++;
        this->N--;
        return r;
    }

    char ver_fim()
    {
        return this->elementos[fim-1];
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
    p->insere_inicio('C');
    p->insere_inicio('D');
    p->insere_inicio('E');
    p->insere_inicio('f');
    p->insere_inicio('g');

    /*p->cria();
    p->insere_fim('e');
    p->insere_fim('d');
    p->insere_fim('c');
    p->insere_fim('b');
    p->insere_fim('a');*/

    cout << "\nValor de N..:" << p->fim << endl;

    // cout << "\nFim da Fila..:" << p->ver_fim();

    while (p->N > 0)
    {
        // cout << "\nFrente da Fila..:" << p->remove_fim();
        // cout << "\nFim da Fila..:" << p->ver_fim();
        cout << "\nFrente da Fila..:" << p->ver_inicio() <<"\n | Fim da Fila..:" << p->ver_fim()<<"\n";
        p->remove_inicio();
    }

    return 0;
}
