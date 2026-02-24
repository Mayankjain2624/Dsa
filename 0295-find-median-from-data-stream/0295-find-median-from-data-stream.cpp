class MedianFinder {
public:
    priority_queue<int> leftmaxheap;
    priority_queue<int, vector<int>, greater<>> rightminheap;
    MedianFinder() {}
    void addNum(int num) {
        if (leftmaxheap.empty() && rightminheap.empty()) {
            leftmaxheap.push(num);
        }
        else if (num > leftmaxheap.top())
            rightminheap.push(num);
        else
            leftmaxheap.push(num);
        if (rightminheap.size() > leftmaxheap.size()) {
            int temp = rightminheap.top();
            leftmaxheap.push(temp);
            rightminheap.pop();
        }
         else if (leftmaxheap.size() > rightminheap.size()+1) {
            int temp = leftmaxheap.top();
            rightminheap.push(temp);
            leftmaxheap.pop();
        }

    }

    double findMedian() {
        double median = 0;
        if (leftmaxheap.size() == rightminheap.size()) {
            median = (leftmaxheap.top() + rightminheap.top()) * 0.5;
        } else {
            median = leftmaxheap.top();
        }
        return median;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */