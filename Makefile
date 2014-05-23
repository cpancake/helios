all: build run

build: 
	cd src && make && make iso && cd ..

run: 
	bochs -f .bochsrc