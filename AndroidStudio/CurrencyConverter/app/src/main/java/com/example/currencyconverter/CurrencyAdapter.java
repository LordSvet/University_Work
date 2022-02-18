package com.example.currencyconverter;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import de.hsulm.graf.currencyconverter.ExchangeRate;
import de.hsulm.graf.currencyconverter.ExchangeRateDatabase;

public class CurrencyAdapter extends BaseAdapter {

    private ExchangeRateDatabase erb = new ExchangeRateDatabase();
    private ExchangeRate[] er;

    public CurrencyAdapter(ExchangeRate[] er){
        this.er = er;
    }


    @Override
    public int getCount() {
        return er.length;
    }

    @Override
    public Object getItem(int i) {
        return er[i];
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @SuppressLint({"ViewHolder", "SetTextI18n", "InflateParams"})
    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        Context context = viewGroup.getContext();
        ExchangeRate entry = (ExchangeRate)getItem(i);

        if(view == null) {
            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            view = inflater.inflate(R.layout.list_view_item, null, false);
        }

        TextView names = (TextView) view.findViewById(R.id.list_names);
        names.setText(entry.getCurrencyName());

        TextView rates = (TextView) view.findViewById(R.id.list_rate);
        rates.setText(Double.toString(entry.getRateForOneEuro()));

        return view;
    }
}
