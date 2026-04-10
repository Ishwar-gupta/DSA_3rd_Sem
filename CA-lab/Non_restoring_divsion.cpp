#include <iostream>
#include <cmath>
using namespace std;

int a = 0, b = 0, c = 0;
int anum[5] = {0}, bnum[5] = {0}, anumcp[5] = {0};
int bcomp[5] = {0}, rem[5] = {0}, res[5] = {0};

void binary(int x, int y)
{
    int r, r2, i;

    for(i = 0; i < 5; i++)
    {
        r = x % 2;
        x /= 2;

        r2 = y % 2;
        y /= 2;

        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;

        // 1's complement of divisor
        bcomp[i] = (r2 == 0) ? 1 : 0;
    }

    // 2's complement of divisor
    int carry = 1;
    for(i = 0; i < 5; i++)
    {
        res[i] = bcomp[i] + carry;
        carry = res[i] / 2;
        res[i] %= 2;
    }

    for(i = 0; i < 5; i++)
        bcomp[i] = res[i];
}

void add(int num[])
{
    int carry = 0;

    for(int i = 0; i < 5; i++)
    {
        res[i] = rem[i] + num[i] + carry;
        carry = res[i] / 2;
        res[i] %= 2;
    }

    for(int i = 0; i < 5; i++)
        rem[i] = res[i];
}

void shl()
{
    for(int i = 4; i > 0; i--)
        rem[i] = rem[i - 1];

    rem[0] = anumcp[4];

    for(int i = 4; i > 0; i--)
        anumcp[i] = anumcp[i - 1];

    anumcp[0] = 0;
}

void display()
{
    for(int i = 4; i >= 0; i--)
        cout << rem[i];

    cout << " : ";

    for(int i = 4; i >= 0; i--)
        cout << anumcp[i];
}

int main()
{
    int i;
    int signA, signB;

    cout << "\n***** NON-RESTORING DIVISION *****\n";

    do
    {
        cout << "Enter dividend: ";
        cin >> a;

        cout << "Enter divisor: ";
        cin >> b;

    } while(abs(a) >= 16 || abs(b) >= 16 || b == 0);

    cout << "\nExpected Quotient: " << a / b;
    cout << "\nExpected Remainder: " << a % b << endl;

    signA = (a < 0);
    signB = (b < 0);

    c = signA ^ signB;

    int A = abs(a);
    int B = abs(b);

    binary(A, B);

    cout << "\nInitial Values:\n";
    display();

    for(i = 0; i < 5; i++)
    {
        cout << "\n\nStep " << i + 1;

        shl();
        cout << "\nAfter Shift: ";
        display();

        // Non-restoring logic
        if(rem[4] == 0)
        {
            cout << "\nSubtract B: ";
            add(bcomp);   // subtract
        }
        else
        {
            cout << "\nAdd B: ";
            add(bnum);    // add
        }

        display();

        // Set quotient bit
        if(rem[4] == 0)
            anumcp[0] = 1;
        else
            anumcp[0] = 0;
    }

    // Final correction if remainder is negative
    if(rem[4] == 1)
    {
        cout << "\n\nFinal Correction (Add B): ";
        add(bnum);
        display();
    }

    cout << "\n----------------------------";
    cout << "\nSign of Quotient: " << (c ? "-" : "+");

    cout << "\nRemainder: ";
    for(i = 4; i >= 0; i--)
        cout << rem[i];

    cout << "\nQuotient: ";
    for(i = 4; i >= 0; i--)
        cout << anumcp[i];

    cout << endl;

    return 0;
}