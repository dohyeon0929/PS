#define ll long long
#include <bits/stdc++.h>
using namespace std;

class Sorting{
private:
    int mode;
public:
    void setMode(int _mode);
    void display();
    void sorting();
}
void setMode(int _mode){
    if(1<=_mode && _mode<=4){
        mode = _mode;
    }
    else{
        "ERROR!!!";
    }
    return;
}
int Sorting::display(){
    cout<<"- Sorting Option\n
    1. Sort by Name\n
    2. Sort by Student ID\n
    3. Sort by Admission Year\n
    4. Sort by Department name\n
    > ";
    int _mode;
    cin>>_mode;
    return _mode;
}
bool compare(vector<string> a, vector<string> b, int _mode){
    return a[_mode-1]<b[_mode-1];
}
void Sorting::sorting(){
    fstream file;
    file.open("file1.txt", in);
    vector<vector<string>> v;
    int cnt=0;
    while(!file.eof()){ //파일 내용 읽기 
        char line[100];
        for(int i=0; i<5; i++){
            file>>line;
            string s(line);
            v[cnt].push_back(s);
        }
        cnt++;
    }
    file.close();

    sort(v.begin(), v.end(), compare(mode)); //정렬 

    file.open("file1.txt", out | trunc); //파일 다 지우고 정렬해서 채워넣기 
    for(int i=0; i<cnt; i++){
        for(int j=0; j<5; j++){
            file<<v[i][j]+" ";
        }
        file<<"\n";
    }
    file.close();
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Sorting s;
    s.setMode(s.display());
    s.sorting();
    
    return 0;
}