/**https://leetcode.com/problems/additive-number/ */
//An additive number is a string whose digits can form an additive sequence.
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//Given a string containing only digits, return true if it is an additive number or false otherwise.
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
// 
//Example 1:
//Input: "112358"
//Output: true
//Explanation: 
//The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//Example 2:
//Input: "199100199"
//Output: true
//Explanation: 
//The additive sequence is: 1, 99, 100, 199. 
//1 + 99 = 100, 99 + 100 = 199
// 
//Constraints:
//	1 <= num.length <= 35
//	num consists only of digits.
// 
//Follow up: How would you handle overflow for very large input integers?
class Solution {
    public boolean isAdditiveNumber(String num) {       
        if(num.length()<3) return false;
        return helper(num, 0, 0, 0);
    }
    
    public boolean helper(String num, int i, int j, int k){
        if(i==num.length() && j==num.length() && k==num.length()) return true;
        if(i==num.length() || j==num.length() || k==num.length()) return false;
        
        if(num.charAt(i)=='0') return helper(num, i+1, j, k);
        
        long first = 0;
        for(int a=i; a<num.length(); a++){
            first = first*10 + (num.charAt(a)-'0');
            if(num.charAt(j)=='0'){
                if(first==0) return helper(num, a+1, j+1, k);
                else return false;
            }
}
    }
    public boolean helper(String num, int i, int j, int k){
        if(i==num.length() && j==num.length() && k==num.length()) return true;
        if(i==num.length() || j==num.length() || k==num.length()) return false;
        
        if(num.charAt(i)=='0') return helper(num, i+1, j, k);
        
        long first = 0;
        for(int a=i; a<num.length(); a++){
            first = first*10 + (num.charAt(a)-'0');
            if(num.charAt(j)=='0'){
                if(first==0) return helper(num, a+1, j+1, k);
                else return false;
            }
        }
        long second = 0;
        for(int b=j; b<num.length(); b++){
            second = second*10 + (num.charAt(b)-'0');
        }
        long third = first+second;
        String thirdStr = String.valueOf(third);
        for(int c=b; c<num.length(); c++){
            if(num.charAt(c)!=thirdStr.charAt(c-b)) return false;
        }
        return helper(num, a+1, b+1, c+1);
    }
}