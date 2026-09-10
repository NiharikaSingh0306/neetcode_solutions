class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord must exist
        if(words.find(endWord) == words.end()){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int lev = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string word = q.front();
                q.pop();

                // changing every character
                for(int i = 0; i < word.length(); i++) {

                    char og = word[i];

                    for(char c = 'a'; c <= 'z'; c++) {

                        if(c == og) {
                            continue;
                        }

                        word[i] = c;

                        if(word == endWord) {
                            return lev + 1;
                        }

                        if(words.find(word) != words.end()) {

                            q.push(word);

                            // mark visited
                            words.erase(word);
                        }
                    }

                    // restore original character
                    word[i] = og;
                }
            }

            lev++;
        }

        return 0;
    }
};