#include <iostream>
#include <string>
#include "solver.h"

int main(){
    char str[101];
    int input[4];
    int count;
    char mode[101];
    char save[101];

    printf("Pilih mode (m/r): ");
    fgets(mode, 100, stdin);
    if(mode[0]=='m' && strlen(mode)==2){
        printf("Masukkan 4 buah kartu: ");
        fgets(str, 100, stdin); // a op b op c op d
        append_to_ftext(str);
        append_to_ftext("\n");
    }
    else if(mode[0]=='r' && strlen(mode)==2){
        strcpy(str, generate_random().c_str());
        strcat(str, " ");
        printf("4 Kartumu: %s", str);
        append_to_ftext(str);
        append_to_ftext("\n");
    }
    else{
        printf("Masukan tidak valid!");
        return 0;
    }

    printf("\n");

    if(is_valid(str)){
        parse(str, input);
        
        double start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
        solve_trivial(input);
        solve(input);
        double end = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

        std::cout<<"Execution duration: "<<(end-start)/1000<<" ms"<<std::endl;
        
    }
    else{
        printf("Kartu tidak valid");
    }

    printf("Apakah kamu mau menyimpannya ke dalam file? (y)");
    fgets(save, 100, stdin);


    if(save[0]=='y' && strlen(save)==2){
        std::string filename;
        std::cout<<"Simpan sebagai: ";
        std::cin>>filename;
        filename.append(".txt");
        save_to_text(filename);
        printf("\nFile berhasil disimpan");
    }
    

}