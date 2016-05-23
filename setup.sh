g++ -o boost_threads boost.cpp -lboost_thread -std=c++11 -lboost_system
g++ -o posix_threads posix.cpp -std=c++11 -pthread
g++ -o std_threads std.cpp -std=c++11 -pthread
g++ -o implicit implicit.cpp -std=c++11
