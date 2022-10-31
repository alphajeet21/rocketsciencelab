/*  STOCHASTIC GRADIENT DESCENT
 In Stochastic Gradient Descent (SGD), 
 we consider just one example at a time to take a single step 
 
 
 or more clear 
 In Batch Gradient Descent we were considering all the examples for every step of Gradient Descent.
  But what if our dataset is very huge. Deep learning models crave for data. 
  The more the data the more chances of a model to be good. Suppose our dataset has 5 million 
  examples, then just to take one step the model will have to calculate the gradients of all 
  the 5 million examples. This does not seem an efficient way. To tackle this problem we have 
  Stochastic Gradient Descent. In Stochastic Gradient Descent (SGD), 
  we consider just one example at a time to take a single step. 
 */
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define desired_error 0.10
#define no_of_sample 5

void testing(int);
float h[no_of_sample];
float cal_h(int, int);
void w_initialisation();
double alpha[5] = {.0000001, .0000002, .0000003, .0000004, .0000005};

// Initialise the training set
int x[no_of_sample][2] = {{1156, 2}, {2100, 3}, {517, 1}, {1028, 2}, {3075, 4}};

// Give the testing data
int test[3][2] = {{1156, 2}, {1500, 2}, {2500, 2}};

float y[no_of_sample] = {10, 20, 5, 9.5, 30};
float w[5][3] = {{.05, .001, .02}, {.001, .007, .2}, {.2, .007, .02}, {.1, .008, .09}, {.4, .004, .1}};

int main()
{
  int i, j;
  int xy;
  for(xy = 0; xy < 5; xy++) { // loop for 5 different alpha

  int k;
  
  for(k = 0; k < 5; k++) // loop for 5 different w0,w1,w2 predictions
  {

    float error = 1;
    int e = 0;
    printf("\n For the Learning rate alpha= %0.7f", alpha[xy]);
    printf("\n set number %d of Weights for alpha %d are: w[%d][0]=%f,w[%d][1]=%f,w[%d][2]=%f",k+1,xy+1, k, w[k][0], k,w[k][1],k, w[k][2]);

    while (error > desired_error)
    {

      printf("\n\n For Epoch %d", ++e);

      for (i = 0; i < no_of_sample && error > desired_error; i++)
      {

        printf("\n\nHypothesis for Training sample %d= %f", i + 1, cal_h(i, k));
        error = 0.5 * pow((h[i] - y[i]), 2);
        printf("\nCost= %f", error);

        for (j = 0; j < 3; j++)
        {
          if (j == 0)
          {
            w[k][0] = w[k][0] + alpha[xy] * (y[i] - h[i]) * 1;
            printf("\n Weight Updated Values");
            printf("\nw%d=%f", j, w[k][j]);
          }
          else
          {

            w[k][j] = w[k][j] + alpha[xy] * (y[i] - h[i]) * x[i][j - 1];
            printf("\nw%d=%f", j, w[k][j]);
          }
        }
      }
    }
    testing(k);
    
  }
  printf("\n\n<-----------------For Next Alpha------------------------->\n");
  getch();
  }
  return 0;
}

void testing(int m)
{
  int i, j;
  float test_y = 0.0;
  for (i = 0; i < 3; i++)
  {
    test_y = 0.0;
    int k;
      for (j = 0; j < 3; j++)
      {
        if (j == 0)
        {
          test_y = w[m][j];
        }
        else
          test_y = test_y + w[m][j] * test[i][j - 1];
      }
      
    
    printf("\n\ntest_y for test set {%d,%d}=%f\n", test[i][0], test[i][1], test_y);

    
  }
}

float cal_h(int i, int k)
{
  int j;
  float temp = 0.0;
  for (j = 0; j < 3; j++)
  {
    if (j == 0)
    {
      temp = w[k][0];
    }
    else
    {
      temp = temp + w[k][j] * x[i][j - 1];
    }
  }
  h[i] = temp;
  return h[i];
}

