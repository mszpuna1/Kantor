#ifndef CURRENCY_H
#define CURRENCY_H
#include <vector>
using namespace std;
enum {PLN, EUR, USD, GBP, FRANK, BTC, YEN, FOR, RUB, DIN};
//template <float>

template < typename T = float >
class currency{
public:
    vector<T> buyvalue;
    vector<T> neutralvalue; //przelicznik przy kowersji na inne waluty (w pln)
    vector<T> sellvalue;
    string name;
    currency() {};
    currency(T bv,T nv,T sv,string nm){
        buyvalue.push_back(bv);
        sellvalue.push_back(sv);
        neutralvalue.push_back(nv);
        name=nm;
    }
    ~currency(){};

    void update(T buy,T neutral,T sell){
        sellvalue.push_back(sell);
        buyvalue.push_back(buy);
        neutralvalue.push_back(neutral);
    }

    void print(){
        int n1, n2;
        n1=buyvalue.size();
        n2=sellvalue.size();
        cout<<name<<endl;
        cout<<"Current buy price: "<<buyvalue.back()<<endl;
        cout<<"Current sell price: "<<sellvalue.back()<<endl;
        cout<<"Previous buy pices (from last) :";
        for (int i=n1-2;i>=0;i--){
            cout<<buyvalue[i]<<"|| ";
        }
        cout<<endl<<"Previous sell prices (from last) :";
        for (int i=n2-2;i>=0;i--){
            cout<<sellvalue[i]<<"|| ";
        }
        cout<<endl;
        }
};




 #endif

