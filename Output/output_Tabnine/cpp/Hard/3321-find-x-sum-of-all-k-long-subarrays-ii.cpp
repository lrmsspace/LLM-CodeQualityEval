/*
 You are given an array nums of n integers and two integers k and x.
 The x-sum of an array is calculated by the following procedure:
 Count the occurrences of all elements in the array.
 Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 Calculate the sum of the resulting array.
 Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 Example 1:
 Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 Output: [6,10,12]
 Explanation:
 For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 Example 2:
 Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 Output: [11,15,15,15,12]
 Explanation:
 Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 Constraints:
 nums.length == n
 1 <= n <= 105
 1 <= nums[i] <= 109
 1 <= x <= k <= nums.length
*/

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // Step 1: Count the occurrences of each element in the array
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Sort the elements in descending order based on their counts and values
        vector<pair<int, int>> sortedCount(count.begin(), count.end());
        sort(sortedCount.begin(), sortedCount.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        
        // Step 3: Keep only the top x most frequent elements
        vector<int> topX;
        for (int i = 0; i < min(x, (int)sortedCount.size()); i++) {
            topX.push_back(sortedCount[i].first);
        }
        
        // Step 4: Calculate the x-sum for each subarray
        vector<long long> answer(nums.size() - k + 1);
        for (int i = 0; i <= nums.size() - k; i++) {
            long long sum = 0;
            for (int j = i; j < i + k; j++) {
                if (find(topX.begin(), topX.end(), nums[j])!= topX.end()) {
                    sum += nums[j];
                }
            }
            answer[i] = sum;
        }
        
        return answer;  
        
    }
};