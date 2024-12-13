
/*Write a program in C++ to use map associative container. The keys will be the 
names of states and the values will be the populations of the states. When the 
program runs, the user is prompted to type the name of a state. The program
then looks in the map, using the state name as an index and returns the
population of the state.*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Declare a map where keys are state names (string) and values are population (int)
    map<string, int> statePopulations;

    // Initialize the map with some sample state data
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 29145505;
    statePopulations["Florida"] = 21538187;
    statePopulations["New York"] = 20201249;
    statePopulations["Pennsylvania"] = 13002700;
    statePopulations["Illinois"] = 12812508;

    // Prompt the user to enter the name of a state
    string state;
    cout << "Enter the name of a state to get its population: ";
    getline(cin, state);  // Read the full state name (in case it has spaces)

    // Search for the state in the map
    auto it = statePopulations.find(state);  // Find the state in the map

    // If the state is found, display its population
    if (it != statePopulations.end()) {
        cout << "The population of " << state << " is " << it->second << "." << endl;
    } else {
        // If the state is not found, display an error message
        cout << "State not found in the map." << endl;
    }

    return 0;
}