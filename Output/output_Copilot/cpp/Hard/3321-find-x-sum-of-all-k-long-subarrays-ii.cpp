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
        int n = nums.size();
        vector<long long> answer(n - k + 1, 0);
        unordered_map<int, int> freqMap;

        // Calculate the x-sum for the first window
        for (int i = 0; i < k; ++i) {
            freqMap[nums[i]]++;
        }

        // Function to calculate the x-sum from the frequency map
        auto calculateXSum = [&]() {
            vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) return a.first > b.first; // Higher value first if same frequency
                return a.second > b.second; // Higher frequency first
            });
            long long sum = 0;
            for (int i = 0; i < min(x, (int)freqVec.size()); ++i) {
                sum += (long long)freqVec[i].first * freqVec[i].second;
            }
            return sum;
        };

        answer[0] = calculateXSum();

        // Slide the window across the array
        for (int i = 1; i <= n - k; ++i) {
            // Remove the element going out of the window
            freqMap[nums[i - 1]]--;
            if (freqMap[nums[i - 1]] == 0) {
                freqMap.erase(nums[i - 1]);
            }
            // Add the new element coming into the window
            freqMap[nums[i + k - 1]]++;
            answer[i] = calculateXSum();
        }

        return answer;
        
    }
};