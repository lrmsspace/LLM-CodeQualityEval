/**https://leetcode.com/problems/second-largest-digit-in-a-string/ */
//Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
//An alphanumeric string is a string consisting of lowercase English letters and digits.
// 
//Example 1:
//Input: s = "dfa12321afd"
//Output: 2
//Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
//Example 2:
//Input: s = "abc1111"
//Output: -1
//Explanation: The digits that appear in s are [1]. There is no second largest digit. 
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and digits.
int secondHighest(char* s) {
    int i = 0;
    int max = -1;
    int secondMax = -1;
    while(s[i] != '\0') {
        if(s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            if(num > max) {
                secondMax = max;
                max = num;
            } else if(num > secondMax && num < max) {
                secondMax = num;
            }
        }
        i++;
    }
    return secondMax;    
}