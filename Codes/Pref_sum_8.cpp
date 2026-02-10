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
// Main function here : Subarray sum divisible by k
// ---------------------------

int subarraysDivByK(vector<int> &nums, int k)
{
    // Brute Force
    // int n = nums.size();
    // int ans = 0;
    // unordered_map<int, int> mp;
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += nums[i];
    //     if (sum % k == 0)
    //         ans++;
    //     for (auto &x : mp)
    //     {
    //         if ((sum - x.first) % k == 0)
    //             ans += x.second;
    //     }
    //     mp[sum]++;
    // }
    // return ans;

    // Optimised
    unordered_map<int, int> mp;
    mp[0] = 1; // Important: prefix sum divisible by k

    int sum = 0, ans = 0;

    for (int num : nums)
    {
        sum += num;

        int rem = sum % k;
        if (rem < 0)
            rem += k; // Fix negative remainder

        if (mp.find(rem) != mp.end())
        {
            ans += mp[rem];
        }

        mp[rem]++;
    }

    return ans;
}

// Driver
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    read(nums);

    int val = subarraysDivByK(nums, k);
    cout << val;
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
