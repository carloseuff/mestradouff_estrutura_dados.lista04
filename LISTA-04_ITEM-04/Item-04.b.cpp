#include <iostream>
#include <stack>

class Pilhasx2
{
public:
            
    void inverte (std::stack<char>* p)
    {
        std::stack<char> pA;
        std::stack<char> pB;
      
        while (!p->empty())
        {
            pA.push(p->top());
            p->pop();
        }
        while (!pA.empty())
        {
            pB.push(pA.top());
            pA.pop();
        }
        while (!pB.empty())
        {
            pA.push(pB.top());
            pB.pop();
        }
        while (!pA.empty())
        {
            p->push(pA.top());
            pA.pop();
        }
    }

};

int main()
{

std::stack<char> p;

Pilhasx2 *px2 = new Pilhasx2();

    p.push('1');
    p.push('2');
    p.push('3');
    p.push('4');
    p.push('5');
    p.push('6');
    p.push('7');
    p.push('8');

    px2->inverte(&p);        
   

    while (!p.empty())
    {
        std::cout << "\nValores da PILHA: " << p.top();
        p.pop();
    }
return 0;
}