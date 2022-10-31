/*  
Batch Gradient Descent :- 
In Batch Gradient Descent we are considering all the examples 
for every step of Gradient Descent 
But what if our dataset is very huge. Deep learning models crave for data. 
The more the data the more chances of a model to be good. Suppose our dataset has 
5 million examples, then just to take one step the model will have to calculate the 
gradients of all the 5 million examples. This does not seem an efficient way. 
To tackle this problem we have Stochastic Gradient Descent
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define desired_error 0.10
#define no_of_sample 10
#define alpha .000000001
void testing();
float h[no_of_sample];
float cal_h(int);
void w_initialisation();


// Initialise the training set
int x[no_of_sample][2] = {{1000, 2}, {2000, 4}, {500, 1}, {3000, 6}, {1500, 3}, {3500, 7}, {4500,9},
{5000, 10}, {5500, 11}, {6000, 12}};

// Initialising the testing data
int test[2][2] = {{4000, 8},{1000,2}};

float y[no_of_sample] = {24, 48, 12, 72, 36, 84, 108, 120,132, 144};
// float w[5][3] = {{.05, .001, .02}, {.001, .007, .2}, {.2, .007, .02}, {.1, .008, .09}, {.4, .004, .1}};
float w[3] = {0.05,0.001,0.02};
int main()
{
  int i, j;
 

    float error = 1;
    int e = 0;
    printf("\n For the Learning rate alpha= .00000001");
    printf("\n Initial Weights for alpha %.9f are: w[0]=%f,w[1]=%f,w[2]=%f",alpha, w[0],w[1], w[2]);

    while (error > desired_error)
    {
      float sum = 0.0;
      int b;
      printf("\n\n For Epoch %d", ++e);
      for(b = 0; b < no_of_sample; b++) {
          printf("\n\nHypothesis for Training sample %d= %f", b + 1, cal_h(b));  //j is sample no and k is the set of w
      }
      int k;
        for(k = 0; k < no_of_sample; k++) {
          sum += pow((h[k] - y[k]), 2);
        }
        float sumof_w = 0.0;
        int a;
        for(a = 0; a < no_of_sample; a++) {
          sumof_w += (y[a] - h[a]);
        }
      for (i = 0; i < no_of_sample && error > desired_error; i++) {

        error = (0.5/no_of_sample) * sum; // h[i] initialisd in cal_h function
        printf("\nCost = %f", error);
        
        for (j = 0; j < 3; j++)
        {
          if (j == 0) {
            w[0] = w[0] + alpha * (sumof_w) * 1;
            printf("\n Weight Updated Values");
            printf("\nw%d=%f", j, w[j]);
          }
          else
          {
            w[j] = w[j] + alpha * (sumof_w) * x[i][j - 1];
            printf("\nw%d=%f", j, w[j]);
          }
        }
      }
    }
    testing();
  
  getch();
  
  
  return 0;
}

void testing()
{
  int i, j;
  float test_y = 0.0;
  for (i = 0; i < 2; i++)
  {
    test_y = 0.0;
    int k;
      for (j = 0; j < 3; j++)
      {
        if (j == 0)
        {
          test_y = w[j];
        }
        else
          test_y = test_y + w[j] * test[i][j - 1];
      }
      
    
    printf("\n\ntest_y for test set {%d,%d}=%f\n", test[i][0], test[i][1], test_y);
    
  }
}

float cal_h(int i)
{
  int j;
  float temp = 0.0;
  for (j = 0; j < 3; j++)
  {
    if (j == 0)
    {
      temp = w[0];
    }
    else
    {
      temp = temp + w[j] * x[i][j - 1];
    }
  }
  h[i] = temp;
  return h[i];
}

