class KthLargest {
private:
    int gk;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > gk) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};