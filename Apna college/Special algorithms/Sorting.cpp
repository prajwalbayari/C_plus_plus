#include<iostream>
using namespace std;

//1.MERGE SORT

// nlogn

// void merge(int arr[],int l,int mid,int r)
// {
//     int n1=mid-l+1;
//     int n2=r-mid;

//     int a[10];
//     int b[10];
//     for(int i=0;i<n1;i++)
//     {
//         a[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++)
//     {
//         b[i]=arr[mid+1+i];
//     }

//     int i=0,j=0,k=l;
//     while(i<n1 && j<n2)
//     {
//         if(a[i]<b[j])
//         {
//             arr[k]=a[i];
//             k++,i++;
//         }
//         else
//         {
//             arr[k]=b[j];
//             k++,j++;
//         }
//     }
//     while(i<n1)
//     {
//         arr[k]=a[i];
//         k++,i++;
//     }
//     while(j<n2)
//     {
//         arr[k]=a[j];
//         k++,j++;
//     }
// }
// void mergeSort(int arr[],int l,int r)
// {
//     if(l<r)
//     {
//         int mid=(l+r/2);
//         mergeSort(arr,l,mid);
//         mergeSort(arr,mid+1,r);

//         merge(arr,l,mid,r);
//     }
// }

// int main()
// {
//     int n,a[10];
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     mergeSort(a,0,n-1);
//     cout<<"Elements after sorting is:\n";
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//2.QUICK SORT

// TIME COMPLEXITY DEPENDS ON PIVOT
// BEST CASE Q(nLogn)
//WORST CASE O(N^2)

// void swap(int arr[], int i,int j)
// {
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }

// int partition(int arr[],int l,int r)
// {
//     int pivot=arr[r];
//     int i=l-1;

//     for(int j=l;j<r;j++)
//     {
//         if(arr[j]<pivot)
//         {
//             i++;
//             swap(arr,i,j);
//         }
//     }
//     swap(arr,i+1,r);
//     return i+1;
// }

// void quick(int arr[],int l,int r)
// {
//     if(l<r)
//     {
//         int pi=partition(arr,l,r);
//         quick(arr,l,pi-1);
//         quick(arr,pi+1,r);
//     }
// }
// int main()
// {
//     int arr[5]={5,4,3,2,1};
//     quick(arr,0,4);
//     for(int i=0;i<5;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0; 
// }

//3.COUNT SORT

// Time cmplexity O(max(Ai,N))
// void countSort(int arr[],int n)
// {
//     int k=arr[0];
//     for(int i=0;i<n;i++)
//     {
//         k=max(k,arr[i]);
//     }
//     int count[10]={0};
//     for(int i=0;i<n;i++)
//     {
//         count[arr[i]]++;
//     }
//     for(int i=1;i<n;i++)
//     {
//         count[i]+=count[i-1];
//     }
//     int out[10];
//     for(int i=n;i>=0;i--)
//     {
//         out[--count[arr[i]]]=arr[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         arr[i]=out[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main()
// {
//     int i,n,arr[20];
//     cout<<"Enter the size of the array\n";
//     cin>>n;
//     cout<<"Enter array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }    
//     countSort(arr,n);
//     return 0;
// }

//4.DNF SORT or 012 SORT
//TIME COMPLEXITY O(N)

// void swap(int arr[],int i,int j)
// {
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }

// void dnf(int arr[],int n)
// {
//     int low=0,mid=0,high=n-1;
//     while(mid<=high)
//     {
//         if(arr[mid]==0)
//         {
//             swap(arr,low,mid);
//             low++,mid++;
//         }
//         else if(arr[mid]==1)
//         {
//             mid++;
//         }
//         else
//         {
//             swap(arr,mid,high);
//             high--;
//         }
//     }
// }

// int main()
// {
//     int arr[]={1,0,2,1,0,1,2,1,2};
//     dnf(arr,9);
//     for(int i=0;i<9;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//5.WAVE SORT
//TIME COMPLEXITY O(N)

// void swap(int arr[],int i,int j)
// {
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }

// void wavesort(int arr[],int n)
// {
//     for(int i=1;i<n;i+=2)
//     {
//         if(arr[i]>arr[i-1])
//         {
//             swap(arr,i,i-1);
//         }
//         if(arr[i]>arr[i+1] && i<=n-2)
//         {
//             swap(arr,i,i+1);
//         }
//     }
// }

// int main()
// {
//     int arr[]={1,3,4,7,5,6,2};
//     wavesort(arr,7);
//     for(int i=0;i<7;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//6.SELECTION SORT

// int main()
// {
//     int n,arr[10];
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 int temp=arr[j];
//                 arr[j]=arr[i];
//                 arr[i]=temp;
//             }
//         }
//     }
//     cout<<"The array after sorting is:\n";
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//7.BUBBLE SORT

// int main()
// {
//     int n,arr[10],i,counter=1;
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     while(counter<n)
//     {
//         for(i=0;i<n-counter;i++)
//         {
//             if(arr[i]>arr[i+1])
//             {
//                 int temp=arr[i];
//                 arr[i]=arr[i+1];
//                 arr[i+1]=temp;
//             }
//         }
//         counter++;
//     }
//     cout<<"Elements after sorting:\n";
//     for(i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }    

//8.INSERTION SORT

// int main()
// {
//     int i,n,arr[10];
//     cout<<"Enter the number of elements in the array\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     for(i=1;i<n;i++)
//     {
//         int current=arr[i];
//         int j=i-1;
//         while(arr[j]>current && j>=0)
//         {
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=current;
//     }
//     cout<<"Array after sorting:\n";
//     for(i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

//COUNT INVERSION USING MERGE SORT
//TIME COMLEXITY FOR BRUTE APPROACH O(N^2)

// long long merge(int arr[],int l,int mid,int r)
// {
//     long long inv =0;
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int a[100],b[100];
//     for(int i=0;i<n1;i++)
//     {
//         a[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++)
//     {
//         b[i]=arr[mid+i+1];
//     }
//     int i=0,j=0,k=l;
//     while(i<n1 && j<n2)
//     {
//         if(a[i]<= b[j])
//         {
//             arr[k]=a[i];
//             i++,k++;
//         }
//         else
//         {
//             arr[k]=b[j];
//             inv+=n1-i;
//             j++,k++;
//         }
//     }
//     while(i<n1)
//     {
//         arr[k]=a[i];
//         i++,k++;
//     }
//     while(j<n2)
//     {
//         arr[k]=b[j];
//         j++,k++;
//     }
//     return inv;
// }

// long long mergeSort(int arr[],int l,int r)
// {
//     long long inv =0;
//     if(l>r)
//     {
//         int mid=(l+r)/2;
//         inv+=mergeSort(arr,l,mid);
//         inv+=mergeSort(arr,mid+1,r);
//         inv+=merge(arr,l,mid,r);
//     }

//     return inv; 
// }

// int main()
// {
//     int n,arr[100];
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<"Number of inversion is:\n";
//     cout<<mergeSort(arr,0,n-1);
// }

int main()
{
    int arr[5]={5,4,3,2,1};
    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
