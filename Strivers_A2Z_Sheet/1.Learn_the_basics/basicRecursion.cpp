#include <bits/stdc++.h>
using namespace std;

/*
    Recursion = function calling itself on a smaller version of the problem,
    until a base condition stops it.

    Base condition: the check that stops the calls. Miss it (or make it
    unreachable) and the function calls itself forever.

    Stack overflow: every call pushes a stack frame (its locals, params,
    return address). Normal calls return fast so the frame pops almost
    immediately. Infinite recursion keeps pushing frames and never pops
    any -> stack memory runs out -> OS kills it (segfault).

    Infinite version (not called, just showing the bug):
        int cnt = 0;
        void f() { cout << cnt; cnt++; f(); }   // no base case

    Fixed:
        int cnt = 0;
        void f() {
            if (cnt == 4) return;   // base condition
            cout << cnt; cnt++; f();
        }

    return; -> stop this call, pop the frame, go back to caller.
    return val; -> same, but hands val back to whoever called this,
                   to be used in that expression (e.g. return n + f(n-1)).
*/

// Q1. Print "Coder" n times
void printName(int i, int n)
{
    if (i > n) // base case
        return;
    cout << "Coder ";
    printName(i + 1, n);
}
// n=3: f(1) print -> f(2) print -> f(3) print -> f(4) stop
// TC: O(n) | SC: O(n) (call stack depth)

// Q2. Print linearly 1 to N
void printLinear(int i, int n)
{
    if (i > n)
        return;
    cout << i << " "; // print before the call -> increasing order
    printLinear(i + 1, n);
}
// TC: O(n) | SC: O(n)

// Q3. Print from N to 1
void printReverseLinear(int i, int n)
{
    if (i < 1)
        return;
    cout << i << " ";
    printReverseLinear(i - 1, n);
}
// called as f(n, n). TC: O(n) | SC: O(n)

// Q4. Print 1 to N using backtracking
// recurse first (go towards base case), print on the way back up.
void printLinearBacktrack(int i, int n)
{
    if (i < 1)
        return;
    printLinearBacktrack(i - 1, n);
    cout << i << " "; // printed while unwinding, so smallest i prints first
}
// called as f(n, n). TC: O(n) | SC: O(n)

// Q5. Print N to 1 using backtracking
void printReverseBacktrack(int i, int n)
{
    if (i > n)
        return;
    printReverseBacktrack(i + 1, n);
    cout << i << " ";
}
// called as f(1, n). TC: O(n) | SC: O(n)

// Sum of first N natural numbers. n=3 -> 1+2+3=6. Closed form: n(n+1)/2.

// Parameterised: carry running total as a param, print at base case.
void sumParameterised(int i, int sum)
{
    if (i < 1)
    {
        cout << "Parameterised sum: " << sum << endl;
        return;
    }
    sumParameterised(i - 1, sum + i);
}
// f(3,0) -> f(2,3) -> f(1,5) -> f(0,6) print 6. TC: O(n) | SC: O(n)

// Functional: n + f(n-1), each call returns a value to its caller.
int sumFunctional(int n)
{
    if (n < 1)
        return 0;
    return n + sumFunctional(n - 1);
}
// f(3) = 3+f(2) = 3+(2+f(1)) = 3+(2+(1+f(0))) = 3+2+1+0 = 6
// TC: O(n) | SC: O(n) (closed form n(n+1)/2 is the real O(1) way, this is for practice)

// Factorial: n * f(n-1) down to f(0)=1
long long factorialFunctional(int n)
{
    if (n <= 1) // 0! and 1! both = 1
        return 1;
    return (long long)n * factorialFunctional(n - 1);
}
// use long long — 13! already overflows a 32-bit int.
// TC: O(n) | SC: O(n)

void factorialParameterised(int i, long long product)
{
    if (i < 1)
    {
        cout << "Parameterised factorial: " << product << endl;
        return;
    }
    factorialParameterised(i - 1, product * i);
}

