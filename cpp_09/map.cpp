#include <iostream>
#include <map>

using namespace std;

int main(void) {
    map<string, int> ages;

    ages.insert({"2024-03-14", 20});
    ages.insert({"2023-12-01", 25});

    map<string, int>::iterator it = ages.lower_bound("2024-03-15");

    if (it == ages.end())
        cout << "not found, but here is lower: " << (ages.rbegin())->second << endl;
    else
        cout << "values: " << it->second << endl;
    return 0;
}