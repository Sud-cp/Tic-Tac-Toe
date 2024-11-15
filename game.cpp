#include<bits/stdc++.h>
using namespace std;

void printgame(char c[]){
    cout<<"  "<<c[0]<<" | "<<c[1]<<" | "<<c[2]<<endl;
    cout<<"____|___|____"<<endl;
    cout<<"  "<<c[3]<<" | "<<c[4]<<" | "<<c[5]<<endl;
    cout<<"____|___|____"<<endl;
    cout<<"  "<<c[6]<<" | "<<c[7]<<" | "<<c[8]<<endl;
    cout<<"    |   |"<<endl;
}

bool checkwin(int game[],int player){
    return ((game[0] == player && game[1] == player && game[2] == player) ||
           (game[3] == player && game[4] == player && game[5] == player) ||
           (game[6] == player && game[7] == player && game[8] == player) ||
           (game[0] == player && game[3] == player && game[6] == player) ||
           (game[1] == player && game[4] == player && game[7] == player) ||
           (game[2] == player && game[5] == player && game[8] == player) ||
           (game[0] == player && game[4] == player && game[8] == player) ||
           (game[2] == player && game[4] == player && game[6] == player));
}

void checkpos(int game[]){

    for (int i = 0; i < 9; i++)
    {
        if(game[i]==-1){
        game[i]=1;
        if(checkwin(game,1)){
            //game[i]=1;
            return;
        }else
            game[i]=-1;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if(game[i]==-1){
        game[i]=0;
        if(checkwin(game,0)){
            game[i]=1;
            return;
        }else
            game[i]=-1;
        }
    }

    vector<int> list;
    for (int i = 0; i < 9; i++) {
        if (game[i] == -1) list.push_back(i);
    }

    int list_size = list.size();
    int random_index = rand() % list_size;
    game[list[random_index]]=1; 
}

int main(){
    int game[9];
    char c[9];
    for (int i = 0; i < 9; i++)
    {
        game[i]=-1;
        c[i]=' ';
    }
    
    int n;

    printgame(c);
    for (int i = 0; i < 9; i++)
    {
        cout<<"Enter your position: ";
        cin>>n;
        n--;
        if(n<0 || n>=9 || game[n]!=-1){
            cout<<"Invalid move! Try again."<<endl;
            i--;
            continue;
        }
        game[n]=0;
        for (int i = 0; i < 9; i++)
        {   
            if(game[i]==0){
                c[i]='O';
            }else if (game[i]==-1)
            {
                c[i]=' ';
            }else{
                c[i]='X';
            }
        }
        checkpos(game);
        for (int i = 0; i < 9; i++)
        {   
            if(game[i]==0){
                c[i]='O';
            }else if (game[i]==-1)
            {
                c[i]=' ';
            }else{
                c[i]='X';
            }
        }
        printgame(c);
        
        if(checkwin(game,0)){
            cout<<"You win"<<endl;
            break;
        }else if (checkwin(game,1)){
            cout<<"You lose"<<endl;
            break;
        }
    }
    
    return 0;
}
