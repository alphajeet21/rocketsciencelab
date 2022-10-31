// person classification (Renu Ma'am)
#include<bits/stdc++.h>
using namespace std;

int main() {
    // vector<string> person;
    // vector<int> height, weight, footsize;

    string s[] = {"male", "male", "male", "male","male", "female", "female", "female", "female", "female"};
    double height[] = {6.1, 5.94, 5.65, 5.58, 5.92, 5.1, 5, 5.5, 5.46, 5.73};
    double weight[] = {180,192,180,170,165, 105,100, 150, 130, 148};
    double footsize[] = {12.1, 11.8, 11, 10.7,10,6.2, 6, 8, 7, 9};

   // for testing
   double testheight[] = {6, 6};
   double testweight[] = {140, 170};
   double testfootsize[] = {8, 11};

    int n = sizeof(weight)/sizeof(double);

/* mean and Variance Calculation of Height of male and Female */

    double meanHMale, meanHFemale, cntM = 0, cntF = 0;
    double sumHMale = 0, sumHFemale = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            sumHMale += height[i];
            cntM++;
        }
        else {
            sumHFemale += height[i];
            cntF++;
        }
    }

    meanHMale = sumHMale/cntM;
    meanHFemale = sumHFemale/cntF;
    cout<<"mean Height male = "<<meanHMale<<" mean Height female =  "<<meanHFemale;

    double varHeightM = 0, varHeightF = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            varHeightM += pow((height[i]-meanHMale), 2);
        }
        else {
            varHeightF += pow((height[i]-meanHFemale), 2);
        }
    }

    varHeightM /= (cntM-1);
    varHeightF /= (cntF-1);
    cout<<"\nVariance Height male = "<<varHeightM<< " Variance Height Female = " <<varHeightF;


/* Mean and Variance Calculation of weight of male and female */

    double meanWMale, meanWFemale;
    double sumWMale = 0, sumWFemale = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            sumWMale += weight[i];
        }
        else {
            sumWFemale += weight[i];
        }
    }

    meanWMale = sumWMale/cntM;
    meanWFemale = sumWFemale/cntF;

    cout<<"\nMean weight male = "<<meanWMale<<" Mean weight female =  "<<meanWFemale;

    double varWeightM = 0, varWeightF = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            varWeightM += pow((weight[i]-meanWMale), 2);
        }
        else {
            varWeightF += pow((weight[i]-meanWFemale), 2);
        }
    }

    varWeightM /= (cntM-1);
    varWeightF /= (cntF-1);
    cout<<"\nVariance weight male = "<<varWeightM<< " Variance weight female = " <<varWeightF;


/* Mean and Variance Calculation of Foot Size of male and female */
    double meanFMale, meanFFemale;
    double sumFMale = 0, sumFFemale = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            sumFMale += footsize[i];
        }
        else {
            sumFFemale += footsize[i];
        }
    }

    meanFMale = sumFMale/cntM;
    meanFFemale = sumFFemale/cntF;
    cout<<"\nMean footsize male = "<<meanFMale<<" Mean footsize female =  "<<meanFFemale;

    double varFootSizeM = 0, varFootSizeF = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == "male") {
            varFootSizeM += pow((footsize[i]-meanFMale), 2);
        }
        else {
            varFootSizeF += pow((footsize[i]-meanFFemale), 2);
        }
    }

    varFootSizeM /= (cntM-1);
    varFootSizeF /= (cntF-1);
    cout<<"\nVariance footsize male = "<<varFootSizeM<< " Variance footsize female = " <<varFootSizeF;
int testsize = sizeof(testheight)/sizeof(double);
for(int i = 0; i < testsize; i++) {


    double probHeightgivenMale =  1/(sqrt(2 * 3.14 * varHeightM)) * exp(-pow((testheight[i]-meanHMale), 2)/(2 * varHeightM));

cout<<"\n probHeightgivenMale = "<<probHeightgivenMale;

double probWeightgivenMale =  1/(sqrt(2 * 3.14 * varWeightM)) * exp(-pow((testweight[i] -meanWMale), 2)/(2 * varWeightM));
cout<<"\n probWeightgivenMale = " << probWeightgivenMale;

double probFootsizegivenMale =  1/(sqrt(2 * 3.14 * varFootSizeM)) * exp(-pow((testfootsize[i] -meanFMale), 2)/(2 * varFootSizeM));
cout<<"\n probFootsizegivenMale = "<<probFootsizegivenMale;



double probHeightGivenFemale = 1/(sqrt(2 * 3.14 * varHeightF)) * exp(-pow((testheight[i] -meanHFemale), 2)/(2 * varHeightF));
cout<<"\n probHeightGivenFemale"<< probHeightGivenFemale;

double probWeightGivenFemale = 1/(sqrt(2 * 3.14 * varWeightF)) * exp(-pow((testweight[i] -meanWFemale), 2)/(2 * varWeightF));
cout<<"\n probWeightGivenFemale = "<<probWeightGivenFemale;

double probFootsizeGivenFemale = 1/(sqrt(2 * 3.14 * varFootSizeF)) * exp(-pow((testfootsize[i] -meanFFemale), 2)/(2 * varFootSizeF));
cout<<"\n probFootsizeGivenFemale = "<<probFootsizeGivenFemale;


double posteriorMale = (cntM/(cntM+cntF)) * probHeightgivenMale * probWeightgivenMale * probFootsizegivenMale;
double posteriorFemale = (cntF/(cntM+cntF)) * probHeightGivenFemale * probWeightGivenFemale * probFootsizeGivenFemale;
cout<<"\n posteriormale = " <<posteriorMale<<"\n posteriorFemale = "<<posteriorFemale<<endl;
if(posteriorMale > posteriorFemale) {
    cout<<i<<"th Sample is Male";
}
else {
    cout<<i<<"th Sample is Female";
}
}
    return 0;    
}