---
layout: themes-detil.cax
title: Register Form Android UI Mobile Project
description: Free download themes template android java register form ui design for learn source code gratis.
image: mobile/membuat_aplikasi_android_regritasi_form_ejtrt4.png
features:
 - Android Java
 - Android Studio
 - Android App
 - Mobile App
 - Documentation Ready
 - Full Source Code Themes Template Project
download: https://creativitaz.gumroad.com/l/adbux
demo: 
tags:
  - themestemplate
  - mobile themes
  - mobile template
  - website themes
  - website template
  - themes
  - template
  - android
  - java
  - mobile
  - androidthemes
  - freethemes
---
### How To

+ Download Source Code
+ Open with android studio
+ Run emulator
+ Build for App bundle or APK

Import
- import android.widget.TextView;
- import android.view.View;
- import android.widget.EditText;

For display
``
package com.example.register;

import androidx.appcompat.app.AppCompatActivity;
import android.widget.TextView;
import android.view.View;
import android.widget.EditText;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
}
public void onBtnClick (View view) {
TextView textViewFirst = findViewById

(R.id.textViewFirst);
EditText editTxtFirst = findViewById

(R.id.editTxtFirst);
editTxtFirst.getText().toString();

textViewFirst.setText(editTxtFirst.getText().toString());

// Lastname fungsi
TextView textViewLast = findViewById

(R.id.textViewLast);
EditText editTxtLast = findViewById

(R.id.editTxtLast);
editTxtLast.getText().toString();

textViewLast.setText(editTxtLast.getText().toString());

// email fungsi

TextView textViewEmail = findViewById

(R.id.textViewEmail);
EditText editTxtEmail = findViewById

(R.id.editTxtEmail);
editTxtEmail.getText().toString();

textViewEmail.setText(editTxtEmail.getText().toString());

}
}
```
