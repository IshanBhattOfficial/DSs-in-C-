#include<iostream>
#include<stdlib.h>
using namespace std;

class sll
{
  int info;
  sll *next;
  public:
    static int count;
    sll(int n=0)
    {
        info=n;
        next=NULL;
        count++;
    }
    void create(sll* &first);
	void traverse(void);
	void append_node(sll *new_node);
	int insert_after(int n,sll *new_node);
	sll* insert_node_first(sll *new_node);
	void insert_node_at_location(sll *new_node,int location);
	void update_node(int old_info,int new_info);
	int delete_node(int n,sll *first);
	sll* second_node(void);
    void sort_list(void);
    void search_list(int n);
};
int sll::count;

void sll::create(sll* &first)
{
    int in;
    int n;
    cout<<"Enter number of link list to create : ";
    cin>>n;
    cout<<"Enter info for node 1 : ";
    cin>>in;
    first= new sll(in);
    sll* p;
    p=first;

    for(int i=2;i<=n;i++)
    {
        cout<<"Enter info for node "<<i<<": ";
        cin>>in;
        p->next=new sll(in);
        p=p->next;
    }
    p=NULL;

}

void sll::traverse(void)
{
  	sll *trav_ptr=this;
	while(trav_ptr != NULL)
	{
  		cout<<trav_ptr->info<<'\t';
		trav_ptr=trav_ptr->next;
	}
}

void sll::append_node(sll *new_node)
{
  	sll *trav_ptr=this;
	while(trav_ptr->next != NULL)
	{
  		trav_ptr=trav_ptr->next;
	}
	trav_ptr->next = new_node;
}

int sll::insert_after(int n,sll *new_node)
{
	sll *trav_ptr=this;
	sll *trav_prev;
	while(trav_ptr != NULL)
	{
        if(trav_ptr->info==n)
			break;
		trav_prev=trav_ptr;
		trav_ptr=trav_ptr->next;
	}

	if(trav_ptr != NULL)
	{
  		new_node->next=trav_ptr->next;
		trav_ptr->next=new_node;
		return 0;
	}
	else
	{
        trav_prev->next=new_node; //append_node(new_node);
		return 1;
	}

}

sll* sll::insert_node_first(sll *new_node)
{
        sll *trav_ptr= this;
        new_node->next=trav_ptr;
        return new_node;
}

void sll::insert_node_at_location(sll *new_node,int location)
{
    int counter=0;
    sll *trav_ptr=this;
    sll *trav_ptr_prev;
    while(trav_ptr!=NULL)
    {
        counter++;
        if(location==counter)
        {
            break;
        }
        trav_ptr_prev=trav_ptr;
        trav_ptr=trav_ptr->next;
    }
    if(trav_ptr!=NULL)
    {
        new_node->next=trav_ptr;
        trav_ptr_prev->next=new_node;
    }
}

void sll::update_node(int old_info,int new_info)
{
 	sll *trav_ptr=this;
	while(trav_ptr != NULL)
	{
		if(trav_ptr->info == old_info)
			trav_ptr->info = new_info;
		trav_ptr=trav_ptr->next;
	}
}

sll* sll:: second_node(void)
{
	sll *trav_ptr=this;
	free(trav_ptr);
	return trav_ptr->next;

}

int sll::delete_node(int n,sll *first)
{
	sll *trav_ptr=this;
	sll *trav_prev;

	if(first->info==n)//first node
    {
        /*trav_ptr=first;
        first=first->next;
        free(trav_ptr);
        first->traverse();*/
        count=count-2;
        return 2;
    }
    else
    {
        while(trav_ptr != NULL)
        {
            if(trav_ptr->info==n)
                break;
            trav_prev=trav_ptr;
            trav_ptr=trav_ptr->next;
        }

        if(trav_ptr != NULL)
        {
            trav_prev->next=trav_ptr->next;
            //free(new sll(info));
            free(trav_ptr);
            count=count-2;
            return 0;
        }
        else
                return 1;
    }



}

void sll:: sort_list(void)
{
 	sll* trav_ptr1=this;
	sll* trav_ptr2=trav_ptr1->next;
	while(trav_ptr1->next != NULL)
	{
		while(trav_ptr2 != NULL)
		{
			if(trav_ptr1->info > trav_ptr2->info)
			{
				int temp = trav_ptr1->info;
				trav_ptr1->info = trav_ptr2->info;
				trav_ptr2->info= temp;
			}
            trav_ptr2=trav_ptr2->next;
		}
		trav_ptr1=trav_ptr1->next;
		trav_ptr2=trav_ptr1;
	}
}

