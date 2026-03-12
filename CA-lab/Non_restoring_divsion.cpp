#include <iostream>
#include <cmath>
using namespace std;

int a = 0, b = 0, c = 0, com[5] = {1,0,0,0,0};
int anum[5] = {0}, bnum[5] = {0}, anumcp[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, rem[5] = {0}, res[5] = {0};

void binary(int x, int y)
{
    int r, r2, i;
    for(i=0;i<5;i++)
    {
        r = x % 2;
        x /= 2;

        r2 = y % 2;
        y /= 2;

        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;

        if(r2 == 0)
            bcomp[i] = 1;
        else
            bcomp[i] = 0;
    }

    int carry = 0;
    for(i=0;i<5;i++)
    {
        res[i] = com[i] + bcomp[i] + carry;
        carry = res[i] / 2;
        res[i] %= 2;
    }

    for(i=0;i<5;i++)
        bcomp[i] = res[i];
}

void add(int num[])
{
    int carry = 0;

    for(int i=0;i<5;i++)
    {
        res[i] = rem[i] + num[i] + carry;
        carry = res[i] / 2;
        res[i] %= 2;
    }

    for(int i=0;i<5;i++)
        rem[i] = res[i];

    for(int i=4;i>=0;i--)
        cout<<rem[i];

    cout<<" : ";

    for(int i=4;i>=0;i--)
        cout<<anumcp[i];
}

void shl()
{
    for(int i=4;i>0;i--)
        rem[i] = rem[i-1];

    rem[0] = anumcp[4];

    for(int i=4;i>0;i--)
        anumcp[i] = anumcp[i-1];

    anumcp[0] = 0;

    cout<<"\nSHIFT LEFT: ";

    for(int i=4;i>=0;i--)
        cout<<rem[i];

    cout<<" : ";

    for(int i=4;i>=0;i--)
        cout<<anumcp[i];
}

int main()
{
    int i;
    int signA, signB;

    cout<<"\t\t******RESTORING DIVISION******\n\n";
    cout<<"Enter two numbers to divide\n";
    cout<<"Both numbers should be less than 16 in magnitude\n\n";

    do
    {
        cout<<"Enter the dividend: ";
        cin>>a;

        cout<<"Enter the divisor: ";
        cin>>b;

    } while(abs(a)>=16 || abs(b)>=16 || b==0);

    cout<<"\nExpected Quotient: "<<a/b<<endl;
    cout<<"Expected Remainder: "<<a%b<<endl;

    signA = (a<0);
    signB = (b<0);

    if(signA ^ signB)
        c = 1;
    else
        c = 0;

    int A = abs(a);
    int B = abs(b);

    binary(A,B);

    cout<<"\n\nUnsigned Binary Equivalents are:\n";

    cout<<"A: ";
    for(i=4;i>=0;i--)
        cout<<anum[i];

    cout<<"\nB: ";
    for(i=4;i>=0;i--)
        cout<<bnum[i];

    cout<<"\nB'+1: ";
    for(i=4;i>=0;i--)
        cout<<bcomp[i];

    cout<<"\n\n-->";

    shl();

    for(i=0;i<5;i++)
    {
        cout<<"\n-->\nSUB B: ";
        add(bcomp);

        if(rem[4]==1)
        {
            cout<<"\n--> RESTORE\nADD B: ";
            anumcp[0] = 0;
            add(bnum);
        }
        else
        {
            anumcp[0] = 1;
        }

        if(i<4)
            shl();
    }

    cout<<"\n----------------------------";

    cout<<"\nSign of result: "<<(c ? "-" : "+");

    cout<<"\nRemainder: ";
    for(i=4;i>=0;i--)
        cout<<rem[i];

    cout<<"\nQuotient: ";
    for(i=4;i>=0;i--)
        cout<<anumcp[i];

    cout<<endl;

    return 0;
}