CC=g++

CFLAGS=-c -Wall
CLIENT_NAME=client_pr
SERVER_NAME=server_pr

common_objects = exception.o record.o functions.o protocol.o

all: client_pr server_pr
	client_pr server_pr

client_pr: main.o file_proccesing.o client.o $(common_objects)
	$(CC) main.o file_proccesing.o client.o $(common_objects) -o $(CLIENT_NAME)

server_pr: server_main.o server.o $(common_objects)
	$(CC) server_main.o server.o $(common_objects) -o $(SERVER_NAME)

main.o: client/main.cpp
	$(CC) $(CFLAGS) client/main.cpp

client.o: client/client.cpp
	$(CC) $(CFLAGS) client/client.cpp

exception.o: Exceptions/exception.cpp
	$(CC) $(CFLAGS) Exceptions/exception.cpp

file_proccesing.o: client/file_proccesing.cpp
	$(CC) $(CFLAGS) client/file_proccesing.cpp

record.o: common/record.cpp
	$(CC) $(CFLAGS) common/record.cpp

server_main.o: server/server_main.cpp
	$(CC) $(CFLAGS) server/server_main.cpp

server.o: server/server.cpp
	$(CC) $(CFLAGS) server/server.cpp

functions.o: common/functions.cpp
	$(CC) $(CFLAGS) common/functions.cpp

protocol.o: common/protocol.cpp
	$(CC) $(CFLAGS) common/protocol.cpp

clean:
	rm -rf *.o $(CLIENT_NAME) $(SERVER_NAME)