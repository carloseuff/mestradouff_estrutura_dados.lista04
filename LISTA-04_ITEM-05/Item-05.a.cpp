#include <iostream>
#include <stack>
#include <queue>


class FilaxPilha // Implementação da FilaTAD com as sentenças propostas na Atividade.
{
public:
    
    // Declaração da função.
    
    void inverte(std::queue<char> *f1) // Função/Método para inverter a Fila 'f1', com a utilização de Ponteiro da Fila 'f1'.
    {
        std::stack<char> p1; // Declaração da Pilha p1.

        while (!f1->empty()) // Laço de repetição (Enquanto a Fila f1 não estiver vazia) - Pilha p1 recebe os elementos da Fila f1.
        {
            p1.push(f1->front()); // Pilha P1 recebe o valor do 1º elemento da Fila f1.
            f1->pop(); // Remove o 1º elemento da Fila f1.
        }
        while (!p1.empty()) // Laço de repetição (Enquanto a Pilha p1 não estiver vazia) - Fila f1 recebe o 1º elemento da Pilha P1.
        {
            f1->push(p1.top()); // Fila f1 recebe o valor do 1º elemento da Pilha p1.
            p1.pop(); // Remove o 1º elemento da Pilha p1.
        }
    }
};

int main()
{
    std::queue<char> f1;

    FilaxPilha *p = new FilaxPilha();

    f1.push('b');
    f1.push('c');
    f1.push('d');
    f1.push('e');
    
    p->inverte(&f1);

    while (!f1.empty())
    {
        std::cout << "\nValores da Fila 01: " << f1.front();
        f1.pop();
    }
    return 0;
}