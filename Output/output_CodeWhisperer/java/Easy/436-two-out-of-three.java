/**https://leetcode.com/problems/two-out-of-three/ */
//Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
// 
//Example 1:
//Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
//Output: [3,2]
//Explanation: The values that are present in at least two arrays are:
//- 3, in all three arrays.
//- 2, in nums1 and nums2.
//Example 2:
//Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
//Output: [2,3,1]
//Explanation: The values that are present in at least two arrays are:
//- 2, in nums2 and nums3.
//- 3, in nums1 and nums2.
//- 1, in nums1 and nums3.
//Example 3:
//Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
//Output: []
//Explanation: No value is present in at least two arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length, nums3.length <= 100
//	1 <= nums1[i], nums2[j], nums3[k] <= 100
import java.util.Set;
import java.util.HashSet;
import java.util.ArrayList;
class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        List<Integer> res = new ArrayList<>();
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        Set<Integer> set3 = new HashSet<>();
        for(int i=0;i<nums1.length;i++){
            set1.add(nums1[i]);
        }
        for(int i=0;i<nums2.length;i++){
            set2.add(nums2[i]);
        }
        for(int i=0;i<nums3.length;i++){
            set3.add(nums3[i]);
        }
        for(int i=0;i<nums1.length;i++){
            if(set2.contains(nums1[i]) || set3.contains(nums1[i])){
                if(!res.contains(nums1[i])){
                    res.add(nums1[i]);
                }
            }
        }
        for(int i=0;i<nums2.length;i++){
            if(set1.contains(nums2[i]) || set3.contains(nums2[i])){
                if(!res.contains(nums2[i])){
                    res.add(nums2[i]);
                }
            }
        }
        for(int i=0;i<nums3.length;i++){
            if(set1.contains(nums3[i]) || set2.contains(nums3[i])){
                if(!res.contains(nums3[i])){
                    res.add(nums3[i]);
                }
            }
        }
        return res;      
    }
}