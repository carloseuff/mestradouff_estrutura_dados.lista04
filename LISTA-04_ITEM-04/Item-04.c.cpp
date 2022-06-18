#include <iostream>
#include <stack>


class PilhaXPilha
{
public:
      
    void inverte (std::stack<char>* f1)
    {
        std::stack<char> p1;
      
        while (!f1->empty())
        {
            p1.push(f1->top());
            f1->pop();
        }
        while (!p1.empty())
        {
            f1->push(p1.top());
            p1.pop();
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