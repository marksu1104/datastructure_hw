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

    int n,m;
    cin >> n >> m;
    int starta = 1,startb = n+1,finisha = n,finishb = n+m;
    avail = n+m+1;
    for(int i=1; i<= n+m; i++){
        cin >> terms[i].coef >> terms[i].expon;
    }

    avail = add(starta,finisha,startb,finishb,avail);

    for(int i= finishb+1; i < avail ; i++){
        cout << terms[i].coef << " " << terms[i].expon << endl;
    }
    return 0;
}