class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
         int n = logs.size();
         vector<pair<string,string>> dig;
         vector<pair<string,string>> letter;
         for(int i =0;i<n;i++){
             int x = logs[i].size();
             bool hua = false;
             int j = 0;
             string key ="";
             while(logs[i][j]!=' '){
                 key+=logs[i][j];
                 j++;
                 
             }

             for(int y = j;y<x;y++){
                if(logs[i][y-1]==' ' && (logs[i][y]>='0' && logs[i][y] <='9')){
                    dig.push_back({key,logs[i].substr(key.size()+1,(logs[i].size()-key.size() + 1))});
                    
                    hua =true;
                    break;
                }
             }
             if(!hua)  letter.push_back({key,logs[i].substr(key.size()+1,(logs[i].size()-key.size() + 1))});
         }

          sort(letter.begin(),letter.end(),[](pair<string,string> a, pair<string,string> b){
                  if(a.second == b.second) return a.first<b.first;
                  return a.second<b.second;
          });
        
         vector<string> ans;
         for(int i =0;i<letter.size();i++){
            string s = letter[i].first + " " + letter[i].second;
              ans.push_back(s);
         }
         for(int i =0;i<dig.size();i++){
            string s = dig[i].first + " " + dig[i].second;
              ans.push_back(s);
         }
         return ans;
         
    }
};