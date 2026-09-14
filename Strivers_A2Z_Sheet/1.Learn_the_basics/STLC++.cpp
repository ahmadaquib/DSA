#include <bits/stdc++.h>
using namespace std;

void printVec(const string &label, const vector<int> &v)
{
    cout << label << ": ";
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void explainPair()
{
    cout << "\n--- Pairs ---\n";

    pair<int, int> p1 = {1, 3};
    cout << "p1: " << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3, 4}}; // nested pair
    cout << "p2: " << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = {{1, 5}, {2, 4}, {5, 1}};
    cout << "arr[1].second: " << arr[1].second << endl;

    // Time Complexity -> access .first/.second: O(1)
    // Space Complexity -> O(1)
}

void explainVector()
{
    cout << "\n--- Vectors ---\n";

    vector<int> newvector;
    newvector.push_back(1);
    newvector.emplace_back(1);
    printVec("newvector", newvector);

    vector<int> vectorWithAllValueSame(5, 100);
    vector<int> vectorWithAllValueZero(5);
    printVec("vectorWithAllValueSame", vectorWithAllValueSame);
    printVec("vectorWithAllValueZero", vectorWithAllValueZero);

    vector<int> v1(5, 20);
    vector<int> v2(v1); // v2 copies v1
    printVec("v1", v1);
    printVec("v2 (copy of v1)", v2);

    // Iterators
    {
        vector<int> v = {1, 2, 3, 4, 5};
        auto it = v.begin();
        it++;
        cout << "it after v.begin()+1: " << *it << endl;

        it = it + 2;
        cout << "it after +2 more: " << *it << endl;

        auto itRBegin = v.rbegin(); // rend() also exists but is never dereferenced directly (marks one-before-first, reverse direction)
        cout << "*rbegin: " << *itRBegin << endl;

        cout << "v[0]: " << v[0] << " | v.at(0): " << v.at(0) << " | v.back(): " << v.back() << endl;

        cout << "loop via iterator: ";
        for (auto i = v.begin(); i != v.end(); i++)
            cout << *i << " ";
        cout << endl;

        cout << "range-based loop: ";
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    // Erase: v.erase(pos) removes one element, v.erase(start, end) removes a range [start, end)
    {
        vector<int> v = {10, 20, 12, 13};
        v.erase(v.begin() + 1);
        printVec("after erase(begin+1)", v);

        vector<int> v2 = {10, 20, 12, 23, 35};
        v2.erase(v2.begin() + 2, v2.begin() + 4);
        printVec("after erase(range)", v2);
    }

    // Insert
    {
        vector<int> v(2, 100);
        v.insert(v.begin(), 300);
        printVec("after insert single", v);

        v.insert(v.begin() + 1, 2, 10);
        printVec("after insert multiple copies", v);

        vector<int> copy(2, 50);
        v.insert(v.begin(), copy.begin(), copy.end());
        printVec("after insert range", v);
    }

    // size / pop_back / swap / clear / empty
    {
        vector<int> v = {10, 20};
        cout << "size: " << v.size() << endl;

        v.pop_back();
        printVec("after pop_back", v);

        vector<int> a = {10, 20};
        vector<int> b = {30, 40};
        a.swap(b);
        printVec("a after swap", a);
        printVec("b after swap", b);

        v.clear();
        cout << "empty after clear: " << v.empty() << endl;
    }

    // Time Complexity -> push/pop_back: O(1) amortized | access []/at/back: O(1) | insert/erase middle: O(n)
    // Space Complexity -> O(n)
}

void explainList()
{
    cout << "\n--- List (doubly linked list) ---\n";
    list<int> ls;
    ls.push_back(2);     // O(1)
    ls.emplace_back(4);  // O(1)
    ls.push_front(5);    // O(1)
    ls.emplace_front(3); // O(1)

    cout << "list: ";
    for (int x : ls)
        cout << x << " ";
    cout << endl;

    // most vector-like functions work the same way here:
    // begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap()
    // NOTE: no random access -> no [] or .at()

    // Time Complexity -> push/pop front & back: O(1) | insert/erase at known iterator: O(1) | no random access
    // Space Complexity -> O(n)
}

void explainDeque()
{
    cout << "\n--- Deque (double ended queue) ---\n";
    deque<int> dq;
    dq.push_back(1);     // O(1)
    dq.emplace_back(2);  // O(1)
    dq.push_front(4);    // O(1)
    dq.emplace_front(3); // O(1)

    cout << "deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_back();
    dq.pop_front();
    cout << "after pop_back & pop_front: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    cout << "back: " << dq.back() << " | front: " << dq.front() << endl;

    // rest of the functions are same as vector:
    // begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap()

    // Time Complexity -> push/pop front & back: O(1) | random access []: O(1) | insert/erase middle: O(n)
    // Space Complexity -> O(n)
}

void explainStack()
{
    cout << "\n--- Stack (LIFO) ---\n";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);

    cout << "top: " << st.top() << endl;

    st.pop();
    cout << "top after pop: " << st.top() << endl;
    cout << "size: " << st.size() << endl;
    cout << "empty: " << st.empty() << endl;

    stack<int> st1, st2;
    st1.swap(st2); // O(1), just swaps internal container pointers

    // Time Complexity -> push/pop/top: O(1)
    // Space Complexity -> O(n)
}

