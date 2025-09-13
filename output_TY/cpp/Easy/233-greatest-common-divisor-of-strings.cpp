/**https://leetcode.com/problems/greatest-common-divisor-of-strings/ */
//For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// 
//Example 1:
//Input: str1 = "ABCABC", str2 = "ABC"
//Output: "ABC"
//Example 2:
//Input: str1 = "ABABAB", str2 = "ABAB"
//Output: "AB"
//Example 3:
//Input: str1 = "LEET", str2 = "CODE"
//Output: ""
// 
//Constraints:
//	1 <= str1.length, str2.length <= 1000
//	str1 and str2 consist of English uppercase letters.
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size())
        {
            swap(str1, str2);
        }
        if(str1.size() == str2.size())
        {
            if(str1 == str2)
            {
                return str1;
            }
            else
            {
                return "";
            }
        }
        else
        {
            if(str1.substr(0, str2.size()) == str2)
            {
                return gcdOfStrings(str1.substr(str2.size()), str2);
            }
        }
        return "";
    }
};