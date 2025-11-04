// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
class stringop{
    public:
    void longword(string str){
        string word="",longest="";
        int maxlen=0;
        str = str+" ";
        
        for(int i=0;i<str.length();i++){
            if(str[i]!=' '){
                word= word + str[i];
            }else{
                if(word.length()>maxlen){
                    maxlen = word.length();
                    longest = word;
                }
            word="";
            }
        }
        cout<<"Longest word :"<<longest<<endl;
        cout<<"Length: "<<maxlen<<endl;
    }
    
    void frequency(string str){
        int count = 0;
        char ch;
        cout<<"Enter Character to count:";
        cin>>ch;
        for(int i=0;i<str.length();i++){
            if(str[i]==ch){
                count++;
            }
        }
        cout<<"The "<<ch<<" appeared "<<count<<" times"<<endl;
    }
    
    void palindrome(){
        string pal;
        int start=0;
        int end = pal.length()-1;
        cout<<"Enter a String To check whether palindrome or not: ";
        cin>>pal;
        bool ispal = true;
        while(start<end){
            if(pal[start]!=pal[end]){
                ispal = false;
                break;
            }
            start++;
            end--;
        }
        if (ispal) {
        cout << "'" << pal << "' is a PALINDROME" << endl;
    } else {
        cout << "'" << pal << "' is NOT a palindrome" << endl;
    }
        
    }
    
    void findSubstring(string str) {
    string sub;
    cout << "Enter substring to find: ";
    cin.ignore();
    getline(cin, sub);
    
    int index = -1;
    
    for (int i = 0; i <= str.length() - sub.length(); i++) {
        bool found = true;
        for (int j = 0; j < sub.length(); j++) {
            if (str[i + j] != sub[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        cout << "Substring found at index: " << index << endl;
    } else {
        cout << "Substring not found" << endl;
    }
}

    void wordCount(string str) {
    string words[100];   
    int counts[100];     
    int uniqueWords = 0; 
    
    str = str + " ";    
    string word = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            word = word + str[i];  
        } else {
            if (word.length() > 0) {
                bool found = false;
                int position = -1;
                
                for (int j = 0; j < uniqueWords; j++) {
                    if (words[j] == word) {
                        found = true;
                        position = j;
                        break;
                    }
                }
                if (found) {
                    counts[position]++;
                } else {
                    words[uniqueWords] = word;
                    counts[uniqueWords] = 1;
                    uniqueWords++;
                }
                
                word = "";  // Reset for next word
            }
        }
    }
    
    cout << "\nWord Occurrences:" << endl;
    for (int i = 0; i < uniqueWords; i++) {
        cout << words[i] << " : " << counts[i] << endl;
    }
}

};
int main() {
    stringop s1;
    // s1.longword("hello to the world of programming");
    // s1.frequency("hello to the world of programming");
    // s1.palindrome();
    s1.findSubstring("hello to the world of programming");
    s1.wordCount("hello to the world of programming")
    return 0;
}