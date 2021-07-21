/*  The class Heap defines an ADT Heap. */
/* begin {Definition of class Heap} */



#include <iostream>
using namespace std;
#define HEAP_SIZE 1000
typedef int ElementType;
typedef int Position;

class Heap {
  ElementType priority[HEAP_SIZE];        // A Heap of integers
  Position last;
public:
  void insertHeap(ElementType x);       // Inserts an element on to the Heap
  ElementType deleteRoot();             // DeleteRoot of the Heap
  int empty();                   // returns 1 if Heap is empty
  void createHeap();             // creates an empty Heap
  void printHeap();               // Prints the heap
 };

void Heap::createHeap(){
    last=0;
    priority[last]=0;
}//creates a heap 

int Heap::empty(){
    if(last==0){return 1;}
    else{return 0;}
}
//check if the heap is empty
void Heap::printHeap(){
    
   if(last!=0){
       for(int i=1;i<=last;i++){
        cout<<priority[i]<<" ";
    }
    cout<<"\n";
   }
}//prints the heap if it is not empty using level order traversal

void Heap::insertHeap(ElementType x){
    last++;
    int i=last;
    while(i!=1 && (x>priority[i/2])){
        priority[i]=priority[i/2];
        i=i/2;
    }//shifting the nodes down the heap until we find the correct position for the new node
    priority[i]=x;
}//inserts the new element in its correct position

ElementType Heap::deleteRoot(){
   int root=priority[1];
    int temp=priority[last];
    last--;
    priority[1]=temp;
    int i=1;
    while((2*i+1)<=last){
        if(temp>priority[2*i] && temp>priority[2*i+1]){break;}//if temp is already in its correct position no need to go ahead
        else{if(priority[2*i]>=priority[2*i+1]){
            if(temp<priority[2*i]){priority[i]=priority[2*i];
                                   priority[2*i]=temp;
                                   i=2*i;
                                  }
        }
        else{
           if(temp<priority[2*i+1]){priority[i]=priority[2*i+1];
                                  priority[2*i+1]=temp;
                                  i=2*i+1;
                                 }
        }}//comparing the siblings and the greater oneof them with the temp untill the last but one level if the last node doesnt have any sibling
    }
    if(2*i<=last){
        if(temp<priority[2*i]){priority[i]=priority[2*i];
                                   priority[2*i]=temp;
                                   i=2*i;
                                  }//if the last node doesnt have any sibling then no comparision is done among the siblings
    }
    return root; 
}



/* end{Definition of class Heap} */
int main(){
    int n;
    scanf("%d",&n);
    Heap H;
    H.createHeap();
    int inarr[HEAP_SIZE];
    int outarr[HEAP_SIZE];
    for(int i=0;i<n;i++){
        scanf("%d",&inarr[i]);//storing the input array 
        H.insertHeap(inarr[i]);//inserting the input in the heap
        H.printHeap();
    }
    for(int i=0;i<n;i++){
        outarr[i]=H.deleteRoot();
        cout<<outarr[i]<<"\n";
        H.printHeap();
        if(H.empty()==1){cout<<"EMPTY HEAP\n";}
    }//deleting the roots and getting the sorted array
    for(int i=0;i<n;i++){
        cout<<outarr[i]<<" ";
    }//printing the sorted array
  return 0;
}