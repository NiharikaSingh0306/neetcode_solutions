class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string s: strs)
        ans+= to_string(s.size()) + "#" + s;

        return ans;

    }

    vector<string> decode(string s) {

        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;

            while(s[j]!='#'){
                j++;
            }

            //length of the current string

            int len=stoi(s.substr(i, j-i));

            //extract string
            ans.push_back(s.substr(j+1,len));

            //move to the next encoded string
            i=j+1+len;
        }

        return ans;

    }
};
