/**https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/ */
//Given a string s, return the maximum number of unique substrings that the given string can be split into.
//You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "ababccc"
//Output: 5
//Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: One way to split maximally is ['a', 'ba'].
//Example 3:
//Input: s = "aa"
//Output: 1
//Explanation: It is impossible to split the string any further.
// 
//Constraints:
//	
//	1 <= s.length <= 16
//	
//	
//	s contains only lower case English letters.
//	
int maxUniqueSplit(char* s) {
    
    int maxCount = 0;
    bool used[16] = {false};
    
    void backtrack(int start, int count) {
        if (start == strlen(s)) {
            if (count > maxCount)
                maxCount = count;
            return;
        }
        
        for (int end = start + 1; end <= strlen(s); end++) {
            int len = end - start;
            bool isUnique = true;
            
            for (int i = 0; i < 16; i++) {
                if (used[i] && strncmp(&s[start], &s[used[i]], len) == 0) {
                    isUnique = false;
                    break;
                }
            }
            
            if (isUnique) {
                used[count] = start;
                backtrack(end, count + 1);
                used[count] = false;
            }
        }
    }
    
    backtrack(0, 0);
    return maxCount;
}   