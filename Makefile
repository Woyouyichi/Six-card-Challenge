flags = -pedantic-errors -std=c++11
functionused.o: functionused.cpp functionused.h
	g++ $(flags) -c $<

sixcard.o: sixcard.cpp functionused.h
	g++ $(flags) -c $<

sixcard: functionused.o sixcard.o
	g++ $(flags) $^ -o $@

clean:
	rm -f sixcard sixcard.o functionused.o

.PHONY: clean
