#include<iostream>
using namespace std;
class search1{
    public:
    int arr[5]={10,20,30,40,50};
    int key,i;
    void linear(){
        cout<<"Enter Element to search: ";
        cin>>key;
        bool found = true;
        for(i=0;i<5;i++){
            if(arr[i]==key){
                cout<<"Element found at "<<i+1<<" position";
                break;
            }
            found = false;
        }
        if(!found){
            cout<<"Element not present";
        }
    }
};
int main(){
    search1 s1;
    s1.linear();
    return 0;
}