package com.example.currencyconverter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import de.hsulm.graf.currencyconverter.ExchangeRate;
import de.hsulm.graf.currencyconverter.ExchangeRateDatabase;

public class CurrencyListActivity extends AppCompatActivity {

    ExchangeRateDatabase erb = new ExchangeRateDatabase();

    //A simple activity for the list that sends you to google maps on the current Exchange Rate's country's capital when you click on it
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_currency_list);

        CurrencyItemAdapter flagAdapter = new CurrencyItemAdapter(erb);
        ListView lv1 = findViewById(R.id.ListView);
        lv1.setAdapter(flagAdapter);

        lv1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String url = "geo://maps.google.co.in/maps?q=" + erb.getCapital(erb.getCurrencies()[i]);
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
                startActivity(intent);
            }
        });

    }



}
