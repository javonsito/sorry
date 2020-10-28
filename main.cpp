// Program: Sorry Board
// Developed by: Javon Gordon, Kaleb Walker, and Thomas Chandler
// Dated: December 22, 2019
// This program is based on the Sorry board game. The purpose is a project assigned by Anthony Ford. Please enjoy

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

bool gameOver = false;
char board[50];
char piece [4] = {'$', '@', '#', '%'};
int placePlayer1, placePlayer2, placePlayer3, placePlayer4; // This is used to create value for board array
const int player1 = 1, player2 = 2, player3 = 3, player4 = 4; // This is used to create value for the character

void winner (int x, int z) // used to determine winner
{
    int game = 0;
    
    if (x >= 50)
    {
            cout << "Player " << z << " you are the winner." << endl;
    
    
            while (game < 0 || game > 2 )
            {
                cout << "Play again? 1 = Yes or 2 = No" << endl;
                cin >> game;
                cout << "Invalid Entry, please try again" << endl;
            }
        if (game == 1)
        gameOver = false;
        
        else if (game == 0)
            gameOver = true;
    }
}


int diceRoll_1()
{
   
    cout << "Press enter to roll" << endl;
    cin.get();
    srand(unsigned (time(0)));
    int dice1 = rand() % 6 + 1;
    
    return dice1;

}



int diceRoll_2()
{

    cout << "Press enter to roll" << endl;
    cin.get();
    srand(unsigned (time(0)));
    int dice2 = rand() % 6 + 1;

    return dice2;
}


