CC=g++
LIBRARIES=lib/md5.cpp lib/sha1.cpp lib/sha256.cpp lib/sha512.cpp lib/libhashblade.cpp

all:
	$(CC) hashblade.cpp $(LIBRARIES) -o hashblade
clean:
	rm -f hashblade
