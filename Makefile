CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O3 -Iinclude -D_POSIX_C_SOURCE=200809L -D_DEFAULT_SOURCE -D_GNU_SOURCE

SRC = src/main.c \
      src/utils/file_utils.c \
      src/utils/string_utils.c \
      src/data/data_manager.c \
      src/data/yaml_parser.c \
      src/data/json_parser.c \
      src/frontmatter/frontmatter.c \
      src/markdown/markdown.c \
      src/template/template_engine.c \
      src/template/filter.c \
      src/sitemap/sitemap.c \
      src/collection/collection.c \
      src/pagination/pagination.c \
      src/tags/tags.c \
      src/build/builder.c \
      src/server/server.c

OBJ = src/main.o \
      src/utils/file_utils.o \
      src/utils/string_utils.o \
      src/data/data_manager.o \
      src/data/yaml_parser.o \
      src/data/json_parser.o \
      src/frontmatter/frontmatter.o \
      src/markdown/markdown.o \
      src/template/template_engine.o \
      src/template/filter.o \
      src/sitemap/sitemap.o \
      src/collection/collection.o \
      src/pagination/pagination.o \
      src/tags/tags.o \
      src/build/builder.o \
      src/server/server.o

TARGET = cax.exe

all: banner $(TARGET)

ifeq ($(OS),Windows_NT)
banner:
	@echo.
	@echo  CAX SSG - C STATIC SITE GENERATOR
	@echo  BY AXCORA TECHNOLOGY
	@echo  ------------------------------------------
else
banner:
	@echo ""
	@echo " CAX SSG - C STATIC SITE GENERATOR"
	@echo " BY AXCORA TECHNOLOGY"
	@echo " ------------------------------------------"
endif

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lws2_32
	@echo [OK] Built $(TARGET) - Native C Server Ready!

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	@echo.
	@echo  CAX SSG - C STATIC SITE GENERATOR
	@echo  BY AXCORA TECHNOLOGY
	@echo  ------------------------------------------
	@-del /F /Q src\main.o src\utils\file_utils.o src\utils\string_utils.o src\data\data_manager.o src\data\yaml_parser.o src\data\json_parser.o src\frontmatter\frontmatter.o src\markdown\markdown.o src\template\template_engine.o src\template\filter.o src\sitemap\sitemap.o src\collection\collection.o src\pagination\pagination.o src\tags\tags.o src\build\builder.o src\server\server.o 2>nul
	@-del /F /Q cax.exe cax 2>nul
	@echo [CLEAN] Done
else
	@echo ""
	@echo " CAX SSG - C STATIC SITE GENERATOR"
	@echo " BY AXCORA TECHNOLOGY"
	@echo " ------------------------------------------"
	rm -f $(OBJ) $(TARGET) cax
	@echo "[CLEAN] Done"
endif

linux: banner
	$(CC) $(CFLAGS) -o cax $(SRC)
	@echo "[OK] Built cax for Linux"

windows: banner
	$(CC) $(CFLAGS) -o cax.exe $(SRC) -lws2_32
	@echo "[OK] Built cax.exe for Windows"

.PHONY: all banner clean linux windows