int diceMove(int x, int y, int z) // int x represents the player move; int y represents the player position; int z represent what player (1 - 4)
{

    switch (x)
    {
    case 2:
        cout << "Player_" << z << " moves 2 spaces." << endl;
        y += 2;
        break;
            
    case 3:
        cout << "Player_" << z << " moves 3 spaces." << endl;
        y += 3;
        break;
            
    case 4:

        if (y - 1 >= 0 )
        {
            cout << "Player_" << z <<" moves back a space. " << endl;
            y -= 1;
        }
        else
        {
            cout << "Player_" << z << " you are at the beginning." << endl;
            y = 0;
        }
        break;
            
    case 5:

        cout << "Player_" << z << " moves 5 spaces." << endl;
        y += 5;
    break;
            
    case 6:
        cout << "Player_" << z << " moves 6 spaces." << endl;
        y += 6;

    break;
            
    case 7: // swaps with highest number player
        if (z == 1)
        {
            
            if (placePlayer2 > placePlayer1 && placePlayer2 > placePlayer3 && placePlayer2 > placePlayer4)
            {
                y = placePlayer2;
                placePlayer2 = placePlayer1;
                cout << "Player_2 is in the lead, Player_" << z << " swaps places" << endl;
                
            }
            else if (placePlayer3 > placePlayer1 && placePlayer3 > placePlayer2 && placePlayer3 > placePlayer4)
            {
                y = placePlayer3;
                placePlayer3 = placePlayer1;
                 cout << "Player_3 is in the lead, Player_" << z << " swaps places" << endl;
            }
            
            else if (placePlayer4 > placePlayer1 && placePlayer4 > placePlayer2 && placePlayer4 > placePlayer3)
            {
             y = placePlayer4;
            placePlayer4 = placePlayer1;
                cout << "Player_4 is in the lead, Player_" << z << " swaps places" << endl;
            }
            else
            {
                cout << "Player_" << z << ", you do not swap places." << endl;
                y += 0;
            }
        }
            
        else if(z == 2)
        {
            if (placePlayer1 > placePlayer2 && placePlayer1 > placePlayer3 && placePlayer1 > placePlayer4)
            {
                y = placePlayer1;
                placePlayer1 = placePlayer2;
                cout << "Player_1 is in the lead, Player_" << z << " swaps places" << endl;
            }
            else if (placePlayer3 > placePlayer1 && placePlayer3 > placePlayer2 && placePlayer3 > placePlayer4)
            {
                y = placePlayer3;
                placePlayer3 = placePlayer2;
                cout << "Player_3 is in the lead, Player_" << z << " swaps places" << endl;
            }
            
            else if (placePlayer4 > placePlayer1 && placePlayer4 > placePlayer2 && placePlayer4 > placePlayer3)
            {
             y = placePlayer4;
            placePlayer4 = placePlayer2;
                cout << "Player_4 is in the lead, Player_" << z << " swaps places" << endl;
            }
            else
                y += 0;
            
        }
        else if (z == 3)
            {
            if (placePlayer2 > placePlayer1 && placePlayer2 > placePlayer3 && placePlayer2 > placePlayer4)
            {
                y = placePlayer2;
                placePlayer2 = placePlayer3;
                cout << "Player_2 is in the lead, Player_" << z << " swaps places" << endl;
            }
            else if (placePlayer3 > placePlayer1 && placePlayer3 > placePlayer2 && placePlayer3 > placePlayer4)
            {
                y = placePlayer3;
                placePlayer3 = placePlayer1;
                cout << "Player_3 is in the lead, Player_" << z << " swaps places" << endl;
            }
            
            else if (placePlayer4 > placePlayer1 && placePlayer4 > placePlayer2 && placePlayer4 > placePlayer3)
            {
             y = placePlayer4;
            placePlayer4 = placePlayer1;
                cout << "Player_4 is in the lead, Player_" << z << " swaps places" << endl;
            }
            else
            {
                cout << "Player_" << z << ", you do not swap places." << endl;
                y += 0;
            }
        }
        else if (z ==4)
            {
                if (placePlayer2 > placePlayer1 && placePlayer2 > placePlayer3 && placePlayer2 > placePlayer4)
                {
                    y = placePlayer2;
                    placePlayer2 = placePlayer4;
                    cout << "Player_2 is in the lead, Player_" << z << " swaps places" << endl;
                }
                else if (placePlayer3 > placePlayer1 && placePlayer3 > placePlayer2 && placePlayer3 > placePlayer4)
                {
                    y = placePlayer3;
                    placePlayer3 = placePlayer4;
                    cout << "Player_4 is in the lead, Player_" << z << " swaps places" << endl;
                }
                
                else if (placePlayer1 > placePlayer2 && placePlayer1 > placePlayer3 && placePlayer1 > placePlayer4)
                {
                 y = placePlayer1;
                placePlayer1 = placePlayer4;
                    cout << "Player_1 is in the lead, Player_" << z << " swaps places" << endl;
                }
                else
                {
                    cout << "Player_" << z << ", you do not swap places." << endl;
                    y += 0;
                }
            }
        break;
            
        case 8:
            cout << "Player_" << z << " moves 8 spaces." << endl;
            y += 8;
        break;
                
        case 9:
            cout << "Player_" << z << " moves 9 spaces." << endl;
            y += 9;
        break;

        case 10:
            cout << "Player_" << z << " moves 10 spaces. " << endl;
            y += 10;
        break;
            
        case 11: // swap with lowest numbered player
            if (z == 1)
            {
                if (placePlayer2 < placePlayer1 && placePlayer2 < placePlayer3 && placePlayer2 < placePlayer4)
                {
                    y = placePlayer2;
                    placePlayer2 = placePlayer1;
                    cout << "Player_2 is in last, Player_" << z << " swaps places" << endl;
                }
                else if (placePlayer3 < placePlayer1 && placePlayer3 < placePlayer2 && placePlayer3 < placePlayer4)
                {
                    y = placePlayer3;
                    placePlayer3 = placePlayer1;
                    cout << "Player_3 is in the last, Player_" << z << " swaps places" << endl;
                }
                           
                else if (placePlayer4 < placePlayer1 && placePlayer4 < placePlayer2 && placePlayer4 < placePlayer3)
                {
                    y = placePlayer4;
                    placePlayer4 = placePlayer1;
                    cout << "Player_4 is in the last, Player_" << z << " swaps places" << endl;
                }
                else
                {
                    cout << "Player_" << z << ", you do not swap places." << endl;
                    y += 0;
                }
            }
            else if (z == 2)
                {
                if (placePlayer1 < placePlayer2 && placePlayer1 < placePlayer3 && placePlayer1 < placePlayer4)
                    {
                        y = placePlayer1;
                        placePlayer1 = placePlayer2;
                        cout << "Player_1 is the last, Player_" << z << " swaps places" << endl;
                    }
                else if (placePlayer3 < placePlayer1 && placePlayer3 < placePlayer2 && placePlayer3 < placePlayer4)
                    {
                        y = placePlayer3;
                        placePlayer3 = placePlayer2;
                        cout << "Player_3 is the last, Player_" << z << " swaps places" << endl;
                    }
                else if (placePlayer4 < placePlayer1 && placePlayer4 < placePlayer2 && placePlayer4 < placePlayer3)
                    {
                        y = placePlayer4;
                        placePlayer4 = placePlayer2;
                        cout << "Player_4 is the last, Player_" << z << " swaps places" << endl;
                    }
                else
                {
                    cout << "Player_" << z << ", you do not swap places." << endl;
                    y += 0;
                }
            }
           else if (z == 3)
                {
                if (placePlayer2 < placePlayer1 && placePlayer2 < placePlayer3 && placePlayer2 < placePlayer4)
                {
                y = placePlayer2;
                placePlayer2 = placePlayer3;
                    cout << "Player_2 is the last, Player_" << z << " swaps places" << endl;
                }
                else if (placePlayer3 < placePlayer1 && placePlayer3 < placePlayer2 && placePlayer3 < placePlayer4)
                {
                y = placePlayer3;
                placePlayer3 = placePlayer1;
                    cout << "Player_3 is in the last, Player_" << z << " swaps places" << endl;
                }
                        
                else if (placePlayer4 < placePlayer1 && placePlayer4 < placePlayer2 && placePlayer4 < placePlayer3)
                {
                y = placePlayer4;
                placePlayer4 = placePlayer1;
                    cout << "Player_4 is in the last, Player_" << z << " swaps places" << endl;
                }
                else
                {
                    cout << "Player_" << z << ", you do not swap places." << endl;
                    y += 0;
                }
                }
                if (z ==4)
                    {
                if (placePlayer2 < placePlayer1 && placePlayer2 < placePlayer3 && placePlayer2 < placePlayer4)
                               {
                                   y = placePlayer2;
                                   placePlayer2 = placePlayer4;
                                   cout << "Player_2 is in the last, Player_" << z << " swaps places" << endl;
                               }
                               else if (placePlayer3 < placePlayer1 && placePlayer3 < placePlayer2 && placePlayer3 < placePlayer4)
                               {
                                   y = placePlayer3;
                                   placePlayer3 = placePlayer4;
                                   cout << "Player_3 is in the last, Player_" << z << " swaps places" << endl;
                               }
                               
                               else if (placePlayer1 < placePlayer2 && placePlayer1 < placePlayer3 && placePlayer1 < placePlayer4)
                               {
                                y = placePlayer1;
                               placePlayer1 = placePlayer4;
                                   cout << "Player_1 is the last, Player_" << z << " swaps places" << endl;
                               }
                               else
                                   {
                                       cout << "Player_" << z << ", you do not swap places." << endl;
                                       y += 0;
                                   }
                           }
            break;
            case 12:
            cout << "Player_" << z << ", you must start from the beginning." << endl;
            y = 0;
            break;
            
            default:
            y += 0;
            break;
    }
            
            return y;
    
}
    
