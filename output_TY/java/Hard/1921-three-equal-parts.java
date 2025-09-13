/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//	arr[0], arr[1], ..., arr[i] is the first part,
//	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//	All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
// 
//Example 1:
//Input: arr = [1,0,1,0,1]
//Output: [0,3]
//Example 2:
//Input: arr = [1,1,0,1,1]
//Output: [-1,-1]
//Example 3:
//Input: arr = [1,1,0,0,1]
//Output: [0,2]
// 
//Constraints:
//	3 <= arr.length <= 3 * 104
//	arr[i] is 0 or 1
class Solution {
    public int[] threeEqualParts(int[] arr) {
        int n = arr.length;
        int[] ones = new int[n];
        int[] zeros = new int[n];
        int[] ones_index = new int[n];
        int[] zeros_index = new int[n];
        int ones_count = 0;
        int zeros_count = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ones[ones_count++] = i;
                ones_index[i] = ones_count-1;
            }
            else{
                zeros[zeros_count++] = i;
                zeros_index[i] = zeros_count-1;
            }
        }  
        int[] parts = new int[3];
        for(int i=0;i<ones_count;i++){
            int j = i;
            int k = i;
            int ones_part_size = ones[i] - ones[i-1];
            int zeros_part_size = zeros[zeros_count-1] - zeros[zeros_count-2];
            int ones_part_end = ones[i] + ones_part_size;
            int zeros_part_end = zeros[zeros_count-1] - zeros_part_size;
            while(j<ones_count && k<zeros_count){
                if(ones[j]<ones_part_end && zeros[k]>zeros_part_end){
                    break;
                }
            }
        }
        return new int[]{-1,-1};
    }
}