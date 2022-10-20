#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int num_size = numbers.size();
    set<int> s;
    for(int i=0; i<num_size; i++){
        for(int j=i+1; j<num_size; j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto i : s){
        answer.push_back(i);
    }
    return answer;
}