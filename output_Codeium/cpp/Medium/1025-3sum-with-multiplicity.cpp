/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
//Output: 20
//Explanation: 
//Enumerating by the values (arr[i], arr[j], arr[k]):
//(1, 2, 5) occurs 8 times;
//(1, 3, 4) occurs 8 times;
//(2, 2, 4) occurs 2 times;
//(2, 3, 3) occurs 2 times.
//Example 2:
//Input: arr = [1,1,2,2,2,2], target = 5
//Output: 12
//Explanation: 
//arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
//We choose one 1 from [1,1] in 2 ways,
//and two 2s from [2,2,2,2] in 6 ways.
//Example 3:
//Input: arr = [2,1,3], target = 6
//Output: 1
//Explanation: (1, 2, 3) occured one time in the array so we return 1.
// 
//Constraints:
//	3 <= arr.length <= 3000
//	0 <= arr[i] <= 100
//	0 <= target <= 300
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res = 0, MOD = 1e9 + 7;
        unordered_map<int, int> count;
        for (int i : arr) ++count[i];
        for (auto it1 = count.begin(); it1 != count.end(); ++it1) {
            for (auto it2 = next(it1); it2 != count.end(); ++it2) {
                int i = it1->first, j = it2->first, k = target - i - j;
                if (k < j) continue;
                if (k == i) res += (long long)it1->second * (it1->second - 1) / 2 * it2->second;
                else if (k == j) res += (long long)it1->second * it2->second * (it2->second - 1) / 2;
                else res += (long long)it1->second * it2->second * count[k];
                res %= MOD;
            }
        }
        return res;
    }
};