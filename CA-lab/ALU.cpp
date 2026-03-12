#include <iostream>
using namespace std;

int main()
{
    int A, B;
    string SEL;
    int Y;

    cout << "4-bit ALU Simulation\n";

    cout << "Enter A (0-15): ";
    cin >> A;

    cout << "Enter B (0-15): ";
    cin >> B;

    cout << "Enter SEL (4-bit code): ";
    cin >> SEL;

    switch (stoi(SEL))
    {
        case 0:  // 0000
            Y = A & B;
            cout << "Operation: AND\n";
            break;

        case 1:  // 0001
            Y = ~(A & B) & 15;
            cout << "Operation: NAND\n";
            break;

        case 2:  // 0010
            Y = A | B;
            cout << "Operation: OR\n";
            break;

        default:
            cout << "Undefined operation\n";
            return 0;
    }

    cout << "Result (decimal): " << Y << endl;

    cout << "Result (binary): ";
    for (int i = 3; i >= 0; i--)
        cout << ((Y >> i) & 1);

    cout << endl;

    return 0;
}