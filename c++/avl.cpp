#include<iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    int height;
	node *left;
    node *right;
};
template <typename T>
class AVL
{
	node<T> *R;
public:
	AVL()
	{
		R=NULL;
	}
	int getheight(node<T> *x)
	{
		if(x==NULL){return 0;}
		int r=getheight(x->right),l=getheight(x->left);
		return 1+((l>r)?l:r);
	}
	bool rightsingle(node<T> *&x)
	{
		if((x==NULL)||((x->left)==NULL))
		{return false;}
		node<T> *t=(x->left);
		(x->left)=(t->right);
		(t->right=x);
		(x->height)=getheight(x);
		(x->height)=getheight(x);
		x=t;
		return true;
	}
	bool leftsingle(node<T> *&x)
	{
		if((x==NULL)||((x->right)==NULL))
		{return false;}
		node<T> *t=(x->right);
		(x->right)=(t->left);
		(t->left=x);
		(x->height)=getheight(x);
		(t->height)=getheight(t);
		x=t;
		return true;
	}
	bool rightdouble(node<T> *&x)
	{
		if(leftsingle(x->left))
		{return rightsingle(x);}
		return false;
	}
	bool leftdouble(node<T> *&x)
	{
		if(rightsingle(x->right))
		{return leftsingle(x);}
		return false;
	}
	bool insert(node<T> *&x ,T b)
	{
		
		bool c;
		node<T> *d =new node<T>;
		if(d==NULL){cout<<" no memory";return false;}
		//test();
		(d->data)=b;
		(d->right)=NULL;
		(d->left)=NULL;
		(d->height)=getheight(d);
		//cout<<" d"<<(d->data)<<"d ";
		if (x==NULL)
		{
			x=d;
			return true;
		}
		
		if(b<=(x->data))
		{
			if((x->left)==NULL)
			{ (x->left)=d;return true;}
			else
			{
				 c=insert((x->left),b);
			}
						if(((getheight(x->right))-(getheight(x->left))==2)||((getheight(x->right))-(getheight(x->left))==-2))
			{
				if(b<=(x->left->data))
				{c=rightsingle(x);}
				if(b>(x->left->data))
				{c=rightdouble(x);}
			}
			return c;
		}
		if(b>(x->data))
		{
			if((x->right)==NULL)
			{ (x->right)=d;return true;}
			else
			{
				bool c=insert((x->right),b);
			}
						if(((getheight(x->right))-(getheight(x->left))==2)||((getheight(x->right))-(getheight(x->left))==-2))
			{
				if(b<=(x->right->data))
				{c=leftdouble(x);}
				if(b>(x->right->data))
				{c=leftsingle(x);}
			}
			return c;
		}
		// ╔══════════════════════════════╗
		// ║                              ║
		// ║  PASS node-> INSTEAD OF node ║
		// ║                              ║
		// ╚══════════════════════════════╝
		
		
	}
	bool insertval(T b)
	{return insert(R,b);}
	
	void postorder(node<T> *x,int n,int d)
	{
		
		
		if ((x==NULL)||(n==0))
		{
			cout<<endl;
			for(int i=0;i<n;i++)
            {cout<<"\t";}
			cout<<"  N"<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
			if(d==-1)
            {
                cout<<char(187);
            }
            if(d==1)
            {
                cout<<char(188);
            }
			return ;
			//cout<<endl;
		}
		
		//if((x->right)!=NULL)
		{postorder((x->left),n-1,-1);}
		cout<<endl;
		for(int i=0;i<n;i++)
		{cout<<"\t";}
		cout<<char(204)<<char(205)<<(x->data);
		int q=1,p;
		for (int i=1;i<=5;i++)
        {
            q*=10;
            if((x->data)%(q)==(x->data))
            {
                p=i;break;
            }
        }
        for (int i=p;i<=5;i++)
		{cout<<char(205);}
		//if((x->left)!=NULL)
            if(d==-1)
            {
                cout<<char(187);
            }
            if(d==1)
            {
                cout<<char(188);
            }
            
		{postorder((x->right),n-1,1);}
		
	}
	void print ()
	{cout<<"\n print ";postorder(R,getheight(R),0);cout<<endl;}
	
	void test()
	{ if(R==NULL){cout<<endl<<'N';return;}cout<<endl<<"  "<<(R->data)<<" "<<(R->left)<<" "<<R<<" "<<(R->right);}
	
	
	bool delrec(node<T> *&r,int x)
	{
		node<T> *t;int tmp;
		if(r==NULL)
		{
			cout<<" empty tree ";
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
				bool c= delrec(r->right,t->data);
				
			}
			if((getheight(r->right))-(getheight(r->left))==2)
			{
				return leftsingle(r);
			}
			if((getheight(r->right))-(getheight(r->left))==-2)
			{
				return rightsingle(r);
			}
		}
		bool c;
		if(x>r->data)
		{
			c= delrec(r->right,x);
		}
		if(x<r->data)
		{
			c= delrec(r->left,x);
		}
		
		if((getheight(r->right))-(getheight(r->left))==2)
		{
			return leftsingle(r);
		}
		if((getheight(r->right))-(getheight(r->left))==-2)
		{
			return rightsingle(r);
		}
		
		else
		{return false;}
	}
	
	bool del(T b)
	{
		return delrec(R,b);
	}
	
};

int main ()
{
	AVL<int> tree;
	bool c;
	cout<<"tree"<<endl;
	cout<<tree.insertval(1);
	//tree.test();
	tree.print();
	cout<<tree.insertval(2);
	//tree.test();
	tree.print();
	cout<<tree.insertval(9);
	//tree.test();
	tree.print();
	cout<<tree.insertval(7);
	//tree.test();
	tree.print();
	cout<<tree.insertval(3);
	//tree.test();
	tree.print();
	cout<<tree.insertval(7);
	//tree.test();
	tree.print();
	cout<<tree.insertval(3);
	//tree.test();
	tree.print();
	cout<<tree.del(2);
	//tree.test();
	tree.print();
	cout<<tree.del(5);
	//tree.test();
	tree.print();
	cout<<tree.del(3);
	//tree.test();
	tree.print();
	cout<<tree.del(9);
	//tree.test();
	tree.print();
	cout<<tree.del(1);
	//tree.test();
	tree.print();
	cout<<tree.del(7);
	//tree.test();
	tree.print();
	cout<<tree.del(7);
	//tree.test();
	tree.print();
	
}