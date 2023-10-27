/**
 * @author Aimen Durrani
 * 20/9/2023
*/

#include<iostream>
using namespace std;

void tictactoe(){

    //declaring all essential variables required for the program 
    char board[3][3]={{'1','2','3'},{'3','4','5'},{'6','7','8'}}; //2D array
    int move;
    int count;
    int tries;
    int row, col;
    string player1, player2; //for storing the names of players (optional)

    //printing the board;
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;

    //retrieving the player names
    cout<<"Player 1 enter your name: ";
    cin>>player1;
    cout<<"Player 2 enter your name: ";
    cin>>player2;

    cout<<endl;

    //assigning symbols
    cout<<player1<<" your symbol is 'x' "<<endl;
    cout<<player2<<" your symbol is 'o' "<<endl;

    cout<<endl;

    //gamelogic
    count=1;
    while(count<=9){
        tries = count % 2;
        if(tries==1){
            cout<<player1<<" (Player1) make a move between 1-9: ";
            cin>>move;
        }
        else{
            cout<<player2<<" (Player2) make a move between 1-9: ";
            cin>>move;
        }

        if(move < 1 || move > 9){
            cout<<"Invalid move. ";
            continue;
        }

        //calculating rows and coloumns
        row = (move - 1)/3;
        col = (move-1)%3;

        if(board[row][col]=='x' || board[row][col]=='o'){
            cout<<"Invalid move. This place is already taken, try again. ";
            continue;
        }

        //ternary operator
        board[row][col] = (tries==1)? 'x' : 'o';
        
        //updated board
        cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
        cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;
        cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
        cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;
        cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
        cout<<"-"<<" | "<<"-"<<" | "<<"-"<<endl;

        //checking for a win or draw
        if(board[0][0]=='x' && board[0][1]=='x' && board[0][2]=='x' || board[0][0]=='x' && board[1][0]=='x' && board[2][0]=='x' ||
         board[2][0]=='x' && board[2][1]=='x' && board[2][2]=='x' || board[0][2]=='x' && board[1][2]=='x' && board[2][2]=='x' ||
         board[0][0]=='x' && board[1][1]=='x' && board[2][2]=='x' || board[0][2]=='x' && board[1][1]=='x' && board[2][0]=='x'){
            cout<<player1<<" wins the match"<<endl;
            break;
        }
        else if(board[0][0]=='o' && board[0][1]=='o' && board[0][2]=='o' || board[0][0]=='o' && board[1][0]=='o' && board[2][0]=='o' ||
         board[2][0]=='o' && board[2][1]=='o' && board[2][2]=='o' || board[0][2]=='o' && board[1][2]=='o' && board[2][2]=='o' ||
         board[0][0]=='o' && board[1][1]=='o' && board[2][2]=='o' || board[0][2]=='o' && board[1][1]=='o' && board[2][0]=='o'){
            cout<<player2<<" wins the match"<<endl;
            break;
         }
         else if(count==9){
            cout<<"It's a draw"<<endl;
            break;
         }

        count+=1;

    }
}

int main(){

   tictactoe();

   char choice;
   
   //exception handling
   try{

    while(true){
        cout<<"Do you want to play again? enter 'y' or 'n' ";
        cin>>choice;

        if(choice=='y'){
          tictactoe();
        }
        else if(choice=='n'){
          break;
        }
        else{
            cout<<"Invalid Input, enter 'y' or 'n': ";
            cin>>choice;

            if(choice=='y'){
              tictactoe();
            }
            else if(choice=='n'){
              break;
            }
        }
    }
    
   }
    catch (exception& e){
       cerr<<e.what()<<endl;
    }
   
    return 0;
}