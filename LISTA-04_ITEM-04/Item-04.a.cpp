#include <iostream>
#include <stack>
#include <queue>

class FilaXPilha
{
public:
      
    void inverte (std::queue<char>* f1)
    {
        std::stack<char> p1;
      
        while (!f1->empty())
        {
            p1.push(f1->front());
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
std::queue<char> f1;

FilaXPilha *p = new FilaXPilha();

    f1.push('b');
    f1.push('c');
    f1.push('d');
    f1.push('e');

    p->inverte(&f1);    
   

    while (!f1.empty())
    {
        std::cout << "\nValores da Fila 01: " << f1.front();
        f1.pop();
    }
return 0;
}