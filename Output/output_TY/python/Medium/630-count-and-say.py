#https://leetcode.com/problems/count-and-say/
#The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
#	countAndSay(1) = "1"
#	countAndSay(n) is the run-length encoding of countAndSay(n - 1).
#Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
#Given a positive integer n, return the nth element of the count-and-say sequence.
# 
#Example 1:
#Input: n = 4
#Output: "1211"
#Explanation:
#countAndSay(1) = "1"
#countAndSay(2) = RLE of "1" = "11"
#countAndSay(3) = RLE of "11" = "21"
#countAndSay(4) = RLE of "21" = "1211"
#Example 2:
#Input: n = 1
#Output: "1"
#Explanation:
#This is the base case.
# 
#Constraints:
#	1 <= n <= 30
# 
#Follow up: Could you solve it iteratively?
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1: return "1"
        else: return self.countAndSay(n-1).replace("1","I",1).replace("2","II",1).replace("3","III",1).replace("4","IV",1).replace("5","V",1).replace("6","VI",1).replace("7","VII",1).replace("8","VIII",1).replace("9","IX",1).replace("10","X",1).replace("20","XX",1).replace("30","XXX",1).replace("40","XL",1).replace("50","L",1).replace("60","LX",1).replace("70","LXX",1).replace("80","LXXX",1).replace("90","XC",1).replace("100","C",1)