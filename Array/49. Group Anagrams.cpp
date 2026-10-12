class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string , vector<string>> map ;



        for(auto& a : strs){


            string temp = a ;

            sort(temp.begin() , temp.end());

            map[temp].push_back(a);
        }



        for(auto& [a , b] : map){

            ans.push_back(b);
        }


        return ans;
    }
};
