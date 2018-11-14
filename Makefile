test:test.cpp
	g++ -o $@ $^ -lpthread  -fpermissive
.PHONY:clean
clean:
	rm -f test
