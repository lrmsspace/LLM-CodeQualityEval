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
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> fac(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = (int)((long long)fac[i - 1] * i % mod);
        }
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        int ans = 1;
        for (auto& word : words) {
            int m = word.size();
            unordered_map<char, int> cnt;
            for (auto& c : word) {
                cnt[c]++;
            }
            int total = fac[m];
            for (auto& [k, v] : cnt) {
                total = (int)((long long)total * fac[v] % mod);
            }
            ans = (int)((long long)ans * total % mod);
        }
        return ans;       
    }
};