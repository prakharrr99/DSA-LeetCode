class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        set<pair<int,int>> s;
        for(int i=0;i<obstacles.size();i++){
            s.insert({obstacles[i][0],obstacles[i][1]});
        }
        int b=0; //y
        int a=1;
        int ans=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                if(a==1) a=2;
                else if(a==2) a=3;
                else if(a==3) a=4;
                else a=1;
                b=!b;
            }
            else if(commands[i]==-2){
                if(a==1) a=4;
                else if(a==2) a=1;
                else if(a==3) a=2;
                else a=3;
                b=!b;
            }
            else{
                int j=0;

                if(s.count({x,y}) && j<commands[i]){
                    if(b==0){ //y
                        int py=y;
                        if(a==1) y++;
                        else y--;
                        if(s.count({x,y})){
                            y=py;
                            continue;
                        }
                    }
                    else{ //x
                        int px=x;
                        if(a==2) x++;
                        else x--;
                        if(s.count({x,y})){
                            x=px;
                            continue;
                        }
                    }
                    ans=max(ans,x*x+y*y);
                    j++;
                }
                while(j<commands[i]){
                    
                    if(b==0){ //y
                        int py=y;
                        if(a==1) y++;
                        else y--;
                        if(s.count({x,y})){
                            y=py;
                            break;
                        }
                        ans=max(ans,x*x+y*y);
                    }
                    else{ //x
                        int px=x;
                        if(a==2) x++;
                        else x--;
                        if(s.count({x,y})){
                            x=px;
                            break;
                        }
                        ans=max(ans,x*x+y*y);
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};