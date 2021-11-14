#include <bits/stdc++.h>
using namespace std;

int n;
class Point{
    public:
    int x, y;
    Point():x(0), y(0){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    Point(Point &obj){
        x = obj.x;
        y = obj.y;
    }
    bool isSafe(){
        if(x >= 0 && x < n && y >= 0 && y < n) return true;
        else return false;
    }
    Point operator +(Point &obj){
        Point temp;
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        return temp;
    }

};

Point top(-1, 0), down(1, 0), l(0, -1), r(0, 1); 
bool solve(vector<vector<char>> &plane, Point s, Point e, Point direction){
    // cout << "This is direction:  " << direction.x << " " << direction.y << endl << endl;
    if(s.x == e.x && s.y == e.y) return true;
    while(s.isSafe()){
        if(s.x == e.x && s.y == e.y) return true;
        // cout << s.x << " " << s.y << endl;
        if(plane[s.x][s.y] == '.') s = s + direction;
        else if(plane[s.x][s.y] == '/'){
            Point temp = direction;
            direction.x = -1*temp.y;
            direction.y = -1*temp.x;
            s = s + direction;
        }else if(plane[s.x][s.y] == '\\'){
            Point temp = direction;
            direction.x = temp.y;
            direction.y = temp.x;
            s = s + direction;
        }
    }
    return false;
}

int main(){
    Point s, e;
    cin >> n;
    cin >> s.x >> s.y;
    cin >> e.x >> e.y;
    vector<vector<char>> plane(n, vector<char>(n, ' '));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> plane[i][j];
        }
    }
    if(solve(plane, s, e, top) || solve(plane, s, e, down) || solve(plane, s, e, l) || solve(plane, s, e, r)) cout << "yes" << endl;
    else cout << "no" << endl;
}
