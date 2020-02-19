compila:
	gcc hello.c -o hello
	./hello

clean:
	rm hello

push: 
	git add .
	git commit 
	git push origin master