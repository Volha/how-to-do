#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
//InsertNode in a specific place
Node* InsertNth(Node *head, int data, int position)
{
  Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    int pos = 0;
    while(pos != position-1)
    {
        temp = temp->next;
        pos++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

//Delete Node in specific position
Node* Delete(Node *head, int position)
{
    if (position == 0)
    {
        head = head->next;
        return head;
    }
    int pos = 0;
    Node* prev = head;
    while(pos != position - 1)
    {
        pos++;
        prev = prev->next;
    }
    prev->next = prev->next->next;
    return head;
}
//reverse print
void ReversePrint(Node *head)
{
  stack<int> tempStack;
  Node* temp = head;
  while(temp != NULL)
  {
      tempStack.push(temp->data);
      temp = temp->next;
  }
    while (tempStack.size() != 0)
    {
        cout << tempStack.top()<<"\n";
        tempStack.pop();
    }
    
}

//merge two linked lists

Node* MergeLists(Node* list1, Node* list2) {
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;

  if (list1->data < list2->data) {
    list1->next = MergeLists(list1->next, list2);
    return list1;
  } else {
    list2->next = MergeLists(list2->next, list1);
    return list2;
  }
}

//Has cycle
int HasCycle(Node* head)
{
   Node* temp = head;
    vector<Node*> visitedNodes;
    
   while (temp != NULL)
   {
       if (find(visitedNodes.begin(), visitedNodes.end(), temp) != visitedNodes.end())
       {
           return 1;
       }else
       {
           visitedNodes.push_back(temp);
       }
       temp = temp->next;
   }
    return 0;
}
//Find merged node of twoo linked lists
int FindMergeNode(Node *headA, Node *headB)
{
    Node* tempA = headA;
    Node* tempB = headB;
    vector<Node*> A,B;
    while (tempA != NULL)
    {
        A.push_back(tempA);
        tempA = tempA->next;
    }
    while (tempB != NULL)
    {
        B.push_back(tempB);
        tempB = tempB->next;
    }
    bool isFound = false;
    int data;
    for_each(A.begin(), A.end(),[&](Node* n)
             {
                 if ((find(B.begin(), B.end(), n) != B.end())&&(!isFound))
                 {
                     isFound = true;
                     data = n->data;
                 }
             });
    return data;
    
}


void Print(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}

int main()
{
	int t;
	cin>>t;
	    Node *head = NULL;
		 head = new Node();
		 head->data = 2;
		 head->next = NULL;
	while(t-- >0){
		int x,n; cin>>x>>n;
		 head = InsertNth(head,x,n);
	}
	 Print(head);
	   cout<<"\n";

}