void game (int x, int y) // variable x represent the character position on the board. Variable y represent the prayer
{
        
    board[x - 1] = piece [y - 1]; // This used to position the pieces on the board.
    cout << "Game Board;" << endl;
    
            for (int i = 0; i < 10; i++)
            {
                cout << setw(3) << "|" << board[i] << "|";
            }
                cout << endl;
    
            for (int i = 10;  i < 20; i++)
            {
                cout << setw(3) << "|" << board[i] << "|";
            }
                cout << endl;
    
            for (int i = 20; i < 30; i++ )
            {
                cout << setw (3) << "|" << board[i] <<"|";
            }
                cout << endl;
    
            for (int i = 30; i < 40; i++ )
            {
                cout << setw (3) << "|" << board[i] << "|";
            }
                cout << endl;
    
            for (int i = 40; i < 50; i++)
            {
                cout << setw (3) << "|" << board[i] << "|";
            }
                cout << endl;
        }

int main ()
    {
        bool win1 = false, win2 = false, win3 = false, win4 = false;
        int numberPlayers = 0;
    
        for (int i = 0; i < 50; i++)
        board[i] = ' ';
        
        cout << "Sorry!!" << endl;
        cout << "Press enter to continue" << endl;
        cin.get();
        cout << "How many number of Players" << endl;
        
        cin >> numberPlayers;

        while (numberPlayers < 2 || numberPlayers > 4)
        {
            cout << "Please enter a valid number " << endl;
            cin >> numberPlayers;
        }

        while (!gameOver)
        {
            
            int j = 1;
            
            
            while (j <= numberPlayers)
            {
                    if (j == player1)
                    {
                        if (win1 == 0)
                        {
                        cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                        int randomNum1, randomNum2;
               
                        
                        randomNum1 = diceRoll_1();
                        cout << "Dice 1: " << randomNum1 << endl;
                               
                        randomNum2 = diceRoll_2();
                        cout << "Dice 2: " << randomNum2 << endl;
                        
                        if (randomNum1 == randomNum2)
                        {
                        cout << "Congrats! Player_" << j << " : " << piece[j-1] << ". You rolled a double" << endl;
                        win1 = true;
                        }
                            else
                                cout << "Sorry, you must roll a double to start." << endl;
                            
                    }
                        
                        if (win1 == 1)
                        {
                            
                            int Num1= 0, Num2 = 0;
                            board[placePlayer1 - 1] = ' ';

                            cout << "'\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                            
                            Num1 = diceRoll_1();
                            cout << "Die 1: " << Num1 << endl;
                        
                            Num2 = diceRoll_2();
                            cout << "Die 2: " << Num2 << endl;
                            int move = Num1 + Num2;
                            
                            cout << "Player_" << j << ": " << piece[j-1] << "You rolled: " << move << endl;
                        

                            if (Num1 == Num2)
                            {
                                cout << "You rolled again." << endl;
                                Num1 = diceRoll_1();
                                cout << "Die 1: " << Num1 << endl;
                                Num2 = diceRoll_2();
                                cout << "Die 2: " << Num2 << endl;
                                move = Num1 + Num2;
                                
                            }
                            
                            if (Num1 == Num2)
                                {
                                    
                                    cout << "You rolled a Double. You must start from the beginning" << endl;
                                    placePlayer1 = 0;
                                }
                                                        
                            if (Num1 != Num2)
                                {
                                    placePlayer1 =  diceMove(move, placePlayer1, player1);
                                    cout << placePlayer1 << endl;
                                }
                            
                            game (placePlayer1, j);
                            winner(placePlayer1, j);
                        }
                    }
                
                    else if (j == player2)
                    {
                        if (win2 == 0)
                        {
                            cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                            int Num1, Num2;
                        
                            Num1 = diceRoll_1();
                            cout << "Dice 1: " << Num1 << endl;
                               
                            Num2 = diceRoll_2();
                            cout << "Dice 2: " << Num2 << endl;
                        
        
                            if (Num1 == Num2)
                            {
                                cout << "Congrats! Player " << j << ". You rolled a double" << endl;
                                win2 = true;
                            }
                            else
                                cout << "Sorry, you must roll a double to start." << endl;
                        }
                        
                        if (win2 == 1)
                        {
                            board[placePlayer2 - 1] = ' ';
                            int Num1, Num2;
                    
                            cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                            Num1 = diceRoll_1();
                            cout << "Dice 1: " << Num1 << endl;
                                   
                            Num2 = diceRoll_2();
                            cout << "Dice 2: " << Num2 << endl;
                             int move = Num1 + Num2;
                            cout << "You rolled a " << move << "." << endl;
                            

                            if (Num1 == Num2)
                            {
                                cout << "You rolled again." << endl;
                                Num1 = diceRoll_1();
                                cout << "Die 1: " << Num1 << endl;
                                Num2 = diceRoll_2();
                                cout << "Die 2: " << Num2 << endl;
                                move = Num1 + Num2;
                            }
                            
                            if (Num1 == Num2)
                                {
                                    cout << "You rolled a Double. You must start from the beginning" << endl;
                                    placePlayer2 = 0;
                                }
                                                        
                            if (Num1 != Num2)
                                {
                                    placePlayer2 =  diceMove(move, placePlayer2, player1);
                                    cout << placePlayer2 << endl;
                                }
                            
                            game (placePlayer2, j);
                            winner (placePlayer2, j);
                            
                        }
                    }
                
                    else if (j == player3)
                    {
                         
                        if (win3 == 0)
                        {
                            int Num1 = 0, Num2 = 0;
                            
                            cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                            Num1 = diceRoll_1();
                            cout << "Dice 1: " << Num1 << endl;
                                
                            Num2 = diceRoll_2();
                            cout << "Dice 2: " << Num2 << endl;
                        
                            if (Num1 == Num2)
                            {
                                cout << "Congrats! Player " << j << ". You rolled a double" << endl;}
                                win3 = true;
                            }
                            else
                                cout << "Sorry, you must roll a double to start." << endl;
                        }
                
                        if (win3 == 1)
                         {
                             board[placePlayer3 - 1] = ' ';
                             int Num1, Num2;

                             cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                             Num1 = diceRoll_1();
                             cout << "Dice 1: " << Num1 << endl;
                                    
                             Num2 = diceRoll_2();
                             cout << "Dice 2: " << Num2 << endl;
                             int move = Num1 + Num2;
                             
                             
                             if (Num1 == Num2)
                             {
                                 cout << "You rolled again." << endl;
                                 Num1 = diceRoll_1();
                                 cout << "Die 1: " << Num1 << endl;
                                 Num2 = diceRoll_2();
                                 cout << "Die 2: " << Num2 << endl;
                                 move = Num1 + Num2;
                             }
                             
                             if (Num1 == Num2)
                             {
                                 cout << "Your rolled a Double. Sorry, must start over" << endl;
                                 placePlayer3 = 0;
                             }
                             
                             if (Num1 != Num2)
                             {
                                 placePlayer3 =  diceMove(move, placePlayer3, player3);
                                 cout << placePlayer3 << endl;
                             }
                                 
                             game (placePlayer3, j);
                             winner (placePlayer3, j);
                         }
            

                    else if (j == player4)
                    {
                       
                        if (win4 == 0)
                        {
                            int Num1, Num2;
                         
                            cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                            Num1 = diceRoll_1();
                            cout << "Dice 1: " << Num1 << endl;
                        
                            Num2 = diceRoll_2();
                            cout << "Dice 2: " << Num2 << endl;
                        
                            if (Num1 == Num2)
                            {
                                cout << "Congrats! Player " << j << ". You rolled a double" << endl;
                                win4 = true;
                            }
                            else
                            cout << "Sorry, you must roll a double to start." << endl;
                        }
                        
                         if (win4 == 1)
                         {
                             board[placePlayer4 - 1] = ' ';
                             int Num1, Num2, move;
                             
                             cout << "\n\n\t\tPlayer_" << j << ": " << piece[j-1] << " It's your turn. " << endl;
                             Num1 = diceRoll_1();
                             cout << "Dice 1: " << Num1 << endl;
                                    
                             Num2 = diceRoll_2();
                             cout << "Dice 2: " << Num2 << endl;
                              move = Num1 + Num2;
                             
                             
                             
                             if (Num1 == Num2)
                             {
                                 cout << "You rolled again." << endl;
                                 Num1 = diceRoll_1();
                                 cout << "Die 1: " << Num1 << endl;
                                 Num2 = diceRoll_2();
                                 cout << "Die 2: " << Num2 << endl;
                                 move = Num1 + Num2;
                             }
                             
                             if (Num1 == Num2)
                             {
                                 cout << "You rolled a Double. You must start from the beginning" << endl;
                                 placePlayer4 = 0;
                             }
                             
                             if (Num1 != Num2)
                             {
                                 placePlayer4 =  diceMove(move, placePlayer4, player4);
                                 cout << placePlayer4 << endl;
                             }
                             
                             game (placePlayer4, j);
                             winner (placePlayer4, j);
                        }
                    }
                j++; //counter
                }
            }
        return 0;
    }
    
