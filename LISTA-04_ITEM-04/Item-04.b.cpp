#include <iostream>
#include <stack>

class Pilhasx2 // Implementação da PilhaTAD com as sentenças propostas na Atividade.
{
public:
    
    // Declaração da função.
    
    void inverte(std::stack<char> *p) // Função/Método para inverter a Pilha 'p', com a utilização de Ponteiro da Pilha 'p'.
    
    {
        std::stack<char> pA; // Declaração da Pilha A.
        std::stack<char> pB; // Declaração da Pilha B.

        while (!p->empty()) // Laço de repetição (Enquanto a Pilha p não estiver vazia) - Pilha A recebe os elementos da Pilha p.
        {
            pA.push(p->top()); // Pilha A recebe o valor do 1º elemento da Pilha p.
            p->pop(); // Remove o 1º elemento da Pilha p.
        }
        while (!pA.empty()) // Laço de repetição (Enquanto a Pilha A não estiver vazia) - Pilha p recebe o 1º elemento da Pilha A.
        {
            pB.push(pA.top()); // Pilha B recebe o valor do 1º elemento da Pilha A.
            pA.pop(); // Remove o 1º elemento da Pilha A.
        }
        while (!pB.empty()) // Laço de repetição (Enquanto a Pilha B não estiver vazia) - Pilha p recebe o 1º elemento da Pilha B.
        {
            p->push(pB.top()); // Pilha p recebe o valor do 1º elemento da Pilha B.
            pB.pop(); // Remove o 1º elemento da Pilha B.
        }
    }
};

int main()
{

    std::stack<char> p;

    Pilhasx2 *px2 = new Pilhasx2();

    px2->inverte(&p);

    p.push('1');
    p.push('2');
    p.push('3');
    p.push('4');
    p.push('5');
    p.push('6');
    p.push('7');
    p.push('8');

    while (!p.empty())
    {
        std::cout << "\nValores da PILHA: " << p.top();
        p.pop();
    }
    return 0;
}