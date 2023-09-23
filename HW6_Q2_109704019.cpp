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

vector<vector<int>> output_node;
vector<int> pass_node,tt;
void find_max_distance_node(treeNode *node,int distance){
    if(node == nullptr) return;
    int data = node->data;
    if(find(pass_node.begin(),pass_node.end(),data) != pass_node.end()) return;
    pass_node.push_back(data);
    
    if(output_node.size() == distance){
        output_node.push_back(tt);
    }
    output_node[distance].push_back(data);

    find_max_distance_node(node->left,distance+1);
    find_max_distance_node(node->right,distance+1);
    find_max_distance_node(node->parent,distance+1);
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
    cin >> target_node;
    search_node(root,target_node);
    find_max_distance_node(search_node_ptr,0);

    sort(output_node.back().begin(),output_node.back().end());


    for(auto it = output_node.back().end()-1;it >= output_node.back().begin();it--){
        cout << *it << " ";
    }

    return 0;
}