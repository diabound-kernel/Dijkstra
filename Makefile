CXX=clang++ -std=c++20
Dir=range-v3/include/

dijkstra : main.cpp
	$(CXX) $? -I $(Dir) -o $@

clean :
		rm dijkstra