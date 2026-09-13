#include <bits/stdc++.h>
using namespace std;

/*
    Digit Extraction — the base trick every problem below builds on.
    n % 10 gives the last digit, n / 10 drops that last digit.
    Example: n = 7789
        7789 % 10 = 9   |   7789 / 10 = 778
        778  % 10 = 8   |   778  / 10 = 77
        77   % 10 = 7   |   77   / 10 = 7
        7    % 10 = 7   |   7    / 10 = 0  -> loop ends
*/
void explainDigitExtraction()
{
    cout << "\n--- Digit Extraction ---\n";
    int n = 7789;
    cout << "digits of " << n << " (last to first): ";
    while (n > 0) // NOTE: condition must be n > 0, not n < 0, or the loop never runs
    {
        int lastDigit = n % 10;
        cout << lastDigit << " ";
        n /= 10;
    }
    cout << endl;
}

// Problem 1: Count all Digits of a Number
void countDigits(int n)
{
    cout << "\n--- Count Digits (n=" << n << ") ---\n";

    // Approach 1: Brute force — extract digits one by one, count each pop
    {
        int temp = n, count = 0;
        while (temp > 0)
        {
            temp /= 10;
            count++;
        }
        cout << "Brute force count: " << count << endl;
        // Time Complexity -> O(log10(N)), since we divide by 10 each step
        // Space Complexity -> O(1)
    }

    // Approach 2: Optimal — use log10, since number of digits = floor(log10(n)) + 1
    {
        int count = (n == 0) ? 1 : (int)(log10(n) + 1);
        cout << "Optimal (log10) count: " << count << endl;
        // Time Complexity -> O(1)
        // Space Complexity -> O(1)
    }
}

// Problem 2: Reverse a Number
int reverseNumber(int n)
{
    long long revNumber = 0; // use long long while building, to avoid overflow mid-computation
    while (n != 0)
    {
        int lastDigit = n % 10;
        n /= 10;
        revNumber = (revNumber * 10) + lastDigit;
    }
    return (int)revNumber;
    // Time Complexity -> O(log10(N))
    // Space Complexity -> O(1)
}

// Problem 3: Palindrome Number
// Idea: reverse the number fully, then compare the reversed value to the original
bool isPalindrome(int n)
{
    int original = n;
    long long revNumber = 0;
    while (n != 0)
    {
        int lastDigit = n % 10;
        n /= 10;
        revNumber = (revNumber * 10) + lastDigit;
    }
    return original == revNumber;
    // Time Complexity -> O(log10(N))
    // Space Complexity -> O(1)
}

// Problem 4: GCD (HCF) of Two Numbers
int gcdBruteForce(int a, int b)
{
    // Brute force: try every number from min(a,b) down to 1,
    // the first one that divides both a and b is the GCD
    int ans = 1;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
            ans = i;
    }
    return ans;
    // Time Complexity -> O(min(a,b))
    // Space Complexity -> O(1)
}

// Better: count down from min(a,b), stop at the FIRST common divisor found
// (since we go from large to small, the first hit is already the greatest)
int gcdBetter(int a, int b)
{
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
    // Time Complexity -> O(min(a,b)) worst case, but exits early in practice
    // Space Complexity -> O(1)
}

// Optimal: Euclidean Algorithm
// gcd(a, b) = gcd(a - b, b) when a > b  ... repeated subtraction is slow,
// so instead replace the larger number with (larger % smaller) — this jumps
// straight to what repeated subtraction would eventually reach.
// Keep going until one of them becomes 0; the other is the GCD.
int gcdEuclidean(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a == 0) ? b : a;
    // Time Complexity -> O(log(min(a,b)))
    // Space Complexity -> O(1)
}

// Problem 5: Check if a Number is an Armstrong Number
// Definition: a number is an Armstrong number if the sum of its own digits,
// each raised to the power of (total digit count), equals the number itself.
// Example: 153 has 3 digits -> 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 -> Armstrong
bool isArmstrong(int n)
{
    int original = n;
    int totalDigits = (n == 0) ? 1 : (int)(log10(n) + 1);

    long long sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += (long long)pow(digit, totalDigits);
        n /= 10;
    }
    return sum == original;
    // Time Complexity -> O(log10(N) * log(totalDigits)) because of pow(); O(log10(N)) if you write your own O(1) power loop
    // Space Complexity -> O(1)
}

// Problem 6: Print all Divisors of a Number
void printDivisors(int n)
{
    cout << "\n--- Print Divisors (n=" << n << ") ---\n";

    // Brute force: check every number from 1 to n
    {
        cout << "Brute force divisors: ";
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                cout << i << " ";
        }
        cout << endl;
        // Time Complexity -> O(N)
        // Space Complexity -> O(1)
    }

    // Optimal: only check up to sqrt(n). If i divides n, then n/i is also a divisor,
    // so each check gives you a pair of divisors for the cost of one loop iteration.
    {
        cout << "Optimal divisors: ";
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
                if (i != n / i) // avoid pushing the same divisor twice for perfect squares
                    divisors.push_back(n / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        for (int d : divisors)
            cout << d << " ";
        cout << endl;
        // Time Complexity -> O(sqrt(N)) for finding + O(k log k) for sorting the k divisors found
        // Space Complexity -> O(k) to store the divisors
    }
}

// Problem 7: Check for Prime Number
bool isPrimeBruteForce(int n)
{
    // Brute force: a prime has exactly two divisors, 1 and itself.
    // Check every number from 2 to n-1 — if any divides n, it's not prime.
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // Time Complexity -> O(N)
    // Space Complexity -> O(1)
}

bool isPrimeOptimal(int n)
{
    // Optimal: same reasoning as printDivisors — a factor pair always has one
    // factor <= sqrt(n), so it's enough to check up to sqrt(n).
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // Time Complexity -> O(sqrt(N))
    // Space Complexity -> O(1)
}

int main()
{
    explainDigitExtraction();

    countDigits(7789);

    cout << "\n--- Reverse a Number ---\n";
    cout << "reverse(100200): " << reverseNumber(100200) << endl;
    // Time Complexity -> O(log10(N)) | Space Complexity -> O(1)

    cout << "\n--- Palindrome Check ---\n";
    cout << "isPalindrome(12321): " << (isPalindrome(12321) ? "true" : "false") << endl;
    cout << "isPalindrome(12345): " << (isPalindrome(12345) ? "true" : "false") << endl;
    // Time Complexity -> O(log10(N)) | Space Complexity -> O(1)

    cout << "\n--- GCD / HCF ---\n";
    cout << "gcdBruteForce(20, 28): " << gcdBruteForce(20, 28) << endl;
    cout << "gcdBetter(20, 28): " << gcdBetter(20, 28) << endl;
    cout << "gcdEuclidean(20, 28): " << gcdEuclidean(20, 28) << endl;

    cout << "\n--- Armstrong Number ---\n";
    cout << "isArmstrong(153): " << (isArmstrong(153) ? "true" : "false") << endl;
    cout << "isArmstrong(123): " << (isArmstrong(123) ? "true" : "false") << endl;
    // Time Complexity -> O(log10(N)) | Space Complexity -> O(1)

    printDivisors(36);

    cout << "\n--- Prime Check ---\n";
    cout << "isPrimeBruteForce(29): " << (isPrimeBruteForce(29) ? "true" : "false") << endl;
    cout << "isPrimeOptimal(29): " << (isPrimeOptimal(29) ? "true" : "false") << endl;
    cout << "isPrimeOptimal(28): " << (isPrimeOptimal(28) ? "true" : "false") << endl;

    return 0;
}