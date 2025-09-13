#https://leetcode.com/problems/stickers-to-spell-word/
#We are given n different types of stickers. Each sticker has a lowercase English word on it.
#You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
#Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
#Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
# 
#Example 1:
#Input: stickers = ["with","example","science"], target = "thehat"
#Output: 3
#Explanation:
#We can use 2 "with" stickers, and 1 "example" sticker.
#After cutting and rearrange the letters of those stickers, we can form the target "thehat".
#Also, this is the minimum number of stickers necessary to form the target string.
#Example 2:
#Input: stickers = ["notice","possible"], target = "basicbasic"
#Output: -1
#Explanation:
#We cannot form the target "basicbasic" from cutting letters from the given stickers.
# 
#Constraints:
#	n == stickers.length
#	1 <= n <= 50
#	1 <= stickers[i].length <= 10
#	1 <= target.length <= 15
#	stickers[i] and target consist of lowercase English letters.
class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        # Initialize a dictionary to store the frequency of each letter in the target
        target_freq = collections.Counter(target)
        
        # Initialize a set to store the remaining stickers
        remaining_stickers = set(stickers)
        
        # Initialize a dictionary to store the minimum number of stickers needed for each letter
        min_stickers = {letter: float('inf') for letter in target_freq}
        
        # Initialize a queue with the target string
        queue = collections.deque([(target, 0)])

        # Breadth-first search
        while queue:
            word, count = queue.popleft()
            
            # If the current word is empty, return the count
            if not word:
                return count
            
            # Update the minimum number of stickers needed for each letter
            for letter in word:
                min_stickers[letter] = min(min_stickers[letter], count)
            
            # Iterate through each sticker
            for sticker in remaining_stickers:
                # Check if the sticker can be used to form the current word
                if all(sticker.count(letter) >= target_freq[letter] for letter in word):
                    # Update the frequency of the letters in the target
                    updated_target_freq = {letter: target_freq[letter] - sticker.count(letter) for letter in target_freq}
                    
                    # Update the remaining stickers
                    remaining_stickers.remove(sticker)

                    # Add the new word to the queue
                    queue.append(("".join(sorted(updated_target_freq.keys())), count + 1))
                    
                    # Reset the remaining stickers
                    remaining_stickers.add(sticker)
            
            # Remove the current word from the queue
            queue.remove(word)
        
        # If no valid combination is found, return -1

        