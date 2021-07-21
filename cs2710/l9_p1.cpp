#include <cmath>
#include <cstdio>
#include <iostream>
#include<cstdlib>
using namespace std;
typedef int NodeType;//nodetype to store vertex indices
typedef int WeightType;//weighttype to store the distances

class Graph{
     int v;     // no of vertices in a graph
     WeightType** adjMat; //adjacency matrix to represent a graph
     public:
        void createGraph(int m);
        void addEdge(NodeType v1, NodeType v2, WeightType d);
        WeightType getEdge(NodeType v1, NodeType v2);//returns the distance between v1 and v2
 };

void Graph::createGraph(int m){
    adjMat=(WeightType**)malloc(m*sizeof(WeightType*));
    for(int i=0;i<m;i++){
        adjMat[i]=(WeightType*)malloc(m*sizeof(WeightType));
        for(int j=0;j<m;j++){
            if(i!=j){adjMat[i][j]=2000;}
            else{adjMat[i][j]=0;}
        }
    }//creates a matrix initialised with 2000 considered as infinite as d<1000 if there is no path and '0' if v1=v2
    v=m;
}

void Graph::addEdge(NodeType v1, NodeType v2, WeightType d){
    adjMat[v1][v2]=d;
    adjMat[v2][v1]=d;
}//changes the element in the matrix if there is a path

WeightType Graph::getEdge(NodeType v1, NodeType v2){
    return adjMat[v1][v2];
}

struct HeapNode {
    NodeType verInd;
    WeightType dist;
};//in the heap the node contains the vertex index and the distance of the vertex from the source

class MinHeap{
    
        struct HeapNode **heap;  // Heap Node should store a graph node and distance from the source                            
        int last;
    public:
        void createHeap(int m);
        void decreaseKey(NodeType v, WeightType d); // WeightType can be used to denote the current distance from source
        struct HeapNode* deleteRoot();
        void insert(NodeType v, WeightType d);
        void printHeap();
        HeapNode* getDistance(NodeType i);
};

void MinHeap::createHeap(int m){
    heap=(HeapNode**)malloc((m+1)*sizeof(HeapNode*));
    last=0;
    for(int i=0;i<=m;i++){
        heap[i]=NULL;
    }
}//creates an array of null pointers of size of number of vertices

void MinHeap::insert(NodeType v, WeightType d){
    last++;
    int i=last;
    HeapNode* h=new HeapNode;
    h->dist=d;
    h->verInd=v;
    while(i!=1 && (d<heap[i/2]->dist)){
        heap[i]=heap[i/2];
        i=i/2;
    }//shifting the nodes down the heap until we find the correct position for the new node
    heap[i]=h;
}//inserts the new element in its correct position

struct HeapNode* MinHeap::deleteRoot(){
    HeapNode* root=new HeapNode;
    HeapNode* temp=new HeapNode;
    root=heap[1];
    temp=heap[last];
    last--;
    heap[1]=temp;
    int i=1;
    while((2*i+1)<=last){
        if(temp->dist<heap[2*i]->dist && temp->dist<heap[2*i+1]->dist){break;}//if temp is already in its correct position no need to go ahead
        else{if(heap[2*i]->dist<=heap[2*i+1]->dist){
            if(temp->dist>heap[2*i]->dist){heap[i]=heap[2*i];
                                   heap[2*i]=temp;
                                   i=2*i;
                                  }
        }
        else{
           if(temp->dist>heap[2*i+1]->dist){heap[i]=heap[2*i+1];
                                  heap[2*i+1]=temp;
                                  i=2*i+1;
                                 }
        }}//comparing the siblings and the greater oneof them with the temp untill the last but one level if the last node doesnt have any sibling
    }
    if(2*i<=last){
        if(temp->dist>heap[2*i]->dist){heap[i]=heap[2*i];
                                   heap[2*i]=temp;
                                   i=2*i;
                                  }//if the last node doesnt have any sibling then no comparision is done among the siblings
    }
    return root; 
}

void MinHeap::decreaseKey(NodeType v, WeightType d){//function to rearrange the heap if one value at any node is changed
    int i=1;
    for(i=1;i<=last;i++){
        if(heap[i]->verInd==v){break;}
    }//searching  for the node with given index
    heap[i]->dist=d;
    while(i!=1){
        if(heap[i]->dist<heap[i/2]->dist){
            HeapNode* temp=new HeapNode;
            temp=heap[i];
            heap[i]=heap[i/2];
            heap[i/2]=temp;
            i=i/2;
        }//moving upwards to find the correct position of the modified node
        else{break;}
    }
}

HeapNode* MinHeap::getDistance(NodeType i){
    if(i<=last&&i>0){return heap[i];}
    else{return NULL;}
}//returns the distance of the vertex present in a node in heap level order

void MinHeap::printHeap(){
    
   if(last!=0){
       for(int i=1;i<=last;i++){
        cout<<heap[i]->verInd<<" "<<heap[i]->dist<<"\n";
    }
       
   }
}//prints the heap
int * ShortestPath(Graph g,int m){
    int * d;//array that stores the shortest distances
    d=(int *)malloc(m*sizeof(int));
    d[0]=0;
    for(int i=1;i<m;i++){
        d[i]=g.getEdge(0,i);
    }//initialising the array with the direct edges(paths)
    MinHeap m1;
    m1.createHeap(m);//min heap is created to get the minimum distanceof a single vertex
    for(int i=1;i<m;i++){
        m1.insert(i,g.getEdge(0,i));
    }//nodes in the heap are initialised to the direct edges
    for(int i=1;i<m;i++){
        HeapNode* h=m1.deleteRoot();
        d[h->verInd]=h->dist;//removing the node with shortest path and noting it in the array
        for(int j=0;j<m;j++){
            if(d[j]>h->dist+g.getEdge(j,h->verInd)){
                m1.decreaseKey(j,h->dist+g.getEdge(j,h->verInd));
            }
        }//Dijkstra's shortest path algorithm's key part (comparing the previous shortest path with the possible shortest path)
        HeapNode* h1=new HeapNode;
        for(int j=1;j<m-i;j++){
            h1=m1.getDistance(j);
            if(h1!=NULL){d[h1->verInd]=h1->dist;}
        }//noting the new shortest paths in the array
    }
    return d;
}

int main() {
    int m;//number of vertices
    int n;//number of edges
    cin>>m;
    cin>>n;//taking the input
    int v1=0;
    int v2=0;
    int d=0;
    Graph g;
    g.createGraph(m);//graph created to store the input
    for (int i=0;i<n;i++){
        cin>>v1>>v2>>d;
        g.addEdge(v1,v2,d);
    }//input to the graph is given
    int * d1;
    d1=(int *)malloc(m*sizeof(int));
    d1=ShortestPath(g,m);//array that stores the shortest distances from the source
    for(int i=0;i<m;i++){
        cout<<i<<" "<<d1[i]<<"\n";
    }//printing the output
    return 0;
}