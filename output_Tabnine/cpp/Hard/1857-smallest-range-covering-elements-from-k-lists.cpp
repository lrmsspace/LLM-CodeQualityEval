/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();
        int k = nums[0].size();
        vector<int> minHeap(k, INT_MAX);
        vector<int> maxHeap(k, INT_MIN);
        
        for(int i = 0; i < k; i++) {
            minHeap[i] = nums[0][i];
            maxHeap[i] = nums[0][i];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < k; i++) {
            pq.push({minHeap[i], i});
        }
        
        vector<int> res = {minHeap[0], maxHeap[0]};
        
        while(!pq.empty()) {
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            if(res[1] - res[0] > maxHeap[index] - val) {
                res[0] = val;
                res[1] = maxHeap[index];
            }
            
            if(index + 1 < k && maxHeap[index + 1] < maxHeap[index]) {
                pq.push({maxHeap[index + 1], index + 1});
                maxHeap[index + 1] = maxHeap[index];
            } else {
                pq.push({nums[index + 1][0], index + 1});
                maxHeap[index] = nums[index + 1][0];
            }
        }
        
        return res;
        
    }
};