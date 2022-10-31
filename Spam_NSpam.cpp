#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<string>> spam = {{"buy","Click", "fantastic", "access", "deal", "bonus", "stock", "free", "trial","gift"},
    {"drastically", "reduced", "exclusive","deal", "get", "Hurry", "instant", "limited", "now", "offer"},
    {"Order", "expires", "get", "Hurry", "offer", "urgent", "stock", "price", "bargain", "bonus"},
    {"promise", "pure", "get", "gurranted", "millions", "dollar", "instant", "offer", "pure", "market"},
    {"hot", "cutie", "certified", "cheap", "purchase", "dollar", "winner", "urgent", "exclusive", "deal"}};

 
    vector<vector<string>> ham = {{"drive", "application", "interview", "opportunity", "selected", "welcome", "nit", "iit", "developer", "regards"},
    {"education", "assessment", "campus", "tech", "drive", "congratulations", "look", "certificate", "round", "hiring"},
    {"tech", "look", "student", "intern", "engineer", "contest", "alert", "save", "interview", "stand"},
    {"thanks", "status", "gate", "campus", "live", "event", "job", "notes", "leetcode", "weekly"},
    {"look", "host", "experience", "design", "skills", "review", "ready", "notes", "email", "response"}};
    

    set<string> vocabulary;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            vocabulary.insert(spam[i][j]);
        }  
    }
   
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            vocabulary.insert(ham[i][j]);
        } 
    }

    // vector<string> spam_text;
    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         spam_text.push_back(spam[i][j]);
    //     }  
    // }

    set<string> spam_text;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            spam_text.insert(spam[i][j]);
        }  
    }

     set<string> ham_text;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            ham_text.insert(ham[i][j]);
        }  
    }
    // vector<string> ham_text;
    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         ham_text.push_back(ham[i][j]);
    //     }  
    // }
    // 1. vocabulary size
    cout<<"Vocabulary size is " << vocabulary.size()<<"\n";
    // 2. no of words in spam files
    cout<<"No of words in spam files "<<spam_text.size()<<"\n";
    // 3. no of words in ham files
    cout<<"No of words in ham files "<<ham_text.size()<<"\n";

    // my test words
    vector<string> test = {"get", "tech", "drive", "event", "buy"};

    // 4 posterior value of spam
    double Pspam = (double)spam.size()/(spam.size()+ham.size());
    
    double cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
    
    for(auto s : spam_text) {
        if(s == "get") {
            cnt1++;
        }
        if(s == "tech") {
            cnt2++;
        }
        if(s == "drive") {
            cnt3++;
        }
        if(s == "event") {
            cnt4++;
        }
        if(s == "buy") {
            cnt5++;
        }
    }
    cout<<"counts in spam class: "<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<" "<<cnt5<<endl;
    
    double Pt1_spam = (cnt1 + 1)/(spam_text.size()+vocabulary.size());
    double Pt2_spam = (cnt2 + 1)/(spam_text.size()+vocabulary.size());
    double Pt3_spam = (cnt3 + 1)/(spam_text.size()+vocabulary.size());
    double Pt4_spam = (cnt4 + 1)/(spam_text.size()+vocabulary.size());
    double Pt5_spam = (cnt5 + 1)/(spam_text.size()+vocabulary.size());
    cout<<"probality: "<<Pspam<<" "<<Pt1_spam<<" "<<Pt2_spam<<" "<<Pt4_spam<<" "<<Pt3_spam<<" "<<Pt5_spam<<endl;
    double Posterior_spam = Pspam * Pt1_spam * Pt2_spam * Pt3_spam * Pt4_spam * Pt5_spam; 
    cout<<"Posterior values of spam " <<Posterior_spam<<endl;

    // 5. posterior values of ham calculation
    cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
    for(auto s : ham_text) {
        if(s == "get") {
            cnt1++;
        }
        if(s == "tech") {
            cnt2++;
        }
        if(s == "drive") {
            cnt3++;
        }
        if(s == "event") {
            cnt4++;
        }
        if(s == "buy") {
            cnt5++;
        }
    }
    cout<<"counts in ham class : "<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<" "<<cnt5<<endl;
    double Pham = (double)ham.size()/(spam.size()+ ham.size());
    double Pt1_ham = (cnt1+1)/(ham_text.size()+vocabulary.size());
    double Pt2_ham = (cnt2+1)/(ham_text.size()+vocabulary.size());
    double Pt3_ham = (cnt3+1)/(ham_text.size()+vocabulary.size());
    double Pt4_ham = (cnt4+1)/(ham_text.size()+vocabulary.size());
    double Pt5_ham = (cnt5+1)/(ham_text.size()+vocabulary.size());
    cout<<"Prob = "<<Pham<<" "<<Pt1_ham<<" "<<Pt2_ham<<" " << Pt3_ham<<" " << Pt4_ham<<" " << Pt5_ham<<endl;
    double Posterior_ham = Pham * Pt1_ham * Pt2_ham * Pt3_ham * Pt4_ham * Pt5_ham;

    cout<<"Posterior Values of Ham "<< Posterior_ham<<endl;


    // 6. Testing file is : 
    if(Posterior_spam > Posterior_ham) {
        cout<<"test file is spam class\n";
    } else {
        cout<<"test file is ham class\n";
    }

    return 0;



}