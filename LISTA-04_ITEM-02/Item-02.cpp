#include <iostream>
#include <queue>

class Pilha2F
{
public:
    std::queue<char> f1;
    std::queue<char> f2;

    char topo()
    {
    return this->f1.front();
    }

    char desempilha()
    {
    char r = this->f1.front();
    this->f1.pop();
    return r;
    }

    void empilha(char dado)
    {
      while (!f1.empty())
      {
        this->f2.push(f1.front());
        this->f1.pop();
      }
    f1.push(dado);

    while (!f2.empty())
    {
        this->f1.push(f2.front());
        this->f2.pop();
    }
    }

    bool filas_vazia()
    {
    return this->f1.empty() && f2.empty();
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

    //std::cout << "\nPILHA 2F: " << p->topo() << std::endl;*/

    //while (!p->filas_vazia())
    while (!(p->f1.empty() && p->f2.empty()))
    {
        std::cout << "\nPILHA 2F: " << p->topo() << std::endl;
        p->desempilha();
    }

    return 0;
}