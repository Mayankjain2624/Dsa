class twoStacks {
  public:
    int arr[100];
    int top1,top2;
    twoStacks() {
        top1=-1;
        top2=100;
    }
    void push1(int x) {
        if(top1<top2-1)
        {
        arr[++top1]=x;
        }
    }
    void push2(int x) {
        if(top1<top2-1)
        {
        arr[--top2]=x;
        }
    }
    int pop1() {
        if(top1>=0)
        {
        int z=arr[top1];
        top1--;
        return z;
        }
        return -1;
    }

    int pop2() {
        if(top2<=99)
        {
        int z=arr[top2];
        top2++;
        return z;
        }
        return -1;
    }
};