# Mac OS X on Apple Silicon (M1) - ARM64

run:
	gcc jen.c -o jen && ./jen

compile:
	gcc jen.c -c -o jen.o

link:
	ld jen.o -o jen -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch arm64
