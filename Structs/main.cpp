#include <bits/stdc++.h>
using namespace std;


struct CSCMember {
    bool glassesUser;
    int age;
    string preferredLang;
} kevin, wackos[5];

int main() {
    kevin.glassesUser = false;
    kevin.age = 17;
    kevin.preferredLang = "English";
    wackos[1].age = 15;
    cout << kevin.glassesUser << endl;
    //not predetermined
    CSCMember lily;
    lily.glassesUser = false;
    lily.preferredLang = "English";
    return 0;
}
