class ParkingSystem {
public:
    // vector<int> bi;
    // vector<int> m;
    // vector<int> s;
    pair<int,int> a;
    pair<int,int> b;
    pair<int,int> c;
    ParkingSystem(int big, int medium, int small) {
        // bi.resize(big,-1);
        // m.resize(medium,-1);
        // s.resize(small,-1);
        a={0,big};
        b={0,medium};
        c={0,small};
    }
    bool addCar(int carType) {
        if(carType==3){
            if(c.first==c.second) return false;
            c.first++;
            return true;
        }
        else if(carType==2){
            if(b.first==b.second) return false;
            b.first++;
            return true;
        }
        else{
            if(a.first==a.second) return false;
            a.first++;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */