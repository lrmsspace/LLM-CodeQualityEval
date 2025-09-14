/*
 You are given an array of integers nums of size 3.
 Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
 Note that the binary representation of any number does not contain leading zeros.
 Example 1:
 Input: nums = [1,2,3]
 Output: 30
 Explanation:
 Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
 Example 2:
 Input: nums = [2,8,16]
 Output: 1296
 Explanation:
 Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
 Constraints:
 nums.length == 3
 1 <= nums[i] <= 127
*/

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> bin;
        for(int i=0;i<nums.size();i++){
            string s="";
            int num = nums[i];
            while(num){
                s+=to_string(num%2);
                num/=2;
            }
            reverse(s.begin(),s.end());
            bin.push_back(s);
        }
        vector<string> all;
        for(int i=0;i<3;i++){
            for(int j=0;j<bin[i].size();j++){
                string s="";
                for(int k=0;k<3;k++){
                    if(k==i){
                        s+=bin[k][j];
                    }
                    else{
                        s+='0';
                    }
                }
                all.push_back(s);
            }
        }
        int res=0;
        for(int i=0;i<all.size();i++){
            int num=0;
            for(int j=0;j<all[i].size();j++){
                num*=2;
                num+=all[i][j]-'0';
            }
            res=max(res,num);
        }
        return res;

            
    }
};