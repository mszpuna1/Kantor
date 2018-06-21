#include <iostream>
#include "currency.h"
#include "client.h"
#include <string>
#include "interface.h"

using namespace std;

/*flagi s¹ znacznikami. flag1 sygnalizuje blad przy wyszukiwaniu waluty. flag2 oznacza, ze znaleziona waluta to pln*/

void interface::run(currency<> *kantor){
string str, str1, str2, str3;
string temp;

client cl;

cout<<"List of commands:"<<endl;
cout<<"SHOW WALLET"<<endl<<"SHOW currency"<<endl<<"BUY currency/ currency"<<endl<<"SELL currency"<<endl<<"--------------\n";
while (1){
    getline(cin,str);
    int counter=0;
    int counter2=0;
    int flag1=0;
    int flag2=0;
    int costam, costam2;
    for(int i=0; i<str.length();i++){
        if (str[i]==' ')
            counter++;
            //cout<<counter;
    }
    if (counter!=1 && counter!=2 && counter!=0) cout<<"Unknown command!"<<endl;
    if (counter==0){
        if(str=="END") return;
        else cout<<"Unknown command!"<<endl;
    }
    if (counter==1){
        size_t pos = str.find(' ');
        str1=str.substr(0,pos);
        str2=str.substr(pos+1);
        //cout<<"\n1:"<<str1<<" 2:"<<str2<<endl;
        if (str1=="SHOW"){
            if (str2=="WALLET"){
                cl.showwallet();
            }
            else{
            for (int i=0; i<11; i++){
                if (i==10){
                    flag1=1;
                    break;
                }
                else if (kantor[i].name==str2){
                    costam=i;
                    break;
                }
            }
            if (flag1)
                cout<<"Unknown currency!"<<endl;
            else
                kantor[costam].print();
            }
        }
        else if (str1=="SELL"){
            for (int i=0; i<11; i++){
                if (i==10){
                    flag1=1;
                    break;
                }
                else if (kantor[i].name==str2){
                    costam=i;
                    break;
                }
            }
            if (flag1)
                cout<<"Unknown currency!"<<endl;
            else{
                    float quantity;
                    cout<<"How much:"<<endl;
                    cin>>quantity;
                    cl.sell_with_pln(kantor[costam],costam,quantity);
                }
        }
        else if (str1=="UPDATE"){
            for (int i=0; i<11; i++){
                if (i==10){
                    flag1=1;
                    break;
                }
                else if (kantor[i].name==str2){
                    costam=i;
                    break;
                }
            }
            if (flag1)
                cout<<"Unknown currency!"<<endl;
            else{
                    float b,n,s;
                    cin>>b>>n>>s;
                    kantor[costam].update(b,s,n);
            }
        }
        else
            cout<<"Unknown command!"<<endl;
    }
    if (counter==2){
        size_t pos1 = str.find(' ');
        size_t pos2 = str.rfind(' ');
        str1=str.substr(0,pos1);
        str2=str.substr(pos1+1,pos2-pos1-1);
        str3=str.substr(pos2+1);
        //cout<<"1:"<<str1<<" 2:"<<str2<<" 3:"<<str3<<endl;
        if (str1!="BUY")
            cout<<"Unknown command!"<<endl;
        else{
            string temp;
            for (int i=0; i<11; i++){
                if (i==10){
                    flag1=1;
                    break;
                }
                else{
                    temp=kantor[i].name + '/';
                    if (str2==temp){
                        costam=i;
                        break;
                    }
                }
            }
            for (int i=0; i<11; i++){
                if (i==10){
                    flag1=1;
                    break;
                }
                else{
                    if (str3==kantor[i].name){
                        costam2=i;
                        if (costam2==PLN) flag2=1;
                        break;
                    }
                }
            }
            if (flag1)
                cout<<"Unknown currency"<<endl;
            else if (flag2){
                float quantity;
                cout<<"How much:"<<endl;
                cin>>quantity;
                cl.buy_with_pln(kantor[costam],costam,quantity);
            }
            else{
                float quantity;
                cout<<"How much:"<<endl;
                cin>>quantity;
                cl.buy_with_curr(kantor[costam],kantor[costam2],costam,costam2,quantity);
            }

        }

    }
    cout<<"----------------\n";
}

}



