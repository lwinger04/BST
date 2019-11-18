// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<int> bst;
    cout << "The number of nodes in tree is " << bst.countNodes() << endl;
    int s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }
    cout << "number of nodes in tree is " << bst.countNodes() << endl;

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;


    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;
    if(!(bst.isEmpty())){
        cout << "tree not empty" << endl;
    }
    cout << bst.countNodes() << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = 89;
    bst.deleteItem(s);

    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    if(bst.isItemInTree(4)){
        cout << "4 is in the BST" << endl;
    }
    if(!(bst.isItemInTree(432))){
        cout << "432 is not in the BST" << endl;
    }
    cout << endl;
    cout << "emptying BST" << endl;
    bst.makeEmpty();
    cout << bst.countNodes() << endl;
    cout << "Finished";

return(EXIT_SUCCESS);
}

