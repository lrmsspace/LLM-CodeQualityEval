/**https://leetcode.com/problems/make-array-empty/ */
//You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:
//	If the first element has the smallest value, remove it
//	Otherwise, put the first element at the end of the array.
//Return an integer denoting the number of operations it takes to make nums empty.
// 
//Example 1:
//Input: nums = [3,4,-1]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[4, -1, 3]
//		
//		
//			2
//			[-1, 3, 4]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 2:
//Input: nums = [1,2,4,3]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 4, 3]
//		
//		
//			2
//			[4, 3]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 3:
//Input: nums = [1,2,3]
//Output: 3
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 3]
//		
//		
//			2
//			[3]
//		
//		
//			3
//			[]
//		
//	
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	All values in nums are distinct.
long long countOperationsToEmptyArray(int* nums, int numsSize) {
    int i, j;
    int a[100000];
    for (i = 0; i < numsSize; i++) {
        a[nums[i]] = i;
    }
    long long res = numsSize;
    for (i = 1; i < numsSize; i++) {
        if (a[i] < a[i - 1])
            res += numsSize - i;
    }
    return res;
}