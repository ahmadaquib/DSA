// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "Hey Warwarion!" << endl
//          << "Hey Aquib" << endl;
//     cout << "Hey";

//     int x = 10;
//     long x = 15;
//     long long x = 1500000000000;
//     float x = 6.9;
//     double x = 90;

//     string s1, s2;
//     cin >> s1 >> s2;
//     cout << s1 << " " << s2;

//     string str;
//     getline(cin, str);
//     cout << str;

//     char ch = 'g';
//     cin >> ch;
//     cout << ch;

//     // If Else Statement

//     int age;
//     cin >> age;

//     if (age >= 18)
//     {
//         cout << "You are an adult!";
//     }
//     else
//     {
//         cout << "You are not an adult!";
//     }

//     int marks;
//     cin >> marks;
//     if (marks < 25)
//     {
//         cout << "F";
//     }
//     else if (marks >= 25 && marks <= 44)
//     {
//         cout << "E";
//     }

//     int day;
//     cin >> day;

//     switch (day)
//     {
//     case 1:
//         cout << "Monday";
//         break;
//     case 2:
//         cout << "Tuesday";
//         break;
//     case 3:
//         cout << "Wednesday";
//         break;
//     case 4:
//         cout << "Thursday";
//         break;
//     case 5:
//         cout << "Friday";
//         break;
//     case 6:
//         cout << "Saturday";
//         break;
//     case 8:
//         cout << "Sunday";
//         break;
//     default:
//         cout << "Invalid";
//     }

//     int arr[5];
//     cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

//     arr[3] += 10;
//     cout << arr[3];

//     // 2D array
//     int arr[3][5];

//     arr[1][2] = 78;
//     cout << arr[1][2];

//     string s = "Aquib";
//     int len = s.size();
//     s[len - 1] = 'z';
//     cout << s[len - 1];

//     for (int i = 0; i < 10; i++)
//     {
//         cout << i + 1 << endl;
//     }

//     int i = 0;
//     while (i < 10)
//     {
//         cout << i + 1 << endl;
//         i++;
//     }

//     int i = 0;
//     do
//     {
//         cout << i + 1 << endl;
//         i++;
//     } while (i < 10);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void printName(string name)
// {
//     cout << "Hey " << name << "!";
// }

// int sum(int num1, int num2)
// {
//     return (num1 + num2);
// }

// // Pass by Value
// void doSomething(int num)
// {
//     cout << num << endl;
//     num += 5;
//     cout << num << endl
//          << endl;
// }

// // Pass by Reference
// void doSomething(int &num)
// {
//     cout << num << endl;
//     num += 5;
//     cout << num << endl
//          << endl;
// }

// int main()
// {
//     string name;
//     cin >> name;
//     printName(name);
//     int num1, num2;
//     cin >> num1 >> num2;
//     cout << sum(num1, num2);

//     int num = 10;
//     doSomething(num);
//     cout << num;

//     // IN AN FUCTION ARRAYS ARE ALWAYS PASSED BY REFERENCE BUT OTHER THINGS NEED TO USE '&' SIGN

//     // Basic Time Complexity & Space Complexity
//     /*
//     Time Complexity
//         Measures how execution time grows with input size.
//         Describes the number of operations an algorithm performs.
//         Common notations: O(1), O(log n), O(n), O(n²).
//         Helps compare algorithm efficiency and speed.
//     Space Complexity
//         Measures how much memory an algorithm needs.
//         Includes extra/auxiliary memory used during execution.
//         Common notations: O(1), O(n), O(n²).
//         Helps determine memory efficiency of an algorithm.
//     */
//     return 0;
// }