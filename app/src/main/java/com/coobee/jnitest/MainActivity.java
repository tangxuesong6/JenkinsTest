package com.coobee.jnitest;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("jni-test");
    }

    private TextView mJni1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mJni1 = findViewById(R.id.jni_1);
        mJni1.setText(get());
        set("hello world from JniTestApp");
    }

    public native String get();

    public native void set(String str);

    public static void methodCalledByJni(String msg) {
        Log.d("JNITEST", "methodCalledByJni,msg:" + msg);
    }

}
