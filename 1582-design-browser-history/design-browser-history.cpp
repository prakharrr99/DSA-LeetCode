class BrowserHistory {
public:
    vector<string> v;
    int a;
    int n;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        a=0;
        n=1;
    }
    
    void visit(string url) {
        v.resize(a+1);
        v.push_back(url);
        n=v.size();
        a=n-1;
    }
    
    string back(int steps) {
        if(steps>a){
            a=0;
            return v[a];
        }
        while(steps!=0){
            steps--;
            a--;
        }
        return v[a];
    }
    
    string forward(int steps) {
        if(steps>=n-a){
            a=n-1;
            return v[a];
        }
        while(steps!=0){
            steps--;
            a++;
        }
        return v[a];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */