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
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++){
            m[nums2[i]] = m[nums2[i]] == 0 ? 2 : 3;
        }
        for(int i = 0; i < nums3.size(); i++){
            if(m.find(nums3[i]) != m.end()){
                m[nums3[i]] = 3;
            }
        }
        vector<int> ans;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second >= 2){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};