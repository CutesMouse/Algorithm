#include <iostream>
#include <string>
using namespace std;

int main() {
    pair<int,int> pos_move[] = {{1,2},{-1,2},{1,-2},{-1,-2},
                            {2,1},{-2,1},{2,-1},{-2,-1}};
    struct pos {
        int move;
        string condi;
        pos(int move, string condi) : condi(condi), move(move) {

        }
        pos() {

        }
        bool isValid() {
            return condi.at(0) >= 'a' && condi.at(0) <= 'h' && condi.at(1) >= '1' && condi.at(1) <= '8';
        }
        pos moveClone(int dx, int dy) {
            string ns;
            ns.push_back((char) (condi.at(0) + dx));
            ns.push_back((char) (condi.at(1) + dy));
            return pos(move+1, ns);
        }
        bool operator==(pos &p2) const {
            return p2.condi == condi;
        }
    };

    string p1,p2;
    pos moves[10000];
    int ptr;
    start:
    while (cin >> p1 >> p2) {
        ptr = 0;
        pos start = pos(0,p1);
        moves[0] = start;
        pos end = pos(0,p2);
        if (start == end) {
            printf("To get from %s to %s takes %d knight moves.\n",start.condi.c_str(),end.condi.c_str(),0);
            goto start;
        }
        for (int i = 0; i < ptr+1; i++) {
            pos c = moves[i];
            for (int j = 0; j < 8; j++) {
                auto pair = pos_move[j];
                auto moved = c.moveClone(pair.first,pair.second);
                if (!moved.isValid()) continue;
                if (moved == end) {
                    printf("To get from %s to %s takes %d knight moves.\n",start.condi.c_str(),end.condi.c_str(),moved.move);
                    goto start;
                }
//                cout << "move from " << c.condi << " to " << moved.condi << " at " << moved.move << endl;
                moves[++ptr] = moved;
            }
        }
    }
}
