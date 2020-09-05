public class TestLine{
	public static void main(String[] args){
		Point point1 = new Point(2.0,3.0);
		Point point2 = new Point(6.0,12.0);
		Line line1 = new Line(point1,point2);
		System.out.println("The first point is " + point1);
		System.out.println("The second point is " + point2);
		System.out.println("The mid point is " + line1.midPoint());
		System.out.println("The length of the line is " + line1.findLength());
	}
	
}