/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.
// 
//Example 1:
//Input: num = 310
//Output: 103
//Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
//The arrangement with the smallest value that does not contain any leading zeros is 103.
//Example 2:
//Input: num = -7605
//Output: -7650
//Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
//The arrangement with the smallest value that does not contain any leading zeros is -7650.
// 
//Constraints:
//	-1015 <= num <= 1015
long long smallestNumber(long long num){
    int a[10]={0},i,j,k,n,m,x,y,z;
    long long r=0;
    n=abs(num);
    while(n){
        a[n%10]++;
        n/=10;
    }
    if(num>=0){
        for(i=1;i<10;i++){
            for(j=0;j<a[i];j++){
                r=r*10+i;
            }
        }
    }
    else{
        for(i=9;i>=1;i--){
            for(j=0;j<a[i];j++){
                r=r*10+i;
            }
        }
    }
    return r;
}