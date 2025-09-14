/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.  
int findTheLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int mask = 0;
    int firstOccurrence[32];
    memset(firstOccurrence, -1, sizeof(firstOccurrence));
    firstOccurrence[0] = 0;

    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'a': mask ^= (1 << 0); break;
            case 'e': mask ^= (1 << 1); break;
            case 'i': mask ^= (1 << 2); break;
            case 'o': mask ^= (1 << 3); break;
            case 'u': mask ^= (1 << 4); break;
        }
        if (firstOccurrence[mask] != -1) {
            maxLength = fmax(maxLength, i + 1 - firstOccurrence[mask]);
        } else {
            firstOccurrence[mask] = i + 1;
        }
    }
    
    return maxLength;
}
