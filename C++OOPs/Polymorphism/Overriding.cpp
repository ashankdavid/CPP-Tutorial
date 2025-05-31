#include<iostream>
using namespace std;
class Mom
{
    public:
    void cook()
    {
        cout << "Cooking Indian" << endl;
    }
};

class Daughter : public Mom
{
    public:
    void cook()
    {
        cout << "Cooking Chinese" << endl;
    }

    void bake()
    {
        cout << "Baking Cakes" << endl;
    }
};
int main()
{
    Mom m;
    m.cook();
    Daughter d;
    d.cook();
}
