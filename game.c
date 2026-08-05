#include <stdio.h>
#include <stdlib.h>
void displayboard(char board[3][3]){
     int i,j;
     for(i=0;i<3;i++){
        for(j=0; j<3; j++){
            printf(" %c ",board[i][j]);
            if (j!=2){
                printf(" | ");
            }
        }
        printf("\n");
        if (i!=2){
            printf("----+-----+----");
            printf("\n");
        }
    }
}
void showavailable(char board[3][3]){
     printf("Available position- ");
     int i,j;
     for(i=0;i<3;i++){
        for(j=0; j<3; j++){
            if (board[i][j]!='X'&&board[i][j]!='O')
            {
                printf(" %c ",board[i][j]);
            }    
        }
    }
    printf("\n");
    printf("\n");
}
int checkwinner(char board[3][3]){
    for(int i=0; i<3; i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]
            &&(board[i][1]=='X'||board[i][1]=='O')){
                return 1;
            }
    }
    for(int i=0; i<3; i++){
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]
        &&(board[0][i]=='X'||board[0][i]=='O')){
            return 1;
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]
    &&(board[0][0]=='X'||board[0][0]=='O')){
        return 1;
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]
    &&(board[0][2]=='X'||board[0][2]=='O')){
        return 1;
    }
    return 0;
}
int main(){
     int i,j,position,row,column,moves=0;
     char num = '1';
     char board[3][3];
     char currentplayer = 'X';
     for(i=0;i<3;i++){
        for(j=0; j<3; j++){
            board[i][j]=num;
            num++;
        }
    }
     while(1){
     system("cls");
     printf("Player %c turn.\n",currentplayer); 
     printf("\n");
     displayboard(board);
     printf("\n");
     showavailable(board);
     printf("enter position = ");
     scanf("%d",&position);
     if (position<1||position>9){
        printf("invalid move.\n");
     }
     else{
     row=(position-1)/3;
     column=(position-1)%3;
     if(board[row][column]=='X'||board[row][column]=='O'){
        printf("invalid move\n");
     }
     else{
        board[row][column] = currentplayer;
        moves++;
        if(checkwinner(board)){
            system("cls");
            displayboard(board);
            printf("\n");
            printf("The winner is- %c\n", currentplayer);
            printf("\n");
            break;
        }
        if(moves==9){
            displayboard(board);
            printf("Its a draw.\n");
            break;
        }
        if (currentplayer=='X')
        currentplayer='O';
        else
        currentplayer='X';
     }
         }
    }    
}