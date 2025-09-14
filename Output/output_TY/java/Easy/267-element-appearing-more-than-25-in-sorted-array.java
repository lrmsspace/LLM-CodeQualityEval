/**https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ */
//Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
// 
//Example 1:
//Input: arr = [1,2,2,6,6,6,6,7,10]
//Output: 6
//Example 2:
//Input: arr = [1,1]
//Output: 1
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 105
class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        int count = 1;
        int maxCount = 0;
        int maxElement = 0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            if(count>maxCount){
                maxCount = count;
                maxElement = arr[i];
            }
        }
        return maxElement;
    }
}