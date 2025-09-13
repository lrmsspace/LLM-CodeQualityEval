/**https://leetcode.com/problems/short-encoding-of-words/ */
//A valid encoding of an array of words is any reference string s and array of indices indices such that:
//	words.length == indices.length
//	The reference string s ends with the '#' character.
//	For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
//Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
// 
//Example 1:
//Input: words = ["time", "me", "bell"]
//Output: 10
//Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
//words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
//words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
//words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
//Example 2:
//Input: words = ["t"]
//Output: 2
//Explanation: A valid encoding would be s = "t#" and indices = [0].
// 
//Constraints:
//	1 <= words.length <= 2000
//	1 <= words[i].length <= 7
//	words[i] consists of only lowercase letters.
int minimumLengthEncoding(char ** words, int wordsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000], b[1000], c[1000], d[1000], e[1000], f[1000], g[1000], h[1000];
    int count = 0;
    for (i = 0; i < wordsSize; i++){    
        for (j = 0; j < wordsSize; j++){
            if (i != j){
                for (k = 0; words[i][k] != '\0'; k++){
                    if (words[i][k] != words[j][k]){
                        break;
                    }
                }
                if (words[i][k] == '\0'){
                    break;
                }
           }
        }
    }   
    return i + 1;
}