// Eyasu Lemma, CS 50, Lab 2, Spring 2020
// Date 4/17/2020
//This Program makes a histogram with bin 16 and expands accordingly 


#include<stdio.h>
 
int range = 1;    // inital range value of histogram 
const int bins = 16;  //constant bin size
int a;                // pointer for input integer from user
int histo_array[16];   //histogram array 

int field_size(int value){    //finds the field size by finding the largest integer size value
    int compare = 10;
    int counter = 1;
    while(value > compare){
        compare *= 10;
        counter+=1;
    }
    return counter;   //returns the field size;
}

void incrementer(int x){  //increments the appropriate range of histogram given an integer a
    int counter = 0;
    for(int i = 0; i < bins; i++){   //goes through the range and compares
        if((x >= counter) && (x <= counter + range -1)){
            histo_array[i] = histo_array[i] + 1;
        }
        counter += range;
    }
}

int main(){
    printf("%d bins of size %d for range[0, %d)\n", bins, range, bins);
    while(scanf("%d", &a) != EOF){
        if(a < (bins*range)){   //if input within current histogram then just increment
            incrementer(a);
        }
        else{                    //if not
           
            while( a >= (bins*(range))){  //increase range till integer input within histogram range of values
                range *=2;
                printf("%d bins of size %d for range[0, %d)\n", bins, range, bins*range);

                int count = 0;                    //update the histogram with each scaling 
                for(int u = 0; u < bins; u+=2){
                histo_array[count] = histo_array[u] + histo_array[u+1];
                count +=1;
                }
                for(int u = bins/2; u < bins; u ++){
                histo_array[u] = 0;
                }
            }
            incrementer(a);    //finally increment integer
        }
    }

    int counter = 0;    //print the histogram with appropriate formal using the field finding function
    int field = field_size(bins*range -1);
    printf("%d\n", field);
    for(int w = 0; w < bins;  w ++){
        printf("[");
        printf("%*d:", field, counter);
        printf("%*d]", field, counter + range -1);
        if(histo_array[w] > 0){
            printf(" %d", histo_array[w]);
        }
        printf("\n");
        counter += range;
    }
    return 0;
}    
