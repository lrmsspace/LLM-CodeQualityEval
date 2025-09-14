/**https://leetcode.com/problems/two-city-scheduling/ */
//A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
// 
//Example 1:
//Input: costs = [[10,20],[30,200],[400,50],[30,20]]
//Output: 110
//Explanation: 
//The first person goes to city A for a cost of 10.
//The second person goes to city A for a cost of 30.
//The third person goes to city B for a cost of 50.
//The fourth person goes to city B for a cost of 20.
//The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
//Example 2:
//Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
//Output: 1859
//Example 3:
//Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
//Output: 3086
// 
//Constraints:
//	2 * n == costs.length
//	2 <= costs.length <= 100
//	costs.length is even.
//	1 <= aCosti, bCosti <= 1000
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int i,j,k,n,m,sum,min,min_sum,min_index;
    int *a,*b;
    a=(int *)malloc(sizeof(int)*costsSize);
    b=(int *)malloc(sizeof(int)*costsSize);
    for(i=0;i<costsSize;i++){
        a[i]=costs[i][0];
        b[i]=costs[i][1];
    }
    sum=0;
    for(i=0;i<costsSize;i++){
        sum+=costs[i][0];
    }   
    min_sum=sum;
    for(i=0;i<costsSize;i++){
        for(j=i+1;j<costsSize;j++){
            sum=sum-a[i]-b[j]+a[j]+b[i];
            if(sum<min_sum){
                min_sum=sum;
            }
            sum=sum-a[j]-b[i]+a[i]+b[j];
        }
   }
   return min_sum;
}