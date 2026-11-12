#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// rand() % 101 gives 0-100 (using 100 would never produce 100).
vector<int> GenerateCredits() {
    vector<int> credits;
    for (int i = 0; i < 20; i++) {
        credits.push_back(rand() % 101);
    }
    return credits;
}

// Checks every element once and counts matches.
// If nothing matches, count stays 0, so no separate "not found" check is needed.
int FoundAmount(int target, vector<int> v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            count++;
        }
    }
    return count;
}

// bubble sort. The vector is passed by value, so the original stays unsorted.
// ascend decides the comparison direction. Bubble sort is easy to read but O(n^2);
// for large data std::sort would be better.
vector<int> SortCredits(bool ascend, vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            bool shouldSwap;
            if (ascend) {
                shouldSwap = v[j] > v[j + 1];
            } else {
                shouldSwap = v[j] < v[j + 1];
            }
            if (shouldSwap) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return v;
}

// Prints lowest, highest, average and median. Expects an ASCENDING sorted vector,
// so the lowest is the first element, the highest is the last, and the median is in the middle.
void PrintStats(vector<int> sorted) {
    if (sorted.empty()) {
        cout << "The vector is empty." << endl;
        return;
    }
    int n = sorted.size();

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sorted[i];
    }
    float average = static_cast<float>(sum) / n;   // float, otherwise the decimal part is lost

    float median;
    if (n % 2 == 1) {
        median = sorted[n / 2];                                 // odd: middle element
    } else {
        median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0f;    // even: mean of two middle elements
    }

    cout << "The lowest is " << sorted[0] << ", the highest is " << sorted[n - 1] << endl;
    cout << "The average is " << average << endl;
    cout << "The median is " << median << endl;
}

void PrintVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));   // seed once, so numbers differ on every run

    vector<int> data = GenerateCredits();
    cout << "Credits: ";
    PrintVector(data);

    cout << "Found " << data[0] << ": " << FoundAmount(data[0], data) << " time(s)" << endl;
    cout << "Found 101: " << FoundAmount(101, data) << " time(s)" << endl;

    vector<int> ascending = SortCredits(true, data);
    cout << "Ascending: ";
    PrintVector(ascending);

    vector<int> descending = SortCredits(false, data);
    cout << "Descending: ";
    PrintVector(descending);

    PrintStats(ascending);
    return 0;
}
