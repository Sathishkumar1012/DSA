class MyCircularQueue {
public:
    vector<int>q;
    int f=0;
    int r=-1;
    MyCircularQueue(int k) {
        q.reserve(k);
        for(int i=0;i<k;i++) {
            q.push_back(-1);
        }
    }
    
    bool enQueue(int value) {
        if(isEmpty() || !isFull()) {
            q[(r+1)%q.capacity()]=value;
            r=(r+1)%q.capacity();
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(f==r)
            f=0,r=-1;
        else
        f=(f+1)%q.capacity();
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return q[f];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return q[r];
    }
    
    bool isEmpty() {
        if(r==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        int temp=(r+1)%q.capacity();
        if(!isEmpty() && temp==f) {
            return true;
        }
        return false;
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