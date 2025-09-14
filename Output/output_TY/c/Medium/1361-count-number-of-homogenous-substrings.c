/**https://leetcode.com/problems/count-number-of-homogenous-substrings/ */
//Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7._x000D_
//_x000D_
//A string is homogenous if all the characters of the string are the same._x000D_
//_x000D_
//A substring is a contiguous sequence of characters within a string._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: s = "abbcccaa"_x000D_
//Output: 13_x000D_
//Explanation: The homogenous substrings are listed as below:_x000D_
//"a"   appears 3 times._x000D_
//"aa"  appears 1 time._x000D_
//"b"   appears 2 times._x000D_
//"bb"  appears 1 time._x000D_
//"c"   appears 3 times._x000D_
//"cc"  appears 2 times._x000D_
//"ccc" appears 1 time._x000D_
//3 + 1 + 2 + 1 + 3 + 2 + 1 = 13._x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: s = "xy"_x000D_
//Output: 2_x000D_
//Explanation: The homogenous substrings are "x" and "y"._x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: s = "zzzzz"_x000D_
//Output: 15_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= s.length <= 105_x000D_
//	s consists of lowercase letters._x000D_


int countHomogenous(char * s){
    int count = 0;
    int prev = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == s[prev])
            count += (i - prev + 1);
        else
            count += (i - prev);
        prev = i;
    }
    return count % 1000000007;
}