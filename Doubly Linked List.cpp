#include <iostream>
#include <stdlib.h>
using namespace std;

class dlll{
    int data;
    dlll *next;
    dlll *prev;
public:
    dlll()
    {
        next=NULL;
        prev=NULL;
    }

    void appendNode(int info)
    {
        dlll *newNode=new dlll,*trav;
        int flag=0;
        trav=this;
        newNode->data=info;
        while(trav->next!=NULL)
        {
            flag=1;
            trav=trav->next;
        }

        trav->next=newNode;
        this->prev=newNode;
        if(flag!=0)
            newNode->prev=trav;
    }


    void travForward()
    {
        dlll *trav;
        trav=this;
        int flag=0;
        int count=1;
        while(trav->next!=NULL)
        {
            flag=1;
            trav=trav->next;
            cout << "data of the node " << count++ << " is " << trav->data << endl;
        }
        if(flag==0)
            cout << "list is empty\n";
    }

    void travBackward()
    {
        dlll *trav=this->prev;
        int flag=0;
        int count=1;
        while(trav!=NULL)
        {
            flag=1;
            cout << "data of the node " << count++ << " is " << trav->data << endl;
            trav=trav->prev;
        }
        if(flag==0)
        {
            cout << "list is empty\n";
        }
    }

    void addAfter(int info)
    {
        dlll *trav=this;
        while(trav->next!=NULL)
        {
            if(info==trav->data)
            {
                dlll *newNode=new dlll;
                cout << "enter the data of the new node \n" ;
                cin >> newNode->data;
                newNode->next=trav->next;
                trav->next=newNode;
                newNode->prev=trav;
                trav=newNode->next;
                trav->prev=newNode;
                return;
            }
            trav=trav->next;
        }
        if(trav->data==info)
        {
            cout << "enter the data of the new node \n" ;
            int num;
            cin >> num;
            this->appendNode(num);
            return;
        }
        cout << "node not found\n";
    }

    void addBefore(int info)
    {
        dlll *trav=this;

        while(trav->next!=NULL)
        {
            if(trav->data==info)
            {
                dlll *newNode=new dlll;
                cout << "enter the data of the node to be added\n";
                cin >> newNode->data;
                newNode->prev=trav->prev;
                trav->prev=newNode;
                trav=newNode->prev;
                if(trav==NULL)
                {
                    newNode->next=this->next;
                    this->next=newNode;
                    return;
                }
                newNode->next=trav->next;
                trav->next=newNode;
                return;
            }
            trav=trav->next;
        }
        if(trav->next==NULL && trav->data==info)
        {
                dlll *newNode=new dlll;
                cout << "enter the data of the node to be added\n";
                cin >> newNode->data;
                newNode->prev=trav->prev;
                trav->prev=newNode;
                trav=newNode->prev;
                newNode->next=trav->next;
                trav->next=newNode;
                return;
        }
        cout << "node not found\n";
    }

    void removeNode(int info)
    {
        dlll *trav=this;

        while(trav->next!=NULL)
        {
            if(trav->data==info)
            {
                dlll *temp;
                temp=new dlll;
                temp=trav;
                trav=trav->next;
                trav->prev=temp->prev;
                if(temp->prev==NULL)
                {
                    this->next=trav;
                    return;
                }
                temp=temp->prev;
                temp->next=trav;
                return;
            }
            trav=trav->next;
        }
        if(trav->next==NULL && trav->data==info)
        {
            this->prev=trav->prev;
            dlll *temp=trav;
            trav=trav->prev;
            if(trav==NULL)
            {
                this->next=NULL;
                return;
            }
            trav->next=NULL;
            delete temp;
            return;
        }
        cout << "node not found\n";
    }

    void updateNode(int info)
    {
        dlll *trav=this;

        while(trav->next!=NULL)
        {
            if(trav->data==info)
            {
                cout << "enter the new data\n";
                cin >> trav->data;
                return;
            }
            trav=trav->next;
        }
        if(trav->next==NULL && trav->data==info)
        {
            cout << "enter the new data\n";
            cin >> trav->data;
            return;
        }
        cout << "node not found\n";
    }
};

int main()
{
    dlll *head;
    head=new dlll;
    char ch;
    do{
        system("cls");
        cout << "\n\n\n\t\t0. Exit\n\n\t\t1. Append New Node\n\n\t\t2. Traverse Forward\n\n\t\t3. Traverse Backward\n\n\t\t4. Add After\n\n\t\t5. Add Before\n\n\t\t6. Remove Node\n\n\t\t7. Update the data of Node\n\n";
        cin >> ch;
        switch(ch){
            case('0'):
            {
                return 0;
                system("exit");
                break;
            }

            case('1'):
            {
                cout << "enter the number ";
                int num;
                cin >> num;
                head->appendNode(num);
                system("pause");
                break;
            }

            case('2'):
            {
                head->travForward();
                system("pause");
                break;
            }

            case('3'):
            {
                head->travBackward();
                system("pause");
                break;
            }

            case('4'):
            {
                cout << "enter the info\n";
                int num;
                cin >> num;
                head->addAfter(num);
                system("pause");
                break;
            }

            case('5'):
            {
                cout << "enter the info\n";
                int num;
                cin >> num;
                head->addBefore(num);
                system("pause");
                break;
            }

            case('6'):
            {
                cout << "enter the data of node to be removed\n";
                int num;
                cin >> num;
                head->removeNode(num);
                system("pause");
                break;
            }

            case('7'):
            {
                cout << "enter the data of the node to be updated\n";
                int num;
                cin >> num;
                head->updateNode(num);
                system("pause");
                break;
            }
        }
    }while(ch!='0');

    return 0;
}
