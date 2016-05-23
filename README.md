# Libraries benchmarking on different number of cores 
Our main goal is to do benchmarking so that we could demonstrate which type of multi-threading is better for a specific core number processor. Also, we wanted to analyze and compare different libraries available to achieve explicit multi-threading to see how they perform so that we could conclude which library is the best as compared to others.

### Run:###

    bash setup.sh

This will create four executables for you to run.

Three different threading libraries and one implicit thread testing program


	./boost_threads 100

This will run the boost_thread implimentation with 10 threads.
All three programs are run the same way and can be started with up to 100 threads.


	./implicit

This will run one program that has quite a long execution time so you can see how the compiler effects it
It is compiled in the 4th line of the setup.sh file using g++ right now. It is there that you can change what it is compiled with.
