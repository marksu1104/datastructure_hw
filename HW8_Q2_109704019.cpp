#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_VERTEX 1000

using namespace std;

typedef struct node{
    int vertex;
    struct node* link; 
}node;

node* list[MAX_VERTEX];
void add_egde(int a,int b){
    node* temp = new node;
    temp->vertex = b;
    temp->link = list[a];
    list[a] = temp;
}

void isTopology(vector<int> ref, vector<int> &path, bool *answer){
    vector<int>::iterator it = find(ref.begin(),ref.end(),0);
    
    if(it == ref.end()){
        *answer = false;
        return;
    }
    int index = distance(ref.begin(),it);
    ref[index] = -1;
    path.push_back(index);
    
    if((int) count(ref.begin(),ref.end(),-1) == (int) ref.size()){
        *answer = true;
        return;
    }

    for(node* current = list[index];current;current = current->link){
        ref[current->vertex]--;
    }
    isTopology(ref,path,answer);
}

int main(){
    int numActions,numPrereq;
    
    cin >> numActions >> numPrereq;
    vector<int> ref(numActions,0) ,path;
    for(int i=0;i<numPrereq;i++){
        int a,b;
        cin >> a >> b;
        add_egde(b,a);
        ref[a]++;
    }

    bool answer;
    isTopology(ref,path,&answer);

    if(answer == true){
        for(int i=0; i<numActions; i++){
            cout << path[i] << " ";
        }
    }
    else{
        cout << -1;
    }
    
    return 0;
}