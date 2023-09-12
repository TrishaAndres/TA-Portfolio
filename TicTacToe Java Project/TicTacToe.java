/*
Trisha Andres
trishaa
11/12/2022
CPSC 1061 - 003
*/

import java.util.Scanner;

public class TicTacToe { 
    
    public static void main(String[] args) {
        
        Scanner scnr = new Scanner(System.in);

        //boolean for exit, initalize at false
        boolean exit = false;

        //while !exit
        while(!exit) {
            //output intro
            System.out.println("Let's play Tic-Tac-Toe!");
            System.out.println("When prompted, enter desired row and column numbers");
            System.out.println("Example: 1 3");
            System.out.println();

            //3D string index 3 and 3 
            String[][] board = new String[3][3];

            //for loop; set parameters of board
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = " _ |";
                }
            }

            //at board 0,2 print X
            board[0][2] = " X |";
            //print board
            printBoard(board);

            //output intro for player going
            System.out.println("Let's play!");
            System.out.println("Player X starts!");
            System.out.println();
            //reset board and print it
            board[0][2] = " _ |";
            printBoard(board);

            //boolean for player1
            boolean isPlayer1 = true;

            //boolean for game end
            boolean gameEnded = false;

            //while game is not over
            while(gameEnded == false) {
                //string vairable for symbol and intialize as " "
                String symbol = " ";

                //if it is player1
                //player1 is X
                if (isPlayer1) {
                    symbol = " X |";
                } 
                //else player is O
                else {
                    symbol = " O |";
                }

                //if it is player1
                //output for their turn
                if (isPlayer1) {
                    System.out.println("Enter row and column for player X");
                } 
                //else output for playerO turn
                else {
                    System.out.println("Enter row and column for player O");
                }

                //declare and initalize ints for row and column 
                int row = 0;
                int column = 0;

                //while loop (true) parameter
                while(true){
                    //row and column are inputs
                    row = scnr.nextInt();
                    column = scnr.nextInt();

                    //if row/column is 1,2,3 then subtract 1
                    if ((row == 1) || (row == 2) || (row == 3) || (column == 1) || (column == 2) || (column == 3)) {
                        row = row - 1;
                        column = column - 1;
                    }

                    //if row/columg is greater than 2 or less than 0 then output to get input in parameters
                    if ((row > 2) || (row < 0) || (column > 2) || (column < 0)) {
                        System.out.println("Please enter valid row and col numbers from 1 to 3:");
                    } 
                    //else if spot is not empty output spot is full
                    else if (board[row][column] != " _ |") {
                        System.out.println("That spot is full!");
                        //depending on play output for their turn
                        if (isPlayer1) {
                            System.out.println("Enter row and column for player X");
                        } else {
                            System.out.println("Enter row and column for player O");
                        }
                    } 
                    //else break
                    else {
                        break;
                    }
                }


                /*i tried to do the try and catch statements for this and got very confused
                 i never could figure out what i did wrong and gave up to save my sanity :)
                */
                /*boolean inputError = false; 
                try{
                    row = scnr.nextInt();
                    column = scnr.nextInt();
                    /*if ((row == 1) || (row == 2) || (row == 3) || (column == 1) || (column == 2) || (column == 3)) {
                        row = row - 1;
                        column = column - 1;
                    }
                    //int userRow = Integer.parseInt(row);
                    //int userCol = Integer.parseInt(column);
                }
                catch (InputMismatchException e) {
                    inputError = true;
                }
                if ((row > 2) || (row < 0) || (column > 2) || (column < 0)) {
                    inputError = true;
                }

                while(inputError == true) {
                    System.out.println("Please enter row and col numbers from 1 to 3:");
                    break;
                }
                if (board[row][column] != "_ |"){
                    System.out.println("That spot is full!");*/
                //}


                //at inputted row and column the symbol of the player is put there
                board[row][column] = symbol;
                
                //print board
                printBoard(board);

                //if player x wins, output thet they have won
                //game is over
                if (hasWon(board) == " X |") {
                    System.out.println("Player X WINS!");
                    gameEnded = true;
                } 
                //else if player o wins, output thet they have won
                //game is over
                else if(hasWon(board) == " O |") {
                    System.out.println("Player O WINS!");
                    gameEnded = true;
                } 
                //else, if game is a tie, output for a tie
                //else isPlayer1 is not isPlayer1
                else {
                    if (hasTied(board)) {
                        System.out.println("It's a TIE!");
                        gameEnded = true;
                    } else {
                        isPlayer1 = !isPlayer1;
                    }
                }

            
            
                //while game has ended
                while (gameEnded == true) {

                    //output if they want to play again
                    System.out.println("Do you want to play again? Y or N");
                    //answer is the next inputted character
                    char answer = scnr.next().charAt(0);

                    //if answer is Y or y then restart game
                    if ((answer == 'Y') || (answer =='y')) {
                        main(args);
                        
                    } 
                    //else if anser is N or n exit game
                    else if ((answer == 'N') || answer == 'n') {
                        exit = true; 
                        break;
                    } 
                    //else input is wrong and output so they can input right input
                    else {
                        System.out.println("Please enter valid input: Y or N");  
                        
                    }
                    //game has not ended
                    gameEnded = false;
                    //break
                    break; 
                }
            }
        }
    }

    //method for printing board
    public static void printBoard(String[][] board) {
        //parameters for board and what to print out
        for (int i = 0; i < 3; i++) {
            System.out.print("|");
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }

    //method for if someone has won
    public static String hasWon(String[][] board) {

        //row win 
        for(int i = 0; i < 3; i++) {
            if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != "| _ |")) {
                return board[i][0];
            }
        }

        //column win
        for(int j = 0; j < 3; j++) {
            if((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != "| _ |")) {
                return board[0][j];
            }
        }

        //diagonal win
        if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != "| _ |")) {
            return board[0][0];
        }
        if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[2][0] != "| _ |")) {
            return board[2][0];
        }
        return null;
    }

    //method for if there is a tie
    public static boolean hasTied(String[][] board) {
        //when there are no empty spots on the board
        for(int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == " _ |") {
                    return false;
                }
            }
        }
        return true;
    }
}