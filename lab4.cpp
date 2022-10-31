#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<string> ham;
    vector<string> spam;
    set<string> vocabulary; 

    map<string,int> freqspam;
    map<string,int> freqham;

    // Combining the spam files
    ifstream in1("spam1.txt");
    ofstream f1("spamcombo.txt", ios::app);
    while(!in1.eof()){
        string text;
        getline(in1,text);
        spam.push_back(text);
        vocabulary.insert(text);
        freqspam[text]++;
        f1<<text<<endl;
    }
    ifstream in2("spam2.txt");
    ofstream f2("spamcombo.txt", ios::app);
    while(!in2.eof()){
        string text;
        getline(in2,text);
        spam.push_back(text);
        vocabulary.insert(text);
        freqspam[text]++;
        f2<<text<<endl;
    }
    ifstream in3("spam3.txt");
    ofstream f3("spamcombo.txt", ios::app);
    while(!in3.eof()){
        string text;
        getline(in3,text);
        spam.push_back(text);
        vocabulary.insert(text);
        freqspam[text]++;
        f3<<text<<endl;
    }
    ifstream in4("spam4.txt");
    ofstream f4("spamcombo.txt", ios::app);
    while(!in4.eof()){
        string text;
        getline(in4,text);
        spam.push_back(text);
        vocabulary.insert(text);
        freqspam[text]++;
        f4<<text<<endl;
    }
    ifstream in5("spam5.txt");
    ofstream f5("spamcombo.txt", ios::app);
    while(!in5.eof()){
        string text;
        getline(in5,text);
        spam.push_back(text);
        vocabulary.insert(text);
        freqspam[text]++;
        f5<<text<<endl;
    }

    // combining the nonspam files
    ifstream ins1("ham1.txt");
    ofstream nsf1("hamcombo.txt", ios::app);
    while(!ins1.eof()){
        string text;
        getline(ins1,text);
        ham.push_back(text);
        vocabulary.insert(text);
        freqham[text]++;
        nsf1<<text<<endl;
    }

    ifstream ins2("ham2.txt");
    ofstream nsf2("hamcombo.txt", ios::app);
    while(!ins2.eof()){
        string text;
        getline(ins2,text);
        ham.push_back(text);
        vocabulary.insert(text);
        freqham[text]++;
        nsf2<<text<<endl;
    }

    ifstream ins3("ham3.txt");
    ofstream nsf3("hamcombo.txt", ios::app);
    while(!ins3.eof()){
        string text;
        getline(ins3,text);
        ham.push_back(text);
        vocabulary.insert(text);
        freqham[text]++;
        nsf3<<text<<endl;
    }
    ifstream ins4("ham4.txt");
    ofstream nsf4("hamcombo.txt", ios::app);
    while(!ins4.eof()){
        string text;
        getline(ins4,text);
        ham.push_back(text);
        vocabulary.insert(text);
        freqham[text]++;
        nsf4<<text<<endl;
    }
    ifstream ins5("ham5.txt");
    ofstream nsf5("hamcombo.txt", ios::app);
    while(!ins5.eof()){
        string text;
        getline(ins5,text);
        ham.push_back(text);
        vocabulary.insert(text);
        freqham[text]++;
        nsf5<<text<<endl;
    }
   
    int docspam = 5;
    int docnonspam = 5;

    int vocabularysize = vocabulary.size();
    int nspam = spam.size();
    int nnonspam = ham.size();

    float pspam = docspam*1.0/(docspam + docnonspam);
    float pnonspam = docnonspam*1.0 / (docspam + docnonspam);

    float posteriorspam = 1.0*pspam;
    float posteriornonspam = 1.0*pnonspam;

    ifstream intest1("test.txt");
    while(!intest1.eof()){
        string text;
        getline(intest1,text);
        posteriorspam *= (freqspam[text] + 1)*1.0/(nspam + vocabularysize);
    }

    ifstream intest2("test.txt");
    while(!intest2.eof()){
        string text;
        getline(intest2,text);
        posteriornonspam *= (freqham[text] + 1)*1.0/(nnonspam + vocabularysize);
    }
    cout<<"Vocabulary size : "<<vocabularysize<<endl;

    cout<<"Spam file size : "<<nspam<<endl;
    cout<<"Nonspam file size : "<<nnonspam<<endl;

    cout<<"Posterior of spam : "<<posteriorspam<<endl;
    cout<<"Posterior of nonspam : "<<posteriornonspam<<endl;

    if(posteriorspam > posteriornonspam){
        cout<<"Test file is a spam file!!!"<<endl;
    }else{
        cout<<"Test file is a non spam file."<<endl;
    }

    return 0;

}