/*
    Patterns — Easy & Medium
    Basic Rule:
        Outer loop -> rows, Inner loop -> columns (extend to i, j, k for x/y/z axes).
        Print the required character in the innermost loop.
        Looking for symmetry between rows helps you spot the loop bounds faster.

    All patterns below run in O(n^2) time (two nested loops over an n-sized grid)
    and O(1) space, unless noted otherwise in a specific function.

    Sample input.txt (order matches the two cin calls in main()):
    9    -> patternNum   (valid range: 1-22, pick whichever pattern to test)
    5    -> n            (grid size fed to that pattern)
*/

#include <bits/stdc++.h>
using namespace std;

// Pattern 1: solid n x n square of stars
void printPattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 2: right triangle, row i has (i+1) stars
void printPattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 3: right triangle of numbers, row i counts 1..(i+1)
void printPattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
}

// Pattern 4: right triangle where row i repeats the row number i, (i) times
void printPattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}

// Pattern 5: inverted right triangle of stars (row 1 has n stars, shrinking)
void printPattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 6: same shrinking shape as Pattern 5, but with numbers 1..(n-i+1)
void printPattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
            cout << j;
        cout << endl;
    }
}

// Pattern 7: pyramid — leading spaces, then (2i+1) stars, then trailing spaces
void printPattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        cout << endl;
    }
}

// Pattern 8: inverted pyramid (mirror of Pattern 7)
void printPattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            cout << "*";
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << endl;
    }
}

// Pattern 9: diamond, built by stacking Pattern 7 (pyramid) on Pattern 8 (inverted pyramid)
void printPattern9(int n)
{
    printPattern7(n);
    printPattern8(n);
}

// Pattern 10: triangle that grows then shrinks, no spaces (1..n..1 stars per row)
void printPattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 11: binary triangle, each row starts with 1 if the row is even-indexed, alternating 0/1 across it
void printPattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = (i % 2 == 0) ? 1 : 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

// Pattern 12: numbers pyramid with a hollow middle — 1..i, gap, then i..1
void printPattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        for (int j = 1; j <= space; j++)
            cout << " ";
        for (int j = i; j >= 1; j--)
            cout << j;
        cout << endl;
        space -= 2;
    }
}

// Pattern 13: right triangle with a single counter that keeps incrementing across all rows
void printPattern13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// Pattern 14: right triangle of letters, row i shows A..(A+i)
void printPattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
            cout << ch;
        cout << endl;
    }
}

// Pattern 15: inverted letter triangle (mirror of Pattern 14)
void printPattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + n - i - 1; ch++)
            cout << ch;
        cout << endl;
    }
}

// Pattern 16: row i repeats a single letter ('A'+i), (i+1) times
void printPattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
            cout << ch;
        cout << endl;
    }
}

// Pattern 17: letter pyramid that rises then falls within each row (e.g. A B C B A)
void printPattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";

        char ch = 'A';
        int breakPoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakPoint)
                ch++;
            else
                ch--;
        }

        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        cout << endl;
    }
}

// Pattern 18: right-aligned window of letters that always ends at the last letter in range
void printPattern18(int n)
{
    // last letter of the range is 'A' + n - 1 — derive it from n, don't hardcode
    // a specific letter, or the pattern only works for one particular n
    char lastChar = 'A' + n - 1;
    for (int i = 0; i < n; i++)
    {
        for (char ch = lastChar - i; ch <= lastChar; ch++)
            cout << ch << " ";
        cout << endl;
    }
}

// Pattern 19: butterfly pattern — two mirrored triangles, wide at the edges and narrow in the middle
void printPattern19(int n)
{
    // Upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "*";
        for (int j = 1; j <= 2 * i; j++)
            cout << " ";
        for (int j = 1; j <= n - i; j++)
            cout << "*";
        cout << endl;
    }

    // Lower half (mirror of the upper half)
    int iniS = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
            cout << "*";
        for (int j = 1; j <= iniS; j++)
            cout << " ";
        for (int j = 1; j <= i + 1; j++)
            cout << "*";
        iniS -= 2;
        cout << endl;
    }
}

// Pattern 20: hollow diamond of stars (grows then shrinks, hollow in the middle)
void printPattern20(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
            cout << "*";
        for (int j = 1; j <= spaces; j++)
            cout << " ";
        for (int j = 1; j <= stars; j++)
            cout << "*";
        cout << endl;

        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

// Pattern 21: hollow square (border made of stars, interior blank)
void printPattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

// Pattern 22: nested concentric squares of numbers, layered from n (outer) to 1 (center)
// Runs over a (2n-1) x (2n-1) grid, so time is O(n^2) — same order as the others despite the larger grid.
void printPattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i, left = j, right = (2 * n - 2) - j, down = (2 * n - 2) - i;
            cout << (n - min(min(top, down), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter pattern number (1-22): ";
    int patternNum;
    cin >> patternNum;

    cout << "Enter n: ";
    int n;
    cin >> n;
    cout << endl;

    switch (patternNum)
    {
    case 1:
        printPattern1(n);
        break;
    case 2:
        printPattern2(n);
        break;
    case 3:
        printPattern3(n);
        break;
    case 4:
        printPattern4(n);
        break;
    case 5:
        printPattern5(n);
        break;
    case 6:
        printPattern6(n);
        break;
    case 7:
        printPattern7(n);
        break;
    case 8:
        printPattern8(n);
        break;
    case 9:
        printPattern9(n);
        break;
    case 10:
        printPattern10(n);
        break;
    case 11:
        printPattern11(n);
        break;
    case 12:
        printPattern12(n);
        break;
    case 13:
        printPattern13(n);
        break;
    case 14:
        printPattern14(n);
        break;
    case 15:
        printPattern15(n);
        break;
    case 16:
        printPattern16(n);
        break;
    case 17:
        printPattern17(n);
        break;
    case 18:
        printPattern18(n);
        break;
    case 19:
        printPattern19(n);
        break;
    case 20:
        printPattern20(n);
        break;
    case 21:
        printPattern21(n);
        break;
    case 22:
        printPattern22(n);
        break;
    default:
        cout << "Invalid pattern number. Choose 1-22." << endl;
    }
    return 0;
}