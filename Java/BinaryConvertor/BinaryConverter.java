import java.util.*;

public class BinaryConverter
{
	public static void main(String[] args)
	{
		//vars
		Scanner keyboard = new Scanner(System.in);
		int num = 0;
		int oldNum;
		int counter = 1;
		int [] binary = new int[326487322];
				
		System.out.print("Input number you want changed to binary ==> ");
		num = keyboard.nextInt();
		oldNum = num;
		
		for(int i = 0; i < binary.length; i++){
			binary[i] = num % 2;
			num = num / 2;
			if(num > 1){
				counter++;
			}
		}
		for(int i = counter; i >= 0; i--){
			System.out.print(binary[i] + " ");
		}
		System.out.println();
	}
}