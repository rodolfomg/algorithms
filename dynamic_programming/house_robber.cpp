/*
  suma_maxima = 0
  Para cada casa:
    Para cada casa a partir de la casa actual + 2 (no podemos robar casas adyacentes):
      Si suma_casa_actual + botin de la siguiente casa es mayor a la suma de la siguiente casa
        suma de la siguiente casa = suma_casa_actual + botin de la casa siguiente
      Si suma de la siguiente casa es mayo a la suma_maxima  
        suma_maxima = suma_casa_siguiente
*/

int houseRobber(std::vector<int> houses) {
  if (houses.empty()) return 0;
  
  int max_sum = 0, sums[houses.size()] = {0};

  if (1 == houses.size()) return houses[0];
  if (2 == houses.size()) return max(houses[0], houses[1]);
  
  sums[0] = houses[0];
  sums[1] = houses[1];
  max_sum = max(houses[0], houses[1]);

  for (size_t i = 0; i < houses.size() - 2; ++i) {
    for (size_t j = i + 2; j < houses.size(); ++j) {
      sums[j] = max(sums[i] + houses[j], sums[j]);
      max_sum = max(sums[j], max_sum);
    }
  }

  return max_sum;
}