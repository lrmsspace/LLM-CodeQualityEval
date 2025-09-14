/**https://leetcode.com/problems/maximum-or/ */
//You are given a 0-indexed integer array nums of length n and an integer k. In an operation, you can choose an element and multiply it by 2.
//Return the maximum possible value of nums[0] | nums[1] | ... | nums[n - 1] that can be obtained after applying the operation on nums at most k times.
//Note that a | b denotes the bitwise or between two integers a and b.
// 
//Example 1:
//Input: nums = [12,9], k = 1
//Output: 30
//Explanation: If we apply the operation to index 1, our new array nums will be equal to [12,18]. Thus, we return the bitwise or of 12 and 18, which is 30.
//Example 2:
//Input: nums = [8,1,2], k = 2
//Output: 35
//Explanation: If we apply the operation twice on index 0, we yield a new array of [32,1,2]. Thus, we return 32|1|2 = 35.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
//	1 <= k <= 15
class Solution {
    public long maximumOr(int[] nums, int k) {
        int n=nums.length;
        int[] left=new int[n];
        int[] right=new int[n];
        int[] left_bit=new int[n];
        int[] right_bit=new int[n];
        int[] left_bit_count=new int[n];
        int[] right_bit_count=new int[n];
        int[] left_bit_count_k=new int[n];
        int[] right_bit_count_k=new int[n];
        int[] left_bit_count_k_1=new int[n];
        int[] right_bit_count_k_1=new int[n];
        int[] left_bit_count_k_2=new int[n];
        int[] right_bit_count_k_2=new int[n];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        left_bit[0]=Integer.bitCount(nums[0]);
        right_bit[n-1]=Integer.bitCount(nums[n-1]);
        
        for(int i=1;i<n;i++){
            left[i]=left[i-1]|nums[i];
            right[n-i-1]=right[n-i]|nums[n-i-1];
            left_bit[i]=left_bit[i-1]+Integer.bitCount(nums[i]);
            right_bit[n-i-1]=right_bit[n-i]+Integer.bitCount(nums[n-i-1]);
        }
        left_bit_count[0]=left_bit[0];
        right_bit_count[n-1]=right_bit[n-1];
        for(int i=1;i<n;i++){
            left_bit_count[i]=left_bit_count[i-1]+left_bit[i];
            right_bit_count[n-i-1]=right_bit_count[n-i]+right_bit[n-i-1];
        }
        left_bit_count_k[0]=left_bit_count[0];
        right_bit_count_k[n-1]=right_bit_count[n-1];
        for(int i=1;i<n;i++){
            left_bit_count_k[i]=left_bit_count_k[i-1]+left_bit_count[i];
            right_bit_count_k[n-i-1]=right_bit_count_k[n-i]+right_bit_count[n-i-1];
        }

        for(int i=0;i<n;i++){
            if(k>=left_bit[i]){
                left_bit_count_k_1[i]=left_bit_count_k[i];
            }
            else{
                left_bit_count_k_1[i]=left_bit_count_k[i-1];
            }
            if(k>=right_bit[n-i-1]){
                right_bit_count_k_1[n-i-1]=right_bit_count_k[n-i-1];
            }
            else{
                right_bit_count_k_1[n-i-1]=right_bit_count_k[n-i];   
            }
        }
        for(int i=0;i<n;i++){
            if(k>=left_bit_count[i]){
                left_bit_count_k_2[i]=left_bit_count_k[i];
            }
            else{
                left_bit_count_k_2[i]=left_bit_count_k[i-1];
            }
            if(k>=right_bit_count[n-i-1]){
                right_bit_count_k_2[n-i-1]=right_bit_count_k[n-i-1];
            }
            else{
                right_bit_count_k_2[n-i-1]=right_bit_count_k[n-i];  
            }
        }
        long res=0;
        for(int i=0;i<n;i++){
            res=Math.max(res,left[i]|right[i]);
            res=Math.max(res,left[i]|right[i-1]);
            res=Math.max(
                res,left[i]|right[i-1]|(left_bit_count_k_1[i]-left_bit_count_k_2[i])
            )   ;
        }
        return res;
    }
}