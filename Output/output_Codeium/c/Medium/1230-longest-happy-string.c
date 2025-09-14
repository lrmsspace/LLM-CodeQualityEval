/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
char* longestDiverseString(int a, int b, int c) {
    
    int max[3] = {a, b, c}, idx = 0;
    char *res = (char *)malloc((a + b + c + 1) * sizeof(char));
    for (int i = 0; i < a + b + c; i++) {
        int prev = idx ? max[idx - 1] : 0;
        if (max[idx] > 0 && max[idx] >= prev) {
            res[i] = idx == 0 ? 'a' : idx == 1 ? 'b' : 'c';
            max[idx]--;
        } else {
            idx = (idx + 1) % 3;
            res[i] = idx == 0 ? 'a' : idx == 1 ? 'b' : 'c';
            max[idx]--;
        }
    }
    res[a + b + c] = '\0';
    return res;
}
