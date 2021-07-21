#include <iostream>

using namespace std;
typedef int elementType;
typedef int Position;

class List {
public:
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
  elementType retrieve(Position p);
  void Exch(Position i, Position j);  
private:
  Position lastNode;
  elementType*  list;
};
void List::makeNull() {
  list = new elementType[100000]; 
  lastNode = 0;
}
void List::insert(elementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p] = x;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 1;
  
  while (p <= lastNode) {
    cout << list[p] << " ";
    p++;
  }
 }
Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}
void List::delItem(Position p) {
  int i;
  for (i = p; i < lastNode; i++)
    list[i] = list[i+1];
  lastNode = lastNode - 1;
}
Position List::first() {
  return(1);
}
Position List::next(Position p) {
  return (p+1);
}

elementType List::retrieve (Position p) {
  return (list[p]);
}
void List::Exch(Position i, Position j){
    elementType x=list[i];
    list[i]=list[j];
    list[j]=x;
} 

List Union(List A, List B) {
    List U;
    U.makeNull();
    elementType x;
    elementType y;
    elementType p = 1;
    while(p!=A.end()){
        x = A.retrieve(p);
        U.insert(x,p);
        p++;
    }//adding elements of first list to new list
    p=1;
    while(p!=B.end()){
        x = B.retrieve(p);
        U.insert(x,p);
        p++;
    }//adding elements of second list to new list
    p=1;
    elementType p1=1;
    while(p!=U.end()){
        p1=p+1;
        while(p1!=U.end()){
            x = U.retrieve(p);
            y = U.retrieve(p1);
            if(x==y){U.delItem(p1);}
            else{p1++;}
        }
        p++;
    }//removing the repeating elements
    return U;
}//function to find the union of two lists

List Intersection(List A, List B) {
    List I;
    I.makeNull();
    elementType x;
    elementType y;
    elementType p1 =1;
    elementType p2 =1;
    elementType p3 =1;
    
    while(p1!=A.end()){
        p2=1;
        while(p2!=B.end()){
            x = A.retrieve(p1);
            y = B.retrieve(p2);
            if(x==y){I.insert(x,p3);
                    p3++;}
            p2++;
        }
         p1++;
    }//finding the common elements and inserting in the new list
    if(p3==1){cout<<"$";
           return I;}
   else{ p1 = 1;
    p2 = 1;
    while(p1!=I.end()){
        p2=p1+1;
        while(p2!=I.end()){
            x = I.retrieve(p1);
            y = I.retrieve(p2);
            if(x==y){I.delItem(p2);}
            else{p2++;}
        }
         p1++;
    }//removing the repeating elements
    return I;}
  
 
  
}//function to find the intersection of two lists
elementType partition(List A,elementType first,elementType last){
    elementType pivot=A.retrieve(last);
    elementType i=first-1;
    elementType j;
    for(j=first;j<last;j++){
        if(A.retrieve(j)<=pivot){
            i++;
           A.Exch(i,j);
        }
    }
     A.Exch(i+1,last);
    return i+1;
}
// function used in quicksort


void quicksort(List A, elementType first, elementType last){
    if(first<last){
         elementType p=partition(A,first,last);
         quicksort(A,first,p-1);
         quicksort(A,p+1,last);
    }
}
//sorting the list using quick sort


int main() {
  
   List A, B, C;
   int M, N;
    A.makeNull();
    B.makeNull();
   cin >> M;
    cin >> N;
    int i=0;
    elementType x;
    for(i=1;i<M+1;i++){
        cin >> x;
        A.insert(x,i);
    }//storing first input list
    for(i=1;i<N+1;i++){
        cin >> x;
        B.insert(x,i);
    }//storing second input list
    C=Union(A,B);//finding unsorted union
    quicksort(C,1,(C.end()-1));//sorting the union
    C.printList();//printing sorted union
    cout<<"\n";
    C=Intersection(A,B);//finding unsorted intresetion
    quicksort(C,1,(C.end()-1));//finding sorted intresetion
    C.printList();//printing sorted intresetion
    
    
}