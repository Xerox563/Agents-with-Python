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
// Main function here :  Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// ---------------------------
int longestSubarray(vector<int> &nums, int limit)
{
    // In this we will maintain the min and max deque
    int n = nums.size();
    deque<int> min_dq, max_dq;
    int s = 0;
    int ans = 0;
    for (int e = 0; e < n; e++)
    {

        // Mainting the min deque for getting min in O(1)
        while (!min_dq.empty() && nums[min_dq.back()] >= nums[e])
        {
            min_dq.pop_back();
        }
        min_dq.push_back(e);

        // Mainting the max deque for getting max in O(1)
        while (!max_dq.empty() && nums[max_dq.back()] <= nums[e])
        {
            max_dq.pop_back();
        }
        max_dq.push_back(e);

        while (abs(nums[max_dq.front()] - nums[min_dq.front()]) > limit)
        {
            // shrink the window
            if (min_dq.front() == s)
                min_dq.pop_front();
            if (max_dq.front() == s)
                max_dq.pop_front();
            s++;
        }

        ans = max(ans, e - s + 1);
    }
    return ans;
}

// Driver
void solve()
{
    int n, limit;
    cin >> n >> limit;

    vector<int> nums(n);
    read(nums);

    int ans = longestSubarray(nums, limit);
    cout << ans << endl;
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
