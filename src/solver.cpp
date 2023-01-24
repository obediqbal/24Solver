#include "solver.h"

int count = 0;

void solve_trivial(int arr[4]){
    int i;
    int sum = 0;

    // Trivial a + b + c + d
    for(i=0; i<4; i++){
        sum += arr[i];
    }
    if(sum==24){
        print_expr(arr, "", "+", "+", "+", "");
        count++;
    }
    sum = 0;

    // Trivial a * b * c * d
    for(i=0; i<4; i++){
        sum *= arr[i];
    }
    if(sum==24){
        print_expr(arr, "", "*", "*", "*", "");
        count++;
    }
}

void solve(int arr[4]){
    std::vector<int*> perms = get_permutations(arr);

    int *perm;
    do{
        perm = perms.back();
        // 2+; 1-
        if(perm[0] + perm[1] + perm[2] - perm[3] == 24) {print_expr(perm, "", "+", "+", "-", "");count++;}
        // 2+; 1*
        if(perm[0] * perm[1] + perm[2] + perm[3] == 24) {print_expr(perm, "", "*", "+", "+", "");count++;}
        if(perm[0] * (perm[1] + perm[2]) + perm[3] == 24) {print_expr(perm, "", "*(", "+", ")+", "");count++;}
        if(perm[0] * (perm[1] + perm[2] + perm[3]) == 24) {print_expr(perm, "", "*(", "+", "+", ")");count++;}
        // 1+; 2*
        if(perm[0] * perm[1] * perm[2] + perm[3] == 24) {print_expr(perm, "(", "*", "*", ")+", "");count++;}
        if(perm[0] * perm[1] * (perm[2] + perm[3]) == 24) {print_expr(perm, "(", "*", "*(", "+", "))");count++;}
        if(perm[0] * perm[1] + perm[2] * perm[3] == 24) {print_expr(perm, "(", "*", ")+(", "*", ")");count++;}
        // 1-; 2*
        if(perm[0] * perm[1] * perm[2] - perm[3] == 24) {print_expr(perm, "(", "*", "*", ")-", "");count++;}
        if(perm[0] * perm[1] * (perm[2] - perm[3]) == 24) {print_expr(perm, "(", "*", "*(", "-", "))");count++;}
        if(perm[0] * perm[1] - perm[2] * perm[3] == 24) {print_expr(perm, "(", "*", ")-(", "*", ")");count++;}
        // 1+; 1-; 1*
        if(perm[0] * perm[1] + perm[2] - perm[3] == 24) {print_expr(perm, "", "*", "+", "-", "");count++;}
        if(perm[0] * (perm[1] + perm[2]) - perm[3] == 24) {print_expr(perm, "", "*(", "+", ")-", "");count++;}
        if(perm[0] * (perm[1] - perm[2]) + perm[3] == 24) {print_expr(perm, "", "*(", "-", ")+", "");count++;}
        if(perm[0] * (perm[1] + perm[2] - perm[3]) == 24) {print_expr(perm, "", "*(", "+", "-", ")");count++;}
        if(perm[0] * perm[1] - (perm[2] + perm[3]) == 24) {print_expr(perm, "", "*", "-(", "+", ")");count++;}
        // 1+; 1*; 1/
        if(perm[0] * perm[1] == (perm[2]-24) * perm[3]) {print_expr(perm, "(", "*", "/", ")+", "");count++;}
        if(((perm[0] * perm[1]) + perm[2]) == 24 * perm[3]) {print_expr(perm, "((", "*", ")+", ")/", "");count++;}
        if((perm[0] + perm[1]) * perm[2] == 24 * perm[3]) {print_expr(perm, "((", "+", ")*", ")/", "");count++;}
        if(perm[0] * perm[1] == 24 * (perm[2] + perm[3])) {print_expr(perm, "(", "*", ")/(", "+", ")");count++;}
        // 1-; 1*; 1/
        if(perm[0] * perm[1] == (perm[2]+24) * perm[3]) {print_expr(perm, "(", "*", "/", ")-", "");count++;}
        if(((perm[0] * perm[1]) - perm[2]) == 24 * perm[3]) {print_expr(perm, "((", "*", ")-", ")/", "");count++;}
        if((perm[0] - perm[1]) * perm[2] == 24 * perm[3]) {print_expr(perm, "((", "-", ")*", ")/", "");count++;}
        if(perm[0] * perm[1] == 24 * (perm[2] - perm[3])) {print_expr(perm, "(", "*", ")/(", "-", ")");count++;}
        // 2*; 1/
        if(perm[0] * perm[1] * perm[2] == 24 * perm[3]) {print_expr(perm, "", "*", "*", "/", "");count++;}
        if(perm[0] * perm[1] == 24 * perm[2] * perm[3]) {print_expr(perm, "", "*", "/(", "*", ")");count++;}
        // 1-; 2/
        if(perm[0] * perm[3] == 24 * (perm[1] * perm[3] - perm[2])) {print_expr(perm, "", "/(", "-", "/", ")");count++;}
        // 1*; 2/
        if(perm[0] * perm[1] == 24 * perm[2] * perm[3]) {print_expr(perm, "(", "*", "/", ")/", "");count++;}

        perms.pop_back();
    }
    while(!perms.empty());

    std::string prompt;

    if(count==0) prompt = "Tidak ada solusi\n";
    else prompt = "\n" + std::to_string(count) + " solusi ditemukan";

    std::cout<<prompt<<std::endl;

    append_to_ftext(prompt);
}

int get_count(){
    return count;
}