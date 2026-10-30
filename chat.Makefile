CC ?= gcc
CFLAGS ?= -O2 -std=c11 -Wall -Wextra

chat-index:
	$(CC) $(CFLAGS) -o cax-chat-index src/chat/chat_json.c src/chat/chat_main.c
	@echo " ✅ cax-chat-index built"

chat-index-clean:
	rm -f cax-chat-index