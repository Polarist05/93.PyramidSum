#include<stdio.h>
#include<vector>
#include<iostream>
#include<utility>
#include<limits.h>
using namespace std;
int Position(int _a, int _b) {
    return((_a) * (_a + 1)) / 2 + _b;
}
class Number {
public:
    int value;
    int head;
    Number(int _value, int _head) {
        head = _head;
        value = _value;
    }
};
vector<Number> v;
int Print(int _a) {
    if (_a != 0) {
        printf(" + %d", v[_a].value - Print(v[_a].head));
    }
    else {
        printf("%d", v[_a].value);
    }
    return v[_a].value;
}
int main() {
    int a;
    scanf_s("%d", &a);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= i; j++) {
            int c;
            scanf_s("%d", &c);
            if (v.size() != 0) {
                int pos1 = Position(i - 1, j - 1), pos2 = Position(i - 1, j);
                if (j == 0) {
                    v.push_back(Number(c + v[pos2].value, pos2));
                }
                else if (j == i) {
                    v.push_back(Number(c + v[pos1].value, pos1));
                }
                else {
                    if (v[pos1].value < v[pos2].value) {
                        v.push_back(Number(c + v[pos2].value, pos2));
                    }
                    else {
                        v.push_back(Number(c + v[pos1].value, pos1));
                    }
                }
            }
            else {
                v.push_back(Number(c, 0));
            }
        }
    }
    int pos;
    int mx = INT_MIN;
    for (int i = Position(a - 1, 0), k = Position(a - 1, a - 1); i <= k; i++) {
        if (v[i].value > mx) {
            mx = v[i].value;
            pos = i;
        }
    }
    Print(pos);
    printf(" = %d", mx);
}
