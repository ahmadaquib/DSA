#include <bits/stdc++.h>
using namespace std;

/*
    Hashing: "how many times does X appear?" for a bunch of queries.

    Brute force: for each query, scan the whole array -> O(n) per query
    -> O(n*q) total. n=q=1e5 gives ~1e10 ops, way too slow.

    Hashing = precompute a frequency table once in O(n), then every
    query is just a lookup.
*/

// 1) Number hashing with a plain array — fastest, but only works when
// values are small enough to use directly as indices.
// int array: safe up to ~1e6 local, ~1e7 global.
// bool array: safe up to ~1e7 local, ~1e8 global.
// negative numbers or huge values don't fit -> use map/unordered_map instead.
void demoNumberHashingArray()
{
    cout << "\n--- Number Hashing (array) ---\n";

    // input
    int arr[] = {1, 3, 2, 1, 3};
    int n = 5;
    int queries[] = {1, 2, 4, 3, 12};
    int q = 5;

    // precompute -> O(n)
    int hashArr[13] = {0};
    for (int i = 0; i < n; i++)
        hashArr[arr[i]]++;

    // fetch -> O(1) each
    for (int i = 0; i < q; i++)
        cout << "frequency of " << queries[i] << ": " << hashArr[queries[i]] << endl;

    // TC: O(n) precompute + O(1) per fetch | SC: O(range of values)
}

// 2) Character hashing with a plain array
// map 'a'-'z' to 0-25 by subtracting 'a' (ascii 97), so 26 slots is enough.
void demoCharacterHashingArray()
{
    cout << "\n--- Character Hashing (array) ---\n";

    string s = "abcdabcfc";
    char queries[] = {'a', 'b', 'c', 'z'};

    int hashArr[26] = {0};
    for (char c : s)
        hashArr[c - 'a']++;

    for (char c : queries)
        cout << "frequency of '" << c << "': " << hashArr[c - 'a'] << endl;

    // if chars outside a-z are possible, use a 256-slot array indexed by raw ascii instead.
    // TC: O(n) precompute + O(1) per fetch | SC: O(1) (fixed 26 slots)
}

// 3) Number hashing with map/unordered_map — for values too big/negative for an array
void demoNumberHashingMap()
{
    cout << "\n--- Number Hashing (map) ---\n";

    vector<int> arr = {1, 2, 1, 3, 2, 1000000007, 1000000007};
    vector<int> queries = {1, 2, 3, 1000000007, 999};

    map<int, int> mpp; // sorted by key, O(log n) insert/find
    for (int x : arr)
        mpp[x]++;

    // mpp[key] on a missing key auto-inserts it with value 0 -> "not found" reads as 0 for free
    for (int x : queries)
        cout << "frequency of " << x << ": " << mpp[x] << endl;

    // TC: O(n log n) precompute, O(log n) per fetch | SC: O(distinct elements)
}

void demoNumberHashingUnorderedMap()
{
    cout << "\n--- Number Hashing (unordered_map) ---\n";

    vector<int> arr = {1, 2, 1, 3, 2, 1000000007, 1000000007};
    vector<int> queries = {1, 2, 3, 1000000007, 999};

    unordered_map<int, int> mpp;
    for (int x : arr)
        mpp[x]++;

    for (int x : queries)
        cout << "frequency of " << x << ": " << mpp[x] << endl;

    // TC: O(1) average, O(n) worst case (collisions) | SC: O(distinct elements)
    // if unordered_map TLEs on an adversarial case, switch to map — guaranteed O(log n)
}

// Q1: Counting Frequencies of Array Elements
// map over unordered_map here so the printout comes out sorted for free.
void countFrequencies(const vector<int> &arr)
{
    map<int, int> mpp;
    for (int x : arr)
        mpp[x]++;

    for (const auto &[num, freq] : mpp)
        cout << num << " -> " << freq << endl;
    // TC: O(n log n) | SC: O(distinct elements)
}

// Q2: Highest Occurring Element in an Array
pair<int, int> highestOccurringElement(const vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (int x : arr)
        mpp[x]++;

    int bestValue = arr[0], bestFreq = 0;
    for (const auto &[num, freq] : mpp)
    {
        // tie-break: smaller value wins
        if (freq > bestFreq || (freq == bestFreq && num < bestValue))
        {
            bestFreq = freq;
            bestValue = num;
        }
    }
    return {bestValue, bestFreq};
    // TC: O(n) average | SC: O(distinct elements)
}

int main()
{
    demoNumberHashingArray();
    demoCharacterHashingArray();
    demoNumberHashingMap();
    demoNumberHashingUnorderedMap();

    cout << "\n--- Q1: Counting Frequencies of Array Elements ---\n";
    vector<int> arr1 = {1, 2, 1, 3, 2, 1};
    countFrequencies(arr1);

    cout << "\n--- Q2: Highest Occurring Element ---\n";
    vector<int> arr2 = {4, 5, 4, 4, 6, 5};
    auto [value, freq] = highestOccurringElement(arr2);
    cout << "highest occurring value: " << value << " (occurs " << freq << " times)" << endl;

    return 0;
}

/*
    Hash function techniques (how a table turns a key into an index) —
    conceptual only, map/unordered_map already do this internally:
    - Division method: index = key % tableSize. Bad tableSize -> lots of
      collisions, usually resolved with linear chaining (a list per index).
    - Folding method: split the key into parts, combine them into an index.
    - Mid-square method: square the key, take the middle digits.

    map vs unordered_map:
    - map: balanced BST, sorted keys, O(log n) guaranteed, key can be
      anything orderable (pair, struct with operator<, etc).
    - unordered_map: hash table, no ordering, O(1) average but O(n)
      worst case, key must be a single hashable type.
*/