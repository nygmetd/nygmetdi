#include <iostream>
#include <string>
using namespace std;

// Program execution begins in main(). It returns an int because that value
// is the exit code passed back to the operating system, and "return 0"
// tells the system that the program finished successfully.
int main() {
    string name;
    cout << "What is your name? ";
    // The name is read with getline because cin >> would stop at the first
    // space and cut a name like "Anna Maria" in half; getline reads the whole line.
    getline(cin, name);
    cout << "Welcome " << name << " to C.A.L.S!" << endl;

    int a;
    cout << "Enter A: ";
    // Numbers are read with cin >>, which converts the typed text into the type of the variable (int here).
    // Limitation: if the user types a letter instead of a number, cin fails
    // and a becomes 0 without any warning. An improvement would be to check
    // cin.fail() and ask the user to enter the number again.
    cin >> a;
    cout << "You entered " << a << endl;

    int b;
    cout << "Enter B: ";
    cin >> b;
    cout << "You entered " << b << endl;

    cout << "Sum: " << a + b << endl;

    cout << "Product: " << a * b << endl;

    // This check prevents division by zero. Without it, the float division
    // would print "inf" and a % b would crash the program, because integer
    // modulo by zero is undefined.
    if (b == 0) {
        cout << "Cannot divide by zero!" << endl;
    } else {
        // Dividing two ints would discard the fractional part (7 / 2 = 3).
        // static_cast<float>(a) temporarily converts a into a float before the
        // division, so the result is calculated as a float too (7 / 2 = 3.5).
        cout << "Division: " << static_cast<float>(a) / b << endl;
        // The remainder (modulo) only works with integers, so a and b stay as ints.
        cout << "Remainder: " << a % b << endl;
    }

    cout << "Goodbye " << name << ", See you again at C.A.L.S!" << endl;

    return 0;
}
