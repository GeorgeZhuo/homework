// LAB_10 PC_02 test.cpp
// ZHUOZHAOJIN 12330443

#include <iostream>

using namespace std;

int main ()
{
    char array[ 80 ];

    cout << "Using the function of getline and get\n";
    cout << "Enter a sentence with a * to specify:\n";
    cin.get( array, 80, '*' );
    cout << "Output the sentence with cin.get\n" << array << endl;
    
    cin >> array;
    cout <<"Output the sentence with cin\n" << array << endl;

    cout << "Enter a sentence:\n";
    cin.getline( array, 80, '*' );
    cout << "Output the sentence with cin.getline\n" << array << endl;
    
    cin >> array;
    cout << "Output the sentence with cin\n" << array << endl;

    return 0;

}
