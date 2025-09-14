/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> newDp(m + 1, INT_MAX);
            for (int j = 0; j <= m; j++) {
                if (i == 1 || arr1[i - 2] < arr1[i - 1]) {
                    if (j == 0 || arr1[i - 1] > arr2[j - 1]) {
                        newDp[j] = min(newDp[j], dp[j]);
                    }
                }
                if (j == 0 || (i > 1 && arr1[i - 2] < arr2[j - 1])) {
                    int k = upper_bound(arr2.begin(), arr2.end(), arr1[i - 1]) - arr2.begin();
                    newDp[k] = min(newDp[k], dp[j] + 1);
                }
            }
            dp = newDp;
        }
        int ans = INT_MAX;
        for (int i = 0; i <= m; i++) {
            ans = min(ans, dp[i]);
        }
        return ans == INT_MAX ? -1 : ans;      
    }
};