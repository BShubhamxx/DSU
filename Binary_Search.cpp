#include <iostream>
using namespace std;
class binary{
    public:
    int arr[5]={10,20,30,40,50};
    int n=5,i,low,mid,high,key;
    
    void getdata(){
        cout<<"Enter Element to Search: ";
        cin>>key;
        low=0;
        high=n-1;
        bool found = false;
        while(low<=high){
            mid=(low + high)/2;
            if(arr[mid]==key){
                cout<<"Element found at Index "<<mid +1;
                found = true;
                break;
            }else if(arr[mid]<key){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        if(!found)
            cout<<"Element not Present in Array!";
    }  
};
int main(){
    binary b;
    b.getdata();
    return 0;
}