import java.util.Scanner;

public class TicTacToe
{
    private static Scanner in = new Scanner(System.in);
	private static boolean isX = false;

	public static void main(String[] args)
	{
		char[][] board = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

		do
		{
			//TODO: switch the player's turn
			//      (if isX is true, make it false, and vice versa)
			isX = !isX;

			print(board);
			board = playerTurn(board);

		} while( !checkWin(board) );
		print(board);
	}

	public static void print(char[][] board)
	{

		for(int r = 0; r < board.length; r++){
			for(int c = 0; c < board[0].length; c++){
				System.out.print("" + board[r][c] + "\t");
			}
			System.out.println("");
		}
	}

	public static char[][] playerTurn(char[][] board)
	{
		//set player to the person's turn
		char player = isX ? 'X' : 'O';   //Ternary operator.  If isX is true then player = 'X' otherwise player = 'O'

		//ask the user for the spot they want
		System.out.print("Player " + player + ", where would you like to go? > ");
		int spot = in.nextInt();

		//Done: set that spot to the player's letter (char player)
		if(spot > 9 || spot < 0){
			System.out.println("Not a spot on board");
		}
		int x = (spot > 6 ? 2 : (spot > 3 ? 1 : 0));
		int y = spot - 3 * x - 1;
		if(board[x][y] == ((char)(spot + '0')))
		board[x][y] = player;
		return board;
	}

	public static boolean checkWin(char[][] board)
	{
		//TODO: check for win and print which player won. (Ex. "Player X won the game!")
		boolean isSame = false;
		int col = 0;
		char winner = ' ';
		for(int r = 0; r < board.length; r++){
			if(board[r][col] == board[r][col + 1] && board[r][col + 1] == board[r][col + 2]){
				isSame = true;
				winner = board[r][col];
			}
		  }
		 int row = 0;
		 for(int c = 0; c < board.length; c++){
		 	if(board[row][c] == board[row + 1][c] && board[row][c] == board[row + 2][c]){
		 		isSame = true;
		 		winner = board[row][c];
		 	}
		 }
		 if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		 	isSame = true;
		 	winner = board[0][0];
		 }
		 if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
		 	isSame = true;
		 	winner = board[2][0];
		 }
		 
		if(isSame == true){
			System.out.println("Player " + winner + " has won!!!");
			return true;
		}
		return isSame;
	}
}