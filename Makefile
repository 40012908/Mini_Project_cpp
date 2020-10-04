all.out:main.cpp 
	g++ main.cpp -lgtest -lgtest_main -lpthread -o all.out
run:all.out
	./all.out

