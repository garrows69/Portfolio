public class Salary extends Employee{
	private double salary;
	
	public Salary(String n, String soc, double sal){
		super(n,soc);
		salary = sal;
	}
	
	public double getSalary(){
		return salary / 12;
	}
}