class Solution {
public:
    string clearDigits(string s) {
        string result;

        for(char ch : s){
            if(isdigit(ch)){
                // remove if it is only integer else add the non-int elements into the results.
                if(!result.empty()){
                    result.pop_back();
                } 
            }
            else {
                    result.push_back(ch);
            }
        }
        return result;
    }
};