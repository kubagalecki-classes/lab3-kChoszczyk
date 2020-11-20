#include <cmath>
#include <iostream>
using namespace std;

class BytGeometryczny
{
    virtual void id() = 0;
};

class Figura : public BytGeometryczny
{
protected:
    double pole;

public:
    Figura(){};
    Figura(double x) : pole(x){};

public:
    virtual ~Figura() { cout << "Zniszczylem Figure" << endl; };
    void         set(double zm) { pole = zm; }
    double       get() { return pole; }
    virtual void id() { cout << "Typ figury: Figura, pole: " << pole << endl; }
};

class Kolo : public Figura
{

public:
    virtual ~Kolo() { cout << "Zniszczylem Kolo" << endl; };
    Kolo() { set(0.0); };
    Kolo(double promien) : Figura{promien * promien * M_PI} {};
    void id() override { cout << "Typ figury: Kolo, pole: " << pole << endl; }
};
class Kwadrat : public Figura
{

public:
    virtual ~Kwadrat() { cout << "Zniszczylem Kwadrat" << endl; };
    Kwadrat() { set(0.0); };
    Kwadrat(double bok) : Figura{bok * bok} {};
    void id() override { cout << "Typ figury: Kwadrat, pole: " << pole << endl; }
};

class WektorFigur
{
public:
    WektorFigur() { tab = new Figura[1000]; };
    void dodaj(Figura& fig)
    {
        tab[licznik] = fig;
        licznik++;
    }
    Figura* operator[](Figura&);
    int licznik = 0;

    Figura* tab;
    ~WektorFigur() { delete[] tab; }
};

void id(Figura& fig)
{
    fig.id();
}

int main()
{

    // Kwadrat kwad1;
    // kwad1.id();
    //  Kwadrat kwad2(1);
    //    kwad2.id();
    // Kolo kol1;
    //  kol1.id();
    //    Kolo kol2(1);
    // kol2.id();
    //  id(kol2);
    // Figura kol_fig = static_cast< Figura >(kol2);
    // kol2.id();
    // kol_fig.id();

    // Figura*  f  = new Kwadrat{3};
    // Kolo*    ko = dynamic_cast< Kolo* >(f);
    // Kwadrat* kw = dynamic_cast< Kwadrat* >(f);
    // ko->id();
    // kw->id();

    // Zadanie 13
    // Figura* f = new Kwadrat{};
    // delete f;

    Kwadrat     kwad0(0);
    Kwadrat     kwad1(1);
    Kwadrat     kwad2(2);
    Kolo        kol0(0);
    Kolo        kol1(1);
    WektorFigur wektor;
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
    wektor.dodaj(kwad0);
    wektor.tab[0].id();
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
    wektor.dodaj(kwad1);
    wektor.tab[1].id();
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
    wektor.dodaj(kwad2);
    wektor.tab[2].id();
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
    wektor.dodaj(kol0);
    wektor.tab[3].id();
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
    wektor.dodaj(kol1);
    wektor.tab[4].id();
    cout << "Rozmiar obiektu " << sizeof(wektor) << endl;
}
