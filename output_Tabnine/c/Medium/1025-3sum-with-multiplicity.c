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
int threeSumMulti(int* arr, int arrSize, int target) {
    int MOD = 1000000007;
    int n = arrSize;
    int count = 0;
    
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    // Iterate through the array
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            
            if (sum == target) {
                // Count the number of valid triplets
                count += (right - left + 1);
                count %= MOD;
                
                // Skip duplicates in the left and right sides
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                
                // Move the pointers
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return count;
    
}