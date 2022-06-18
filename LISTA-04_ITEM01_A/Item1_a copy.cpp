#include <iostream>
//#include <queue>

using namespace std;

constexpr int MAXN = 5; // capacidade máxima da fila

class FilaSeq3
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
    void libera() {} // nenhum recurso dinâmico para desalocar

    char frente()
    {
        return this->elementos[inicio];
    }
    void enfileira(char dado)
    {
        this->elementos[fim] = dado; // dado entra no fim
        this->fim = (fim + 1) % MAXN; // estratégia circular
        this->N++;
    }
    char desenfileira()
    {
        char r = this->elementos[inicio];
        this->inicio= (inicio + 1) % MAXN; // estratégia circular
        this->N--;
        return r;
    }
};

int main()
{

    FilaSeq3 *p = new FilaSeq3();

    p->cria();
    p->enfileira('A');
    p->enfileira('B');
    p->enfileira('C');
    /*p->enfileira('D');
    p->enfileira('E');
    /*p->enfileira('F');
    p->enfileira('G');
    p->enfileira('I');*/
    
    // std::cout << p->frente();
    // std::cout << p->desenfileira();
   
    while (p->N > 0)
    {
        cout <<"\nFrente da Fila..:" << p->desenfileira(); // <<" | Proxima da Fila..:" << p->frente()<<"\n";   
    }

    p->libera();

    return 0;
}