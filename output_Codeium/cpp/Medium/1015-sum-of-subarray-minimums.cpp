/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [3,1,2,4]
//Output: 17
//Explanation: 
//Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
//Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
//Sum is 17.
//Example 2:
//Input: arr = [11,81,94,43,3]
//Output: 444
// 
//Constraints:
//	1 <= arr.length <= 3 * 104
//	1 <= arr[i] <= 3 * 104
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0, MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            right[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            left[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            int l = i - left[i], r = right[i] - i;
            res = (res + arr[i] * (l + 1) * (r + 1)) % MOD;
        }
        return res;
    }
};