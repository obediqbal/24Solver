#include "generator.h"

void swap (int *arr, int a, int b){
    int temp;

    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void copy (int *dest, int src[], int size){
    int i;
    for(i = 0; i<size; i++){
        dest[i] = src[i];
    }
}

std::vector<int*> perm;

bool is_unique (int *arr){
    if(perm.empty()) return true;

    bool found;
    int size = perm.size();
    for(int i = 0; i<size; i++){
        found = true;
        for(int j = 0; j<4; j++){
            if(arr[j] != perm.at(i)[j]) found = false;
        }
        if(found) return false;
    }
    return true;
}

void generate_permutations(int *arr, int l, int r){
    int i;
    int temp;

    if (l==r){
        if(is_unique(arr)){
            int *result = (int*)malloc(sizeof(arr)*4);
            copy(result, arr, 4);
            perm.push_back(result);
        }
    }else {
        for(i=l; i<=r; i++){
            swap(arr, l, i);
            generate_permutations(arr, l+1, r);
            swap(arr, l, i);
        }
    }
}

std::vector<int*> get_permutations(int *arr){
    generate_permutations(arr, 0, 3);
    return perm;
}

// int main(){
//     int arr[] = {1,2,3,4};
//     generate_permutations(arr, 0, 3);
//     int *top;

//     std::stack<int*> temp = get_permutations();

//     while(!temp.empty()){
//         top = temp.top();
//         printf("%d %d %d %d\n", top[0], top[1], top[2], top[3]);
//         temp.pop();
//     }

// }