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
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = i * factorial[i - 1];
        }
        
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string result;
        
        --k;
        for (int i = n; i > 0; --i) {
            int j = k / factorial[i - 1];
            result += to_string(nums[j]);
            nums.erase(nums.begin() + j);
            k %= factorial[i - 1];
        }
        
        return result;
        
    }
};