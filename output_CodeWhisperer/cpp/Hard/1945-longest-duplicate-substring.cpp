/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = s[i] - 'a';
        }
        int base = 26;
        int mod = 1e9 + 7;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hash = 0;
            for (int i = 0; i < mid; i++) {
                hash = (hash * base + nums[i]) % mod;
            }
            set<int> seen;
            seen.insert(hash);
            int base_pow = 1;
            for (int i = 0; i < mid; i++) {
                base_pow = (base_pow * base) % mod;
            }
            for (int i = mid; i < n; i++) {
                hash = (hash * base - nums[i - mid] * base_pow % mod + mod) % mod;
                hash = (hash + nums[i]) % mod;
                if (seen.count(hash)) {
                    return s.substr(i - mid + 1, mid);
                }
                seen.insert(hash);
            }
            right = mid;
        }
        return "";     
    }
};