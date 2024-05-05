
names = main plane collecting splitting distributing

files:
	gcc main.c -o main 
	gcc plane.c -o plane
	gcc collecting.c -o collecting 
	gcc splitting.c -o splitting
	gcc distributing.c -o distributing


run:
	./main 

clean:
	rm -f $(names)


