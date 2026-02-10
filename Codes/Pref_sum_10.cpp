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
// Main function here : Contigious Array
// ---------------------------
int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> mp;

    int diff = 0; // zeroes - ones
    int ans = 0;

    mp[0] = -1; // difference 0 occurs before the array starts

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] == 0)
            diff++;
        else
            diff--;

        if (mp.count(diff))
        {
            ans = max(ans, i - mp[diff]);
        }
        else
        {
            mp[diff] = i;
        }
    }

    return ans;
}

// Driver
void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    read(nums);

    int x = findMaxLength(nums);
    cout << x;
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
