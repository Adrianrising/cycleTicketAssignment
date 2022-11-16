//
// Created by BMT on 11/9/2022.
//
#include "string"
#include "iostream"
#include "lottery.h"
#include "fstream"
using namespace std;
using namespace A;

void lottery::welcome(){
    cout<<"Program is loading..."<<endl<<"These numbers are taken by other customers."<<endl;
    mainLoading();
    showData();
    mainMenu();

}

void lottery::mainMenu() {
    cout<<"Enter 1 to choose numbers"<<endl<<"Enter 2 to quit:";
    cin>>option;
    if(option=="1"){
        numberChoosing();
    }else{
        cout<<"Bye Bye GOOD LUCK!";
        exit(0);
    }
}


void lottery::numberChoosing(){
    cout<<"enter the number you want to bet:";
    cin>>number;
    int result=numberExists();
    if(number.length()==3) {
        while(result==-1){
            cout << "Bet accepted"<<endl<<"Enter name:";
            cin>>cName;
            nameCollect[infoIndex]=cName;
            cout<<"Enter phone number:";
            cin>>cPh;
            phNoCollect[infoIndex]=cPh;
            noCollect[infoIndex]=number;
            record();
            infoIndex++;
            mainMenu();
        }
        cout<<"This number is taken by another customer."<<endl;
        mainMenu();
    }else{
        cout<<"Invalid number!"<<endl;
        mainMenu();
    }
};

int lottery::numberExists(){
    for(int i=0;i<infoIndex;i++){
        if(noCollect[i]==number){
            return i;
        }
    }
    return -1;
}

void lottery::record(){
    ofstream record_file;
    record_file.open(file_name,ios::app);
    if(record_file.is_open()){
        record_file<<noCollect[infoIndex]<<" "<<nameCollect[infoIndex]<<" "<<phNoCollect[infoIndex]<<endl;
    }else{
        cout<<"File opening failed";
    }
    record_file.close();
}

void lottery::mainLoading(){
    string dataLine;
    string data;
    int count=0;
    ifstream dataFile;
    dataFile.open(file_name,ios::out|ios::in);
    if(dataFile.is_open()){
        while(getline(dataFile,dataLine)){
            dataLine=dataLine+" ";
            for(auto &ch:dataLine){
                if(ch!=' ' && count==0){
                    data+=ch;
                    noCollect[infoIndex]=data;
                }else if(ch==' ' && count==0){
                    count++;
                    data="";
                }else if(ch!=' ' && count==1){
                    data+=ch;
                    nameCollect[infoIndex]=data;
                }else if(ch==' ' && count==1){
                    count++;
                    data="";
                }else if(ch!=' ' && count==2){
                    data+=ch;
                    phNoCollect[infoIndex]=data;
                }else if(ch==' ' && count==2){
                    count=0;
                    data="";
                    infoIndex++;
                }
            }
        }
    }else{
        cout<<"Cannot open file";
    }
}

void lottery::showData(){
    for(int i=0;i<infoIndex;i++){
        cout<<noCollect[i]<<endl;
    }
}

