#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Point
{
protected: // Pour y avoir accès dans la fille Pointcol
    int m_y;
    int m_x;

public:
    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    int affiche_x()
    {
        return m_x;
    }

    int affiche_y()
    {
        return m_y;
    }

    string affiche()
    {
        return "[" + to_string(m_x) + "," + to_string(m_y) + "]";
    }

    void deplace(int dx, int dy)
    {
        m_x += dx;
        m_y += dy;
    }
};

class Pointcol : public Point
{
private:
    int m_cl;

public:
    Pointcol(int x, int y, int col) : Point(x, y)
    {
        m_cl = col;
    }
    void colore(int new_cl)
    {
        m_cl = new_cl;
    }

    string affiche_color()
    {
        return "[" + to_string(m_x) + "," + to_string(m_y) + "," + to_string(m_cl) + "]";
    }
};

int main()
{
    Point *a = new Point(5, 6);

    a->affiche();

    cout << "Point" << a->affiche() << endl;

    a->deplace(-1, -2);
    cout << "Point" << a->affiche() << endl;

    cout << "passage à la fonction fille" << endl;

    Pointcol b(10, 10, 10);
    b.colore(16);
    b.deplace(-2, 3);
    cout << "résultat : " << b.affiche_color() << endl;
}
