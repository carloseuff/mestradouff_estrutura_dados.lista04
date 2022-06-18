#include <iostream>
#include <stack>

class Fila2P
{
public:
    std::stack<char> p1;
    std::stack<char> p2;
    int N = 0;

    char topo()
    {
        while (!p1.empty())
        {
            this->p2.push(p1.top());
            this->p1.pop();
        }
        char r = this->p2.top();
        while (!p1.empty())
        {
            this->p1.push(p2.top());
        }
        return r;
    }

    char desempilha()
    {
        while (!p1.empty())
        {
            p2.push(p1.top());
            p1.pop();
        }

        char r = p2.top();
        p2.pop();

        while (!p2.empty())
        {
            p1.push(p2.top());
            p2.pop();
            return r;
        }
        this->N--;
    }

    void empilha(char dado)
    {
        p1.push(dado);
        this->N++;
    }
};

int main()
{

    Fila2P *p = new Fila2P();

    p->empilha('a');

    p->empilha('b');
    // p->desempilha();
    p->empilha('c');

    p->empilha('d');
    p->empilha('e');
    // p->desempilha();
    p->empilha('U');
    p->empilha('W');

    std::cout << "\nVALOR DE N: " << p->N << std::endl;

    
    while (p->N != 0)
    {
        std::cout << "\nPILHA 2F: " << p->topo() << std::endl;
        p->desempilha();
    }
    
    return 0;
}