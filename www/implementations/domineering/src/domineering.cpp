#include "../include/domineering.h"

Domineering::Domineering(int width, int height){
    n = width;
    m = height;
}

void Domineering::print_board(){
    vector<b_pos> rems = get_sorted_removes();
    cout << "[";
    int rem_ind = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(std::tie(i, j) == rems[rem_ind]){
                ++rem_ind;
                cout << "x";
            }
            else cout << "o";
            cout << " ";
        }
        cout << "]\n ";
    }
}

void Domineering::make_move(move mv){
    moves.push_back(mv);
    b_pos p1, p2;
    std::tie(p1, p2) = mv;
    removed.push_back(p1);
    removed.push_back(p2);
}

vector<b_pos> Domineering::get_sorted_removes() const {
    auto rems(removed);
    sort_removed(rems);
    rems.push_back({-1, -1});
    return rems;
}

void Domineering::sort_removed(vector<b_pos>& rems) const {
    auto comp = [&](const b_pos& p1, const b_pos& p2) {
        int a = n * (get<1>(p1) - get<1>(p2)) + (get<0>(p1) - get<1>(p2));
        return a < 0;
    };
    std::sort(rems.begin(), rems.end(), comp);
}