class MyCircularQueue {
public:
    vector<int>q;
    int f=0;
    int r=-1;
    int len=0;
    MyCircularQueue(int k) {
        q.reserve(k);
        /*for(int i=0;i<k;i++) {
            q.push_back(-1);
        }*/
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            q[(r+1)%q.capacity()]=value;
            r=(r+1)%q.capacity();
            len++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        f=(f+1)%q.capacity();
        len--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:q[f];
    }
    
    int Rear() {
        return isEmpty()?-1:q[r];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==q.capacity();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */