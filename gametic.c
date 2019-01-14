#include<stdio.h>
#include<conio.h>

void init_maze(char *maze){
    for(int i =0 ; i< 3 ;i++){
       for(int j =0 ; j< 3 ;j++){
        *(maze+i*3+j) ='?';
       }
    }

}
void show_maze(char *maze){
    printf("\n");
    for(int i =0 ; i< 3 ;i++){
       for(int j =0 ; j< 3 ;j++){
        printf("| %c ",*(maze+i*3+j));
       }
       printf("\n------------\n");
    }

}
void make_move(char *maze,int pos,int *turn){
    system("cls");
    int row = (pos-1)/3;
    int col = (pos-1)%3;
    if(*(maze+row*3+col)=='?'){
        if(*turn){
            *(maze+row*3+col) ='O';
        }
        else{
            *(maze+row*3+col) ='X';
        }
  }
  else{
    printf("Invalid move, ");
    *turn=*turn?0:1;
  }
}
int check_win(char maze[3][3]){
    char hori[3]={'m','m','m'};
    char ver[3];
    char diag[3];
    char seconddiag[3];
    for(int i = 0;i<3 ;i++){
        for(int j = 0;j<3 ;j++){
            hori[j]=maze[i][j];//single row

            ver[j]=maze[j][i];//single column
        }

        if(hori[0]==hori[1] && hori[1]==hori[2] && hori[0]!='?'){ //check horizontally win (row wise)
           return 1;
        }
        if(ver[0]==ver[1] && ver[1]==ver[2] && ver[0]!='?'){  //check Vertical win (Column wise)
                getch();
            return 1;
        }
        diag[i]=maze[i][i];
        seconddiag[i] =maze[i][2-i];
    }
    if(diag[0]==diag[1] && diag[1]==diag[2] && diag[0]!='?'){  //check diagonal win (diagonal wise wise)
            getch();
            return 1;
    }
        if(seconddiag[0]==seconddiag[1] && seconddiag[1]==seconddiag[2] && seconddiag[0]!='?'){  //check Vertical win (lol wise)
            getch();
            return 1;
    }

    return 0;

}
int main(){
        char maze[3][3],player1[10] ,player2[10];
        int turn =0,pos=0;//turn is 0 for player1,1 for player2
        printf("Enter player one name \n");
        scanf("%s",&player1);
        printf("Enter player one name \n");
        scanf("%s",&player2);
        system("cls");


    init_maze(&maze);
    show_maze(&maze);
    while(pos!=11){
        printf("player %s choose your next position",turn?player2:player1);
        scanf("%d",&pos);
        make_move(&maze,pos,&turn);
        turn=turn?0:1;
        show_maze(&maze);
        if(check_win(maze)){
            printf("***Player %s has won ***",turn?player2:player1);
            break;
        }
    }
}
