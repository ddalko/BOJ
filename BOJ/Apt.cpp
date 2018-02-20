#include <bits/stdc++.h>

using namespace std;

int main()
{
    //TERMINAL_ID, SRU_ID, ST_TIME_WINDOW, END_TIME_WINDOW, MAX_SLOT, CURRENT_SLOT
    freopen("plant_workload.txt","r",stdin);
    freopen("apt_slot_no_for_rec.csv","w",stdout);

    const int MAX_SLOT = 3; const int TwoHours = 120;
    const int AVG_OPTIME = 490 / 60;
    const char comma = ','; const char newline = '\n'; const char quote = '"';
    string TERMINAL_ID, SRU_ID, ST_TIME_WINDOW1, ST_TIME_WINDOW2, END_TIME_WINDOW1, END_TIME_WINDOW2, WL_LVL;
    int SHIP_OP_NO, GATE_OP_NO, REMAR_OP_NO;

    while(cin >> TERMINAL_ID
            >> SRU_ID
            >> ST_TIME_WINDOW1
            >> ST_TIME_WINDOW2
            >> END_TIME_WINDOW1
            >> END_TIME_WINDOW2
            >> WL_LVL
            >> SHIP_OP_NO
            >> GATE_OP_NO
            >> REMAR_OP_NO){

            int availslot = (int)((TwoHours - ((SHIP_OP_NO * 4) / 3)) / AVG_OPTIME);
            cout << TERMINAL_ID << comma << SRU_ID << comma;
            cout << ST_TIME_WINDOW1 << ' ' << ST_TIME_WINDOW2 << comma;
            cout << END_TIME_WINDOW1 << ' ' << END_TIME_WINDOW2 << comma;
            cout << availslot << comma << availslot << newline;

    }
    return 0;
}
