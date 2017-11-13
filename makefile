all:
	g++ hashblade.cpp lib/md5.cpp lib/sha1.cpp lib/sha256.cpp lib/sha512.cpp lib/libhashblade.cpp -o hashblade -w
clean:
	rm -f hashblade
