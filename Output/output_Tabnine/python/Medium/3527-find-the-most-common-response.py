# You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.
# Return the most common response across all days after removing duplicate responses within each responses[i]. If there is a tie, return the lexicographically smallest response.
# Example 1:
# Input: responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]
# Output: "good"
# Explanation:
# After removing duplicates within each list, responses = [["good", "ok"], ["ok", "bad", "good"], ["good"], ["bad"]].
# "good" appears 3 times, "ok" appears 2 times, and "bad" appears 2 times.
# Return "good" because it has the highest frequency.
# Example 2:
# Input: responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]
# Output: "bad"
# Explanation:
# After removing duplicates within each list we have responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"], ["great", "good"]].
# "bad", "good", and "ok" each occur 2 times.
# The output is "bad" because it is the lexicographically smallest amongst the words with the highest frequency.
# Constraints:
# 1 <= responses.length <= 1000
# 1 <= responses[i].length <= 1000
# 1 <= responses[i][j].length <= 10
# responses[i][j] consists of only lowercase English letters

class Solution(object):
    def findCommonResponse(self, responses):
        """
        :type responses: List[List[str]]
        :rtype: str
        """
        # Remove duplicates within each responses[i] list
        responses = [list(set(response)) for response in responses]
        
        # Count the frequency of each response
        frequency = {}
        for response in responses:
            for word in response:
                frequency[word] = frequency.get(word, 0) + 1
        
        # Find the most common response
        max_frequency = 0
        most_common_response = None
        for response, count in frequency.items():
            if count > max_frequency:
                max_frequency = count
                most_common_response = response
            elif count == max_frequency and response < most_common_response:
                most_common_response = response
        
        return most_common_response 
        