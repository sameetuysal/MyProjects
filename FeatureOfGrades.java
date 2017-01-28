
import java.util.Scanner;

public class FeatureOfGrades {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        float minGrade = Float.MAX_VALUE;
        float maxGrade = -Float.MAX_VALUE;
        float sum = 0 ;
        float average= 0 ;
        System.out.println("Please enter the grade: ");
        while (scanner.hasNextLine()) {
        	System.out.println("Please enter the grade: ");
            String line = scanner.nextLine();
            if (line.isEmpty())
                break;

            n++;
            float grade = Float.parseFloat(line);

            if(grade < minGrade)
                minGrade = grade;
            else if(grade > maxGrade)
                maxGrade=grade;

            sum += grade;
            
            
        }
        average = sum / n;

        System.out.println("Number of grades : " + n);
        System.out.println("Average grade    : " + average);
        System.out.println("The minimum grade: " + minGrade);
        System.out.println("The maximum grade: " + maxGrade);
		
        scanner.close();
    }

}
