#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
using namespace std;

bool isMailIdValid(string email)
{
    const string gmailSuffix = "@gmail.com";
    if (email.length() < gmailSuffix.length())
        return false;
    return email.compare(email.length() - gmailSuffix.length(), gmailSuffix.length(), gmailSuffix) == 0;
}

class createAcc
{
public:
    string firstname;
    string lastname;
    string mailID;
    string pwd;
    string confirmpwd;
    void input()
    {
        system("cls");
        cout<<"\n\t\t\t\t\tSIGN UP"<<endl;
        cout<<"\n\n\t\tPlease enter your details for creating an account!!\n"<<endl;
        cout<<"\n\t\t\tFirst Name        : ";
        cin>>firstname;
        cout<<"\t\t\tLast Name         : ";
        cin>>lastname;
        cout<<"\t\t\tMail ID           : ";
        cin>>mailID;
        while(!isMailIdValid(mailID)){
            cout<<"\n\t\t\tInvalid Mail Id!Please Enter a Valid Mail Id : ";
            cin>>mailID;
        }
        cout<<"\t\t\tPassword          : ";
        cin>>pwd;
        cout<<"\t\t\tConfirm Password  : ";
        cin>>confirmpwd;
        if(pwd!=confirmpwd)
        {
            cout<<"\n\t\t\tPassword and Confirm password not matching!";
        }
        else
        {
            ofstream file;
            file.open("mail.txt",ios::app);
            file <<mailID<<endl;
            file.close();
            ofstream file1;
            file1.open("password.txt",ios::app);
            file1 <<pwd<<endl;
            file1.close();

        }
    }
};
#endif // ACCOUNT_H_INCLUDED
