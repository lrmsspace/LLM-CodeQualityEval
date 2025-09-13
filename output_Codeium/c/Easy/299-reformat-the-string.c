/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500    
//	s consists of only lowercase English letters and/or digits
int find_first(int *arr) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] > 0) return i;
    }
    return -1;
}

char* reformat(char* s) {
    int letters[26] = {0};
    int digits[10] = {0};
    int l = 0, d = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            letters[s[i] - 'a']++;
            l++;
        } else {
            digits[s[i] - '0']++;
            d++;
        }
    }
    if (abs(l - d) > 1) return "";
    int i = 0, j = 0;
    char *res = malloc((l + d + 1) * sizeof(char));
    while (i < l || j < d) {
        if (i < l && j < d && l > d) {
            res[i + j] = 'a' + find_first(letters);
            i++;
        } else if (i < l && j < d && l < d) {
            res[i + j] = '0' + find_first(digits);
            j++;
        } else if (i < l) {
            res[i + j] = 'a' + find_first(letters);
            i++;
        } else {
            res[i + j] = '0' + find_first(digits);
            j++;
        }
    }
    res[i + j] = 0;
    return res;
}

