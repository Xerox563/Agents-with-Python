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
// Main function here : Contigious Subarray !!
// ---------------------------
bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int r = sum % k;

        if (mp.count(r))
        {
            if (i - mp[r] > 1)
                return true;
        }
        else
        {
            mp[r] = i;
        }
    }

    return false;
}

// Binary Subarray with sum
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (mp.count(sum - goal))
        {
            ans += mp[sum - goal];
            mp[sum]++;
        }
        else
        {
            mp[sum]++;
        }
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

    bool x = checkSubarraySum(nums, k);
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
