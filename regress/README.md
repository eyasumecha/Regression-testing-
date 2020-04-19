This program does regression testing of software and compare outcome to previous test results and see difference. 

Compilation:
    mygcc regress.sh -o regress


Execution:
    ./regress.sh   -and it takes at least two arguments and will return an error if not. 
                    -it takes a directory and a test files arguments and compares the 
                    - outcome of the test cases to the results in the directory and returns the difference. 