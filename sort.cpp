#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;
const int length=30;

inline void print(string name,int number[],int len)
{
    cout<<name;
    for(int i=0;i<len;i++) cout<<number[i]<<" ";
    cout<<endl;
}

void insertsort(int number[],int len)
{
    for(int i=1;i<len;i++)
    {
        int j=i;
        while(j>0&&number[j]<number[j-1])
        {
            swap(number[j],number[j-1]);
            j--;
        }
    }
    string name="insert sort: ";
    print(name,number,len);
}

void selectsort(int number[],int len)
{
    for(int i=0;i<len;i++)
    {
        int min=i;
        for(int j=i+1;j<len;j++)
        {
            if(number[j]<number[min])
                min=j;
        }
        if(i!=min)
            swap(number[i],number[min]);
    }
    string name="select sort: ";
    print(name,number,len);
}

void shellsort(int number[],int len)
{
    int dk=len/2;
    while(dk>=1){
        for(int i=dk;i<len;i++)
        {
            int j=i-dk;
            while(j>=0&&number[j]>number[j+dk])
            {
                swap(number[j],number[j+dk]);
                j-=dk;
            }

        }
        dk/=2;
    }
    string name="shell sort: ";
    print(name,number,len);
}

void adjustheap(int number[],int i,int len)
{
    while(i<len/2)
    {
        int tmp=i*2+1;
        if(tmp<len-1)
            tmp=number[tmp]>number[tmp+1]?tmp+1:tmp;
        if(number[i]>number[tmp])
        {
            swap(number[i],number[tmp]);
            i=tmp;
        }
        else
            break;
    }
}

void heapsort(int number[],int len)
{
    for(int i=len/2-1;i>=0;i--)
        adjustheap(number,i,len);
    cout<<"heap sort: ";
    int i=len-1;
    while(i>0)
    {
        cout<<number[0]<<" ";
        number[0]=number[i];
        adjustheap(number,0,i);
        i--;
    }
    cout<<number[0]<<endl;
}

void bubblesort(int number[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(number[j]>number[j+1])
                swap(number[j],number[j+1]);
        }
    }
    string name="bubble sort:";
    print(name,number,len);
}

int Partition(int number[],int low,int high)
{
    int key=number[low];
    while(low<high){
        while(low<high&&number[high]>=key) high--;
        swap(number[low],number[high]);
        while(low<high&&number[low]<=key) low++;
        swap(number[low],number[high]);
    }
     return low;
}

void quicksort(int number[],int low,int high)
{
    if(low<high)
    {
        int pos=Partition(number,low,high);
        quicksort(number,low,pos-1);
        quicksort(number,pos+1,high);
    }
}

void mergesort(int number[],int low,int high)
{
    if(high-low>=2)
    {
        mergesort(number,low,(high+low)/2);
        mergesort(number,(high+low)/2+1,high);
        int *A= new int[high-low+1];
        for(int i=0;i<=(high-low);i++)
            A[i]=number[i+low];
        int i=0,j=(high-low)/2+1,key=low;
        while(i<=(high-low)/2&&j<=(high-low))
        {
            number[key++]=A[i]>A[j]?A[j++]:A[i++];
        }
        while(i<=(high-low)/2)
        {
            number[key++]=A[i++];
        }
        while(j<=high-low)
        {
            number[key++]=A[j++];
        }
        delete []A;

    }
    else{
        if(number[low]>number[high]) swap(number[low],number[high]);
    }
}

void Radixsort(int number[],int len,int maxradix)
{
    int k=0;
    int m=1;
    while(k<maxradix)
    {
        vector<int> A[10];
        for(int i=0;i<len;i++){
            int key=(number[i]/m)%10;
            A[key].push_back(number[i]);
        }
        int key=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<A[i].size();j++)
                number[key++]=A[i][j];
        }
        m=m*10;
        k++;
    }
}

void buildnumber(int number[])
{
    srand(time(NULL));
    for(int i=0;i<length;i++)
        number[i]=rand()%1000;
}


int main()
{
    int number[length];

    buildnumber(number);
    cout<<"origin number: ";
    for(int i=0;i<length;i++)
        cout<<number[i]<<" ";
    cout<<endl;
    insertsort(number,length);

    buildnumber(number);
    selectsort(number,length);

    buildnumber(number);
    shellsort(number,length);

    buildnumber(number);
    heapsort(number,length);

    buildnumber(number);
    bubblesort(number,length);

    buildnumber(number);
    quicksort(number,0,length-1);
    string name="quick sort: ";
    print(name,number,length);

    buildnumber(number);
    mergesort(number,0,length-1);
    name="merge sort: ";
    print(name,number,length);

    buildnumber(number);
    Radixsort(number,length,3);
    name="Radix sort: ";
    print(name,number,length);
    return 0;
}
