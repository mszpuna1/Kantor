#ifndef CLIENT_H
#define CLIENT_H

#include "currency.h"

/*portfel to 10-cio kolumnowa tablica, w której ka¿da kolumna odpowiada za iloœæ odpowiednio:
PLN, EUR, USD, GBP, FRANK, BTC, YEN, FOR, RUB, DIN*/
class client{
    float wallet[10];
public:
    client(){for(int i=0;i<10;i++)wallet[i]=10000.0;};
    ~client(){};
    void showwallet();
    void buy_with_pln(currency<> &c, int pick, float quantity);
    void sell_with_pln( currency<> &c, int pick, float quantity);
    void buy_with_curr( currency<> &c1, currency<> &c2, int pick1, int pick2, float quantity);
};
#endif // CLIENT_H

