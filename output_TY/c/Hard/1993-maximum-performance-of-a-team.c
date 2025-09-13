/**https://leetcode.com/problems/maximum-performance-of-a-team/ */
//You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
//Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
//The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
//Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
//Output: 60
//Explanation: 
//We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
//Example 2:
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
//Output: 68
//Explanation:
//This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
//Example 3:
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
//Output: 72
// 
//Constraints:
//	1 <= k <= n <= 105
//	speed.length == n
//	efficiency.length == n
//	1 <= speed[i] <= 105
//	1 <= efficiency[i] <= 108
int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k){
    int i,j,k1,k2,s,e,max,min,sum,len,*p,*q;
    int *a,*b;
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        a[i]=efficiency[i];
        b[i]=speed[i];
    }
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]==efficiency[j]){
                efficiency[j]=i;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(b[i]==speed[j]){
                speed[j]=i;
                break;
            }
        }
    }
    max=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k1=0;k1<=k;k1++){
                for(k2=0;k2<=k;k2++){
                    if(k1+k2==k){
                        s=0;
                        e=0;
                        sum=0;
                        len=0;
                        p=a+i;
                    }
                }
            }
        }
    }
    free(a);
    free(b);
    return max;
}