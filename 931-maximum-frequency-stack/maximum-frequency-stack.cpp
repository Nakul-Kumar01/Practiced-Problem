class FreqStack {
public:

    unordered_map<int,int>m;
    unordered_map<int,stack<int>>freq;

    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;


        freq[m[val]].push(val);
    }
    
    int pop() {
        int f = freq.size();


        int res = freq[f].top();
        freq[f].pop();
        m[res]--;
        
        if(freq[f].empty()) freq.erase(f);

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */