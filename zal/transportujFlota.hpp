#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    Stocznia     stocznia{};
    unsigned int suma = 0;
    unsigned int teraz;
    unsigned int zagi = 0;

    while (suma < towar) {
        Statek* s1 = stocznia();
        teraz      = s1->transportuj();
        suma += teraz;
        if (dynamic_cast< Zaglowiec* >(s1))
            zagi++;
    }

    return zagi;
}