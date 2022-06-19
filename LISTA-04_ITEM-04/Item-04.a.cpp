#include <iostream>
#include <stack>
#include <queue>

class FilaXPilha
{
public:
    void inverte(std::stack<char> *p1)
    {
        std::queue<char> f1;

        while (!p1->empty())
        {
            f1.push(p1->top());
            p1->pop();
        }
        while (!f1.empty())
        {
            p1->push(f1.front());
            f1.pop();
        }
    }
};

int main()
{
    std::stack<char> p1;

    FilaXPilha *p = new FilaXPilha();

    p->inverte(&p1);

    p1.push('a');
    p1.push('b');
    p1.push('c');
    p1.push('d');
    p1.push('e');

    while (!p1.empty())
    {
        std::cout << "\nValores da Fila 01: " << p1.top();
        p1.pop();
    }
    return 0;
}