#include<iostream>
#include<ctime>

// Function Prototypes
void DrawBoard(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);
bool CheckWinner(char *spaces, char player, char computer);
bool CheckTie(char *spaces);

int main(){
    // Initialize board with empty spaces
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X'; // Player symbol
    char computer='O'; // Computer Symbol
    bool running=true; // Game running state

    DrawBoard(spaces); // Function call to draw initial empty board
    while(running){
        PlayerMove(spaces, player); // Function call for player makes a move
        DrawBoard(spaces); // Redraw board after player makes a move
        if(CheckWinner(spaces, player, computer)){
            running=false;
            break;
        }
        else if(CheckTie(spaces)){
            running=false;
            break;
        }

        ComputerMove(spaces, computer); // Function to call computer move
        DrawBoard(spaces); // Redraw board after computer makes a move
        if(CheckWinner(spaces, player, computer)){
            running=false;
            break;
        }
        else if(CheckTie(spaces)){
            running=false;
            break;
        }
    }
    std::cout<<"\nThis Game is created by Ishrakuzzaman Emon\n"

    return 0;
}

// Function to draw the Tic-Tac-Toe board
void DrawBoard(char *spaces){
    std::cout<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<'\n';
}

// Function to handle player move
void PlayerMove(char *spaces, char player){
    int number;
    do{
        std::cout<<"Enter a spot to place a marker (1-9)";
        std::cin>>number;
        number--;
        // Checking if the chosen spot is empty
        if(spaces[number]==' '){
            spaces[number]=player; // Players move
            break;
        }
    }while(!number >0 || !number<8); // Ensure valid input range
}

// Function to handle computer move
void ComputerMove(char *spaces, char computer){
    int number;
    srand(time(NULL));
    while(true){
        number=rand()%9; // Generate a random number between 0-8
        if(spaces[number]==' '){
            spaces[number]=computer; // Place computer's move
            break;
        }
    }
}

// Function to check winner
bool CheckWinner(char *spaces, char player, char computer){
    // Check for Row
    if(spaces[0]!=' ' && (spaces[0] == spaces[1] && spaces[1] == spaces[2])){
        spaces[0]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    } else if(spaces[3]!=' ' && (spaces[3] == spaces[4] && spaces[5] == spaces[6])){
        spaces[3]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    } else if(spaces[6]!=' ' && (spaces[6] == spaces[7] && spaces[7] == spaces[8])){
        spaces[6]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }

    // Check for Columns
    else if(spaces[0]!=' ' && (spaces[0] == spaces[3] && spaces[3] == spaces[6])){
        spaces[0]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    } else if(spaces[1]!=' ' && (spaces[1] == spaces[4] && spaces[4] == spaces[7])){
        spaces[1]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    } else if(spaces[2]!=' ' && (spaces[2] == spaces[5] && spaces[5] == spaces[8])){
        spaces[2]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }

    // Check for Diagonals
    else if(spaces[0]!=' ' && (spaces[0] == spaces[4] && spaces[4] == spaces[8])){
        spaces[0]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    }

    else if(spaces[2]!=' ' && (spaces[2] == spaces[4] && spaces[4] == spaces[6])){
        spaces[2]==player? std::cout<<"YOU WIN!\n" : std::cout<<"YOU LOSE!\n";
    } 
    
    else{
        return false;
    }
    return true; // Player has won
}

// Function to check Tie
bool CheckTie(char *spaces){
    for(int i=0; i<9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout<<"IT'S A TIE!\n";
    return true;
}