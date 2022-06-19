#include <iostream>

constexpr int MAXN = 5; // Capacidade máxima do deque (VETOR).

using namespace std;

class Deque1 // Implementação do DequeTAD com as sentenças propostas na Atividade.
{
public:
    
    // Declaração de variáveis.

    char elementos[MAXN]; // Vetor de Máximo de elementos.
    int N;                // Número de elementos.
    int inicio;           // Posição do início.
    int fim;              // Posição do fim.

   // Declaração das Funções.
   
    void cria() // inicialização  do deque, zerando o número de elementos.
    {
        this->N = 0;
        this->inicio = 0;
        this->fim = 0;
    }

    char ver_inicio() // Função/Método para retorna o valor do elemento no início.
    {
        return this->elementos[inicio];
    }

    void insere_inicio(char dado) // Função/Método para inseri no início  do deque o elemento "dado" tipo 'char'.
    {
        this->elementos[fim] = dado;
        this->fim = (fim + 1) % MAXN; /* O Elemento fim é incrementado com o resto da divisão entre o valor de fim (atualizado no laço) 
                                     + o valor Máximo de elementos MAXN, dessa forma é garantida que a Função/Método ultrapasse 
                                     o número de elementos do vetor elementos, pois se torna uma estratégia circular no Vetor, 
                                     caso o número de inserções for maior que MAXN.*/
        this->N++;
    }

    char remove_inicio() // Função/Método para Remover no início  do deque o elemento "dado" tipo 'char'.
    {
        char r = this->elementos[inicio];
        this->inicio = (inicio + 1) % MAXN; /*Idem da Explicação anteriopr para o %MAXN (resto da divisão entre o valor de fim 
                                            (atualizado no laço) + o valor Máximo de elementos MAXN).*/
        this->N--;
        return r;
    }
    char ver_fim() // Função/Método para retornar o elemento no fim do Deque.
    {
        return this->elementos[N + inicio - 1]; /* N é o número atual de elementos do deque, inicio é a posição atual do início 
                                                do deque e com o decremento de 1 é possível determinar a posição exata do fim do Deque.*/
    }

    void insere_fim(char dado) // Função/Método para inseri no fim do deque o elemento "dado" tipo 'char'.
    {
        this->elementos[fim] = dado;
        this->fim = (fim + 1) % MAXN;/*Idem da Explicação anteriopr para o %MAXN (resto da divisão entre o valor de fim 
                                     (atualizado no laço) + o valor Máximo de elementos MAXN).*/
        this->N++;
    }

    char remove_fim() // Função/Método para remover no fim do deque o elemento "dado" tipo 'char'.
    {
        char r = this->elementos[fim];
        this->fim = (fim + 1) % MAXN;/*Idem da Explicação anteriopr para o %MAXN (resto da divisão entre o valor de fim 
                                     (atualizado no laço) + o valor Máximo de elementos MAXN).*/
        this->N--;
        return r;
    }
};

int main()
{

    Deque1 *p = new Deque1();

    p->cria();
    p->insere_fim('p');
    p->insere_inicio('k');
    p->insere_fim('A');
    p->insere_inicio('B');
    p->insere_fim('C');

    cout << "\nValor de FIM------:" << p->fim + p->N << endl;
    cout << "\nValor de N........:" << p->N << endl;
    cout << "\nValor de INICIO...:" << p->inicio << endl;

    cout << "================================================" << endl;

    while (p->N > 0)
    {
        cout << "\nFrente da Fila..:" << p->ver_inicio() << endl;
        cout << "Fim da Fila..:" << p->ver_fim() << endl;
        cout << "\nValor de FIM------:" << p->N << endl;
        // p->remove_inicio();
        p->remove_fim();
    }
    cout << endl
         << "================================================" << endl;
    cout << "\nValor de FIM------:" << p->fim << endl;
    cout << "\nValor de N........:" << p->N << endl;
    cout << "\nValor de INICIO...:" << p->inicio << endl;
    return 0;
}
