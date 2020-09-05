import java.util.*;

public class PlaySlots{
	public static void main(String [] args){
		int option;
		boolean isRunning = true;
		SlotMachine slots = new SlotMachine();
		Scanner keyboard = new Scanner(System.in);
		
		while(isRunning == true){
		
		System.out.print("1. Pull Lever 2. Quit --> ");
		option = keyboard.nextInt();
		
		if(option == 1){
			slots.pullLever();
			slots.displayRollers();
			slots.displayResults();
		}
		if(option == 2){
			isRunning = false;
		}	
		}
	}
}