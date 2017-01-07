
import java.util.Scanner;
public class FindingLargerNumberAmongTwoNumbers {
	
	public static void main(String [] args)
	{
		int sonuc ;
		
		Scanner sayiAl = new Scanner (System.in);
		
		System.out.println("Please enter the two numbers to find that which one is bigger =>");
		
		int a = sayiAl.nextInt();
		int b = sayiAl.nextInt();
		
		sonuc = büyüksayi(a,b);
		
		System.out.println("Larger number => " + sonuc);
		
		sayiAl.close();
		
	}

	static int büyüksayi(int a , int b)
	{
		int büyüksayi ;
		
		if (a > b)
			  büyüksayi = a ;
		else if(b > a)
			büyüksayi = b ;
		else
			büyüksayi = a ;
		
		return büyüksayi ;
	}

}
