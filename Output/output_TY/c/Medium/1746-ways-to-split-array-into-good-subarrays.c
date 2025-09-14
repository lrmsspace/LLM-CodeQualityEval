/**https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/ */
//You are given a binary array nums.
//A subarray of an array is good if it contains exactly one element with the value 1.
//Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [0,1,0,0,1]
//Output: 3
//Explanation: There are 3 ways to split nums into good subarrays:
//- [0,1] [0,0,1]
//- [0,1,0] [0,1]
//- [0,1,0,0] [1]
//Example 2:
//Input: nums = [0,1,0]
//Output: 1
//Explanation: There is 1 way to split nums into good subarrays:
//- [0,1,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 1
int numberOfGoodSubarraySplits(int* nums, int numsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==1){
            for(j=i+1;j<numsSize;j++){
                if(nums[j]==1){
                    for(k=j+1;k<numsSize;k++){
                        if(nums[k]==1){
                            for(l=k+1;l<numsSize;l++){
                                if(nums[l]==1){
                                    for(m=l+1;m<numsSize;m++){
                                        if(nums[m]==1){
                                            for(n=m+1;n<numsSize;n++){
                                                if(nums[n]==1){
                                                    for(o=n+1;o<numsSize;o++){
                                                            if(nums[o]==1){
                                                                for(p=o+1;p<numsSize;p++){
                                                                    if(nums[p]==1){
                                                                        for(q=p+1;q<numsSize;q++){
                                                                            if(nums[q]==1){
                                                                                for(r=q+1;r<numsSize;r++){
                                                                                    if(nums[r]==1){
                                                                                        for(s=r+1;s<numsSize;s++){
                                                                                            if(nums[s]==1){
                                                                                                for(t=s+1;t<numsSize;t++){
                                                                                                    if(nums[t]==1){
                                                                                                       for(u=t+1;u<numsSize;u++){
                                                                                                          if(nums[u]==1){
                                                                                                              for(v=u+1;v<numsSize;v++){
                                                                                                                if(nums[v]==1){
                                                                                                                    for(w=v+1;w<numsSize;w++){
                                                                                                                if(nums[w]==1){
                                                                                                                    for(x=w+1;x<numsSize;x++){
                                                                                                                        if(nums[x]==1){
                                                                                                                            for(y=x+1;y<numsSize;y++){
                                                                                                                                if(nums[y]==1){
                                                                                                                            return 1;
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
