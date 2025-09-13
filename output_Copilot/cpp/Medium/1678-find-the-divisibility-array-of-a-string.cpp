/**https://leetcode.com/problems/find-the-divisibility-array-of-a-string/ */
//You are given a 0-indexed string word of length n consisting of digits, and a positive integer m.
//The divisibility array div of word is an integer array of length n such that:
//	div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
//	div[i] = 0 otherwise.
//Return the divisibility array of word.
// 
//Example 1:
//Input: word = "998244353", m = 3
//Output: [1,1,0,0,0,1,1,0,0]
//Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".
//Example 2:
//Input: word = "1010", m = 10
//Output: [0,1,0,1]
//Explanation: There are only 2 prefixes that are divisible by 10: "10", and "1010".
// 
//Constraints:
//	1 <= n <= 105
//	word.length == n
//	word consists of digits from 0 to 9
//	1 <= m <= 109
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n, 0);
        int mod = 0;
        int power = 1;
        for (int i = 0; i < n; i++) {
            mod = (mod * 10 + word[i] - '0') % m;
            if (mod == 0) {
                ans[i] = 1;
            }
            power = (power * 10) % m;
        }
        mod = 0;
        for (int i = n - 1; i > 0; i--) {
            mod = (mod + (word[i] - '0') * power) % m;
            if (mod == 0) {
                ans[i - 1] = 1;
            }
            power = (power * 10) % m;
        }
        return ans;        
    }
};