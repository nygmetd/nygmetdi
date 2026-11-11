#include <iostream>
using namespace std;

// The result of the formula is a decimal, but the function returns an int,
// so the fractional part is discarded (2.2 becomes 2).
int PointsConverter(int Points) {
    if (Points < 0) {
        return 0;
    }
    return Points * 2.4 - 5;
}

// The first condition uses && because both requirements must be met at the same
// time (verified and more than 100 points). The second uses || because either
// days > points or days > 60 is enough. The final return false covers every
// other case where neither condition is true.
bool GoldStatusChecker(int points, bool isVerified, float days) {
    if (points > 100 && isVerified) {       
        return true;
    }
    if (days > points || days > 60) {    
        return true;
    }
    return false;
}

// UserService runs a loop with while (true) so the menu keeps repeating until
// the user chooses option 3. Only "return" in option 3 ends the function and
// therefore the loop. It is void because the brief says it returns nothing.
void UserService() {
    cout << "Hello. Welcome to the User service." << endl;

    // credits is declared before the loop so its value is kept between rounds.
    // If it was inside the loop, it would reset to 0 every time.
    // If a user selects option 2 directly, without having gone through option 1, 
    // then credits = 0. In this case, any days > 0 results in gold member status, 
    // because days > points.
    int credits = 0;
    int choice;

    while (true) {
        cout << "Please type in an option of 1, 2, or 3: ";
        cin >> choice;

        // If the user typed a letter, cin is in a "failed" state.
        if (cin.fail()) {            // cin.fail() checks if the last input operation failed
            cin.clear();             // cin.clear() resets state
            cin.ignore(1000, '\n');  // cin.ignore() throws away the bad input
            continue;                
        }

        if (choice == 1) {
            int points;
            cout << "Enter your points: ";
            cin >> points;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please enter a number." << endl;
                continue;
            }
            credits = PointsConverter(points);
            cout << "You currently have " << credits << " credits." << endl;
        } else if (choice == 2) {
            bool isVerified;
            float days;
            cout << "Are you verified? (1 = yes, 0 = no): ";
            cin >> isVerified;
            cout << "Enter number of days: ";
            cin >> days;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again." << endl;
                continue;        // go back to the start of the loop and ask the menu question again.
            }

            // The GoldStatusChecker function takes the saved credits as "points";
            // isVerified and days come from the user.
            if (GoldStatusChecker(credits, isVerified, days)) {
                cout << "You are a gold member" << endl;
            } else {
                cout << "You are not a gold member" << endl;
            }
        } else if (choice == 3) {
            cout << "ending system, goodbye!" << endl;
            return;
        }
    }
}

int main() {
    UserService();
    return 0;
}
