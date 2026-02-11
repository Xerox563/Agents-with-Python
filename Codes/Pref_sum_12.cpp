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
// Shifting Letters

char shift(char ch, int k)
{
    return 'a' + ((ch - 'a' + k) % 26);
}
string shiftingLetters(string s, vector<int> &shifts)
{
    vector<int> temp(shifts.size());
    temp[shifts.size() - 1] = (shifts[shifts.size() - 1]) % 26;
    for (int i = shifts.size() - 2; i >= 0; i--)
    {
        temp[i] = (temp[i + 1] + shifts[i]) % 26;
    }
    string ans = "";
    for (int i = 0; i < temp.size(); i++)
    {
        char ch = shift(s[i], temp[i]);
        ans += ch;
    }
    return ans;
}

// Car Pooling Problem
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    //     priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
    //     for(auto &x: trips) {
    //         pq.push({{x[1],x[2]},x[0]});
    //     }
    //     int prev_e = 0;
    //     int prev_cnt_pas = 0;
    //     if(!pq.empty()) {
    //         prev_e = pq.top().first.second;
    //         prev_cnt_pas = pq.top().second;
    //         pq.pop();
    //     }

    //     while(!pq.empty()) {
    //         auto it = pq.top();
    //         pq.pop();
    //         int s = pq.top().first.first;
    //         int e = pq.top().first.second;
    //         int cnt_pas = pq.top().second;

    //         if(e < prev_e && (cnt_pas + prev_cnt_pas < capacity)) {
    //             return false;
    //         }
    //         else {
    //             prev_e = e;
    //             prev_cnt_pas = cnt_pas;
    //         }
    //     }
    //    return true;

    int maxEnd = 0;

    // Finding furthest point
    for (auto &t : trips)
        maxEnd = max(maxEnd, t[2]);

    // Difference array of size maxEnd+1
    vector<int> diff(maxEnd + 1, 0);

    // using differnce array
    for (auto &t : trips)
    {
        int p = t[0];
        int s = t[1];
        int e = t[2];

        diff[s] += p;
        diff[e] -= p;
    }

    // Building prefix sum and checking
    int curr = 0;
    for (int i = 0; i <= maxEnd; i++)
    {
        curr += diff[i];
        if (curr > capacity)
            return false;
    }

    return true;
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
