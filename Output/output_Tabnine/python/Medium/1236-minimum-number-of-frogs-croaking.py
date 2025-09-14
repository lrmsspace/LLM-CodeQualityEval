#https://leetcode.com/problems/minimum-number-of-frogs-croaking/
#You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
#Return the minimum number of different frogs to finish all the croaks in the given string.
#A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
# 
#Example 1:
#Input: croakOfFrogs = "croakcroak"
#Output: 1 
#Explanation: One frog yelling "croak" twice.
#Example 2:
#Input: croakOfFrogs = "crcoakroak"
#Output: 2 
#Explanation: The minimum number of frogs is two. 
#The first frog could yell "crcoakroak".
#The second frog could yell later "crcoakroak".
#Example 3:
#Input: croakOfFrogs = "croakcrook"
#Output: -1
#Explanation: The given string is an invalid combination of "croak" from different frogs.
# 
#Constraints:
#	1 <= croakOfFrogs.length <= 105
#	croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.
class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """
        if not croakOfFrogs or len(croakOfFrogs) % 5!= 0:
            return -1
        
        frogs = [0] * 5
        count = 0
        
        for c in croakOfFrogs:
            if c == 'c':
                frogs[0] += 1
            elif c == 'r':
                frogs[1] += 1
            elif c == 'o':
                frogs[2] += 1
            elif c == 'a':
                frogs[3] += 1
            elif c == 'k':
                frogs[4] += 1
                count += 1
            
            if any(frog!= 5 for frog in frogs):
                return -1
            
            for i in range(5):
                if frogs[i] > 0:
                    frogs[i] -= 1
        
        return count
        