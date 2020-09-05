public class Hourly extends Employee{
	private double hWage;
	private int hoursWrked;
	
	public Hourly(String n, String soc, double wage, int hours){
		super(n,soc);
		hWage = wage;
		hoursWrked = hours;
	}
	
	public double getSalary(){
		if(hoursWrked > 160){
			return ((hoursWrked - 160) * hWage * 1.5) + 160 * hWage;
		}	
		return hoursWrked * hWage;
	}
}