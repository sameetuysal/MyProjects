
import java.util.Scanner;
public class FindingLargerNumberAmongTwoNumbers {
	
	public static void main(String [] args)
	{
		int sonuc ;
		
		Scanner sayiAl = new Scanner (System.in);
		
		System.out.println("Please enter the two numbers to find that which one is bigger =>");
		
		int a = sayiAl.nextInt();
		int b = sayiAl.nextInt();
		
		sonuc = b�y�ksayi(a,b);
		
		System.out.println("Larger number => " + sonuc);
		
		sayiAl.close();
		
	}

	static int b�y�ksayi(int a , int b)
	{
		int b�y�ksayi ;
		
		if (a > b)
			  b�y�ksayi = a ;
		else if(b > a)
			b�y�ksayi = b ;
		else
			b�y�ksayi = a ;
		
		return b�y�ksayi ;
	}

}
