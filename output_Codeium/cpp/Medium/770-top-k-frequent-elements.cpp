/**https://leetcode.com/problems/top-k-frequent-elements/ */
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	k is in the range [1, the number of unique elements in the array].
//	It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (const int& num : nums) {
            frequency[num]++;
        }
        
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        
        for (const auto& [num, count] : frequency) {
            heap.emplace(num, count);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().first);
            heap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;

        }
};