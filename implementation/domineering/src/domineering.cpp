#include "../include/domineering.hpp"

Domineering::Domineering(int height, int width) {
    n = width;
    m = height;
}

Domineering::Domineering(const Domineering& other) {
    n = other.n;
    m = other.m;
    moves = other.moves;
    removed = other.removed;
}

void Domineering::print_board() {
    vector<b_pos> rems = get_sorted_removes();
    cout << "[";
    int rem_ind = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(rems[rem_ind] == std::tie(i, j)){
                ++rem_ind;
                cout << "x";
            }
            else cout << "o";
            cout << " ";
        }
        cout << "]\n ";
    }
}

void Domineering::make_move(move mv) {
    moves.push_back(mv);
    removed.push_back(mv.pos1);
    removed.push_back(mv.pos2);
}

vector<b_pos> Domineering::get_sorted_removes() const {
    auto rems(removed);
    sort_removed(rems);
    rems.push_back({-1, -1});
    return rems;
}

void Domineering::sort_removed(vector<b_pos>& rems) const {
    auto comp = [&](const b_pos& p1, const b_pos& p2) {
        int a = n * (p1.y - p2.y) + (p1.x - p2.x);
        return a < 0;
    };
    std::sort(rems.begin(), rems.end(), comp);
}