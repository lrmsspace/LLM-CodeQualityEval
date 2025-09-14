/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] cnt = new int[10];
        int sum = 0;
        for(int d: digits){
            cnt[d]++;
            sum += d;
        }
        int a = -1, b = -1;
        for(int i = 0; i < 10; i++){
            if(cnt[i] == 0) continue;
            if(i % 3 == 1){
                if(a == -1 || a > i) a = i;
            }else if(i % 3 == 2){
                if(b == -1 || b > i) b = i;
            }
        }
        int k = sum % 3;
        if(k == 0){
            return digits;
        }else if(k == 1){
            if(a == -1) return new int[]{};
            cnt[a]--;
            cnt[a - 1]++;
            return digits;
        }else{
            if(b == -1) return new int[]{};
            cnt[b]--;
            cnt[b + 1]++;
            return digits;
        }
            
    }
}