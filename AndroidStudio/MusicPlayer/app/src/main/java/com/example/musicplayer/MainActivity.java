package com.example.musicplayer;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.annotation.SuppressLint;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Random;

public class MainActivity extends AppCompatActivity implements MediaPlayer.OnPreparedListener{
    ActivityResultLauncher<String> storagePermissionLauncher;
    ArrayList<Song> songList;
    Song song;
    MediaPlayer mediaPlayer;
    Button shuffle;
    Button playPause;
    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        shuffle = findViewById(R.id.shuffle);
        playPause = findViewById(R.id.playPause);
        tv = findViewById(R.id.textView);

        //Asks for permission and if it is denied it stops the program and shows a toast
        storagePermissionLauncher = registerForActivityResult(new ActivityResultContracts.RequestPermission(), result -> {  //Asking for permission
           if(result){  //If permission is not given it stops the program
               Toast.makeText(this," You denied permission", Toast.LENGTH_LONG).show();
               this.finish();
           }
        });
        storagePermissionLauncher.launch(Manifest.permission.WRITE_EXTERNAL_STORAGE);

    }

    //Selects a new random song and plays it
    public void onClickShuffle(View view){
        if(mediaPlayer != null){
            mediaPlayer.reset();
            mediaPlayer.release();
        }
        songList = getSongs();
        song = shuffle(songList);
        String textView = song.getArtistName() + "\n" + song.getSongName() + "\n" + song.getAlbumName();
        tv.setText(textView);

        mediaPlayer = new MediaPlayer();
        mediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);

        try {
            mediaPlayer.setDataSource(this, song.getUri());
        } catch (Exception e) {
            Log.i("Error: ", e.getMessage());
        }


        mediaPlayer.setOnPreparedListener(this);
        mediaPlayer.prepareAsync();
        mediaPlayer.setLooping(true);
    }

    public void onClickPP(View view) {  //Pauses current song if its running or starts it if its paused.
        if(mediaPlayer.isPlaying()){
            mediaPlayer.pause();
        }else
            mediaPlayer.start();
    }

    public Song shuffle(ArrayList<Song> songList){  //Returns a random song from a given array list with songs
        Random r = new Random();
        int n = r.nextInt(songList.size());
        return songList.get(n);
    }

    //Method scans through the phones external memory and returns all songs as an array list of objects Song
    @SuppressLint("Range")
    public ArrayList<Song> getSongs(){
        ArrayList<Song> songList = new ArrayList<>();
        ContentResolver cr = getContentResolver();
        Uri uri = MediaStore.Audio.Media.EXTERNAL_CONTENT_URI;

        String[] projection = new String[]{
                MediaStore.Audio.Media._ID,
                MediaStore.Audio.Media.ARTIST,
                MediaStore.Audio.Media.DISPLAY_NAME,
                MediaStore.Audio.Media.DURATION,
                MediaStore.Audio.Media.ALBUM,
        };
        Cursor cursor = cr.query(uri, projection, null, null, null);
        if(cursor.getCount()>0){
            int idColumn  = cursor.getColumnIndexOrThrow(MediaStore.Audio.Media._ID);
            int artistColumn = cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ARTIST);
            int titleColumn  = cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DISPLAY_NAME);
            int durationColumn  = cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DURATION);
            int albumIdColumn  = cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ALBUM);
            while(cursor.moveToNext()){
                String artist = cursor.getString(artistColumn);
                String album = cursor.getString(albumIdColumn);
                String title = cursor.getString(titleColumn);
                int duration = cursor.getInt(durationColumn);
                long id = cursor.getLong(idColumn);
                Uri songUri = ContentUris.withAppendedId(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI,id);
                Song song = new Song(id,songUri,title,artist,album,duration);
                songList.add(song);
            }
        }
        return songList;
    }

    //Starts the player as soon as the random song is selected
    @Override
    public void onPrepared(MediaPlayer mediaPlayer) {
        mediaPlayer.start();
    }
}