/**https://leetcode.com/problems/count-good-meals/ */
//A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.
//You can pick any two different foods to make a good meal.
//Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.
//Note that items with different indices are considered different even if they have the same deliciousness value.
// 
//Example 1:
//Input: deliciousness = [1,3,5,7,9]
//Output: 4
//Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
//Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
//Example 2:
//Input: deliciousness = [1,1,1,3,3,3,7]
//Output: 15
//Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.
// 
//Constraints:
//	1 <= deliciousness.length <= 105
//	0 <= deliciousness[i] <= 220
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int res = 0;
        int maxSum = 0;
        for(int i = 0; i < deliciousness.size(); i++){
            maxSum = max(maxSum,deliciousness[i]);
        }
        int maxPow = log2(maxSum)+1;
        vector<int> pow2(maxPow+1,0);
        pow2[0] = 1;
        for(int i = 1; i <= maxPow; i++){
            pow2[i] = pow2[i-1]*2;
        }
        vector<int> cnt(pow2[maxPow]+1,0);
        for(int i = 0; i < deliciousness.size(); i++){
            for(int j = 0; j <= maxPow; j++){
                int sum = pow2[j]-deliciousness[i];
                if(sum >= 0 && sum < pow2[maxPow]+1){
                    res += cnt[sum];
                }
            }
            cnt[deliciousness[i]]++;
        }
        return res%1000000007;
    }
};