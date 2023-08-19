//Merge kth list into single sorted list   
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode  dummy(-1); 
        ListNode *result = &dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;                
                result = result->next;
                l2 = l2->next;
            }            
        }
        if(l1)
            result->next = l1;
        else if(l2)
            result->next = l2;
        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) 
        {
            for (int i = 0; i < len / 2; ++i) 
            {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists.front();
    }

int main()
{
    int size;
    vector<ListNode *> lists;
    
    cout<<"Enter the size :: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int lsize;
        ListNode *p = NULL;
        cout<<"Enter list number :: ";
        cin>>lsize; 
        for(int j=0;j<lsize;j++){
            p=new ListNode();
            int x;
            cin>>x;
            p->val=x;
            lists.push_back(p);
        }
    }
    mergeKLists(lists);
    
    for(auto list:lists){
        ListNode *q = list;
        while(q!=NULL){
            cout<<q->val<<" ";
            q=q->next;
        }
    }

    return 0;
}