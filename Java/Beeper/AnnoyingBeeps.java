import java.util.Scanner;

public class AnnoyingBeeps{
    private Scanner keyboard = new Scanner(System.in);
    
    public static void main (String [] args){
        AnnoyingBeeps audio = new AnnoyingBeeps();
        //audio.example();
        audio.beep10();
        audio.beep(5);
        audio.risingPitch();
        audio.risingPitch(500, 150, 600, 5);
        audio.buildup();
        audio.song();
        
    }
    
        /*This code creates a beep, followed by a pause, followed by another beep.*/
        public void example(){
            Beeper.beep(800,400);
            Beeper.sleep(300);
            Beeper.beep(440,800);
        }
        
        
        /*This method will beep 10 times. You can choose the frequency and the duration, 
         *but the ten beeps should be clearly separate beeps.*/
        public void beep10(){

             System.out.println("Testing beep10()"); //used for grading
             for(int i = 1; i <= 10; i++){
             	Beeper.beep(500,500);
             	Beeper.sleep(400);
             }

        }
        
        /*This method will beep n times. You can choose the frequency and the duration, 
         *but the n beeps should be clearly separate beeps. Hint: This will be very similar
         *to the previous method, except that instead of always beeping 10 times you will 
         *need to beep the number of times passed as a parameter (n). */
        public void beep(int n){
             System.out.println("Testing beep(int n)"); //used for grading
             for(int i = 1; i <= n; i++){
             	Beeper.beep(500,500);
             	Beeper.sleep(400);
             }
        }
        
        /*This method will beep will beep 12 times at different frequencies. The first beep 
         *should be beep once at 500 Hz . Each subsequent beep should be 20 Hz higher.*/
        public void risingPitch(){
             System.out.println("Testing risingPitch()"); //used for grading
             int frequency = 500;
             for(int i = 1; i <= 12; i++){
             	Beeper.beep(frequency, 500);
             	Beeper.sleep(400);
             	frequency += 20;
             } 
        }
        
        
        /* This method will have times beeps, starting at startHz, incrementing by incrementHz, 
         *and delaying delay between each beep. Hint: This will be very similar to the last method, 
         *except that you are now getting information from your parameters.*/
        public void risingPitch(int startHz, int incrementHz, int delay, int times){
             System.out.println("Testing risingPitch(int startHz, int incrementHz, int delay, int times)"); //used for grading
             for(int i = 1; i <= times; i++){
             	Beeper.beep(startHz, 500);
             	Beeper.sleep(delay);
             	startHz += incrementHz;
             }
        }
        
        /*This method will consecutively beep more times in a row, until seven beeps in a row 
         *are reached. It should first beep once and sleep for one second, then beep twice and sleep for 
         *one second, then three times and sleep for one second, and so on. Hint: This will require a 
         *nested loop. For the outer loop, think about how many sets you need to beep. For the inner loop, 
         *think about how many beeps for that set need to be made.*/
        public void buildup(){
             System.out.println("Testing buildup()"); //used for grading
             for(int t = 1; t <= 7; t++){
             	for(int b = 1; b <= t; b++){
             		Beeper.beep(500 , 500);
             		Beeper.sleep(300);
             	}
             	   Beeper.sleep(1000);
             }
        }

        
        /*This method will will play a short song created by you. When the song ends, the user should be 
         *prompted to hear it again. The song should repeat as long as they wish to continue hearing it. */
        public void song(){
            System.out.println("Testing song()"); //used for grading
            boolean play = true;
            String answer = "";
            while(play == true){
            //first lick
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 400);
            //second lick
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 400);
            //second measure
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 200);
            Beeper.beep(659, 200);
            Beeper.beep(587, 400);
            Beeper.beep(491, 200);
            Beeper.beep(523, 200); //8th note B
            //third measure
            Beeper.beep(491, 200);
            Beeper.beep(392, 200);
            Beeper.beep(329, 1000);
            Beeper.beep(293, 200);
            //fourth measure
            Beeper.beep(329, 200);
            Beeper.beep(392, 200);
            Beeper.beep(329, 900);
            //fifth measure
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 400);
            //second lick
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 400);
            //sixth measure
            Beeper.beep(349, 200);
            Beeper.beep(436, 200);
            Beeper.beep(491, 200);
            Beeper.beep(659, 200);
            Beeper.beep(587, 400);
            Beeper.beep(491, 200);
            Beeper.beep(523, 200); //8th note B
            //seventh measure
            Beeper.beep(659, 200);
            Beeper.beep(491, 200);
            Beeper.beep(392, 800);
            Beeper.beep(491, 200);
            //eigth measure
            Beeper.beep(392, 200);
            Beeper.beep(293, 200);
            Beeper.beep(329, 800);
            //9th measure
            Beeper.beep(293, 200);
            Beeper.beep(329, 200);
            Beeper.beep(349, 400);
            Beeper.beep(392, 200);
            Beeper.beep(440, 200);
            Beeper.beep(492, 400);
            //10th measure
            Beeper.beep(523, 200);
            Beeper.beep(493, 200);
            Beeper.beep(329, 800);
            //11th measure
            Beeper.beep(293, 200);
            Beeper.beep(329, 200);
            Beeper.beep(349, 400);
            Beeper.beep(392, 200);
            Beeper.beep(440, 200);
            Beeper.beep(493, 400);
            //12th measure
            Beeper.beep(523, 200);
            Beeper.beep(587, 200);
            Beeper.beep(659, 800);
            //13th measure
            Beeper.beep(293, 200);
            Beeper.beep(329, 200);
            Beeper.beep(349, 400);
            Beeper.beep(392, 200);
            Beeper.beep(440, 200);
            Beeper.beep(493, 400);
            //14th measure
            Beeper.beep(523, 200);
            Beeper.beep(493, 200);
            Beeper.beep(329, 800);
            //15th measure
            Beeper.beep(329, 200);
            Beeper.beep(293, 200);
            Beeper.beep(349, 200);
            Beeper.beep(329, 200);
            Beeper.beep(392, 200);
            Beeper.beep(349, 200);
            Beeper.beep(440, 200);
            Beeper.beep(392, 200);
            //16th measure
            Beeper.beep(493, 200);
            Beeper.beep(440, 200);
            Beeper.beep(523, 200);
            Beeper.beep(493, 200);
            Beeper.beep(587, 200);
            Beeper.beep(523, 200);
            Beeper.beep(659, 100);
            Beeper.beep(698, 100);
            Beeper.beep(587, 100);
            Beeper.beep(659, 1000);
            System.out.print("Do you want to hear the song again?  ");
            answer = keyboard.nextLine();
            if(answer.equalsIgnoreCase("yes")){
            	play = true;
            }
            else if(answer.equalsIgnoreCase("no")){
            	play = false;
            }
            }
        }
        
    }