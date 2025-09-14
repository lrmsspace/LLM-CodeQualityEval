/*
 You are given an integer array nums.
 Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
 Example 1:
 Input: nums = [4,2,9,5,3]
 Output: 3
 Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
 Example 2:
 Input: nums = [4,8,2,8]
 Output: 0
 Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.
 Constraints:
 1 <= nums.length <= 3 * 105
 1 <= nums[i] <= 100
 The input is generated such that the number of prime numbers in the nums is at least one.
*/

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        int min_num = *min_element(nums.begin(), nums.end());
        
        int prime[max_num + 1] = {0};
        prime[0] = prime[1] = 0;
        for(int i = 2; i <= max_num; i++){
            prime[i] = 1;
        }
        
        for(int i = 2; i <= sqrt(max_num); i++){
            if(prime[i] == 1){
                for(int j = i * i; j <= max_num; j += i){
                    prime[j] = 0;
                }
            }
        }
        
        int max_diff = 0;
        for(int i = 0; i < nums.size(); i++){
            int curr_num = nums[i];
            int max_prime = curr_num;
            while(prime[max_prime] == 0){
                max_prime--;
            }
            int min_prime = curr_num;
            while(prime[min_prime] == 0){
                min_prime++;
            }
            max_diff = max(max_diff, max_prime - min_prime);
        }
        return max_diff;
        
    }
};