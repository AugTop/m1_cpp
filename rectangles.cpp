#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Rectangle
{
protected:
    int m_long;
    int m_larg;

public:
    Rectangle(int L, int l)
    {
        m_long = L;
        m_larg = l;
    }
    float surface()
    {
        return float(m_long) * float(m_larg);
    }
    void infos()
    {
        cout << "Rectangle : L=" << m_long << " l = " << m_larg << endl;
    }
};

class Parallelepipede : public Rectangle
{
private:
    int m_hauteur;

public:
    Parallelepipede(int L, int l, int h) : Rectangle(L, l)
    {
        m_hauteur = h;
    }

    float volume()
    {
        return surface() * m_hauteur;
    }

    void infos()
    {
        Rectangle::infos();
        cout << "hauteur de : " << m_hauteur << endl;
    }
};

int main()
{
    Rectangle *a = new Rectangle(20, 5);
    a->infos();

    cout << "On passe a la 3D" << endl;
    Parallelepipede p(4, 3, 10);
    p.infos();
    cout << "Volume :" << p.volume() << endl;
}