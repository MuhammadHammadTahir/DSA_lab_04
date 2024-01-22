#include <iostream>
#include <cstdlib>
#include<thread>
#include<chrono>
using namespace std;

int max3(int a,int b,int c)
{
    if (a>b && a>c)
        return a;
    if (b>a && b>c)
        return b;
    if (c>a && c>b)
        return c;
    return 0;
}

int maxSubSum(int a[], int left, int right)
{
    int mid,maxLeft,maxRight,maxLeftBorder,leftBorder,i, maxRightBorder,rightBorder;

    if (left==right) return a[left];
    else
    mid=(left+right)/2;
    maxLeft=maxSubSum(a,left,mid);
    maxRight=maxSubSum(a,mid+1,right);

    maxLeftBorder=0; leftBorder=0;
    for(i = mid; i>= left;i--)
        {
           leftBorder += a[i];
           if (leftBorder>maxLeftBorder)
               maxLeftBorder=leftBorder;
        }

// same for the right
    maxRightBorder=0;
    rightBorder=0;


   return max3(maxLeft,maxRight,maxLeftBorder+maxRightBorder);

}

int main()
{
    int size_arr,value,left,right;
    cout<<"Enter Size of Array : ";
    cin>>size_arr;
    int arr[size_arr];
    for(int i=0;i<size_arr;i++)
    {
        value=std::rand()%1000000;
        arr[i]=value;
    }
    left=0;
    right=size_arr-1;
    maxSubSum(arr,left,right);


    int answer;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    answer=maxSubSum(arr,left,right);
    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2-t1);

    duration<double, std::milli> ms_double = t2-t1;

    std ::cout<<ms_int.count()<<"ms\n";
    std::cout<< ms_double.count()<<"ms";
    return 0;


}

