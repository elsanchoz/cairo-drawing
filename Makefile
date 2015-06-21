CC = gcc 

CFLAGS = -Wall 
CFLAGS += -Wextra

LIBS = `pkg-config --cflags --libs gtk+-3.0` 
LIBS += `pkg-config --cflags --libs cairo`

all: window

window: window.o 
		$(CC) $(CFLAGS) window.o -o window $(LIBS)

window.o: window.c
		$(CC) $(CFLAGS) -c -o window.o window.c $(LIBS)			
	

#draw.o: draw.c
#		$(CC) $(CFLAGS) -c -o draw.o draw.c $(LIBS)
