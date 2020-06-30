#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node 
{
    int data;
    node *next;
};

class linked_list 
{
    private :
    node *head, *tail;
    public:
        linked_list(){
            head = NULL;
        tail = NULL;
        }
        
        void add(int x)
        {
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        void display()
        {
            if(head == NULL)
            return;
             node *temp = new node;
             temp = head;
             while(temp!=NULL)
             {
                 cout<<temp->data<<endl;
                 temp = temp->next;
             }
            
        }
        void delete_node(int p)
        {
             node *temp = new node;
             temp = head;
             if(head ==NULL)
             {
                 return;
             }
             else if(head->data ==p)
             {
                 node *temp = new node;
                 temp = head;
                 head = head->next;
                 free(temp);
             }
             else
             {
                  node *temp = new node;
                    temp = head;
                 while(temp!=NULL)
                 {
                     if(temp->next->data==p)
                     {
                         
                         if(temp->next ==tail)
                         {
                             temp->next = NULL;
                             tail = temp;
                             break;
                         }
                         else
                         {
                             node *temp1 = new node;
                             temp1 = temp->next;
                             temp->next = temp->next->next;
                             free(temp1);
                             break;
                         }
                         
                     }
                     temp = temp->next;
                 }
             }
        }
        void swap()
        {
            node *temp = new node;
            temp = head;
            while(temp!=NULL)
            {
                int a = temp->data;
                int b = temp->next->data;
                temp->next->data= a;
                temp->data = b;
                temp = temp->next->next;
            }
        }
        void front()
        {
            if(head==NULL || (head==tail))
            {
              return;  
            }
            else
            {
                node *temp =  new node;
                node *temp1 =  new node;
                node *temp2 =  new node;
                temp =  head;
                temp1 = tail;
                temp2->data = head->data;
                tail->next = head->next;
                head = tail;
                while(temp->next!=temp1)
                {
                    temp = temp->next;
                }
                temp->next = temp2;
                tail = temp2;
            }
        }
        void middle()
        {
            node *slow_ptr = head;  
            node *fast_ptr = head;  
          
            if (head!=NULL)  
            {  
                while (fast_ptr != NULL && fast_ptr->next != NULL)  
                {  
                    fast_ptr = fast_ptr->next->next;  
                    slow_ptr = slow_ptr->next;  
                }  
              cout<<"The middle element is "<<slow_ptr->data<<endl;
            }  
            
        }
    
};

int main() {
	linked_list l;
	l.add(4);
	l.add(5);
	l.add(6);
	l.add(7);
	//l.display();
	//l.delete_node(4);
	//l.display();
	//l.swap();
	//l.front();
	l.middle();
	l.display();
}