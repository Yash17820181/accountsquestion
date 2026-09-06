#include <iostream>
using namespace std;
class Time{
    private:
        int hrs;
        int mins;
    public:
        Time(int hrs=0,int mins=0){
            this->hrs = hrs;
            this->mins=mins;
        }
        // copy construct
        Time(Time& t){

            hrs = t.hrs;
            mins = t.mins;
        }
        void checkTime(Time &t){
            if(t.mins>=60){
                t.hrs += t.mins/60;
                t.mins = t.mins%60;
            }
            if(t.mins<0){
                t.mins += 60;
                t.hrs--;
            }
        }

        Time operator +(Time &t){
            Time temp;
            temp.hrs = this->hrs+t.hrs;
            temp.mins = this->mins+t.mins;
            checkTime(temp);
            return temp;
        }

        Time operator -(Time &t){ //a-b
            Time temp;
            temp.mins = this->mins - t.mins;
            checkTime(temp);

            if(this->hrs<0 && t.hrs > this->hrs){
                cout<< "Invalid Time Input! (a > b) "<<endl;
                return 0 ;
            }
            temp.hrs = (this->hrs - t.hrs);
            return temp;
        }

        Time& operator=(Time& t){
            if(this == &t){
                return *this;
            }
            hrs = t.hrs;
            mins = t.mins;
            return *this;
        }
        //prefix ++
        Time& operator++(){
            
            this->mins++;
            checkTime(*this);
            return *this;
        }
        //prefix --
        Time& operator--(){
            
            this->mins--;
            checkTime(*this);
            return *this;
        }
                //prefix ++
        Time operator++(int){
            // Time temp;
            Time temp=*this;

            this->mins++;
            // checkTime(temp);
            return temp;
        }
        Time operator--(int){
            // Time temp;
            Time temp=*this;
            this->mins--;
            // checkTime(temp);
            return temp;
        }

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);

        
};

ostream& operator<< (ostream& out,const Time& t){
    out<<"Hours: "<<t.hrs<<" Min: "<<t.mins<<endl;
    return out;


}
istream& operator>>(istream& in,Time& t){
    cout <<"enter hours & minutes:"<<endl;
    in>>t.hrs;
    in>>t.mins;
    t.checkTime(t);
    return in;
}


