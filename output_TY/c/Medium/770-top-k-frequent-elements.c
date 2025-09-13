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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int i,j,max,max_index,count;
    int* result;
    int* freq;
    int freq_size;
    int freq_index;
    
    freq_size = 0;
    for(i=0;i<numsSize;i++){
        for(j=0;j<freq_size;j++){
            if(freq[j]==nums[i]){
               freq[j]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        freq_size++;
    }
    freq = (int*)malloc(sizeof(int)*freq_size);
    for(i=0;i<freq_size;i++){
        freq[i]=0;
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<freq_size;j++){
            if(freq[j]==nums[i]){
               freq[j]++;
            }
        }
    }
    for(i=0;i<freq_size;i++){
        if(freq[i]==0){
            freq_size--;
        }
    }
    for(i=0;i<freq_size;i++){
        for(j=i+1;j<freq_size;j++){
            if(freq[i]<freq[j]){
                temp=freq[i];
                freq[i]=freq[j];
                freq[j]=temp;
            }
        }
    }
    for(i=0;i<k;i++){
        ans[i]=freq[i];
    }
    return ans;
}