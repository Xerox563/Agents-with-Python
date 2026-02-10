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
// Main function here : Minimum length Subarray !!
// ---------------------------
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();

    vector<int> pref(n);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + nums[i];

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        if (pref[i] >= target)
        {
            int need = pref[i] - target;

            // binary search ONLY in [0..i]
            int j = upper_bound(pref.begin(), pref.begin() + i, need) - pref.begin() - 1;

            if (j >= 0)
            {
                // subarray (j+1) ... i
                ans = min(ans, i - j);
            }
            else
            {
                // subarray from start (0 ... i)
                ans = min(ans, i + 1);
            }
        }
    }

    return (ans == INT_MAX ? 0 : ans);
}

// Driver
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    read(nums);

    int x = minSubArrayLen(k, nums);
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
