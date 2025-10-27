class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> lasers;
        for(int i=0;i<bank.size();i++){
            int count=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]!='0') count++;
            }   
            lasers.push_back(count);
        }

        int total=0;

        int i=0; int j=i+1;
        while(i<lasers.size()-1 && j<lasers.size()){
            j=i+1;
            while(i<lasers.size()-1 && lasers[i]==0) i++;
            while(j<lasers.size() && lasers[j]==0) j++;
            if(i<lasers.size()-1 && j<lasers.size() && i!=j)
                total+=lasers[i++]*lasers[j++];
        }
        return total;
    }
};