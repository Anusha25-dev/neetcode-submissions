class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string &str:strs){
            result+=to_string(str.size())+'#'+str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int length=stoi(s.substr(i,j-i));
            //substr(pos,length reqd.)
            //stoi - int to substring
            //here, we've included length of each string before the delimiter# and the string itself for ex. 7#awesome4#life
            string add=s.substr(j+1,length);
            result.push_back(add);
            i=j+1+length;
            //j+1 will be the position right after#
        }
        return result;
    }
};
