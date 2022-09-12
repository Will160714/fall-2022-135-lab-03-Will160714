// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
  std::cout << "Task A" << std::endl;
  get_east_storage("01/01/2018"); //59.94
  std::cout << std::endl;
  get_east_storage("05/20/2018");
  std::cout << std::endl;
  get_east_storage("09/24/2018"); //67.68

  std::cout << std::endl;
  
  std::cout << "Task B" << std::endl;
  std::cout << "Minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "Maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
  std::cout << std::endl;

  std::cout << "Task C" << std::endl;
  std::cout << "Compare Basins on (01/05/2018): " << compare_basins("01/05/2018") << std::endl;
  std::cout << "Compare Basins on (09/13/2018): " << compare_basins("09/13/2018") << std::endl;
  std::cout << "Compare Basins on (03/31/2018): " << compare_basins("03/31/2018") << std::endl;
  std::cout << "Compare Basins on (09/13/2018): " << compare_basins("09/13/2018") << std::endl;
  std::cout << std::endl;

  std::cout << "Task D" << std::endl;
  std::cout << "Enter earlier date: 05/29/2018" << std::endl;
  std::cout << "Enter later date: 06/02/2018" << std::endl;
  std::cout << std:: endl;
  reverse_oreder("05/29/2018", "06/02/2018");

  return 0;
}