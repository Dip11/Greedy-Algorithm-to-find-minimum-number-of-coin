// Dipto Barua
//Greedy Algorithm to find minimum number of coin...

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class greedy
{
    int length=0;
    bool found=false;
public:
    void input(int A[], int n, int m)
    {
        cout<< "Enter currencies(Press -1 for ending Input): ";
        for(int i=0; i<n; i++)
        {
            cin>>m;
            if(m==-1)
                return ;
            else
            {
                A[i]=m;
                length++;
            }
        }
    }
    int FindMax(int A[],int length)
    {
        int max=-999999;
        for(int i=0; i<length; i++)
        {
            if(A[i]>max)
            {
                max=A[i];
            }

        }
        return max;
    }
    void insertion_sort(int *A)
    {
        for(int i=1; i<length; ++i)
        {
            int j=i-1;
            int key=A[i];
            while(A[j]>key && j>=0)
            {
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=key;
        }
    }
    void display(int A[])
    {
        for(int j=0; j<length; j++)
        {
            cout<<A[j]<<" ";
        }
    }

    void coinexchange(int A[], int taka,int tk,int &sum)
    {
        if(sum==tk)
        {
            return;
        }
        else
        {
            found=false;
            for(int i=0; i<length; i++)
            {
                if(A[i]<=taka && A[i+1]>taka)
                {
                    if(taka%A[i]==0)
                    {
                        for(int j=0; j<taka/A[i]; j++)
                        {
                            cout<<A[i]<< " ";
                            sum+=A[i];
                        }
                        return;
                    }
                    else if(taka%A[i]>0)
                    {
                        int howmanytimes= taka/A[i];
                        for(int y=0; y<howmanytimes; y++)
                        {
                            cout<<A[i]<< " ";
                        }
                        taka=taka%A[i];
                        sum+=A[i];
                    }
                    found=true;
                }
            }
            if(found==false)
            {
                int k=FindMax(A,length);
                int howmanytimes1= taka/k;
                for(int y=0; y<howmanytimes1; y++)
                {
                    cout<<k<< " ";
                }
                taka=taka%k;
                sum+=k;
            }
            coinexchange(A, taka,tk,sum);
        }
    }
};

int main()
{
    int A[100];
    int n=100,taka;
    int m=0,sum=0;
    greedy obj;
    obj.input(A,n,m);
    obj.insertion_sort(A);
    cout<<endl<<"Your given currencies: ";
    obj.display(A);
    cout<<endl<<endl<<"Enter Amount:";
    cin>>taka;
    int tk=taka;
    cout<<endl<< "The Currency arrangement will be like this: "<<endl<<endl;
    obj.coinexchange(A,taka,tk,sum);
    cout<<endl;
}
