#include <iostream>
#include <stack>


class PilhaXPilha // Implementação da PilhaTAD com as sentenças propostas na Atividade.
{
public:

    // Declaração da função.

    void inverte (std::stack<char>* f1) // Função/Método para inverter a Pilha 'f1', com a utilização de Ponteiro da Pilha 'f1'.
    {
        std::stack<char> p1; // Declaração da Pilha p1.
      
        while (!f1->empty()) // Laço de repetição (Enquanto a Pilha f1 não estiver vazia) - Pilha p1 recebe os elementos da Pilha f1.
        {
            p1.push(f1->top()); // Pilha P1 recebe o valor do 1º elemento da Pilha f1.
            f1->pop(); // Remove o 1º elemento da Pilha f1.
        }
        while (!p1.empty()) // Laço de repetição (Enquanto a Pilha p1 não estiver vazia) - Pilha f1 recebe o 1º elemento da Pilha P1.
        {
            f1->push(p1.top()); // Pilha f1 recebe o valor do 1º elemento da Pilha p1.
            p1.pop(); // Remove o 1º elemento da Pilha p1.
        }
    }

};

int main()
{
std::stack<char> f1;

PilhaXPilha *p = new PilhaXPilha();

    f1.push('b');
    f1.push('c');
    f1.push('d');
    f1.push('e');

    p->inverte(&f1);    
   

    while (!f1.empty())
    {
        std::cout << "\nValores da Fila 01: " << f1.top();
        f1.pop();
    }
return 0;
}