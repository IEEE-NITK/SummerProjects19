#include<bits/stdc++.h>
#define size 8
#define depth 4
using namespace std;

char board[size][size];         //Matrix representing the actual board
char m_board[size][size];        //Matrix representing the board for calculating minimax
int level[size];             //To track the levels in each column
int cost[size]={0};         //To track the cost in one bfs
int m_level[size];     //To track the levels in each column for calculating minimax
int u_move,c_move;        //To store the moves

bool game_over = false;
bool user_won = false;


void initialise_board(){            //Function to clear the board
  int i,j;
  for(i=0;i<size;i++){
    level[i]=size-1;
    m_level[i]=size-1;
    for(j=0;j<size;j++){
      board[i][j]='.';
      m_board[i][j]='.';
    }
  }
}



void show_board(){                      //Function to display the board
  cout<<"\nCurrent board status:\n";
  int i,j;
  for(j=0;j<size;j++){
    cout<<j+1<<" ";
  }
  cout<<endl;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<"\n";
  }
}


void set_val_to_0(int *arr){                 //Function to set all values of 1D array to 0
    for(int i=0;i<size;i++){
      arr[i]=0;
    }
}


void set_val1(int arr1[], int arr2[]){                 //Function to copy one 1D array to other
    for(int i=0;i<size;i++){
        arr1[i]=arr2[i];
    }
}



void set_val2(char arr1[][size], char arr2[][size]){      //Function to copy one 2D matrix to other
  int i,j;
  for(i=0;i<size;i++){
      for(j=0;j<size;j++){
          arr1[i][j]=arr2[i][j];
      }
  }
}



bool check(char matrix[size][size]){                //Function to check if the matrix is filled
  int i;
  for(i=0;i<size;i++){
      if(matrix[i]>=0) return true;
  }
  return false;
}



