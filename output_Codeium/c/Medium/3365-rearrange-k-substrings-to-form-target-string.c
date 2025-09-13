/*
 You are given two strings s and t, both of which are anagrams of each other, and an integer k.
 Your task is to determine whether it is possible to split the string s into k equal-sized substrings, rearrange the substrings, and concatenate them in any order to create a new string that matches the given string t.
 Return true if this is possible, otherwise, return false.
 An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "abcd", t = "cdab", k = 2
 Output: true
 Explanation:
 Split s into 2 substrings of length 2: ["ab", "cd"].
 Rearranging these substrings as ["cd", "ab"], and then concatenating them results in "cdab", which matches t.
 Example 2:
 Input: s = "aabbcc", t = "bbaacc", k = 3
 Output: true
 Explanation:
 Split s into 3 substrings of length 2: ["aa", "bb", "cc"].
 Rearranging these substrings as ["bb", "aa", "cc"], and then concatenating them results in "bbaacc", which matches t.
 Example 3:
 Input: s = "aabbcc", t = "bbaacc", k = 2
 Output: false
 Explanation:
 Split s into 2 substrings of length 3: ["aab", "bcc"].
 These substrings cannot be rearranged to form t = "bbaacc", so the output is false.
 Constraints:
 1 <= s.length == t.length <= 2 * 105
 1 <= k <= s.length
 s.length is divisible by k.
 s and t consist only of lowercase English letters.
 The input is generated such that s and t are anagrams of each other.
*/
bool isPossibleToRearrange(char* s, char* t, int k) {
    int len = strlen(s);
    int substring_len = len / k;
    
    // Check if both s and t are anagrams of each other
    int char_count_s[26] = {0};
    int char_count_t[26] = {0};
    
    for (int i = 0; i < len; i++) {
        char_count_s[s[i] - 'a']++;
        char_count_t[t[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (char_count_s[i] != char_count_t[i]) {
            return false;
        }
    }
    
    // Check if it's possible to rearrange substrings
    // Since s and t are anagrams, we only need to check if we can split and rearrange
    // the k substrings to form t
    for (int i = 0; i < substring_len; i++) {
        int temp_count[26] = {0};
        
        for (int j = 0; j < k; j++) {
            temp_count[s[i + j * substring_len] - 'a']++;
            temp_count[t[i + j * substring_len] - 'a']--;
        }
        
        for (int j = 0; j < 26; j++) {
            if (temp_count[j] != 0) {
                return false;
            }
        }
    }
    
    return true;
}

