/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], k = 10
//Output: 1
//Explanation: The only good subarray is the array nums itself.
//Example 2:
//Input: nums = [3,1,4,3,2,2,4], k = 2
//Output: 4
//Explanation: There are 4 different good subarrays:
//- [3,1,4,3,2,2] that has 2 pairs.
//- [3,1,4,3,2,2,4] that has 3 pairs.
//- [1,4,3,2,2,4] that has 2 pairs.
//- [4,3,2,2,4] that has 2 pairs.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i], k <= 109
long long countGood(int* nums, int numsSize, int k){  
    int i,j,count,*freq,*freq_count,*freq_index,*freq_index_count,*freq_index_count_count,*freq_index_count_count_count,*freq_index_count_count_count_count,*freq_index_count_count_count_count_count,*freq_index_count_count_count_count_count_count,*freq_index_count_count_count_count_count_count_count     ;
    long long result=0;
    freq=calloc(numsSize,sizeof(int));
    freq_count=calloc(numsSize,sizeof(int));
    freq_index=calloc(numsSize,sizeof(int));
    freq_index_count=calloc(numsSize,sizeof(int));
    freq_index_count_count=calloc(numsSize,sizeof(int));
    freq_index_count_count_count=calloc(numsSize,sizeof(int));
    freq_index_count_count_count_count=calloc(numsSize,sizeof(int));
    freq_index_count_count_count_count_count=calloc(numsSize,sizeof(int));
    freq_index_count_count_count_count_count_count=calloc(numsSize,sizeof(int));
    for(i=0;i<numsSize;i++){
        freq[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        freq_count[i]=1;
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq[i]==freq[j]){
                freq_index[i]=j;
                freq_index_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index[i]==freq_index[j]){
                freq_index_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count[i]==freq_index_count[j]){
                freq_index_count_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count_count[i]==freq_index_count_count[j]){
                freq_index_count_count_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count_count_count[i]==freq_index_count_count_count[j]){
                freq_index_count_count_count_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count_count_count_count[i]==freq_index_count_count_count[j]){
                freq_index_count_count_count_count_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count_count_count_count_count[i]==freq_index_count_count_count_count[j]){
                freq_index_count_count_count_count_count_count_count[i]++;
            }
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(freq_index_count_count_count_count_count_count[i]==freq_index_count_count_count_count_count[j]){
                result+=freq_index_count_count_count_count_count_count_count[i];
           }
        }
    }
    free(freq);
    free(freq_count);
    free(freq_index);
    free(freq_index_count);
    free(freq_index_count_count);
    free(freq_index_count_count_count);
    free(freq_index_count_count_count_count);
    free(freq_index_count_count_count_count_count_count);
    return result;
}