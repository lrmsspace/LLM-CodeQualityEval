/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
// 
//Example 1:
//Input: a = "abcd", b = "cdabcdab"
//Output: 3
//Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
//Example 2:
//Input: a = "a", b = "aa"
//Output: 2
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist of lowercase English letters.
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int count = 0;
        int i = 0;
        int j = 0;
        while(i < m){
            if(a[j] == b[i]){
                i++;
                j++;
            }
            else{
                j = 0;
                i = 0;
                count++;
            }
            if(j == n){
                j = 0;
                i = 0;
                count++;
            }
        }
        if(count == 0){
            return 1;
        }
        else if(count== 1){
            return -1;
        }
        return count;
    }
};