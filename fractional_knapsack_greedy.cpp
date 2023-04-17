#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
    int value;
    int weight;

    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool compare(Item a, Item b){ // comparator function(returns true when swap is not required)
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

//using greedy approach
double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, compare);
    int curWeight = 0;
    double finalValue = 0.0;
    for(int i=0; i<n; i++){
        if(curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main(){
    int W ;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item* arr;
    for(int i=0; i<n; i++){
        int value, weight;
        cout << "Enter the value and weight of item " << i+1 << ": ";
        cin >> value >> weight;
        arr[i] = Item(value, weight);
    }
    cout << endl;
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}