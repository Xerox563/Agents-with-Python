#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
// Main function here : maxSlidingWindow !!
// ---------------------------
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq; // stores indices
    vector<int> ans;
    int n = nums.size();

    int s = 0;
    int e = 0;

    // Process first k elements
    while (e < k)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[e])
            dq.pop_back();

        dq.push_back(e);
        e++;
    }

    // First window answer
    ans.push_back(nums[dq.front()]);

    // Slide the window
    while (e < n)
    {

        // Remove element going out of window
        if (dq.front() == s)
            dq.pop_front();

        // Insert new element
        while (!dq.empty() && nums[dq.back()] <= nums[e])
            dq.pop_back();

        dq.push_back(e);

        ans.push_back(nums[dq.front()]);
        e++;
        s++;
    }

    return ans;
}

// ---------------------------
// Main function here : Minimum Window Substring
// ---------------------------
bool all_zeroes(vector<int> &freq1)
{
    for (int i = 0; i < 128; i++)
    {
        if (freq1[i] > 0)
            return false;
    }
    return true;
}

string minWindow(string str, string t)
{

    vector<int> freq1(128, 0);

    for (auto &ch : t)
    {
        freq1[ch]++;
    }

    int prev_len = INT_MAX;
    pair<int, int> ans = {-1, -1};

    int s = 0;
    int e = 0;

    while (e < str.length())
    {

        // include current character
        freq1[str[e]]--;

        // if window is valid
        while (all_zeroes(freq1))
        {

            if (e - s + 1 < prev_len)
            {
                ans = {s, e};
                prev_len = e - s + 1;
            }

            // shrink from left
            freq1[str[s]]++;
            s++;
        }

        e++;
    }

    if (ans.first == -1)
        return "";

    return str.substr(ans.first, prev_len);
}
// Driver
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    read(nums);

    vector<int> ans = maxSlidingWindow(nums, k);
    print(ans);
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

/*
Deque[monotonic queue] : Used when we want to maintain elements in a specific order .
- Increasing order : (for maxiumum)
- Decreasing order : (for minimum)

'''
-- push_front()
-- push_back()
-- pop_front()
-- pop_back()
-- front()
-- back()
'''

When to use this :
- sliding window
- need min/max repeatedly
- elements gets useless after sometime
- window shrinks from left .
*/
