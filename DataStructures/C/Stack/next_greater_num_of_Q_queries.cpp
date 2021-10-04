#include <iostream>
#include <stack>

#define SIZE    8

using namespace std;

void find_next_greatest(int a[], int next_gtr[], int n) {
    stack<int> s;
    s.push(0);

    for (int i=1; i<n; i++) {

        while (!s.empty()) {
            int cur_index = s.top();

            if (a[cur_index] < a[i]) {
                next_gtr[cur_index] = i;
                s.pop();    // as the next greater element has been found so pop the cur_index from the stack
            } else {
                break;
            }
        }

        s.push(i);
    }

    while (!s.empty()) {
        int cur = s.top();
        next_gtr[cur] = -1;
        s.pop();
    }
}

int find_query (int a[], int next_gtr[], int n, int index) {
    int index_of_next_gtr = next_gtr[index];

    if (index_of_next_gtr == -1) {
        return -1;
    } else {
        return a[index_of_next_gtr];
    }
}

int main () {
    int n=SIZE;  
    //cin >> n; 

    int a[SIZE];
    for (int i=0; i<n; i++)
        std::cin >> a[i];

    int next_gtr[SIZE] = {0};

    find_next_greatest(a, next_gtr, n);

    int q;
    std::cout << "Enter the number of queries: " << endl;
    std::cin >> q;

    int j=0, ind; 
    while (j != q) {
        cout << "enter the index number: " << endl;
        std::cin >>ind;
        std::cout << find_query(a, next_gtr, n, ind) << " " << endl;
        j--;
    }
}