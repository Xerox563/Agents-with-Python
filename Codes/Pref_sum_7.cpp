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
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n, 0);
    ll cnt_zeroes = 0;
    prefix[0] = nums[0];
    if (nums[0] == 0)
        cnt_zeroes++;
    for (ll i = 1; i < n; i++)
    {
        if (nums[i] == 0)
            cnt_zeroes++;
        prefix[i] = prefix[i - 1] * nums[i];
    }
    ll p = 1;
    if (cnt_zeroes == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            p *= nums[i];
        }
    }
    vector<int> ans;
    for (ll i = 0; i < n; i++)
    {
        if (nums[i] == 0 && cnt_zeroes == 1)
        {
            ans.push_back(p);
        }
        else if (cnt_zeroes > 1)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back((ll)(prefix[n - 1] / nums[i]));
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

    vector<int> x = productExceptSelf(nums);
    print(x);
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
