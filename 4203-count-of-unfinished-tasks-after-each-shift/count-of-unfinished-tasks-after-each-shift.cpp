class Solution {
public:
    vector<int> countTasks(vector<int>& task, vector<int>& shift) {
        vector<long long> p;
        p.push_back(task[0]);
        for(int i=1;i<task.size();i++){
            p.push_back(p[i-1]+task[i]);
        }

        long long workdone=0;
        vector<int> ans;
        for(auto it:shift){
            workdone+=it;
            auto iit=upper_bound(p.begin(),p.end(),workdone);
            int idx=iit-p.begin();
            ans.push_back(task.size()-idx);
           
            if(task.size()-idx==0) workdone=0;
        }
        return ans;
    }
};