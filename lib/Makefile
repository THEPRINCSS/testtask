lib_compile:
	gcc -fPIC -c -Wimplicit-function-declaration -I ../include get_branch.c high_verion_release.c only_first.c read_json.c write_json.c
	gcc -shared  -o libtesttasklib.so get_branch.o high_verion_release.o only_first.o read_json.o write_json.o

clear: get_branch.o high_verion_release.o only_first.o read_json.o write_json.o
	rm *.o
