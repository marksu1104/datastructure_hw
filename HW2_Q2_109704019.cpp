#include <iostream>
#define MAX_TERMS 100

using namespace std;

/*size of terms array*/
typedef struct{
    float coef;
    int expon;
    }polynomial;
polynomial terms [MAX_TERMS];
int avail = 0;

void attach(int avi,int start){
    terms[avi].coef = terms[start].coef;
    terms[avi].expon = terms[start].expon;
}

int add(int starta, int finisha, int startb, int finishb, int avail){
    while(starta <= finisha && startb <= finishb) {
        if(terms[starta].expon == terms[startb].expon){
            terms[avail].coef = terms[starta].coef + terms[startb].coef;
            terms[avail].expon = terms[starta].expon;
            
            starta ++;
            startb ++;
        }
        else if(terms[starta].expon > terms[startb].expon){
            attach(avail,starta);
            starta ++;
        }
        else if(terms[starta].expon < terms[startb].expon){
            attach(avail,startb);          
            startb ++;
        }
        avail ++;
    }

    for(; starta <= finisha; avail ++){
        attach(avail,starta);
        starta++;
    }

    for(; startb <= finishb; avail ++){
        attach(avail,startb);
        startb++;
    }
    return avail;
}

int main() {

    int n,m,temp;
    cin >> n >> m;
    int starta = 1,startb = n+1,finisha = n,finishb = n+m;
    avail = n+m+1;
    
    for(int i=1; i<= n+m; i++){
        cin >> terms[i].coef >> terms[i].expon;
    }

    int starta2 = avail,finisha2 = starta2 + m -1;
    while(starta <= finisha){

        for(int i=startb ; i<=finishb ; i++){
            terms[avail].coef = terms[starta].coef * terms[i].coef;
            terms[avail].expon = terms[starta].expon + terms[i].expon;
            avail ++;
        }
       
        int startb2 = finisha2 + 1, finishb2 = startb2 + m -1;
        temp = avail;
        if(starta > 1){
            avail = add(starta2,finisha2,startb2,finishb2,avail);
            starta2 = temp;
            finisha2 = avail -1;
        }
        starta ++;
    }
 
    for(int i= temp; i < avail ; i++){
        cout << terms[i].coef << " " << terms[i].expon << endl;
    }

    return 0;
}