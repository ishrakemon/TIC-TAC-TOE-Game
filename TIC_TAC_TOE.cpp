#include<iostream>
#include<ctime>

// Function Prototypes
void DrawBoard(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);

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

        ComputerMove(spaces, computer); // Function to call computer move
        DrawBoard(spaces); // Redraw board after computer makes a move
    }

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
    srand(time(null));
    while(true){
        number=rand()%9;
        if(spaces[number]==' '){
            spaces[number]=computer;
            break;
        }
    }
}
