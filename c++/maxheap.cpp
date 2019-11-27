#include<iostream>
#include<math.h>
using namespace std;
template<typename T>
struct node
{
	int priority ;
	T data;
	
};
template<typename T>
class heap
{
	node<T> *arr;
	int len;
	int n;
	bool ismaxheap;
	//using array from index 1 !!
public:
	heap()
	{
		len=1;
		arr =new node<T> [len+1];
		
		n=0;
		ismaxheap=true;
	}
	heap(int l,bool mxh=true)
	{
		ismaxheap=mxh;
		len=l;
		arr =new node<T> [len+1];
		
		n=0;
		//ismaxheap=true;
	}
	
	heap(int ar[],int len2,int start,bool mxh=true)
	{
		ismaxheap=mxh;
		//delete ar outside this method
		copyarr(ar,len2,start,len2);
	}
	
	double logn(int n,double d)
	{
		return log(d)/log(n);
	}
	void copyarr(node<T> ar[],int end,int start,int target_len)
	{
		/*
		input ar is copied into internal arr allocated to fit target_len
		*/
		/* ARGS
		input array,
		index of ar to copy untill,
		start index to copy from,
		new maximum length 
		*/
		// NOTE delete old ar pointer outside this method
		int limit=end-start;
		//cout<<" lim "<<limit;
		if (((end<0)||(start<0)||(limit<0)))//target_len<limit+1)||
		{return;}
		
		int new_len=pow(2,ceil(logn(2,limit+2)));
		//cout<<" new len "<<new_len;
		//if internal length is already bigger use len ?
		node<T> *tempar =new node<T> [new_len+1];//starting one thing so +1
		
		for(int i=0;i<=limit;i++)
		{
			tempar[1+i]=ar[start+i];
		}
		arr=tempar;
		len=new_len;
		n=limit+1;
		
		
		//convert array with start to array starting from 1
	}
	void resizearr(int target_len)
	{
		node<T> *tempar=arr;
		copyarr(arr,n,1,target_len);
		delete(tempar);
	}
	
	/* void resizearr(int target_len)
	{
		node<T> *tmp =new node<T> [target_len+1];
		for (int i=1;i<=n;i++)
		{
			tmp[i]=arr[i];
			cout<<" r"<<tmp[i].data<<arr[i].priority;
		}
		int new_l=pow(2,ceil(logn(2,target_len+1)));
		arr =new node<T> [new_l];
		for (int i=1;i<=n;i++)
		{
			arr[i]=tmp[i];
		}
		len =new_l;
		
	} */
	
