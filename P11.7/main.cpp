#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class htwt{
    private:
        int height;
        int weight;
    public:
        htwt(int h, int w){height=h; weight=w;};
        int getHeight(){return height;};
        int getWeight(){return weight;};
        bool isAbove(htwt previous);
};

bool htwt::isAbove(htwt previous){
    if(previous.getHeight() > height && previous.getWeight()>weight) return true;
    else return false;
}

bool compare(htwt a, htwt b){
    if(a.getHeight() != b.getHeight()) return a.getHeight() < b.getHeight();
    else return a.getWeight() < b.getWeight();
}

unsigned int fillNextSequ(vector<htwt> &items, unsigned int start, vector<htwt> &seq){
    unsigned int firstUnfitItem= start;
    if(start< items.size()){
        for (unsigned int i = start; i < items.size(); i++) {
			if (i == start || items[i].isAbove(seq.back())) {
				seq.push_back(items[i]);
			} else {
				firstUnfitItem = i;
			}
		}
    }
    return firstUnfitItem;
}

vector<htwt> findMaxSeq(vector<htwt> items){
    sort(items.begin(), items.end(), compare);
    vector<htwt> maxSeq;
    unsigned int currentUnfit = 0, nextUnfit = 0;
    while (currentUnfit < items.size()) {
		vector<htwt> nextSeq;
		nextUnfit = fillNextSequ(items, currentUnfit, nextSeq);
		if (maxSeq.size() < nextSeq.size())
			maxSeq = nextSeq;
		if (nextUnfit == currentUnfit)
			break;
		else
			currentUnfit = nextUnfit;
	}
	return maxSeq;
}

int main()
{
    vector<htwt> items;
	items.push_back(htwt(65, 100));
	items.push_back(htwt(70, 150));
	items.push_back(htwt(56, 90));
	items.push_back(htwt(75, 190));
	items.push_back(htwt(60, 95));
	items.push_back(htwt(68, 110));

	cout << "Input (ht,wt): ";
	vector<htwt>::iterator it = items.begin();
	while (it != items.end()) {
		cout << "(" << it->getHeight() << ", " << it->getWeight() << ") ";
		it++;
	}
	cout << endl << "Output: ";

	vector<htwt> maxSeq = findMaxSeq(items);
	it = maxSeq.begin();
	while (it != maxSeq.end()) {
		cout << "(" << it->getHeight() << ", " << it->getWeight() << ") ";
		it++;
	}
	cout << endl;
    return 0;
}
