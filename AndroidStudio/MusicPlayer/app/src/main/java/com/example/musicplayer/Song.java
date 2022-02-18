package com.example.musicplayer;

import android.net.Uri;

import java.util.ArrayList;
import java.util.Random;

//I made class Song to make objects containing all the info I will need for the player and made getters and setters
public class Song {
    private long id;
    private String songName;
    private String artistName;
    private String albumName;
    private int duration;
    private Uri uri;

    public Song(long id, Uri uri, String songName, String artistName, String albumName, int duration){
        this.songName = songName;
        this.artistName = artistName;
        this.albumName = albumName;
        this.duration = duration;
        this.id = id;
        this.uri = uri;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public Uri getUri(){
        return uri;
    }

    public void setUri(Uri uri){
        this.uri = uri;
    }

    public String getSongName() {
        return songName;
    }

    public void setSongName(String songName) {
        this.songName = songName;
    }

    public String getArtistName() {
        return artistName;
    }

    public void setArtistName(String artistName) {
        this.artistName = artistName;
    }

    public String getAlbumName() {
        return albumName;
    }

    public void setAlbumName(String albumName) {
        this.albumName = albumName;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

}
