class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        
        for(int i=0;i<asteroids.size();i++){
            if(mass>=asteroids[i]){
                long long pp=mass+asteroids[i];
                if(pp>=1e5+8) return true;
                else mass+=asteroids[i];
            }
            else return false;
        }
        return true;
    }
};