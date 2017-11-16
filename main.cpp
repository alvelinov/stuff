/*
Aleksandar Velinov
Faculty number: 45416
Group 4
Trion problem
*/

#include <iostream>

using namespace std;

int main()
{

    unsigned int input;
    bool start_of_ones = false;
    cin >> input;
    while(input>1000000000){
        cout << "Not a valid number. Try again" << endl;
        cin >> input;
    }

    bool digit1;
    bool digit2;
    int output=0;

    for(int c=0;c<31;c++){
        digit1 = ((input >> (32-c-1))&1);
        digit2 = ((input >> (32-c-2))&1);
        if(digit2 == 1){
            start_of_ones = true;
        } else if(digit1 == 0 && digit2 == 0 && start_of_ones){
            input |= (1<<32-c-2);
            c++;
        }
        if(digit1 ==1 && digit2 == 1){
            input = input & (~(1<<32-c-2));
            c++;
        }
    }

    cout << input << endl;

    return 0;
}
