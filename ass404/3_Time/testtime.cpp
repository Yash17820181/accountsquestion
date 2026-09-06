#include <iostream>
#include "time.h"
using namespace std;

int main(){
    Time t1, t2;
    // input data in obj
    cin>>t1;
    cin>>t2;
    // addition
    Time t3 = t1+t2; // 6:10
    // substraction
    Time t4 = t1-t2;

    // display
    cout<<t3;
    cout<<t4;

    // assignment
    Time t5 = t4;
    cout<<t5;

    // chained assignment
    Time t6 = t5 = t3;
    cout<<t6<<t5<<t3;
    //prefix ++

    cout<< t6;
    cout << ++t6;

    //prefix --

    cout<< t6;
    cout << --t6;

    // -- postfix
    cout << t6++;
    cout<< t6;

    // ++ postfix
    cout << t6--;
    cout << t6;

}