#ifndef GLOBALFUNCTIONS_H_INCLUDED
#define GLOBALFUNCTIONS_H_INCLUDED
using namespace std;

const float tax = 63.72;
const float fee = 54.00;
const float gst = 9.72;
const float EliteRate = 220.21;
const float BudgetRate = 101.21;

float Total(float tax,float fee,float gst,float BG,int ticket_choice)
{
    float rate = BG * ticket_choice;
    return tax+fee+gst+rate;
}
char choose()
{
    char ch;
    cout<<"\n\t\t\tDo you want to continue Booking (Y/N) : ";
    cin>>ch;
    return ch;
}

void drawBorder(string text,int width, int height) {
    cout<< "\t\t\t+";
    for (int i = 0; i < width - 2; i++) {
        cout<< "-";
    }
    cout<< "+" <<endl;
    int textWidth = text.length();
    int textX = (width - textWidth) / 2;
    int textY = (height - 3) / 2;
    for (int i = 0; i < height - 3; i++) {
        cout<< "\t\t\t|";
        if (i == textY) {
            for (int j = 0; j < textX; j++) {
                cout << " ";
            }
            cout<< ""<<text;
            for (int j = textX + textWidth; j < width - 2; j++) {
                cout<< " ";
            }
        } else {
            for (int j = 0; j < width - 2; j++) {
                cout<< " ";
            }
        }
        cout<< "|" <<endl;
    }
    cout<< "\t\t\t+";
    for (int i = 0; i < width - 2; i++) {
        cout<< "-";
    }
    cout<< "+" <<endl;
}

void movieConfirmationE(string name,string showtime,int ticket_choice,string screen,float total)
{
    float Rate = ticket_choice * EliteRate;
    cout<<"\n\t\t\t\t\t\tORDER CONFIRMATION"<<endl;
    cout<<"\n\t\t\t\t  "<<name<<endl;
    cout<<"\t\t\t\t  "<<showtime<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<screen;
    cout<<"\n\t\t\t\t  "<<ticket_choice<<" Ticket(s)"<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<ticket_choice<<" x Elite"<<"\t\t\t\t"<<Rate;
    cout<<"\n\t\t\t\t  Taxes and Fees"<<"\t\t\t"<<tax;
    cout<<"\n\t\t\t\t  Convenience Fee"<<"\t\t\t"<<fee;
    cout<<"\n\t\t\t\t  GST"<<"\t\t\t\t\t"<<gst;
    cout<<"\n\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  Total"<<"\t\t\t\t\t"<<total;
    cout<<"\n\t\t\t\t---------------------------------------------------"<<endl;
}
void movieConfirmationB(string name,string showtime,int ticket_choice,string screen,float total)
{
    float Rate = ticket_choice * BudgetRate;
    cout<<"\n\t\t\t\t\t\tORDER CONFIRMATION"<<endl;
    cout<<"\n\t\t\t\t  "<<name<<endl;
    cout<<"\t\t\t\t  "<<showtime<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<screen;
    cout<<"\n\t\t\t\t  "<<ticket_choice<<" Ticket(s)"<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<ticket_choice<<" x Budget"<<"\t\t\t\t"<<Rate;
    cout<<"\n\t\t\t\t  Taxes and Fees"<<"\t\t\t"<<tax;
    cout<<"\n\t\t\t\t  Convenience Fee"<<"\t\t\t"<<fee;
    cout<<"\n\t\t\t\t  GST"<<"\t\t\t\t\t"<<gst;
    cout<<"\n\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  Total"<<"\t\t\t\t\t"<<total;
    cout<<"\n\t\t\t\t---------------------------------------------------"<<endl;
}

void ticketConfirmationE(string name,string showtime,int ticket_choice,string screen)
{
    cout<<"\n\t\t\t\t\t\tBOOKING CONFIRMATION\n"<<endl;
    cout<<"\n\t\t\t\t  "<<name<<endl;
    cout<<"\t\t\t\t  "<<showtime<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<screen;
    cout<<"\n\t\t\t\t  Elite "<<ticket_choice<<" Ticket(s)"<<endl;
    cout<<"\t\t\t\t---------------------------------------------------\n\n\n";
}
void ticketConfirmationB(string name,string showtime,int ticket_choice,string screen)
{
    float Rate = ticket_choice * BudgetRate;
    cout<<"\n\t\t\t\t\t\tBOOKING CONFIRMATION\n"<<endl;
    cout<<"\n\t\t\t\t  "<<name<<endl;
    cout<<"\t\t\t\t  "<<showtime<<endl;
    cout<<"\t\t\t\t---------------------------------------------------";
    cout<<"\n\t\t\t\t  "<<screen;
    cout<<"\n\t\t\t\t  Budget "<<ticket_choice<<" Ticket(s)"<<endl;
    cout<<"\t\t\t\t---------------------------------------------------\n\n\n";
}
#endif // GLOBALFUNCTIONS_H_INCLUDED
