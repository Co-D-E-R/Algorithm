#include<bits/stdc++.h>
using namespace std;
class minHeap {
   
public:
    int *a;
    int capacity;
    int size;
    // Constructor for the class.
     minHeap(int cap) {
        // Write your code here.
        size=0;
        capacity=cap;
        a=new int[cap];
    }

    int parent(int i){
        return (i-1)/2;
    }
    int lchild(int i){
        return (2*i+1);
    }
    int rchild(int i){
        return (2*i+2);
    }


   
    void minhepify(int i){
        int l=lchild(i);
        int r=rchild(i);
        int small = i;
        if(l < size && a[l]<a[small])
            small = l;
        if(r < size && a[r]<a[small])
            small = r;
        if(small != i)
        {
            swap(a[i],a[small]);
            minhepify(small);
        } 
    }
    // Implement the function to remove minimum element.
    int extractMinElement() {
        if(size<=0){
            return -1;
        }
        if(size == 1){
            size--;
            return a[0];
        }
        int root = a[0];
        size--;
        a[0] = a[size];
        a[size]=0;
        minhepify(0);
        return root;
    }
    void keyelement(int ind,int new_val){
        a[ind]=new_val;
        while(ind != 0 && a[parent(ind)] > a[ind])
        {
            swap(a[ind],a[parent(ind)]);
            ind=parent(ind);
        }
       

    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
       if(ind < size){
           keyelement(ind,INT_MIN);
           extractMinElement();
       }
       
        
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        size++;
        int i=size-1;
        a[i]=val;

        while(i!=0 && a[parent(i)]>a[i]){
            swap(a[parent(i)],a[i]);
            i=parent(i);
        }

    }
};