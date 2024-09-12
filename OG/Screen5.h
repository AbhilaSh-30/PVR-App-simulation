#ifndef SCREEN5_H_INCLUDED
#define SCREEN5_H_INCLUDED
using namespace std;
const int MAX_ROWS5 = 20;
const int MAX_COLS5 = 20;

class Screen5 {
public:

    char seats[MAX_ROWS5][MAX_COLS5];
    char showTime[20];

public:
    Screen5(const char* time) {
        strcpy(showTime, time);
        for (char i = 'A'; i <= 'P'; i++) {
            for (int j = 0; j < MAX_COLS5; j++) {
                seats[i][j] = '#';
            }
        }
    }
    void readFromFile(int x){
        ifstream fin;
        switch(x)
        {
        case 1:
            {
                fin.open("booksc5st1.txt");
                char row;
                int col;
                char c;
                while(fin >> row >> col >>c)
                {
                seats[row][col-1]=c;
                }
                fin.close();
            }
        case 2:
            {
                fin.open("booksc5st2.txt");
                char row;
                int col;
                char c;
                while(fin >> row >> col >>c)
                {
                seats[row][col-1]=c;
                }
                fin.close();
            }
        case 3:
            {
                fin.open("booksc5st3.txt");
                char row;
                int col;
                char c;
                while(fin >> row >> col >>c)
                {
                seats[row][col-1]=c;
                }
                fin.close();
            }
        case 4:
            {
                fin.open("booksc5st4.txt");
                char row;
                int col;
                char c;
                while(fin >> row >> col >>c)
                {
                seats[row][col-1]=c;
                }
                fin.close();
            }
        default:
            break;
        }
        }
    void display() const {
        cout << "\nShow Time : " << showTime << endl;
        cout<<"\n\t\t\t\tELITE : Rs 220.21 "<<endl;
        cout<<"\n\t-----------------------------------------------------------------------------"<<endl;
        cout << setw(4) << " ";
        for (int j = 0; j < MAX_COLS5; j++) {
            cout << setw(4) << j+1;
        }
        cout << endl;
            for (char i = 'A'; i <= 'M'; i++) {
            cout << setw(4) << i;
            for (int j = 0; j < MAX_COLS5; j++) {
                cout << setw(4) << seats[i][j];
            }
            cout << endl;
        }
        cout<<"\n\t\t\t\tBUDGET : Rs 101.21 "<<endl;
        cout<<"\n\t-----------------------------------------------------------------------------"<<endl;
        cout << setw(4) << " ";
        cout << endl;
            for (char i = 'O'; i <='P'; i++) {
            cout << setw(4) << i;
            for (int j = 0; j < MAX_COLS5; j++) {
                cout << setw(4) << seats[i][j];
            }
            cout << endl;
        }
        cout<<"\n\t---------------------------SCREEN THIS WAY------------------------------------"<<endl;
    }

     void bookEliteSeat(int x) {
        char row;
        int col;
        while (1) {
        cout << "\n\t\tEnter row number      : ";
        cin >> row;
        cout << "\n\t\tEnter column number   : ";
        cin >> col;

        if(row<'A' || row>'K' || col<1 || col>MAX_COLS1){
            cout<<"\n\t\tInvalid seat choice !!"<<endl;
            continue;
        }
        else
            break;
        }
        if (seats[row][col-1] == '#') {
            seats[row][col-1]= 'X';
            cout << "\n\t\tSeat Reserved successfully!" << endl;
            ofstream outfile;
            switch(x)
                {
                case 1:
                    {
                        outfile.open("booksc5st1.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 2:
                    {
                        outfile.open("booksc5st2.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 3:
                    {
                        outfile.open("booksc5st3.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 4:
                    {
                        outfile.open("booksc5st4.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                default:
                    break;

                }
        }
     else {
        cout << "\n\t\tThat seat is already booked. Please choose another seat." << endl;
        switch(x)
        {
        case 1:
            {
                bookEliteSeat(1);
                break;
            }
        case 2:
            {
                bookEliteSeat(2);
                break;
            }
        case 3:
            {
                bookEliteSeat(3);
                break;
            }
        case 4:
            {
                bookEliteSeat(4);
                break;
            }
        default:
            break;
        }
    }

    }
    void bookBudgetSeat(int x) {
        char row;
        int col;
        while(1){
            cout << "\n\t\tEnter row number     :  ";
            cin >> row;
            cout << "\n\t\tEnter column number  :  ";
            cin >> col;
            if(row<'L' || row>'N' || col<1 || col>MAX_COLS1){
                cout<<"\n\t\tInvalid seat choice !!"<<endl;
                continue;}
            else
                break;
        }
        if (seats[row][col-1] == '#') {
            seats[row][col-1] = 'X';
            cout << "\n\t\tSeat Reserved successfully!" << endl;
            ofstream outfile;
            switch(x)
                {
                case 1:
                    {
                        outfile.open("booksc5st1.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 2:
                    {
                        outfile.open("booksc5st2.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 3:
                    {
                        outfile.open("booksc5st3.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                case 4:
                    {
                        outfile.open("booksc5st4.txt",ios::app);
                        outfile << row <<" "<<col<<" X\n";
                        outfile.close();
                        break;
                    }
                default:
                    break;

                }
        } else {
            cout << "\n\t\tThat seat is already booked. Please choose another seat." << endl;
            switch(x)
            {
            case 1:
            {
                bookBudgetSeat(1);
                break;
            }
            case 2:
            {
                bookBudgetSeat(2);
                break;
            }
            case 3:
            {
                bookBudgetSeat(3);
                break;
            }
            case 4:
            {
                bookBudgetSeat(4);
                break;
            }
            default:
                break;
            }
        }
    }
};
#endif // SCREEN5_H_INCLUDED
