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
        long long ans = 1;
        int mod = 1e9 + 7;
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        unordered_map<string, int> mp;
        string word = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                mp[word]++;
                word = "";
            } else {
                word += s[i];
            }
        }
        mp[word]++;
        for (auto [key, value] : mp) {
            ans = (ans * fact[value]) % mod;
        }
        return ans;        
    }
};