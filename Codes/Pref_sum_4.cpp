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
// Main function here : Range Sum Query - Immutable
// ---------------------------
vector<int> ans;
NumArray(vector<int> &nums)
{
    int n = nums.size();
    ans.resize(n);
    ans[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = nums[i] + ans[i - 1];
    }
}

int sumRange(int left, int right)
{
    if (left == 0)
    {
        return ans[right];
    }
    else
    {
        return ans[right] - ans[left - 1];
    }
}
// Driver
void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    read(arr);

    cout << NumArray(arr);
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
