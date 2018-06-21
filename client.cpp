#include <iostream>
#include <cstdlib>
#include "currency.h"
#include "client.h"

using namespace std;


void client::buy_with_pln(currency<> &c, int pick, float quantity){
float temp;
temp=c.buyvalue.back();
if (pick==PLN)
    cout<<"Impossible"<<endl;
else if (quantity>(wallet[PLN]*temp))
    cout<<"Too poor"<<endl;
else {
    wallet[pick]+=quantity;
    wallet[PLN]-=quantity*temp;
    }
}

void client::sell_with_pln(currency<> &c, int pick, float quantity){
float temp;
temp=c.sellvalue.back();
if (pick==PLN)
    cout<<"Impossible"<<endl;
else if (quantity>wallet[pick])
    cout<<"Not enough money to sell"<<endl;
else {
    wallet[pick]-=quantity;
    wallet[PLN]+=quantity*temp;
    }
}


//DO POPRAWY!
void client::buy_with_curr(currency<> &c2, currency<> &c1, int pick1, int pick2, float quantity){
float temp1, temp2;
temp1=wallet[pick1]*c1.neutralvalue.back();
if (pick1==pick2 || pick1==PLN || pick2 ==PLN)
    cout<<"Impossible"<<endl;
else if(quantity*c2.buyvalue.back()>temp1)
    cout<<"Too poor"<<endl;
else{
    temp2=quantity*c2.buyvalue.back();
    temp1-=temp2;
    wallet[pick2]=(temp1)/(c1.neutralvalue.back());
    wallet[pick1]+=quantity;
}
}

void client::showwallet(){
cout<<"PLN: "<<wallet[PLN]<<endl;
cout<<"EURO: "<<wallet[EUR]<<endl;
cout<<"USD: "<<wallet[USD]<<endl;
cout<<"GBP: "<<wallet[GBP]<<endl;
cout<<"FRANK: "<<wallet[FRANK]<<endl;
cout<<"BITCOIN: "<<wallet[BTC]<<endl;
cout<<"YEN: "<<wallet[YEN]<<endl;
cout<<"FORINT: "<<wallet[FOR]<<endl;
cout<<"RUBEL: "<<wallet[RUB]<<endl;
cout<<"DINAR: "<<wallet[DIN]<<endl;
}





