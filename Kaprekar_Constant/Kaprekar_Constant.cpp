// Kaprekar_Constant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Any 4 digit number, with at least 2 digits that are seperate (1110 works, but 1111 does not), put the digits in numerical order, and subtract the numbers reversed
//Do this long enough, it will end up being 6174




#include <iostream>
#include <string> 

using std::endl;
using std::cout;
using std::cin;
using std::string;

bool getUserInput(string& userInput);
void InsertionSortDescending(string& theString); //O(n^2)
void printStringSpaced(string& theString); 
void flipString(string& theString); //O(n/2)

int main()
{
    //get number

    string userInput = "";

    if (getUserInput(userInput))
    {
            int number = std::stoi(userInput);

            int sortedDesc = 0;
            int sortedAsc = 0;

            int answer = number;
            int counter = 0;

            string reversed = "";

            std::string answerString = std::to_string(answer);

            while (answer != 6174)
            {
                //turn into string
                std::string s = std::to_string(answer);

                printStringSpaced(s);
                
                //put digits in order decending
                InsertionSortDescending(s);

                //make a copy with digits on ascending order
                reversed = s;

                flipString(reversed);

                //convert back to numbers
                sortedDesc = std::stoi(s);
                sortedAsc = std::stoi(reversed);

                //do the operation
                cout << "...SUBTRACTING..." << endl;

                cout << "\t";
                printStringSpaced(s);
                cout << " -      ";
                printStringSpaced(reversed);

                answer = sortedDesc - sortedAsc;

                cout << "_________________________________\n";
                answerString = std::to_string(answer);

                cout << "\t";
                printStringSpaced(answerString);

                cout << "Did the math and... " << answer << endl;

                counter++;
                cout << "Operation done " << counter << " times. " << endl;
            }

            cout << answer;

            //repeat until you get 6174, and print the number of reps
        }
}

bool getUserInput(string& userInput)
{
    cout << " Give a 4 digit number with no more than 3 repeating numbers" << endl;
    cin >> userInput;

    if (userInput.length() == 4) { //make sure it's 4 digits
        if (!(userInput[0] == userInput[1] && userInput[0] == userInput[2] && userInput[0] == userInput[3])) //make sure all 4 numbers aren't the same
        {
            return true;
        }
        else
        {
            cout << "Not valid number. Can only have max of 3 repeating digits of a 4 digit number" << endl;
            return false;
        }
     }
    else
    {
        cout << "Not valid number. Too long" << endl;
        return false;
    }
}

void InsertionSortDescending(string& theString)
{
    //Faster for small arrays. known length

    cout << "...SORTING..." << endl;

    for (int k = 1; k < 4; k++)
    {
        int temp = theString[k];
        int j = k - 1;

        while (j >= 0 && temp >= theString[j])
        {
            theString[j + 1] = theString[j];
            j = j - 1;
        }

        theString[j + 1] = temp;
    }

}

void printStringSpaced(string& theString)
{
    for (int i = 0; i < 4; i++)
    {
        cout << theString[i] << "\t";
    }
    cout << endl;
}

void flipString(string& theString)
{

    cout << "...REVERSING..." << endl;

    //do by reference with no return
    int size = theString.length();
    char temp = theString[0]; //point at first value


    for (int i = 0; i < size/2; i++)
    {
        temp = theString[i];
        theString[i] = theString[size - 1 - i];
        theString[size - 1 - i] = temp;
    }
}