	int child1(int i)
	{
		if((i<1)||(i>len)||((2*i)>n))
		{return -1;}
		/* if ((2*i)>len)
		{
			node<T> *tmparr=arr;
			copyarr(arr,n,1,(2*i));
			delete(tmparr);
			
		} */
		return 2*i;
		
	}
	int child2(int i)
	{
		if((i<1)||(i>len)||(((2*i)+1)>n))
		{return -1;}
		/* if (((2*i)+1)>len)
		{
			node<T> *tmparr=arr;
			copyarr(arr,n,1,((2*i)+1));
			delete(tmparr);
			
		} */
		return (2*i)+1;
		
	}
	int parent (int i)
	{
		if ((i<=1)||(i>len))
		{return -1;}
		return floor((i/2));
	}
	
	
	void heapify(int i)
	{
		int par=parent (n);
		if((i<1)||(i>len))
		{ return ; }
		//if(i>par)//i> last row of parents 
		//or if i is just > len error
		//{
			//cout<<" child nodes ";
			//return ;
		//}
		
		int ch1=child1(i),ch2=child2(i);
		if((ch1<1)&&(ch2<1))//ie dont exist returns bad index
		{
			return ;
		}
		int ch;
		if(ismaxheap)
		{ch= (arr[ch1].priority>arr[ch2].priority)?ch1:ch2;}//max
		else
		{ch= (arr[ch1].priority<arr[ch2].priority)?ch1:ch2;}//min 
		
		if(ch2<1)
		{
			ch=ch1;
		}
		else if(ch1<1)
		{
			ch=ch2;
		}
		/* cout<<"\n c1 "<<ch1<<',';
		if(ch1<1){cout<<cout<<"-1";}
		else {cout<<arr[ch1].priority;}
		cout<<"; c2 "<<ch2<<',';
		if(ch2<1){cout<<cout<<"-1";}
		else {cout<<arr[ch2].priority;}
		cout<<"; ch "<<ch; */
		if((ismaxheap&&(arr[ch].priority>arr[i].priority))||((!ismaxheap)&&(arr[ch].priority<arr[i].priority)))
			//if(arr[ch].priority>arr[i].priority)
		{
			//cout<<'s';
			//swap
			node<T> t=arr[ch];
			arr[ch]=arr[i];
			arr[i]=t;
			//maxheap lower level 
			heapify(ch);
		}
		return ;
	}
	void buildmaxheap()
	{
		int par=parent (n);
		for(int i=n;i>0;i--)
		{
			heapify(i);
		}
	}
	void heapinsertnode(node<T> t)
	{
		heapinsert(t.priority,t.data);
	}
	void heapinsert(int pri,T dat)
	{
		//cout<<"\n inserting "<<dat;
		if (n+1>=len)
		{
			resizearr(n+1);
			//cout<<"\n resizeto"<<len;
		}
		n++;
		int i=n;
		arr[i].priority=pri;
		arr[i].data=dat;
		//i=parent(n);
		
		//printheap();
		//cout<<"\n inserted";
		while (i>0)
		{
			//cout<<"\n  heapify i "<<i;
			heapify (i);
			i=parent(i);
		}
	}
	void heapincreasekey(int i, int k)
	{
		if((i>n)||(i<0))
		{return;}
		arr[i].priority=(arr[i].priority>k)?arr[i].priority:k;
		if(!ismaxheap)
		{
			heapify(i);//min heap increased value goes down 
		}
		else
		{
			//max heap increased value goes up
			int j=parent(i);
			while (j>0)
			{
				cout<<"\n j"<<j;
				heapify (j);
				j=parent(j);
			}
		}
	}
	void heapdecreasekey(int i, int k)
	{
		if((i>n)||(i<0))
		{return;}
		arr[i].priority=(arr[i].priority<k)?arr[i].priority:k;
		if(ismaxheap)
		{
			heapify(i);//max heap decreased value goes down 
		}
		else
		{
			//min heap decreased value goes up
			int j=parent(i);
			while (j>0)
			{
				heapify (j);
				j=parent(j);
			}
		}
	}
	void heapsort ()
	{
		int n_tmp=n;
		for (int i=1;i<=n_tmp;i++)
		{
			node<T> t=arr[1];
			arr[1]=arr[n];
			arr[n]=t;
			n--;
			heapify(1);
		}
		n=n_tmp;
		cout<<"\n heap sort :";
		for (int i=1;i<=n;i++)
		{
			cout<<" "<<arr[i].data;
		}
	}
	void heapextract(T &x)
	{
		x=arr[1].data;
		arr[1]=arr[n];
		n--;
		heapify(1);
	}
	void heappeek(T &x)
	{
		x=arr[1].data;
	}
	void printheap()
	{
		//cout<<"\n Top";
		//cout<<len<<','<<n;
		cout<<" \n";
		
		for (int i=1,j=0;i<=n;i++)
		{
			cout<<" "<<arr[i].data;
			if(i==(pow(2,j+1)-1))
			{
				cout<<'\n';
				j++;
			}
		}
		if(n<1){cout<<" E";}
		cout<<"\n ----";
	}
	
	
	
	
	
	
	
	
};

int main()
{
	//heap<int> h1(22,false);
	heap<int> h1(22);
	h1.printheap();
	h1.heapinsert(9,9);
	h1.printheap();
	h1.heapinsert(8,8);
	h1.printheap();
	h1.heapinsert(1,1);
	h1.printheap();
	h1.heapinsert(2,2);
	h1.printheap();
	h1.heapinsert(19,19);
	h1.printheap();
	h1.heapinsert(18,18);
	h1.printheap();
	h1.heapinsert(11,11);
	h1.printheap();
	h1.heapinsert(12,12);
	//h1.buildmaxheap();
	h1.printheap();
	h1.heapsort();
	h1.printheap();
	h1.buildmaxheap();
	h1.heapdecreasekey(7,0);
	h1.printheap();
	
	
	cout<<'\n';
	int v;
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	h1.heapextract(v);
	cout<<v;
	h1.printheap();
	
	
}