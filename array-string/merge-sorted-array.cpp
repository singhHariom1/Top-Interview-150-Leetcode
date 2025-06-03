// 🟠 Approach 1: Extra Array (Brute Force)
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArray;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            mergedArray.push_back(nums2[j]);
            j++;
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = mergedArray[i];
        }
    }
};


// 🟢 Approach 2: Optimal In-Place (Two Pointers from End)
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] <= nums2[p2]) {
                nums1[p--] = nums2[p2--];
            } else {
                nums1[p--] = nums1[p1--];
            }
        }

        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};