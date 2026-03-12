#include <iostream>
using namespace std;

// function to print 5-bit binary
void printBinary(int num, int bits = 5)
{
    for (int i = bits - 1; i >= 0; i--)
        cout << ((num >> i) & 1);
}

int main()
{
    int A = 0;       // remainder register
    int Q;           // dividend
    int M;           // divisor
    int n = 5;       // number of bits
    int sign = 0;    // sign of quotient

    cout << "\t\t******RESTORING DIVISION******\n\n";
    cout << "Enter two numbers to divide\n";
    cout << "Both numbers should be less than 16 in magnitude\n\n";

    cout << "Enter the dividend: ";
    cin >> Q;

    cout << "Enter the divisor: ";
    cin >> M;

    if (M == 0)
    {
        cout << "Division by zero not allowed\n";
        return 0;
    }

    cout << "\nExpected Quotient: " << Q / M << endl;
    cout << "Expected Remainder: " << Q % M << endl;

    int dividend = Q;

    // determine sign of quotient
    if ((Q < 0 && M > 0) || (Q > 0 && M < 0))
        sign = 1;

    // convert to positive for algorithm
    Q = abs(Q);
    M = abs(M);

    cout << "\nInitial Values\n";
    cout << "A = ";
    printBinary(A);
    cout << "  Q = ";
    printBinary(Q);
    cout << "  M = ";
    printBinary(M);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nStep " << i + 1 << endl;

        // shift left (A,Q)
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1) & 31;

        cout << "After Shift -> A=";
        printBinary(A);
        cout << " Q=";
        printBinary(Q);
        cout << endl;

        // subtract M
        A = A - M;

        cout << "After A = A - M -> A=";
        printBinary(A);
        cout << endl;

        if (A < 0)
        {
            Q = Q & (~1);
            A = A + M;

            cout << "Restore A -> A=";
            printBinary(A);
            cout << " Q=";
            printBinary(Q);
            cout << endl;
        }
        else
        {
            Q = Q | 1;

            cout << "Set Q0 = 1 -> Q=";
            printBinary(Q);
            cout << endl;
        }
    }

    // apply sign to quotient
    if (sign)
        Q = -Q;

    // remainder sign same as dividend
    if (dividend < 0)
        A = -A;

    cout << "\n----------------------------\n";
    cout << "Sign of result: " << (sign ? "-" : "+") << endl;

    cout << "Final Quotient (Binary): ";
    printBinary(abs(Q));
    cout << endl;

    cout << "Final Remainder (Binary): ";
    printBinary(abs(A));
    cout << endl;

    return 0;
}