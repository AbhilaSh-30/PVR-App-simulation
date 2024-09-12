#include <iostream>
#include<string>
#include <cstring>
#include <cmath>
#include<iomanip>
#include<fstream>
#include"Screen1.h"
#include"Screen2.h"
#include"Screen3.h"
#include"Screen4.h"
#include"Screen5.h"
#include"Screen6.h"
#include"Account.h"
#include"Payment.h"
#include"GlobalFunctions.h"
#include"MovieInfo.h"

using namespace std;

class Movie:public createAcc
{
public:
    int movie_choice;
    int ticket_choice;
    int show_choice;
    char seat_class;
    char pay,com,cls;
    char ch;
    void login()
    {
        string mailId, password;
        string mailline, passline;
        getchar();
        system("cls");
        cout << "\n\t\t\t\tSIGN IN "<<endl;
        cout << "\n\t\t\tEnter your EmailId    : ";
        getline(cin,mailId);
        cout << "\n\t\t\tEnter your password   : ";
        getline(cin, password);
        bool is_success = false;
        ifstream mailfile("mail.txt");
        ifstream passfile("password.txt");
        while (getline(mailfile, mailline) && getline(passfile, passline))
        {
            if (mailline == mailId && passline == password)
            {
                is_success = true;
                break;
            }
        }
        mailfile.close();
        passfile.close();
        if (is_success)
        {
            cout << "\n\t\t\tAuthentication successful!" << endl;
            system("cls");
            choosing_movie();
        }
        else
        {
            if(passline!=password || mailline!= mailId)
            {
                cout<<"\n\t\tYou have entered a wrong passsword or an invalid mail!Please try again.";
                login();
            }
        }
    }
    void choosing_movie()
    {
        do
        {
        cout<<"\n\t\t\tNOW SHOWING : "<<endl;
        cout<<"\n\t\t______________________________"<<endl;
        cout<<"\n\t\t1.PONNYIN SELVAN : II "<<endl;
        cout<<"\t\t2.SUZUME "<<endl;
        cout<<"\t\t3.JOHN WICK CHAPTER : 4 "<<endl;
        cout<<"\t\t4.VIDUTHALAI PART 1 "<<endl;
        cout<<"\t\t5.SUPER MARIO BROS "<<endl;
        cout<<"\t\t6.PATHU THALA "<<endl;
        cout<<"\n\tEnter the movie number choice to book tickets : ";
        cin>>movie_choice;
        system("cls");
        switch(movie_choice)
        {
        case 1:
        {
            movieInfo1();
            string movie = "PONNYIN SELVAN : II  (U/A)(2D)";
            string screen = "Screen 6";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st1:{
            case 1:
                {
                    Screen6 s1("12.40pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"12.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"12.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st1;
                        }
                        else
                            goto st1;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"12.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st1;
                        }
                        else
                            goto st1;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st1;
                    }
                    break;
                }
            }
            st2:{
            case 2:
                {
                    Screen6 s1("03.30pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st2;
                        }
                        else
                            goto st2;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st2;
                        }
                        else
                            goto st2;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st2;
                    }
                    break;
                }
            }
            st3:{
            case 3:
               {
                    Screen6 s1("06.40pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"06.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"06.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st3;
                        }
                        else
                            goto st3;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"06.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st3;
                        }
                        else
                            goto st3;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st3;
                    }
                    break;
                }
            }
            st4:{
            case 4:
                {
                    Screen6 s1("10.30pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"10.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"10.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st4;
                        }
                        else
                            goto st4;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"10.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"10.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st4;
                        }
                        else
                            goto st4;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st4;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        case 2:
        {
            movieInfo2();
            string movie = "SUZUME (U/A)(2D)";
            string screen = "Screen 4";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st11:{
            case 1:
                {
                    Screen4 s1("12.20pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st11;
                        }
                        else
                            goto st11;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st11;
                        }
                        else
                            goto st11;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st11;
                    }
                    break;
                }
            }
            st12:{
            case 2:
                {
                    Screen4 s1("02.40pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"02.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"02.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st12;
                        }
                        else
                            goto st12;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"02.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"02.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st12;
                        }
                        else
                            goto st12;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st12;
                    }
                    break;
                }
            }
            st13:{
            case 3:
               {
                    Screen4 s1("06.00pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"06.00 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"06.00 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st13;
                        }
                        else
                            goto st13;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"06.00 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.00 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st13;
                        }
                        else
                            goto st13;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st13;
                    }
                    break;
                }
            }
            st14:{
            case 4:
                {
                    Screen4 s1("09.10pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"09.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"09.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st14;
                        }
                        else
                            goto st14;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"09.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"09.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st14;
                        }
                        else
                            goto st14;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st14;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        case 3:
        {
            movieInfo3();
            string movie = "JOHN WICK CHAPTER : 4  (A)(2/D)";
            string screen = "Screen 1";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st21:{
            case 1:
                {
                    Screen1 s1("12.40pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"12.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"12.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st21;
                        }
                        else
                            goto st21;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"12.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st21;
                        }
                        else
                            goto st21;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st21;
                    }
                    break;
                }
            }
            st22:{
            case 2:
                {
                    Screen1 s1("03.30pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st22;
                        }
                        else
                            goto st22;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st22;
                        }
                        else
                            goto st22;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st22;
                    }
                    break;
                }
            }
            st23:{
            case 3:
               {
                    Screen1 s1("06.40pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"06.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"06.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st23;
                        }
                        else
                            goto st23;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"06.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st23;
                        }
                        else
                            goto st23;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st23;
                    }
                    break;
                }
            }
            st24:{
            case 4:
                {
                    Screen1 s1("10.30pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"10.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"10.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st24;
                        }
                        else
                            goto st24;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"10.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"10.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st24;
                        }
                        else
                            goto st24;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st24;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        case 4:
        {
            movieInfo4();
            string movie = "VIDUTHALAI PART 1  (A)(2/D)";
            string screen = "Screen 5";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st31:{
            case 1:
                {
                    Screen5 s1("12.20pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st31;
                        }
                        else
                            goto st31;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st31;
                        }
                        else
                            goto st31;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st31;
                    }
                    break;
                }
            }
            st32:{
            case 2:
                {
                    Screen5 s1("03.20pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"03.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"03.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st32;
                        }
                        else
                            goto st32;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"03.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"03.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st32;
                        }
                        else
                            goto st32;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st32;
                    }
                    break;
                }
            }
            st33:{
            case 3:
               {
                    Screen5 s1("06.20pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"06.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"06.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st33;
                        }
                        else
                            goto st33;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"06.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st33;
                        }
                        else
                            goto st33;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st33;
                    }
                    break;
                }
            }
            st34:{
            case 4:
                {
                    Screen5 s1("10.20pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"10.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"10.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st34;
                        }
                        else
                            goto st34;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"10.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"10.20 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st34;
                        }
                        else
                            goto st34;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st34;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        case 5:
        {
            movieInfo5();
            string movie = "THE SUPER MARIO BROS  (U)(2D)";
            string screen = "Screen 3";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st41:{
            case 1:
                {
                    Screen3 s1("01.10pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"01.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"01.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st41;
                        }
                        else
                            goto st41;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"01.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"01.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st41;
                        }
                        else
                            goto st41;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st41;
                    }
                    break;
                }
            }
            st42:{
            case 2:
                {
                    Screen3 s1("04.30pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"04.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"04.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st42;
                        }
                        else
                            goto st42;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"04.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"04.30 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st42;
                        }
                        else
                            goto st42;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st42;
                    }
                    break;
                }
            }
            st43:{
            case 3:
               {
                    Screen3 s1("07.10pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"07.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"07.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st43;
                        }
                        else
                            goto st43;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"07.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"07.10 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st43;
                        }
                        else
                            goto st43;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st43;
                    }
                    break;
                }
            }
            st44:{
            case 4:
                {
                    Screen3 s1("09.40pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"09.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationE(movie,"09.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st44;
                        }
                        else
                            goto st44;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"09.40 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"09.40 pm",ticket_choice,screen);
                                ch = choose();
                                system("cls");
                            }
                            else
                                goto st44;
                        }
                        else
                            goto st44;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st44;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        case 6:
        {
            movieInfo6();
            string movie = "PATHU THALA  (U/A)(2D)";
            string screen = "Screen 2";
            cout<<"\n\tWhich show do you prefer ? : ";
            cin>>show_choice;
            system("cls");
            switch(show_choice)
            {
            st51:{
            case 1:
                {
                    Screen2 s1("12.20pm");
                    s1.readFromFile(1);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st51;
                        }
                        else
                            goto st51;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(1);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"12.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"12.20 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st51;
                        }
                        else
                            goto st51;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st51;
                    }
                    break;
                }
            }
            st52:{
            case 2:
                {
                    Screen2 s1("03.30pm");
                    s1.readFromFile(2);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st52;
                        }
                        else
                            goto st52;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(2);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"03.30 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"03.30 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st52;
                        }
                        else
                            goto st52;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st52;
                    }
                    break;
                }
            }
            st53:{
            case 3:
               {
                    Screen2 s1("06.10pm");
                    s1.readFromFile(3);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"06.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.10 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st53;
                        }
                        else
                            goto st53;
                    }
                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(3);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"06.10 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"06.10 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st53;
                        }
                        else
                            goto st53;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st53;
                    }
                    break;
                }
            }
            st54:{
            case 4:
                {
                    Screen2 s1("10.20pm");
                    s1.readFromFile(4);
                    s1.display();
                    cout<<"\n\tWhich Class do you want to book ?(Elite - E / Budget - B) : ";
                    cin>>seat_class;
                    fflush(stdin);
                    if(seat_class == 'E')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 && ticket_choice>11 && isdigit(ticket_choice) == false )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookEliteSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,EliteRate,ticket_choice);
                        system("cls");
                        movieConfirmationE(movie,"10.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"10.20 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st54;
                        }
                        else
                            goto st54;
                    }

                    else if(seat_class == 'B')
                    {
                        cout<<"\n\tHow many tickets do you want to book ? (Maximum 10): ";
                        cin>>ticket_choice;
                        if(ticket_choice<=0 || ticket_choice>10 || isdigit(ticket_choice) == 0 )
                        {
                            cout<<"\n\t\tInvalid Ticket Choice!! : ";
                            cout<<"\n\tHow many tickets do you want to book ?(Maximum 10) : ";
                            cin>>ticket_choice;
                        }
                        for(int i=0;i<ticket_choice;i++)
                        {
                            s1.bookBudgetSeat(4);
                        }
                        float totalAmount = Total(tax,fee,gst,BudgetRate,ticket_choice);
                        system("cls");
                        movieConfirmationB(movie,"10.20 pm",ticket_choice,screen,totalAmount);
                        cout<<"\n\t\t\tPay Order !!!"<<endl;
                        cout<<"\t\t\tTo Confirm Booking Press P : ";
                        cin>>pay;
                        if(pay == 'P')
                        {
                            system("cls");
                            payment(totalAmount);
                            cout<<"\n\n\t\t\tPress C for Payment completion : ";
                            cin>>com;
                            if(com == 'C')
                            {
                                system("cls");
                                cout<<"\n\n\t\t\t\t\t\t   PAYMENT DONE!!\n\n"<<endl;
                                ticketConfirmationB(movie,"10.20 pm",ticket_choice,screen);
                                ch = choose();
                            }
                            else
                                goto st54;
                        }
                        else
                            goto st54;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\n\t\t\t\t\t\t\tInvalid Seat Class"<<endl;
                        goto st54;
                    }
                    break;
                }
            }
            default:
                cout<<"Invalid ShowTime!!"<<endl;
                break;
            }
            break;
        }
        }
        }while(ch == 'Y');
        close:{
        cout<<"\n\t\t\tPress C to Close App : ";
        cin>>cls;
        if(cls == 'C')
        {
            system("cls");
            cout<<"\n\t\t\tClosing App...";
            exit(0);
        }
        else
        {
            system("cls");
            choosing_movie();
        }
        }

    }

} ;

int main()
{
    char open;
    while(1){
    drawBorder("PVR",50,10);
    cout<<"\n\t\t\tEnter O to Open the app !!";
    cin>>open;
        if(open == 'O')
        {
            int ch;
            Movie m1;
            system("cls");
            cout<<"\n\t\t\t\t     1.Sign In"<<endl;
            cout<<"\n\t\t\t\t     2.Sign Up"<<endl;
            cout<<"\n\t\t\tEnter choice number to proceed (1/2) : ";
            cin>>ch;
            if (ch==2)
            {
                createAcc p1;
                p1.input();
                m1.login();
            }
            else if(ch==1)
            {
                m1.login();
            }
            break;
        }
        else{
            system("cls");
            continue;
        }
    }
    return 0;
}
