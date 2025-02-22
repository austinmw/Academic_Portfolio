/* Sample input:
	6
	1
	2
	2
	3
	3
	4
*/

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
	public:
		int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
class Solution{
	public:        




/* Function to remove duplicates from a unsorted linked list */
	Node* removeDuplicates(Node *head)
	{
		Node *ptr1, *ptr2, *dup;
		ptr1 = head;
	 
		/* Pick elements one by one */
		while(ptr1 != NULL && ptr1->next != NULL)
		{
			 ptr2 = ptr1;
	 
			 /* Compare the picked element with rest of the elements */
			 while(ptr2->next != NULL)
			 {
				 /* If duplicate then delete it */
				 if(ptr1->data == ptr2->next->data)
				 {
						/* sequence of steps is important here */
						dup = ptr2->next;
						ptr2->next = ptr2->next->next;						
						free(dup);
				 }
				 else /* This is tricky */
				 {
						ptr2 = ptr2->next;
				 }
			 }
			 ptr1 = ptr1->next;
		}
		return head;
	}
	
	Node* insert(Node *head,int data)
	{
			 Node* p=new Node(data);
			 if(head==NULL){
					 head=p;  

			 }
			 else if(head->next==NULL){
					 head->next=p;

			 }
			 else{
					 Node *start=head;
					 while(start->next!=NULL){
							 start=start->next;
					 }
					 start->next=p;   

			 }
						return head;
				
		
	}
	void display(Node *head)
	{
					Node *start=head;
						while(start)
						{
								cout<<start->data<<" ";
								start=start->next;
						}
	 }
};
			
int main()
{
	Node* head=NULL;
		Solution mylist;
		int T,data;
		cin>>T;
		while(T-->0){
				cin>>data;
				head=mylist.insert(head,data);
		}	
		head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}
		