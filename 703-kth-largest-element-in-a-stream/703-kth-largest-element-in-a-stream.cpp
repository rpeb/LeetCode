class KthLargest {
    int c;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        c = k;
        for (int num: nums) {
            q.push(num);
            if (q.size() > k)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        while (q.size() > c) {
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */