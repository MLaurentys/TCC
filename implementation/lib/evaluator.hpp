#ifndef _EVALUATOR_H
#define _EVALUATOR_H

#include <vector>
#include <tuple>
#include <functional>
#include <unordered_map>

using std::function;

typedef std::tuple<std::vector<float>, std::vector<float>> evaluation;

template<typename T>
using moves = std::tuple<std::vector<T>, std::vector<T>>;

template<typename TGame, typename TMove, typename ...args>
evaluation evaluate(
        const TGame& G,
        function<moves<TMove>(args...)> get_moves) {}

#endif