int end_check(bool user, int x , int y, bool last, char board1[size][size]){                        //Function to check if a row is formed
  char pawn = user ? '*' : '#';
    if(x>=1){
        if(x>=2){
            if(pawn==board1[x-1][y] && pawn==board1[x-2][y]){
                if(last){
                    game_over = true;
                    user_won = user;
                }
                return user? 1 : -1;
            }
            if(y>=2){
                if(pawn==board1[x-1][y-1] && pawn==board1[x-2][y-2]){
                    if(last){
                        game_over = true;
                        user_won = user;
                    }
                    return user? 1 : -1;
                }
            }
            if(y<size-2){
                if(pawn==board1[x-1][y+1] && pawn==board1[x-2][y+2]){
                    if(last){
                        game_over = true;
                        user_won = user;
                    }
                    return user? 1 : -1;
                }
            }
        }
    }
    if(x<size-1){
        if(x<size-2){
            if(pawn==board1[x+1][y] && pawn==board1[x+2][y]){
                if(last){
                    game_over = true;
                    user_won = user;
                }
                return user? 1 : -1;
            }
            if(y>=2){
                if(pawn==board1[x+1][y-1] && pawn==board1[x+2][y-2]){
                    if(last){
                        game_over = true;
                        user_won = user;
                    }
                    return user? 1 : -1;
                }
            }
            if(y<size-2){
                if(pawn==board1[x+1][y+1] && pawn==board1[x+2][y+2]){
                    if(last){
                        game_over = true;
                        user_won = user;
                    }
                    return user? 1 : -1;
                }
            }
        }
    }
    if(y>=2){
        if(pawn==board1[x][y-1] && pawn==board1[x][y-2]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
    }
    if(y<size-2){
        if(pawn==board1[x][y+1] && pawn==board1[x][y+2]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
    }
    if(y>=1 && y<size-1){
        if(pawn==board1[x][y+1] && pawn==board1[x][y-1]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
    }
    if(x>=1 && x<size-1){
        if(pawn==board1[x-1][y] && pawn==board1[x+1][y]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
    }
    if(x>=1 && x<size-1 && y>=1 && y<size-1){
        if(pawn==board1[x-1][y-1] && pawn==board1[x+1][y+1]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
        if(pawn==board1[x-1][y+1] && pawn==board1[x+1][y-1]){
            if(last){
                game_over = true;
                user_won = user;
              }
            return user? 1 : -1;
        }
    }
    return 0;
}



void user_move(){                            //Function dealing with user inputs
  int i,j;
  u_move=-1;
  while(!(u_move<=size && u_move>=1 && level[u_move-1]>-1)){
    cout<<"Enter your move(chose the column name): ";
    cin>>u_move;
  }
  u_move--;
  i = level[u_move];
  j = u_move;
  board[i][j] = '*';
  end_check(true,i,j,true,board);
  level[u_move]--;
}



int minimax(int dep, bool user){              //Function to implement minimax
    int i,j,val;
    char pawn = user ? '*' : '#';
    int array[size];
    set_val_to_0(array);
    if(!check(m_board)){
        return 0;
    }
    if(dep == depth){
        for(j=0;j<size;j++){
            if(m_level[j]<0){
                if(user)
                  array[j]=2;
                else
                  array[j]=-2;
                continue;
            }
            i=level[j];
            m_board[i][j]=pawn;
            array[j] = end_check(user,i,j,false,m_board);
            m_board[i][j]='.';
        }
    }
    else{
        for(j=0;j<size;j++){
            if(m_level[j]<0){
              if(user)
                array[j]=2;
              else
                array[j]=-2;
                continue;
            }
            i=level[j];
            m_board[i][j]=pawn;
            val = end_check(user,i,j,false,m_board);
            if(val!=0){
                array[j]=val;
            }
            else{
                m_level[j]--;
                array[j] = minimax(dep+1,!user);
                m_level[j]++;
            }
            m_board[i][j]='.';
        }
      }
    val=0;
    if(user){
        for(i=0;i<size;i++){
            val = min(val,array[i]);
        }
    }
    else{
        for(i=0;i<size;i++){
            val = max(val,array[i]);
        }
    }
    return val;
}

void comp_move(){                      //Function to calculate the computer's move
    int j,i,max,index,val;
    bool done = false;
    set_val_to_0(cost);
    set_val2(m_board,board);
    set_val1(m_level,level);
    for(j=0;j<size;j++){
        if(m_level[j]>0){
            i = level[j];
            m_board[i][j]='#';
            val = end_check(false,i,j,false,m_board);
            if(val==-1){
                index = j;
                done = true;
                break;
            }
            m_board[i][j]='*';
            val = end_check(true,i,j,false,m_board);
            if(val==1){
                index = j;
                done = true;
                break;
            }
        }
    }
    if(!done){
      for(j=0;j<size;j++){
          if(m_level[j]<0){
            cost[j]=-2;
              continue;
          }
          i=level[j];
          m_board[i][j]='#';
          m_level[j]--;
          cost[j] = minimax(1,false);
          m_level[j]++;
          m_board[i][j]='.';
      }
      max = cost[0];
      index=0;
      for(j=1;j<size;j++){
          if(max<cost[j]){
              max= cost[j];
              index=j;
          }
      }
    }
    board[level[index]][index]='#';
    m_board[level[index]][index]='#';
    c_move = index;
    end_check(false,level[index],index,true,board);
    level[index]--;
}


void connect3(){                              //Function controlling the game
  game_over = false;
  user_won=false;
  while(!game_over){
    if(!check(board)){
      game_over = false;
      return ;
    }
    show_board();
    user_move();
    if(game_over){
      return ;
    }
    if(!check(board)){
      game_over = false;
      return ;
    }
    comp_move();
    cout<<"Computer's move: "<<c_move+1<<endl;
    if(game_over){
      return ;
    }
  }
}


int main(){
  char ch='y';
  while(ch=='y' || ch=='Y'){
      initialise_board();
      cout<<"Welcome to Connect3 game. Your move: *. Computer's move: #.\n";
      cout<<"Given a 8*8 board, your goal in the game is to make a row of 3 '*' before the computer makes a row of 3 '#''.\n";
      cout<<"\n\t\t\tGAME BEGINS\n";
      connect3();
      show_board();
      if(game_over){
        if(user_won){
          cout<<"\t\t\tYOU WON :)\n\n";
        }
        else{
          cout<<"\t\t\tYOU LOST :(\n\n";
        }
      }
      else{
        cout<<"\t\t\tIT'S A TIE :|\n\n";
      }
      ch = '.';
      while(!(ch=='n'|| ch=='N' || ch=='y' || ch=='Y')){
        cout<<"Do you want to play again?  y/n\t";
        cin>>ch;
      }
  }
  return 0;
}
