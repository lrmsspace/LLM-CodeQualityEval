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
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        do {
            if (digits[0] == 0) continue;
            int num = 0;
            for (int i = 0; i < digits.size(); i++) {
                num = num * 10 + digits[i];
            }
            if ((num & (num - 1)) == 0) return true;
        } while (next_permutation(digits.begin(), digits.end()));
        return false;       
    }
};