void explainQueue()
{
    cout << "\n--- Queue (FIFO) ---\n";
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(1);

    q.back() += 5;
    cout << "back after +5: " << q.back() << endl;
    cout << "front: " << q.front() << endl;

    q.pop();
    cout << "front after pop: " << q.front() << endl;

    // Time Complexity -> push/pop/front/back: O(1)
    // Space Complexity -> O(n)
}

void explainPQ()
{
    cout << "\n--- Priority Queue (heap) ---\n";

    // Max Heap (default)
    {
        priority_queue<int> pq;
        pq.push(5);
        pq.push(2);
        pq.push(8);
        pq.emplace(10);

        cout << "max-heap top: " << pq.top() << endl;
        pq.pop();
        cout << "max-heap top after pop: " << pq.top() << endl;
    }

    // Min Heap: pass greater<int> as the comparator
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(5);
        pq.push(2);
        pq.push(8);
        pq.emplace(10);

        cout << "min-heap top: " << pq.top() << endl;
    }

    // Time Complexity -> push/pop: O(log n) | top: O(1)
    // Space Complexity -> O(n)
}

void explainSet()
{
    cout << "\n--- Set (sorted, unique elements, BST internally) ---\n";
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2); // duplicate, ignored
    st.insert(4);
    st.insert(3);

    cout << "set: ";
    for (int x : st)
        cout << x << " ";
    cout << endl;

    // begin(), end(), rbegin(), rend(), size(), empty(), swap() work same as vector

    auto itFound = st.find(3);
    cout << "find(3): " << (itFound != st.end() ? "found" : "not found") << endl;

    auto itMissing = st.find(6);
    cout << "find(6): " << (itMissing != st.end() ? "found" : "not found") << endl;

    st.erase(4); // erase by value
    cout << "after erase(4): ";
    for (int x : st)
        cout << x << " ";
    cout << endl;

    int cnt = st.count(1); // only ever 0 or 1, since a set has unique elements
    cout << "count(1): " << cnt << endl;

    auto itToErase = st.find(3);
    st.erase(itToErase); // erase by iterator
    cout << "after erase(iterator to 3): ";
    for (int x : st)
        cout << x << " ";
    cout << endl;

    st.insert(4);
    st.insert(5);
    auto it1 = st.find(2);
    auto it2 = st.find(5);
    st.erase(it1, it2); // erases [it1, it2)
    cout << "after erase(range): ";
    for (int x : st)
        cout << x << " ";
    cout << endl;

    // lower_bound/upper_bound work like in vector, but O(log n) since set is a BST
    auto lb = st.lower_bound(2); // first element >= 2
    auto ub = st.upper_bound(3); // first element > 3
    cout << "lower_bound(2): " << (lb != st.end() ? to_string(*lb) : "end") << endl;
    cout << "upper_bound(3): " << (ub != st.end() ? to_string(*ub) : "end") << endl;

    // Time Complexity -> insert/erase/find/lower_bound/upper_bound: O(log n)
    // Space Complexity -> O(n)
}

void explainMultiSet()
{
    cout << "\n--- Multiset (sorted, duplicates allowed) ---\n";
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << "multiset: ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    int cnt = ms.count(1);
    cout << "count(1): " << cnt << endl;

    ms.erase(ms.find(1)); // erase(iterator) removes only ONE occurrence
    cout << "after erase(iterator, removes one): ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    // ms.erase(value) instead removes ALL occurrences of that value
    // multiset iterators are bidirectional, not random access, so use std::next() for offsets, not +N
    ms.insert(1);
    ms.erase(ms.find(1), next(ms.find(1), 1));
    cout << "after erase(range via next()): ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    // rest of the functions are the same as set
    // Time Complexity -> insert/erase/find: O(log n)
    // Space Complexity -> O(n)
}

