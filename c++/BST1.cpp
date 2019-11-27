#include<iostream>
using namespace std;
template <typename V>
struct node
{
    V data;
    node *left;
    node *right;
};
template<typename T>
class BST
{
	node<T> *R;
public:
	BST()
	{
		R=NULL;//root
	}
	bool insert(T b)
	{
		node<T> *t=new node<T>;
		if(t==NULL){cout<<" out of memory "; return false;}
		t->data=b;
		t->left=NULL;
		t->right=NULL;
		if(R==NULL)
		{
			R=t;
			return true;
		}
		else
		{
			node<T> *d=R;
			int f=0;
			while(f==0)
			{
				if ((t->data)==(d->data))
				{
					(t->left)=(d->left);
					(d->left)=t;
					f=1;
				}
				else if ((t->data)>(d->data))
				{
					if ((d->right)==NULL)
					{
						(d->right)=t;
						f=1;
					}
					else
					{
						d=(d->right);
					}
				}
				else if ((t->data)<(d->data))
				{
					if ((d->left)==NULL)
					{
						(d->left)=t;
						f=1;
					}
					else
					{
						d=(d->left);
					}
				}

			}
			return ((f==1)?true:false);
		}

	}
	bool Search(T b)
	{
	    node<T> *t;
	    return search (b,t);
	} 
	bool search(T b,node<T> *&p)
	{
		p=NULL;
		if(R==NULL)
		{

			cout<<" empty tree ";
			return false;
		}
		int f=0;
		node<T> *d=R;
		while(f==0)
		{
			if ((d->data)==b)
			{
				p=d;
				return true;
			}
			if ((d->data)<b)
			{
				if((d->right)==NULL)
				{
					cout<<" leaves reached, not found ";f=1;
					return false;
				}
				else
				{
					d=(d->right);
				}
			}
			if ((d->data)>b)
			{
				if((d->left)==NULL)
				{
					cout<<" leaves reached, not found ";f=1;
					return false;
				}
				else
				{
					d=(d->left);
				}
			}
		}
		return false;
	}
	bool delrec(node<T> *&r,int x)
	{
		node<T> *t;int tmp;
		if(r==NULL)
		{
			//cout<<" empty tree ";
			return false;
		}
		if(x==r->data)
		{
			if ((r->left)==NULL)
			{
				t=r;
				r=r->right;
				delete(t);
				return true;
			}
			if ((r->right)==NULL)
			{
				t=r;
				r=r->left;
				delete(t);
				return true;
			}
			else
			{
				t=r->right;
				while((t->left)!=NULL)
				{
					t=t->left;
				}
				tmp=(r->data);
				(r->data)=(t->data);
				(t->data)=tmp;
				return delrec(r->right,t->data);
			}
		}
		if(x>r->data)
		{
			return delrec(r->right,x);
		}
		if(x<r->data)
		{
			return delrec(r->left,x);
		}
		else
		{return false;}
	}

	bool del(T b)
	{
		if(R==NULL)
		{cout<<" empty tree ";return false;}
		return delrec(R,b);
	}
	bool findmin(T &b)
	{
		if(R==NULL)
		{cout<<" empty tree ";return false;}
		b=0;
		node<T> *d=R;
		while((d->left)!=NULL)
		{
			d=d->left;
		}
		b=d->data;
		return true;
	}
	bool findmax(T &b)
	{
		if(R==NULL)
		{cout<<" empty tree ";return false;}
		b=0;
		node<T> *d=R;
		while((d->right)!=NULL)
		{
			d=d->right;
		}
		b=d->data;
		return true;
	}
	bool empty(node<T> *&r)
	{
		if(r==NULL)
		{
			return true;
		}
		bool c;
		node<T> *t=r;
		if((t->left)!=NULL)
		{
			c=empty((t->left));
		}
		//if(c){cout<<" deleted left";}
		if((t->right)!=NULL)
		{
			c=empty((t->right));
		}
		//if(c){cout<<" deleted right";}
		cout<<" del "<<t->data<<endl;
		delete (t);
		
		return true;
	}

	~BST()
	{
		bool c=empty(R);
	}



	void print()
	{
		if (R==NULL)
		{
			cout<<" empty tree"<<endl;
			return ;
		}
		cout<<endl<<" printing ";
		bool c=inorder(R);
		cout<<endl;
	}
	bool inorder(node<T> *r)
	{
		bool c;
		if ((r->left)!=NULL)
		{
			c=inorder((r->left));
		}
		cout<<" "<<(r->data);
		if((r->right)!=NULL)
		{
			c= inorder((r->right));
		}

	}
};

int main()
{
	//BST<int> tree;
	BST<int> l1;
	bool c;
	int a,b;
    
    cout<<"  \n  1.insert 2.delete 3.search \n  4.find min 5.find max \n  6.print in order 0.exit \n ";
    do 
    {
        cout<<" _:" ;
        cin>>a;
        switch(a)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                cout<<" number";cin>>b;
                c=l1.insert(b);
                if (c){cout<<" s";}
                else {cout<<" failed";}
                break;
            }
        case 2:
            {
                cout<<" number";cin>>b;
                c=l1.del(b);
                if (c){cout<<" deleted "<<b<<" ";cout<<" s";}
                else {cout<<" failed";}
                break;
            }
        case 3:
            {
                cout<<" number";cin>>b;
                c=l1.Search(b);
                if (c){cout<<" found "<<b<<" ";cout<<" s";}
                else {cout<<b<<" not in tree";}
                break;
            }
        case 4:
            {
                c=l1.findmin(b);
                if (c){cout<<" min "<<b<<" ";cout<<" s";}
                else {cout<<" failed";}
                break;
            }
        case 5:
            {
                c=l1.findmax(b);
                if (c){cout<<" max "<<b<<" ";cout<<" s";}
                else {cout<<" failed";}
                break;
            }
        case 6:
            {
                l1.print();
                break;
            }
        default :
            {
                cout<<" invalid input ";
            }
        
        }
        
    }while (a!=0);
	/*
	c=tree.del(2);
	c=tree.del(2);
	c=tree.insert(12);
	c=tree.insert(5);
	c=tree.insert(20);
	c=tree.insert(22);
	c=tree.insert(19);
	tree.print();
	tree.del(5);
	tree.print();
	tree.del(12);
	tree.print();
	tree.del(20);
	tree.print();
	tree.del(22);
	tree.print();
	tree.del(19);
	tree.print();
	tree.del(22);

	tree.print();
	*/
/*	node<int> *d;
	cout<<" s"<<tree.search(7,d);
	cout<<" d"<<((d==NULL)?0:1);
	cout<<" s"<<tree.search(20,d);
	cout<<" d"<<(d->data);*/

}
