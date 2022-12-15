CLANG=clang++ -std=c++20
Dir=range-v3/include/

dijkstra : main.cpp
	$(CLANG) $? -I $(Dir) -o $@

