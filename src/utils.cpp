#include "utils.h"

bool is_valid(char* str){
    int len = strlen(str);
    if(len!=8) return false;

    int i;
    for(i = 1; i<7 ; i+=2){
        if(str[i]!=' ') return false;
    }
    char key[] = "A23456789JQK";
    char * pch;
    for(i = 0; i<8; i+=2){
        pch = strchr(key, str[i]);
        if(pch==NULL) return false;
    }

    return true;
}

void parse(char* str, int* res){
    int i;
    int j = 0;
    char key[] = "A23456789JQK";
    char * pch;
    for(i = 0; i<8; i+=2){
        pch = strchr(key, str[i]);
        res[j] = pch - key + 1;
        j++;
    }
}

std::string generate_random(){
    char key[] = "A23456789JQK";
    std::string res;

    int random;
    int i;
    srand(time(NULL));
    for(i = 0; i<4; i++){
        random = rand() % 12;
        res.push_back(key[random]);
        res.push_back(' ');
    }
    res.pop_back();

    return res;
}

std::string ftext = "";

void print_expr(int arr[4], std::string prefix, std::string op1, std::string op2, std::string op3, std::string suffix){
    std::string query("\n"+prefix+std::to_string(arr[0])+op1+std::to_string(arr[1])+op2+std::to_string(arr[2])+op3+std::to_string(arr[3])+suffix);
    std::cout<<query;
    ftext.append(query);
}

void append_to_ftext(std::string str){
    ftext.append(str);
}

void save_to_text(std::string filename){
    std::ofstream file(filename.c_str(), std::ofstream::out);
    
    file<<ftext;

    file.close();
}