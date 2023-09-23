#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// node
treeNode *CreateNode(int data)
{
    treeNode *temp = new treeNode;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

treeNode *InsertLevelOrder(treeNode *node, int data)
{
    if (node == nullptr)
    {
        node = CreateNode(data);
        return node;
    }

    std::queue<treeNode *> q;
    treeNode *current = node;

    while (current)
    {
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        else
        {
            current->left = CreateNode(data);
            return current->left;
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
        else
        {
            current->right = CreateNode(data);
            return current->right;
        }
        current = q.front();
        q.pop();
    }
    return nullptr;
}

// hint: you can use InsertLevelOrder()
// reference of level-order insertion:
// http://alrightchiu.github.io/SecondRound/binary-tree-jian-li-yi-ke-binary-tree.html#func2
// you can modify this function
treeNode *input()
{
    treeNode *root = CreateNode(0);
    treeNode *red = InsertLevelOrder(root, 1);
    treeNode *black = InsertLevelOrder(root, 1);
    // TODO

    int round,input;
    cin >> round;

    for(int i=1; i<=round; i++){
        for(int j=0; j<pow(2,i+1); j++){

            cin >> input;
            if(i%2 == 1){
                if(j<pow(2,i+1)/2){
                    InsertLevelOrder(red,input);
                }
                else{
                    InsertLevelOrder(black,input);
                }
            }
            else{
                if(j<pow(2,i+1)/2){
                    InsertLevelOrder(black,input);
                }
                else{
                    InsertLevelOrder(red,input);
                }
            }

        }
    }

    return root;
}

bool CanGoHome(treeNode *root)
{
    // TODO

    queue<treeNode*> q;
    vector<int> v;
    q.push(root);

    while(!q.empty()){

        treeNode* current = q.front();
        q.pop();
        v.push_back(current->data);

        if(current->left != nullptr){
            q.push(current->left);
        }

        if(current->right != nullptr){
            q.push(current->right);
        }
    }    
    
    int round_size = v.size();
    int pow_count = 1;
    for(int i=3; i<round_size; i=i+pow(2,pow_count)){
        int temp = 1;
        pow_count++;
        for(int j=i; j<i+pow(2,pow_count)/2; j++){
            if(v[j] != v[i+pow(2,pow_count)-temp]){
                
                return true;
                
            }
            temp++;
        } 
    }
    return false;
    
}

// DO NOT modify main function
int main()
{
    treeNode *root = input();
    if (CanGoHome(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
