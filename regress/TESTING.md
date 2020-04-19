I tested the program by using three test cases of my own and did everything that was done on the course webpage, except replaced with my test files. 

[lab2/regress/testdir]$ ls
query.sh*	test0		test1		test2		test3
[lab2/regress/testdir]$ cat test?
cat query.sh
./query.sh
./query.sh TEST
./query.sh CITY STABBR SAT_AVG_ALL UGDS
[lab2/regress/testdir]$ ../regress.sh base test?
saved test results in base
[lab2/regress/testdir]$ ../regress.sh base test?
saved test results in 20190112.114114
comparing 20190112.114114 with base...
no differences
[lab2/regress/testdir]$ echo ./query.sh CITY > test4
[lab2/regress/testdir]$ ls
20190112.114114/  base/  query.sh*  test0  test1  test2  test3  test4
[lab2/regress/testdir]$ ../regress.sh base test?
saved test results in 20190112.114227
comparing 20190112.114227 with base...
Only in 20190112.114227: test4.status
Only in 20190112.114227: test4.stderr
Only in 20190112.114227: test4.stdout
Only in 20190112.114227: test4.test
[lab2/regress/testdir]$ echo ./query.sh UG > test2
[lab2/regress/testdir]$ cat test?
cat query.sh
./query.sh
./query.sh UG
./query.sh CITY STABBR SAT_AVG_ALL UGDS
./query.sh CITY
[lab2/regress/testdir]$ ../regress.sh base test?
saved test results in 20190112.114425
comparing 20190112.114425 with base...
Files base/test2.stdout and 20190112.114425/test2.stdout differ
Files base/test2.test and 20190112.114425/test2.test differ
Only in 20190112.114425: test4.status
Only in 20190112.114425: test4.stderr
Only in 20190112.114425: test4.stdout
Only in 20190112.114425: test4.test
[lab2/regress/testdir]$ ls
20190112.114114/  20190112.114425/  query.sh*  test1  test3
20190112.114227/  base/       test0      test2  test4
[lab2/regress/testdir]$
######## now some error cases
[lab2/regress/testdir]$ ../regress.sh
usage: regress.sh dirname testfilename...
[lab2/regress/testdir]$ ../regress.sh base
usage: regress.sh dirname testfilename...
[lab2/regress/testdir]$ ../regress.sh test?
first argument ('test0') is not a directory
[lab2/regress/testdir]$ ../regress.sh /base test?
mv: cannot create directory '/base': Permission denied
failed to save test results in /base; they remain in 20190112.115105
[lab2/regress/testdir]$ ../regress.sh base testing
test case 'testing' is not a file (or not readable)
[lab2/regress/testdir]$ ../regress.sh base base
test case 'base' is not a file (or not readable)
[lab2/regress/testdir]$ chmod -r test?
[lab2/regress/testdir]$ ../regress.sh base test?
test case 'test0' is not a file (or not readable)
[lab2/regress/testdir]$