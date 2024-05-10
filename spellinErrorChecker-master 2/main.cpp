#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "TimeInterval.h"
#include "Hash.h"

int main(){
    //open the dictionary 
    std::ifstream inPut;
    inPut.open("Dictionary.txt");

    Hash h;
    TimeInterval t;
    std::string recieve;
    std::vector<std::string>vect;

    // getting the word from dictionart.txt
    if(inPut.is_open()){
        while(std::getline(inPut, recieve)){
            vect.push_back(recieve);
        }
    }else{
        std::cout<<"file cannot be opened"<<std::endl;
    }
        inPut.close();
        //delete[]w;

        //transforming all of the words to lower case
        for(auto &i: vect){
            std::transform(i.begin(), i.end(), i.begin(), ::tolower);
        }

        //inserting all th words
        for(int i = 0; i<vect.size(); i++){
            h.insert(vect[i]);
        }

       /* t.start();
        h.wordChecking(f);
        //h.wordSuggest(f);
        t.stop();
        std::cout<<std::endl;
        std::cout<<t.GetInterval()<<" micro-sec\n";*/

        std::string input, word;

        //user interface
        do
        {
            //std::string input;
            std::cout<<"1) Run program\n";
            std::cout<<"2) exit\n";
            std::cin>>input;

            if(input == "1"){
                std::cout<<"enter a word: ";
                std::cin>>word;
                t.start();
                h.wordChecking(word);
                t.stop();
                std::cout<<std::endl;
                std::cout<<t.GetInterval()<<" micro-sec\n";

            }else if (input == "2"){
                std::cout<<"thank you for running my program\n";
            }else{
                std::cout<<"i dont understand what you trying to do\n";
            }
        } while (input != "2");
        
}


