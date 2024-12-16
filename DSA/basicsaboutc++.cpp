#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int x,y;
    x=100;
    std::cout << x << std::endl;
    std::cout << "Hello World\n\n";
    std::cout << 3 << "\n";
    std::cout << 3+3;
    const int myNum = 15;  // myNum will always be 15

    // cin is a predefined variable that reads data from the keyboard with the extraction operator (>>).
    // insertion operator (<<)

    //for user input
    std::cout << "\nType a number: ";
    std::cin >> y;
    std::cout << y;

    char myGrade = 'B';
    char a = 65;
    std::cout <<"\n" ;
    std:: cout << myGrade<<"\n";
    std::cout << a << std::endl;
    std::string greeting = "Hello";
    std::cout << greeting << std::endl;
    std::cout << "abc" << a <<x <<"\n";

    //for comparison return 0 if false and 1 if true
    std::cout<<(x<y)<<"\n";

    //String Concatenation
    //A string in C++ is actually an object, which contain functions that can perform certain operations on strings
    //C++ uses the + operator for both addition and concatenation.Numbers are added. Strings are concatenated.
    std::string firstName = "John ";
    std::string lastName = "Doe";
    std::string fullName = firstName + lastName;
    std::cout << fullName;
    std::string xyz = firstName.append(lastName);
    std::cout << "\n";
    std::cout << xyz<<"\n";

    //String Length
    //To get the length of a string, use the length() function:
    std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::cout << "The length of the txt string is: " << txt.length()<<"\n";

    //C++ Access Strings
    std::string myString = "Hello";
    std::cout << myString[0]<<"\n";
    myString[0] = 'J';
    std::cout << myString[0]<<"\n";
    //The <string> library also has an at() function that can be used to access characters in a string:
    std::cout << myString.at(1)<<"\n";

    //C++ Short Hand If Else
    //variable = (condition) ? expressionTrue : expressionFalse;
    int time = 2;
    std::string result = (time < 18) ? "Good day." : "Good evening.";
    std::cout << result << "\n";

    //foreach Loop
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int i : myNumbers) 
    {
    std::cout << i << "\n";
    }
    
    //c++ break
    for (int i = 0; i < 10; i++) 
    {
    if (i == 4) 
    {
        break;
    }
    cout << i << "\n";
    }
    //C++ Continue
    // The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.   
    //This example skips the value of 4:
     for (int i = 0; i < 10; i++) 
     {
        if (i == 4) 
        {
            continue;
        }
        std::cout << i << "\n";
    }

    
    return 0;
}