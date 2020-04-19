Testing of this file happens by inputting numbers and seeing if the outcome is correct. 

I used this tests from the course webpage:
    $ mygcc histo.c -o histo
$ ./histo
16 bins of size 1 for range [0,16)
3 -4 5 1 7 0
8 0 15 12 3 5
3 3 3 3 3
^D
[ 0: 0] 2
[ 1: 1] 1
[ 2: 2]
[ 3: 3] 7
[ 4: 4]
[ 5: 5] 2
[ 6: 6]
[ 7: 7] 1
[ 8: 8] 1
[ 9: 9]
[10:10]
[11:11]
[12:12] 1
[13:13]
[14:14]
[15:15] 1
$





$ ./histo
16 bins of size 1 for range [0,16)
3 -4 5 1 7 0
8 0 15 12 3 5
18
16 bins of size 2 for range [0,32)
19 20 30 7 12
50
16 bins of size 4 for range [0,64)
34
32
19
44
^D
[ 0: 3] 5
[ 4: 7] 4
[ 8:11] 1
[12:15] 3
[16:19] 3
[20:23] 1
[24:27]
[28:31] 1
[32:35] 2
[36:39]
[40:43]
[44:47] 1
[48:51] 1
[52:55]
[56:59]
[60:63]
$



$ echo {1..16} 150 | ./histo
16 bins of size 1 for range [0,16)
16 bins of size 2 for range [0,32)
16 bins of size 4 for range [0,64)
16 bins of size 8 for range [0,128)
16 bins of size 16 for range [0,256)
[  0: 15] 15
[ 16: 31] 1
[ 32: 47]
[ 48: 63]
[ 64: 79]
[ 80: 95]
[ 96:111]
[112:127]
[128:143]
[144:159] 1
[160:175]
[176:191]
[192:207]
[208:223]
[224:239]
[240:255]
$