#include <iostream>
#include <string.h>
using namespace std;

 struct node
   {
       int id;
       char name[30];
       int age;
       node* prev;
       node* next;
   };

   class linkedlist
   {

        node* head;
        node* tail;

    public:
        linkedlist()
        {
            head = tail = NULL;
        }

        void append ( int _id , char _name[] ,int _age)
        {
            node * temp = new node();
            temp -> id = _id;
            strcpy (temp ->name , _name);
            temp -> age = _age;
            temp ->prev  = temp -> next = NULL;
            if (head == NULL)
                head = tail = temp;
            else
            {
               temp ->prev = tail;
                tail->next = temp;
                tail = temp;
            }

        }
        void display()
        {
            node* temp = head;
            while (temp != NULL)
            {
                cout <<"id : " << temp ->id << "\t" << "name : " << temp ->name <<"\t" <<"age = " << temp ->age <<"\n" ;
                temp = temp ->next;
            }
        }
        int countN()
        {
            int n =0;
            node * temp = head;
            while (temp != NULL)
            {
                n++;
                temp = temp ->next;
            }
            cout << "\n count :"<<n <<"\n";
            return n;
        }
        node* searchbyId(int _id)
        {
            node *temp = head;
            while (temp != NULL)
            {
                if (temp ->id == _id)
                {
                    //cout<< "temp : " <<"\n id = "<< temp->id <<"\t name = " << temp->name <<"\t age = " <<temp ->age<<"\n";
                    return temp;
                }
                temp = temp->next;
            }

        }

        node* searchbyName(char _name[])
        {
            node *temp = head;
            while (temp != NULL)
            {
                if (strcmp(temp ->name, _name)==0)
                {
                    cout<< "temp : " <<"\n id = "<< temp->id <<"\t name = " << temp->name <<"\t age = " <<temp ->age;
                    return temp;
                }
                temp = temp->next;
            }

        }
        void deleteN(int _id)
        {
            node *temp = searchbyId(_id);
            if (head == NULL)
                return;
            if(head == tail)
            {
                head = tail = NULL;
                delete temp;
            }
            if(head == temp)
            {
                head = head->next;
                head ->prev = NULL;
                delete temp;
            }
            if(tail == temp)
            {
                tail = tail ->prev;
                tail ->next = NULL;
                delete temp;
            }

        }

        void insertN(int _id , char _name[], int _age , int whId)
        {

                node * temp = searchbyId(whId);
                node *t = new node();
                t-> id = _id;
                strcpy (t->name , _name);
                t -> age = _age;
                if(temp == head )
                {

                    head ->prev = t;
                    t->next =head;
                    t->prev =NULL;
                    head= t;
                }
                else
                {


                    t ->next = temp;
                    t->prev = temp ->prev;
                    t->prev->next = t ;
                    temp ->prev = t;
                }




        }


   };


int main()
{
    linkedlist l1;
    l1.append(0 ,"hadeer",23);
    l1.append(1 ,"nora",21);
    l1.append(2 ,"fatma",22);
    l1.display();

    l1.countN();
    //l1.searchbyId(2);
    //l1.searchbyName("hadeer");
    //l1.deleteN(0);
   // l1.display();


    l1.insertN(4 ,"sara",20 ,0);
    l1.display();

    return 0;
}
