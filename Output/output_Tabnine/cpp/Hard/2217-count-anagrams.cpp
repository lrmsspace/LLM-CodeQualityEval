/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//	For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "too hot"
//Output: 18
//Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
//Example 2:
//Input: s = "aa"
//Output: 1
//Explanation: There is only one anagram possible for the given string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters and spaces ' '.
//	There is single space between consecutive words.
class Solution {
public:
    int countAnagrams(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int mod = 1e9 + 7;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        long res = 1;
        for (int i = 0; i < 26; i++) {
            res = (res * freq[i]) % mod;
        }
        vector<long> pow_26(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow_26[i] = (pow_26[i - 1] * 26) % mod;
        }
        for (int i = 1; i <= n; i++) {
            int j = n - i;
            res = (res - (pow_26[j] * freq[s[j] - 'a']) % mod + mod) % mod;
        }
        return res;
        
    }
};