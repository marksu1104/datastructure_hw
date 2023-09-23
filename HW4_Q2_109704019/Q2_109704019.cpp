#include <iostream>

using namespace std;

// You MUST NOT modify this!
struct Snake {
    int ratWeight;
    Snake *nextRat;
    Snake() : ratWeight(0), nextRat(nullptr) {}
    Snake(int x) : ratWeight(x), nextRat(nullptr) {}
    Snake(int x, Snake *nextRat) : ratWeight(x), nextRat(nextRat) {}
};

Snake* digestMiddle(Snake* head) {
    // TODO
    int remain_rats = 0;
    int to_middle_rats;
    Snake* temp2 = head;

    for(;temp2;temp2=temp2->nextRat){
        remain_rats ++;
    }
    
    temp2 = head;

    to_middle_rats = remain_rats/2 +1;
    
    for(;temp2;temp2=temp2->nextRat){
        to_middle_rats--;
        if(to_middle_rats == 1){
            temp2->nextRat = temp2->nextRat->nextRat;
            break;
        }
        if(to_middle_rats == 0){
           temp2->ratWeight = -1;
           break; 
        }
    }

    return head;
}

int** vomitAndCrawl(int rows, int cols, Snake* head, int digestInterval) {
    // TODO
    int** terrarium;
    int count = 1,temprows = 0,tempcols = 0;
    int countD = 0;
    Snake* temp = head;

    terrarium = new int* [rows];
    for(int i = 0; i < rows; i++){
        terrarium[i] = new int [cols];
    }

    for(int i = 0; i< rows; i++){
        for(int j = 0; j<cols; j++){
            terrarium[i][j] = -1;
        }
    }
    
    while(temp->nextRat != 0){

        if(count%4 == 1){
            for(; tempcols < cols-1-count/4; tempcols++){
                terrarium[temprows][tempcols] = temp->ratWeight;
                if(temp->nextRat == 0){ 
                    break;
                }
                temp =  temp->nextRat;

                countD++;
                if(countD == digestInterval){
                    temp = digestMiddle(temp);
                    countD = 0;
                }
            }
        }
        else if(count%4 == 2){
            for(; temprows < rows-1-count/4; temprows++){
                terrarium[temprows][tempcols] = temp->ratWeight;
                if(temp->nextRat == 0){
                    break;
                }
                temp =  temp->nextRat;

                countD++;
                if(countD == digestInterval){
                    temp = digestMiddle(temp);
                    countD = 0;
                }
            }            
        }
        else if(count%4 == 3){
            for(; tempcols > 0+count/4; tempcols--){
                terrarium[temprows][tempcols] = temp->ratWeight;
                if(temp->nextRat == 0){
                    break;
                }
                temp =  temp->nextRat;

                countD++;
                if(countD == digestInterval){
                    temp = digestMiddle(temp);
                    countD = 0;
                }
            }            
        }
        else if(count%4 == 0){
            for(; temprows > 0+count/4-1; temprows--){
                terrarium[temprows][tempcols] = temp->ratWeight;
                if(temp->nextRat == 0){
                    break;
                }
                temp =  temp->nextRat;

                countD++;
                if(countD == digestInterval){
                    temp = digestMiddle(temp);
                    countD = 0;
                }
            }
            temprows ++;
            tempcols ++;            
        }  
        count ++;              
    }

    return terrarium;    
}

// You MUST NOT modify this!
int main()
{
    int rows, cols, numOfRats, digestInterval ;
    cin >> rows >> cols >> numOfRats ;

    Snake* head = new Snake();
    Snake* current = head;

    for(int i=0; i<numOfRats ; i++)
    {
        cin >> current->ratWeight;
        if(i < numOfRats - 1)
        {
            Snake* nextRat = new Snake();
            current->nextRat = nextRat;
            current = current->nextRat;
        }
    }

    cin >> digestInterval;

    int** terrarium = vomitAndCrawl(rows, cols, head, digestInterval);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << terrarium[i][j];
            if(j < cols-1)
                cout << " ";
        }
        if(i < rows-1)
            cout << "\n";
    }

    return 0;
}

