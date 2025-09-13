/**https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/ */
//You are given an array of strings words (0-indexed).
//In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].
//Return true if you can make every string in words equal using any number of operations, and false otherwise.
// 
//Example 1:
//Input: words = ["abc","aabc","bc"]
//Output: true
//Explanation: Move the first 'a' in words[1] to the front of words[2],
//to make words[1] = "abc" and words[2] = "abc".
//All the strings are now equal to "abc", so return true.
//Example 2:
//Input: words = ["ab","a"]
//Output: false
//Explanation: It is impossible to make all the strings equal using the operation.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
bool makeEqual(char ** words, int wordsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int count[26] = {0};
    intmax = 0;
    for(i = 0; i < wordsSize; i++){
        for(j = 0; j < strlen(words[i]); j++){
            count[words[i][j] - 'a']++;
        }
    }
    for(i = 0; i < 26; i++){
        if(count[i] % wordsSize != 0){
            return false;
        }
    }
    return true;
}