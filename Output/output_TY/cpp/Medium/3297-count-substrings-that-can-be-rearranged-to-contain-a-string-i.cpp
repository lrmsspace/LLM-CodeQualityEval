/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        
        int n = word1.size(), m = word2.size();
        
        vector<int> pos1(26, -1), pos2(26, -1);
        
        for(int i = 0; i < n; i++)
            pos1[word1[i] - 'a'] = i;
        
        for(int i = 0; i < m; i++)
            pos2[word2[i] - 'a'] = i;
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            int j = pos2[word1[i] - 'a'];
            if(j != -1){
                ans += (j >= i);
                pos2[word1[i] - 'a'] = -1;
            }
            else{
                int j = pos1[word2[i] - 'a'];
                ans += (j >= i);
            }
            pos1[word1[i] - 'a'] = -1;

        }
        return ans;
    }
};