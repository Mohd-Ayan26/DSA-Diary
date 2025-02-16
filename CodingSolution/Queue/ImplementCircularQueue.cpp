class MyCircularQueue {
public:
    int *arr;
    int qfront;
    int qrear;
    int size;
    MyCircularQueue(int k) {
        size=k;
        arr=new int[k];
        qfront=qrear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        else if(qfront==-1)
        {
            qfront=qrear=0;
        }
        else if(qrear==size-1 && qfront!=0)
        {
            qrear=0;
        }
        else
        {
            qrear++;
        }
        arr[qrear]=value;
        return true;
    }
    
    bool deQueue() {
      if(isEmpty())
      {
        return false;
      }
      int ans=arr[qfront];
      arr[qfront]=-1;
      //single element
      if(qfront==qrear)
      {
         qfront=qrear=-1;
      }
      else if(qfront==size-1)
      {
        qfront=0;
      }
      else
      {
        qfront++;
      }
      return true;

    }
    
    int Front() {
        if(!isEmpty())
        {
            return arr[qfront];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
       {
         return arr[qrear];

       }
       return -1;
    }
    
    bool isEmpty() {
        if(qfront==-1)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(qfront==0 && qrear==size-1 || qrear==(qfront-1)%(size))
        {
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
