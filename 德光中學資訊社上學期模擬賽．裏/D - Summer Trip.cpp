/*
* description
Leo has started a job in a travel agency.
His first task is to organize a summer trip to an exotic overseas city.
During the summer season, events of various types take place in the city:
sports matches, concerts, beach parties, and many others.
At any given time, there is exactly one event taking place.
Events of any particular type may take place more than once during the season.
The itinerary of events that Leo offers to his clients cannot be chosen arbitrarily;
the company requires them to form a so-called “good itinerary.”
A good itinerary is a consecutive sequence of at least two events in the summer season,
where the first and last events are of different types,
and they are both unique among all event types during the sequence. 
For example, if the first event in a good itinerary is a beach party, 
none of the other events during the itinerary can also be a beach party.
There are no other restrictions on the event types in the sequence of a good itinerary.
Before he starts organizing the trip, 
Leo wants to know the total number of good itineraries that are possible given a calendar of events 
that will take place over the summer season.

* Input:
The input consists of one line with a string describing the sequence of event types 
in the summer season.
All characters are lowercase English letters (’a’ – ’z’), 
with different letters represent different types of events. 
Character i of the string encodes the ith event of the summer. 
There are no blanks or spaces in the string.
The length of the input string is at least 2 and at most 100000 characters.

* Output
Print the number of good itineraries that exist for the given summer season.

Sample Input 1	Sample Output 1
abbcccddddeeeee
10
Sample Input 2	Sample Output 2
thenumberofgoodstringsis
143

*/
#include <iostream> 
#include <cstring>

using namespace std;
string s;
int cs[26];
int index(char c) {
	return c - 'a';
}
bool isValid(int begin, int end) {
	if (begin == end) return false;
	return !cs[index(s.at(end))];
}
int dpd(int begin, int end) {
	if (begin >= end) return 0;
	if (end >= s.length()) return 0;
	int result = 0;
	char f = s.at(begin);
	memset(cs,0,sizeof(int)*26);
	for (int i = begin; i <= end; i++) {
		if (i != begin && s.at(i) == f) break;
		if (isValid(begin, i)) result += 1;
		cs[index(s.at(i))]++;
	}
	result += dpd(begin+1,end);
	return result;
}
int main() 
{
	cin >> s;
	cout << dpd(0,s.length()-1);
} 
