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
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        k--;
        string res;
        while (n > 0) {
            n--;
            int idx = k / factorial(n);
            k %= factorial(n);
            res += (char)(v[idx] + '0');
            v.erase(v.begin() + idx);
        }
        return res;
    }
    int factorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) res *= i;
        return res;
    }
        
};