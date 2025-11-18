class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        if(bits.size()>1 && bits[bits.size()-1]==0 && bits[bits.size()-2]==0) return true;

        int i=0; int a=0;
        while(i<bits.size()){
            a=0;
            if(bits[i]==0){ i++; a=1;}
            else i+=2;
        }
        if(a==1) return true;
        return false;
    }
};