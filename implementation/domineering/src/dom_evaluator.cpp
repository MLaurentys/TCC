/*
 * This file contains the implementation of the DomEvaluator class.
 */

#include "../include/dom_evaluator.hpp"

unordered_map<rectangle, game> DomEvaluator::hmap {};

std::vector<game> DomEvaluator::evaluate(const Domineering& G){
    int_mat mat;
    vector<semi_board> sbs;
    std::tie(mat, sbs) = break_configuration(G);
    std::vector<game> ret;
    for (auto& sb : sbs) {
        int a = 0;
        ret.push_back(evaluate_game_fixed(mat,sb));
        int b = 1;
    }
    return ret;
}

tuple<vector<move>, vector<move>>
DomEvaluator::get_moves(const int_mat& mat, const semi_board& sb) {
    vector<move> left,right;
    //left moves verticaLLy
    for (int i = std::max(1,sb.bottom); i < sb.height; ++i)
        for (int j = sb.left; j < sb.width + sb.left; ++j)
            if (mat[i][j] == sb.gID && mat[i-1][j] == sb.gID)
                left.push_back({{i-1,j}, {i,j}});
    //right moves hoRizontally
    for (int i = sb.bottom; i < sb.bottom + sb.height; ++i)
        for (int j = std::max(1, sb.left); j < sb.left + sb.width; ++j)
            if (mat[i][j] == sb.gID && mat[i][j-1] == sb.gID)
                right.push_back({{i,j-1}, {i,j}});
    return std::make_tuple(std::move(left), std::move(right));
}

tuple<int_mat, vector<semi_board>>
DomEvaluator::break_configuration(const Domineering& G) {
    auto rems = G.get_sorted_removes();
    int n = G.wid(), m = G.hei(), g_ind = 0, g_amt;
    int_mat mat;
    unordered_map<int, int> id_map {};
    std::tie(mat, g_amt) = union_find(n, m, rems);
    vector<semi_board> ret(g_amt, {INT32_MAX, INT32_MAX, 0, 0, -1});
    // During this loop, width and height will mean max x and max y 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int g = mat[i][j];
            if (g == -1) continue;
            if (id_map.find(g) == id_map.end())
                id_map[g] = g_ind++;
            ret[g].gID = id_map[g];
            if (j < ret[g].left)
                ret[g].left = j;
            if (j > ret[g].width)
                ret[g].width = j;
            if (i < ret[g].bottom)
                ret[g].bottom = i;
            if (i > ret[g].height)
                ret[g].height = i;
        }
    }
    for (auto& sb : ret) {
        sb.width -= sb.left - 1;
        sb.height -= sb.bottom - 1;
    }
    return std::make_tuple(std::move(mat), std::move(ret));
}

void toggle (int_mat& mat, move& m, int id) {
    int x1,y1,x2,y2;
    x1 = m.pos1.x; y1 = m.pos1.y; x2 = m.pos2.x; y2 = m.pos2.y;
    if (mat[x1][y1] == -1) {
        mat[x1][y1] = id;
        mat[x2][y2] = id;
    } else {
        mat[x1][y1] = -1;
        mat[x2][y2] = -1;
    }
}

game DomEvaluator::evaluate_game_fixed(int_mat& mat, semi_board& sb) {
    bool is_rec = is_rect(mat, sb);
    if (is_rec) {
        auto it = hmap.find(rectangle(sb)); 
        if (it != hmap.end()) {
            cout << "Used hash_map\n";
            return it->second;
        }
    }
    auto moves = get_moves(mat, sb);
    int id = sb.gID;
    game ret;
    for (move& m : get<0>(moves)) {
        toggle(mat, m, id);
        ret.left.push_back(evaluate_game_fixed(mat, sb));
        toggle(mat, m, id);
    }
    for (move& m : get<1>(moves)) {
        toggle(mat, m, id);
        ret.right.push_back(evaluate_game_fixed(mat, sb));
        toggle(mat, m, id);
    }
    if (is_rec) {
        cout << "Filled hash_map\n";
        hmap[rectangle(sb)] = ret;
    }
    return ret;
}

// I.e. < < 2 | 6 >, 4 | 6, 10, 19 >
// < < < | > | > | < | > >
std::string build_eval_string (game& G) {
    std::string s = "<";
    int sz_l = static_cast<int>(G.left.size());
    int sz_r = static_cast<int>(G.right.size());
    for (int i = 0; i < sz_l - 1; ++i)
        s += " " + build_eval_string(G.left[i]) + ",";
    if (sz_l) s += " " + build_eval_string(G.left[sz_l - 1]);
    s += " |";
    for (int i = 0; i < sz_r - 1; ++i)
        s += " " + build_eval_string(G.right[i]) + ",";
    if (sz_r) s += " " + build_eval_string(G.right[sz_r - 1]);
    s += " >";
    return s;
}

void DomEvaluator::print_evaluation(game G){
    cout << build_eval_string(G);
}

bool DomEvaluator::is_rect (const int_mat& mat, const semi_board& sb) {
    for (int i = sb.bottom; i < sb.bottom + sb.height; ++i)
        for (int j = sb.left; j < sb.left + sb.width; ++j)
            if (mat[i][j] != sb.gID) return false;
    return true;
}