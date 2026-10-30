windows os run
```
mingw32-make clean
```
then run
```
mingw32-make
```

Build and run chat project

Build the project
```
cax build
```

Run the Chat
```
gcc -O2 -std=c11 -o cax-chat-index.exe src\chat\chat_json.c src\chat\chat_main.c
cax-chat-index.exe content/themes site/themes-index.json
```


