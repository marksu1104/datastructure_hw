#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct treeNode{
    int data;
    struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *CreateNode(int data,treeNode *parent){
    treeNode *temp = new treeNode;
    if(data == -1){
        temp = nullptr;
    }
    else{
        temp->data = data;
        temp->left = temp->right = nullptr;
        temp->parent = parent;
    }
    return temp;
}

treeNode *InsertNode(treeNode *node,int data){
    if(node == nullptr){
        node = CreateNode(data,nullptr);
        return node;
    }
    treeNode *current = node;
    queue<treeNode *> q;

    while(current){
        if(current->left != nullptr){
            q.push(current->left);   
        }
        else{
            current->left = CreateNode(data,current);
            return current->left; 
        }

        if(current->right != nullptr){
            q.push(current->right);   
        }
        else{
            current->right = CreateNode(data,current);
            return current->right; 
        }
        current = q.front();
        q.pop();
    }
    return nullptr;
}

treeNode *search_node_ptr;
void search_node(treeNode *node,int key){
    if(node == nullptr) return ;
    
    if(node->data == key) search_node_ptr = node;
    
    search_node(node->left,key);
    search_node(node->right,key);
}

vector<int> output_node,not_answer_node;
void find_distance_node(treeNode *node,int distance){
    if(node == nullptr || distance < 0) return;
    if(distance == 0) {
        int data = node->data;
        if(find(not_answer_node.begin(),not_answer_node.end(),data) == not_answer_node.end()){
            output_node.push_back(data);
        }     
    }
    else{
        not_answer_node.push_back(node->data);
    }
    find_distance_node(node->left,distance-1);
    find_distance_node(node->right,distance-1);
    find_distance_node(node->parent,distance-1);
}

treeNode *Input(){
    treeNode *root = nullptr;
    int node_num;
    cin >> node_num;
    for(int i=0; i<node_num; i++){
        int node_input;
        cin >> node_input;
        if(i == 0){
            root = InsertNode(root,node_input);
        }
        else{
            InsertNode(root,node_input);
        }    
    }
    return root;
}

void Output(treeNode *node){
    queue<treeNode*> q;
    q.push(node);

    while(!q.empty()){
        treeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if(current->left != nullptr){
            q.push(current->left);
        }

        if(current->right != nullptr){
            q.push(current->right);
        }
    }
}

int main(){
    int target_node,distance;
    treeNode *root = Input();
    cin >> target_node >> distance;
    search_node(root,target_node);
    find_distance_node(search_node_ptr,distance);

    sort(output_node.begin(),output_node.end());
    if(output_node.empty()==true){
        cout << "NULL" ;
    }
    else{
        for(auto it = output_node.end()-1;it >= output_node.begin();it--){
            cout << *it << " ";
        }
    }
    return 0;
}