package com.example.currencyconverter;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.MenuItemCompat;
import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ShareActionProvider;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Toolbar;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.StandardCharsets;

import de.hsulm.graf.currencyconverter.ExchangeRate;
import de.hsulm.graf.currencyconverter.ExchangeRateDatabase;
import de.hsulm.graf.currencyconverter.ExchangeRateUpdateRunnable;


public class MainActivity extends AppCompatActivity {

    ExchangeRateDatabase erb = new ExchangeRateDatabase();
    ExchangeRateUpdateRunnable runnable;
    Spinner spinnerFrom;
    Spinner spinnerTo;
    String filename = "SavedCurrencies.txt";
    File path;
    File file;



    @Override
    protected void onCreate(Bundle savedInstanceState) {


        TextView tv1 = findViewById(R.id.textView2);
        runnable = new ExchangeRateUpdateRunnable(this);    //Using this activity so I can use the context to make the toast in the other class
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinnerFrom = (Spinner) findViewById(R.id.spinnerFrom);
        spinnerTo = (Spinner) findViewById(R.id.spinnerTo);


        CurrencyItemAdapter flagAdapter = new CurrencyItemAdapter(erb); //Creating and setting the adapters for the spinners

        spinnerFrom.setAdapter(flagAdapter);
        spinnerTo.setAdapter(flagAdapter);

        androidx.appcompat.widget.Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        Thread tr = new Thread(runnable);
        tr.start();


    }

    //onPause saves everything in preferences so that it can be loaded once onResume is called
    @Override
    protected void onPause() {
        super.onPause();
        path = this.getFilesDir();
        file = new File(path, filename);
        SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = preferences.edit();
        int savedSpaceTo = spinnerTo.getSelectedItemPosition();
        int savedSpaceFrom = spinnerFrom.getSelectedItemPosition();
        editor.putInt("Currency1", savedSpaceTo);
        editor.putInt("Currency2", savedSpaceFrom);
        double[] savedCurrency = new double[erb.getCurrencies().length];
        for(int i = 0; i < savedCurrency.length; i++){
            savedCurrency[i] = erb.getExchangeRate(erb.getCurrencies()[i]);
        }

        try{
            FileOutputStream ostream = new FileOutputStream(file);
            for(int i = 0; i < erb.getCurrencies().length; i++){
                if(i == erb.getCurrencies().length-1){
                    ostream.write(String.valueOf(savedCurrency[i]).getBytes());
                }else
                ostream.write(String.valueOf(savedCurrency[i] + "/").getBytes());
            }
            ostream.close();
        }catch (Exception e){
            Log.i("Error is: ", e.getMessage());
      }
        editor.apply();
    }

    //onResume loads all of the rates saved in onPause and sets them in the database
    @Override
    protected void onResume() {
        super.onResume();
        path = this.getFilesDir();
        file = new File(path, filename);
        SharedPreferences preferences = getPreferences(Context.MODE_PRIVATE);
        spinnerTo.setSelection(preferences.getInt("Currency1",0));
        spinnerFrom.setSelection(preferences.getInt("Currency2",0));
        try {
            FileInputStream istream = openFileInput(filename);
            InputStreamReader inputReader = new InputStreamReader(istream, StandardCharsets.UTF_8);
            StringBuilder stringer = new StringBuilder();
            BufferedReader reader = new BufferedReader(inputReader);
            String line = reader.readLine();
            String[] newRates = line.split("/", 32);
            double[] rates = new double[newRates.length];
            for(int i = 0; i < newRates.length; i++){
                rates[i] = Double.parseDouble(newRates[i]);
                ExchangeRate newER = new ExchangeRate(erb.getCurrencies()[i],"",rates[i]);
                erb.setExchangeRate(newER);
            }

        } catch (Exception e) {
            Log.i("Error is: ", e.getMessage());
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_menu, menu);
        return true;
    }

    @SuppressLint("NonConstantResourceId")
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.item: {
                Intent intent = new Intent(MainActivity.this, CurrencyListActivity.class);
                startActivity(intent);  //Starts the CurrencyListActivity
                return true;
            }
            case R.id.share_button: {
                Spinner spinnerFrom = (Spinner) findViewById(R.id.spinnerFrom);
                Spinner spinnerTo = (Spinner) findViewById(R.id.spinnerTo);
                TextView tv1 = (TextView) findViewById(R.id.textView2);
                EditText et1 = (EditText) findViewById(R.id.plain_text_input);
                String sharedString = et1.getText() + " " + spinnerFrom.getSelectedItem().toString() + " equals " + tv1.getText() + " " + spinnerTo.getSelectedItem().toString();
                Intent intent = new Intent(Intent.ACTION_SEND);
                intent.setType("text/plain");
                intent.putExtra(Intent.EXTRA_TEXT, sharedString);
                startActivity(intent);  //Gives the option to share the result of the conversion
                return true;
            }
            case R.id.refresh_item: {
                runnable.beginStop();   //Starts the update of currencies in the background
                return true;
            }
        }
        return super.onOptionsItemSelected(item);
    }




    @SuppressLint("DefaultLocale")
    public void clickConvert(View view){

        TextView tv1 = (TextView) findViewById(R.id.textView2);
        EditText et1 = (EditText) findViewById(R.id.plain_text_input);
        Spinner spinnerFrom2 = (Spinner) findViewById(R.id.spinnerFrom);
        Spinner spinnerTo2 = (Spinner) findViewById(R.id.spinnerTo);

        double initial = Double.parseDouble(et1.getText().toString());
        double value = erb.convert( initial,
                     spinnerFrom2.getSelectedItem().toString(),
                     spinnerTo2.getSelectedItem().toString());
        tv1.setText(String.format("Value is: %.2f", value));
    }


}