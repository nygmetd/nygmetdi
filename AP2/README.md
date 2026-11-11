# User Service Program

This program provides a simple user service system with a menu of three options. First, it can convert user points into credits using the PointsConverter function. Negative points return 0, while positive points are multiplied by 2.4 and reduced by 5. The result is stored as an integer, so any decimal part is discarded.

The program can also check whether a user has Gold Member status using the GoldStatusChecker function. A user becomes a gold member if they have more than 100 points and are verified, or if the number of days is greater than their points or greater than 60.

The UserService function displays a menu that repeats until the user selects option 3 to exit. Option 1 converts points into credits and saves the result. Option 2 checks the user's Gold Member status using the saved credits, verification status and number of days. The program also handles invalid input by clearing the input error and asking the user to try again.

## How to run
g++ -std=c++17 main.cpp -o main
./main

## Example
Input: option 1, points = 50

Output: You currently have 115 credits.

Input: option 2, verified = 1, days = 10

Output: You are a gold member

Input: option 3

Output: ending system, goodbye!

## AI usage
| ChatGPT | Helped prepare the program description and explain its functionality |
