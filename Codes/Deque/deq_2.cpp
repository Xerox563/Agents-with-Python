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
// Main function here : Count Subarrays wiht cost <= k !!
// ---------------------------
void deque_fun(vector<int> &nums)
{
    deque<int> max_dq, min_dq;

    for (int i = 0; i < nums.size(); i++)
    {
        // maintaining max deque : maximum element at the start[front]
        while (!max_dq.empty() && max_dq.back() <= nums[i])
        {
            max_dq.pop_back();
        }
        max_dq.push_back(i);

        // maintaining min deque : minimum element at the start[front]
        while (!min_dq.empty() && min_dq.back() >= nums[i])
        {
            min_dq.pop_back();
        }
        min_dq.push_back(i);

        // Shrink window if needed
        while (condition_not_valid)
        {
            if (max_dq.front() == i)
                max_dq.pop_front();
            if (min_dq.front() == i)
                min_dq.pop_front();
        }
    }
}
// Driver
void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    read(nums);

    deque_fun(nums);
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