// Reverse an array using recursion

// two pointers, swap ends, move inward
void reverseArrayTwoPointer(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    swap(a[l], a[r]);
    reverseArrayTwoPointer(a, l + 1, r - 1);
}
// TC: O(n) | SC: O(n)

// single index, mirror against (n-1-i)
void reverseArraySingleIndex(vector<int> &a, int i, int n)
{
    if (i >= n / 2)
        return;
    swap(a[i], a[n - i - 1]);
    reverseArraySingleIndex(a, i + 1, n);
}
// TC: O(n) | SC: O(n)

// Palindrome check, recursive. "MADAM", "1221" etc.
bool isStringPalindrome(const string &s, int i)
{
    int n = s.size();
    if (i >= n / 2) // compared every mirrored pair, no mismatch
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    return isStringPalindrome(s, i + 1);
}
// TC: O(n) | SC: O(n)

// Nth Fibonacci: 0,1,1,2,3,5,8,13... f(n) = f(n-1)+f(n-2)

// iterative, optimal
long long fibonacciLoop(int n)
{
    if (n <= 1)
        return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        long long curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
// TC: O(n) | SC: O(1)

// recursive, branches into 2 calls each time
long long fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
// f(4) tree — f(2) and f(1) get recomputed multiple times:
//              f(4)
//             /    |
//          f(3)     f(2)
//          /  |     /  |
//       f(2) f(1) f(1) f(0)
//       /  |
//     f(1) f(0)
// TC: O(2^n) (lots of repeated sub-calls) | SC: O(n) (deepest single chain)
// this is why the loop version above is the one to actually use.

int main()
{
    cout << "--- Q1: Print Coder n times ---\n";
    printName(1, 5);
    cout << endl;

    cout << "\n--- Q2: Print linearly 1 to N ---\n";
    printLinear(1, 5);
    cout << endl;

    cout << "\n--- Q3: Print from N to 1 ---\n";
    printReverseLinear(5, 5);
    cout << endl;

    cout << "\n--- Q4: Print 1 to N via backtracking ---\n";
    printLinearBacktrack(5, 5);
    cout << endl;

    cout << "\n--- Q5: Print N to 1 via backtracking ---\n";
    printReverseBacktrack(1, 5);
    cout << endl;

    cout << "\n--- Sum of first N natural numbers (N=5) ---\n";
    sumParameterised(5, 0);
    cout << "Functional sum: " << sumFunctional(5) << endl;
    cout << "Closed-form check n(n+1)/2: " << (5 * 6) / 2 << endl;

    cout << "\n--- Factorial (N=5) ---\n";
    cout << "Functional factorial: " << factorialFunctional(5) << endl;
    factorialParameterised(5, 1);

    cout << "\n--- Reverse an Array ---\n";
    vector<int> arr1 = {1, 2, 3, 4, 5};
    reverseArrayTwoPointer(arr1, 0, arr1.size() - 1);
    cout << "Two-pointer reversed: ";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    reverseArraySingleIndex(arr2, 0, arr2.size());
    cout << "Single-index reversed: ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    cout << "\n--- Palindrome Check ---\n";
    cout << "isStringPalindrome(\"MADAM\"): " << (isStringPalindrome("MADAM", 0) ? "true" : "false") << endl;
    cout << "isStringPalindrome(\"1221\"): " << (isStringPalindrome("1221", 0) ? "true" : "false") << endl;
    cout << "isStringPalindrome(\"HELLO\"): " << (isStringPalindrome("HELLO", 0) ? "true" : "false") << endl;

    cout << "\n--- Nth Fibonacci Number ---\n";
    cout << "fibonacciLoop(10): " << fibonacciLoop(10) << endl;
    cout << "fibonacciRecursive(10): " << fibonacciRecursive(10) << endl;

    return 0;
}