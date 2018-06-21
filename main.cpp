/*
Micha³ Szpunar 2AR PROJEKT 2

INSTRUKCJA OBS£UGI:

*/

#include <iostream>
#include "currency.h"
#include "client.h"
#include "interface.h"
#include <string>


using namespace std;

int main(){

currency<> pln(1,1,1, "PLN");
currency<> euro(4.5,4.2,4, "EURO");
currency<> usdollar(3.7,3.5,3.2, "USD");
currency<> gbp(5.1,5.0,4.9, "GBP");
currency<> frank(4.9,4.7,4.4, "FRANK");
currency<> bitcoin(10000, 9999, 9990, "BITCOIN");
currency<> yen(0.031, 0.03, 0.03, "YEN");
currency<> forint(0.011, 0.01, 0.01, "FORINT");
currency<> rubel(2.1, 2, 1.9, "RUBEL");
currency<> dinar(0.5, 0.49, 0.47, "DINAR");

currency<> kantor[10];
kantor[PLN]=pln;
kantor[EUR]=euro;
kantor[USD]=usdollar;
kantor[GBP]=gbp;
kantor[FRANK]=frank;
kantor[BTC]=bitcoin;
kantor[YEN]=yen;
kantor[FOR]=forint;
kantor[RUB]=rubel;
kantor[DIN]=dinar;

interface interfejs;
interfejs.run(kantor);

return 0;
}
