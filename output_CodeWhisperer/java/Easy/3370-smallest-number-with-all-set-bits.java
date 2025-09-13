/*
 You are given a positive number n.
 Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
 Example 1:
 Input: n = 5
 Output: 7
 Explanation:
 The binary representation of 7 is "111".
 Example 2:
 Input: n = 10
 Output: 15
 Explanation:
 The binary representation of 15 is "1111".
 Example 3:
 Input: n = 3
 Output: 3
 Explanation:
 The binary representation of 3 is "11".
 Constraints:
 1 <= n <= 1000
*/

class Solution {
    public int smallestNumber(int n) {
        int count = 0;
        int temp = n;
        while(temp > 0){
            if((temp & 1) == 1){
                count++;
            }
            temp = temp >> 1;
        }
        if(count == 1){
            return n;
        }
        int ans = 0;
        for(int i = 0; i < count - 1; i++){
            ans += Math.pow(2, i);
        }
        return ans + (int)Math.pow(2, count - 1);            
    }
}