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
    bool isUnique(char* substrings[], int count, char* str) {
        for (int i = 0; i < count; i++) {
            if (strcmp(substrings[i], str) == 0) {
                return false;
            }
        }
        return true;
    }

    int backtrack(char* s, int start, char* substrings[], int count) {
        if (start == strlen(s)) {
            return count;
        }

        int maxCount = 0;
        char temp[17]; // Maximum length of s is 16
        for (int i = start; i < strlen(s); i++) {
            strncpy(temp, s + start, i - start + 1);
            temp[i - start + 1] = '\0';

            if (isUnique(substrings, count, temp)) {
                substrings[count] = strdup(temp);
                maxCount = fmax(maxCount, backtrack(s, i + 1, substrings, count + 1));
                free(substrings[count]);
            }
        }
        return maxCount;
    }

    int maxUniqueSplit(char* s) {
        char* substrings[16]; // Maximum number of substrings is 16
        return backtrack(s, 0, substrings, 0);
    }
