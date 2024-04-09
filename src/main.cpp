#include <Constants.h>
#include <DfsBfs.h>
#include <Misc.h>
#include <UniformCost.h>
#include <AStar.h>

int main()
{
  Constants constants;
  Misc misc;
  DfsBfs dfsbfs;
  UniformCost uniformcostsearch;
  AStar astar;
  map<char, std::vector<char>> mygraph;
  map<string, int> heuristic;
  vector<char> bfsPath, dfsPath;
  Graph romaniaMap;

  const std::vector<char> valid_chars = constants.VALID_CHARS;
  char startNode, goalNode, response;
  int choice;
  std::string startCity, endCity;

  const std::vector<char> validResponse = constants.validResponse;
  
  bool validInput = false;
  while (!validInput)
  {
    std::cout << "(1) Breadth First Search (BFS)" << endl;
    std::cout << "(2) Depth First Search (DFS)" << endl;
    std::cout << "(3) Uniform Cost Search" << endl;
    std::cout << "(4) A* Search" << endl;
    std::cout << "(5) Exit" << std::endl;
    choice = misc.getValidInt("Enter your choice [1-5]: ", constants.MIN_VALUE, constants.MAX_VALUE);

    switch (choice)
    {
      case 1:
      case 2:
      {
        startNode = misc.getValidChar("Enter start node (A-Y): ", valid_chars);
        goalNode = misc.getValidChar("Enter goal node (A-Y): ", valid_chars);
        mygraph = constants.graph;

        if (choice == 1)
        {
          // bfs search
          bfsPath = dfsbfs.BFS(mygraph, startNode, goalNode);
          std::cout << "BFS Path: ";
          misc.printPath(bfsPath);
        }
        else
        {
          // dfs search
          dfsPath = dfsbfs.DFS(startNode, goalNode, mygraph);
          std::cout << "DFS Path: ";
          misc.printPath(dfsPath);
        }
        break;
      }
      case 3:
      case 4:
      {
        romaniaMap = constants.RomaniaMap;
        heuristic = constants.Heuristics;
        startCity = misc.getValidString("Enter start city (e.g., Arad): ", constants.CITIES);
        endCity = misc.getValidString("Enter goal city (e.g., Bucharest): ", constants.CITIES);
        if (choice == 3)
        {
          // Uniform Cost Search
          auto result = uniformcostsearch.UniformCostSearch(romaniaMap, startCity, endCity);
          std::cout << "Uniform Cost Search Path: ";
          auto path = result.first;
          auto cost = result.second;
          misc.printPath(path);
          std::cout << "Uniform Cost Search Path Cost: ";
          std::cout << cost;
          std::cout << "\n";
        }
        else
        {
          // AStar search
          auto result = astar.AStarSearch(romaniaMap, startCity, endCity, heuristic);
          std::cout << "A* Search Path: ";
          auto path = result.first;
          auto cost = result.second;
          misc.printPath(path);
          std::cout << "A* Search Path Cost: ";
          std::cout << cost;
          std::cout << "\n";
        }
        break;
      }
      case 5:
      {
        std::cout << "Exiting program." << std::endl;
        return 0;
      }
      default:
      {
        std::cout << "Invalid choice" << std::endl;
        break;
      }
    }

    response = misc.getValidChar("Do you want to continue (Enter 'n|N' for No 'y|Y' for Yes): ", validResponse);
    validInput = (response == 'N');
  }
  return 0;
}
