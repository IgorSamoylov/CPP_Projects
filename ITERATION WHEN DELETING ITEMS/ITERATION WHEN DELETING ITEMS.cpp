

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void test_vector() {
    vector<int> my_vector {1,2,3,4,5};

    vector<int>::iterator vector_iterator = my_vector.begin();

    for (int i = 0; i < 100; ++i) {
        vector_iterator++;
        if (vector_iterator == my_vector.end()) vector_iterator = my_vector.begin();
        

        //cout << *vector_iterator << endl;

        my_vector.erase(vector_iterator);
    }
}

void test_unordered_map() {
    unordered_map<int, int> my_map {{1,10}, {2, 20}, {3,30}, {4,40}, {5,50}};
    cout << my_map.bucket(1) << " " << my_map.bucket_count() << " " << my_map.bucket_size(1) << endl;

    auto map_iterator = my_map.begin();

    for (int i = 0; i < 20; ++i) {
        
        if (map_iterator == my_map.end()) { 
            map_iterator = my_map.begin();
            if(map_iterator == my_map.end()) break;
        }
        else cout << map_iterator->first << " " << map_iterator->second << endl;

        if(i % 4 == 0) my_map.erase(map_iterator++);
        else ++map_iterator;
        
    }

}

int main()
{
    test_unordered_map();

   
}

