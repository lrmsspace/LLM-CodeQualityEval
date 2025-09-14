/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//	Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.
// 
//Example 1:
//Input: nums = [7,21,3]
//Output: true
//Explanation: We can sort [7,21,3] by performing the following operations:
//- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
//- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
//Example 2:
//Input: nums = [5,2,6,2]
//Output: false
//Explanation: It is impossible to sort the array because 5 cannot be swapped with any other element.
//Example 3:
//Input: nums = [10,5,9,3,15]
//Output: true
//We can sort [10,5,9,3,15] by performing the following operations:
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
//- Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
//- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	2 <= nums[i] <= 105
bool gcdSort(int* nums, int numsSize) {
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        maxNum = fmax(maxNum, nums[i]);
    }
    int prime[maxNum + 1];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= maxNum; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= maxNum; j += i) {
                prime[j] = i;
            }
        }
    }
    int parent[maxNum + 1];
    for (int i = 0; i <= maxNum; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (num > 1) {
            int p = prime[num];
            while (num % p == 0) {
                num /= p;
            }
            parent[find(parent, p)] = find(parent, parent[p]);
        }
    }
    int sorted[numsSize];
    for (int i = 0; i < numsSize; i++) {
        sorted[i] = nums[i];
    }
    qsort(sorted, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (find(parent, nums[i]) != find(parent, sorted[i])) {
            return false;
        }
    }
    return true;    
}