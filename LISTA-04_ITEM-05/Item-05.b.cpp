#include <iostream>
#include <queue>

class Filasx2
{
public:
    void inverte(std::queue<char> *f)
    {
        std::queue<char> fA;
        std::queue<char> fB;
        int n = f->size();

        while (--n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                fB.push(f->front());
                f->pop();
            }
            
            fA.push(f->front());
            f->pop();
            
            while (!fB.empty()){
                f->push(fB.front());
                fB.pop();
            }
        }
        
        fA.push(f->front());
        f->pop();
        
        while (!fA.empty())
        {
            f->push(fA.front());
            fA.pop();
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