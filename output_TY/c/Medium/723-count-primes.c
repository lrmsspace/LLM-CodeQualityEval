/**https://leetcode.com/problems/count-primes/ */
//Given an integer n, return the number of prime numbers that are strictly less than n.
// 
//Example 1:
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//Example 2:
//Input: n = 0
//Output: 0
//Example 3:
//Input: n = 1
//Output: 0
// 
//Constraints:
//	0 <= n <= 5 * 106
int countPrimes(int n){
    if(n <= 2) return 0;
    int *arr = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i * i < n; i++){
        if(arr[i] == 0){
            for(int j = i * i; j < n; j += i){
                arr[j] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}