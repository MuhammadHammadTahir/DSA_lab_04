#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <vector>
using namespace std;

int maxSubSum1(const vector<int> &a)
{
    int maxSum=0;
    for(int i=0; i<a.size(); i++)
        for(int j=i; j<a.size(); j++)
    {
        int thisSum=0;
        for(int k=i; k<=j ;k++)
            thisSum+=a[k];
        if(thisSum>maxSum)
            maxSum=thisSum;
    }
    return maxSum;
}

int main()
{
        int size;
        int value,result;
        cout<<"Please enter the size of array=";
        cin>>size;
       std::vector<int> arry(size);
        for(int i=0; i<size; i++)
        {
            value=std::rand()%10000000;
            arry[i]=value;
        }
        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::milliseconds;

        auto t1= high_resolution_clock::now();
        result=maxSubSum1(arry);
        auto t2=high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(t2-t1);
        duration<double, std::milli> ms_double=t2-t1;

        std::cout <<ms_int.count() <<"ms\n";
        std::cout <<ms_double.count() <<"ms";
        return 0;
}
