package com.example.currencyconverter;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import de.hsulm.graf.currencyconverter.ExchangeRateDatabase;

//The adapter that are used for the spinners with all the rates
public class CurrencyItemAdapter extends BaseAdapter {
    ExchangeRateDatabase rateDb;
    public CurrencyItemAdapter(ExchangeRateDatabase db) {
        rateDb = db;
    }
    @Override
    public int getCount() {
        return rateDb.getCurrencies().length;
    }
    @Override
    public Object getItem(int position) {
        return rateDb.getCurrencies()[position];
    }
    @Override
    public long getItemId(int position) {
        return position;
    }
    @SuppressLint("InflateParams")
    @Override
    public View getView(int position, View view, ViewGroup parent) {    //Puts the flag next to the currency
        Context context = parent.getContext();
        String currencyName = rateDb.getCurrencies()[position];
        String resourceName = "flag_" + currencyName.toLowerCase();
        int imageId = context.getResources().getIdentifier(resourceName, "drawable", context.getPackageName());

        if(view == null) {
            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            view = inflater.inflate(R.layout.spinner_flags, null, false);
        }

        @SuppressLint("UseCompatLoadingForDrawables") Drawable drawable = context.getDrawable(imageId);
        ImageView image = view.findViewById(R.id.image);
        image.setImageDrawable(drawable);

        TextView text = view.findViewById(R.id.flag_names);
        text.setText(currencyName);


        return view;
    }
}