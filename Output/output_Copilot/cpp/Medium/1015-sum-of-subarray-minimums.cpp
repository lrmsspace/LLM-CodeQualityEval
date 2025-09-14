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
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            left[i] = i + 1;
            right[i] = n - i;
        }
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            res = (res + arr[i] * left[i] * right[i]) % mod;
        }
        return res;        
    }
};