/**https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/ */
//Given a string s, return true if s is a good string, or false otherwise.
//A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
// 
//Example 1:
//Input: s = "abacbc"
//Output: true
//Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
//Example 2:
//Input: s = "aaabb"
//Output: false
//Explanation: The characters that appear in s are 'a' and 'b'.
//'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
bool areOccurrencesEqual(char * s){
    int hash[26] = {0};
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < strlen(s); i++) {
        hash[s[i] - 'a']++;
    }
    int first = hash[s[0] - 'a'];
    for(i = 0; i < 26; i++) {
        if(hash[i] != first) {
            return false;
        }
    }
    return true;
}