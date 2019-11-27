#include <iostream>
#include<cstring>
using namespace std;
template <typename T>
class Stack
{
    T *a;
    int top,Size;

public:
    Stack(int);
    bool isfull();
    bool isempty();
    bool push(T b);
    bool pop(T& b);
    void makeempty();
    bool peek(T& b);
    //for testing
    void trace();
    //for testing
    ~Stack();
};
template<typename T>
Stack<T>::Stack(int n)
{
    a=new T[n];top=-1;Size=n;
}
template<typename T>
Stack<T>::~Stack()
{
    delete a;
}
template<typename T>
bool Stack<T>::isempty()
{
    return (top==-1)?true:false;
}
template<typename T>
bool Stack<T>::isfull()
{
    return (top==Size-1)?true:false;
}
template<typename T>
bool Stack<T>::push(T b)
{
    if(!isfull())
    {
        top++;a[top]=b;return true;
    }
    return false;
}
template<typename T>
bool Stack<T>::pop(T& b)
{
    if(!isempty())
    {
        b=a[top];top--;return true;
    }
    return false;
}
template<typename T>
bool Stack<T>::peek(T& b)
{
    if(!isempty())
    {
        b=a[top];return true;
    }
    return false;
}
template<typename T>
void Stack<T>::makeempty()
{
    top=-1;
}
template<typename T>
void Stack<T>::trace()
{
    cout<<'\t'<<'\t'<<"| ";
    for (int i=0;i<=top;i++)
    {
        cout<<a[i];
    }
}

int order (char a)
{
    switch(a)
    {
        case '(':return 1;break;
        case '+':return 2;break;
        case '-':return 2;break;
        case '*':return 3;break;
        case '/':return 3;break;
        case '%':return 4;break;
        case '^':return 5;break;
        default: //cout<<"#unrecognised character#";
            return 0;
    }
}
void tf(bool a)
{
    cout<<((a)?"true":"false");
}
template<typename T>
void chk(int i,char a,Stack<T> s,Stack<T> p)
    {
        cout<<endl<<"  "<<i+1<<" "<<a;
        s.trace();
        p.trace();
    }


int main()
{
    //Stack<char> st();
    //Stack<char> post();
    bool c;
    int n,i;
    char a[100],b[100],temp;
    cout<<"enter expression : ";
    cin>>a;
    n=strlen(a);
    Stack<char> st(n);
    Stack<char> post(n);


    cout<<" sln "<<'\t'<<'\t'<<"| stack "<<'\t'<<"| postfix "<<endl<<"--------------------------------------";
    for( i=0;i<n;i++)
    {
        cout<<endl<<"  "<<i+1<<" "<<a[i];
        int ord=order (a[i]);//cout<<'O'<<ord;
        //if operand
        if(isalpha(a[i]))
        {
           //cout<<" A ";
           c=post.push(a[i]);
           //chk(i,a[i],st,post);
           //tf(c);
        }
        //if operator

        if(ord>1)
        {
            //cout<<" O ";
            if(!st.isempty())
            {
                //cout<<" sE ";
                c=st.peek(temp);
                while ((order(temp)>=order(a[i]))&&(!st.isempty()))
                {
                    c=st.pop(temp);
                    //chk(i,a[i],st,post);
                    c=post.push(temp);
                    //chk(i,a[i],st,post);
                    c=st.peek(temp);
                    //chk(i,a[i],st,post);
                }
            }
            c=st.push((char)a[i]);
            //chk(i,a[i],st,post);
            //tf(c);
        }
        //order 1 = (
        if(ord==1)
        {
            //cout<<" ( ";
            c=st.push(a[i]);
            //chk(i,a[i],st,post);
            //tf(c);
        }
        //if )
        if(a[i]==')')
        {
            //cout<<" ) ";
            c=st.pop(temp);
            //chk(i,a[i],st,post);
            while (temp!='(')
            {
                c=post.push(temp);
                //chk(i,a[i],st,post);
                c=st.pop(temp);
                //chk(i,a[i],st,post);
                if(c==false){cout<<"#stack empty braces not matched#";}
            }
            //tf(c);
        }
        //chk(i,a[i],st,post);
        st.trace();
        post.trace();


    }
    cout<<endl<<endl<<" postfix expression :";
    while(!st.isempty())
    {
        c=st.pop(temp);
        c=post.push(temp);
    }
    post.trace();
    cout<<endl<<endl;
}
