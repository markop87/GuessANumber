/*
Simple game of guessing a number from 1 to 100
*/

#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    int number, guess;
    vector <int> log; //vector to save guesses

    cout << "Guess number from 1 to 100!\n\n";

    static mt19937 gen(time(nullptr));; // seed the generator
    uniform_int_distribution<> distr(1, 100); //range

    number = distr(gen); // generate a number to guess

    //
    for(int i = 1; i < 100; i++)
    {

        //checking if the input is good
        do {
            cout << "Guess nr " << i << ": ";

            if (cin >> guess) {
                if (guess > 0 && guess < 101) break;
                cout << "Value out of range! Try again." << endl;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Bad input! Try again." << endl;
            }
        }
        while (true);

        cout << guess << endl;


        log.push_back(guess); //adding guess to vector

        // information to player is a guess is too high or too low
        if(guess > number)
            cout << "Too high!" << endl;
        else if(guess < number)
            cout << "Too low!" << endl;
        else if(guess == number)
            break;
    }

    system("CLS"); //clear window
    cout << "Congratulations! You guess it right!" << endl;

    cout << "\nYour guesses:\n";

    //printing all guesses
    for(int j = 0; j < 100; j++)
    {
        cout << "Guess nr " << j+1 << ": " << log[j];

        if(log[j] > number)
            cout << " - too high!" << endl;
        else if(log[j] < number)
            cout << " - too low!" << endl;
        else {
            cout << " - perfect!" << endl;
            break;
        }
    }

    return 0;
}
