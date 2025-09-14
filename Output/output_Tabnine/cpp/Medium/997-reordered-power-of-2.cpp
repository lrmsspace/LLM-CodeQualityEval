/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string numStr = to_string(n);
        sort(numStr.begin(), numStr.end());
        do {
            int m = stoi(numStr);
            if ((m & (m - 1)) == 0) return true;
        } while (next_permutation(numStr.begin(), numStr.end()));
        return false;  // no power of 2 found after trying all permutations of digits of n

        // Alternative solution using bit manipulation (not recommended for large n)
        // int m = 1;
        // while (m < n) {
        //     if ((m & (m - 1)) == 0 && (m & (n - 1)) == 0) return true;
        //     m <<= 1;
        // }
        // return false;  // no power of 2 found after checking all possible powers of 2 less than n
        
    }
};