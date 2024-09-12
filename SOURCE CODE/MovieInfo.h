#ifndef MOVIEINFO_H_INCLUDED
#define MOVIEINFO_H_INCLUDED
using namespace std;

void movieInfo1()
{
    fstream p;
    p.open("movieinfo Ps.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
void movieInfo2()
{
    fstream p;
    p.open("movieinfo Suszema.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
void movieInfo3()
{
    fstream p;
    p.open("movieinfo john wick.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
void movieInfo4()
{
    fstream p;
    p.open("movieinfo viduthalai.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
void movieInfo5()
{
    fstream p;
    p.open("movieinfo mario.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
void movieInfo6()
{
    fstream p;
    p.open("movieinfo pathuthala.txt",ios::in);
    while(p)
    {
        char line=p.get();
        cout<<line;
    }
    p.close();
}
#endif // MOVIEINFO_H_INCLUDED
