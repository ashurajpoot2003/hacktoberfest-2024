#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to find the shortest transformation sequence length
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set for the words in wordList (this makes lookups O(1))
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // If endWord is not in the dictionary, return 0 (no valid transformation)
        if (dict.find(endWord) == dict.end()) return 0;

        // Use a queue to implement BFS
        queue<string> todo;
        todo.push(beginWord);  // Start BFS with beginWord
        int ladder = 1;  // Ladder represents the number of transformations

        // Perform BFS
        while (!todo.empty()) {
            int n = todo.size();  // Number of words to process at this level

            // Process each word at the current level
            for (int i = 0; i < n; i++) {
                string word = todo.front();  // Get the current word
                todo.pop();

                // If the current word is the endWord, return the ladder length
                if (word == endWord) {
                    return ladder;
                }

                // Erase the word from the dictionary to avoid revisiting
                dict.erase(word);

                // Try changing every character of the current word
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];  // Save the original character

                    // Try all 26 possible characters in the alphabet
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;  // Replace with 'a' to 'z'

                        // If the new word exists in the dictionary, push it to the queue
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                    }
                    
                    word[j] = originalChar;  // Restore the original character
                }
            }

            // Increase ladder count after processing all words at the current level
            ladder++;
        }

        // If no transformation is possible, return 0
        return 0;
    }
};

int main() {
    Solution solution;

    // Input from the user
    string beginWord, endWord;
    int n;

    // Input the beginWord and endWord
    cout << "Enter the begin word: ";
    cin >> beginWord;
    cout << "Enter the end word: ";
    cin >> endWord;

    // Input the size of the word list
    cout << "Enter the number of words in the word list: ";
    cin >> n;

    // Input the word list
    vector<string> wordList(n);
    cout << "Enter the words in the word list: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    // Call the function and display the result
    int result = solution.ladderLength(beginWord, endWord, wordList);
    if (result == 0) {
        cout << "No transformation sequence exists." << endl;
    } else {
        cout << "The shortest transformation sequence is: " << result << " words long." << endl;
    }

    return 0;
}
