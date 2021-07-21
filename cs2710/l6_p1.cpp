#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

struct ElementType{
    int vow=0;
    int con=0;
};

struct HashNode{
    ElementType value;
    string key;
};


class HashTable 
{
    public:
        void MakeHashTable(int cap);
        void HashTableResize(int cap);
        void HashTableInsert(string s, ElementType count); // create your own ElementType that stores number of vowels and consonants.
        ElementType HashTableDelete(string s);
        ElementType HashTableFind(string s);
        void PrintSizeAndCapacity();
        void HashTablePrint();
  		// add other nessasary member functions.	
    private:
        HashNode** hashTable; //define your own hash node structure or class to store Key, ElementType pair
        int capacity;
        int size;
        HashNode* del;
};

int FindKey(string s,int capacity){
    int key=0;
    for(int i=0;i<(int)s.size();i++){
        key=key+s[i];
    }
    key=key%capacity;
    return key;
}//returns the primitive key value(hash function) for the string that has to be placed in hash table

void HashTable::MakeHashTable(int cap){
    size=0;
    capacity=cap;
    del=new HashNode;
    del->key="@#$";
    (del->value).con=0;
    (del->value).vow=0;//a dummy node to mark the deleted nodes
    hashTable=(HashNode**)malloc(capacity*sizeof(HashNode*));
    for (int i = 0; i < capacity; i++)
    {
        hashTable[i] = NULL;                           
    }//creating an array of pointers to store the nodes
}

void HashTable::PrintSizeAndCapacity(){
    printf("size =%d capacity =%d\n",size,capacity);
}//prints the current size and capacity of the hashtable
void HashTable::HashTableInsert(string s, ElementType count){
    int key=FindKey(s,capacity);
    int i=0;
    int alrpre=0;//to keep note if the key is already present
    HashNode *H=new HashNode ;
    H->key=s;
    H->value=count;
    while(i<capacity){
        if(hashTable[i]!=NULL){
        if(hashTable[i]->key==s){
            alrpre++;
            break;
                                  }}
        else{break;}
        i++;
    }//checking if the string is already present
    i=0;
    if(alrpre==0){while(i<capacity){
        if(hashTable[key]==NULL || hashTable[key]==del ){
            hashTable[key]=H;
            break;
        }//if there is an empty slot then insert the node
        
        else{
            key++;
            if(key==capacity){key=0;}
            i++;
        }//else check the next slot
    }
    
        size++;
        if(size>capacity/2){HashTableResize(capacity*2);}
                 }//resize the hash table if size is more than half of its capacity
    
    
}

void HashTable::HashTableResize(int cap){
    HashNode** H;
    H=(HashNode**)malloc(cap*sizeof(HashNode*));//new pointer array of new capacitiy is created
    int i=0;
    for(i=0;i<cap;i++){H[i]=NULL;}//array is initialised
    for(i=0;i<capacity;i++){
        if(hashTable[i]!=NULL&&hashTable[i]!=del){
            int key=FindKey(hashTable[i]->key,cap);//new hash index for the hashtable with new capacity
            for(int j=0;j<cap;j++){
            if(H[key]==NULL){
                H[key]=hashTable[i];
                break;
            }//just like inssert function but now we are inserting the nodes of old into new table
            else{
                key++;
            }
        }}
    }
    free(hashTable);
    capacity=cap;
    hashTable=H;
}

ElementType HashTable::HashTableFind(string s){
    int key=FindKey(s,capacity);//finding the hashindex
    int i=0;
    while(hashTable[key]!=NULL){
        if(hashTable[key]->key==s){return hashTable[key]->value; }
        else{key++;
            if(key==capacity){key=0;}
             i++;
            }
        if(i==capacity){break;}//ssearching if there is the given string  in the hashtable
    }
    return del->value;//if not present then returning a dummy value
}

ElementType HashTable::HashTableDelete(string s){
    int key=FindKey( s, capacity);
    ElementType temp;
    for(int i=0;i<capacity;i++){
        if(hashTable[key]!=NULL){
            if(hashTable[key]->key==s){
            temp=hashTable[key]->value;
            hashTable[key]=del;
            size--;
            if (size<capacity/4){HashTableResize(capacity/2);}
            return temp;
            break;
        }
         else{
            key++;
             key=key%capacity;
        }
               }//if the string is present at the index then delete the node and mark it deleted
        else if(hashTable[key]==NULL){
            break;
        }//if there is NULL at the index then stop searching
    }
    return del->value;//if there is no string 's' in the hash table then return the dmmy value
    
}


ElementType count(string s){
    ElementType Count;
    Count.vow=0;
    Count.con=0;
    int i=0;
    for(i=0;i<(int) s.size();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){Count.vow++;}
        else{Count.con++;}
    }
    return Count;
}// counting the number of vowels and consonants in the string

int main() {
    int n;
    string s;
    cin>>n;
    int op;
    HashTable H;
    H.MakeHashTable(2);
    for(int i=0;i<n;i++){
        scanf("%d",&op);
        if(op==1){
            cin>>s;
            H.HashTableInsert(s,count(s));
        }//if '1' is given then iserting the given string
        else if(op==2){
            cin>>s;
            ElementType E=H.HashTableFind(s);
            if(E.vow==0 && E.con==0){cout<<"Not Found\n";}
            else{cout<<"Consonants: "<<E.con<<" Vowels: "<<E.vow<<"\n";}
        }//if '2' is given then finding the string given and printing its value
        else if(op==3){
            cin>>s;
            ElementType E;
            E=H.HashTableDelete(s);
        }//if '3' is given then deleting the given string
        else if(op==4){H.PrintSizeAndCapacity();}
    }//if '4' is given then printing urrent size and capacity
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}