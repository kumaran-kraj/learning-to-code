#include<iostream>
#include<stdio.h>
using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;
};
template<typename U>
class linkedlist
{
    node<U> *a;
    int len;
public:
    linkedlist()
    {
        len=0;a=NULL;
    }
    bool insertbeg(U b)
    {
        node<U> *t=new node<U>;
        t->data=b;
        if(t==NULL){cout<<"no memory";return false;}
        if(isempty())
        {
            a=t;a->next=NULL;
            len++;
        }
        else
        {
            t->next=a;
            a=t;
            len++;
        }
        return true;
    }
    bool insertend(U b)
    {
        node<U> *t=new node<U>;
        t->data=b;
        if(t==NULL){cout<<"no memory";return false;}
        if(isempty())
        {
            a=t;a->next=NULL;
            len++;
        }
        else
        {
            node<U> *d;
            d=a;
            while (d->next!=NULL)
            {
                d=d->next;
            }
            d->next=t;
            t->next=NULL;
            len++;
        }
        return true;
    }
    bool insertat(U b,int n)
    {
         node<U> *t=new node<U>;
        t->data=b;
        if(t==NULL){cout<<"no memory";return false;}
        if(n<1){cout<<"wrong index"; return false;}
        if (n==1){return insertbeg(b);}
        if(n>len+1){cout<<"bad index";return false;}
        int pos=2;
        node<U> *d;
        d=a;
        while(pos<n)
        {
            if(d->next==NULL){cout<<" end reached unexpectedly ";break;}
            d=d->next;
            pos++;
        }
        t->next=d->next;
        d->next=t;
        len++;
        return true;
    }
    bool deletebeg(U &b)
    {
        if(a==NULL)
            {return false;}
        if(a->next==NULL)
            {node<U> *t=a;
            a=NULL; 
            b=t->data;
            delete t;
            len--; 
            return true;}
        else
        {
            node<U> *t=a;
            a=a->next; 
            b=t->data;
            delete t;
            len--;
            return true;
        }

    }
    bool deleteend(U &b)
    {
        if(a==NULL)
            {return false;}
        if(a->next==NULL)
        {
            node<U> *t=a;
            a=NULL; 
            b=t->data;
            delete t;
            len--; 
            return true;}
        node<U> *d;
        d=a;
        d=d->next;
        node<U> *t=a;
        while(d->next!=NULL)
        {
            d=d->next;
            t=t->next;
        }
        t->next=NULL;
        b=d->data;
        delete d;
        len--;
        return true;
    }
    bool deleteat(U &b,int n)
    {
        if(a==NULL)
            {cout<<" empty array ";return false;}
        if((n<1))
            {cout<<" bad index ";return false;}
        if (n==1)
        {
            return deletebeg(b);
        }
        else
        {
           //n--;
           node<U> *d;
           d=a;
           //d=d->next;
           node<U> *t;
           int pos=2;

           while(pos<n)
           {

               if (d->next==NULL){cout<<" bad index ";return false;}
               d=d->next;
               pos++;
           }
           t=d->next;
           d->next=t->next;
           b=t->data;
           delete t;
           return true;
        }

        return false;
    }
    bool elementat(U &b,int n)
    {
        if(a==NULL)
            {cout<<" empty array ";return false;}
        if((n<1))
            {cout<<" bad index ";return false;}
        if (n==1)
        {
            b=a->data;
            return true;
        }
        else
        {
           //n--;
           node<U> *d;
           d=a;
           //d=d->next;
           node<U> *t;
           int pos=2;

           while(pos<n)
           {

               if (d->next==NULL){cout<<" bad index ";return false;}
               d=d->next;
               pos++;
           }
           t=d->next;
           
           b=t->data;
           
           return true;
        }

        return false;
    }
    bool isempty()
    {
        return (a==NULL)?true:false;
    }
    void disp()
    {
        cout<<" printing";
        if(a==NULL)
            {cout<<" empty ";}
        else
        {
           node<U> *d;
           d=a;
           cout<<" "<<d->data;
           while(d->next!=NULL)
           {
                d=d->next;
               cout<<" "<<d->data;

           }
        }
        //cout<<endl;
    }
    int getlen()
    {
        return len;
    }
    ~linkedlist()
    {
        bool c;
        U b;
        while (!isempty())
        {
            c=deleteend(b);
        }
        //cout<<endl<<"list cleared from memory";
    }
};



enum colourflag{W,G,B};
struct Edge
{
	int u,v;
	int cost;
	colourflag colour;
};
struct Vertex
{
	int value;
	linkedlist<int> adjL;
	
	colourflag colour;
	
	int parent_index;
	int dist;//shortest dist to parent
	
	int Set;
	
