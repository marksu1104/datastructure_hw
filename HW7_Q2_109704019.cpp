#include <iostream>
#include <queue>
#include <vector>

#define MAX_VERTEX 100
#define MAX_level 999999

using namespace std;

typedef struct node{
    int vertex;
    int egde_level;
    struct node* link; 
}node;

node* list[MAX_VERTEX];

void add_egde(int a,int b,int level){
    node* temp = new node;
    temp->vertex = b;
    temp->egde_level = level;
    temp->link = list[a];
    list[a] = temp;
}

int find_shortest_distance(int start,int end,int vertex_num){
    vector<int> distance(vertex_num+1,MAX_level);
    vector<int> prev(vertex_num+1,-1);
    vector<bool> done(vertex_num+1,false);

    distance[start] = 0;
    done[start] = true;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({distance[start],start});
    while(!pq.empty()){
        pair<int,int> min = pq.top();
        pq.pop();
        int vertex = min.second;
        
        for(node* current = list[vertex];current;current = current->link){
            int link_vertex = current->vertex;
            int link_level = current->egde_level;

            if(!done[link_vertex] && max(distance[vertex] , link_level) < distance[link_vertex]){
                distance[link_vertex] = max(distance[vertex] , link_level);
                prev[link_vertex] = vertex;
                pq.push({distance[link_vertex],link_vertex});
            }
        }
        done[vertex] = true;
    }
    return distance[end];
}

int main(){

    int c,s,q;
    cin >> c >> s >> q; 
    for(int i=0; i<s; i++){
        int a,b,level;
        cin >> a >> b >> level;
        add_egde(a,b,level);
        add_egde(b,a,level);

    }

    vector<int> answer;
    for(int i=0; i<q; i++){
        int find_a,find_b;
        cin >> find_a >>  find_b;
        answer.push_back(find_shortest_distance(find_a,find_b,c));
    }

    for(int i=0;i<q;i++){
        if(answer[i] == MAX_level)
            cout << "no path" << endl;
        else
            cout << answer[i] << endl;
    }       
    return 0;
}