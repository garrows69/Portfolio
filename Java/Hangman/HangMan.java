
import java.util.*;

public class HangMan{

	private static char leftLeg = 92;

	public static void drawHang() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|");
		System.out.format("\n|");
		System.out.format("\n|");
		System.out.format("\n=====");
	}

	public static void missOne() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|  O");
		System.out.format("\n|");
		System.out.format("\n|");
		System.out.format("\n=====");
	}

	public static void missTwo() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|  O");
		System.out.format("\n| /|");
		System.out.format("\n|");
		System.out.format("\n=====");
	}

	public static void missThree() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|  O");
		System.out.format("\n| /|" + leftLeg);
		System.out.format("\n=====");
	}

	public static void missFour() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|  O");
		System.out.format("\n| /|" + leftLeg);
		System.out.format("\n| / ");
		System.out.format("\n=====");
	}

	public static void missFive() {
		System.out.format(".___");
		System.out.format("\n|  |");
		System.out.format("\n|  O");
		System.out.format("\n| /|" + leftLeg);
		System.out.format("\n| / " + leftLeg);
		System.out.format("\n=====");
	}

	public static void missSix() {
		System.out.format(".___      .------..------..------..------.");
		System.out.format("\n|  |      |D.--. ||E.--. ||A.--. ||D.--. |");
		System.out.format("\n|  0      | :/\\: || (\\/) || (\\/) || :/\\: |");
		System.out.format("\n| /|" + leftLeg + "     | (__) || :\\/: || :\\/: || (__) |");
		System.out.format("\n| / " + leftLeg + "     | '--'D|| '--'E|| '--'A|| '--'D|");
		System.out.format("\n=====     `------'`------'`------'`------'");
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		String word = "";
		String guess = "";
		boolean gameover = false;
		boolean match = false;
		boolean won = false;
		final int allowedMiss = 6;
		int misses = 0;

		System.out.print("Input a word ==> ");
		word = keyboard.nextLine();
		boolean [] words = new boolean[word.length()];
		boolean [] correctWords = new boolean[word.length()];
		for(int i = 0; i < correctWords.length; i++) {
			correctWords[i] = true;
		}

		for(int i = 0; i <= 100; i++) {
			System.out.println();
		}

		while(gameover != true) {
			match = false;
			//draws art
			if(misses == 0) {
				drawHang();
			}
			else if(misses == 1) {
				missOne();
			}
			else if(misses == 2) {
				missTwo();
			}
			else if(misses == 3) {
				missThree();
			}
			else if(misses == 4) {
				missFour();
			}
			else if(misses == 5) {
				missFive();
			}
			System.out.println();
			//sets it to _ or letter
			for(int i = 0; i < words.length; i++) {
				if(words[i] == false) {
					System.out.print("_ ");
				}
				else if(words[i] == true) {
					System.out.print(word.substring(i, i + 1));
				}
			}
			System.out.println();
			//reads input from user
			System.out.print("Take a guess ==> ");
			guess = keyboard.nextLine();

			//checks letter
			for(int i = 0; i < word.length(); i++) {
				if(guess.equalsIgnoreCase(word.substring(i, i + 1))) {
					words[i] = true;
					match = true;
				}
			}


			//checks to see if  the player lost
			if(match ==  false) {
				misses++;
			}
			if(misses == allowedMiss) {
				gameover =  true;
				missSix();
				System.out.println("The word was " + word +". Better luck next time!");
			}
			//win game feature
			won = true;
				for(int i = 0; i < words.length; i++) {
					if(words[i] != correctWords[i]) {
						won = false;
					}
				}
				if(won == true) {
					gameover = true;
				}
	}
		if(won == true) {
			if(misses == 0){
				drawHang();
			}
			else if(misses == 1){
				missOne();
			}
			else if(misses == 2){
				missTwo();
			}
			else if(misses == 3){
				missThree();
			}
			else if(misses == 4){
				missFour();
			}
			else if(misses == 5){
				missFive();
			}
			else if(misses == 6){
				missSix();
			}
			System.out.println("\n" + word);
			System.out.println("Good job. You Won!");
		}
  }
}
