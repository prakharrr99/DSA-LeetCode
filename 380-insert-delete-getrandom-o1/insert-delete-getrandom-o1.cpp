class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int,int> m;
    RandomizedSet() {
        srand(time(0));
    }
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        a.push_back(val);
        m[val]=a.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){

            int last=a.back();
            int idx=m[val];
            a[idx]=last;
            m[last]=idx;

            a.pop_back();
            m.erase(val);

            return true;
        }
        return false;
    }
    
    int getRandom() {

        int idx = rand() % a.size();
        return a[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */