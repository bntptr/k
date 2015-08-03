/**
 * include:
 * pourquoi séparation avec source si projet code::block met tout ensemble?
 *
 * Constructeur : les objets obligatoire pour construire l'objet
 * Sinon les setter.
 *
 * serviceManager->setFactory(key, new factory);
 *
 * le createService du factory prend le serviceManager
 * et récupère tous les services dont l'objet à besoin lors de sa construction.
 *
 */

#include <iostream>
using namespace std;

#include "A.h"

int main()
{
    kstdlib::A a;
    kadriciel::A b;
    kgraphique::A c;

    cout << "AFFICHAGE KSTDLIB::A" << endl;
    a.print();
    cout << endl;

    cout << "AFFICHAGE KADRICIEL::A" << endl;
    b.print();
    cout << endl;

    cout << "AFFICHAGE KGRAPHIQUE::A" << endl;
    c.print();
    cout << endl;

    cout << "FIN INTEROGATION STATIC LIBRARY " << endl;
    return 0;
}

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
  // Constructeurs
  Point();
  Point(double x, double y);

  //Accesseurs et mutateurs
  void setX(double x);
  void setY(double y);
  double getX() const;
  double getY() const;

  // Autres méthodes
  double distance(const Point &P) const;
  Point milieu(const Point &P) const;

  void saisir();
  void afficher() const;

private:
  double x,y;
};

#endif

#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0)
{}

Point::Point(double x, double y) : x(x), y(y)
{}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::distance(const Point &P) const
{
    double dx = this->x - P.x;
    double dy = this->y - P.y;
    return sqrt(dx*dx + dy*dy);
}

Point Point::milieu(const Point &P) const
{
    Point result;
    result.x = (P.x + this->x) / 2;
    result.y = (P.y + this->y) / 2;
    return result;
}

void Point::saisir()
{
    cout << "Tapez l'abscisse : ";  cin >> this->x;
    cout << "Tapez l'ordonnée : ";  cin >> this->y;
}

void Point::afficher() const
{
    cout << "L'abscisse vaut " << this->x << endl;
    cout << "L'ordonnée vaut " << this->y << endl;
}


#include <iostream>
using namespace std;

#include "Point.h"

int main()
{
    Point A, B, C;
    double d;

    cout << "SAISIE DU POINT A" << endl;
    A.saisir();
    cout << endl;

    cout << "SAISIE DU POINT B" << endl;
    B.saisir();
    cout << endl;

    C = A.milieu(B);
    d = A.distance(B);

    cout << "MILIEU DE AB" << endl;
    C.afficher();
    cout << endl;

    cout << "La distance AB vaut : " << d << endl;
    return 0;
}
namespace kstdlib
{
    class A
    {
    public:
        int getValue() const { return this->value; } // définition au sein de la classe
        void setValue(int value);
        void print() const;
    private:
        int value;
    };

    inline void A::setValue(int value) // définition en dehors de la classe (inline)
    {
        this->value = value;
    }

    void A::print() const // définition en dehors de la classe (non inline)
    {
        std::cout << "Value=" << this->value << std::endl;
    }
} // kstdlib

#include <iostream>
using namespace std;

#include "A.h"

int main()
{
    kstdlib::A a;

    cout << "AFFICHAGE KSTDLIB::A" << endl;
    a.print();
    cout << endl;

    cout << "AFFICHAGE K::A" << endl;
    a.print();
    cout << endl;

    cout << "AFFICHAGE KSTDLIB::A" << endl;
    a.print();
    cout << endl;

    cout << "FIN INTEROGATION STATIC LIBRARY " << endl;
    return 0;
}

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
  // Constructeurs
  Point();
  Point(double x, double y);

  //Accesseurs et mutateurs
  void setX(double x);
  void setY(double y);
  double getX() const;
  double getY() const;

  // Autres méthodes
  double distance(const Point &P) const;
  Point milieu(const Point &P) const;

  void saisir();
  void afficher() const;

private:
  double x,y;
};

#endif

#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0)
{}

Point::Point(double x, double y) : x(x), y(y)
{}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::distance(const Point &P) const
{
    double dx = this->x - P.x;
    double dy = this->y - P.y;
    return sqrt(dx*dx + dy*dy);
}

Point Point::milieu(const Point &P) const
{
    Point result;
    result.x = (P.x + this->x) / 2;
    result.y = (P.y + this->y) / 2;
    return result;
}

void Point::saisir()
{
    cout << "Tapez l'abscisse : ";  cin >> this->x;
    cout << "Tapez l'ordonnée : ";  cin >> this->y;
}

void Point::afficher() const
{
    cout << "L'abscisse vaut " << this->x << endl;
    cout << "L'ordonnée vaut " << this->y << endl;
}


#include <iostream>
using namespace std;

#include "Point.h"

int main()
{
    Point A, B, C;
    double d;

    cout << "SAISIE DU POINT A" << endl;
    A.saisir();
    cout << endl;

    cout << "SAISIE DU POINT B" << endl;
    B.saisir();
    cout << endl;

    C = A.milieu(B);
    d = A.distance(B);

    cout << "MILIEU DE AB" << endl;
    C.afficher();
    cout << endl;

    cout << "La distance AB vaut : " << d << endl;
    return 0;
}
