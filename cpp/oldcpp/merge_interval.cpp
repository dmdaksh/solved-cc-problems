#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool helper(Interval a, Interval b){
	return (min(a.end, b.end) >= max(a.start, b.start));
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
	int n = intervals.size();
	if(n == 0){
		res.push_back(newInterval);
		return res;
	}
	// Case 1 & 2
	if(intervals[0].start > newInterval.end || intervals[n-1].end < newInterval.start){
		if(intervals[0].start > newInterval.end)	res.push_back(newInterval);
		for(auto i:intervals){
			res.push_back(i);
		}
		if(intervals[n-1].end < newInterval.start)	res.push_back(newInterval);
		return res;
	}
	// Case 3
	if(intervals[0].start > newInterval.start && intervals[n-1].end < newInterval.end){
		res.push_back(newInterval);
		return res;
	}
	// Case 4 & 5
	for(int i = 0; i < intervals.size(); i++){
		if(!helper(intervals[i], newInterval)){
			res.push_back(intervals[i]);
			if(newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start){
				res.push_back(newInterval);
			}
			continue;
		}
		Interval temp;
		temp.start = min(newInterval.start, intervals[i].start);
		bool overlap = helper(newInterval, intervals[i]);
		while(i < n && overlap){
			temp.end = max(newInterval.end, intervals[i].end);
			if(i == n-1){
				overlap = false;
			}
			else{
				overlap = helper(newInterval, intervals[i+1]);
			}
			i++;
		}
		i--;
		res.push_back(temp);
	}
	return res;
}

int main(){
	vector<Interval> intervals{Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16)};
	Interval newInterval(4,9);
	vector<Interval> ans{insert(intervals, newInterval)};
	for(auto i:ans){
		cout << i.start << " " << i.end << endl;
	}
}