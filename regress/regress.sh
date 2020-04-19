#Eyasu Lemma, CS 50, Spring 2020
#This program does regression testing against previous results and 
#see performance 

#!/bin/bash

b=$(echo $1)       #assign the directory to a variable 
shift               # shift the arguments 

if [ $# -ge 1 ]   #for each argument or testfile 
then 
    x=$(date "+%Y%m%d.%I%M%S")    #create a directory using current time and date
    mkdir ./$x                      #to save the results 
    
    for i in $@
    do   

      y=$(find ~ -name $i)      #find the test file

      if [ -z "$y" ]           #if the test file does not exists
      then 
          echo one of the testfiles do not exist
          exit 20  
      fi  

      z=$(basename $y)                        #if the test file exists
      $y 1> ./$x/$z.stdout 2> ./$x/$z.stderr   #create its ouput, status, error and copy files.
      echo $? > ./$x/$z.status 
      cp $y ./$x/$z.test
     done 
else 
    echo error: not enough arguments   #if argument not more than 1 send error message
    exit 20       
fi

a=$(find ~ -name $b)

if [ -d "$a" ]   #check if the directory exists
then 
    result=$(diff -rq $a ./$x)   #if it does then compare to current directory and 
    if [ -z "$result" ]             #if no difference say that
    then                            # if difference echo the difference 
        echo no difference
    else
        echo $result
    fi    
else   
    mv ./$x ./$b            #if the directory doesn't exist then rename current directory 
fi                            #with the name of directory given
 