	int st_time;
	int end_time;
	
};
class graph
{public:
	int **adjM;
	int Size,edges;
	Vertex *v;
	Edge *edgear;
	linkedlist<Edge> edgeList;
	graph()
	{
		Size=0;
		edges=0;
	}
	graph(int s)
	{
		Size=s;
		adjM =new int *[Size];
		for(int i=0;i<Size;i++)
		{
			adjM[i]=new int [Size];
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			adjM[i][j]=0;
			}
		}*/
		
	}
	graph(int **a,int s)
	{
		Size=s;
		adjM =new int *[Size];
		for(int i=0;i<Size;i++)
		{
			adjM[i]=new int [Size];
		}
		for(int i=0;i<Size;i++)
		{
			for(int j=0;j<Size;j++)
			{
                adjM[i][j]=a[i][j];
                
			}
		}
		
	}
	void setadjM()
	{
	    int q=0;
	    cout<<" 0 for directed 1 for undirected: ";
	    cin>>q;
	    cout<<"\n from,to:\n";
	    for(int i=0;i<Size;i++)
		{
			for(int j=0;j<Size;j++)
			{
                adjM[i][j]=INT_MAX;
                
                if(q>0)
                {
                    if(j>i)
                    {
                        continue;//dont do the other pairs
                    }
                }
                
                if(i==j){continue;}//leaves it as intmax
                
                cout<<i<<","<<j<<":";
                cin>>adjM[i][j];
                if(q>0)
                    {
                        adjM[j][i]=adjM[i][j];
                    }
                if(adjM[i][j]>=9999)
                {
                    adjM[i][j]=INT_MAX;
                    
                }
                
                
                else
                {
                    edges++;
                    Edge temp1;
                    temp1.u=i;
                    temp1.v=j;
                    temp1.cost=adjM[i][j];
                    temp1.colour=W;
                    edgeList.insertbeg(temp1);
                    //for undirected
                    if(q>0)
                    {
                        Edge temp1;
                        edges++;
                        temp1.u=j;
                        temp1.v=i;
                        temp1.cost=adjM[i][j];//same as [j][i]
                        temp1.colour=W;
                        edgeList.insertbeg(temp1);
                    }
                }
			}
		}
	}
	void edgesort()
	{
	    //cout<<" ed len"<<edgeList.getlen();
	    edgear =new Edge [edgeList.getlen()];
	    int i,j;
	    Edge key;
	    for(i=0;i<edgeList.getlen();i++)
        {
            edgeList.elementat(edgear[i],i+1);
        }
        for(i=0;i<edgeList.getlen();i++)
        {
            key=edgear[i];
            for (j=i-1;j>=0;j--)
            {
                if(edgear[j].cost>key.cost)
                {
                    edgear[j+1]=edgear[j];
                }
                else
                {
                    break;
                }
            }
            edgear[j+1]=key;
        }
	    
	}
	/*void initialize()
	{
	    for(int i=0;i<n;i++)
		{
			v.colour=W;
			v.parent_index=-1;
			v.dist=99999;
		}
	    
	}*/
	void constructgraph()
	{
	    v= new Vertex [Size];
        for(int i=0;i<Size;i++)
		{
			v[i].value=i;
			v[i].dist=INT_MAX;
			v[i].colour=W;
			v[i].parent_index=-1;
			v[i].Set=i;
			
			for(int j=0;j<Size;j++)
			{
                if(adjM[i][j]<9999)
                {
                    //v[i].adjL.insertbeg(adjM[i][j]);
                    v[i].adjL.insertbeg(j);
                }
                //cout<<i<<","<<j<<":";cin>>adjM[i][j];
			}
		}
	}
	
	/*void BFS(int i)
	`1234567890-=   qwertyuiop[]\AAasdfghjkl;'
	ZZzxcv,.
	{
	    v[i].colour=G;
	    v[i].dist=0;
        v[i].parent_index=-1;vbnmm,./
        
        linkedlist<int> Q;
        Q.insertend(i);
        int c,u;
        while(Q.deleteend(c))
        {
            for(int p=1;p<=v[c].adjL.getsize();p++)
            {
                if(v[c].adjL.elementat(u,p))
                {
                    v[u].colour=G;
                    v[u].dist=v[c].dist+1;
                    v[u].parent_index=c;
                    Q.deletebeg(u);
                }
            }
            v[c].colour=B;
        }
	}*/
	void BFS (int s)
	{
	    int c,u;
	    for(int i=0;i<Size;i++)
		{
			v[i].dist=INT_MAX;
			v[i].colour=W;
			v[i].parent_index=-1;
		}
		v[s].colour=G;
		v[s].dist=0;
		linkedlist<int> Q;
		Q.insertend(s);
		while (Q.deletebeg(c))
        {
            int j=1;
            while (j<=v[c].adjL.getlen())
            {
               
                v[c].adjL.elementat(u,j);
                if(v[u].colour==W)
                {
                    v[u].parent_index=c;
                    cout<<" "<<c<<" parent of "<<u;
                    v[u].colour=G;
                    v[u].dist=v[c].dist+1;
                    Q.insertend(u);
                }
                j++;
            }
            v[c].colour=B;
        }
	}
	
	
	void DFS()
	{
	    for(int i=0;i<Size;i++)
        {
            v[i].parent_index=-1;
            v[i].colour=W;
        }	    
	    int time=0;
	    for(int i=0;i<Size;i++)
        {
            if(v[i].colour==W)
            {
                //v[i].parent_index=-1;
                DFS_visit(i,time);
            }
        }
	}
	
	DFS_visit(int i,int &time)
	{
	    int u;
	    v[i].colour=G;
	    time++;
	    v[i].st_time=time;
	    //cout<<" for"<<i<<"checking ";
	    for(int p=1;p<=v[i].adjL.getlen();p++)
        {
            if(v[i].adjL.elementat(u,p))
            {
                //cout<<" adjV"<<u;
                if(v[u].colour==W)
                {
                    v[u].parent_index=i;
                    //cout<<" "<<i<<" parent of "<<u;
                    cout<<"\n\t"<<v[u].parent_index<<"-->"<<v[u].value;
                    DFS_visit(u,time);
                }
            }
        }
        //cout<<"--";
        time++;
        v[i].end_time=time;
        v[i].colour=B;
	}
	
	bool extractmin(int &u)
	{
	    int Min=9999;
	    u=-1;
	    for(int i=0;i<Size;i++)
        {
            if((v[i].colour==W)&&(v[i].dist<Min))
            {
                Min=v[i].dist;
                u=i;
            }
            /*
            if((v[i].colour==W)&&(adjM[u][i]<Min))
            {
                Min=adjM[u][i];
                u=i;
            }
            */
        }
        //if(Min>=9999)
        if(u==-1)
        {
            return false;
        }
        else 
        {
            return true;
        }
	}
	
	void prims(int r)
	{
	    cout<<endl<<" prims";
	    for(int i=0;i<Size;i++)
        {
            v[i].parent_index=-1;
            v[i].dist=INT_MAX;
            v[i].colour=W;
        }
	    v[r].dist=0;
	    v[r].parent_index=-1;
	    int u,c;
	    while(extractmin(c))
        {
            v[c].colour=G;
            for(int p=1;p<=v[c].adjL.getlen();p++)
            {
                if(v[c].adjL.elementat(u,p))
                {
                    if((v[c].colour==W)||(adjM[c][u]<v[u].dist))
                    {
                        v[u].parent_index=c;
                        v[u].dist=adjM[c][u];
                    }
                }
            }
            v[c].colour=B;
            cout<<" "<<c;
        }
	}
	void Union(int x,int y)
	{
	    for(int i=0;i<Size;i++)
        {
            if(v[i].Set==v[y].Set)
            {
                v[i].Set=v[x].Set;
            }
        }
	}
	void kruskal()
	{
	    edgesort();//also does initializations 
	    for(int i=0;i<edgeList.getlen();i++)
        {
            if(v[edgear[i].u].Set!=v[edgear[i].v].Set)
            {
                edgear[i].colour=B;
                Union(edgear[i].u,edgear[i].v);
            }
        }
	}
	
	void printedge()
	{
	    if (edgear==NULL){return;}
	    cout<<endl<<" u \t v \t cost \t col";
	    for(int i=0;i<edgeList.getlen();i++)
        {
            cout<<endl<<edgear[i].u<<'\t'<<edgear[i].v<<'\t'<<edgear[i].cost<<'\t'<<edgear[i].colour;
        }
	}
	
	void printvertex()
	{
	    cout<<endl<<"value col \tpar  \t    dist \tst \tfin";
	    for(int i=0;i<Size;i++)
        {
            cout<<endl<<v[i].value<<'\t'<<v[i].colour<<'\t'<<v[i].parent_index<<'\t'<<v[i].dist<<'\t'<<v[i].st_time<<'\t'<<v[i].end_time;
            cout<<" adj L ";v[i].adjL.disp();
        }
	    
	}
	
};

int main()
{
    graph g1(6);
    g1.setadjM();
    g1.constructgraph();
    cout<<"\nBFS"<<endl;
    g1.BFS(0);
    g1.printvertex();
    g1.constructgraph();
    cout<<"\nDFS"<<endl;
    g1.DFS();
    g1.printvertex();
    g1.constructgraph();
    cout<<"\nprims"<<endl;
    g1.prims(0);
    g1.printvertex();
    g1.constructgraph();
    cout<<"\nkruskal"<<endl;
    g1.kruskal();
    
    //g1.edgesort();
    g1.printedge();
    //cout<<"bfs";
    
}