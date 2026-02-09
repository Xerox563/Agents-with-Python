#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Check prime
bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Check palindrome (string)
bool isPalindrome(const string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}

// Read vector
template <typename T>
void read(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

// Print vector
template <typename T>
void print(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << "\n";
}

// ---------------------------
// Main function here
// ---------------------------
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> ans(n + 1, 0);
    for (auto &it : bookings)
    {
        int s = it[0];
        int e = it[1];
        int seats = it[2];
        ans[s] += seats;
        if (e + 1 <= n)
            ans[e + 1] -= seats;
    }

    // Taking prefix sum of ans ..
    vector<int> pref(n + 1);
    pref[0] = ans[0];
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + ans[i];
    }
    for (auto &val : pref)
    {
        cout << val << " ";
    }
    cout << endl;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(pref[i]);
    }
    return res;
}

// Driver
void solve()
{
    int n = 5;
    // cin >> n;

    int bookings[3][3] = [ [ 1, 2, 10 ], [ 2, 3, 20 ], [ 2, 5, 25 ] ];

    cout << corpFlightBookings(arr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