void explainUSet()
{
    cout << "\n--- Unordered Set (hash table) ---\n";
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);

    cout << "unordered_set (no guaranteed order): ";
    for (int x : st)
        cout << x << " ";
    cout << endl;

    // lower_bound() & upper_bound() do NOT work here (no ordering)
    // rest of the functions are the same as set
    // faster on average than set, but worst case degrades badly on hash collisions

    // Time Complexity -> insert/erase/find: O(1) average, O(n) worst case (collisions)
    // Space Complexity -> O(n)
}

void explainMap()
{
    cout << "\n--- Map (sorted by key, unique keys, BST internally) ---\n";
    map<int, int> mpp;
    // other map declarations, for reference:
    // map<int, pair<int,int>> mpp2;
    // map<pair<int,int>, int> mpp3;

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({2, 4});

    cout << "map (auto-sorted by key): ";
    for (auto it : mpp)
        cout << "{" << it.first << "," << it.second << "} ";
    cout << endl;

    cout << "mpp[1]: " << mpp[1] << endl;
    cout << "mpp[100] (operator[] creates the key if missing, value 0): " << mpp[100] << endl;

    auto itFound = mpp.find(3);
    cout << "find(3): " << (itFound != mpp.end() ? to_string(itFound->second) : "not found") << endl;

    auto itMissing = mpp.find(50);
    cout << "find(50): " << (itMissing != mpp.end() ? "found" : "not found") << endl;

    auto lb = mpp.lower_bound(2); // first key >= 2
    auto ub = mpp.upper_bound(3); // first key > 3
    cout << "lower_bound(2) key: " << lb->first << " | upper_bound(3) key: " << ub->first << endl;

    // erase(key), erase(iterator), erase(range), count(), size(), swap() work as in set

    // Time Complexity -> []/insert/erase/find/lower_bound/upper_bound: O(log n)
    // Space Complexity -> O(n)
}

void explainMultiMap()
{
    cout << "\n--- Multimap ---\n";
    // same as map, but allows duplicate keys
    // mpp[key] cannot be used here since one key can map to many values
    // Time Complexity -> insert/erase/find: O(log n)
    // Space Complexity -> O(n)
}

void explainUnorderedMap()
{
    cout << "\n--- Unordered Map ---\n";
    // same relationship to map as unordered_set has to set:
    // no ordering, better average complexity, worse worst case
    // Time Complexity -> []/insert/erase/find: O(1) average, O(n) worst case (collisions)
    // Space Complexity -> O(n)
}

// sorts pairs by second element ascending; if second is equal, by first element descending
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    else if (p1.second == p2.second)
        return p1.first > p2.first;
    return false;
}

void explainExtra()
{
    cout << "\n--- Extra Algorithms & Tricks ---\n";

    // sort()
    {
        int a[] = {5, 3, 1, 4, 2};
        int n = 5;
        sort(a, a + n); // ascending
        cout << "sorted array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        sort(a + 2, a + 4); // sorts only the partial range [2,4)
        cout << "after partial sort(a+2, a+4): ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        sort(a, a + n, greater<int>()); // descending
        cout << "descending sort: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        vector<int> v = {5, 3, 1, 4, 2};
        sort(v.begin(), v.end());
        printVec("sorted vector", v);
    }

    // custom comparator sort
    {
        pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
        int n = 3;
        sort(arr, arr + n, comp); // by comp(): second asc, then first desc on ties
        cout << "custom sorted pairs: ";
        for (int i = 0; i < n; i++)
            cout << "{" << arr[i].first << "," << arr[i].second << "} ";
        cout << endl;
    }

    // bit tricks
    {
        int num = 7;
        int cnt = __builtin_popcount(num); // counts set bits
        cout << "popcount(" << num << "): " << cnt << endl;

        long long bigNum = 1657329492388;
        int bigCnt = __builtin_popcountll(bigNum); // same, for long long
        cout << "popcountll(" << bigNum << "): " << bigCnt << endl;
    }

    // permutations
    {
        string s = "123";
        sort(s.begin(), s.end()); // next_permutation needs a sorted starting point to cover all of them
        cout << "all permutations of \"123\": ";
        do
        {
            cout << s << " ";
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }

    // max/min element
    {
        int a[] = {3, 7, 1, 9, 4};
        int n = 5;
        int maxi = *max_element(a, a + n);
        int mini = *min_element(a, a + n);
        cout << "max: " << maxi << " | min: " << mini << endl;
    }

    // Time Complexity -> sort: O(n log n) | next_permutation: O(n) per call | max/min_element: O(n) | popcount: O(1)
}

int main()
{
    explainPair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUSet();
    explainMap();
    explainMultiMap();
    explainUnorderedMap();
    explainExtra();
    return 0;
}