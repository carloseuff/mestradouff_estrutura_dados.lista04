#include <iostream>
#include <queue>

class Filasx2 // Implementação da FilaTAD com as sentenças propostas na Atividade.
{
public:

    // Declaração da função.

    void inverte(std::queue<char> *f) // Função/Método para inverter a Fila 'f', com a utilização de Ponteiro da Fila 'f'.
    {
        std::queue<char> fA; // Declaração da Fila fA.
        std::queue<char> fB; // Declaração da Fila fB.
        int n = f->size(); // Declaração da variável n, que recebe o tamanho da Fila f.

        while (--n > 0) // Laço de repetição (Enquanto --n for maior 0) serão executados os laços e comandos abaixo.
        {
            for (int i = 0; i < n; i++) // Laço de repetição (Enquanto i for menor que n) - Fila fB recebe os elementos da Fila f.
            {
                fB.push(f->front()); // Fila fB recebe o valor do 1º elemento da Fila f.
                f->pop(); // Remove o 1º elemento da Fila f.
            }
            
            fA.push(f->front()); // Fila fA recebe o valor do 1º elemento da Fila f.
            f->pop(); // Remove o 1º elemento da Fila f.
            
            while (!fB.empty()) // Laço de repetição (Enquanto a Fila fB não estiver vazia) - Fila f recebe o 1º elemento da Fila fB.
            {
                f->push(fB.front()); // Fila f recebe o valor do 1º elemento da Fila fB.
                fB.pop(); // Remove o 1º elemento da Fila fB.
            }
        }
        
        fA.push(f->front()); // Fila fA recebe o valor do 1º elemento da Fila f.
        f->pop(); // Remove o 1º elemento da Fila f.
        
        while (!fA.empty()) // Laço de repetição (Enquanto a Fila fA não estiver vazia) - Fila f recebe o 1º elemento da Fila fA.
        {
            f->push(fA.front()); // Fila f recebe o valor do 1º elemento da Fila fA.
            fA.pop(); // Remove o 1º elemento da Fila fA.
        }
    }
};

int main()
{

    std::queue<char> f;

    Filasx2 *px2 = new Filasx2();

    px2->inverte(&f);

    f.push('0'); // FRONT
    f.push('1');
    f.push('2');
    f.push('3');
    f.push('4'); // BACK

    px2->inverte(&f);

    while (!f.empty())
    {
        std::cout << "\nValores da PILHA: " << f.front();
        f.pop();
    }
    return 0;
}