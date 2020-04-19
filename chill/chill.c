// Eyasu Lemma, CS50, Spring 2020
// This program takes wind speed and teperature and calculates wind speed

#include<stdio.h>
#include<math.h>


float chill_calculator(int temp, int wind){	   //the function that calculates wind chill using temperature 
	float chill = 35.74 + 0.6215*temp - 35.75*(pow(wind, 0.16)) + 0.4275*temp*(pow(wind, 0.16));  // and wind speed
	return chill;
}

int main(int argc, char *argv[]){
	float temp, wind, chill;

	if(argc == 1){  

		printf("Temp \t Wind \t Chill\n");
	    printf("---- \t ---- \t -----\n");

		for(temp = -10; temp < 50; temp += 10){  //for a difference of 10 in temp starting from -10
			for(wind = 5; wind < 20; wind+= 5){		// and for a difference of 5 in wind V starting from 5
				chill = chill_calculator(temp, wind); // calculate and display temp, wind, and chill
				printf("%.0f \t %.0f \t %.1f\n", temp, wind, chill);
			}	
			printf("\n");
		}	
			
	}

	if(argc == 2){
		 int f = sscanf(argv[1], "%f", &temp);
		 
		 if( f == 0){
			 fprintf(stderr, "Error: enter a number\n");
			 return 1;
		 }

		 if( (temp > -99) && (temp < 50)){								  // if argument is two the consider as temperature 
		 	printf("Temp\tWind\tChill\n");   // and do wind chill calculation for a range of wind speed as above
		 	printf("---- \t ---- \t -----\n");
		 
		 	for(wind = 5; wind < 20; wind+= 5){              
			 	chill = chill_calculator(temp, wind); 
			 	printf("%.0f \t %.0f \t %.1f\n", temp, wind, chill );                                           
		 	}
		 }
		 else{
		 	 fprintf(stderr, "Error: temperature out of bounds\n");
			 return 1;
		 }
		 	 
	}

	if(argc == 3){
		sscanf(argv[1], "%f", &temp); // if argument is three, then take temp and wind speed from arguments
		sscanf(argv[2], "%f", &wind); // and calculate speed. 
		
		if( temp > -99 && temp < 50 && wind > 0.5){
			printf("Temp \t Wind \t Chill\n"); 
	    	printf("---- \t ---- \t -----\n");
			chill = chill_calculator(temp, wind);    
			printf("%.0f \t %.0f \t %.1f\n", temp, wind, chill); 
		}
		else
		{
			fprintf(stderr, "Error: temperature or wind speed out of bound\n" );
			return 1;
		}
			                                                                                                                         

	}

	if(argc > 3){
		fprintf(stderr, "Error: exceeded limit of arguments\n" );
		return 1;
	}
	return 0;
}
