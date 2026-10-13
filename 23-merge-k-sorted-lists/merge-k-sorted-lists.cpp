/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* a,ListNode* b){

        ListNode* d = new ListNode(-1),*t = d;


        while(a && b){

            if(a->val <= b->val){
                t->next = a;
                a = a->next;
                t = t->next;
            }
            else{
                t->next = b;
                b = b->next;
                t = t->next;
            }
        }


        if(a) t->next = a;
        if(b) t->next = b;

        return d->next;
    }

    void find(int i,int j,vector<ListNode*>& arr){

        if(i>=j) return;


        int mid = i+(j-i)/2;


        find(i,mid,arr);
        find(mid+1,j,arr);

        arr[i] = merge(arr[i],arr[mid+1]);
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n = arr.size();

        if(n==0) return NULL;



        find(0,n-1,arr);
        return arr[0];
    }
};