#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Try all possible subarrays and track the max sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class BruteForceSolution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

// 🟢 Approach 2: Kadane's Algorithm (Max Sum only)
// Track running sum and reset if it drops below 0
// Time Complexity: O(n)
// Space Complexity: O(1)

class KadaneSumOnly
{
public:
    class Solution
    {
    public:
        int maxSubArray(vector<int> &nums)
        {
            int ans = INT_MIN;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                ans = max(ans, sum);
                if (sum < 0)
                    sum = 0;
            }
            return ans;
        }
    };
};

// 🟢 Approach 3: Kadane's Algorithm with Subarray Tracking
// Track start and end index of max sum subarray
// Time Complexity: O(n)
// Space Complexity: O(1)

class KadaneWithSubarray
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int sum = 0;
        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum == 0)
                start = i;

            sum += nums[i];

            if (sum > ans)
            {
                ans = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0)
                sum = 0;
        }

        // 🔍 Print subarray
        cout << "Subarray with max sum: ";
        for (int i = ansStart; i <= ansEnd; i++)
            cout << nums[i] << " ";
        cout << endl;

        return ans;
    }
};

// 🔵 Approach 4: Divide and Conquer
// Divide array into two halves and combine results
// Time Complexity: O(n log n)
// Space Complexity: O(log n) (recursion stack)

class DivideAndConquer
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return divide(nums, 0, nums.size() - 1);
    }

private:
    int divide(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        int mid = (left + right) / 2;
        int leftMax = divide(nums, left, mid);
        int rightMax = divide(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);

        return max({leftMax, rightMax, crossMax});
    }

    int maxCrossingSum(vector<int> &nums, int left, int mid, int right)
    {
        int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;

        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }
};
