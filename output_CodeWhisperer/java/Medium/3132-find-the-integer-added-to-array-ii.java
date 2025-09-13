/*
 You are given two integer arrays nums1 and nums2.
 From nums1 two elements have been removed, and all other elements have been increased (or decreased in the case of negative) by an integer, represented by the variable x.
 As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.
 Return the minimum possible integer x that achieves this equivalence.
 Example 1:
 Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]
 Output: -2
 Explanation:
 After removing elements at indices [0,4] and adding -2, nums1 becomes [18,14,10].
 Example 2:
 Input: nums1 = [3,5,5,3], nums2 = [7,7]
 Output: 2
 Explanation:
 After removing elements at indices [0,3] and adding 2, nums1 becomes [7,7].
 Constraints:
 3 <= nums1.length <= 200
 nums2.length == nums1.length - 2
 0 <= nums1[i], nums2[i] <= 1000
 The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by removing two elements and adding x to each element of nums1.
*/

class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums1.length; i++) {
            for (int j = i + 1; j < nums1.length; j++) {
                int[] temp = new int[nums1.length - 2];
                int index = 0;
                for (int k = 0; k < nums1.length; k++) {
                    if (k != i && k != j) {
                        temp[index++] = nums1[k];
                    }
                }
                int diff = nums2[0] - temp[0];
                boolean flag = true;
                for (int k = 0; k < temp.length; k++) {
                    if (nums2[k] - temp[k] != diff) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    min = Math.min(min, diff);
                }
            }
        }
        return min;
                
    }
}