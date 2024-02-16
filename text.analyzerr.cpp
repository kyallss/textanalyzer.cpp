#include <bits/stdc++.h>
 using namespace std; 
 
int totalWordCount(string s) { 
    int wordCnt=0; 
     
    for(char c:s) 
        if(c==' ') 
           wordCnt++; 
 
    return wordCnt+1; 
} 
 
int sentenceCount(string s) { 
    int sntCnt=0; 
     
    s=s+' '; 
    for (int i=0; i<s.length(); i++) 
    { 
        if ((s[i]=='.' or s[i]=='?' or  s[i]=='!') and s[i+1]==' ') 
            sntCnt++; 
    }  
    return sntCnt; 
} 
 
string longestWord(const string& s) { 
    int cnt=0; 
    int longest=0; 
    string lngt=""; 
     
    for (int i=0; i<s.length(); i++) { 
        if (s[i]!=' ') { 
            cnt++; 
        } 
     
        if (s[i]==' ' or i==s.length()-1) { 
            if (cnt>longest) { 
                longest=cnt; 
                 
                if (i==s.length()-1) { 
                    lngt=s.substr(i+1-longest, longest); 
                } else { 
                    lngt=s.substr(i-longest, longest); 
                } 
            } 
            cnt = 0; 
        } 
    } 
    return lngt; 
} 
 
string shortestWord(const string& s) { 
    string tmpWord=""; 
    string shrt=""; 
 
    for (int i=0; i<s.length(); i++) { 
        if (s[i]!=' ') 
            tmpWord=tmpWord+s[i]; 
        else { 
            if (shrt.length()==0) 
                shrt=tmpWord; 
 
            if (tmpWord.length()<shrt.length()) 
                shrt=tmpWord; 
 
            tmpWord=""; 
        } 
    } 
    if (tmpWord.length()<shrt.length()) 
        shrt=tmpWord; 
     
    return shrt; 
} 
 
int countStrings(string s) { 
    set<string> st; 
    string word=""; 
    s=s+" "; 
    for (int i=0; i<s.length(); i++) { 
        if (s[i]!=' ' ) 
        { 
            word=word+s[i]; 
        } 
        else { 
            if (word.length()>0) 
                st.insert(word); 
            word=""; 
        } 
    } 
      
     return st.size(); 
} 
 
int numberOfVowels(string s) { 
    int cnt=0; 
    for (int i=0; i<s.length(); i++) { 
        
if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='y' or s[i]=='A' or s[i]=='E' or s[i]=='I'           or s[i]=='O' or s[i]=='U' or s[i]=='Y') { 
            cnt++;  
        } 
    } 
     
    return cnt; 
}  
 
int main() { 
    ifstream file("myfile.txt");  
 
    if (!file.is_open()) { 
        cout << "Unable to open file!" << endl; 
        return 1; 
    } 
 
    string s; 
    getline(file, s); 
 
    cout << "Length of the string: " << s.length() << endl; 
    cout << "Total word count: " << totalWordCount(s) << endl; 
    cout << "Sentence count: " << sentenceCount(s) << endl; 
    cout << "Longest word: " << longestWord(s) << endl; 
    cout << "Shortest word: " << shortestWord(s) << endl; 
    cout << "Number of vowels: " << numberOfVowels(s) << endl; 
    cout << "Number of unique words: " << countStrings(s) << endl;
 
    file.close(); 
    return 0; 
}