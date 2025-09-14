/*
 You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
 Return the minimum possible value of nums[n - 1].
 Example 1:
 Input: n = 3, x = 4
 Output: 6
 Explanation:
 nums can be [4,5,6] and its last element is 6.
 Example 2:
 Input: n = 2, x = 7
 Output: 15
 Explanation:
 nums can be [7,15] and its last element is 15.
 Constraints:
 1 <= n, x <= 108
*/

class Solution {
    public long minEnd(int n, int x) {
        int[] bits = new int[32];
        int index = 31;
        while(x > 0) {
            bits[index] = x%2;
            x = x/2;
            index--;
        }
        
        n--;
        int[] bits2 = new int[32];
        index = 31;
        while(n > 0) {
            bits2[index] = n%2;
            n = n/2;
            index--;
        }
        
        index = 31;
        while(index >= 0) {
            if(bits[index] == 0) {
                bits[index] = bits2[index];
            }
            index--;
        }
        
        long result = 0;
        long base = 1;
        for(int i = 31; i >= 0; i--) {
            result += bits[i]*base;
            base *= 2;
        }
        
        return result;
                
    }
}