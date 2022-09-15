#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Declaration of functions
void ReverseString ();
void FindLargestInteger ();
void CalculateFactorial ();
void FibonacciTermFinder ();

int main() {
    int userChoice = 0;

    //Prompt for which function to run
    cout << "Which function would you like to run? \n(1): Reverse a String \n(2): Find the largest of 3 numbers \n(3): Calculate the factorial of a number \n(4): Find a term in the Fibonacci Sequence \n" << endl;
    cout << "Please enter a number: " << endl;
    cin >> userChoice;

    //Switch statement to run correct requested function
    switch (userChoice) {
        case 1: ReverseString();
            break;
        case 2: FindLargestInteger();
            break;
        case 3: CalculateFactorial();
            break;
        case 4: FibonacciTermFinder();
            break;
        default: cout << "Invalid Input" << endl;
            break;
    }

    return 0;
}

//Function to reverse input string
void ReverseString () {
    string inputString;
    string reversedString;
    string blankSpace;

    getline(cin, blankSpace); //Program was taking input one line early, this set it back on track

    //Prompt for user input string
    cout << "Please input a string (word or short phrase) to be reversed: " << endl;
    getline(cin, inputString);

    //For loop that pulls the last character from the input string and places it in the reversed string
    for (int i = inputString.size() - 1; i >= 0; --i){
        reversedString.push_back(inputString.at(i));
    }

    //Print reversed string
    cout << reversedString << endl;
}

//Function to find the largest of three integers
void FindLargestInteger () {
    int first = 0, second = 0, third = 0;

    //Prompt to input three integers and assigning to variables
    cout << "Please enter three integers separated by spaces to find the largest: " << endl;
    cin >> first >> second >> third;

    //If statements to find and print the largest input integer
    if (first >= second && first >= third) {
        cout << first << " is the largest" << endl;
    }
    else if (second >= first && second >= third) {
        cout << second << " is the largest" << endl;
    }
    else if (third >= first && third >= second) {
        cout << third << " is the largest" << endl;
    }
}

//Function to calculate the factorial of an input integer
void CalculateFactorial (){
    int inputNumber = 0;
    int factorial = 0;
    int interim = 0;

    //Prompt for integer to take factorial of
    cout << "Please enter an integer to find the factorial: " << endl;
    cin >> inputNumber;

    //Setting working variables equal to user input
    factorial = inputNumber;
    interim = inputNumber;

    //Loop to calculate factorial, interim variable so loop executes fully
    for (int i = 0; i < inputNumber - 1; ++i) {
        interim -= 1;
        factorial = factorial * interim;
    }
    //Print result
    cout << inputNumber << "! = " << factorial << endl;
}

//Function to find the nth (user inputted) number of the Fibonacci Sequence
void FibonacciTermFinder (){

    //Declaration of variables, vector to store the entire sequence
    vector<int> fibonacciSequence;
    int termNumber = 0;
    int first = 1;
    int second = 0;
    int third = 1;

    //Prompt to get term to find in the sequence
    cout << "Enter an integer to find that term in the Fibonacci Sequence: " << endl;
    cin >> termNumber;

    //For loop that calculates each term in the Fibonacci Sequence and stores the sequence in a vector
    for (int i = 0; i < termNumber; ++i){
        fibonacciSequence.push_back(third);
        third = second + first;
        second = first;
        first = third;
    }

    //Optional loop to print the entire sequence
    /*for (int j = 0; j < termNumber; ++j) {
        cout << fibonacciSequence.at(j) << " ";
    }*/

    //Print desired term of the sequence
    cout << "That term (" << termNumber << ") of the Fibonacci Sequence is " << fibonacciSequence.at(termNumber - 1) << endl;
}