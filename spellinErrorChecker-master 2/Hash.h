#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cctype>
#include <list>
#include <algorithm>
#ifndef Hash_hpp
#define Hash_hpp

class Hash{
    //atributes of the hash table
    public:
         int size;
         std::list<std::string> *map;        
        int hashFunction(std::string data){

            int i = tolower(int(data[0])) % size;
            return i;
        }//end of the hash function

    //methods
    public:

        //constructor with no parameters 
        Hash(){
            this->size = 26; //set number off the hash table to 10 
            map = new std::list<std::string> [this->size];
        }
        
        //constructors with parameter
        Hash(int size){
            this->size = size;
            map = new std::list<std::string> [this->size];
        }

        //deconstructor to free up space
        ~Hash(){
            delete [] map;
        }

       //method to insert numbers to the hashtable 
       void insert(std::string data){
           int i = hashFunction(data); //calling the hashfunction to insert numbers
           map[i].push_front(data);
       }

        //function to check if word exist
       void wordChecking(std::string word){
           int x = hashFunction(word);
           std::transform(word.begin(), word.end(), word.begin(), ::tolower);
           std::string similar;
           bool exist = false;

           for(auto it: map[x]){

               if (word.length() == 1){ // if lenght of the word is just 1
                   if(word == it){
                       exist = true;
                   }else if(tolower(word[0]) == tolower(it[0]) && tolower(word[1]) == tolower(it[1])){ // check if the first two indexes are the same if they are add them to similar
                       similar = similar + " -->" + it;
                   }
               }
                       
               else if(word.length()> 1){ // if length is greater than one
                   if (word == it){ //if word is found boolean becomes true
                       exist = true;
                   }else if(tolower(word[0]) == tolower(it[0]) && tolower(word[1]) == tolower(it[1])){
                       similar = similar + "-->"+ it;
                   }
               }
           }

           if(exist == false && similar == ""){ //if the boolian id false and the are no similar 
               //wordSuggest(word);
               std::cout<<"false\n";   
           }else if(exist == true){ // if word is found return all the suggestions
               std::cout<<"true\n"
                    <<similar<<std::endl;

           }else if(exist == false && similar != ""){ // if word is not found but there are similar call word suggestion function
               wordSuggest(word);
           }else{
               std::cout<<"true\n"
                    <<similar<<std::endl;
           }
       }

        //suggesting words if is mispelled 
       void wordSuggest(std::string word){
           int x = hashFunction(word);
           std::transform(word.begin(), word.end(), word.begin(), ::tolower); //converting word to lower case 
           std::string found = "";
           std::string similar, t;  
            for(auto it: map[x]){ // looping through the hash table row
                    if(it.length() == word.length()){
                        found = it;                   
                }            
            }
            // find suggestions
            if(found != ""){
                for(auto i: map[x]){
                    if(i[0] == found[0] && i[1] == found[1]){
                        similar = similar + "-->" +i;
                    }
                }
                    std::cout<<"Did you mean "<<found<<std::endl;
                    std::cout<<"y/n: ";
                    std::cin>>t; 
                    if(t == "y" | t == "Y"){
                        std::cout<<"true\n"
                            <<similar;                 
                    }else{
                        std::cout<<"fasle\n";
                    }
            }else{
                std::cout<<"false\n";
            }    
       }
        
        //printing the hash table
        void printShow(){
            for (int i = 1; i < size; i++) {
                std::cout<< i << ": ";
                for (auto it = map[i].begin(); it != map[i].end(); it++ ){
                    std::cout<< " --> " << *it;
                }
                std::cout<<std::endl;
            }
        }
       

};//end of class
#endif


