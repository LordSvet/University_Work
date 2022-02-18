public abstract class InGerman {

  //Takes number(0-999999) in digits and returns it in german
	final static String[] units = {
			"null", "ein", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", "zehn", "elf", "zwölf", "dreizehn", "vierzehn", "fünfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn", "zwanzig"
	};
	final static String[] tens = {
			"", "zehn", "zwanzig", "dreißig", "vierzig", "fünfzig", "sechzig", "siebzig", "achtzig", "neunzig"
	};

	private static String tensInGerman(int numberTens){ //method to return numbers < 100
		if(numberTens == 1)
			return "eins";
		if (numberTens > 20 & numberTens % 10 != 0)
			return units[numberTens % 10] + "und" + tens[numberTens/10];
		else if (numberTens > 20 & numberTens % 10 == 0)
			return tens[numberTens/10];
		return units[numberTens];
	}
	private static String hundredsInGerman(int numberHundreds){ //method to return numbers < 1000	
		if (numberHundreds % 100 == 0)
			return units[numberHundreds/100] + "hundert";
		return units[numberHundreds/100] + "hundert" + tensInGerman(numberHundreds%100);
	}
		
	public static String inGerman(int number) {
		if(number < 0 || number > 999999)
			return "<<<unbekannt>>>";
		if(number < 100)
			return tensInGerman(number);
		if(number < 1000)
			return hundredsInGerman(number);
		if(number < 10000) {
			if (number % 1000 == 0)
				return units[number / 1000] + "tausend";
			if(number % 1000 < 100)
				return units[number / 1000] + "tausend" + tensInGerman(number % 1000);
			return units[number / 1000] + "tausend" + hundredsInGerman(number % 1000);
		}
		if(number < 100000){
			if(number % 1000 == 0)
                return tensInGerman(number / 1000) + "tausend";
			if(number % 1000 <= 20){
			    if(number / 1000 > 20)
                    return tensInGerman(number/1000) + "tausend" + tensInGerman(number % 1000);
                return units[number/1000] + "tausend" + tensInGerman(number % 100);
			}
			if(number / 1000 > 10 & number / 1000 <= 20 & number % 1000 == 0)
				return units[number/1000] + "tausend";
			if(number % 1000 < 100)
				return tensInGerman(number/1000) + "tausend" + tensInGerman(number % 1000);
			return tensInGerman(number/1000) + "tausend" + hundredsInGerman(number % 1000);
		}
		if(number < 1000000){
			if(number % 1000 == 0) {//121042
				if ((number / 1000) % 100 == 1)
					return units[number/100000] + "hunderteintausend";
				return hundredsInGerman(number / 1000) + "tausend";
			}
			if(number % 1000 < 100) {
				if ((number / 1000) % 100 == 1)
					return units[number/100000] + "hunderteintausend" + tensInGerman(number % 100) ;
				return hundredsInGerman(number / 1000) + "tausend" + tensInGerman(number % 1000);
			}
			if(number % 1000 >= 100 & (number / 1000) % 100 == 1)
				return units[number/100000] + "hunderteintausend" + hundredsInGerman(number%1000);
		return hundredsInGerman(number / 1000) + "tausend" + hundredsInGerman(number % 1000);
		}
		return "<<<unbekannt>>>";
		
	}
}
