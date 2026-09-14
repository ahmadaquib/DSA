#include <bits/stdc++.h>
using namespace std;

/*
    Sample input.txt (order matters — matches the cin/getline calls
    below, in the order the functions run inside main()):

    Hello World                     -> s1, s2            (demoBasicIO: cin >> s1 >> s2, two words)
    This is a full line for getline -> str                (demoBasicIO: getline(cin, str), whole line incl. spaces)
    A                                -> ch                 (demoBasicIO: cin >> ch, single character)
    20                               -> age                (demoIfElse: cin >> age)
    85                               -> marks              (demoIfElse: cin >> marks, 0-100 -> mapped to a grade)
    3                                -> day                (demoSwitchCase: cin >> day, 1-7)
    10 20 30 40 50                   -> arr[0..4]          (demoArrays: 5 ints, space or newline separated)
    Aquib                            -> name               (demoFunctionsAndPassing: cin >> name)
    5 7                              -> num1, num2         (demoFunctionsAndPassing: cin >> num1 >> num2)
*/

void printName(string name)
{
    cout << "Hey " << name << "!" << endl;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}

// Pass by Value: a COPY of num is made; changes inside never affect the caller's variable
void doSomethingByValue(int num)
{
    cout << "before: " << num << endl;
    num += 5;
    cout << "after:  " << num << " (only changed inside this function)" << endl;
}

// int&, not int, since arrays are passed by reference automatically but
// everything else (int, string, etc.) needs an explicit & to be passed by reference.
// gotcha: doSomething(int) and doSomething(int&) with the SAME name is ambiguous —
// compiler can't tell which overload a plain int call should resolve to. Split into
// two differently-named functions instead.
void doSomethingByReference(int &num)
{
    cout << "before: " << num << endl;
    num += 5;
    cout << "after:  " << num << " (this also changed the caller's variable)" << endl;
}

void demoBasicIO()
{
    cout << "\n--- Basic I/O ---\n";
    cout << "Hey Warwarion!" << endl
         << "Hey Aquib" << endl;

    // each type gets its own variable name — reusing one name for different types
    // in the same scope is an illegal redeclaration
    int a = 10;
    long b = 15;
    long long c = 1500000000000;
    float d = 6.9f;
    double e = 90;
    cout << "int: " << a << " | long: " << b << " | long long: " << c
         << " | float: " << d << " | double: " << e << endl;

    cout << "Enter two words: ";
    string s1, s2;
    cin >> s1 >> s2; // cin >> stops at whitespace, so this reads one word into each
    cout << "you entered: " << s1 << " " << s2 << endl;

    cin.ignore(); // clears the leftover newline still in the buffer before getline
    cout << "Enter a full line: ";
    string str;
    getline(cin, str); // getline reads the whole line, including spaces
    cout << "you entered: " << str << endl;

    cout << "Enter a character: ";
    char ch;
    cin >> ch;
    cout << "you entered: " << ch << endl;
}

void demoIfElse()
{
    cout << "\n--- If-Else ---\n";

    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age >= 18)
        cout << "You are an adult!" << endl;
    else
        cout << "You are not an adult!" << endl;

    cout << "Enter your marks: ";
    int marks;
    cin >> marks;
    // grade ladder — bands are exhaustive and non-overlapping so every mark
    // maps to exactly one grade
    if (marks < 25)
        cout << "Grade: F" << endl;
    else if (marks <= 44) // 25-44
        cout << "Grade: E" << endl;
    else if (marks <= 49) // 45-49
        cout << "Grade: D" << endl;
    else if (marks <= 59) // 50-59
        cout << "Grade: C" << endl;
    else if (marks <= 69) // 60-69
        cout << "Grade: B" << endl;
    else if (marks <= 84) // 70-84
        cout << "Grade: A" << endl;
    else // 85-100
        cout << "Grade: S" << endl;
}

void demoSwitchCase()
{
    cout << "\n--- Switch Case ---\n";
    cout << "Enter a day number (1-7): ";
    int day;
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "Invalid" << endl;
    }
}

void demoArrays()
{
    cout << "\n--- Arrays ---\n";

    cout << "Enter 5 numbers: ";
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    arr[3] += 10;
    cout << "arr[3] after +10: " << arr[3] << endl;

    // 2D array — separate name from arr above
    int arr2D[3][5];
    arr2D[1][2] = 78;
    cout << "arr2D[1][2]: " << arr2D[1][2] << endl;
}

void demoStrings()
{
    cout << "\n--- Strings ---\n";
    string s = "Aquib";
    int len = s.size();
    s[len - 1] = 'z';
    cout << "after mutating last char: " << s << endl;
}

void demoLoops()
{
    cout << "\n--- Loops (for / while / do-while) ---\n";

    cout << "for:       ";
    for (int i = 0; i < 5; i++)
        cout << i + 1 << " ";
    cout << endl;

    cout << "while:     ";
    int i = 0;
    while (i < 5)
    {
        cout << i + 1 << " ";
        i++;
    }
    cout << endl;

    cout << "do-while:  ";
    int j = 0;
    do
    {
        cout << j + 1 << " ";
        j++;
    } while (j < 5); // do-while always runs the body at least once, even if the condition is false
    cout << endl;
}

void demoFunctionsAndPassing()
{
    cout << "\n--- Functions & Pass by Value vs Reference ---\n";

    cout << "Enter your name: ";
    string name;
    cin >> name;
    printName(name);

    cout << "Enter two numbers to sum: ";
    int num1, num2;
    cin >> num1 >> num2;
    cout << "sum: " << sum(num1, num2) << endl;

    int num = 10;
    cout << "\nPass by value -> caller's variable is untouched:\n";
    doSomethingByValue(num);
    cout << "num after the call: " << num << endl;

    cout << "\nPass by reference -> caller's variable changes too:\n";
    doSomethingByReference(num);
    cout << "num after the call: " << num << endl;
}

/*
    Time Complexity
        Measures how execution time grows with input size.
        Describes the number of operations an algorithm performs.
        Common notations: O(1), O(log n), O(n), O(n^2).
        Helps compare algorithm efficiency and speed.

    Space Complexity
        Measures how much memory an algorithm needs.
        Includes extra/auxiliary memory used during execution.
        Common notations: O(1), O(n), O(n^2).
        Helps determine memory efficiency of an algorithm.
*/

int main()
{
    demoBasicIO();
    demoIfElse();
    demoSwitchCase();
    demoArrays();
    demoStrings();
    demoLoops();
    demoFunctionsAndPassing();
    return 0;
}