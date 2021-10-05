#include <iostream>
#include <stack>

#define SIZE    8

using namespace std;

/*

// approach-1 start from the beginning
void find_next_greatest(int *a, int *next_gtr, int n) {
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

*/

// approach-2   start from the end
void find_next_greatest(int *a, int *next_gtr, int n) {
    stack<int> s;
    
    next_gtr[n-1] = -1;
    
    s.push(n-1);

    for (int i=n-2; i>=0; i--) {
        
        
        if (a[i+1] > a[i]) {
            next_gtr[i] = i+1;
            s.push(i+1);
            
        } else {
            
            while (!s.empty()) {
                if (a[s.top()] > a[i]) {
                    next_gtr[i] = s.top();
                    break;
                } 
                s.pop();
            }
            
            if (s.empty())
                next_gtr[i] = -1;
            
        } 
    }

}


int find_query (int *a, int *next_gtr, int n, int index) {
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
        cin >> a[i];

    int next_gtr[SIZE] = {0};

    find_next_greatest(a, next_gtr, n);

    int q;
    cout << "Enter the number of queries: " << endl;
    cin >> q;

    int j=0, ind; 
    while (j != q) {
        cout << "enter the index number: " << endl;
        cin >>ind;
        cout << find_query(a, next_gtr, n, ind) << " " << endl;
        j++;
    }
}