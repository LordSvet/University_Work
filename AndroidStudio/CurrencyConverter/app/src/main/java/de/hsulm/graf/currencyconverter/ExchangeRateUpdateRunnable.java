package de.hsulm.graf.currencyconverter;


import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.example.currencyconverter.MainActivity;
import com.example.currencyconverter.R;

import org.w3c.dom.Text;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;

// Class for the runnable so that it can update the exchange rates in the background
public class ExchangeRateUpdateRunnable implements Runnable {
    private boolean running = false;
    private Activity activity;
    //I made the ERURunnable object have a parameter activity which I use to create the Toast
    public ExchangeRateUpdateRunnable(Activity activity){
        this.activity = activity;
    }
    @Override
    public void run() {


        while(true){
            if(running){
                updateCurrencies(); //Calling update currencies
                activity.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if(running){
                            Toast refresh = Toast.makeText(activity.getBaseContext(), "Exchange Rates Updated!", Toast.LENGTH_SHORT);
                            refresh.show();
                        }
                    }
                });
                try {
                    Thread.sleep(7000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void beginStop(){
        running = !running;
    }

    public static void updateCurrencies(){  //Method updates the currencies from ecb.europa.eu with xml parsing

        ExchangeRateDatabase erbRefresh = new ExchangeRateDatabase();
        ExchangeRateDatabase erb = new ExchangeRateDatabase();
        String url = "https://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml";

        try {
            URL link = new URL(url);
            URLConnection connection = link.openConnection();
            InputStream stream = connection.getInputStream();
            String encoding = connection.getContentEncoding();
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            factory.setNamespaceAware(true);
            XmlPullParser parser = factory.newPullParser();
            parser.setInput(stream, encoding);

            int eventType = parser.getEventType();

            while(eventType != XmlPullParser.END_DOCUMENT){
                if(eventType == XmlPullParser.START_TAG){
                    if("Cube".equals(parser.getName()) && parser.getAttributeValue(null, "currency") != null && parser.getAttributeValue(null, "rate") != null){

                        ExchangeRate erNew = new ExchangeRate(parser.getAttributeValue(null, "currency"), "", Double.parseDouble(parser.getAttributeValue(null, "rate")));
                        erb.setExchangeRate(erNew);
                    }
                }
                eventType = parser.next();
            }


        } catch (Exception e) {
            Log.i("Exception is:  ", e.toString());
            e.printStackTrace();
        }
    }

}
