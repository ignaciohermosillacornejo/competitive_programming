/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5220
Tags: Tree, FenwickTree, Sweep Line
Status: TLE
*/

#include <bits/stdc++.h>

int P, V;

int max_value = 100000 + 1; //  10**6
int tree[100000 + 1];       // 10**6 + 1 (0 doesn't count)

int ft_sum(int index)
{
    int total = 0;
    while (index != 0)
    {
        total += tree[index];
        index -= (index & -index);
    }
    return total;
}

void ft_update(int index, int value)
{
    while (index <= max_value)
    {
        tree[index] += value;
        index += (index & -index);
    }
}

bool seg_comp(std::tuple<int, int, int> a, std::tuple<int, int, int> b)
{
    return std::get<0>(a) < std::get<0>(b);
}

bool plant_comp(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    while (std::cin >> P >> V)
    {

        std::vector<std::pair<int, int>> input_plants;
        std::vector<std::pair<int, int>> input_fence;
        std::vector<std::tuple<int, int, int>> segment;
        std::unordered_map<int, int> y_pos;
        std::set<int> y_s;

        memset(tree, 0, sizeof tree);

        // Input the plants
        int x, y;
        for (int i = 0; i < P; i++)
        {
            std::cin >> x >> y;
            input_plants.emplace_back(std::make_pair(x, y));
            y_s.insert(y);
        }

        // Input the fence
        for (int i = 0; i < V; i++)
        {
            std::cin >> x >> y;
            input_fence.emplace_back(std::make_pair(x, y));
            y_s.insert(y);
            std::cout << "i: " << i << "\n";
            std::cout << x << " " << y << "\n";
        }

        for (int i = 0; i < input_fence.size(); i++)
        {
            int j = (i + 1) % int(input_fence.size());
            // If it is a vertical segment, we emplace it on the segment vector
            if (input_fence[i].first == input_fence[j].first)
            {
                segment.emplace_back(input_fence[i].first, std::min(input_fence[i].second, input_fence[j].second),
                                     std::max(input_fence[i].second, input_fence[j].second));
            }
        }

        // We do the mapping for all the vertical positions
        int i = 1;
        for (auto y : y_s)
        {
            y_pos[y] = i++;
        }

        std::sort(segment.begin(), segment.end(), seg_comp);
        std::sort(input_plants.begin(), input_plants.end(), plant_comp);

        int counter = 0;
        i = 0;

        std::tuple<int, int, int> p_segment;

        for (auto s : segment)
        {

            if (s == segment.front())
            {
                p_segment = s;
                continue;
            }

            if (ft_sum(std::get<1>(p_segment)) == 1 and ft_sum(std::get<2>(p_segment)) == 1)
            {
                ft_update(std::get<1>(p_segment), -1);
                ft_update(std::get<2>(p_segment), 1);
            }
            else
            {
                ft_update(std::get<1>(p_segment), 1);
                ft_update(std::get<2>(p_segment), -1);
            }

            //std::cout << "iteration: " << i << " ";

            //plant_debug();

            if (i == P)
                break;

            std::pair<int, int> current_plant = input_plants[i];

            //std::cout << "x_fence: " << std::get<0>(s) << " x_plant: " << current_plant.first << "\n";

            while (current_plant.first < std::get<0>(s))
            {
                if (ft_sum(y_pos[current_plant.second]) == 1)
                    counter++;
                i++;
                if (i == P)
                    break;
                current_plant = input_plants[i];
            }

            p_segment = s;
        }

        std::cout << counter << "\n";
    }

    return 0;
}
