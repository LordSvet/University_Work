import java.io.*;

public abstract class Terminal {
	
	public static String getString(String prompt) {
		
		if (!prompt.equals("")) System.out.print(prompt + " ");
		
		InputStreamReader reader = new InputStreamReader(System.in);
		BufferedReader    input  = new BufferedReader(reader);
		
		try {
			return input.readLine();
		} catch (Exception e) {
			return "";
		} 
	}
	
	public static int getInt(String prompt) {
		
		int resultat = 0;
		
		try {
			resultat = Integer.parseInt(getString(prompt));
		} catch (Exception e) {
			put("Please enter an integer number between -2147483647 and +2147483647!");
			resultat = getInt(prompt);
		}
		
		return resultat;
	}
	
	public static double getDouble(String prompt) {
		
		double resultat = 0.0;
		
		try {
			resultat = Double.parseDouble(getString(prompt));
		} catch (Exception e) {
			put("Please enter a decimal number!");
			resultat = getDouble(prompt);
		}
		
		return resultat;
	}
	
	public static void put(String s) {
		
		System.out.println(s);
	}
	
	public static void put(int s) {
		
		System.out.println(s);
	}
	
	public static void put(double s) {
		
		System.out.println(s);
		
	}
	
	
}
