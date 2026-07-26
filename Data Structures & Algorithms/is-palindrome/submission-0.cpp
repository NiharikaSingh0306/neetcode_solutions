class Solution {
private:
    bool valid(char ch) {
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            return 1;
        } else {
            return 0;
        }
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return ch;
        } else {
            // Convert uppercase to lowercase
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string s) {
        int st = 0;
        int e = s.length() - 1;

        while (st < e) {
            if (s[st] != s[e]) {
                return false;
            } else {
                st++;
                e--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        // Remove invalid characters
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }

        // Convert to lowercase
        for (int j = 0; j < temp.length(); j++) {
            temp[j] = toLowerCase(temp[j]);
        }

        return checkPalindrome(temp);

    }
};



