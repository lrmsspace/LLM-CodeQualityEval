/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//Given n and k, return the kth permutation sequence.
// 
//Example 1:
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//Input: n = 4, k = 9
//Output: "2314"
//Example 3:
//Input: n = 3, k = 1
//Output: "123"
// 
//Constraints:
//	1 <= n <= 9
//	1 <= k <= n!
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums(n);
        vector<int> factorial(n, 1);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
            if (i > 0) {
                factorial[i] = factorial[i - 1] * i;
            }
        }
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int j = k / factorial[i];
            k %= factorial[i];
            res.push_back(nums[j] + '0');
            nums.erase(nums.begin() + j);
        }
        return res;        
    }
};