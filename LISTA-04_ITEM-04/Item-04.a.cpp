#include <iostream>
#include <stack>
#include <queue>

class FilaXPilha // Implementação da PilhaTAD com as sentenças propostas na Atividade.
{
public:

// Declaração da função.

    void inverte(std::stack<char> *p1) // Função/Método para inverter a Pilha 'p1', com a utilização de Ponteiro da Pilha 'p1'.
    {
        std::queue<char> f1; // Declaração da Fila 1.

        while (!p1->empty()) // Laço de repetição (Enquanto a Pilha 1 não estiver vazia) - Fila 1 recebe os elementos da Pilha 1.
        {
            f1.push(p1->top()); // Fila 1 recebe o valor do 1º elemento da Pilha 1.
            p1->pop(); // Remove o 1º elemento da Pilha 1.
        }
        while (!f1.empty()) // Laço de repetição (Enquanto a Fila 1 não estiver vazia) - Pilha 1 recebe o 1º elemento da Fila 1.
        {
            p1->push(f1.front()); // Pilha 1 recebe o valor do 1º elemento da Fila 1.
            f1.pop(); // Remove o 1º elemento da Fila 1.
        }
    }
};

int main()
{
    std::stack<char> p1;

    FilaXPilha *p = new FilaXPilha();

    p->inverte(&p1);

    p1.push('a');
    p1.push('b');
    p1.push('c');
    p1.push('d');
    p1.push('e');

    while (!p1.empty())
    {
        std::cout << "\nValores da Fila 01: " << p1.top();
        p1.pop();
    }
    return 0;
}