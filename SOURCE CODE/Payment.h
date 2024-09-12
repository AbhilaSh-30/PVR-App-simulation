#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED
using namespace std;

bool isValidCardNumber(string card_number)
{
    int length = card_number.length();
    if(length!=16)
        return false;
    return true;
}

class Payment {
public:
    virtual void makePayment(float amount) = 0;
};

class CreditCard : public Payment{
public:
    CreditCard(string cardNumber, string expirationDate, string cvv)
        : cardNumber(cardNumber), expirationDate(expirationDate), cvv(cvv) {}

    void makePayment(float amount) override {
        cout << "\n\t\t\tMaking Credit card payment of Rs." << amount;
        cout << " \n\n\t\t\t\tUsing Card number       : " << cardNumber.substr(0,4) << " xxxx xxxx xxxx";
        cout << " \n\t\t\t\tExpiration date         : " << expirationDate;
        cout << " \n\t\t\t\tand cvv                 : " << cvv[0] << "xx" << endl;
    }

private:
    string cardNumber;
    string expirationDate;
    string cvv;
};

class DebitCard : public Payment{
public:
    DebitCard(string cardNumber, string expirationDate, string cvv)
        : cardNumber(cardNumber), expirationDate(expirationDate), cvv(cvv) {}

    void makePayment(float amount) override {
        cout << "\n\t\t\tMaking Debit card payment of Rs." << amount;
        cout << " \n\n\t\t\t\tUsing Card number     : " << cardNumber.substr(0,4)<< " xxxx xxxx xxxx";
        cout << " \n\t\t\t\tExpiration date       : " << expirationDate;
        cout << " \n\t\t\t\tand cvv               : " << cvv[0]<< "xx"<<endl;
    }

private:
    string cardNumber;
    string expirationDate;
    string cvv;
};

class UPI : public Payment {
public:
    UPI(string upiId, string pin)
        : upiId(upiId), pin(pin) {}

    void makePayment(float amount) override {
        cout << "\n\t\t\tMaking UPI payment of Rs." << amount ;
        cout << " \n\n\t\t\t\tUsing UPI ID          : " << upiId;
        cout << " \n\t\t\t\tand PIN               : " << pin.substr(0,3) << " xxx "<<endl;
    }

private:
    string upiId;
    string pin;
};
void payment(float totalAmount)
{
    cout<<"\n\t\t\tPAYMENT OPTIONS : "<<endl;
    cout<<"\t\t\t\t1.CREDIT CARD   "<<endl;
    cout<<"\t\t\t\t2.DEBIT CARD    "<<endl;
    cout<<"\t\t\t\t3.UPI           "<<endl;
    int payment_choice;
    cout<<"\n\t\t\tEnter Payment Choice from above : ";
    cin>>payment_choice;
    switch(payment_choice)
    {
    case 1:
        {
            Payment *p1;
            string cardNo,exDate,cvv;
            cout<<"\n\t\tCREDIT CARD PAYMENT!!! "<<endl;
            cout<<"\n\t\t\tEnter credit card number (16 digits)           : ";
            cin>>cardNo;
            while(!isValidCardNumber(cardNo))
            {
                cout<<"\n\t\t\tInvalid Card Number!Enter credit card number (16 digits) : ";
                cin>>cardNo;
            }
            cout<<"\n\t\t\tEnter expiry date (mm/yy)                      : ";
            cin>>exDate;
            fflush(stdin);
            cout<<"\n\t\t\tEnter CVV (3 digits)                           : ";
            cin>>cvv;
            fflush(stdin);
            p1 = new CreditCard(cardNo,exDate,cvv);
            p1->makePayment(totalAmount);
            break;
        }
    case 2:
        {
            Payment *p1;
            string cardNo,exDate,cvv;
            cout<<"\n\t\tDEBIT CARD PAYMENT!!! "<<endl;
            cout<<"\n\t\t\tEnter credit card number (16 digits)           : ";
            cin>>cardNo;
            while(!isValidCardNumber(cardNo))
            {
                cout<<"\n\t\t\tInvalid Card Number!Enter debit card number (16 digits) : ";
                cin>>cardNo;
            }
            cout<<"\n\t\t\tEnter expiry date (mm/yy)                      : ";
            cin>>exDate;
            fflush(stdin);
            cout<<"\n\t\t\tEnter CVV (3 digits)                           : ";
            cin>>cvv;
            fflush(stdin);
            p1 = new DebitCard(cardNo,exDate,cvv);
            p1->makePayment(totalAmount);
            break;
        }
    case 3:
        {
            Payment *p1;
            string upiId,pin;
            cout<<"\n\t\tUPI PAYMENT!!! "<<endl;
            cout<<"\n\t\t\tEnter UPI ID                     : ";
            cin>>upiId;
            fflush(stdin);
            cout<<"\n\t\t\tEnter Pin (6-digits)             : ";
            getline(cin,pin);
            fflush(stdin);
            p1 = new UPI(upiId,pin);
            p1->makePayment(totalAmount);
            break;
        }
    default:
        {
            cout<<"Invalid Payment Choice !!! "<<endl;
            break;
        }
    }
}
#endif // PAYMENT_H_INCLUDED
