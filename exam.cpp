#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Fraction
{
private:
    int m_num;
    int m_denum;

public:
    Fraction(int num, int denum)
    {
        m_num = num,
        m_denum = denum;
    }
    float valeur()
    {
        return (float)m_num / m_denum;
    }

    float addition(Fraction &autre)
    {
        return valeur() + autre.valeur();
    }

    int getNum()
    {
        return m_num;
    }

    int getDenum()
    {
        return m_denum;
    }

    string returnFraction()
    {
        return to_string(m_num) + "/" + to_string(m_denum);
    }
};

int main()
{
    Fraction a(1, 3), b(1, 2);
    Fraction *c = new Fraction(1, 4);

    cout << "La valeur de la fraction " << a.returnFraction() << " est : " << a.valeur() << endl;
    cout << "La valeur de la fraction " << b.returnFraction() << " est : " << b.valeur() << endl;
    cout << "La valeur de la fraction " << c->returnFraction() << " est : " << c->valeur() << endl;

    cout << a.returnFraction() << " + " << b.returnFraction() << " =  " << a.addition(b) << endl;
    cout << a.returnFraction() << " + " << c->returnFraction() << " =  " << a.addition(*c) << endl;
    cout << c->returnFraction() << " + " << b.returnFraction() << " =  " << c->addition(b) << endl;
}