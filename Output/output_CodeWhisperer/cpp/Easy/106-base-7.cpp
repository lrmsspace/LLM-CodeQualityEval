/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.
// 
//Example 1:
//Input: num = 100
//Output: "202"
//Example 2:
//Input: num = -7
//Output: "-10"
// 
//Constraints:
//	-107 <= num <= 107
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool isNegative = num < 0;
        num = abs(num);
        string result = "";
        while(num > 0){
            result = to_string(num % 7) + result;
            num /= 7;
        }
        if(isNegative){
            result = "-" + result;
        }
        return result;    
    }
};