#include <iostream>
#include <queue>

class Pilha2F // Implementação da PilhaTAD com as sentenças propostas na Atividade.
{
public:
    
    // Declaração de variáveis.

    std::queue<char> f1; // Fila 1 de elementos tipo char.
    std::queue<char> f2; // Fila 2 de elementos tipo char.

    // Declaração das Funções.

    char topo() // Função/Método para retorna o valor do elemento no início da Pilha.
    {
    return this->f1.front();
    }

    char desempilha() // Função/Método para remover o valor do elemento no fim da Pilha.
    {
    char r = this->f1.front(); //Aqui é armazanado o valor do elemento removido numa variável auxiliar tipo 'char', para um posterior retorno.
    this->f1.pop(); //Remove o 1º elemento da Fila 1.
    return r; // Variável 'r' retornada com o 1º elemento da Pilha.
    }

    void empilha(char dado) // Função/Método para inserir (criar a Pilha) o valor do elemento na Pilha.
    {
      while (!f1.empty()) // Laço de repetição (Enquanto a Fila 1 não estiver vazia) - o elemento tipo 'char' dado é inserido na Fila 2.
      {
        this->f2.push(f1.front()); // Fila 2 recebe o valor do 1º elemento da Fila 1.
        this->f1.pop(); // Remove o 1º elemento da Fila 1.
      }
    
    f1.push(dado); // Insere outro novo elemento tipo 'char' dado na Fila 1.

    while (!f2.empty()) // Laço de repetição (Enquanto a Fila 2 não estiver vazia) - o elemento tipo 'char' dado é inserido na Fila 01.
    {
        this->f1.push(f2.front());// Fila 1 recebe o valor do 1º elemento da Fila 2.
        this->f2.pop(); // Remove o 1º elemento da Fila 2.
    }
    }
};

int main()
{

    Pilha2F *p = new Pilha2F();

    p->empilha('a');
    p->desempilha();
    p->empilha('b');
    p->desempilha();
    p->empilha('c');
    p->desempilha();
    p->empilha('d');
    p->empilha('e');
    p->desempilha();
    p->empilha('e');
    p->desempilha();
    p->empilha('e');

    while (!(p->f1.empty() && p->f2.empty()))
    {
        std::cout << "\nPILHA 2F: " << p->topo() << std::endl;
        p->desempilha();
    }

    return 0;
}