void sll::search_list(int n)
{
	sll* trav_ptr=this;
	int flag=0,count=0;
	while(trav_ptr != NULL)
	{
		count++;
		if(trav_ptr->info==n)
		{
			flag=1;
			break;
		}
		trav_ptr=trav_ptr->next;
	}
	if(flag==1)
	{
		cout<<"NODE IS FOUND AT LOCATION "<<count<<endl;
	}
	else
	  	cout<<"NODE IS NOT FOUND !!"<<endl;
}

main()
{
    int choice;
    sll *first;
    next:

    cout<<endl<<"PRESS 0 : FOR CREATE LIST"<<endl;
    cout<<"PRESS 1 : FOR LISTING ALL NODES "<<endl;
    cout<<"PRESS 2 : APPEND NEW NODE "<<endl;
    cout<<"PRESS 3 : INSERT NEW NODE AFTER OTHER NODE "<<endl;
    cout<<"PRESS 4 : INSERT NEW NODE AT PARTICULAR LOCATION"<<endl;
    cout<<"PRESS 5 : UPDATE NODE"<<endl;
    cout<<"PRESS 6 : DELETE NODE "<<endl;
    cout<<"PRESS 7 : SORT LIST"<<endl;
    cout<<"PRESS 8 : SEARCH LIST"<<endl;
    cout<<"PRESS 9 : FOR EXIT "<<endl;


    cout<<"ENTER YOUR CHOICE : ";
    cin>>choice;

	switch(choice)
	{
	    case 0:
        {
            first->create(first);
            first->traverse();
            break;
        }
   		case 1:
		{
  			first->traverse();
			break;
		}
		case 2:
		{
 			int in;
			cout<<"Enter info for new node : ";
			cin>>in;
			sll *append_node=new sll(in);
			first->append_node(append_node);
			first->traverse();
			break;
		}
		case 3:
		{
 			int new_in,old_in;
			int ans;
			cout<<"Enter info for new node : ";
			cin>>new_in;
			cout<<"Enter a info of old node after which you want to insert new node : ";
			cin>>old_in;
			sll *insert_node=new sll(new_in);
			ans=first->insert_after(old_in,insert_node);
			if(ans==0)
				cout<<"OLD NODE IS FOUND !!"<<endl;
			else
				cout<<"OLD NODE IS NOT FOUND !! :--> NEW NODE IS APPENDED "<<endl;
			first->traverse();
			break;
		}
        case 4:
		{
			cout<<"Total number of nodes : "<<first->count<<endl;
			int location,new_in;
			cout<<"Enter the location to enter new node : ";
			cin>>location;
			cout<<"Enter info for new node which will be inserted at given location : ";
			cin>>new_in;
			sll *new_node=new sll(new_in);
			if(location==1)
			{
				sll *temp=first->insert_node_first(new_node);
				if(temp!= NULL)
				first=temp;
			}
			else
			{
			 	first->insert_node_at_location(new_node,location);
			}
			first->traverse();
			break;

        	}
		case 5:
		{
			int old_in,new_in;
			cout<<"Enter old node info which will be updated : ";
			cin>>old_in;
			cout<<"Enter new info : ";
			cin>>new_in;

			first->update_node(old_in,new_in);
			first->traverse();
			break;
		}
		case 6:
		{
 			int in;
			cout<<"Enter info for node to be delete : ";
			cin>>in;

			int ans=first->delete_node(in,first);
			if(ans==0)
				cout<<"NODE IS FOUND AND DELETED!!"<<endl;
			else if(ans==1)
				cout<<"NODE IS NOT FOUND !!"<<endl;
            else
            {
                sll *temp=first->second_node();
                if(temp != NULL)
                    first=temp;
            }
			first->traverse();
			break;
		}
		case 7:
		{
			first->sort_list();
			first->traverse();
			break;
		}
		case 8:
		{
 			int in;
			cout<<"Enter info for node to be search : ";
			cin>>in;
			first->search_list(in);
			break;
		}
		case 9:
		{
			exit(0);
			break;
		}


	}

        goto next;


}
