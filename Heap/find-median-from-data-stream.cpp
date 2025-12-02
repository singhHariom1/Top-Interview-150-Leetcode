#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Sorting (Brute Force)
// Time Complexity: O(n log n) per add/find
// Space Complexity: O(n)

class MedianFinder_BruteForce {
    vector<int> nums;
public:
    MedianFinder_BruteForce() {}
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 1) return nums[n / 2];
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};


// 🟢 Approach 2: Two Heaps (Optimal)
// Time Complexity: O(log n) for addNum, O(1) for findMedian
// Space Complexity: O(n)

class MedianFinder {
    priority_queue<int> maxHeap; // Stores the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores the upper half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        
        // Ensure every element in maxHeap is <= every element in minHeap
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        
        // Balance the sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
