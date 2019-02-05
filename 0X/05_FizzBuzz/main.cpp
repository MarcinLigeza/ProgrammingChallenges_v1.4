//#################################################################
// Programming challenges v1.4 - 05 Fizz Buzz
// Marcin Ligeza 2019
//#################################################################

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "\nProgramming challenges v1.4 - 05 Fizz Buzz\n" << endl;

    for (int i = 1; i < 100; i++)
    {
        string output{};
        if(i % 3 == 0)
            output += "Fizz";
        if(i % 5 == 0)
            output += "Buzz";
        else if (i % 3)
            output += to_string(i);
        cout << output << " ,";
    }
}
