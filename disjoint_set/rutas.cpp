#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class City {
 public:
  City(int pop) {
    population_.push(pop)
  }

  int population () {
    return population_.top();
  }

  int oldPopulation () {
    population_.pop();
    return population_.top();
  }

  void newPopulation (int pop) {
    population_.push(pop);
  }

 private:
  stack<int> population_;
};

struct Route {
  int city_a, city_b;
};

struct Query {
  Query (int r) : route(r), city(0) {}
  Query (int c, int pop) : route(0), city(c) {}
  int route, city;
  // if(query.city) city updated
  // if(query.route) route updated
}

/**
 * N queries -> O(N)
 *     x
 * Update regions (Disjoint Set) -> O(1)    Worst case N regions
 *     x
 * Get most populated region (Swipe regions to compare) -> O(N)
 * 
 * calculateResults -> O(N^2)
**/
vector<int> calculateResults(const vector<Query>& queries) {}

int main () {
  size_t cities_count, routes_count, queries_count, population, city_a, city_b, route_id, city_id;
  char query_type;

  cin >> cities_count >> routes_count >> queries_count;

  vector<City> cities;
  vector<Route> routes;
  vector<Query> queries;

  for (int i = 1; i <= cities_count; ++i){
    cin >> population;
    cities.emplace_back(City(population));
  }

  for (int i = 0; i < routes_count; ++i) {
    cin >> city_a >> city_b;
    routes.emplace_back(Route(city_a, city_b));
  }

  for (int i = 0; i < queries_count; ++i) {
    cin >> query_type;
    if (query_type == 'D') {
      cin >> route_id;
      queries.emplace_back(Query(route_id));
    }
    else {
      cin >> city_id >> population;
      queries.emplace_back(Query(city_id));
      cities[city_id].newPopulation(population);
    }
  }

  calculateResults(queries);
}