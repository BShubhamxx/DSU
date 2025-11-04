#include <iostream>
using namespace std;
class bubble{
    public:
    int arr[10];
    int i,n,m,temp;
    
    void getdata(){
        cout<<"Enter no. of Array: ";
        cin>>n;
        cout<<"Enter the elements of Array: ";
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        for(m=0;m<=n-1;m++){
            for(i=0;i<n-m-1;i++){
                if(arr[i+1]<arr[i]){
                    temp= arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
        }
        cout<<"Sorted Array: ";
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    bubble b;
    b.getdata();
    return 0;
}