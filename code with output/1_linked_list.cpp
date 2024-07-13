#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct linked_list{
    int val;
    linked_list* next;
    linked_list()
    {
        val=0;
        next=NULL;
    }
    linked_list(int x)
    {
        val=x;
        next=NULL;
    }
    linked_list* push(int x)
    {
        linked_list* curr=this;
        curr->next=new linked_list(x);
        curr=curr->next;
        return curr;
    }
};
linked_list* reverse(linked_list* head)
{
    linked_list* nextNode=new linked_list();
    linked_list* prevNode=NULL;
    linked_list* curr=head;
    while(curr!=NULL)
    {
        nextNode=curr->next;
        curr->next=prevNode;
        prevNode=curr;
        curr=nextNode;
    }
    head=prevNode;
    return head;
}
int main()
{
    cout<<"Length of the linked list:";
    int N;
    cin>>N;
    cout<<"Input of the linked list:"<<endl;
    int x;
    cin>>x;
    linked_list* head=new linked_list(x);
    linked_list* curr=head;
    for(int t=1;t<N;t++)
    {
        cin>>x;
        curr=curr->push(x);
    }
    head=reverse(head);
    curr=head;
    while(curr!=NULL)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}