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
// Main function here : Number of Sub-arrays With Odd Sum
// ---------------------------
const int MOD = 1e9 + 7;
int numOfSubarrays(vector<int> &arr)
{
    int n = arr.size();
    int evens = 0, odds = 0;
    long long ans = 0;
    // unordered_map<int,int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // check
        if (sum % 2 == 1)
        {
            ans++;
            ans += evens;
            odds++;
        }
        else
        {
            ans += odds;
            evens++;
        }
        // Trvaerse map
        // for(auto &x : mp) {
        //     if(abs(sum - x.first) % 2 == 1) ans++;
        // }
        // mp[sum]++;
    }
    return ans % MOD;
}

// Driver
void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    read(nums);

    int x = numOfSubarrays(nums);
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
