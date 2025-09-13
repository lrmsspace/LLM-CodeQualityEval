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
char * longestDiverseString(int a, int b, int c){
    int freq[3] = {a, b, c};
    int maxFreq = 0;
    for (int i = 1; i < 3; i++) {
        if (freq[i] > freq[maxFreq]) {
            maxFreq = i;
        }
    }
    char *res = malloc(sizeof(char) * (a + b + c + 1));
    int resLen = 0;
    while (freq[maxFreq] > 0) {
        int maxFreqCount = freq[maxFreq] - 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < maxFreqCount; j++) {
                res[resLen++] = 'a' + maxFreq;
            }
            if (freq[maxFreq] <= 1) {
                break;
            }
        }
    }
    res[resLen] = '\0';
    return res;
}