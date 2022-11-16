//
// Created by BMT on 11/9/2022.
//
#include "iostream"
using namespace std;
#ifndef PROJECTS_LOTTERY_H
#define PROJECTS_LOTTERY_H
namespace A{
    class lottery{
    public:
        //attributes
        string number;
        string option;
        string cName;
        string cPh;
        int infoIndex=0;
        string noCollect[1000];
        string nameCollect[1000];
        string phNoCollect[1000];
        string file_name="lotteryRecords.txt";
        //methods
        void welcome();
        void mainMenu();
        void numberChoosing();
        void showData();
        int numberExists();
        void record();
        void mainLoading();
    };
};

#endif //PROJECTS_LOTTERY_H
