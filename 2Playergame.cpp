#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
bool checkWinner(char *spaces, char player1, char player2);
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;
    int turn = 0;

    drawBoard(spaces);

    while(running){
        if(turn % 2 == 0){
            cout << "Player 1 (X) turn:\n";
            playerMove(spaces, player1);
        } else {
            cout << "Player 2 (O) turn:\n";
            playerMove(spaces, player2);
        }
        drawBoard(spaces);
        if(checkWinner(spaces, player1, player2)){
            running = false;
            break;
        }else if(checkTie(spaces)){
            cout << "It's a tie!\n";
            running = false;
            break;
        }
        turn++;
    }
    return 0;
}

void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0]<< "  |  " << spaces[1]<< "  |  " << spaces[2]<< "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3]<< "  |  " << spaces[4]<< "  |  " << spaces[5]<< "  " << endl;
    cout << "_____|_____|_____" << endl;    
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6]<< "  |  " << spaces[7]<< "  |  " << spaces[8]<< "  " << endl;
    cout << "     |     |     " << endl;   
    cout << endl;
}

void playerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter a spot to play 1-9: ";
        cin >> number;
        number--;
        if(number >= 0 && number <= 8 && spaces[number] == ' '){
            spaces[number] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }while(true);
}

bool checkWinner(char *spaces, char player1, char player2){
    int winCombos[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // cols
        {0,4,8},{2,4,6}          // diags
    };
    for(int i=0; i<8; i++){
        int a = winCombos[i][0], b = winCombos[i][1], c = winCombos[i][2];
        if(spaces[a] != ' ' && spaces[a] == spaces[b] && spaces[b] == spaces[c]){
            if(spaces[a] == player1)
                cout << "Player 1 (X) wins!\n";
            else
                cout << "Player 2 (O) wins!\n";
            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces){
    for(int i=0; i<9; i++){
        if(spaces[i] == ' ')
            return false;
    }
    return true;
}