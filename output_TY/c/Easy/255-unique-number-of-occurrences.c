/**https://leetcode.com/problems/unique-number-of-occurrences/ */
//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
// 
//Example 1:
//Input: arr = [1,2,2,1,1,3]
//Output: true
//Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
//Example 2:
//Input: arr = [1,2]
//Output: false
//Example 3:
//Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
//Output: true
// 
//Constraints:
//	1 <= arr.length <= 1000
//	-1000 <= arr[i] <= 1000
bool uniqueOccurrences(int* arr, int arrSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[1001]={0};
    int b[1001]={0};
    for(i=0;i<arrSize;i++){
        a[arr[i]]++;
    }
    for(i=0;i<1001;i++){
        if(a[i]!=0){
            b[a[i]]++;
        }
    }
    for(i=0;i<1001;i++){
        if(b[i]>1){
            return false;
        }
    }
    return true;
}