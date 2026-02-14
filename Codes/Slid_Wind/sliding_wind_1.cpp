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
// Main function here : Count Subarrays wiht cost <= k !!
// ---------------------------
long long countSubarrays(vector<int> &nums, long long k)
{
    int n = nums.size();
    long long ans = 0;

    // Max heap
    priority_queue<pair<int, int>> pq_max;

    // Min heap
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq_min;

    int s = 0;

    for (int e = 0; e < n; e++)
    {

        pq_max.push({nums[e], e});
        pq_min.push({nums[e], e});

        while (true)
        {

            // Lazy remove elements outside window
            while (!pq_max.empty() && pq_max.top().second < s)
                pq_max.pop();

            while (!pq_min.empty() && pq_min.top().second < s)
                pq_min.pop();

            long long maxi = pq_max.top().first;
            long long mini = pq_min.top().first;

            long long len = e - s + 1;
            long long cost = (maxi - mini) * len;

            if (cost <= k)
                break;

            s++;
        }

        // Count all valid subarrays ending at e
        ans += (e - s + 1);
    }

    return ans;
}

// ---------------------------
// Main function here : Merge Adjacent Equal Elements
// ---------------------------
vector<long long> mergeAdjacent(vector<int> &nums)
{
    int n = nums.size();
    vector<long long> ans;
    stack<long long> st;
    for (int i = 0; i < n; i++)
    {
        long long curr = nums[i];
        while (!st.empty() && st.top() == curr)
        {
            long long ele = st.top();
            curr += ele;
            st.pop();
        }
        st.push(curr);
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// Driver
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    read(nums);

    long long x = countSubarrays(nums, k);
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
