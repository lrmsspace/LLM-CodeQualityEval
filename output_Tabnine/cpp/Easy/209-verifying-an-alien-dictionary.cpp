/**https://leetcode.com/problems/verifying-an-alien-dictionary/ */
//In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
//Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
// 
//Example 1:
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
//Example 2:
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
//Example 3:
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 20
//	order.length == 26
//	All characters in words[i] and order are English lowercase letters.
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> map(26, -1);
        for (int i = 0; i < 26; ++i)
            map[order[i] - 'a'] = i;
        
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i].size() > words[i + 1].size())
                return false;
            
            for (int j = 0; j < words[i].size(); ++j) {
                if (words[i][j]!= words[i + 1][j]) {
                    if (map[words[i][j] - 'a'] > map[words[i + 1][j] - 'a'])
                        return false;
                    break;
                }
            }
        }
        
        return true;
        
    }
};