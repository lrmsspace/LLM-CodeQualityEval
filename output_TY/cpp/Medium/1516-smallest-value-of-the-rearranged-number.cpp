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
class Solution {
public:
    long long smallestNumber(long long num) {
        long long ans = 0;
        vector<int> v;
        bool flag = false;
        if(num < 0){
            flag = true;
            num = -num;
        }
        while(num){
            v.push_back(num%10);
            num = num/10;
        }
        sort(v.begin(),v.end());
        if(flag){
            for(int i = 0;i<v.size();i++){
                if(v[i] != 0){
                    ans = ans*10 + v[i];
                    v[i] = 0;
                    break;
                }
            }
            for(int i = 0;i<v.size();i++){
                ans = ans*10 + v[i];
            }
        }
        else{
            for(int i = v.size()-1;i>=0;i--){
                ans = ans*10 + v[i];
            }
        }
        return -ans;
    }
};