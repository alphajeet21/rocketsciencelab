#include <stdio.h>
#include <conio.h>
#include <math.h>
#define alpha .00000001
#define no_of_sample 10
	
void testing();
float h[no_of_sample];
float  cal_h(int);
void w_initialisation();
void calculateHypothesis();

// Initialise the training set
int x[no_of_sample][2]= { {1000,2}, {2000,4},{500,1}, {3000,6},{1500,3},{3500,7},{4500,9},{5000,10},{5500,11},{6000,12}};

// Give the testing data
int test[no_of_sample][2]= { {1000,2}, {2000,4}, {3000,6}, {4000,8}};

float y[no_of_sample]={24,48,12,72,36,84,108,120,132,144};
float w[3];

float hypothesis[no_of_sample];

int main(){ 
    for(int k=1;k<=5;k++){
        int i,j;
        float error=1;
        printf("\n\nGive %dth set of weights:",k);  	
        float a;
        float b;
        float c;
        scanf("%f",&a);
        scanf("%f",&b);
        scanf("%f",&c);
        w[0] = a;
        w[1] = b;
        w[2] = c;
        int e=0;
        float desired_error = 0.10;
        printf("\n For the Learning rate alpha= %0.8f", alpha);
        printf("\n Initial Weights are: w[0]=%f,w[1]=%f,w[2]=%f",w[0],w[1],w[2]);	
        while(error>desired_error){
            printf("\n\n For Epoch %d",++e);
            
            for(i = 0; i < no_of_sample && error > desired_error; i++){

                // Calculate the hypothesis for all the samples using updated weights
                for(int sample = 0; sample < 10; sample++){
                    printf("\n\nHypothesis for Training sample %d= %f", sample+1,cal_h(sample));
                }

                // Summation for finding the error (summation pow(h[sample]-y[sample],2))
                float summation = 0.0f;
                for(int sample = 0; sample < no_of_sample; sample++){
                    summation += pow((hypothesis[sample]- y[sample]), 2);
                }
                // Find the error
                error = (0.5/no_of_sample) * summation;
                printf("\nCost = %f", error);
                
                // Update the weights accordingly
                for (j = 0; j < 3; j++){
                    if (j == 0) {
                        float weightUpdateSummation = 0.0f;
                        for(int k = 0; k < no_of_sample; k++){
                            weightUpdateSummation += (y[k] - hypothesis[k]);
                        }
                        w[0] = w[0] + alpha * (weightUpdateSummation);
                        printf("\n Weight Updated Values");
                        printf("\nw%d=%f", j, w[j]);
                    }else{
                        float weightUpdateSummation = 0.0f;
                        for(int k = 0; k < no_of_sample; k++){
                            weightUpdateSummation += (y[k] - hypothesis[k])*x[k][j-1];
                        }
                        w[j] = w[j] + alpha * (weightUpdateSummation);
                        printf("\nw%d=%f", j, w[j]);
                    }
                }
            }
            // If the calculated error is still less than desired error then run the next epoc
           
        }
        // Predict values for the given data
        testing();
    }
    getch();
    return 0;
}

void testing(){  
    int i,j;
    float test_y=0.0;
    for(i=0; i < 4; i++){ 
       test_y=0.0;
       
       for(j=0; j < 3; j++){
           if(j == 0){ 
		   	    test_y = w[0] * 1;
	 	   }else{ 
                test_y= test_y + w[j] * test[i][j-1];
           }
        }
        printf("\n\ntest_y for test set {%d,%d}=%f\n",test[i][0],test[i][1],test_y);
    }
}

float  cal_h( int i){  
    int j;
    float temp=0.0;
    for(j=0; j < 3; j++){
        if(j==0){ 
            temp=w[0];
        }else{
            temp = temp + w[j]* x[i][j-1];
        }
    }
    hypothesis[i]=temp;
    return hypothesis[i];
}