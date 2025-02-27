#include<iostream>
#include<ctime>

// Function Prototypes
void DrawBoard(char *spaces);
void PlayerMove(char *spaces, char player);

int main(){
    // Initialize board with empty spaces
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X'; // Player symbol
    char computer='O'; // Computer Symbol
    bool running=true; // Game running state

    DrawBoard(spaces); // Function call to draw initial empty board
    while(running){
        PlayerMove(spaces, player);
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
void PlayerMove(char *spaces, char player){
    int number;
    do{
        std::cout<<"Enter a spot to place a marker (1-9)";
        std::cin>>number;
        number--;
        if(spaces[number]==' '){
            spaces[number]=player;
            break;
        }
    }while(!number >0 || !number<8);
}