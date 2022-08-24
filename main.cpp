/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<string>
using namespace std;
struct Node{
   string name,number;
   Node* next;
};
Node*head=0,*temp;
void create_contact(){
    Node* newnode=new Node();
    cout<<"Enter Name: ";
    cin>>newnode->name;
    cout<<"Enter Number: ";
    cin>>newnode->number;
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
         temp->next=newnode;
         temp=newnode;
    }
}
void show_list(){
    Node* show=head;
    int i=1;
    if(head==0)
    {
        cout<<"List is Empty"<<endl;
        
    }
    else
    {
        while(show!=0)
        {
            cout<<i<<":"<<"Name:"<<show->name<<endl;
            cout<<"Number: "<<show->number<<endl;
            show=show->next;
            i++;
        }
    }
    
}
void search_list(){
    string srch;
    cin>>srch;
    Node*search_node=head;
    if (head==0)
    {
        cout<<"List is Empty"<<endl;
        
    }
    else
    {
        while(search_node!=0)
        {
            if(srch==search_node->name || srch==search_node->number)
            {
                cout<<"Name:"<<search_node->name<<endl;
                cout<<"Number:"<<search_node->number<<endl;
               break;
            }
            else
            {
                 search_node=search_node->next;
            }
        }
    }
}
void update(){
    cout<<"Enter name or number , you want to update the details"<<endl;
    string s;
    cin>>s;
    Node* updt=head;
    if (head==0)
    {
        cout<<"List is Empty"<<endl;
        
    }
    else
    {
        while(updt!=0)
        {
            if(s==updt->name || s==updt->number)
            {
                break;
            }
            else
            {
                updt=updt->next;
            }
        }
    }
    cout<<"Edit Name:";
    cin>>updt->name;
    cout<<"Edit Number:";
    cin>>updt->number;
    cout<<"Contact has updated"<<endl;
}
void delete_list(){
    Node*dlt=head;
    cout<<"Enter name or number you want to delete from List"<<endl;
    int count=1;
    string d;
    cin>>d;
    Node*prev=0;
    
    if(head==0)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        while(dlt!=0)
        {
            if(d==dlt->name  || d==dlt->number)
            {
                break;
            }
            else
            {prev=dlt;
                dlt=dlt->next;
                count++;
            }
        }
    }
    if(dlt==0)
    {
        cout<<"Contact not Found"<<endl;
    }
    else if(count==1 && dlt->next==0)
    {
        head=0;
    }
    else if(count==1 && dlt->next!=0)
    {
        head=dlt->next;
    }
    
    else{
    prev->next=dlt->next;
    }
    
}
int main()
{bool operation=true;
   while(operation)
   {
       int op;
       cout<<"Enter 1 to add Contact"<<endl;
       cout<<"Enter 2 to show List"<<endl;
       cout<<"Enter 3 to Search Contact "<<endl;
       cout<<"Enter 4 to update contact Details"<<endl;
       cout<<"Enter 5 to delete contact from list"<<endl;
       cin>>op;
       switch(op)
       {
           case 1:
           create_contact();
           break;
           case 2:
           show_list();
           break;
           case 3:
           search_list();
           break;
           case 4:
           update();
           break;
           case 5:
           delete_list();
           break;
           default:
           operation=false;
           cout<<"Invalid"<<endl;
           
       }
   }

    return 0;
}
