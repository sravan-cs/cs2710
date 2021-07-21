#include <iostream>
using namespace std;
typedef struct tnode* treeptr;
typedef struct tnode {
    int element;
    treeptr leftMostChild;
    treeptr rightSibling;
} TreeNode; 

class Tree {
  private:
    treeptr root;
    void printTreeHelper(treeptr ptr,int val);
    treeptr makeTreeHelper(treeptr ptr,int val);
    int max(int x, int y); 
  public:
     void createNode (int E, Tree L, Tree R);
     void makeTree(int *array, int n);
     treeptr getRoot();
     void printTree();
     
     //Implement the following functions
     int height(treeptr ptr);               
     int numNodesLevel(treeptr ptr, int level, int curlevel);
     
    Tree(){root = NULL;}
    ~Tree () { delete root;}
};


void Tree::createNode(int E, Tree leftMostChild, Tree rightSibling) {
   root = new TreeNode;
   root->leftMostChild = leftMostChild.getRoot();
   root->rightSibling = rightSibling.getRoot();
   root->element = E;
}

/*-------------------------------------------------------------------------
 *  getRoot -- Returns the root of a given node
 *    Args:	
 *    Returns:	treeptr
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
treeptr Tree::getRoot()
{
  return(root);
}	/*  End of getRoot		End of getRoot   */


/*-------------------------------------------------------------------------
 *  max -- max of two integer variables
 *    Args:int, int	
 *    Returns:	returns the maximum of two numbers
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
int Tree::max(int x, int y) {
  if (x > y) 
    return(x);
  else
    return(y);
}


/*-------------------------------------------------------------------------
 *   -- makeTreeHelper a private function
 *    Args:	
 *    Returns: tree
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/

treeptr Tree::makeTreeHelper(treeptr ptr,int i) {
  if (ptr == NULL) {
    ptr = new TreeNode;
    ptr->element = i;
    ptr->leftMostChild = NULL;
    ptr->rightSibling = NULL;
  }
   else if (i < ptr->element) 
     ptr->leftMostChild = (treeptr) makeTreeHelper(ptr->leftMostChild,i);
   else if (i > ptr->element)
     ptr->rightSibling = (treeptr) makeTreeHelper(ptr->rightSibling,i);
 return(ptr);
}

/*-------------------------------------------------------------------------
 *   -- printTreeHelper a private function recursively prints elements in the tree
 *    Args:	
 *    Returns: tree
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/


void Tree::printTreeHelper(treeptr ptr,int val) {
  if (ptr != NULL) {
    printTreeHelper(ptr->leftMostChild,0);
    cout << " " << ptr->element << " value " << val << endl ;
    printTreeHelper(ptr->rightSibling,1);
  }
}


/*-------------------------------------------------------------------------
 *  printTree -- public interface function to printTree
 *    Args:	
 *    Returns:	Nothing
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
void Tree::printTree() {
  if (root != NULL)
    printTreeHelper(root,0);
  else
    cout << "root is NULL\n";
}

/*-------------------------------------------------------------------------
 *  makeTree -- create a tree with leftMostChild, rightSibling
 *    Args:	
 *    Returns:	makes the tree
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/


void Tree::makeTree(int *array, int n) {
  int i = 0;
  root = new TreeNode;
  root->leftMostChild = NULL;
  root->rightSibling = NULL;
  root->element = 0;
 
  while (i < n) {
      root->leftMostChild = (treeptr) makeTreeHelper(root->leftMostChild,array[i]);
      i++;
      
   }
}


/*-------------------------------------------------------------------------
 *  numNodesLevel --  returns the number nodes at a particular level 
 *    Args:	
 *    Returns:	int
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
//Complete This Function
int Tree::numNodesLevel(treeptr ptr, int lev, int curlev) {
    if(lev==1){return 1;}//at first level there is only one node
    if(curlev>lev){return 0;}
    if(ptr->rightSibling==NULL && ptr->leftMostChild==NULL){
        if(curlev==lev){return 1;}
        else{return 0;}
    }//if the node has no branches then return 0 or 1 according to its level
    else if(ptr->rightSibling==NULL && ptr->leftMostChild!=NULL){
        if(curlev==lev){return numNodesLevel( ptr->leftMostChild,lev,curlev+1)+1;}
        else{return numNodesLevel( ptr->leftMostChild,lev,curlev+1);}
    }//if it has only left branch then find number of nodes in that branch according to its level
    else if(ptr->rightSibling!=NULL && ptr->leftMostChild==NULL){
        if(curlev==lev){return numNodesLevel(ptr->rightSibling,lev,curlev)+1;}
        else{return numNodesLevel(ptr->rightSibling,lev,curlev);}
    }//if it has only right branch then find number of nodes in that branch according to its level
    else{
        if(curlev==lev){
            return numNodesLevel(ptr->rightSibling,lev,curlev)+numNodesLevel(ptr->leftMostChild,lev,curlev+1)+1;
        }
        else{return numNodesLevel(ptr->rightSibling,lev,curlev)+numNodesLevel(ptr->leftMostChild,lev,curlev+1);}
    }////if it has both the branches then find number of nodes in both branches according to its level
}


/*-------------------------------------------------------------------------
 *  height -- returns the height of a tree
 *    Args:	
 *    Returns:	int
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
//Complete This Function
int Tree::height(treeptr ptr) {
    if(ptr->rightSibling==NULL && ptr->leftMostChild!=NULL){return height(ptr->leftMostChild)+1;}//if the node has only left branch the find the height of left branch and add one
    else if(ptr->rightSibling==NULL && ptr->leftMostChild==NULL){return 0;}//if it has neither branches then return 0
    else if(ptr->rightSibling!=NULL && ptr->leftMostChild==NULL){return height(ptr->rightSibling);}//if it has only right branch then find the height of right branch
    else{return max(height(ptr->rightSibling),height(ptr->leftMostChild)+1);}//if it has both the branches then find the max among them 
}


/*-------------------------------------------------------------------------
 *  main -- Main program
 *    Args:	
 *    Returns:	int
 *    Throws:	
 *    See:	
 *    Bugs:	
 -------------------------------------------------------------------------*/
int main() {
  int hght,lev;
  Tree T1;
  int i, n;
  int *array;
  cin >> n;
  array = new int [n];
  for (i = 0; i < n; i++)
    cin >> array[i];
  
  T1.makeTree(array, n);
  hght = T1.height(T1.getRoot());
  cout << "Height of the tree is: " << hght << endl;
  
  
  for(lev = 1; lev <= hght+1; lev++)
  {
        cout << "Number of nodes at level " << lev << ": "  << T1.numNodesLevel(T1.getRoot(),lev,1) << endl;
  }
  
  return 0;
}