# Compiler le fichier main.c
`gcc src/main.c $(sdl2-config --cflags --libs) -o bin/main -LSDL2 -lSDL2_image`
