//
//  main.cpp
//  Hash-Map-Test
//
//  Created by David Dang on 2/20/25.
//

#include <iostream>
#include <vector>
//#include <cpr>
#include "Hasher.h"
using namespace std;

const int kNumberOfStates = 50;

string UnitedStates[kNumberOfStates] {
    "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New_Hampshire", "New_Jersey", "New_Mexico", "New_York", "North_Carolina", "North_Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode_Island", "South_Carolina", "South_Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West_Virginia", "Wisconsin", "Wyoming"
};

string StateNicknames[kNumberOfStates] {
    "Yellowhammer", "Last_Frontier", "Grand_Canyon", "Natural", "Golden", "Centennial", "Constitution", "First", "Sunshine", "Peach", "Aloha", "Gem", "Prairie", "Hoosier", "Hawkeye", "Sunflower", "Bluegrass", "Pelican", "Pine_Tree", "Old_Line", "Bay", "Great_Lakes", "North_Star", "Magnolia", "Show_Me", "Treasure", "Cornhusker", "Silver", "Granite", "Garden", "Land_of_Enchantment", "Empire", "Tar_Heel", "Peace_Garden", "Buckeye", "Sooner", "Beaver", "Keystone", "Ocean", "Palmetto", "Mount_Rushmore", "Volunteer", "Lone_Star", "Beehive", "Green_Mountain", "Old_Dominion", "Evergreen", "Mountain", "Badger", "Equality"
};


int StatePopulations[kNumberOfStates]{
    4920000, 730000, 7420000, 3030000, 39030000, 5810000, 3560000, 1000000, 22240000, 10910000, 1410000, 1830000, 12580000, 6750000, 3160000, 2910000, 4480000, 4650000, 1350000, 6060000, 6890000, 10030000, 5660000, 2970000, 6150000, 1080000, 1940000, 3140000, 1370000, 9260000, 2110000, 19670000, 10690000, 770000, 11750000, 3980000, 4240000, 12970000, 1060000, 5220000, 900000, 6890000, 30030000, 3250000, 640000, 8680000, 7790000, 1780000, 5830000, 580000
};

//Try this: Templateizing Value to be generic.
//Try this: dynamic states array capacity
    //if any linkedList exceeds a certain length(like 6), call rehash,
    //rehash() create new array of double size, rehash and copy data over, and then delete old array
    //allMyKeys() returns an array of every key
    //allMyValues() returns an array of every value

//Modern version, instead of linked lists(separate-chaining), they use open-addressing to handle collisions

//Load Factor: number of total entries / size of array. Bigger load Factor = worse performance.
//There could be another metric which measures the average length of linkedLists


int main() {
    // Create the hashed array
    //LinkedList states[kSizeOfHashTable];
    Hasher<string> states;
    for(int i = 0; i < kNumberOfStates; i++){
        states.SetValue(UnitedStates[i], StateNicknames[i]);
    }
    
    Hasher<int> statePops;
    for(int i = 0; i < kNumberOfStates; i++){
        statePops.SetValue(UnitedStates[i], StatePopulations[i]);
    }
    
    //Take input Nickname, output Value, Nickname, and cycles taken to find it.
    string inputNick;
    cout << "Enter a State's name." << endl;
    cin >> inputNick;
    string foundState = states.getValue(inputNick);
    int statePopulation = statePops.getValue(inputNick);
    cout << "State's Nickname: " << foundState << endl;
    cout << "State's Population: " << statePopulation << endl;
    cout << endl;
    
    //Check Spread
    //states.checkSpread();
    cout << "\n";
    //statePops.checkSpread();
    string* keys = states.allMyKeys();
    for(int i = 0; i < 32; i++){
        cout << keys[i] << endl;
    }
    
    return 0;
}

//Try coding a hash map
//Use 50 states

//1. I now have ListNode(a class), LinkedList(a class), and UnitedStates(a enum)
//2. Make a hashmap of size 50.
//This should be an array of size 50.
// The keys shall be the nickname for each state. Yellowhammer is Alabama, Mountain is Virginia, Equality is Wyoming.

//Take nickname. Calculate a hash. Assign the state to that index. If any collision, just extend it.
//Options: Enum, Array, struct

