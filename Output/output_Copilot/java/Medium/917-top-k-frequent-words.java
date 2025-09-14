/**https://leetcode.com/problems/top-k-frequent-words/ */
//Given an array of strings words and an integer k, return the k most frequent strings.
//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
// 
//Example 1:
//Input: words = ["i","love","leetcode","i","love","coding"], k = 2
//Output: ["i","love"]
//Explanation: "i" and "love" are the two most frequent words.
//Note that "i" comes before "love" due to a lower alphabetical order.
//Example 2:
//Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
//Output: ["the","is","sunny","day"]
//Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
// 
//Constraints:
//	1 <= words.length <= 500
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
//	k is in the range [1, The number of unique words[i]]
// 
//Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        // Create a frequency map to count occurrences of each word
        Map<String, Integer> frequencyMap = new HashMap<>();
        for (String word : words) {
            frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
        }

        // Create a priority queue (min-heap) to store the top k frequent words
        PriorityQueue<String> minHeap = new PriorityQueue<>((a, b) -> {
            if (frequencyMap.get(a).equals(frequencyMap.get(b))) {
                return a.compareTo(b); // Lexicographical order
            }
            return frequencyMap.get(a) - frequencyMap.get(b); // Frequency order
        });

        // Add words to the min-heap
        for (String word : frequencyMap.keySet()) {
            minHeap.offer(word);
            if (minHeap.size() > k) {
                minHeap.poll(); // Remove the least frequent word
            }
        }

        // Extract the top k frequent words from the min-heap
        List<String> result = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll());
        }

        // Reverse the result to get the correct order
        Collections.reverse(result);
        return result;        
    }
}