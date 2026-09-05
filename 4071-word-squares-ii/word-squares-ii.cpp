class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
         vector<vector<string>> temp;
        for(int i=0;i<words.size();i++){
            string top=words[i];
            for(int j=0;j<words.size();j++){
                string left=words[j];
                for(int k=0;k<words.size();k++){
                    string right=words[k];
                    for(int l=0;l<words.size();l++){
                        string bottom=words[l];
                        if(top!=bottom && top!=right && top!=left && bottom!=right && bottom!=left && left!=right){
                            if(top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3]){
                                temp.push_back({top,left,right,bottom});
                            }
                        }
                    }
                }
            }
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};