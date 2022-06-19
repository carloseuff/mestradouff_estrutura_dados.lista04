#include <iostream>
#include <stack>

class Fila2P // Implementação da FilaTAD com as sentenças propostas na Atividade.
{
public:
    
    // Declaração de variáveis.

    std::stack<char> p1; // Pilha 1 de elementos tipo char.
    std::stack<char> p2; // Pilha 2 de elementos tipo char.
    
    int N = 0;

    // Declaração das Funções.

    void enfileira(char dado) // Função/Método para inserir (criar a Fila) o valor do elemento na Fila.
    {
        p1.push(dado); // Insere os valores dos elementos na Pilha 1.
        this->N++; // Incrementa o valor da variável N.
    }
    
    char front() // Função/Método para retorna o valor do elemento no início da Fila.
    {
        while (!p1.empty()) // Laço de repetição (Enquanto a Pilha 1 não estiver vazia) - Pilha 2 recebe os elementos da Pilha 1.
        {
            this->p2.push(p1.top()); // Pilha 2 recebe o valor do 1º elemento da Pilha 1.
            this->p1.pop(); // Remove o 1º elemento da Pilha 1.
        }
        
        char r = this->p2.top(); // Variável 'r' recebe o valor do 1º elemento da Pilha 2.
        
        while (!p1.empty()) // Laço de repetição (Enquanto a Pilha 1 não estiver vazia) - Pilha 1 recebe o 1º elemento da Pilha 2.
        {
            this->p1.push(p2.top()); // Pilha 1 recebe o valor do 1º elemento da Pilha 2.
        }
        return r;// Variável 'r' retornada com o 1º elemento da Fila.
    }

    char desenfileira() // Função/Método para remover o valor do elemento no início da Fila.
    {
        while (!p1.empty()) // Laço de repetição (Enquanto a Pilha 1 não estiver vazia) - Pilha 2 recebe o 1º elemento da Pilha 1.
        {
            p2.push(p1.top()); // Pilha 2 recebe o valor do 1º elemento da Pilha 1.
            p1.pop(); // Remove o 1º elemento da Pilha 1.
        }

        char r = p2.top(); // Variável 'r' recebe o valor do 1º elemento da Pilha 2.

        p2.pop(); // Remove o 1º elemento da Pilha 2.

        while (!p2.empty()) //
        {
            p1.push(p2.top()); // Pilha 1 recebe o valor do 1º elemento da Pilha 2.
            p2.pop(); // Remove o 1º elemento da Pilha 2.
            return r;  // Variável 'r' retornada com o 1º elemento da Pilha 2.
        }
        this->N--; // Decrementa o valor da variável N.
    }
};

int main()
{

    Fila2P *p = new Fila2P();

    p->enfileira('a');

    p->enfileira('b');
    // p->desenfileira();
    p->enfileira('c');

    p->enfileira('d');
    p->enfileira('e');
    // p->desenfileira();
    p->enfileira('U');
    p->enfileira('W');

    std::cout << "\nVALOR DE N: " << p->N << std::endl;

    
    while (p->N != 0)
    {
        std::cout << "\nFila 2P: " << p->front() << std::endl;
        p->desenfileira();
    }
    
    return 0;
}