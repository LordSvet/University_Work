import java.util.*;
import java.util.Arrays;
import java.util.Collections;


//Algorithm for huffman tree
public class Huffman {
	
	public static String reverseString(String input) {
		String output = "";
		for(int i = input.length() - 1; i >=0; i--)
			output = output + input.charAt(i);
		return output;
	}	
	public static int getIndex(Code g, String symbol) {
		int i = 0;
		while( i < g.size()) {
			if(g.getBySymbol(symbol) == g.getAt(i)) {
				return i;
			}else i++;
		}return -1;
	}
	public static void generateHuffmanCode(Code c) {	
		ArrayList <Code.CodeItem> list = new ArrayList<Code.CodeItem>();
		String[] encodlist = new String[c.size()];
				
		for(int i = 0; i < c.size(); i++) {
			list.add(c.getAt(i));}		
		Comparator<Code.CodeItem> compare = (o1, o2) -> {
			return Double.compare(o1.getProbability() , o2.getProbability());};
		Collections.sort(list, compare);
		for(int i = 0; i < list.size(); i++) {
			encodlist[i] = "";}
		double sum = 0;
		String codeword = "";
		if(list.get(0).getProbability() == 1) {
			encodlist[0] += "1";}
		for(int i = 0; i < c.size() - 1; i++) {		
			sum = list.get(0).getProbability() + list.get(1).getProbability();
			codeword = list.get(0).getSymbol() + "/" + list.get(1).getSymbol();
			Code.CodeItem sum1 = new Code.CodeItem(codeword, sum);
			
			String[] splitold = list.get(0).getSymbol().split("/");			
			String[] splitarr = codeword.split("/");
			
			if(list.size()>2 || list.get(0).getProbability() != list.get(1).getProbability()) {
				for(int j = 0; j < splitold.length; j++) {
					for(int k = 0; k < splitarr.length; k++) {
						if(splitold[j].equals(splitarr[k])) {
							encodlist[getIndex(c, splitold[j])] += "1"; }}}
				for(int j = splitarr.length -1; j > splitold.length -1; j--) {
					encodlist[getIndex(c, splitarr[j])] += "0"; 
				}
			}else if(list.size()==2 && list.get(0).getProbability() == list.get(1).getProbability()) {
				for(int j = 0; j < splitold.length; j++) {
					for(int k = 0; k < splitarr.length; k++) {
						if(splitold[j].equals(splitarr[k])) {
							encodlist[getIndex(c, splitold[j])] += "0"; }}}
				for(int j = splitarr.length -1; j > splitold.length -1; j--) {
					encodlist[getIndex(c, splitarr[j])] += "1"; }}		
			list.set(1, sum1);
			list.remove(0);
			Collections.sort(list, compare);
		}	
		for(int i = 0; i < c.size(); i++) {
			c.getAt(i).setEncoding(reverseString(encodlist[i]));}	
	}
}
