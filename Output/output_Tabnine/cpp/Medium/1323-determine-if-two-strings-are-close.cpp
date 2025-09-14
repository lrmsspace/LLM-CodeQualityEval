/**https://leetcode.com/problems/determine-if-two-strings-are-close/ */
//Two strings are considered close if you can attain one from the other using the following operations:
//	Operation 1: Swap any two existing characters.
//	
//		For example, abcde -> aecdb
//	
//	
//	Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//	
//		For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
//	
//	
//You can use the operations on either string as many times as necessary.
//Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
// 
//Example 1:
//Input: word1 = "abc", word2 = "bca"
//Output: true
//Explanation: You can attain word2 from word1 in 2 operations.
//Apply Operation 1: "abc" -> "acb"
//Apply Operation 1: "acb" -> "bca"
//Example 2:
//Input: word1 = "a", word2 = "aa"
//Output: false
//Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
//Example 3:
//Input: word1 = "cabbba", word2 = "abbccc"
//Output: true
//Explanation: You can attain word2 from word1 in 3 operations.
//Apply Operation 1: "cabbba" -> "caabbb"
//Apply Operation 2: "caabbb" -> "baaccc"
//Apply Operation 2: "baaccc" -> "abbccc"
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 contain only lowercase English letters.
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length()!= word2.length()) return false;
        
        // Count the frequency of each character in both strings
        unordered_map<char, int> freq1, freq2;
        for (char c : word1) freq1[c]++;
        for (char c : word2) freq2[c]++;
        
        // Check if the frequencies are the same
        if (freq1!= freq2) return false;
        
        // Count the number of unique characters in both strings
        unordered_set<char> unique1(word1.begin(), word1.end()), unique2(word2.begin(), word2.end());
        if (unique1.size()!= unique2.size()) return false;
        
        // Count the number of characters that appear an odd number of times
        int oddCount = 0;
        for (auto& [c, freq] : freq1) {
            if (freq % 2!= 0) oddCount++;
            if (oddCount > 2) return false;
        }
        
        // Check if the characters can be swapped to achieve word2 from word1
        for (char c1 : unique1) {
            int freq1 = freq1[c1], freq2 = freq2[c1];
            if (freq1!= freq2) {
                int diff = abs(freq1 - freq2);
                if (diff % 2!= 0) return false;
            }
        }
        
        return true;
    }
};