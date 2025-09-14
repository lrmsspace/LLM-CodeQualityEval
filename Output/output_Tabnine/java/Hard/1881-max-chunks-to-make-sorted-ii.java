/**https://leetcode.com/problems/max-chunks-to-make-sorted-ii/ */
//You are given an integer array arr.
//We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
//Return the largest number of chunks we can make to sort the array.
// 
//Example 1:
//Input: arr = [5,4,3,2,1]
//Output: 1
//Explanation:
//Splitting into two or more chunks will not return the required result.
//For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
//Example 2:
//Input: arr = [2,1,3,4,4]
//Output: 4
//Explanation:
//We can split into two chunks, such as [2, 1], [3, 4, 4].
//However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
// 
//Constraints:
//	1 <= arr.length <= 2000
//	0 <= arr[i] <= 108
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int[] leftMax = new int[arr.length];
        int[] rightMin = new int[arr.length];
        
        leftMax[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], arr[i]);
        }
        
        rightMin[arr.length - 1] = arr[arr.length - 1];
        for (int i = arr.length - 2; i >= 0; i--) {
            rightMin[i] = Math.min(rightMin[i + 1], arr[i]);
        }
        
        int chunks = 0;
        for (int i = 0; i < arr.length; i++) {
            if (leftMax[i] <= rightMin[i]) {
                chunks++;
            }
        }
        
        return chunks;
        
    }
}