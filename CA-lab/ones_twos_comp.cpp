#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string bin, temp, ones, twos;
    int len;
    cout << "\t\t*****1's and 2's COMPLEMENT******\n\n";
    cout << "Enter a valid binary number: ";
    cin >> bin;
    len = bin.length();

    int count = 0,flag=0;
    while (count != len)
    {
        if (bin[count] != '1' && bin[count] != '0')
        {
            cout << "Invalid binary number." << endl;
            
        }
        count += 1;
       
    }

    if(flag!=1){

    ones=bin;
    // 1's complement
    for (int i = 0; i < len; i++)
    {
        if (ones[i] == '1')
        {
            ones[i] = '0';
        }
        else
        {
            ones[i] = '1';
        }
    }
    // ones = bin;
    // temp = ones;

    twos = ones;
    // 2's complement
    int carry = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (twos[i] == '1' && carry == 1)
        {
            twos[i] = '0';
            carry=1;
        }
        else if (twos[i] == '0' && carry == 1)
        {
            twos[i] = '1';
            carry = 0;
        }
    }
    // twos = bin;

    cout << "The 1s complement of the entered number is: " << ones << endl;
    cout << "The 2s complement of the entered number is: " << twos << endl;
    }
    return 0;
}